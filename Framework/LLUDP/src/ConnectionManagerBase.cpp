#include <list>
#include "fanni/Logger.h"
#include "fanni/LLUDP/ConnectionManagerBase.h"

using namespace Fanni;

ConnectionManagerBase::ConnectionManagerBase() {
	this->check_ALIVE_timer = new Poco::Timer(0, 5000); // TODO @@@ MAGIC NUMBER !
	// TODO @@@ do not use Poco::DefaultThreadPool
	this->check_ALIVE_timer->start(Poco::TimerCallback<ConnectionManagerBase>(*this, &ConnectionManagerBase::onCheckALIVETimer));
	DEBUG_LOG("ConnectionManagerBase started");
}

ConnectionManagerBase::~ConnectionManagerBase() {
	this->check_ALIVE_timer->stop();
	delete this->check_ALIVE_timer;
	DEBUG_LOG("ConnectionManagerBase stopped");
}

void ConnectionManagerBase::onCheckALIVETimer(Poco::Timer &timer) {
	TRACE_LOG("enter");
	Poco::FastMutex::ScopedLock l(this->conn_map);
	if (this->conn_map.empty())
		return;
	INFO_LOG("check alive for " << this->conn_map.size() << " connections");
	std::list<const EndPoint> remove_list;
	for (CONNECTION_MAP::iterator it = this->conn_map.begin(); it!= this->conn_map.end(); it++) {
		if (!it->second->checkALIVE()) {
			ERROR_LOG("Connection to " << it->second->getEndPoint().toString() << " timeout");
			remove_list.push_back(it->second->getEndPoint());
		}
	}
	if (remove_list.size() > 0) {
		INFO_LOG("remove " << remove_list.size() << " client connections");
		for (std::list<const EndPoint>::iterator it = remove_list.begin(); it != remove_list.end(); it++) {
			this->closeConnection(*it);
		}
	}
	TRACE_LOG("exit");
}

bool ConnectionManagerBase::isConnected_unsafe(const EndPoint &ep) const {
	CONNECTION_MAP::iterator it = this->conn_map.find(ep.toString());
	return !(it == this->conn_map.end());
}

ConnectionBasePtr &ConnectionManagerBase::getConnection_unsafe(const EndPoint &ep) const {
	CONNECTION_MAP::iterator it = this->conn_map.find(ep.toString());
	if (it == this->conn_map.end()) {
		throw Poco::NotFoundException("unknown connection");
	} else {
		return it->second;
	}
}

bool ConnectionManagerBase::tryDispatch(PacketBuffer &buffer, const EndPoint &ep) const {
	Poco::FastMutex::ScopedLock l(this->conn_map);
	if (this->isConnected_unsafe(ep)) {
		TaskPtr pTask(new IncomingData(buffer, ep));
		this->getConnection_unsafe(ep)->addTask(pTask);
		return true;
	} else {
		return false;
	}
}

ConnectionBasePtr ConnectionManagerBase::addConnection(const PacketBasePtr &packet, const EndPoint &ep) {
	ConnectionBasePtr conn = this->createConnection(packet, ep);
	{
		Poco::FastMutex::ScopedLock l(this->conn_map);
		this->conn_map[conn->getEndPoint().toString()] = conn;
	}
	this->ConnectionAdded(this, ep);
	return conn;
}

void ConnectionManagerBase::closeConnection(const EndPoint &ep) {
	{
		INFO_LOG("remove connection " << ep.toString());
		Poco::FastMutex::ScopedLock l(this->conn_map);
		this->conn_map.erase(ep.toString()); // TODO @@@ handle not found exception
	}
	this->ConnectionRemoved(this, ep);
}

ConnectionBasePtr &ConnectionManagerBase::getConnection(const EndPoint &ep) const {
	Poco::FastMutex::ScopedLock l(this->conn_map);
	return this->getConnection_unsafe(ep);
}