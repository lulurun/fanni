/*
 * ConnectionBase.h
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#ifndef CONNECTIONBASE_H_
#define CONNECTIONBASE_H_

#include "Poco/SharedPtr.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/LLUDP/LLUDP_def.h"
#include "fanni/LLUDP/ConnectionPacketHandler.h"
#include "fanni/LLUDP/ConnectionPacketWorkerBase.h"
#include "fanni/LLUDP/AckManager.h"

namespace Fanni {

class LLUDPBase;
class Fanni_LLUDP_API ConnectionBase : public ConnectionPacketWorkerBase {
protected:
	const ConnectionPacketHandlerFactory &connection_handler_factory;
	LLUDPBase &udp; // TODO @@@ change to ConnectionManagerBase
	AckManager *ack_mgr;

public:
	ConnectionBase(const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp);
	virtual ~ConnectionBase();
	void sendPacket(PacketBasePtr &packet);
	bool checkALIVE();
	LLUDPBase &getUDPBase() const;

	virtual void dispatch(const PacketBasePtr &packet);
};

typedef Poco::SharedPtr<ConnectionBase> ConnectionBasePtr;

}

#endif /* CONNECTIONBASE_H_ */

