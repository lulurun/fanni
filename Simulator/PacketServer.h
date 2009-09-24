/*
 * PacketServer.h
 *
 *  Created on: Sep 19, 2009
 *      Author: lulu
 */

#ifndef PACKETSERVER_H_
#define PACKETSERVER_H_

#include "LLPackets/LLPacketsID.h"
#include "LLPackets/LLPacketFactory.h"
#include "PacketTransfer/PacketTransferBase.h"

namespace Fanni {

class PacketServer : public PacketTransferBase {
private:
	static const PacketHeader::PACKET_ID_TYPE OPEN_CONNECTION_PACKET = UseCircuitCode_ID;
	static const PacketHeader::PACKET_ID_TYPE CLOSE_CONNECTION_PACKET = CloseCircuit_ID;

	const LLPacketFactory &packet_factory;
	PacketHandlerFactory packet_handler_factory;

public:
	PacketServer(const std::string &addr, int port, int thread_number);
	virtual ~PacketServer();
	virtual void init();

	virtual ClientConnectionBase *createClientConnection(uint32_t circuit_code, const EndPoint *ep);
	virtual bool skipProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id);
	virtual bool skipHandlePacket(PacketHeader::PACKET_ID_TYPE packet_id);

};

}

#endif /* PACKETSERVER_H_ */
