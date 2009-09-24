
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
#include "Threads/DataControl.h"
#include "Packets/PacketBase.h"

namespace Fanni {

static const int CONNECTION_TIMEOUT = 100; // 100 sec
static const int RESEND_TIMEOUT = 4; // 4 sec
static const int MAX_RESENDING_TRIES = 0xffff; // will give up transferring after trying to resend 4 times

// MEMO @@@ supposed to be write from only one thread
class ResendPacket {
private:
	const PacketBase *packet;
	std::time_t last_sent;
	int resend_count;

public:
	ResendPacket(const PacketBase *packet) :
		packet(packet->clone()), last_sent(::time(NULL)), resend_count(0){
	}

	~ResendPacket() {
		delete this->packet;
	}

	bool shouldResend() {
		return (::time(NULL) - this->last_sent ) > RESEND_TIMEOUT;
	}

	bool shouldGiveup() {
		return this->resend_count >= MAX_RESENDING_TRIES;
	}

	PacketBase *get() {
		this->last_sent = ::time(NULL);
		this->resend_count++;
		return this->packet->clone();
	}

};

typedef std::queue<uint32_t> ACK_PACKET_QUEUE_TYPE;
typedef std::tr1::unordered_map<uint32_t, ResendPacket *> RESEND_PACKET_MAP_TYPE;

class PacketTransferBase;
class ClientConnectionBase {
protected:
    uint32_t circuit_code;
	PacketTransferBase *transfer_peer;
	time_t last_packet_received;
	const EndPoint ep;

public:
	ClientConnectionBase();
	ClientConnectionBase(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_base);
	virtual ~ClientConnectionBase();

	uint32_t getCircuitCode() const { return this->circuit_code; }
	const EndPoint &getEndPoint() const { return this->ep; }
	void sendPacket(PacketBase *packet);

	void updateLastReceived();

	virtual void checkACK();
	virtual void checkRESEND();
	virtual bool checkALIVE();

	virtual void processIncomingPacket(const PacketBase *packet);
	virtual void processOutgoingPacket(const PacketBase *packet);

private:
	// ACK, RESEND management
	DataControl ack_lock;
	ACK_PACKET_QUEUE_TYPE ack_packet_queue;
	DataControl resend_lock;
	RESEND_PACKET_MAP_TYPE resend_packet_map;

private:
	// MEMO @@@ these methods are not thread safe
	void remove_resend_packet_nolock(uint32_t seq);
	void add_resend_packet_nolock(const PacketBase* packet);
};

}

#endif /* CLIENTCONNECTIONBASE_H_ */
