/*
 * ConnectionBase.h
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#ifndef CONNECTIONBASE_H_
#define CONNECTIONBASE_H_

#include <cstdio>
#include <string>
#include "Poco/SharedPtr.h"
#include "Poco/Timestamp.h"
#include "Poco/BasicEvent.h"
#include "fanni/EndPoint.h"
#include "fanni/PacketBuffer.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketSerializer.h"
#include "fanni/LLUDP/LLUDP_def.h"
#include "fanni/LLUDP/ConnectionPacketHandler.h"
#include "fanni/LLUDP/AckManager.h"

namespace Fanni {

class LLUDPBase;
class Fanni_LLUDP_API ConnectionBase {
private:
	const PacketSerializer &packet_serializer;
	const ConnectionPacketHandlerFactory &connection_handler_factory;

protected:
	EndPoint ep;
	LLUDPBase &udp; // TODO @@@ change to ConnectionManagerBase
	AckManager ack_mgr;
	Poco::Timestamp last_received;

public:
	ConnectionBase(const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp);
	virtual ~ConnectionBase();
	void sendPacket(PacketBasePtr &pPacket);
	bool checkALIVE();
	LLUDPBase &getUDPBase() const;
	const EndPoint &getEndPoint() const;

	virtual void close();

	void onDataReceived(const void* pSender, PacketBufferPtr &pBuf);
};

typedef Poco::SharedPtr<ConnectionBase> ConnectionBasePtr;

}

#endif /* CONNECTIONBASE_H_ */

