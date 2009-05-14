/*
 * PacketHandlerFactory.cpp
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#include <tr1/unordered_map>
#include "Packets.h"
#include "PacketHandlerFactory.h"
#include "PacketHandlers.h"

using namespace std;
using namespace Fanni;

typedef tr1::unordered_map<PacketHeader::PACKET_ID_TYPE, const PacketHandlerBase*> PACKET_HANDLER_MAP_TYPE;
static PACKET_HANDLER_MAP_TYPE PacketHandlerList;
static NullHandler null_handler;

PacketHandlerFactory::PacketHandlerFactory() {}
PacketHandlerFactory::~PacketHandlerFactory() {}

void PacketHandlerFactory::init() {
	PacketHandlerList[PacketAck_ID] = new PacketAckHandler();
}

const PacketHandlerBase *PacketHandlerFactory::getPacketHandler(PacketHeader::PACKET_ID_TYPE packet_id) const {
	const PacketHandlerBase *ret = NULL;
    PACKET_HANDLER_MAP_TYPE::const_iterator it = PacketHandlerList.find(packet_id);
    if(it != PacketHandlerList.end()){
		ret = it->second;
    }
    return &null_handler;
}

PacketHandlerFactory *PacketHandlerFactory::GetInstance() {
    static PacketHandlerFactory *factory;
    if (factory == NULL){
		factory = new PacketHandlerFactory();
		factory->init();
    }
    return factory;
}

