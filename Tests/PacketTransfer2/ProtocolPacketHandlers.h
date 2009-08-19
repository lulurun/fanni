/*
 * QueuePacketTransferHandlers.h
 *
 *  Created on: Aug 9, 2009
 *      Author: lulu
 */

#ifndef QUEUEPACKETTRANSFERHANDLERS_H_
#define QUEUEPACKETTRANSFERHANDLERS_H_

#include "Packets/Packets.h"

#include "PacketServer.h"
#include "PacketHandlerFactory.h"

namespace Fanni {
namespace Tests {

// =======
// server side handlers
class StartPingCheckPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		TRACE_LOG("enter");
		const StartPingCheckPacket *start_ping_packet = dynamic_cast<const StartPingCheckPacket *> (packet);
		if (start_ping_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint8_t ping_id = start_ping_packet->PingID.PingID;
		// create response packet
		PacketBase *packet_base = PacketFactory::GetInstance()->createPacket(CompletePingCheck_ID);
		CompletePingCheckPacket *complete_ping_packet = dynamic_cast<CompletePingCheckPacket *> (packet_base);
		if (complete_ping_packet == NULL) {
			FATAL_LOG("should never reach here");
			return;
		}
		complete_ping_packet->PingID.PingID = ping_id;

		DEBUG_LOG("answering start_ping: " << ping_id);
		transfer_peer->sendPacket(complete_ping_packet, ep);
		TRACE_LOG("exit");
	};
};

// =======
// client side handlers
class CompletePingCheckPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		const CompletePingCheckPacket *complete_ping_packet = dynamic_cast<const CompletePingCheckPacket *> (packet);
		if (complete_ping_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint8_t ping_id = complete_ping_packet->PingID.PingID;
		 DEBUG_LOG("got complete ping id: " << ping_id);
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

}
}

#endif /* QUEUEPACKETTRANSFERHANDLERS_H_ */
