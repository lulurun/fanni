#include "fanni/Logger.h"
#include "fanni/Packets/PacketBase.h"

namespace Fanni {

PacketBase::PacketBase() {
}

PacketBase::~PacketBase() {
}

void PacketBase::setFlag(PacketHeader::Flag flag) {
	this->header.flag |= flag;
}

void PacketBase::setSequence(uint32_t seq) {
	this->header.setSequenceNumber(seq);
}

void PacketBase::setID(uint32_t id) {
	this->header.freq = (PacketHeader::Frequency)(id >> 16);
	//this->header.id = id << 16 >> 16;
	this->header.id = id;
}

void PacketBase::appendAck(uint32_t ack_seq) {
	this->header.setAppendedAcks(true);
	appended_acks.push_back(ack_seq);
}

const PacketBase::ACK_LIST_TYPE &PacketBase::getAppendedAcks() const {
	return this->appended_acks;
}

void PacketBase::serializePacket(PacketBuffer &buffer) const {
	TRACE_LOG("enter");
	// header
	this->header.serialize(buffer);
	// body
	this->serialize(buffer);
	// acks
	if (this->header.isAppendedAcks()) {
		unsigned char ack_number = static_cast<unsigned char>(this->appended_acks.size());
		for(int i=0; i<ack_number; i++) {
			buffer->putValue<uint32_t>(appended_acks[i]);
		}
		buffer->putValue<uint8_t>(ack_number);
	}
	TRACE_LOG("exit");
}

void PacketBase::deserializePacket(PacketBuffer &buffer) {
	TRACE_LOG("enter");
	// header
	this->header.deserialize(buffer);
	// body
	this->deserialize(buffer);
	// acks
	if (this->header.isAppendedAcks()) {
		int buf_len = buffer->getLength();
		buffer->resetPos(buf_len-1);
		int ack_number = buffer->getValue<uint8_t>();
		int ack_len = ack_number * 4 + 1;
		buffer->resetPos(buf_len - ack_len);
		for(int i=0; i<ack_number; i++) {
			this->appended_acks.push_back(buffer->getValue<uint32_t>());
		}
	}
	TRACE_LOG("exit");
}

}
