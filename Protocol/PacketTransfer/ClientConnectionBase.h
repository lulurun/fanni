/*
 * ClientConnectionBase.h
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#ifndef CLIENTCONNECTIONBASE_H_
#define CLIENTCONNECTIONBASE_H_

#include <ctime>
#include <queue>
#include <tr1/unordered_map>

#include "fanni/EndPoint.h"
#include "Threads/Mutex.h"
#include "Packets/PacketBase.h"

namespace Fanni {

typedef std::queue<uint32_t> ACK_PACKET_QUEUE_TYPE;
typedef std::tr1::unordered_map<uint32_t, const PacketBase *> RESEND_PACKET_MAP_TYPE;
typedef std::tr1::unordered_map<uint32_t, std::time_t> RESEND_STATUS_MAP_TYPE;

class PacketTransferBase;
class ClientConnectionBase {
protected:
    uint32_t circuit_code;
	const EndPoint ep;
	PacketTransferBase *transfer_peer;
	time_t last_packet_received;

public:
	static const int CONNECTION_TIMEOUT = 100; // 100 seconds

	ClientConnectionBase();
	ClientConnectionBase(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_base);
	virtual ~ClientConnectionBase();

	uint32_t getCircuitCode() const { return this->circuit_code; }
	const EndPoint &getEndPoint() const { return this->ep; }
	void sendPacket(PacketBase *packet);

	void updateLastReceived();

	virtual void checkACK();
	virtual void checkRESEND();
	virtual bool checkAlive();

	virtual void processIncomingPacket(const PacketBase *packet);
	virtual void processOutgoingPacket(const PacketBase *packet);

private:
	// ACK, RESEND management
	Mutex resend_lock;
	Mutex ack_lock;
	ACK_PACKET_QUEUE_TYPE ack_packet_queue;
	RESEND_PACKET_MAP_TYPE resend_packet_map;
	RESEND_STATUS_MAP_TYPE resend_status_map;

	// MEMO @@@ these methods are not thread safe
	// locked by caller from "this"
	void remove_resend_packet(uint32_t seq);
	void add_resend_packet(const PacketBase* packet);
};

}

#endif /* CLIENTCONNECTIONBASE_H_ */
