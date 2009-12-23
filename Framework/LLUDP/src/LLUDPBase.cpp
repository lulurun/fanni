#include "Poco/NObserver.h"
#include "fanni/Logger.h"
#include "fanni/LLUDP/LLUDPBase.h"

using namespace Fanni;

class ConnectionPacketTask : public UDPPacketData {
public:
	ConnectionBasePtr &pConn;

	ConnectionPacketTask(UDPPacketData &pUDPData, ConnectionBasePtr &pConn) : UDPPacketData(pUDPData), pConn(pConn) {};
	virtual ~ConnectionPacketTask() {};
};

class LLUDPBaseWorker : public Worker {
private:
	virtual void doTask(TaskPtr &pTask) {
		ConnectionPacketTask *data = dynamic_cast<ConnectionPacketTask *>(pTask.get());
		if (data != NULL) {
			data->pConn->onDataReceived(this, data->pBuf);
		} else {
			// TODO @@@ exception
		}
	};
};

LLUDPBase::LLUDPBase(const EndPoint &ep) : server_ep(ep) {
	// start worker threads
	for (int i=0; i<15; i++) {
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
	UDPPacketData *data = new UDPPacketData();
	TaskPtr pTask(data);
	// receive
	int recv_len = this->socket.receiveFrom(data->pBuf->getBuffer(), PACKET_BUF_LEN, data->ep);
	if (recv_len == -1) {
		ERROR_LOG("recvfrom() returned -1");
		return;
	} else if (recv_len == 0) {
		ERROR_LOG("Connection Close");
		return;
	}
	data->pBuf->setLength(recv_len);
	// dispatch
	{
		Poco::FastMutex::ScopedLock l(this->conn_map);
		if (this->isConnected_unsafe(data->ep)) {
			ConnectionBasePtr &pConn = this->getConnection_unsafe(data->ep);
			TaskPtr pTask(new ConnectionPacketTask(*data, pConn));
			this->worker_thread_mgr.deliverTask(pTask);
		} else {
			this->addTask(pTask);
		}
	}
}

void LLUDPBase::onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf) {
	INFO_LOG("shutdown udp server");
}

