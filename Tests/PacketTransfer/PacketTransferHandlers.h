/*
 * QueuePacketTransferHandlers.h
 *
 *  Created on: Aug 9, 2009
 *      Author: lulu
 */

#ifndef QUEUEPACKETTRANSFERHANDLERS_H_
#define QUEUEPACKETTRANSFERHANDLERS_H_

namespace Fanni {
namespace Tests {

// =======
// server side handlers
class StartPingCheckPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferManager *packet_transfer_manager = NULL) const {
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
		if (packet_transfer_manager != NULL) {
			DEBUG_LOG("answering start_ping: " << ping_id);
			TransferDataPacket *resp_data = new TransferDataPacket(complete_ping_packet, ep);
			packet_transfer_manager->deliverTask(resp_data);
		}
	};
};

// =======
// client side handlers
class CompletePingCheckPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferManager *packet_transfer_manager = NULL) const {
		const CompletePingCheckPacket *complete_ping_packet = dynamic_cast<const CompletePingCheckPacket *> (packet);
		if (complete_ping_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint8_t ping_id = complete_ping_packet->PingID.PingID;
		 DEBUG_LOG("got complete ping id: " << ping_id);
	};
};

}
}

#endif /* QUEUEPACKETTRANSFERHANDLERS_H_ */
