#include <cassert>
#include <list>
#include <vector>
#include "Poco/Mutex.h"
#include "fanni/Logger.h"
#include "fanni/LLPackets/LLPackets.h"
#include "fanni/LLUDP/AckManager.h"
#include "fanni/LLUDP/ConnectionBase.h"

using namespace Fanni;

AckManager::AckManager(ConnectionBase &conn) : conn(conn), received_packet_list(10000 /* TODO @@@ */) {
	this->check_ACK_timer = new Poco::Timer(0, 250); // TODO @@@ MAGIC NUMBER !
	// TODO @@@ do not use Poco::DefaultThreadPool
	this->check_ACK_timer->start(Poco::TimerCallback<AckManager>(*this, &AckManager::onCheckACKTimer));
	DEBUG_LOG("AckManager started");
}

AckManager::~AckManager() {
	this->check_ACK_timer->stop();
	delete this->check_ACK_timer;
	INFO_LOG("stat: \n" << this->stat.toString());
	DEBUG_LOG("AckManager stopped");
}

// =====
// * return true if this packet needs to be dispatched
bool AckManager::processIncomingPacket(const PacketBasePtr &packet) {
	bool ret = true;
	// stat
	this->stat.received_packets++;
	// ACK
	if (packet->header.isReliable()) {
	    Poco::FastMutex::ScopedLock lock(this->ack_packet_queue);
		this->ack_packet_queue.push_back(packet->header.getSequenceNumber());
		if (packet->header.isResent()) {
			if ( this->received_packet_list.checkReceived(packet->header.getSequenceNumber()) ) {
				// already received, need not to dispatch
				//DEBUG_LOG("packet " << packet->header.getPacketID() << "("  << packet->header.getSequenceNumber() << ") has been already received");
				ret = false;
			}
		}
	}
	// RESEND
    Poco::FastMutex::ScopedLock lock(this->resend_packet_map);
	if (packet->header.isAppendedAcks()) {
		PacketBase::ACK_LIST_TYPE::const_iterator it = packet->appended_acks.begin();
		for (; it != packet->appended_acks.end(); it++) {
			this->removeResendPacket_unsafe(*it);
		}
	}
	// TODO @@@ Should not be here
	if (packet->header.getPacketID() == PacketAck_ID) {
		const PacketAckPacket *ack_packet = dynamic_cast<const PacketAckPacket *>(packet.get());
		assert(ack_packet);
		DEBUG_LOG("removing resend packets: " << ack_packet->Packets.val.size());
		for(std::vector<PacketAckPacket::PacketsBlock>::const_iterator it = ack_packet->Packets.val.begin(); it!=ack_packet->Packets.val.end(); it++) {
			this->removeResendPacket_unsafe(it->ID);
		}
		ret = false;
	}
	return ret;
}

void AckManager::processOutgoingPacket(PacketBasePtr &packet) {
	if (!packet->header.isResent()) {
		packet->setSequence(this->sequence_counter++);
		if (packet->header.isReliable()) {
			Poco::FastMutex::ScopedLock lock(this->resend_packet_map);
			ResendPacketPtr pResendPacket(new ResendPacket(packet));
			this->resend_packet_map[packet->header.getSequenceNumber()] = pResendPacket;
		}
	}
	// stat
	this->stat.send_packets++;
}

// Timer
void AckManager::onCheckACKTimer(Poco::Timer &timer) {
	this->checkACK();
	this->checkRESEND();
}

// TODO @@@ remove this by doing "tomultiplepackets"
static const int MAX_ACK_NUMBER = 250;
void AckManager::checkACK() {
    Poco::FastMutex::ScopedLock lock(this->ack_packet_queue);
    if (this->ack_packet_queue.empty()) return;
    int total_count = 0;
    while (!this->ack_packet_queue.empty()) {
		int count = 0;
		PacketAckPacket *ack_packet = new PacketAckPacket();
		PacketBasePtr packet(ack_packet);
		while (!this->ack_packet_queue.empty()) {
			PacketAckPacket::PacketsBlock packets_block;
			packets_block.ID = this->ack_packet_queue.front();
			// TODO @@@ memory reallocate/copy inside "push" + coping packets_block
			ack_packet->Packets.push(packets_block);
			this->ack_packet_queue.pop_front();
			if (++count == MAX_ACK_NUMBER) break;
		}
		this->conn.sendPacket(packet);
		total_count += count;
    }
	this->stat.acked_packets += total_count;
    DEBUG_LOG("ACKed " << total_count << " packets");
}

void AckManager::checkRESEND() {
    Poco::FastMutex::ScopedLock lock(this->resend_packet_map);
	if (this->resend_packet_map.empty()) return;
	std::list<uint32_t> delete_list;
	int resend_count = 0;
	for(RESEND_PACKET_MAP::iterator it=this->resend_packet_map.begin(); it!=this->resend_packet_map.end(); it++) {
		if (it->second->shouldResend()) {
			PacketBasePtr &packet = it->second->get();
			packet->setFlag(PacketHeader::FLAG_RESENT);
			packet->setFlag(PacketHeader::FLAG_RELIABLE);
			this->conn.sendPacket(packet);
			resend_count++;
		} else if (it->second->shouldGiveup()) {
			WARN_LOG("give up resending packet: " << it->second->get()->header.getPacketID());
			delete_list.push_back(it->first);
		}
	}

	DEBUG_LOG("number of resend packets: " << this->resend_packet_map.size());
	if (!delete_list.empty()) {
		DEBUG_LOG("giveup resending " << delete_list.size() << " packets");
		for(std::list<uint32_t>::const_iterator it=delete_list.begin(); it!=delete_list.end(); it++ ) {
			this->removeResendPacket_unsafe(*it);
		}
		this->stat.giveup_packets += delete_list.size();
	}
	if (resend_count > 0) {
		this->stat.resend_packets += resend_count;
		DEBUG_LOG("resend " << resend_count << " packets");
	}
}

void AckManager::removeResendPacket_unsafe(uint32_t seq) {
	this->resend_packet_map.erase(seq); // TODO @@@ handle not found
}

