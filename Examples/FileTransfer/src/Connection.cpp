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

void TransferNodeConnectionBase::addTransferStatus(StatusPtr &pStatus) {
	Poco::FastMutex::ScopedLock l(this->status_map);
	this->status_map[pStatus->getTransferID().toString()] = pStatus;
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
	this->setName("ClientConnection_" + ep.toString());
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

bool ClientConnection::sendFile(const std::string &file_path) {
	int file_size = FileUtils::get_file_size(file_path);
	if (file_size < 0) return false;
	StatusPtr pStatus = this->createStatus(file_size, file_path, UUIDGeneratorSingleton::get().Create());
	this->addTransferStatus(pStatus);
	// send a FileInfoPacket
	FileInfoPacket *packet = new FileInfoPacket();
	assert(packet);
	packet->FileInfo.SenderTransferID = pStatus->getTransferID();
	packet->FileInfo.Size = file_size;
	packet->FileInfo.Name = file_path;
	PacketBasePtr pPacket(packet);
	this->sendPacket(pPacket);
	INFO_LOG("file transfer started, wait until complete");
	pStatus->waitComplete();
	if (pStatus->isFailed()) {
		ERROR_LOG("send_transfer failed: " << pStatus->getTransferID().toString());
		return false;
	} else {
		INFO_LOG("send_transfer completed: " << pStatus->getTransferID().toString());
		this->closeTransfer(pStatus->getTransferID());
		return true;
	}
}

void ClientConnection::onFileInfoReply(const void* pSender, const FileInfoReplyPacket &packet) {
	TRACE_LOG("enter");
	UUID transfer_id = packet.FileInfo.ReceiverTransferID.val; // TODO @@@ remove val
	StatusPtr pStatus;
	try {
		pStatus = this->getTransfer(transfer_id);
	} catch (Poco::NotFoundException &ex) {
		WARN_LOG("onFileInfoReply: can not find transfer for: " << transfer_id.toString() << " " << ex.message());
		return;
	}
	// read file , send
	ifstream fs(pStatus->getFileName().c_str(), ios::binary);
	if (fs.fail()) {
		ERROR_LOG("unable to open file for reading" << pStatus->getFileName());
		pStatus->failed();
		return;
	}

	size_t total_size = pStatus->getFileSize();
	size_t left_size = total_size;
	INFO_LOG("start transferring file: " << pStatus->getFileName() << " total size: " << total_size << " packets: " << total_size/FILE_PART_SIZE);
	int data_number = 0;

	unsigned char file_part_buf[FILE_PART_SIZE];
	while(left_size > 0) {
		int read_size = left_size > FILE_PART_SIZE ? FILE_PART_SIZE : left_size;
		fs.read(reinterpret_cast<char*>(file_part_buf), read_size);
		if (read_size != fs.gcount()) {
			WARN_LOG("unmatched read size: " << read_size << " " << fs.gcount());
		}
		read_size = fs.gcount();
		// send file data packet
		FileDataPacket *packet = new FileDataPacket();
		packet->FileData.ReceiverTransferID = pStatus->getTransferID();
		packet->FileData.DataNumber = data_number++;
		packet->FileData.Data.setValue(file_part_buf, read_size);
		packet->setFlag(PacketHeader::FLAG_RELIABLE);
		PacketBasePtr pPacket(packet);
		this->sendPacket(pPacket);
		left_size -= read_size;
		if (data_number % 5 == 0) {
			// MEMO @@@ do not send too much
			Sleep(100);
		}
	}
	fs.close();
	INFO_LOG("read all file contents to transfer queue: " << pStatus->getFileName());

	TRACE_LOG("exit");
}

void ClientConnection::onTransferComplete(const void* pSender, const TransferCompletePacket &packet) {
	TRACE_LOG("enter");
	StatusPtr &pStatus = this->getTransfer(packet.FileData.SenderTransferID.val);
	pStatus->setComplete();
	TRACE_LOG("exit");
}

// ================
// ServerConnection
ServerConnection::ServerConnection(uint32_t circuit_code, const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp):
	TransferNodeConnectionBase(circuit_code, ep, packet_serializer, udp) {
	this->setName("SystemConnection_" + ep.toString());
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
	std::string file_name = packet.FileInfo.Name.asString();
	UUID transfer_id = packet.FileInfo.SenderTransferID.val; // TODO @@@ remove .val
	StatusPtr pStatus = this->createStatus(packet.FileInfo.Size, file_name, transfer_id);
	INFO_LOG("got file info, prepare to receive: " << file_name << " " << transfer_id.toString());
	// send reply packet
	FileInfoReplyPacket *reply_packet = new FileInfoReplyPacket();
	reply_packet->FileInfo.ReceiverTransferID = transfer_id;
	reply_packet->FileInfo.SenderTransferID = transfer_id;
	PacketBasePtr pPacket(reply_packet);
	this->sendPacket(pPacket);
	TRACE_LOG("exit");
}

void ServerConnection::onFileData(const void* pSender, const FileDataPacket &packet) {
	TRACE_LOG("enter");
	StatusPtr pStatus;
	try {
		pStatus = this->getTransfer(packet.FileData.ReceiverTransferID.val);
	} catch (Poco::NotFoundException &ex) {
		WARN_LOG("unknown FileDataPacket: " << ex.message());
		return;
	}
	if (pStatus->update(packet.FileData.DataNumber, &packet.FileData.Data.val[0], packet.FileData.Data.val.size())) {
		// send back to sender
		TransferCompletePacket *complete_packet = new TransferCompletePacket();
		complete_packet->FileData.SenderTransferID = pStatus->getTransferID();
		PacketBasePtr pPacket(complete_packet);
		this->sendPacket(pPacket);

		INFO_LOG("received all file data: " << pStatus->getFileName() << " " << packet.FileData.ReceiverTransferID.val.toString());
		string out_file = pStatus->getFileName() + "_" + packet.FileData.ReceiverTransferID.val.toString();
		ofstream fs(out_file.c_str(), ios::binary);
		if (fs.fail()) {
			ERROR_LOG("unable to open file for writing" << out_file);
			return;
		}
		fs.write(reinterpret_cast<const char *>(pStatus->getFileBuffer()), pStatus->getFileSize());
		fs.close();
		// close this transfer, release memory // server
		this->closeTransfer(packet.FileData.ReceiverTransferID.val);
	}
	TRACE_LOG("exit");
}

