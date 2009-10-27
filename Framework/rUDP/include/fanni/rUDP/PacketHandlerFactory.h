/*
 * PacketHandlerFactory.h
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERFACTORY_H_
#define PACKETHANDLERFACTORY_H_

#include "Poco/Net/SocketAddress.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketHeader.h"
#include "fanni/rUDP/rUDP_def.h"

namespace Fanni {

class ConnectionBase;
class PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection) const = 0;
};

class Fanni_RUDP_API PacketHandlerFactory {
public:
	PacketHandlerFactory();
	virtual ~PacketHandlerFactory();

	void init();
	const PacketHandlerBase &getPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
	void registerPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *packet_handler);
};

}

#endif /* PACKETHANDLERFACTORY_H_ */
