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
	PacketHandlerFactory();
public:
	virtual ~PacketHandlerFactory();

	void init();
	const PacketHandlerBase *getPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
	static PacketHandlerFactory *GetInstance();
};

}

#endif /* PACKETHANDLERFACTORY_H_ */
