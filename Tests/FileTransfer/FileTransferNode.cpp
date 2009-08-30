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
	PacketTransferBase(addr, port, thread_number) {
}

FileTransferNode::~FileTransferNode() {}

void FileTransferNode::init() {
	PacketTransferBase::init();
	this->getReceiverManager()->registerHandler(OpenConnection_ID, new OpenConnectionPacketHandler());
	this->getReceiverManager()->registerHandler(OpenConnectionReply_ID, new OpenConnectionReplyPacketHandler());
	this->getReceiverManager()->registerHandler(CloseConnection_ID, new CloseConnectionPacketHandler());
	this->getReceiverManager()->registerHandler(FileInfo_ID, new FileInfoPacketHandler());
	this->getReceiverManager()->registerHandler(FileInfoReply_ID, new FileInfoReplyPacketHandler());
	this->getReceiverManager()->registerHandler(FileData_ID, new FileDataPacketHandler());
}

ClientConnectionBase *FileTransferNode::createClientConnection(uint32_t circuit_code, const EndPoint *ep) {
	return new FileTransferClientConnection(circuit_code, *ep, this);
}

bool FileTransferNode::ignoreInProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == OpenConnection_ID) || (packet_id == OpenConnectionReply_ID);
}

// file sender methods
void FileTransferNode::openConnection(const EndPoint &ep) {
	TRACE_LOG("enter");
	int circuit_code = 1;

	OpenConnectionPacket *packet = dynamic_cast<OpenConnectionPacket *>(FileTransferPacketFactorySingleton::get().createPacket(OpenConnection_ID));
	assert(packet);
	packet->OpenConnection.Code = circuit_code;
	this->sendPacket(packet, &ep);
	TRACE_LOG("exit");
}

void FileTransferNode::closeConnection(const EndPoint &ep) {
	CloseConnectionPacket *packet = dynamic_cast<CloseConnectionPacket *>(FileTransferPacketFactorySingleton::get().createPacket(CloseConnection_ID));
	assert(packet);
	this->sendPacket(packet, &ep);
	// memo @@@ don't wait
	this->removeConnection(&ep);
}

void FileTransferNode::startSendFile(const string &file_path, const EndPoint &ep) {
	this->send_file_path = file_path;
	this->openConnection(ep);
}

