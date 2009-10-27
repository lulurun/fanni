#include "fanni/Exception.h"
#include "fanni/Logger.h"
#include "fanni/Packets/PacketHeader.h"

using namespace Fanni;

PacketHeader::PacketHeader() {
	// TODO @@@ init flag
	this->flag = FLAG_UNKNOWN;
}

PacketHeader::~PacketHeader() {
}

void PacketHeader::serialize(PacketBuffer &buffer) const {
	this->flag.serialize(buffer);
	this->sequence.serialize(buffer);
	this->undef.serialize(buffer);
	switch (this->freq) {
	case FREQ_LOW:
		buffer.putValue<uint16_t>(0xFFFF);
		buffer.putValue<uint16_t>(this->id << 16 >> 16);
		break;
	case FREQ_MEDIUM:
		buffer.putValue<uint8_t>(0xFF);
		buffer.putValue<uint8_t>(this->id << 24 >> 24);
		break;
	case FREQ_HIGH:
		buffer.putValue<uint8_t>(this->id << 24 >> 24);
		break;
	case FREQ_FIXED:
		// TODO @@@ * LOW == FIXED
		// in fact, no such case
		buffer.putValue<uint16_t>(0xFFFF);
		buffer.putValue<uint16_t>(this->id << 16 >> 16);
		break;
	case FREQ_UNKNOWN:
    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "frequency is not initialized");
		break;
	default:
    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "unknown frequency enum type");
		break;
	}
}

void PacketHeader::deserialize(PacketBuffer &buffer) {
	this->flag.deserialize(buffer);
	this->sequence.deserialize(buffer);
	this->undef.deserialize(buffer);
	uint8_t c1 = buffer.getValue<uint8_t>();
	if (c1 != 0xFF) {
		this->freq = FREQ_HIGH;
		this->id = c1;
	} else {
		uint8_t c2 = buffer.getValue<uint8_t>();
		if (c2 != 0xFF) {
			this->freq = FREQ_MEDIUM;
			this->id = c2 | 0x00FF0000;
		} else {
			this->freq = FREQ_LOW;
			this->id = buffer.getValue<uint16_t>()  | 0xFFFF0000;
			// TODO @@@ * LOW == FIXED
		}
	}
}

bool PacketHeader::isAppendedAcks() const {
    return (this->flag & FLAG_APPENDED_ACKS) != 0;
}

void PacketHeader::setAppendedAcks(bool val) {
    if(val) {
    	this->flag |= (unsigned char) FLAG_APPENDED_ACKS;
    }
    else {
    	this->flag &= (FLAG_APPENDED_ACKS ^ 0xFF);
    }
}

bool PacketHeader::isResent() const {
    return (this->flag & FLAG_RESENT) != 0;
}

void PacketHeader::setResent(bool val) {
    if(val) {
    	this->flag |= (unsigned char) FLAG_RESENT;
    }
    else {
    	this->flag &= (FLAG_RESENT ^ 0xFF);
    }
}

bool PacketHeader::isReliable() const {
    return (this->flag & FLAG_RELIABLE) != 0;
}

void PacketHeader::setReliable(bool val) {
    if(val) {
    	this->flag |= FLAG_RELIABLE;
    }
    else {
        this->flag &= (FLAG_RELIABLE ^ 0xFF);
    }
}

bool PacketHeader::isZeroCoded() const {
    return (this->flag & FLAG_ZEROCODED) != 0;
}

void PacketHeader::setZeroCoded(bool val) {
    if (val) {
        this->flag |= FLAG_ZEROCODED;
    } else {
    	this->flag &= (FLAG_ZEROCODED ^ 0xFF);
    }
}

uint32_t PacketHeader::getSequenceNumber() const {
	return this->sequence;
}

void PacketHeader::setSequenceNumber(uint32_t seq) {
	this->sequence = seq;
}

PacketHeader::PACKET_ID_TYPE PacketHeader::getPacketID() const {
	return this->id;
}

void PacketHeader::setPacketID(PacketHeader::PACKET_ID_TYPE packet_id) {
	this->id = packet_id;
}

PacketHeader::Frequency PacketHeader::getFrequence() const {
	return this->freq;
}

void PacketHeader::setFrequence(Frequency freq) {
	this->freq = freq;
}

