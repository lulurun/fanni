/*
 * FileTransferNode.cpp
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#include <cassert>
#include <fstream>
#include "FileTransferNode.h"
#include "FileTransferHandlers.h"
#include "FileTransferClientConnection.h"

using namespace std;
using namespace Fanni;

FileTransferNode::FileTransferNode(const std::string &addr, uint16_t port, int thread_number) :
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

FileTransferNode::~FileTransferNode() {
}

ConnectionBase *FileTransferNode::createConnection(const PacketBase *packet_base, const Poco::Net::SocketAddress &addr) {
	TRACE_LOG("enter");
	ConnectionBase *connection = NULL;
	if (packet_base->header.getPacketID() == OpenConnection_ID) {
		const OpenConnectionPacket *packet = dynamic_cast<const OpenConnectionPacket *>(packet_base);
		assert(packet);
		connection = new FileTransferClientConnection(packet->OpenConnection.Code, addr, *this);
	} else if (packet_base->header.getPacketID() == OpenConnectionReply_ID) {
		const OpenConnectionReplyPacket *packet = dynamic_cast<const OpenConnectionReplyPacket *>(packet_base);
		assert(packet);
		connection = new FileTransferClientConnection(packet->OpenConnectionReply.Code, addr, *this);
	}
	TRACE_LOG("exit");
	return connection;
}

bool FileTransferNode::isNewConnection(const PacketBase *packet) {
	return (packet->header.getPacketID() == OpenConnection_ID) || (packet->header.getPacketID() == OpenConnectionReply_ID);
}

// file sender methods
void FileTransferNode::openConnection(const Poco::Net::SocketAddress &addr) {
	TRACE_LOG("enter");
	int circuit_code = 1; // TODO @@@ should be a random number
	OpenConnectionPacket *packet = dynamic_cast<OpenConnectionPacket *> (this->packet_factory.createPacket(OpenConnection_ID));
	assert(packet);
	packet->OpenConnection.Code = circuit_code;
	this->sendPacket(packet, addr);
	TRACE_LOG("exit");
}

void FileTransferNode::closeConnection(const Poco::Net::SocketAddress &addr) {
	CloseConnectionPacket *packet = dynamic_cast<CloseConnectionPacket *> (this->packet_factory.createPacket(CloseConnection_ID));
	assert(packet);
	this->sendPacket(packet, addr);
	// memo @@@ don't wait
	this->removeConnection(addr);
}

void FileTransferNode::startSendFile(const string &file_path, const Poco::Net::SocketAddress &addr) {
	this->send_file_path = file_path;
	this->openConnection(addr);
}

