/*
 * QueuePacketTransferHandlers.h
 *
 *  Created on: Aug 9, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERS_H_
#define PACKETHANDLERS_H_

#include <cassert>
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
		transfer_peer->addConnection(open_conn_packet->OpenConnection.Code, ep);
		// send reply
		OpenConnectionReplyPacket *reply_packet = dynamic_cast<OpenConnectionReplyPacket *>(FileTransferPacketFactorySingleton::get().createPacket(OpenConnectionReply_ID));
		assert(reply_packet);
		reply_packet->OpenConnectionReply.Code = open_conn_packet->OpenConnection.Code;
		transfer_peer->sendPacket(reply_packet, ep);
		delete packet;
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
		delete packet;
	};
};

class CloseConnectionPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		delete packet;
		transfer_peer->removeConnection(ep);
	};
};

class FileInfoPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const FileInfoPacket *file_info_packet = dynamic_cast<const FileInfoPacket *> (packet);
		if (file_info_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		// TODO @@@ asset(connection); // !!
		connection->OnFileInfo(file_info_packet->FileInfo.Size, file_info_packet->FileInfo.Name.c_str(), file_info_packet->FileInfo.SenderTransferID.val, connection);
		delete packet;
		TRACE_LOG("exit");
	};
};

class FileInfoReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const FileInfoReplyPacket *file_info_reply_packet = dynamic_cast<const FileInfoReplyPacket *> (packet);
		if (file_info_reply_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		UUID receiver_transfer_id = file_info_reply_packet->FileInfo.ReceiverTransferID.val;
		UUID sender_transfer_id = file_info_reply_packet->FileInfo.SenderTransferID.val;
		DEBUG_LOG("receiver_transfer_id: " << receiver_transfer_id.toString());
		DEBUG_LOG("sender_transfer_id: " << sender_transfer_id.toString());
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		assert(connection);
		connection->OnFileInfoReply(receiver_transfer_id, sender_transfer_id, connection);
		delete packet;
		TRACE_LOG("exit");
	};
};

class FileDataPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const FileDataPacket *file_data_packet = dynamic_cast<const FileDataPacket *> (packet);
		if (file_data_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		delete packet;
		TRACE_LOG("exit");
	};
};

}
}

#endif /* PACKETHANDLERS_H_ */
