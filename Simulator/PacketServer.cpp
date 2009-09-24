/*
 * PacketServer.cpp
 *
 *  Created on: Sep 19, 2009
 *      Author: lulu
 */

#include "PacketServer.h"
#include "ClientConnection.h"
#include "SystemPacketHandlers.h"

namespace Fanni {

PacketServer::PacketServer(const std::string &addr, int port, int thread_number) :
	PacketTransferBase(addr, port, thread_number), packet_factory(LLPacketFactorySingleton::get()) {
}

PacketServer::~PacketServer() {
}

void PacketServer::init() {
	// set packet handlers
	this->packet_handler_factory.registerPacketHandler(UseCircuitCode_ID, new UseCirciutCodePacketHandler());
	this->packet_handler_factory.registerPacketHandler(StartPingCheck_ID, new StartPingCheckPacketHandler());
	PacketTransferBase::init(&this->packet_factory, &this->packet_handler_factory);
}

ClientConnectionBase *PacketServer::createClientConnection(uint32_t circuit_code, const EndPoint *ep) {
	// MEMO @@@ will be deleted in "PacketTransferBase::destructor()" or "closeConnection()"
	return new ClientConnection(circuit_code, *ep, this);
}

bool PacketServer::skipProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == UseCircuitCode_ID);
}

bool PacketServer::skipHandlePacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == PacketAck_ID);
}


}
