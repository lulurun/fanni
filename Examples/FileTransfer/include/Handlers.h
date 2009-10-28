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
#include "Connection.h"
#include "Node.h"

namespace Fanni {
namespace FileTransfer {

// System Packet Handlers
class OpenConnectionPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		TRACE_LOG("enter");
		const OpenConnectionPacket *packet = dynamic_cast<const OpenConnectionPacket *>(packet_base);
		assert(packet);
		// send reply
		std::auto_ptr<OpenConnectionReplyPacket> reply_packet(dynamic_cast<OpenConnectionReplyPacket *>(FTPacketFactorySingleton::get().createPacket(OpenConnectionReply_ID)));
		assert(reply_packet.get());
		reply_packet->OpenConnectionReply.Code = packet->OpenConnection.Code;
		conn_base->sendPacket(reply_packet.release());
		TRACE_LOG("exit");
	};
};

class CloseConnectionPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		INFO_LOG("FileTransfer", "reply to close connection request");
		std::auto_ptr<CloseConnectionPacket> packet(dynamic_cast<CloseConnectionPacket *>(FTPacketFactorySingleton::get().createPacket(CloseConnection_ID)));
		conn_base->getTransferNode().sendPacket(packet.release(), conn_base->getAddr());
		// TODO @@@ solve this !!
		//node->removeConnection(addr);
	};
};

class CloseConnectionReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		INFO_LOG("FileTransfer", "got close connection reply");
		Connection *conn = dynamic_cast<Connection *>(conn_base);
		assert(conn);
		//node->removeConnection(conn->getAddr());
	};
};

// Connection Event Packet Handlers
class OpenConnectionReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		Connection *conn = dynamic_cast<Connection *>(conn_base);
		assert(conn);
		conn->OnOpenConnectionReply(conn);
	};
};

class FileInfoPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		TRACE_LOG("enter");
		const FileInfoPacket *packet = dynamic_cast<const FileInfoPacket *>(packet_base);
		assert(packet);
		Connection *conn = dynamic_cast<Connection *>(conn_base);
		assert(conn);
		conn->OnFileInfo(packet->FileInfo.Size, packet->FileInfo.Name.asString(), packet->FileInfo.SenderTransferID.val, conn);
		TRACE_LOG("exit");
	};
};

class FileInfoReplyPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		TRACE_LOG("enter");
		const FileInfoReplyPacket *packet = dynamic_cast<const FileInfoReplyPacket *>(packet_base);
		assert(packet);
		Connection *conn = dynamic_cast<Connection *>(conn_base);
		assert(conn);
		conn->OnFileInfoReply(packet->FileInfo.ReceiverTransferID.val, packet->FileInfo.SenderTransferID.val, conn);
		TRACE_LOG("exit");
	};
};

class FileDataPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		TRACE_LOG("enter");
		const FileDataPacket *packet = dynamic_cast<const FileDataPacket *>(packet_base);
		assert(packet);
		Connection *conn = dynamic_cast<Connection *>(conn_base);
		assert(conn);
		conn->OnFileData(packet->FileData.ReceiverTransferID.val, packet->FileData.DataNumber, packet->FileData.Data.val, conn);
		TRACE_LOG("exit");
	};
};

class TransferCompletePacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, ConnectionBase *conn_base) const {
		TRACE_LOG("enter");
		const TransferCompletePacket *packet = dynamic_cast<const TransferCompletePacket *>(packet_base);
		assert(packet);
		Connection *conn = dynamic_cast<Connection *>(conn_base);
		assert(conn);
		conn->OnFileTransferComplete(packet->FileData.SenderTransferID.val, conn);
		TRACE_LOG("exit");
	};
};

}
}

#endif /* PACKETHANDLERS_H_ */
