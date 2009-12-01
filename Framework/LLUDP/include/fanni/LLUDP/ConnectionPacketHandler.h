/*
 * ConnectionPacketHandlerBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_CONNECTIONPACKETHANDLER_H_
#define FANNI_CONNECTIONPACKETHANDLER_H_

#include <map>
#include "fanni/Packets/PacketHeader.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/LLUDP/LLUDP_def.h"

namespace Fanni {

class ConnectionBase;
class Fanni_LLUDP_API ConnectionPacketHandlerBase {
public:
	virtual void operator()(ConnectionBase *conn, const PacketBasePtr &packet) const = 0;
};

class Fanni_LLUDP_API ConnectionPacketHandlerFactory {
private:
	typedef std::map<PacketHeader::PACKET_ID_TYPE, const ConnectionPacketHandlerBase *> PACKET_HANDLER_MAP;
	PACKET_HANDLER_MAP handler_map;

public:
	ConnectionPacketHandlerFactory();
	~ConnectionPacketHandlerFactory();

	// unsafe methods
	void registerHandler(PacketHeader::PACKET_ID_TYPE pakcet_id, const ConnectionPacketHandlerBase *handler);
	const ConnectionPacketHandlerBase &getHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
};

}

#endif /* FANNI_CONNECTIONPACKETHANDLER_H_ */

