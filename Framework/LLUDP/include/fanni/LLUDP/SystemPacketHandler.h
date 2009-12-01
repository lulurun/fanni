/*
 * SystemPacketHandlerBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_SYSTEMPACKETHANDLER_H_
#define FANNI_SYSTEMPACKETHANDLER_H_

#include <map>
#include "fanni/EndPoint.h"
#include "fanni/Packets/PacketHeader.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/LLUDP/LLUDP_def.h"

namespace Fanni {

class LLUDPBase;
class Fanni_LLUDP_API SystemPacketHandlerBase {
public:
	virtual void operator()(LLUDPBase &udp, const PacketBasePtr &packet, const EndPoint &ep) const = 0;
};

class Fanni_LLUDP_API SystemPacketHandlerFactory {
private:
	typedef std::map<PacketHeader::PACKET_ID_TYPE, const SystemPacketHandlerBase *> PACKET_HANDLER_MAP;
	PACKET_HANDLER_MAP handler_map;

public:
	SystemPacketHandlerFactory();
	~SystemPacketHandlerFactory();

	void registerHandler(PacketHeader::PACKET_ID_TYPE packet_id, const SystemPacketHandlerBase *handler);
	const SystemPacketHandlerBase &getHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
	bool isHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
};

}

#endif /* FANNI_SYSTEMPACKETHANDLER_H_ */

