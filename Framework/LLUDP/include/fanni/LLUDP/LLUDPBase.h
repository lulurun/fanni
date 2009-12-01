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
#include "fanni/LLUDP/SystemPacketWorkerBase.h"
#include "fanni/LLUDP/ConnectionManagerBase.h"

namespace Fanni {

class LLUDPBase : public UDPServerBase, public SystemPacketWorkerBase, public ConnectionManagerBase {
protected:
	EndPoint server_ep;
	SystemPacketHandlerFactory system_handler_factory;
	ConnectionPacketHandlerFactory connection_handler_factory;

public:
	LLUDPBase(const EndPoint &ep) :
	  UDPServerBase(ep), // start UDPServer
	  server_ep(ep) {
		  LLPackets::init(this->packet_factory);
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
	virtual void dispatch(PacketBasePtr &packet, const EndPoint &ep) {
		try {
			const SystemPacketHandlerBase &handler = this->system_handler_factory.getHandler(packet->header.getPacketID());
			handler(*this, packet, ep);
		} catch (Poco::NotFoundException &ex) {
			ERROR_LOG("LLUDP", "packet handler not found" << ex.message());
		}
	}

	virtual void dispatch(const TaskPtr &pTask, const EndPoint &ep) {
		const CloseConnectionTask *ccTask = dynamic_cast<const CloseConnectionTask *>(pTask.get());
		if (ccTask) {
			this->closeConnection(ep);
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

