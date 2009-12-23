/*
 * LLUDPBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_LLUDPBASE_H_
#define FANNI_LLUDPBASE_H_

#include "Poco/AutoPtr.h"
#include "Poco/Thread.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/SocketNotification.h"
#include "fanni/PacketBuffer.h"
#include "fanni/LLUDP/LLUDP_def.h"
#include "fanni/Logger.h"
#include "fanni/EndPoint.h"
#include "fanni/ThreadManager.h"
#include "fanni/LLPackets/LLPackets.h"
#include "fanni/LLUDP/SystemPacketHandler.h"
#include "fanni/LLUDP/LocalTaskHandler.h"
#include "fanni/LLUDP/SystemPacketWorkerBase.h"
#include "fanni/LLUDP/ConnectionManagerBase.h"

namespace Fanni {

class Fanni_LLUDP_API LLUDPBase : public SystemPacketWorkerBase, public ConnectionManagerBase {
protected:
	EndPoint server_ep;
	SystemPacketHandlerFactory system_handler_factory;
	ConnectionPacketHandlerFactory connection_handler_factory;
	LocalTaskHandlerFactory task_handler_factory;

private:
	Poco::Net::DatagramSocket socket;
	Poco::Net::SocketReactor reactor;
	Poco::Thread reactor_thread;

	// UDPServerHandler
	void onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& pNf);
	void onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf);


	ThreadManager worker_thread_mgr;

public:
	LLUDPBase(const EndPoint &ep);
	virtual ~LLUDPBase();

	// UDPServerBase
	inline int sendData(const PacketBufferPtr &pBuf, const EndPoint &ep) {
		return this->socket.sendTo(pBuf->getConstBuffer(), pBuf->getLength(), ep);
	};

	// SystemPacketWorkerBase
	virtual void dispatch(const PacketBasePtr &packet, const EndPoint &ep) {
		try {
			const SystemPacketHandlerBase &handler = this->system_handler_factory.getHandler(packet->header.getPacketID());
			handler(*this, packet, ep);
		} catch (Poco::NotFoundException &ex) {
			ERROR_LOG("Exception: " << packet->header.getPacketID() << " " << ep.toString() << " " << ex.message());
		}
	}

	virtual void dispatch(const LocalTaskBasePtr &pLocTask) {
		try {
			const LocalTaskHandlerBase &handler = this->task_handler_factory.getHandler(pLocTask->getName());
			handler(*this, pLocTask);
		} catch (Poco::NotFoundException &ex) {
			ERROR_LOG("Exception: " << pLocTask->getName() << " " << ex.message());
		}
	}

	const ConnectionPacketHandlerFactory &getConnectionHandlerFactory() const {
		return this->connection_handler_factory;
	}

	void scheduleCloseConnection(const EndPoint &ep) {
		TaskPtr pTask(new CloseConnectionTask(ep));
		this->addTask(pTask);
	}
};

}

#endif /* FANNI_LLUDPBASE_H_ */

