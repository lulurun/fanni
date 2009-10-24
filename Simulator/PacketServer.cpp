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

PacketServer::PacketServer(const std::string &addr, uint16_t port, int thread_number) :
	TransferNode(LLPacketFactorySingleton::get(), addr, port, thread_number) {
}

PacketServer::~PacketServer() {
}

void PacketServer::init() {
	// set packet handlers
	this->packet_handler_factory.registerPacketHandler(UseCircuitCode_ID, new UseCirciutCodePacketHandler());
	this->packet_handler_factory.registerPacketHandler(StartPingCheck_ID, new StartPingCheckPacketHandler());
}

ConnectionBase *PacketServer::createConnection(uint32_t circuit_code, const Poco::Net::SocketAddress *addr) {
	// MEMO @@@ will be deleted in "PacketTransferBase::destructor()" or "closeConnection()"
	return new ClientConnection(circuit_code, *addr, *this);
}

bool PacketServer::skipProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == UseCircuitCode_ID);
}

bool PacketServer::skipHandlePacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == PacketAck_ID);
}

}
