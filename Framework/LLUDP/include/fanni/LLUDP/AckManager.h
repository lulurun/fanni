/*
 * AckManager.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_LLUDPACKMANAGER_H_
#define FANNI_LLUDPACKMANAGER_H_

#include <deque>
#include <map>
#include "Poco/Timer.h"
#include "Poco/AtomicCounter.h"
#include "fanni/LockableTemplate.h"
#include "fanni/Packets/PacketBase.h"

namespace Fanni {

// TODO @@@ karn's algo
static const int CONNECTION_TIMEOUT = 15 * 1000000; // 15 sec
static const int RESEND_TIMEOUT = 750 * 1000; // 0.75 sec
static const int MAX_RESENDING_TRIES = 0xffff; // will give up transferring after trying to resend n times

// TODO @@@ not thread safe
// ResendPacket is managed by each connection(thread)
class ResendPacket {
private:
	PacketBasePtr packet;
	Poco::Timestamp last_sent;
	int resend_count;

	ResendPacket(ResendPacket &resend_packet);
	ResendPacket &operator=(ResendPacket &resend_packet);

public:
	ResendPacket(const PacketBasePtr &packet) :
		packet(packet->clone()), last_sent(), resend_count(0){}
	~ResendPacket() {}

	bool shouldResend() {
		return this->last_sent.isElapsed(RESEND_TIMEOUT);
	}
	bool shouldGiveup() { return this->resend_count >= MAX_RESENDING_TRIES; }

	// MEMO @@@ only Call this before send packet
	PacketBasePtr &get(){
		this->last_sent.update();
		this->resend_count++;
		return this->packet;
	}
};

typedef Poco::SharedPtr<ResendPacket> ResendPacketPtr;

// TODO @@@ not thread safe
class ConnectionStatistics {
public:
	/* TODO @@@ should not be here ??
	Poco::Timestamp created;
	Poco::Timestamp destroyed;
	*/
	int send_packets;
	int received_packets;
	int acked_packets;
	int resend_packets;
	int giveup_packets;

	ConnectionStatistics() : send_packets(0), received_packets(0),
		acked_packets(0), resend_packets(0), giveup_packets(0) {}
	~ConnectionStatistics() {};
	const std::string toString() const {
		char buffer[256];
		std::sprintf(buffer,
			"send packets    %d\n"
			"receive packets %d\n"
			"acked packets   %d\n"
			"resend packets  %d\n"
			"giveup packets  %d\n",
			this->send_packets, this->received_packets,
			this->acked_packets, this->resend_packets, this->giveup_packets);
		std::string result(buffer);
		return result;
	}
};

template<class T>
class ReceivedPacketList {
private:
	std::map<T, bool> _map;
	T *_list;
	size_t _size;
	size_t _pos;
	Poco::FastMutex _mutex;

public:
	ReceivedPacketList(size_t size) : _size(size), _pos(0) {
		this->_list = new T[size];
	}

	~ReceivedPacketList() {
		delete [] _list;
	}

	void enqueue(const T &val) {
		Poco::FastMutex::ScopedLock l(this->_mutex);
		this->_pos++;
		if (this->_pos == this->_size) this->_pos = 0;
		this->_map.erase(this->_list[this->_pos]);
		this->_list[this->_pos] = val;
		this->_map.insert(val, true);
	}

	bool hasValue(const T &val) {
		Poco::FastMutex::ScopedLock l(this->_mutex);
		std::map<T, bool>::iterator it = this->_map.find(val);
		return it != this->_map.end();
	}

	bool checkReceived(const T &val) {
		Poco::FastMutex::ScopedLock l(this->_mutex);
		std::map<T, bool>::iterator it = this->_map.find(val);
		if (it != this->_map.end()) {
			// has value
			return true; // already received, need not to dispatch
		} else {
			this->_pos++;
			if (this->_pos == this->_size) this->_pos = 0;
			this->_map.erase(this->_list[this->_pos]);
			this->_list[this->_pos] = val;
			this->_map[val] = true;
			// value added
			return false; // continue to dispatch
		}
	}
};

class ConnectionBase;
class AckManager {
private:
	ConnectionBase &conn;

	typedef lockable< std::deque<uint32_t> > ACK_PACKET_QUEUE;
	ACK_PACKET_QUEUE ack_packet_queue;
	typedef lockable< std::map<uint32_t, ResendPacketPtr> > RESEND_PACKET_MAP;
	RESEND_PACKET_MAP resend_packet_map;
	typedef ReceivedPacketList<uint32_t> RECEIVED_PACKET_LIST; // TODO @@@ xxxtree?
	RECEIVED_PACKET_LIST received_packet_list;

	Poco::AtomicCounter sequence_counter;
	ConnectionStatistics stat;

	Poco::Timer *check_ACK_timer;
	void onCheckACKTimer(Poco::Timer &timer);
	void checkACK();
	void checkRESEND();

	void removeResendPacket_unsafe(uint32_t seq);

public:
	AckManager(ConnectionBase &pConn);
	virtual ~AckManager();
	bool processIncomingPacket(const PacketBasePtr &pPacket);
	void processOutgoingPacket(PacketBasePtr &pPacket);
};

}

#endif /* FANNI_LLUDPACKMANAGER_H_ */

