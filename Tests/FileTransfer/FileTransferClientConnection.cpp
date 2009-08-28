/*
 * FileTransferClientConnection.cpp
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#include "FileTransferPackets/FileTransferPacketFactory.h"
#include "FileTransferPackets/FileTransferPacketsID.h"
#include "FileTransferPackets/FileTransferPackets.h"
#include "FileTransferClientConnection.h"

using namespace Fanni;
using namespace Fanni::Tests;

FileTransferClientConnection::FileTransferClientConnection(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_base) :
	ClientConnectionBase(circuit_code, ep, transfer_base){
}

FileTransferClientConnection::~FileTransferClientConnection() {
	for(FILE_TRANSFER_STATUS_MAP_TYPE::iterator it=this->file_transfer_status_map.begin(); it!=this->file_transfer_status_map.end(); it++) {
		delete it->second;
	}
}

void FileTransferClientConnection::addFileTransfer(FileTransferStatus *status) {
	S_MUTEX_LOCK l;
	l.lock(&this->file_transfer_status_map_lock);
	this->file_transfer_status_map[status->TransferID.toString()] = status;
}

// =============
// events
void FileTransferClientConnection::OnFileInfoEvent::operator ()(uint32_t file_size, const std::string &file_name, FileTransferClientConnection *connection) {
	TRACE_LOG("enter");
	DEBUG_LOG("size: " << file_size);
	DEBUG_LOG("name: " << file_name);

	FileTransferStatus *status = new FileTransferStatus(file_size, file_name);
	connection->addFileTransfer(status);

	// send reply packet
	PacketBase *packet = FileTransferPacketFactorySingleton::get().createPacket(FileInfoReply_ID);
	FileInfoReplyPacket *file_info_reply_packet = dynamic_cast<FileInfoReplyPacket *>(packet);
	file_info_reply_packet->FileInfo.TransferID = status->TransferID;
	connection->sendPacket(file_info_reply_packet);

	TRACE_LOG("exit");
}

void FileTransferClientConnection::OnFileInfoReplyEvent::operator ()(UUID &transfer_id, const std::string &file_name, FileTransferClientConnection *transfer_peer) {
	TRACE_LOG("enter");
	DEBUG_LOG("transfer_id: " << transfer_id.toString());
	DEBUG_LOG("name: " << file_name);

	// read file, split
	// send file data packets

	TRACE_LOG("exit");
}

void FileTransferClientConnection::OnFileDataEvent::operator ()(UUID &transfer_id, const std::string &file_name, FileTransferClientConnection *transfer_peer) {
	;
}

void FileTransferClientConnection::OnFileTransferCompleteEvent::operator ()(UUID &transfer_id, FileTransferClientConnection *transfer_peer) {
	;
}

