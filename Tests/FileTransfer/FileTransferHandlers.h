/*
 * QueuePacketTransferHandlers.h
 *
 *  Created on: Aug 9, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERS_H_
#define PACKETHANDLERS_H_

#include <cassert>
#include <memory>
#include "fanni/UUID.h"
#include "fanni/Logger.h"
#include "FileTransferPackets/FileTransferPackets.h"
#include "FileTransferPackets/FileTransferPacketFactory.h"

#include "PacketTransfer/PacketHandlerFactory.h"
#include "FileTransferClientConnection.h"
#include "FileTransferNode.h"

namespace Fanni {
namespace Tests {

class OpenConnectionPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		const OpenConnectionPacket *open_conn_packet = dynamic_cast<const OpenConnectionPacket *> (packet);
		assert(open_conn_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->addConnection(open_conn_packet->OpenConnection.Code, ep));
		assert(connection);
		// send reply
		OpenConnectionReplyPacket *reply_packet = dynamic_cast<OpenConnectionReplyPacket *>(FileTransferPacketFactorySingleton::get().createPacket(OpenConnectionReply_ID));
		assert(reply_packet);
		reply_packet->OpenConnectionReply.Code = open_conn_packet->OpenConnection.Code;
		connection->sendPacket(reply_packet);
	};
};

class OpenConnectionReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		const OpenConnectionReplyPacket *open_conn_reply_packet = dynamic_cast<const OpenConnectionReplyPacket *> (packet);
		assert(open_conn_reply_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->addConnection(open_conn_reply_packet->OpenConnectionReply.Code, ep));
		assert(connection);
		connection->OnOpenConnectionReply(connection);
	};
};

class CloseConnectionPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		transfer_peer->removeConnection(ep);
	};
};

class FileInfoPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const FileInfoPacket *file_info_packet = dynamic_cast<const FileInfoPacket *> (packet);
		assert(file_info_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		assert(connection);
		connection->OnFileInfo(file_info_packet->FileInfo.Size, file_info_packet->FileInfo.Name.c_str(), file_info_packet->FileInfo.SenderTransferID.val, connection);
		TRACE_LOG("exit");
	};
};

class FileInfoReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const FileInfoReplyPacket *file_info_reply_packet = dynamic_cast<const FileInfoReplyPacket *> (packet);
		assert(file_info_reply_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		assert(connection);
		connection->OnFileInfoReply(file_info_reply_packet->FileInfo.ReceiverTransferID.val, file_info_reply_packet->FileInfo.SenderTransferID.val, connection);
		TRACE_LOG("exit");
	};
};

class FileDataPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const FileDataPacket *file_data_packet = dynamic_cast<const FileDataPacket *> (packet);
		assert(file_data_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		if (!connection) {
			ERROR_LOG("connection is NULL: " << ep->getAddrStr() << " " << ep->getPort());
			return;
		}
		assert(connection);
		connection->OnFileData(file_data_packet->FileData.ReceiverTransferID.val, file_data_packet->FileData.DataNumber, file_data_packet->FileData.Data.val, connection);
		TRACE_LOG("exit");
	};
};

class TransferCompletePacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const TransferCompletePacket *transfer_complete_packet = dynamic_cast<const TransferCompletePacket *>(packet);
		assert(transfer_complete_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		assert(connection);
		connection->OnFileTransferComplete(transfer_complete_packet->FileData.SenderTransferID.val, connection);
		TRACE_LOG("exit");
	};
};

}
}

#endif /* PACKETHANDLERS_H_ */
