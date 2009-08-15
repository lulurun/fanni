/*
 * PacketHandlerFactory.h
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERFACTORY_H_
#define PACKETHANDLERFACTORY_H_

#include "fanni/EndPoint.h"
#include "Packets/PacketBase.h"
#include "Packets/PacketHeader.h"

namespace Fanni {
namespace Tests {

class PacketServer;
class PacketHandlerBase {
public:
	PacketHandlerBase() {};
	virtual ~PacketHandlerBase() {};
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketServer &packet_server) const = 0;
};

class PacketHandlerFactory {
public:
	PacketHandlerFactory();
	virtual ~PacketHandlerFactory();

	void init();
	const PacketHandlerBase *getPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
	void registerPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *packet_handler);
};

}
}

#endif /* PACKETHANDLERFACTORY_H_ */
