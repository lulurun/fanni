/*
 * PacketHandlerFactory.cpp
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#include <iostream>
#include <tr1/unordered_map>

#include "fanni/Exception.h"
#include "PacketHandlerFactory.h"

namespace Fanni {
namespace Tests {

class NullHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferManager *ptm) const {
		INFO_LOG("handler not defined for Packet: " << std::hex << packet->header.getPacketID() << std::dec);
	};
};

}
}

using namespace std;
using namespace Fanni;
using namespace Fanni::Tests;

typedef tr1::unordered_map<PacketHeader::PACKET_ID_TYPE, const PacketHandlerBase*> PACKET_HANDLER_MAP_TYPE;
static PACKET_HANDLER_MAP_TYPE PacketHandlerList;
static NullHandler null_handler;

PacketHandlerFactory::PacketHandlerFactory() {}
PacketHandlerFactory::~PacketHandlerFactory() {
	//TODO @@@ memory leak, delete
}

void PacketHandlerFactory::init() {}

void PacketHandlerFactory::registerPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *packet_handler) {
	PacketHandlerList[packet_id] = packet_handler;
}

const PacketHandlerBase *PacketHandlerFactory::getPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id) const {
    PACKET_HANDLER_MAP_TYPE::const_iterator it = PacketHandlerList.find(packet_id);
    if(it != PacketHandlerList.end()){
		return it->second;
    }
    return &null_handler;
}

