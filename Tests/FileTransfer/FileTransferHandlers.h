/*
 * QueuePacketTransferHandlers.h
 *
 *  Created on: Aug 9, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERS_H_
#define PACKETHANDLERS_H_

#include "fanni/UUID.h"
#include "fanni/Logger.h"
#include "FileTransferPackets/FileTransferPackets.h"
#include "FileTransferPackets/FileTransferPacketFactory.h"

#include "PacketTransfer/PacketHandlerFactory.h"
#include "FileTransferClientConnection.h"
#include "FileTransferNode.h"

namespace Fanni {
namespace Tests {

class FileInfoPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const FileInfoPacket *file_info_packet = dynamic_cast<const FileInfoPacket *> (packet);
		if (file_info_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint32_t file_size = file_info_packet->FileInfo.Size;
		string file_name = file_info_packet->FileInfo.Name.c_str();

		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		// TODO @@@ asset(connection); // !!
		connection->OnFileInfo(file_size, file_name, connection);
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
		UUID transfer_id = file_info_reply_packet->FileInfo.TransferID.val;
		string file_name = file_info_reply_packet->FileInfo.Name.c_str();

		FileTransferClientConnection *connection = dynamic_cast<FileTransferClientConnection *>(transfer_peer->getConnection(ep));
		// TODO @@@ asset(connection); // !!
		connection->OnFileInfoReply(transfer_id, file_name, connection);
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
		TRACE_LOG("exit");
	};
};

class UseCircuitCodePacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		const UseCircuitCodePacket *circuit_code_packet = dynamic_cast<const UseCircuitCodePacket *> (packet);
		if (circuit_code_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint32_t circuit_code = circuit_code_packet->CircuitCode.Code;
		transfer_peer->addConnection(circuit_code, ep);
	};
};

class CloseCircuitPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		const CloseCircuitPacket *close_circuit_packet = dynamic_cast<const CloseCircuitPacket *> (packet);
		if (close_circuit_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		transfer_peer->removeConnection(ep);
	};
};

}
}

#endif /* PACKETHANDLERS_H_ */
