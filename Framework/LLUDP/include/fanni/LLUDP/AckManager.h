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

public:
	AckManager(ConnectionBase &conn);
	virtual ~AckManager();
	void processIncomingPacket(const PacketBasePtr &packet);
	void processOutgoingPacket(PacketBasePtr &packet);
};

}

#endif /* FANNI_LLUDPACKMANAGER_H_ */

