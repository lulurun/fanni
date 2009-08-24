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

#include "PacketServer.h"
#include "PacketHandlerFactory.h"

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
		UUID transfer_id = file_info_packet->FileInfo.TransferID.val;
		int file_size = file_info_packet->FileInfo.Size;
		string file_name = *file_info_packet->FileInfo.Name;

		DEBUG_LOG("transfer_id: " << transfer_id.toString());
		DEBUG_LOG("size: " << file_size);
		DEBUG_LOG("name: " << file_name);

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
