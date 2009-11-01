/*
 * ConnectionBase.cpp
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#include <cassert>
#include <list>
#include "Poco/ScopedLock.h"

#include "fanni/EndPoint.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/rUDP/TransferNode.h"
#include "fanni/rUDP/DefaultPacketAckPacket.h"
#include "fanni/rUDP/ConnectionBase.h"

using namespace std;
using namespace Poco;
using namespace Fanni;

ConnectionBase::ConnectionBase(uint32_t circuit_code, const EndPoint &ep, TransferNode &node) :
	node(node), packet_handler_factory(node.getPacketHandlerFactory()),
	ep(ep), circuit_code(circuit_code), last_packet_received(::time(NULL)) {
}

ConnectionBase::~ConnectionBase() {
	this->resend_packet_map.clear();
}

void ConnectionBase::updateLastReceived() {
	// TODO @@@ Lock ?
	this->last_packet_received = ::time(NULL);
}

void ConnectionBase::processIncomingPacket(const PacketBasePtr &packet) {
	TRACE_LOG("enter");
	this->updateLastReceived();
	if (packet->header.isReliable()) {
	    Poco::FastMutex::ScopedLock lock(this->ack_packet_queue);
		this->ack_packet_queue.push(packet->header.getSequenceNumber());
	}
	// process resend
    Poco::FastMutex::ScopedLock lock(this->resend_packet_map);
	if (packet->header.isAppendedAcks()) {
		PacketBase::ACK_LIST_TYPE::const_iterator it = packet->appended_acks.begin();
		for (; it != packet->appended_acks.end(); it++) {
			this->remove_resend_packet_nolock(*it);
		}
	}
	if (packet->header.getPacketID() == DefaultPacketAckPacket::DefaultPacketAck_ID) {
		const DefaultPacketAckPacket *ack_packet = dynamic_cast<const DefaultPacketAckPacket *>(packet.get());
		assert(ack_packet);
		int debug_count = 0;

		DEBUG_LOG("rUDP", "removing resend packets: " << ack_packet->Packets.val.size());

		for(vector<DefaultPacketAckPacket::PacketsBlock>::const_iterator it = ack_packet->Packets.val.begin(); it!=ack_packet->Packets.val.end(); it++) {
			this->remove_resend_packet_nolock(it->ID);
			debug_count++;
		}
		return; // @@@ this is the handler of packetack
	}
	// dispatch packet handler
	const ClientPacketHandlerBase &handler = this->packet_handler_factory.getClientHandler(packet->header.getPacketID());
	handler(packet, this);

	TRACE_LOG("exit");
}

void ConnectionBase::processOutgoingPacket(const PacketBasePtr &packet) {
	if (packet->header.isReliable() && !packet->header.isResent()) {
	    Poco::FastMutex::ScopedLock lock(this->resend_packet_map);
		this->add_resend_packet_nolock(packet);
	}
}

void ConnectionBase::checkACK() {
    Poco::FastMutex::ScopedLock lock(this->ack_packet_queue);
    if (this->ack_packet_queue.empty()) return;
    int total_count = 0;
    while (!this->ack_packet_queue.empty()) {
		int count = 0;
		DefaultPacketAckPacket *ack_packet = new DefaultPacketAckPacket();
		PacketBasePtr packet(ack_packet);
		while (!this->ack_packet_queue.empty()) {
			DefaultPacketAckPacket::PacketsBlock packets_block;
			packets_block.ID = this->ack_packet_queue.front();
			// TODO @@@ memory reallocate/copy inside "push" + coping packets_block
			ack_packet->Packets.push(packets_block);
			this->ack_packet_queue.pop();
			if (++count == MAX_ACK_NUMBER) break;
		}
		this->sendPacket(packet);
		total_count += count;
    }
    DEBUG_LOG("rUDP", "ACKed " << total_count << " packets");
}

void ConnectionBase::checkRESEND() {
    Poco::FastMutex::ScopedLock lock(this->resend_packet_map);
	if (this->resend_packet_map.empty()) return;
	DEBUG_LOG("rUDP", "number of resend packets: " << this->resend_packet_map.size());
	list<uint32_t> delete_list;
	int resend_count = 0;
	for(RESEND_PACKET_MAP::Iterator it=this->resend_packet_map.begin(); it!=this->resend_packet_map.end(); it++) {
		if (it->second->shouldResend()) {
			PacketBasePtr &packet = it->second->get();
			packet->setFlag(PacketHeader::FLAG_RESENT);
			packet->setFlag(PacketHeader::FLAG_RELIABLE);
			this->sendPacket(packet);
			resend_count++;
		} else if (it->second->shouldGiveup()) {
			WARN_LOG("rUDP", "give up resending packet: " << it->second->get()->header.getPacketID());
			delete_list.push_back(it->first);
		}
	}
	DEBUG_LOG("rUDP", "giveup resending " << delete_list.size() << " packets");
	for(list<uint32_t>::const_iterator it=delete_list.begin(); it!=delete_list.end(); it++ ) {
		this->remove_resend_packet_nolock(*it);
	}
	DEBUG_LOG("rUDP", "resending " << resend_count << " packets");
}

bool ConnectionBase::checkALIVE() {
	time_t now = time(NULL);
	if ((now - this->last_packet_received) > CONNECTION_TIMEOUT) {
		return true;
	}
	return false;
}

void ConnectionBase::remove_resend_packet_nolock(uint32_t seq) {
	RESEND_PACKET_MAP::ConstIterator it = this->resend_packet_map.find(seq);
	if (it != this->resend_packet_map.end()) {
		this->resend_packet_map.erase(seq);
	}
}

void ConnectionBase::add_resend_packet_nolock(const PacketBasePtr &packet) {
	ResendPacketPtr resend_packet(new ResendPacket(packet));
	this->resend_packet_map[packet->header.sequence] = resend_packet;
}

void ConnectionBase::sendPacket(PacketBasePtr &packet) {
	this->node.sendPacket(packet, this->ep);
}

