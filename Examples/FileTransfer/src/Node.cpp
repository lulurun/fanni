/*
 * FileTransferNode.cpp
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#include <cassert>
#include <fstream>
#include "Node.h"
#include "Handlers.h"
#include "Connection.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::FileTransfer;

Node::Node(const std::string &addr, uint16_t port, int thread_number) :
	TransferNode(FTPacketFactorySingleton::get(), addr, port, thread_number)  {
	// set packet handlers
	this->packet_handler_factory.registerPacketHandler(OpenConnection_ID, new OpenConnectionPacketHandler());
	this->packet_handler_factory.registerPacketHandler(OpenConnectionReply_ID, new OpenConnectionReplyPacketHandler());
	this->packet_handler_factory.registerPacketHandler(CloseConnection_ID, new CloseConnectionPacketHandler());
	this->packet_handler_factory.registerPacketHandler(CloseConnectionReply_ID, new CloseConnectionReplyPacketHandler());
	this->packet_handler_factory.registerPacketHandler(FileInfo_ID, new FileInfoPacketHandler());
	this->packet_handler_factory.registerPacketHandler(FileInfoReply_ID, new FileInfoReplyPacketHandler());
	this->packet_handler_factory.registerPacketHandler(FileData_ID, new FileDataPacketHandler());
	this->packet_handler_factory.registerPacketHandler(TransferComplete_ID, new TransferCompletePacketHandler());
}

Node::~Node() {}

ConnectionBase &Node::createConnection(const PacketBase *packet_base, const Poco::Net::SocketAddress &addr) {
	TRACE_LOG("enter");
	ConnectionBase *conn = NULL;
	if (packet_base->header.getPacketID() == OpenConnection_ID) {
		// Server
		const OpenConnectionPacket *packet = dynamic_cast<const OpenConnectionPacket *>(packet_base);
		assert(packet);
		conn = new Connection(packet->OpenConnection.Code, addr, *this);
	} else if (packet_base->header.getPacketID() == OpenConnectionReply_ID) {
		// Client
		const OpenConnectionReplyPacket *packet = dynamic_cast<const OpenConnectionReplyPacket *>(packet_base);
		assert(packet);
		conn = new Connection(packet->OpenConnectionReply.Code, addr, *this);
	} else {
		// throw Exception
	}
	this->addConnection(conn);
	TRACE_LOG("exit");
	return *conn;
}

bool Node::isNewConnection(const PacketBase *packet) {
	return (packet->header.getPacketID() == OpenConnection_ID) || (packet->header.getPacketID() == OpenConnectionReply_ID);
}

// file sender methods
void Node::connect(const Poco::Net::SocketAddress &addr) {
	TRACE_LOG("enter");
	int circuit_code = 1; // TODO @@@ should be a random number
	std::auto_ptr<OpenConnectionPacket> packet(dynamic_cast<OpenConnectionPacket *> (this->packet_factory.createPacket(OpenConnection_ID)));
	assert(packet.get());
	packet->OpenConnection.Code = circuit_code;
	this->sendPacket(packet.release(), addr);
	TRACE_LOG("exit");
}

void Node::close(const Poco::Net::SocketAddress &addr) {
	std::auto_ptr<CloseConnectionPacket> packet(dynamic_cast<CloseConnectionPacket *> (this->packet_factory.createPacket(CloseConnection_ID)));
	assert(packet.get());
	this->sendPacket(packet.release(), addr);
	// TODO @@@ don't wait ??
	// this->removeConnection(addr);
}

void Node::startSendFile(const string &file_path, const Poco::Net::SocketAddress &addr) {
	this->send_file_path = file_path;
	this->connect(addr);
}

std::string& Node::getSendFile() {
	return this->send_file_path;
}
