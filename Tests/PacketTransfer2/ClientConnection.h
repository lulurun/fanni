/*
 * ClientConnection.h
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#ifndef CLIENTCONNECTION_H_
#define CLIENTCONNECTION_H_

#include <ctime>
#include <queue>
#include <tr1/unordered_map>

#include "fanni/EndPoint.h"
#include "Threads/Mutex.h"
#include "Packets/PacketBase.h"

namespace Fanni {
namespace Tests {

typedef std::queue<uint32_t> ACK_PACKET_QUEUE_TYPE;
typedef std::tr1::unordered_map<uint32_t, const PacketBase *> RESEND_PACKET_MAP_TYPE;
typedef std::tr1::unordered_map<uint32_t, std::time_t> RESEND_STATUS_MAP_TYPE;

class PacketTransferBase;
class ClientConnection {
private:
    uint32_t circuit_code;
	const EndPoint ep;
	PacketTransferBase *transfer_peer;

	// ACK, RESEND management
	Mutex resend_lock;
	Mutex ack_lock;
	ACK_PACKET_QUEUE_TYPE ack_packet_queue;
	RESEND_PACKET_MAP_TYPE resend_packet_map;
	RESEND_STATUS_MAP_TYPE resend_status_map;

public:
	ClientConnection();
	ClientConnection(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_base);
	virtual ~ClientConnection();

	uint32_t getCircuitCode() const { return this->circuit_code; }
	const EndPoint &getEndPoint() const { return this->ep; }

	void checkACK();
	void checkRESEND();

	void processIncomingPacket(const PacketBase *packet);
	void processOutgoingPacket(const PacketBase *packet);

private:
	// MEMO @@@ these methods are not thread safe
	// locked by caller from "this"
	void remove_resend_packet(uint32_t seq);
	void add_resend_packet(const PacketBase* packet);
};

}
}

#endif /* CLIENTCONNECTION_H_ */
