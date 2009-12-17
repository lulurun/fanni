#include "Poco/NObserver.h"
#include "fanni/Logger.h"
#include "fanni/LLUDP/LLUDPBase.h"

using namespace Fanni;

class ConnectionPacketData : public TaskBase {
public:
	PacketBufferPtr pBuf;
	ConnectionBasePtr &pConn;

	ConnectionPacketData(PacketBufferPtr &pBuf, ConnectionBasePtr &pConn) : pBuf(pBuf), pConn(pConn) {}
	virtual ~ConnectionPacketData() {}
};

class LLUDPBaseWorker : public Worker {
private:
	virtual void doTask(TaskPtr &pTask) {
		ConnectionPacketData *data = dynamic_cast<ConnectionPacketData *>(pTask.get());
		if (data != NULL) {
			data->pConn->onDataReceived(this, data->pBuf);
		} else {
			// TODO @@@ exception
		}
	};
};

LLUDPBase::LLUDPBase(const EndPoint &ep) : server_ep(ep) {
	// start worker threads
	for (int i=0; i<5; i++) {
		WorkerPtr pWorker(new LLUDPBaseWorker());
		this->worker_thread_mgr.addWorker(pWorker);
	}

	// register handler
	LLPackets::init(this->packet_factory);
	this->task_handler_factory.registerHandler("CloseConnection", new CloseConnectionTaskHandler());

	// start udp server
	this->socket.bind(this->server_ep, true);
	this->reactor.addEventHandler(this->socket, Poco::NObserver<LLUDPBase,
		Poco::Net::ReadableNotification>(*this, &LLUDPBase::onReadable));
	this->reactor.addEventHandler(this->socket, Poco::NObserver<LLUDPBase,
		Poco::Net::ShutdownNotification>(*this, &LLUDPBase::onShutdown));
	this->reactor_thread.start(this->reactor);
	DEBUG_LOG("UDPServer started");

}

LLUDPBase::~LLUDPBase() {
	this->reactor.stop();
	this->reactor_thread.join();
	DEBUG_LOG("UDPServer stopped");
}

void LLUDPBase::onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& pNf) {
	PacketBufferPtr pBuf(new PacketBuffer());
	EndPoint ep;
	// receive
	int recv_len = this->socket.receiveFrom(pBuf->getBuffer(), PACKET_BUF_LEN, ep);
	if (recv_len == -1) {
		ERROR_LOG("recvfrom() returned -1");
		return;
	} else if (recv_len == 0) {
		ERROR_LOG("Connection Close");
		return;
	}
	pBuf->setLength(recv_len);
	// dispatch
	{
		Poco::FastMutex::ScopedLock l(this->conn_map);
		if (this->isConnected_unsafe(ep)) {
			ConnectionBasePtr &pConn = this->getConnection_unsafe(ep);
			TaskPtr pTask(new ConnectionPacketData(pBuf, pConn));
			this->worker_thread_mgr.deliverTask(pTask);
		} else {
			TaskPtr pTask(new SystemPacketData(pBuf, ep));
			this->addTask(pTask);
		}
	}
}

void LLUDPBase::onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf) {
	INFO_LOG("shutdown udp server");
}

