/*
 * PacketServer.h
 *
 *  Created on: Aug 15, 2009
 *      Author: lulu
 */

#ifndef PACKETSERVER_H_
#define PACKETSERVER_H_

#include <string>
#include <tr1/unordered_map>

#include "fanni/EndPoint.h"
#include "Packets/PacketBase.h"
#include "LLPackets/LLPacketsID.h"

#include "PacketTransferBase.h"

namespace Fanni {
namespace Tests {

class PacketServer : public PacketTransferBase {
private:
	typedef std::tr1::unordered_map<EndPoint::IPV4_HASH_KEY_TYPE, ClientConnection *> CLIENT_CONNECTION_MAP_TYPE;
	CLIENT_CONNECTION_MAP_TYPE client_connection_map;
	Mutex client_connection_map_lock;
	static const PacketHeader::PACKET_ID_TYPE OPEN_CONNECTION_PACKET = UseCircuitCode_ID;

public:
	PacketServer(const std::string &addr, int port, int thread_number);
	virtual ~PacketServer();
	virtual void init();

	// Client Connection management
	virtual void addConnection(uint32_t circuit_code, const EndPoint *ep);
	virtual void removeConnection(const EndPoint *ep);
	ClientConnection *getConnection(const EndPoint *ep);

	// Reliable Packet Transfer
	virtual void processIncomingPacket(const PacketBase *packet, const EndPoint *ep);
	virtual void processOutgoingPacket(const PacketBase *packet, const EndPoint *ep);

	virtual void checkACK();
	virtual void checkRESEND();
};

}
}

#endif /* PACKETSERVER_H_ */
