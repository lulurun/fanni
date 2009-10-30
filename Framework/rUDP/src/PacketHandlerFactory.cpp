/*
 * PacketHandlerFactory.cpp
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#include <iostream>
#include "Poco/HashMap.h"

#include "fanni/Exception.h"
#include "fanni/EndPoint.h"
#include "fanni/rUDP/PacketHandlerFactory.h"
#include "fanni/rUDP/TransferNode.h"

namespace Fanni {

class NullClientHandler: public ClientPacketHandlerBase {
public:
	void operator()(const PacketBase *packet, ConnectionBase *conn) const {
		INFO_LOG("rUDP", "handler not defined for Packet: " << std::hex << packet->header.getPacketID() << std::dec
				<< " from " << conn->getEndPoint().toString());
	}
};

class NullSystemHandler: public SystemPacketHandlerBase {
public:
	void operator()(const PacketBase *packet, const EndPoint &ep, TransferNode &node) const {
		FATAL_LOG("rUDP", "system handler not defined for Packet: " << std::hex << packet->header.getPacketID() << std::dec
				<< " from " << ep.toString());
		// TODO @@@ throw exception
	}
};

}

using namespace std;
using namespace Fanni;

static NullClientHandler null_client_handler;
static NullSystemHandler null_system_handler;

PacketHandlerFactory::PacketHandlerFactory() {}

PacketHandlerFactory::~PacketHandlerFactory() {
	for(CLIENT_HANDLER_MAP::Iterator it=this->ClientHandlerList.begin(); it!=this->ClientHandlerList.end(); it++) {
		delete it->second;
	}
	for(SYSTEM_HANDLER_MAP::Iterator it=this->SystemHandlerList.begin(); it!=this->SystemHandlerList.end(); it++) {
		delete it->second;
	}
}

void PacketHandlerFactory::registerClientHandler(PacketHeader::PACKET_ID_TYPE packet_id, const ClientPacketHandlerBase *packet_handler) {
	// MEMO @@@ not thread safe, call me in one thread
	this->ClientHandlerList[packet_id] = packet_handler;
}

void PacketHandlerFactory::registerSyetemHandler(PacketHeader::PACKET_ID_TYPE packet_id, const SystemPacketHandlerBase *packet_handler) {
	// MEMO @@@ not thread safe, call me in one thread
	this->SystemHandlerList[packet_id] = packet_handler;
}

const ClientPacketHandlerBase &PacketHandlerFactory::getClientHandler(PacketHeader::PACKET_ID_TYPE packet_id) const {
	CLIENT_HANDLER_MAP::ConstIterator it = this->ClientHandlerList.find(packet_id);
	if (it != this->ClientHandlerList.end()) {
		return *it->second;
	}
	return null_client_handler;
}

const SystemPacketHandlerBase &PacketHandlerFactory::getSystemHandler(PacketHeader::PACKET_ID_TYPE packet_id) const {
	SYSTEM_HANDLER_MAP::ConstIterator it = this->SystemHandlerList.find(packet_id);
	if (it != this->SystemHandlerList.end()) {
		return *it->second;
	}
	return null_system_handler;
}

