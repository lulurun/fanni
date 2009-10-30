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
#include "fanni/EndPoint.h"
#include "fanni/Logger.h"
#include "fanni/FTPackets/FTPacketFactory.h"
#include "fanni/FTPackets/FTPacketsID.h"
#include "fanni/FTPackets/FTPackets.h"
#include "Node.h"
#include "FileUtils.h"
#include "Connection.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::FileTransfer;

Connection::Connection(uint32_t circuit_code, const EndPoint &ep, TransferNode &node)
: ConnectionBase(circuit_code, ep, node) {
}

Connection::~Connection() {
	// TODO @@@ thread safe
	for(STATUS_MAP::Iterator it=this->receive_status_map.begin(); it!=this->receive_status_map.end(); it++) {
		delete it->second;
	}
	for(STATUS_MAP::Iterator it=this->send_status_map.begin(); it!=this->send_status_map.end(); it++) {
		delete it->second;
	}
}

// ================
// receive transfer
Status &Connection::createReceiveStatus(uint32_t file_size, const std::string file_name, const UUID &receive_id, const UUID &send_id) {
	Status *status = new Status(file_size, file_name, receive_id, send_id, true);
	Poco::FastMutex::ScopedLock l(this->receive_status_map);
	this->receive_status_map[status->getReceiverTransferID().toString()] = status;
	return *status;
}

Status *Connection::getReceiveTransfer(const UUID &transfer_id) {
	Poco::FastMutex::ScopedLock l(this->receive_status_map);
	return this->_getReceiveTransfer_nolock(transfer_id);
}

Status *Connection::_getReceiveTransfer_nolock(const UUID &transfer_id) {
	STATUS_MAP::Iterator it = this->receive_status_map.find(transfer_id.toString());
	if (it == this->receive_status_map.end()) {
		return NULL;
	} else {
		return it->second;
	}
}

void Connection::closeReceiveTransfer(const UUID &transfer_id) {
	Poco::FastMutex::ScopedLock l(this->receive_status_map);
	Status *status = this->_getReceiveTransfer_nolock(transfer_id);
	if (status) {
		INFO_LOG("FileTransfer", "receive transfer success: " << transfer_id.toString());
		this->receive_status_map.erase(transfer_id.toString());
		delete status;
	} else {
		WARN_LOG("FileTransfer", "receive transfer: " << transfer_id.toString() << " is no longer under manage");
	}
}

// ================
// send transfer
Status &Connection::createSendStatus(uint32_t file_size, const std::string file_name, const UUID &receive_id, const UUID &send_id) {
	Status *status = new Status(file_size, file_name, receive_id, send_id, false);
	Poco::FastMutex::ScopedLock l(this->send_status_map);
	this->send_status_map[status->getSenderTransferID().toString()] = status;
	return *status;
}

Status *Connection::getSendTransfer(const UUID &transfer_id) {
	Poco::FastMutex::ScopedLock l(this->send_status_map);
	return this->_getSendTransfer_nolock(transfer_id);
}

Status *Connection::_getSendTransfer_nolock(const UUID &transfer_id) {
	STATUS_MAP::Iterator it = this->send_status_map.find(transfer_id.toString());
	if (it == this->send_status_map.end()) {
		// not found
		return NULL;
	} else {
		return it->second;
	}
}

void Connection::closeSendTransfer(const UUID &transfer_id) {
	Poco::FastMutex::ScopedLock l(this->send_status_map);
	Status *status = this->_getSendTransfer_nolock(transfer_id);
	if (status) {
		INFO_LOG("FileTransfer", "send transfer success: " << transfer_id.toString());
		this->send_status_map.erase(transfer_id.toString());
		delete status;
	} else {
		WARN_LOG("FileTransfer","send transfer: " << transfer_id.toString() << " is no longer under manage");
	}
}

//Server Events
void Connection::OnFileInfoEvent::operator ()(uint32_t file_size, const std::string &file_name, const UUID &send_id, Connection *conn) {
	TRACE_LOG("enter");
	UUID receive_id = UUIDGeneratorSingleton::get().Create();
	Status &status = conn->createReceiveStatus(file_size, file_name, receive_id, send_id);
	// send reply packet
	std::auto_ptr<FileInfoReplyPacket> packet(dynamic_cast<FileInfoReplyPacket *>(FTPacketFactorySingleton::get().createPacket(FileInfoReply_ID)));
	assert(packet.get());
	packet->FileInfo.ReceiverTransferID = status.getReceiverTransferID();
	packet->FileInfo.SenderTransferID = status.getSenderTransferID();
	conn->sendPacket(packet.release());
	TRACE_LOG("exit");
}

void Connection::OnFileDataEvent::operator ()(const UUID &receive_id, int data_number, const vector<unsigned char> &data_buf, Connection *conn) {
	TRACE_LOG("enter");
	Status *status = conn->getReceiveTransfer(receive_id);
	if (status == NULL) {
		ERROR_LOG("FileTransfer", "unknown transfer id: " << receive_id.toString());
		return;
	}
	if (status->update(data_number, &data_buf[0], data_buf.size())) {
		// send back to sender
		std::auto_ptr<TransferCompletePacket> packet(dynamic_cast<TransferCompletePacket *>(FTPacketFactorySingleton::get().createPacket(TransferComplete_ID)));
		assert(packet.get());
		packet->FileData.SenderTransferID = status->getSenderTransferID();
		conn->sendPacket(packet.release());

		INFO_LOG("FileTransfer", "TransferComplete: " << status->getFileName() << " " << status->getReceiverTransferID().toString());
		string out_file = status->getFileName() + "_" + receive_id.toString();
		ofstream fs(out_file.c_str(), ios::binary);
		if (fs.fail()) {
			ERROR_LOG("FileTransfer", "unable to open file for writing" << out_file);
			return;
		}
		fs.write(reinterpret_cast<const char *>(status->getFileBuffer()), status->getFileSize());
		fs.close();
		// close this transfer, release memory // server
		conn->closeReceiveTransfer(receive_id);
	}
	TRACE_LOG("exit");
}

// Client Events
void Connection::OnOpenConnectionReplyEvent::operator ()(Connection *conn) {
	TRACE_LOG("enter");
	Node *node = dynamic_cast<Node *>(&conn->node);
	assert(node);
	string file_path = node->getSendFile();
	size_t file_size = FileUtils::get_file_size(file_path);

	Status &status = conn->createSendStatus(file_size, file_path, UUIDGeneratorSingleton::get().Zero(), UUIDGeneratorSingleton::get().Create());
	// send a FileInfoPacket
	std::auto_ptr<FileInfoPacket> packet(dynamic_cast<FileInfoPacket *>(FTPacketFactorySingleton::get().createPacket(FileInfo_ID)));
	assert(packet.get());
	packet->FileInfo.SenderTransferID = status.getSenderTransferID();
	packet->FileInfo.Size = status.getFileSize();
	packet->FileInfo.Name = status.getFileName();
	conn->sendPacket(packet.release());
	TRACE_LOG("exit");
}

// memo @@@ client_transfer_id is for multiple file transfer ...
void Connection::OnFileInfoReplyEvent::operator ()(const UUID &receive_id, const UUID &send_id, Connection *conn) {
	TRACE_LOG("enter");
	Status *status = conn->getSendTransfer(send_id);
	if (!status) {
		ERROR_LOG("FileTransfer", "can not find file transfer status for " << send_id.toString());
		return;
	}
	// update receiver transfer id
	status->setReceiverTransferID(receive_id);
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

	unsigned char file_part_buf[FILE_PART_SIZE];
	while(left_size > 0) {
		int read_size = left_size > FILE_PART_SIZE ? FILE_PART_SIZE : left_size;
		fs.read(reinterpret_cast<char*>(file_part_buf), read_size);
		if (read_size != fs.gcount()) {
			WARN_LOG("FileTransfer", "unmatched read size: " << read_size << " " << fs.gcount());
		}
		read_size = fs.gcount();
		// send file data packet
		std::auto_ptr<FileDataPacket> packet(dynamic_cast<FileDataPacket *>(FTPacketFactorySingleton::get().createPacket(FileData_ID)));
		assert(packet.get());
		packet->FileData.ReceiverTransferID = status->getReceiverTransferID();
		packet->FileData.DataNumber = data_number++;
		packet->FileData.Data.setValue(file_part_buf, read_size);
		packet->setFlag(PacketHeader::FLAG_RELIABLE);
		conn->sendPacket(packet.release());
		left_size -= read_size;
		if (data_number % 5000 == 0) {
			// MEMO @@@ do not send too much
			Sleep(1000);
		}
	}
	fs.close();

	TRACE_LOG("exit");
}

void Connection::OnFileTransferCompleteEvent::operator ()(const UUID &send_id, Connection *conn) {
	TRACE_LOG("enter");
	// close this transfer
	conn->closeSendTransfer(send_id);
	INFO_LOG("FileTransfer", "send_transfer completed: " << send_id.toString());
	std::auto_ptr<CloseConnectionPacket> packet(dynamic_cast<CloseConnectionPacket *>(FTPacketFactorySingleton::get().createPacket(CloseConnection_ID)));
	assert(packet.get());
	conn->sendPacket(packet.release());
	TRACE_LOG("exit");
}


