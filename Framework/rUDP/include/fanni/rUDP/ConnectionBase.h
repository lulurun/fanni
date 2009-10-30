
/*
 * ConnectionBase.h
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#ifndef CONNECTIONBASE_H_
#define CONNECTIONBASE_H_

#include <ctime>
#include <queue>
#include "Poco/HashMap.h"
#include "Poco/Mutex.h"
#include "fanni/EndPoint.h"
#include "fanni/LockableTemplate.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/rUDP/rUDP_def.h"
#include "fanni/rUDP/PacketHandlerFactory.h"

namespace Fanni {

// TODO @@@ read from config file
static const int CONNECTION_TIMEOUT = 100; // 100 sec
static const int RESEND_TIMEOUT = 4; // 4 sec
static const int MAX_RESENDING_TRIES = 0xffff; // will give up transferring after trying to resend 4 times

// MEMO @@@ supposed to be used from only one thread
class ResendPacket {
private:
	const PacketBase *packet;
	std::time_t last_sent;
	int resend_count;

public:
	ResendPacket(const PacketBase *packet) :
		packet(packet->clone()), last_sent(::time(NULL)), resend_count(0){
	}
	~ResendPacket() { delete this->packet; }

	bool shouldResend() { return (::time(NULL) - this->last_sent ) > RESEND_TIMEOUT; }
	bool shouldGiveup() { return this->resend_count >= MAX_RESENDING_TRIES; }

	PacketBase *get() {
		this->last_sent = ::time(NULL);
		this->resend_count++;
		return this->packet->clone();
	}
};

class TransferNode;
class Fanni_RUDP_API ConnectionBase {
protected:
	TransferNode &node;
	const PacketHandlerFactory &packet_handler_factory;

	const EndPoint ep;
    uint32_t circuit_code; // connection id
	time_t last_packet_received;

public:
	ConnectionBase(uint32_t circuit_code, const EndPoint &ep, TransferNode &node);
	virtual ~ConnectionBase();

	const uint32_t getCircuitCode() const { return this->circuit_code; }
	const EndPoint &getEndPoint() const { return this->ep; }
	TransferNode &getTransferNode() const { return this->node; }
	void sendPacket(PacketBase *packet);

	void updateLastReceived();

	virtual void processIncomingPacket(const PacketBase *packet);
	virtual void processOutgoingPacket(const PacketBase *packet);

	// Reliable UDP
private:
	typedef std::queue<uint32_t> __ACK_PACKET_QUEUE;
	typedef Poco::HashMap<uint32_t, ResendPacket *> __RESEND_PACKET_MAP;
public:
	typedef lockable<__ACK_PACKET_QUEUE> ACK_PACKET_QUEUE;
	typedef lockable<__RESEND_PACKET_MAP> RESEND_PACKET_MAP;

	virtual void checkACK();
	virtual void checkRESEND();
	virtual bool checkALIVE();

private:
	ACK_PACKET_QUEUE ack_packet_queue;
	RESEND_PACKET_MAP resend_packet_map;

	// MEMO @@@ these methods are not thread safe
	void remove_resend_packet_nolock(uint32_t seq);
	void add_resend_packet_nolock(const PacketBase *packet);
};

}

#endif /* CONNECTIONBASE_H_ */
