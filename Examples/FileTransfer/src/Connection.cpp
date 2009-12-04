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
#include "fanni/FTPackets/FTPacketsID.h"
#include "fanni/FTPackets/FTPackets.h"
#include "TransferNode.h"
#include "FileUtils.h"
#include "Connection.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::FileTransfer;

TransferNodeConnectionBase::TransferNodeConnectionBase(uint32_t circuit_code, const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp):
	ConnectionBase(ep, packet_serializer, udp), circuit_code(circuit_code) {
}

TransferNodeConnectionBase::~TransferNodeConnectionBase() {
	DEBUG_LOG("TransferNodeConnectionBase destoryed");
}

StatusPtr &TransferNodeConnectionBase::getTransfer(const UUID &trans_id) {
	Poco::FastMutex::ScopedLock l(this->status_map);
	return this->getTransfer_unsafe(trans_id);
}

StatusPtr &TransferNodeConnectionBase::getTransfer_unsafe(const UUID &trans_id) {
	STATUS_MAP::iterator it = this->status_map.find(trans_id.toString());
	if (it == this->status_map.end()) {
		throw Poco::NotFoundException("unknown transfer ID: ", trans_id.toString());
	} else {
		return it->second;
	}
}

void TransferNodeConnectionBase::closeTransfer(const UUID &trans_id) {
	try {
		Poco::FastMutex::ScopedLock l(this->status_map);
		StatusPtr &pStatus = this->getTransfer_unsafe(trans_id); // TODO @@@ needed ?
		INFO_LOG("send transfer success: " << trans_id.toString());
		this->status_map.erase(trans_id.toString());
	} catch (Poco::NotFoundException &ex) {
		WARN_LOG("send transfer is no longer under manage: " << ex.message());
	}
}

// ================
// ClientConnection
ClientConnection::ClientConnection(uint32_t circuit_code, const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp):
	TransferNodeConnectionBase(circuit_code, ep, packet_serializer, udp) {
	this->FileInfoReplyEvent += Poco::Delegate<ClientConnection, const FileInfoReplyPacket>(this, &ClientConnection::onFileInfoReply);
	this->TransferCompleteEvent += Poco::Delegate<ClientConnection, const TransferCompletePacket>(this, &ClientConnection::onTransferComplete);
}

ClientConnection::~ClientConnection() {
	this->FileInfoReplyEvent -= Poco::Delegate<ClientConnection, const FileInfoReplyPacket>(this, &ClientConnection::onFileInfoReply);
	this->TransferCompleteEvent -= Poco::Delegate<ClientConnection, const TransferCompletePacket>(this, &ClientConnection::onTransferComplete);
	DEBUG_LOG("ClientConnection destoryed");
}

StatusPtr ClientConnection::createStatus(uint32_t file_size, const std::string file_name, const UUID &trans_id) {
	StatusPtr pStatus(new Status(file_size, file_name, trans_id, false));
	Poco::FastMutex::ScopedLock l(this->status_map);
	this->status_map[trans_id.toString()] = pStatus;
	return pStatus;
}

void ClientConnection::onFileInfoReply(const void* pSender, const FileInfoReplyPacket &packet) {
	TRACE_LOG("enter");
	/*
	StatusPtr pStatus;
	try {
		pStatus = conn->getTransfer(send_id);
	} catch (Poco::NotFoundException &ex) {
		WARN_LOG("FileTransfer", "onFileInfoReply" << ex.message());
		return;
	}
	// update receiver transfer id
	pStatus->setReceiverTransferID(receive_id);
	// read file , send
	ifstream fs(pStatus->getFileName().c_str(), ios::binary);
	if (fs.fail()) {
		ERROR_LOG("FileTransfer", "unable to open file for reading" << pStatus->getFileName());
		status->failed();
		return;
	}

	size_t total_size = pStatus->getFileSize();
	size_t left_size = total_size;
	INFO_LOG("FileTransfer", "start transferring file: " << pStatus->getFileName() << " total size: " << total_size << " packets: " << total_size/FILE_PART_SIZE);
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
		FileDataPacket *packet = new FileDataPacket();
		packet->FileData.ReceiverTransferID = pStatus->getReceiverTransferID();
		packet->FileData.DataNumber = data_number++;
		packet->FileData.Data.setValue(file_part_buf, read_size);
		packet->setFlag(PacketHeader::FLAG_RELIABLE);
		PacketBasePtr packet_ptr(packet);
		conn->sendPacket(packet_ptr);
		left_size -= read_size;
		if (data_number % 5000 == 0) {
			// MEMO @@@ do not send too much
			Sleep(1000);
		}
	}
	fs.close();
	*/
	TRACE_LOG("exit");
}

void ClientConnection::onTransferComplete(const void* pSender, const TransferCompletePacket &packet) {
	TRACE_LOG("enter");
	/*
	// close this transfer
	conn->closeTransfer(send_id);
	INFO_LOG("FileTransfer", "send_transfer completed: " << send_id.toString());
	*/
	TRACE_LOG("exit");
}

// ================
// ServerConnection
ServerConnection::ServerConnection(uint32_t circuit_code, const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp):
	TransferNodeConnectionBase(circuit_code, ep, packet_serializer, udp) {
	this->FileInfoEvent += Poco::Delegate<ServerConnection, const FileInfoPacket>(this, &ServerConnection::onFileInfo);
	this->FileDataEvent += Poco::Delegate<ServerConnection, const FileDataPacket>(this, &ServerConnection::onFileData);
}

ServerConnection::~ServerConnection() {
	this->FileInfoEvent -= Poco::Delegate<ServerConnection, const FileInfoPacket>(this, &ServerConnection::onFileInfo);
	this->FileDataEvent -= Poco::Delegate<ServerConnection, const FileDataPacket>(this, &ServerConnection::onFileData);
	DEBUG_LOG("ServerConnection destoryed");
}

StatusPtr ServerConnection::createStatus(uint32_t file_size, const std::string file_name, const UUID &trans_id) {
	StatusPtr pStatus(new Status(file_size, file_name, trans_id, true));
	Poco::FastMutex::ScopedLock l(this->status_map);
	this->status_map[trans_id.toString()] = pStatus;
	return pStatus;
}

//Server Events
void ServerConnection::onFileInfo(const void* pSender, const FileInfoPacket &packet) {
	TRACE_LOG("enter");
	/*
	UUID trans_id = UUIDGeneratorSingleton::get().Create();
	StatusPtr status = conn->createStatus(file_size, file_name, trans_id);
	INFO_LOG("FileTransfer", "got file info, prepare to receive: " << pStatus->getFileName() << " " << pStatus->getReceiverTransferID().toString());
	// send reply packet
	FileInfoReplyPacket *packet = new FileInfoReplyPacket();
	packet->FileInfo.ReceiverTransferID = pStatus->getReceiverTransferID();
	packet->FileInfo.SenderTransferID = pStatus->getSenderTransferID();
	PacketBasePtr packet_ptr(packet);
	conn->sendPacket(packet_ptr);
	*/
	TRACE_LOG("exit");
}

void ServerConnection::onFileData(const void* pSender, const FileDataPacket &packet) {
	TRACE_LOG("enter");
	/*
	StatusPtr pStatus;
	try {
		pStatus = conn->getTransfer(receive_id);
	} catch (Poco::NotFoundException &ex) {
		WARN_LOG("FileTransfer", "onFileInfoReply" << ex.message());
		return;
	}
	if (pStatus->update(data_number, &data_buf[0], data_buf.size())) {
		// send back to sender
		TransferCompletePacket *packet = new TransferCompletePacket();
		PacketBasePtr packet_ptr(packet);
		packet->FileData.SenderTransferID = pStatus->getSenderTransferID();
		conn->sendPacket(packet_ptr);

		INFO_LOG("FileTransfer", "TransferComplete: " << pStatus->getFileName() << " " << receive_id.toString());
		string out_file = pStatus->getFileName() + "_" + receive_id.toString();
		ofstream fs(out_file.c_str(), ios::binary);
		if (fs.fail()) {
			ERROR_LOG("FileTransfer", "unable to open file for writing" << out_file);
			return;
		}
		fs.write(reinterpret_cast<const char *>(pStatus->getFileBuffer()), pStatus->getFileSize());
		fs.close();
		// close this transfer, release memory // server
		conn->closeTransfer(receive_id);
	}
	*/
	TRACE_LOG("exit");
}

