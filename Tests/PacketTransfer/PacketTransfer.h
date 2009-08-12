/*
 * PacketTransfer.h
 *
 *  Created on: Aug 8, 2009
 *      Author: lulu
 */

#ifndef PACKETTRANSFER_H_
#define PACKETTRANSFER_H_

#include <tr1/unordered_map>

#include "fanni/Logger.h"

#include "Threads/Mutex.h"
#include "Threads/ThreadManager.h"
#include "Packets/PacketBase.h"
#include "Packets/Packets.h"
#include "Packets/PacketSerializer.h"

namespace Fanni {
namespace Tests {

class PacketSender: public ThreadWorker {
private:
	int server_socket;
	PacketSerializer packet_serializer;

public:
	PacketSender(int server_socket) : server_socket(server_socket) {}
	virtual void loop();
	virtual void stop() { ; }
};

typedef std::tr1::unordered_map<uint32_t, const PacketBase*> RESEND_PACKET_LIST_TYPE;
static RESEND_PACKET_LIST_TYPE ResendPacketList;
static Mutex ResendPacketList_lock;

typedef std::tr1::unordered_map<uint32_t, bool> ACK_PACKET_LIST_TYPE;
static ACK_PACKET_LIST_TYPE AckPacketList;
static Mutex AckPacketList_lock;

// TODO @@@ add timer to resend packets and answer acks
class PacketTransferManager: public ThreadManager {
private:
	int thread_number;
	int server_socket;

public:
	PacketTransferManager(int thread_number, int server_socket) :
		thread_number(thread_number), server_socket(server_socket) {}

	virtual void init();
	virtual void processIncomingPacket(PacketBase *packet, const EndPoint *ep) {
		if (packet->header.isReliable()) {
			S_MUTEX_LOCK l;
			l.lock(&AckPacketList_lock);
			AckPacketList[packet->header.getSequenceNumber()] = true;
		}
		if (packet->header.isAppendedAcks()) {
			S_MUTEX_LOCK l;
			l.lock(&ResendPacketList_lock);
			PacketBase::ACK_LIST_TYPE::const_iterator it = packet->appended_acks.begin();
			for (; it != packet->appended_acks.end(); it++) {
				ResendPacketList.erase(*it);
			}
		}
		if (packet->header.getPacketID() == PacketAck_ID) {
			; // TODO @@@ get sequence numbers from packet
		}
	}

	virtual void processOutgoingPacket(PacketBase *packet, const EndPoint *ep) {
		if (packet->header.isReliable()) {
			S_MUTEX_LOCK l;
			l.lock(&ResendPacketList_lock);
			ResendPacketList[packet->header.getSequenceNumber()] =
				PacketFactory::GetInstance()->createPacketCopy(packet->header.getPacketID(), packet);
		}
	}
};

}
}

#endif /* PACKETTRANSFER_H_ */
