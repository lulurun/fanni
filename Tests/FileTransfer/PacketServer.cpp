/*
 * PacketServer.cpp
 *
 *  Created on: Aug 15, 2009
 *      Author: lulu
 */

#include "fanni/UUID.h"
#include "ReceiverBase.h"
#include "PacketServer.h"
#include "PacketHandlers.h"
#include "FileTransferPackets/FileTransferPackets.h"

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
	this->getReceiverManager()->registerHandler(UseCircuitCode_ID, new UseCircuitCodePacketHandler());
	this->getReceiverManager()->registerHandler(CloseCircuit_ID, new CloseCircuitPacketHandler());
	this->getReceiverManager()->registerHandler(FileInfo_ID, new FileInfoPacketHandler());
}

void PacketServer::addConnection(uint32_t circuit_code, const EndPoint *ep) {
	DEBUG_LOG("add connection: " << ep->getAddrStr() << ":" << ep->getPort());
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
	DEBUG_LOG("remove connection: " << ep->getAddrStr() << ":" << ep->getPort());
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
	DEBUG_LOG("checking ACK for " << this->client_connection_map.size() << " connections");
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.begin();
		it != this->client_connection_map.end(); it++) {
		it->second->checkACK();
	}
	TRACE_LOG("exit");
}

void PacketServer::checkRESEND() {
	TRACE_LOG("enter");
	DEBUG_LOG("checking RESEND for " << this->client_connection_map.size() << " connections");
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

// specified (client) methods
void PacketServer::openConnection(const EndPoint &ep) {
	TRACE_LOG("enter");
	int circuit_code = 1;

	PacketBase *packet = FileTransferPacketFactorySingleton::get().createPacket(UseCircuitCode_ID);
	UseCircuitCodePacket *circuit_code_packet = dynamic_cast<UseCircuitCodePacket *>(packet);
	circuit_code_packet->CircuitCode.Code = circuit_code;

	circuit_code_packet->CircuitCode.SessionID = UUID::New();
	circuit_code_packet->CircuitCode.ID = UUID::New();
	this->sendPacket(circuit_code_packet, &ep);
	this->addConnection(circuit_code, &ep);
	TRACE_LOG("exit");
}

void PacketServer::closeConnection(const EndPoint &ep) {
	PacketBase *packet = FileTransferPacketFactorySingleton::get().createPacket(CloseCircuit_ID);
	CloseCircuitPacket *close_circuit_packet = dynamic_cast<CloseCircuitPacket *>(packet);
	this->sendPacket(close_circuit_packet, &ep);
	this->removeConnection(&ep);
}

void PacketServer::sendFile(const string &file_path, const EndPoint &ep) {
	PacketBase *packet = FileTransferPacketFactorySingleton::get().createPacket(FileInfo_ID);
	FileInfoPacket *file_info_packet = dynamic_cast<FileInfoPacket *>(packet);
	file_info_packet->FileInfo.TransferID = UUID::New();
	file_info_packet->FileInfo.Size = 15908;
	PacketBuffer buffer(reinterpret_cast<const unsigned char*>(file_path.c_str()), file_path.size());
	file_info_packet->FileInfo.Name = buffer;
	this->sendPacket(file_info_packet, &ep);
}

