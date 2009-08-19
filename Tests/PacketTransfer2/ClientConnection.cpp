/*
 * ClientConnection.cpp
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#include <ctime>

#include "Packets/Packets.h"
#include "ClientConnection.h"
#include "PacketTransferBase.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Tests;

static const int MAX_ACK_NUMBER = 250;

ClientConnection::ClientConnection() {
	this->circuit_code = 0;
	this->transfer_peer = NULL;
}

ClientConnection::ClientConnection(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_peer) :
	circuit_code(circuit_code), ep(ep), transfer_peer(transfer_peer) {}

ClientConnection::~ClientConnection() {}

void ClientConnection::checkACK() {
	if (this->ack_packet_queue.empty()) return;
	PacketAckPacket *packet = new PacketAckPacket();
	S_MUTEX_LOCK l;
	l.lock(&this->ack_lock);
	int count = 0;
	while (!this->ack_packet_queue.empty()) {
		PacketAckPacket::PacketsBlock packets_block;
		packets_block.ID = this->ack_packet_queue.front();
		// TODO @@@ memory reallocate inside "push" + coping packets_block
		packet->Packets.push(packets_block);
		this->ack_packet_queue.pop();
		if (++count == MAX_ACK_NUMBER) break;
	}
	this->transfer_peer->sendPacket(packet, &this->ep);
}

void ClientConnection::checkRESEND() {
	if (this->resend_packet_map.empty()) return;
	S_MUTEX_LOCK l;
	l.lock(&this->resend_lock);
	for(RESEND_PACKET_MAP_TYPE::iterator it=this->resend_packet_map.begin(); it!=this->resend_packet_map.end(); it++) {
		; // RESEND unACKed packets
	}
}

void ClientConnection::processIncomingPacket(const PacketBase *packet) {
	if (packet->header.isReliable()) {
		S_MUTEX_LOCK l;
		l.lock(&this->ack_lock);
		this->ack_packet_queue.push(packet->header.getSequenceNumber());
	}
	if (packet->header.isAppendedAcks()) {
		S_MUTEX_LOCK l;
		l.lock(&this->resend_lock);
		PacketBase::ACK_LIST_TYPE::const_iterator it = packet->appended_acks.begin();
		for (; it != packet->appended_acks.end(); it++) {
			this->remove_resend_packet(*it);
		}
	}
}

void ClientConnection::processOutgoingPacket(const PacketBase *packet) {
	if (packet->header.isReliable()) {
		S_MUTEX_LOCK l;
		l.lock(&this->resend_lock);
		this->add_resend_packet(packet);
	}
}

void ClientConnection::remove_resend_packet(uint32_t seq) {
	RESEND_PACKET_MAP_TYPE::const_iterator it = this->resend_packet_map.find(seq);
	if (it != this->resend_packet_map.end()) {
		this->resend_packet_map.erase(seq);
		if (it->second != NULL) delete it->second;
		this->resend_status_map.erase(seq);
	}
}

void ClientConnection::add_resend_packet(const PacketBase* packet) {
	uint32_t seq_key = packet->header.sequence;
	// @@@ take a copy of the packet
	this->resend_packet_map[seq_key] = PacketFactory::GetInstance()->createPacketCopy(
			packet->header.getPacketID(), packet);
	this->resend_status_map[seq_key] = ::time(NULL);
}

