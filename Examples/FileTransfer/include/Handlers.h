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
#include "fanni/EndPoint.h"
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
class OpenConnectionPacketHandler : public SystemPacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, const EndPoint &ep, TransferNode &node) const {
		TRACE_LOG("enter");
		ConnectionBase &conn = node.createConnection(packet_base, ep);
		// send reply
		std::auto_ptr<OpenConnectionReplyPacket> reply_packet(dynamic_cast<OpenConnectionReplyPacket *>(FTPacketFactorySingleton::get().createPacket(OpenConnectionReply_ID)));
		assert(reply_packet.get());
		reply_packet->OpenConnectionReply.Code = conn.getCircuitCode();
		node.sendPacket(reply_packet.release(), ep);
		TRACE_LOG("exit");
	};
};

class OpenConnectionReplyPacketHandler : public SystemPacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, const EndPoint &ep, TransferNode &node) const {
		TRACE_LOG("enter");
		ConnectionBase &conn_base = node.createConnection(packet_base, ep);
		Connection *conn = dynamic_cast<Connection *>(&conn_base);
		assert(conn);
		conn->OnOpenConnectionReply(conn);
		TRACE_LOG("exit");
	};
};

class CloseConnectionPacketHandler : public SystemPacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, const EndPoint &ep, TransferNode &node) const {
		INFO_LOG("FileTransfer", "reply to close connection request");
		std::auto_ptr<CloseConnectionReplyPacket> packet(dynamic_cast<CloseConnectionReplyPacket *>(FTPacketFactorySingleton::get().createPacket(CloseConnectionReply_ID)));
		node.sendPacket(packet.release(), ep);
		// TODO @@@ solve this !!?
		node.removeConnection(ep);
	};
};

class CloseConnectionReplyPacketHandler : public SystemPacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, const EndPoint &ep, TransferNode &node) const {
		INFO_LOG("FileTransfer", "got close connection reply");
		node.removeConnection(ep);
	};
};

// Connection Event Packet Handlers
class FileInfoPacketHandler : public ClientPacketHandlerBase {
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

class FileInfoReplyPacketHandler : public ClientPacketHandlerBase {
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

class FileDataPacketHandler : public ClientPacketHandlerBase {
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

class TransferCompletePacketHandler : public ClientPacketHandlerBase {
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
