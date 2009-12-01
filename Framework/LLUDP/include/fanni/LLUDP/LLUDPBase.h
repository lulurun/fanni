/*
 * LLUDPBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_LLUDPBASE_H_
#define FANNI_LLUDPBASE_H_

#include "fanni/Logger.h"
#include "fanni/EndPoint.h"
#include "fanni/LLPackets/LLPackets.h"
#include "fanni/LLUDP/UDPServerBase.h"
#include "fanni/LLUDP/SystemPacketHandler.h"
#include "fanni/LLUDP/LocalTaskHandler.h"
#include "fanni/LLUDP/SystemPacketWorkerBase.h"
#include "fanni/LLUDP/ConnectionManagerBase.h"

namespace Fanni {

class LLUDPBase : public UDPServerBase, public SystemPacketWorkerBase, public ConnectionManagerBase {
protected:
	EndPoint server_ep;
	SystemPacketHandlerFactory system_handler_factory;
	ConnectionPacketHandlerFactory connection_handler_factory;
	LocalTaskHandlerFactory task_handler_factory;

public:
	LLUDPBase(const EndPoint &ep) :
	  UDPServerBase(ep), // start UDPServer
	  server_ep(ep) {
		  LLPackets::init(this->packet_factory);
		  this->task_handler_factory.registerHandler("CloseConnection", new CloseConnectionTaskHandler());
	};
	virtual ~LLUDPBase() {};

	// UDPServerBase
	virtual void processIncomingData(PacketBuffer &buffer, const EndPoint &ep) {
		if (!this->tryDispatch(buffer, ep)) {
			TaskPtr pTask(new IncomingData(buffer, ep));
			this->addTask(pTask);
		}
	}

	// SystemPacketWorkerBase
	virtual void dispatch(const PacketBasePtr &packet, const EndPoint &ep) {
		const SystemPacketHandlerBase &handler = this->system_handler_factory.getHandler(packet->header.getPacketID());
		handler(*this, packet, ep);
	}

	virtual void dispatch(const LocalTaskBasePtr &pLocTask) {
		const LocalTaskHandlerBase &handler = this->task_handler_factory.getHandler(pLocTask->getName());
		handler(*this, pLocTask);
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

