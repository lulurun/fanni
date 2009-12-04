/*
 * ConnectionHandler.h
 *
 *  Created on: Aug 9, 2009
 *      Author: lulu
 */

#ifndef CONNECTIONHANDLER_H_
#define CONNECTIONHANDLER_H_

#include <cassert>
#include <memory>
#include "fanni/EndPoint.h"
#include "fanni/UUID.h"
#include "fanni/Logger.h"
#include "fanni/FTPackets/FTPackets.h"
#include "fanni/LLUDP/ConnectionPacketHandler.h"
#include "Connection.h"
#include "TransferNode.h"

namespace Fanni {
namespace FileTransfer {

// Server
class FileInfoPacketHandler : public ConnectionPacketHandlerBase {
public:
	virtual void operator()(ConnectionBase *conn_base, const PacketBasePtr &packet_base) const {
		TRACE_LOG("enter");
		const FileInfoPacket *packet = dynamic_cast<const FileInfoPacket *>(packet_base.get());
		assert(packet);
		ServerConnection *sConn = dynamic_cast<ServerConnection *>(conn_base);
		assert(sConn);
		//sConn->FileIn(sConn, packet);
		TRACE_LOG("exit");
	};
};

class FileDataPacketHandler : public ConnectionPacketHandlerBase {
public:
	virtual void operator()(ConnectionBase *conn_base, const PacketBasePtr &packet_base) const {
		TRACE_LOG("enter");
		const FileDataPacket *packet = dynamic_cast<const FileDataPacket *>(packet_base.get());
		assert(packet);
		ServerConnection *sConn = dynamic_cast<ServerConnection *>(conn_base);
		assert(sConn);
		//sConn->onFileData(packet);
		TRACE_LOG("exit");
	};
};

// Client
class FileInfoReplyPacketHandler : public ConnectionPacketHandlerBase {
public:
	virtual void operator()(ConnectionBase *conn_base, const PacketBasePtr &packet_base) const {
		TRACE_LOG("enter");
		const FileInfoReplyPacket *packet = dynamic_cast<const FileInfoReplyPacket *>(packet_base.get());
		assert(packet);
		ClientConnection *cConn = dynamic_cast<ClientConnection *>(conn_base);
		assert(cConn);
		//cConn->onFileInfoReply(packet);
		TRACE_LOG("exit");
	};
};

class TransferCompletePacketHandler : public ConnectionPacketHandlerBase {
public:
	virtual void operator()(ConnectionBase *conn_base, const PacketBasePtr &packet_base) const {
		TRACE_LOG("enter");
		const TransferCompletePacket *packet = dynamic_cast<const TransferCompletePacket *>(packet_base.get());
		assert(packet);
		ClientConnection *cConn = dynamic_cast<ClientConnection *>(conn_base);
		assert(cConn);
		//cConn->onFileTransferComplete(packet);
		TRACE_LOG("exit");
	};
};

// Close Procedure
class CloseConnectionPacketHandler : public ConnectionPacketHandlerBase {
public:
	virtual void operator()(ConnectionBase *conn_base, const PacketBasePtr &packet_base) const {
		INFO_LOG("reply to close connection request, remove connection: " << conn_base->getEndPoint().toString());
		PacketBasePtr packet(new CloseConnectionReplyPacket());
		conn_base->sendPacket(packet);
		conn_base->getUDPBase().scheduleCloseConnection(conn_base->getEndPoint());
	};
};

class CloseConnectionReplyPacketHandler : public ConnectionPacketHandlerBase {
public:
	virtual void operator()(ConnectionBase *conn_base, const PacketBasePtr &packet_base) const {
		INFO_LOG("got close connection reply, remove connection: " << conn_base->getEndPoint().toString());
		conn_base->getUDPBase().scheduleCloseConnection(conn_base->getEndPoint());
	};
};


}
}

#endif /* CONNECTIONHANDLER_H_ */
