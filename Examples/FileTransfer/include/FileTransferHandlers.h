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
#include "fanni/FTPackets/FTPackets.h"
#include "fanni/FTPackets/FTPacketFactory.h"

#include "fanni/rUDP/PacketHandlerFactory.h"
#include "FileTransferClientConnection.h"
#include "FileTransferNode.h"

namespace Fanni {

// System Packet Handlers
class OpenConnectionPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection) const {
		TRACE_LOG("enter");
		const OpenConnectionPacket *open_conn_packet = dynamic_cast<const OpenConnectionPacket *> (packet);
		assert(open_conn_packet);
		// send reply
		std::auto_ptr<OpenConnectionReplyPacket> reply_packet(dynamic_cast<OpenConnectionReplyPacket *>(FTPacketFactorySingleton::get().createPacket(OpenConnectionReply_ID)));
		assert(reply_packet.get());
		reply_packet->OpenConnectionReply.Code = open_conn_packet->OpenConnection.Code;
		connection->sendPacket(reply_packet.release());
		TRACE_LOG("exit");
	};
};

class CloseConnectionPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *connection) const {
		INFO_LOG("FileTransfer", "reply to close connection request");
		std::auto_ptr<CloseConnectionPacket> packet(dynamic_cast<CloseConnectionPacket *>(FTPacketFactorySingleton::get().createPacket(CloseConnection_ID)));
		connection->getTransferNode().sendPacket(packet.release(), connection->getAddr());
		// TODO @@@ solve this !!
		//node->removeConnection(addr);
	};
};

class CloseConnectionReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection_base) const {
		INFO_LOG("FileTransfer", "got close connection reply");
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(connection_base);
		assert(connection);
		//connection->OnCloseConnectionReply(connection);
		// TODO @@@
		//node->removeConnection(addr);
	};
};

// Connection Event Packet Handlers
class OpenConnectionReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection_base) const {
		const OpenConnectionReplyPacket *open_conn_reply_packet = dynamic_cast<const OpenConnectionReplyPacket *> (packet);
		assert(open_conn_reply_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(connection_base);
		assert(connection);
		connection->OnOpenConnectionReply(connection);
	};
};

class FileInfoPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection_base) const {
		TRACE_LOG("enter");
		const FileInfoPacket *file_info_packet = dynamic_cast<const FileInfoPacket *> (packet);
		assert(file_info_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(connection_base);
		assert(connection);
		connection->OnFileInfo(file_info_packet->FileInfo.Size, file_info_packet->FileInfo.Name.asString(), file_info_packet->FileInfo.SenderTransferID.val, connection);
		TRACE_LOG("exit");
	};
};

class FileInfoReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection_base) const {
		TRACE_LOG("enter");
		const FileInfoReplyPacket *file_info_reply_packet = dynamic_cast<const FileInfoReplyPacket *> (packet);
		assert(file_info_reply_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(connection_base);
		assert(connection);
		connection->OnFileInfoReply(file_info_reply_packet->FileInfo.ReceiverTransferID.val, file_info_reply_packet->FileInfo.SenderTransferID.val, connection);
		TRACE_LOG("exit");
	};
};

class FileDataPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection_base) const {
		TRACE_LOG("enter");
		const FileDataPacket *file_data_packet = dynamic_cast<const FileDataPacket *> (packet);
		assert(file_data_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(connection_base);
		assert(connection);
		connection->OnFileData(file_data_packet->FileData.ReceiverTransferID.val, file_data_packet->FileData.DataNumber, file_data_packet->FileData.Data.val, connection);
		TRACE_LOG("exit");
	};
};

class TransferCompletePacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, ConnectionBase *connection_base) const {
		TRACE_LOG("enter");
		const TransferCompletePacket *transfer_complete_packet = dynamic_cast<const TransferCompletePacket *>(packet);
		assert(transfer_complete_packet);
		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(connection_base);
		assert(connection);
		connection->OnFileTransferComplete(transfer_complete_packet->FileData.SenderTransferID.val, connection);
		TRACE_LOG("exit");
	};
};

}

#endif /* PACKETHANDLERS_H_ */
