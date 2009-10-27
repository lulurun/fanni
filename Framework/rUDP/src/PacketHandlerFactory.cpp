/*
 * PacketHandlerFactory.cpp
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#include <iostream>
#include "Poco/HashMap.h"

#include "fanni/Exception.h"
#include "fanni/rUDP/PacketHandlerFactory.h"
#include "fanni/rUDP/TransferNode.h"

namespace Fanni {

class NullHandler: public PacketHandlerBase {
public:
	void operator()(const PacketBase *packet, ConnectionBase *connection) const {
		INFO_LOG("rUDP", "handler not defined for Packet: " << std::hex << packet->header.getPacketID() << std::dec
				<< " from " << connection->getAddr().toString());
	}
	;
};

}

using namespace std;
using namespace Fanni;

typedef Poco::HashMap<PacketHeader::PACKET_ID_TYPE, const PacketHandlerBase*> PACKET_HANDLER_MAP_TYPE;
static PACKET_HANDLER_MAP_TYPE PacketHandlerList;
static NullHandler null_handler;

PacketHandlerFactory::PacketHandlerFactory() {
}
PacketHandlerFactory::~PacketHandlerFactory() {
	//TODO @@@ memory leak, delete
}

void PacketHandlerFactory::init() {
}

void PacketHandlerFactory::registerPacketHandler(
		PacketHeader::PACKET_ID_TYPE packet_id,
		const PacketHandlerBase *packet_handler) {
	// MEMO @@@ not thread safe, call me in one thread
	PacketHandlerList[packet_id] = packet_handler;
}

const PacketHandlerBase &PacketHandlerFactory::getPacketHandler(
		PacketHeader::PACKET_ID_TYPE packet_id) const {
	PACKET_HANDLER_MAP_TYPE::ConstIterator it = PacketHandlerList.find(
			packet_id);
	if (it != PacketHandlerList.end()) {
		// MEMO @@@ do not copy
		return *it->second;
	}
	return null_handler;
}

