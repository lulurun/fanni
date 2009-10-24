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
#include "rUDP/TransferNode.h"

namespace Fanni {

class PacketServer : public TransferNode {
private:
	static const PacketHeader::PACKET_ID_TYPE OPEN_CONNECTION_PACKET = UseCircuitCode_ID;
	static const PacketHeader::PACKET_ID_TYPE CLOSE_CONNECTION_PACKET = CloseCircuit_ID;

public:
	PacketServer(const std::string &addr, uint16_t port, int thread_number);
	virtual ~PacketServer();
	virtual void init();

	virtual ConnectionBase *createConnection(uint32_t circuit_code, const Poco::Net::SocketAddress *addr);
	virtual bool skipProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id);
	virtual bool skipHandlePacket(PacketHeader::PACKET_ID_TYPE packet_id);

};

}

#endif /* PACKETSERVER_H_ */
