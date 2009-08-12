/*
 * PacketHandlerFactory.h
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERFACTORY_H_
#define PACKETHANDLERFACTORY_H_

#include "PacketHeader.h"
#include "PacketHandlerBase.h"

namespace Fanni {

class PacketHandlerFactory {
public:
	PacketHandlerFactory();
	virtual ~PacketHandlerFactory();

	void init();
	const PacketHandlerBase *getPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
	void registerPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *packet_handler) ;
};

}

#endif /* PACKETHANDLERFACTORY_H_ */
