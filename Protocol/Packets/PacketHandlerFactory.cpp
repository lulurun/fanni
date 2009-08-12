/*
 * PacketHandlerFactory.cpp
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#include <iostream>
#include <tr1/unordered_map>
#include "Packets.h"
#include "PacketHandlerFactory.h"

namespace Fanni {

class NullHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase& packet, const EndPoint &ep) const {
		INFO_LOG("handler not defined for Packet: " << std::hex << packet.header.getPacketID() << std::dec);
	};
};

}

using namespace std;
using namespace Fanni;

typedef tr1::unordered_map<PacketHeader::PACKET_ID_TYPE, const PacketHandlerBase*> PACKET_HANDLER_MAP_TYPE;
static PACKET_HANDLER_MAP_TYPE PacketHandlerList;
static NullHandler null_handler;

PacketHandlerFactory::PacketHandlerFactory() {}
PacketHandlerFactory::~PacketHandlerFactory() {
	//TODO @@@ memory leak, delete
}

void PacketHandlerFactory::init() { }

void PacketHandlerFactory::registerPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *packet_handler) {
	PacketHandlerList[packet_id] = packet_handler;
}

const PacketHandlerBase *PacketHandlerFactory::getPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id) const {
	const PacketHandlerBase *ret = NULL;
    PACKET_HANDLER_MAP_TYPE::const_iterator it = PacketHandlerList.find(packet_id);
    if(it != PacketHandlerList.end()){
		ret = it->second;
    }
    return &null_handler;
}

