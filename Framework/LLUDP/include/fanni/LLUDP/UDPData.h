/*
 * UDPPacketData.h
 *
 *  Created on: Oct 18, 2009
 *      Author: lulu
 */

#ifndef _FANNI_UDPPACKET_DATA_H_
#define _FANNI_UDPPACKET_DATA_H_

#include "Fanni/TaskQueue.h"
#include "fanni/EndPoint.h"
#include "fanni/PacketBuffer.h"
#include "fanni/Packets/PacketBase.h"

namespace Fanni {

class IncomingData : public TaskBase {
public:
	PacketBuffer data;
	EndPoint ep;

	IncomingData(PacketBuffer &data, const EndPoint &ep) : data(data), ep(ep) {}
	~IncomingData() {}
};

class CloseConnectionTask : public TaskBase {
public:
	EndPoint ep;
	CloseConnectionTask(const EndPoint &ep): ep(ep) {}
	~CloseConnectionTask() {}
};

// TODO @@@ read from config file
static const int CONNECTION_TIMEOUT = 100; // 100 sec
static const int RESEND_TIMEOUT = 4; // 4 sec
static const int MAX_RESENDING_TRIES = 0xffff; // will give up transferring after trying to resend 4 times

// MEMO @@@ supposed to be used from only one thread
class ResendPacket {
private:
	PacketBasePtr packet;
	std::time_t last_sent;
	int resend_count;

public:
	ResendPacket(const PacketBasePtr &packet) :
		packet(packet->clone()), last_sent(::time(NULL)), resend_count(0){}
	ResendPacket(const ResendPacket &resend_packet) :
		packet(resend_packet.packet), last_sent(::time(NULL)), resend_count(0){
		// TODO @@@ should forbid calling this	
	}
	~ResendPacket() {}

	bool shouldResend() { return (::time(NULL) - this->last_sent ) > RESEND_TIMEOUT; }
	bool shouldGiveup() { return this->resend_count >= MAX_RESENDING_TRIES; }

	// MEMO @@@ only Call this before send packet
	PacketBasePtr &get(){
		this->last_sent = ::time(NULL);
		this->resend_count++;
		return this->packet;
	}
};

typedef Poco::SharedPtr<ResendPacket> ResendPacketPtr;

};

#endif // _FANNI_UDPPACKET_DATA_H_
