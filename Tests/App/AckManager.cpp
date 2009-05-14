/*
 * AckManager.cpp
 *
 *  Created on: Apr 23, 2009
 *      Author: lulu
 */

#include "AckManager.h"
#include "fanni/Logger.h"

using namespace Fanni;

static AckManager::ACK_MAP_TYPE pending_ack_map;
static Mutex pending_ack_map_lock;

static AckManager::RELIABLE_MAP_TYPE reliable_out_packet_map;
static Mutex reliable_out_packet_map_lock;

void AckManager::checkInPacket(const PacketBase &packet) {
	TRACE_LOG("enter");
	if (packet.header.isReliable()) {
		S_MUTEX_LOCK l;
		l.lock(&pending_ack_map_lock);
		pending_ack_map[packet.header.getSequenceNumber()] = true;
	}
	if (packet.header.isAppendedAcks()) {
		S_MUTEX_LOCK l;
		l.lock(&reliable_out_packet_map_lock);
		for (PacketBase::ACK_LIST_TYPE::const_iterator it =
				packet.appended_acks.begin(); it != packet.appended_acks.end(); it++) {
			reliable_out_packet_map.erase(*it);
		}
	}
	TRACE_LOG("exit");
}

void AckManager::checkOutPacket(PacketBase &packet) {
	TRACE_LOG("enter");
	if (packet.header.isReliable()) {
		// remember this packet, waiting for ACK from client
		S_MUTEX_LOCK l;
		l.lock(&reliable_out_packet_map_lock);
		reliable_out_packet_map[packet.header.getSequenceNumber()] = &packet;
		// TODO @@@ make sure the packet wont be deleted
	}
	// send ACKed packets to client
	//if (this->pending_ack_map.count() > 0) {
	int append_count = 0;
	S_MUTEX_LOCK l;
	l.lock(&pending_ack_map_lock);
	for (ACK_MAP_TYPE::iterator it = pending_ack_map.begin(); it
			!= pending_ack_map.end(); it++) {
		packet.appendAck(it->first);
		if (append_count++ == 10)
			break;
		WARN_LOG("more acks are waiting to be sent");
	}
	//}
	TRACE_LOG("exit");
}

