/*
 * SystemPacketHandlers.h
 *
 *  Created on: Sep 19, 2009
 *      Author: lulu
 */

#ifndef SYSTEMPACKETHANDLERS_H_
#define SYSTEMPACKETHANDLERS_H_

#include "LLPackets/LLPackets.h"
#include "LLPackets/LLPacketFactory.h"

namespace Fanni {

class UseCirciutCodePacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		const UseCircuitCodePacket *packet = dynamic_cast<const UseCircuitCodePacket *> (packet_base);
		assert(packet);
		ClientConnection *connection = dynamic_cast<ClientConnection *>(transfer_peer->addConnection(packet->CircuitCode.Code, ep));
		assert(connection);
		// ACK to this packet
		connection->processIncomingPacket(packet_base);
		{
			// send region hand shake
			RegionHandshakePacket *packet = LLPacketFactorySingleton::get().createPacket(RegionHandshake_ID);
			//packet->RegionInfo.
		}
	};
};

class StartPingCheckPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet_base, const EndPoint *ep, PacketTransferBase *transfer_peer) const {
		const StartPingCheckPacket *req_packet = dynamic_cast<const StartPingCheckPacket*> (packet_base);
		assert(req_packet);
		ClientConnectionBase *connection = transfer_peer->getConnection(ep);
		if (!connection) {
			ERROR_LOG("unknown connection from: " << ep->getAddrStr() << ":" << ep->getPort());
			return;
		}
		CompletePingCheckPacket *res_packet = dynamic_cast<CompletePingCheckPacket *>(LLPacketFactorySingleton::get().createPacket(CompletePingCheck_ID));
		assert(res_packet);
		res_packet->PingID.PingID = req_packet->PingID.PingID;
		connection->sendPacket(res_packet);
	};
};

}


#endif /* SYSTEMPACKETHANDLERS_H_ */
