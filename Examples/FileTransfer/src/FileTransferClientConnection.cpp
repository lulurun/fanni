/*
 * FileTransferClientConnection.cpp
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>

#include "fanni/Sleep.h"
#include "fanni/Logger.h"
#include "fanni/FTPackets/FTPacketFactory.h"
#include "fanni/FTPackets/FTPacketsID.h"
#include "fanni/FTPackets/FTPackets.h"
#include "FileTransferNode.h"
#include "FileTransferClientConnection.h"
#include "FileUtils.h"

using namespace std;
using namespace Fanni;

FileTransferClientConnection::FileTransferClientConnection(uint32_t circuit_code, const Poco::Net::SocketAddress &addr, TransferNode &node) :
	ConnectionBase(circuit_code, addr, node){
}

FileTransferClientConnection::~FileTransferClientConnection() {
	// TODO @@@ thread safe
	for(FILE_TRANSFER_STATUS_MAP::Iterator it=this->receive_transfer_status_map.begin(); it!=this->receive_transfer_status_map.end(); it++) {
		delete it->second;
	}
	for(FILE_TRANSFER_STATUS_MAP::Iterator it=this->send_transfer_status_map.begin(); it!=this->send_transfer_status_map.end(); it++) {
		delete it->second;
	}
}

// ================
// receive transfer
void FileTransferClientConnection::addReceiveFileTransfer(FileTransferStatus *status) {
	Poco::FastMutex::ScopedLock l(this->receive_transfer_status_map);
	this->receive_transfer_status_map[status->getReceiverTransferID().toString()] = status;
}

FileTransferStatus *FileTransferClientConnection::getReceiveFileTransfer(const UUID &receiver_transfer_id) {
	Poco::FastMutex::ScopedLock l(this->receive_transfer_status_map);
	return this->_getReceiveFileTransfer_nolock(receiver_transfer_id);
}

FileTransferStatus *FileTransferClientConnection::_getReceiveFileTransfer_nolock(const UUID &receiver_transfer_id) {
	FILE_TRANSFER_STATUS_MAP::Iterator it = this->receive_transfer_status_map.find(receiver_transfer_id.toString());
	if (it == this->receive_transfer_status_map.end()) {
		// not found
		return NULL;
	} else {
		return it->second;
	}
}

void FileTransferClientConnection::closeReceiveTransfer(const UUID &receiver_transfer_id) {
	Poco::FastMutex::ScopedLock l(this->receive_transfer_status_map);
	FileTransferStatus *status = this->_getReceiveFileTransfer_nolock(receiver_transfer_id);
	if (status) {
		INFO_LOG("FileTransfer", "receive transfer success: " << receiver_transfer_id.toString());
		this->receive_transfer_status_map.erase(receiver_transfer_id.toString());
		delete status;
	} else {
		WARN_LOG("FileTransfer", "receive transfer: " << receiver_transfer_id.toString() << " is no longer under manage");
	}
}

// ================
// send transfer
void FileTransferClientConnection::addSendFileTransfer(FileTransferStatus *status) {
	Poco::FastMutex::ScopedLock l(this->send_transfer_status_map);
	this->send_transfer_status_map[status->getSenderTransferID().toString()] = status;
}

FileTransferStatus *FileTransferClientConnection::getSendFileTransfer(const UUID &sender_transfer_id) {
	Poco::FastMutex::ScopedLock l(this->send_transfer_status_map);
	return this->_getSendFileTransfer_nolock(sender_transfer_id);
}

FileTransferStatus *FileTransferClientConnection::_getSendFileTransfer_nolock(const UUID &sender_transfer_id) {
	FILE_TRANSFER_STATUS_MAP::Iterator it = this->send_transfer_status_map.find(sender_transfer_id.toString());
	if (it == this->send_transfer_status_map.end()) {
		// not found
		return NULL;
	} else {
		return it->second;
	}
}

void FileTransferClientConnection::closeSendTransfer(const UUID &sender_transfer_id) {
	Poco::FastMutex::ScopedLock l(this->send_transfer_status_map);
	FileTransferStatus *status = this->_getSendFileTransfer_nolock(sender_transfer_id);
	if (status) {
		INFO_LOG("FileTransfer", "send transfer success: " << sender_transfer_id.toString());
		this->send_transfer_status_map.erase(sender_transfer_id.toString());
		delete status;
	} else {
		WARN_LOG("FileTransfer","send transfer: " << sender_transfer_id.toString() << " is no longer under manage");
	}
}

//Server Events
void FileTransferClientConnection::OnFileInfoEvent::operator ()(uint32_t file_size, const std::string &file_name, const UUID &sender_transfer_id, FileTransferClientConnection *connection) {
	TRACE_LOG("enter");
	UUID receiver_transfer_id = UUIDGeneratorSingleton::get().Create();
	// TODO @@@ memory management: status is generated here // server
	std::auto_ptr<FileTransferStatus> status(new FileTransferStatus(file_size, file_name, receiver_transfer_id, sender_transfer_id, true));
	INFO_LOG("FileTransfer", "add transfer: " << status->getReceiverTransferID().toString());
	connection->addReceiveFileTransfer(status.release());
	// send reply packet
	std::auto_ptr<FileInfoReplyPacket> packet(dynamic_cast<FileInfoReplyPacket *>(FTPacketFactorySingleton::get().createPacket(FileInfoReply_ID)));
	assert(packet.get());
	packet->FileInfo.ReceiverTransferID = status->getReceiverTransferID();
	packet->FileInfo.SenderTransferID = status->getSenderTransferID();
	connection->sendPacket(packet.release());
	TRACE_LOG("exit");
}

void FileTransferClientConnection::OnFileDataEvent::operator ()(const UUID &receiver_transfer_id, int data_number, const vector<unsigned char> &data_buf, FileTransferClientConnection *connection) {
	TRACE_LOG("enter");
	FileTransferStatus *status = connection->getReceiveFileTransfer(receiver_transfer_id);
	if (status == NULL) {
		//ERROR_LOG("unknown transfer id: " << receiver_transfer_id.toString());
		return;
	}
	if (status->update(data_number, &data_buf[0], data_buf.size())) {
		// send back to sender
		std::auto_ptr<TransferCompletePacket> packet(dynamic_cast<TransferCompletePacket *>(FTPacketFactorySingleton::get().createPacket(TransferComplete_ID)));
		assert(packet.get());
		packet->FileData.SenderTransferID = status->getSenderTransferID();
		connection->sendPacket(packet.release());

		INFO_LOG("FileTransfer", "TransferComplete: " << status->getFileName() << " " << status->getReceiverTransferID().toString());
		string out_file = status->getFileName() + "_" + receiver_transfer_id.toString();
		ofstream fs(out_file.c_str(), ios::binary);
		if (fs.fail()) {
			ERROR_LOG("FileTransfer", "unable to open file for writing" << out_file);
			return;
		}
		fs.write(reinterpret_cast<const char *>(status->getFileBuffer()), status->getFileSize());
		fs.close();
		// close this transfer, release memory // server
		connection->closeReceiveTransfer(receiver_transfer_id);
	}
	TRACE_LOG("exit");
}

// Client Events
void FileTransferClientConnection::OnOpenConnectionReplyEvent::operator ()(FileTransferClientConnection *connection) {
	TRACE_LOG("enter");
	FileTransferNode *node = dynamic_cast<FileTransferNode *>(&connection->node);
	assert(node);
	string file_path = node->getSendFile();
	size_t file_size = FileUtils::get_file_size(file_path);

	// TODO @@@ memory management: status is generated here // client
	std::auto_ptr<FileTransferStatus> status(new FileTransferStatus(file_size, file_path, UUIDGeneratorSingleton::get().Zero(), UUIDGeneratorSingleton::get().Create()));
	connection->addSendFileTransfer(status.release());

	// send a FileInfoPacket
	std::auto_ptr<FileInfoPacket> packet(dynamic_cast<FileInfoPacket *>(FTPacketFactorySingleton::get().createPacket(FileInfo_ID)));
	assert(packet.get());
	packet->FileInfo.SenderTransferID = status->getSenderTransferID();
	packet->FileInfo.Size = status->getFileSize();
	PacketBuffer buffer(reinterpret_cast<const unsigned char*>(status->getFileName().c_str()), status->getFileName().size());
	packet->FileInfo.Name = buffer;
	connection->sendPacket(packet.release());
	TRACE_LOG("exit");
}

// memo @@@ client_transfer_id is for multiple file transfer ...
void FileTransferClientConnection::OnFileInfoReplyEvent::operator ()(const UUID &receiver_transfer_id, const UUID &sender_transfer_id, FileTransferClientConnection *connection) {
	TRACE_LOG("enter");
	FileTransferStatus *status = connection->getSendFileTransfer(sender_transfer_id);
	if (!status) {
		ERROR_LOG("FileTransfer", "can not find file transfer status for " << sender_transfer_id.toString());
		return;
	}
	// update receiver transfer id
	status->setReceiverTransferID(receiver_transfer_id);
	// read file , send
	ifstream fs(status->getFileName().c_str(), ios::binary);
	if (fs.fail()) {
		ERROR_LOG("FileTransfer", "unable to open file for reading" << status->getFileName());
		status->failed();
		return;
	}

	size_t total_size = status->getFileSize();
	size_t left_size = total_size;
	INFO_LOG("FileTransfer","start transferring file: " << status->getFileName() << " total size: " << total_size << " packets: " << total_size/FILE_PART_SIZE);
	int data_number = 0;
	while(left_size > 0) {
		int read_size = left_size > FILE_PART_SIZE ? FILE_PART_SIZE : left_size;
		PacketBuffer buffer;
		fs.read(reinterpret_cast<char*>(buffer.getBuffer()), read_size);
		if (read_size != fs.gcount()) {
			WARN_LOG("FileTransfer", "unmatched read size: " << read_size << " " << fs.gcount());
		}
		buffer.setLength(fs.gcount());
		// send file data packet
		std::auto_ptr<FileDataPacket> packet(dynamic_cast<FileDataPacket *>(FTPacketFactorySingleton::get().createPacket(FileData_ID)));
		assert(packet.get());
		packet->FileData.ReceiverTransferID = status->getReceiverTransferID();
		packet->FileData.DataNumber = data_number++;
		packet->FileData.Data = buffer;
		packet->setFlag(PacketHeader::FLAG_RELIABLE);
		connection->sendPacket(packet.release());
		left_size -= read_size;
		if (data_number % 5000 == 0) {
			// MEMO @@@ do not send too much
			Sleep(1000);
		}
	}
	fs.close();

	TRACE_LOG("exit");
}

void FileTransferClientConnection::OnFileTransferCompleteEvent::operator ()(const UUID &sender_transfer_id, FileTransferClientConnection *connection) {
	TRACE_LOG("enter");
	// close this transfer
	connection->closeSendTransfer(sender_transfer_id);
	INFO_LOG("FileTransfer", "send_transfer completed: " << sender_transfer_id.toString());
	std::auto_ptr<CloseConnectionPacket> packet(dynamic_cast<CloseConnectionPacket *>(FTPacketFactorySingleton::get().createPacket(CloseConnection_ID)));
	assert(packet.get());
	connection->sendPacket(packet.release());
	TRACE_LOG("exit");
}

