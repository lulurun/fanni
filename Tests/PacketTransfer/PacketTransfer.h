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
#include "fanni/Timer.h"

#include "Threads/Mutex.h"
#include "Threads/ThreadManager.h"
#include "Packets/PacketBase.h"
#include "Packets/PacketSerializer.h"
#include "LLPackets/LLPackets.h"
#include "LLPackets/LLPacketFactory.h"

#include "TransferData.h"

namespace Fanni {
namespace Tests {

class PacketSender: public ThreadWorker {
private:
	int server_socket;
	PacketSerializer *packet_serializer;

public:
	PacketSender(int server_socket) : server_socket(server_socket) {
		this->packet_serializer = CreateLLPacketSerializer();
		}
	~PacketSender() {
		delete this->packet_serializer;
	}
	virtual void loop();
	virtual void stop() { ; }
};

typedef std::tr1::unordered_map<uint32_t, const TransferDataPacket*> RESEND_PACKET_LIST_TYPE;
static RESEND_PACKET_LIST_TYPE ResendPacketList;
static Mutex ResendPacketList_lock;

typedef std::tr1::unordered_map<uint32_t, const EndPoint*> ACK_PACKET_LIST_TYPE;
static ACK_PACKET_LIST_TYPE AckPacketList;
static Mutex AckPacketList_lock;

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
			AckPacketList[packet->header.getSequenceNumber()] = new EndPoint(*ep);
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
			PacketAckPacket *packet_ack = dynamic_cast<PacketAckPacket *>(packet);
			for(size_t i=0; i<packet_ack->Packets.size(); i++) {
				ResendPacketList.erase(packet_ack->Packets[i].ID);
			}
		}
	}

	virtual void processOutgoingPacket(PacketBase *packet, const EndPoint *ep) {
		if (packet->header.isReliable()) {
			S_MUTEX_LOCK l;
			l.lock(&ResendPacketList_lock);
			TransferDataPacket *transfer_data = new TransferDataPacket(
					LLPacketFactorySingleton::get().createPacketCopy(packet->header.getPacketID(), packet),
					new EndPoint(*ep));
			ResendPacketList[packet->header.getSequenceNumber()] = transfer_data;
		}
	}
};

static const int MAX_ACK_NUMBER = 100;
class OnTimerElapsedHandler_CheckACK : public OnTimerElapsedHandler {
private:
	PacketTransferManager *packet_transfer_manager;
public:
	OnTimerElapsedHandler_CheckACK(PacketTransferManager *packet_transfer_manager) :
		packet_transfer_manager(packet_transfer_manager) { }

	virtual void operator()() const {
		S_MUTEX_LOCK l;
		l.lock(&AckPacketList_lock);
		if (AckPacketList.size() == 0) return;
		int count = 0;
		PacketAckPacket *packet = new PacketAckPacket();
		for(ACK_PACKET_LIST_TYPE::iterator it=AckPacketList.begin(); it!=AckPacketList.end(); it++) {
			PacketAckPacket::PacketsBlock packets_block;
			packets_block.ID = it->first;
			packet->Packets.push(packets_block); // TODO @@@ avoid memory reallocate insize "push"
			if (++count == MAX_ACK_NUMBER) break;
		}
		// send
		/*
		TransferDataPacket *transfer_data = new TransferDataPacket(packet, );
		this->packet_transfer_manager->deliverTask()

		for(int i=0; i<count; count++) {
			AckPacketList.erase(packet.Packets[i].ID);
		}
		*/
	}
};

}
}

#endif /* PACKETTRANSFER_H_ */
