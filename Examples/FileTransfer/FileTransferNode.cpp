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
using namespace Fanni::Tests;

FileTransferNode::FileTransferNode(const std::string &addr, int port, int thread_number) :
	PacketTransferBase(addr, port, thread_number), packet_factory(FileTransferPacketFactorySingleton::get()) {
}

FileTransferNode::~FileTransferNode() {
}

void FileTransferNode::init() {
	// set packet handlers
	this->packet_handler_factory.registerPacketHandler(OpenConnection_ID, new OpenConnectionPacketHandler());
	this->packet_handler_factory.registerPacketHandler(OpenConnectionReply_ID, new OpenConnectionReplyPacketHandler());
	this->packet_handler_factory.registerPacketHandler(CloseConnection_ID, new CloseConnectionPacketHandler());
	this->packet_handler_factory.registerPacketHandler(CloseConnectionReply_ID, new CloseConnectionReplyPacketHandler());
	this->packet_handler_factory.registerPacketHandler(FileInfo_ID, new FileInfoPacketHandler());
	this->packet_handler_factory.registerPacketHandler(FileInfoReply_ID, new FileInfoReplyPacketHandler());
	this->packet_handler_factory.registerPacketHandler(FileData_ID, new FileDataPacketHandler());
	this->packet_handler_factory.registerPacketHandler(TransferComplete_ID, new TransferCompletePacketHandler());
	PacketTransferBase::init(&this->packet_factory, &this->packet_handler_factory);
}

ClientConnectionBase *FileTransferNode::createClientConnection(uint32_t circuit_code, const EndPoint *ep) {
	// MEMO @@@ will be deleted in "PacketTransferBase::destructor()" or "closeConnection()"
	return new FileTransferClientConnection(circuit_code, *ep, this);
}

bool FileTransferNode::skipProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == OpenConnection_ID) || (packet_id == OpenConnectionReply_ID);
}

bool FileTransferNode::skipHandlePacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == PacketAck_ID);
}

// file sender methods
void FileTransferNode::openConnection(const EndPoint &ep) {
	TRACE_LOG("enter");
	int circuit_code = 1; // TODO @@@ should be a random number
	OpenConnectionPacket *packet = dynamic_cast<OpenConnectionPacket *> (this->packet_factory.createPacket(OpenConnection_ID));
	assert(packet);
	packet->OpenConnection.Code = circuit_code;
	this->sendPacket(packet, &ep);
	TRACE_LOG("exit");
}

void FileTransferNode::closeConnection(const EndPoint &ep) {
	CloseConnectionPacket *packet = dynamic_cast<CloseConnectionPacket *> (this->packet_factory.createPacket(CloseConnection_ID));
	assert(packet);
	this->sendPacket(packet, &ep);
	// memo @@@ don't wait
	this->removeConnection(&ep);
}

void FileTransferNode::startSendFile(const string &file_path, const EndPoint &ep) {
	this->send_file_path = file_path;
	this->openConnection(ep);
}

