/*
 * ClientConnectionBase.cpp
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#include "ClientConnectionBase.h"
#include "PacketTransferBase.h"
#include "FileTransferPackets/FileTransferPackets.h"
#include "FileTransferPackets/FileTransferPacketFactory.h"

using namespace std;
using namespace Fanni;

static const int MAX_ACK_NUMBER = 0xff;

ClientConnectionBase::ClientConnectionBase() {
	this->circuit_code = 0;
	this->transfer_peer = NULL;
	this->updateLastReceived();
}

ClientConnectionBase::ClientConnectionBase(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_peer) :
	circuit_code(circuit_code), ep(ep), transfer_peer(transfer_peer) {
	this->updateLastReceived();
}

ClientConnectionBase::~ClientConnectionBase() {
	for(RESEND_PACKET_MAP_TYPE::iterator it=this->resend_packet_map.begin(); it!=this->resend_packet_map.end(); it++) {
		delete it->second;
	}
}

void ClientConnectionBase::updateLastReceived() {
	this->last_packet_received = time(NULL);
}

void ClientConnectionBase::checkACK() {
    if (this->ack_packet_queue.empty()) return;
    S_MUTEX_LOCK l;
    l.lock(&this->ack_lock);
    int total_count = 0;
    while (!this->ack_packet_queue.empty()) {
	int count = 0;
	PacketAckPacket *packet = new PacketAckPacket();
	while (!this->ack_packet_queue.empty()) {
	    PacketAckPacket::PacketsBlock packets_block;
	    packets_block.ID = this->ack_packet_queue.front();
	    // TODO @@@ memory reallocate/copy inside "push" + coping packets_block
	    packet->Packets.push(packets_block);
	    this->ack_packet_queue.pop();
	    if (++count == MAX_ACK_NUMBER) break;
	}
	this->sendPacket(packet);
	total_count += count;
    }
    DEBUG_LOG("ACKed " << total_count << " packets");
}

void ClientConnectionBase::checkRESEND() {
	if (this->resend_packet_map.empty()) return;
	S_MUTEX_LOCK l;
	l.lock(&this->resend_lock);
	DEBUG_LOG("number of resend packets: " << this->resend_packet_map.size());
	list<uint32_t> delete_list;
	int resend_count = 0;
	for(RESEND_PACKET_MAP_TYPE::iterator it=this->resend_packet_map.begin(); it!=this->resend_packet_map.end(); it++) {
		// MEMO @@@ need copy this packet, because the packet will be deleted after sending
		if ( it->second->shouldResend() ) {
			PacketBase *packet = it->second->get();
			packet->setFlag(PacketHeader::FLAG_RESENT);
			packet->setFlag(PacketHeader::FLAG_RELIABLE);
			this->sendPacket(packet);
			resend_count++;
		} else if (it->second->shouldGiveup() ) {
			WARN_LOG("give up resending packet: " << it->second->get()->header.getPacketID());
			delete_list.push_back(it->first);
		}
	}
	for(list<uint32_t>::const_iterator it=delete_list.begin(); it!=delete_list.end(); it++ ) {
		this->remove_resend_packet_nolock(*it);
	}
	DEBUG_LOG("resending " << resend_count << " packets");
}

bool ClientConnectionBase::checkAlive() {
	time_t now = time(NULL);
	if ((now - this->last_packet_received) > CONNECTION_TIMEOUT) {
		return true;
	}
	return false;
}

void ClientConnectionBase::processIncomingPacket(const PacketBase *packet) {
	TRACE_LOG("enter");
	this->updateLastReceived();
	if (packet->header.isReliable()) {
		S_MUTEX_LOCK l;
		l.lock(&this->ack_lock);
		this->ack_packet_queue.push(packet->header.getSequenceNumber());
	}
	// process resend
	S_MUTEX_LOCK l;
	l.lock(&this->resend_lock);
	if (packet->header.isAppendedAcks()) {
		PacketBase::ACK_LIST_TYPE::const_iterator it = packet->appended_acks.begin();
		for (; it != packet->appended_acks.end(); it++) {
			this->remove_resend_packet_nolock(*it);
		}
	}
	if (packet->header.getPacketID() == PacketAck_ID) {
		const PacketAckPacket *ack_packet = dynamic_cast<const PacketAckPacket *>(packet);
		assert(ack_packet);
		int debug_count = 0;
		for(vector<PacketAckPacket::PacketsBlock>::const_iterator it = ack_packet->Packets.val.begin(); it!=ack_packet->Packets.val.end(); it++) {
			this->remove_resend_packet_nolock(it->ID);
			debug_count++;
		}
	}
	TRACE_LOG("exit");
}

void ClientConnectionBase::processOutgoingPacket(const PacketBase *packet) {
	if (packet->header.isReliable() && !packet->header.isResent()) {
		S_MUTEX_LOCK l;
		l.lock(&this->resend_lock);
		this->add_resend_packet_nolock(packet);
	}
}

void ClientConnectionBase::remove_resend_packet_nolock(uint32_t seq) {
	RESEND_PACKET_MAP_TYPE::const_iterator it = this->resend_packet_map.find(seq);
	if (it != this->resend_packet_map.end()) {
		if (it->second != NULL) delete it->second;
		this->resend_packet_map.erase(seq);
		//this->resend_status_map.erase(seq); // TODO @@@ !!!
	}
}

void ClientConnectionBase::add_resend_packet_nolock(const PacketBase* packet) {
	this->resend_packet_map[packet->header.sequence] = new ResendPacket(packet);
}

void ClientConnectionBase::sendPacket(PacketBase *packet) {
	this->transfer_peer->sendPacket(packet, &this->ep);
}

