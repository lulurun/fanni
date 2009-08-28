/*
 * FileTransferNode.cpp
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#include "FileTransferNode.h"
#include "FileTransferHandlers.h"
#include "FileTransferClientConnection.h"

using namespace Fanni;
using namespace Fanni::Tests;

FileTransferNode::FileTransferNode(const std::string &addr, int port, int thread_number) :
	PacketTransferBase(addr, port, thread_number) {
}

FileTransferNode::~FileTransferNode() {}

void FileTransferNode::init() {
	PacketTransferBase::init();
	this->getReceiverManager()->registerHandler(UseCircuitCode_ID, new UseCircuitCodePacketHandler());
	this->getReceiverManager()->registerHandler(CloseCircuit_ID, new CloseCircuitPacketHandler());
	this->getReceiverManager()->registerHandler(FileInfo_ID, new FileInfoPacketHandler());
	this->getReceiverManager()->registerHandler(FileInfoReply_ID, new FileInfoReplyPacketHandler());
	this->getReceiverManager()->registerHandler(FileData_ID, new FileDataPacketHandler());
}

ClientConnectionBase *FileTransferNode::createClientConnection(uint32_t circuit_code, const EndPoint *ep) {
	return new FileTransferClientConnection(circuit_code, *ep, this);
}

bool FileTransferNode::ignoreInProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id) {
	return (packet_id == OPEN_CONNECTION_PACKET);
}

// file sender methods
void FileTransferNode::openConnection(const EndPoint &ep) {
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

void FileTransferNode::closeConnection(const EndPoint &ep) {
	PacketBase *packet = FileTransferPacketFactorySingleton::get().createPacket(CloseCircuit_ID);
	CloseCircuitPacket *close_circuit_packet = dynamic_cast<CloseCircuitPacket *>(packet);
	this->sendPacket(close_circuit_packet, &ep);
	this->removeConnection(&ep);
}

void FileTransferNode::startSendFile(const string &file_path, const EndPoint &ep) {
	// send a FileInfoPacket
	PacketBase *packet = FileTransferPacketFactorySingleton::get().createPacket(FileInfo_ID);
	FileInfoPacket *file_info_packet = dynamic_cast<FileInfoPacket *>(packet);
	file_info_packet->FileInfo.Size = 15908;
	PacketBuffer buffer(reinterpret_cast<const unsigned char*>(file_path.c_str()), file_path.size());
	file_info_packet->FileInfo.Name = buffer;
	this->sendPacket(file_info_packet, &ep);
}

