/*
 * PacketServer.cpp
 *
 *  Created on: Aug 15, 2009
 *      Author: lulu
 */

#include "ReceiverBase.h"
#include "PacketServer.h"
#include "ProtocolPacketHandlers.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;
using namespace Fanni::Tests;

// ==========
// PacketServer
PacketServer::PacketServer(const std::string &addr, int port, int thread_number) :
	PacketTransferBase(addr, port, thread_number) {}

PacketServer::~PacketServer() {}

void PacketServer::init() {
	PacketTransferBase::init();
	this->getReceiverManager()->registerHandler(StartPingCheck_ID, new StartPingCheckPacketHandler());
}

void PacketServer::addConnection(uint32_t circuit_code, const EndPoint *ep) {
	ClientConnection *client_connection = new ClientConnection(circuit_code, *ep, this);
	S_MUTEX_LOCK l;
	l.lock(&this->client_connection_map_lock);
	client_connection_map[ep->getIPv4HashKey()] = client_connection;
}

ClientConnection *PacketServer::getConnection(const EndPoint *ep) {
	uint64_t ep_key = ep->getIPv4HashKey();
	S_MUTEX_LOCK l;
	l.lock(&this->client_connection_map_lock);
	CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.find(ep_key);
	if (it == this->client_connection_map.end()) {
		// not found
		return NULL;
	} else {
		return it->second;
	}
}

void PacketServer::removeConnection(const EndPoint *ep) {
	S_MUTEX_LOCK l;
	l.lock(&this->client_connection_map_lock);
	ClientConnection *client_connection = this->getConnection(ep);
	if (client_connection != NULL) {
		this->client_connection_map.erase(ep->getIPv4HashKey());
		delete client_connection;
	}
}

void PacketServer::checkACK() {
	TRACE_LOG("enter");
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.begin();
		it != this->client_connection_map.end(); it++) {
		it->second->checkACK();
	}
	TRACE_LOG("exit");
}

void PacketServer::checkRESEND() {
	TRACE_LOG("enter");
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.begin();
		it != this->client_connection_map.end(); it++) {
		it->second->checkRESEND();
	}
	TRACE_LOG("exit");
}

void PacketServer::processIncomingPacket(const PacketBase *packet, const EndPoint *ep) {
	TRACE_LOG("enter");
	if (packet->header.getPacketID() == OPEN_CONNECTION_PACKET) {
		TRACE_LOG("exit 1");
		return;
	}
	ClientConnection *client_connection = this->getConnection(ep);
	if (client_connection) {
		client_connection->processIncomingPacket(packet);
	} else {
		WARN_LOG("unknown packet from ADDR: " << ep->getAddrStr() << " PORT: " << ep->getPort());
	}
	TRACE_LOG("exit 0");
}

void PacketServer::processOutgoingPacket(const PacketBase *packet, const EndPoint *ep) {
	TRACE_LOG("enter");
	ClientConnection *client_connection = this->getConnection(ep);
	if (client_connection) {
		client_connection->processOutgoingPacket(packet);
		TRACE_LOG("exit 0");
	} else {
		WARN_LOG("unknown packet from ADDR: " << ep->getAddrStr() << " PORT: " << ep->getPort());
		TRACE_LOG("exit 1");
	}
}

