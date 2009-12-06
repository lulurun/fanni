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
#include "fanni/LLUDP/UDPData.h"

namespace Fanni {

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

class ConnectionBase;
class AckManager {
private:
	typedef lockable< std::deque<uint32_t> > ACK_PACKET_QUEUE;
	ACK_PACKET_QUEUE ack_packet_queue;
	typedef lockable< std::map<uint32_t, ResendPacketPtr> > RESEND_PACKET_MAP;
	RESEND_PACKET_MAP resend_packet_map;

	Poco::Timer *check_ACK_timer;
	void onCheckACKTimer(Poco::Timer &timer);
	void checkACK();
	void checkRESEND();

	void removeResendPacket_unsafe(uint32_t seq);

	Poco::AtomicCounter sequence_counter;
	ConnectionBase &conn;

	ConnectionStatistics stat;

public:
	AckManager(ConnectionBase &conn);
	virtual ~AckManager();
	void processIncomingPacket(const PacketBasePtr &packet);
	void processOutgoingPacket(PacketBasePtr &packet);
};

}

#endif /* FANNI_LLUDPACKMANAGER_H_ */

