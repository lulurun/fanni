#include "fanni/Packets/PacketHeader.h"
#include "fanni/Packets/PacketSerializer.h"

namespace Fanni {

PacketSerializer::PacketSerializer(const PacketFactory &packet_factory):
	packet_factory(packet_factory) {
}

PacketSerializer::~PacketSerializer() {}

PacketBuffer PacketSerializer::serialize(const PacketBasePtr &packet) const {
	PacketBuffer buf(new __PacketBuffer());
	packet->serializePacket(buf);
	return buf;
}

PacketBasePtr PacketSerializer::deserialize(PacketBuffer &buffer) const {
	buffer->resetPos();
	PacketHeader header;
	header.deserialize(buffer);
	PacketBasePtr packet = this->packet_factory.createPacket(header.getPacketID());
	if (packet.get() == NULL) {
		ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "unknown packet: %08x", header.getPacketID());
	}
	buffer->resetPos();
	packet->deserializePacket(buffer); // TODO @@@ header is deserialized twice !!
	return packet;
}

bool PacketSerializer::isZerocoded(PacketBuffer &buf) {
    return ((*buf)[0] & PacketHeader::FLAG_ZEROCODED)!=0;
}

bool PacketSerializer::isAppendedAcks(PacketBuffer &buf) {
    return ((*buf)[0] & PacketHeader::FLAG_APPENDED_ACKS)!=0;
}

void PacketSerializer::zeroEncode(PacketBuffer &data) {
	// Create a copy
	PacketBuffer src_buf(new __PacketBuffer(data->getConstBuffer(), data->getLength()));
	int srclen = src_buf->getLength();
	const unsigned char* src = src_buf->getConstBuffer();
	int bodylen = isAppendedAcks(src_buf) ? srclen - src[srclen - 1] * 4 - 1 : srclen;
	unsigned char *dest = data->getBuffer();

	int zerolen = 6; // Skip header, 6 = header length
	//int zerolen = 0; // Skip header, 6 = header length
	unsigned char zerocount = 0;
	for (int i = zerolen; i < bodylen; i++) {
		if (src[i] == 0x00) {
			zerocount++;
			if (zerocount == 0) {
				dest[zerolen++] = 0x00;
				dest[zerolen++] = 0xff;
				zerocount++;
			}
		} else {
			if (zerocount != 0) {
				dest[zerolen++] = 0x00;
				dest[zerolen++] = (unsigned char)zerocount;
				zerocount = 0;
			}
			dest[zerolen++] = src[i];
		}
	}
	data->setPos(zerolen);
}

void PacketSerializer::zeroDecode(PacketBuffer &data) {
	// Create a copy
	PacketBuffer src_buf(new __PacketBuffer(data->getConstBuffer(), data->getLength()));
	int srclen = src_buf->getLength();
    int bodylen = srclen;
	const unsigned char* src = src_buf->getConstBuffer();
    unsigned char *dest = data->getBuffer();

	int zerolen = 6; // Skip header, 6 = header length
	//int zerolen = 0; // Skip header, 6 = header length
	int i; // TODO @@@ not necessary
	for (i = zerolen; i < bodylen; i++) {
        if (src[i] == 0x00) {
            for (unsigned char j = 0; j < src[i + 1]; j++) {
                dest[zerolen++] = 0x00;
            }
            i++;
        } else {
            dest[zerolen++] = src[i];
        }
    }
    // Copy appended ACKs
    for (; i < srclen; i++) {
        dest[zerolen++] = src[i];
    }
	data->setPos(zerolen);
}

}
