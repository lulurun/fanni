#include "PacketHeader.h"
#include "PacketSerializer.h"

namespace Fanni {

PacketSerializer::PacketSerializer(const PacketFactory &packet_factory) :
	factory(packet_factory) {
}

PacketSerializer::~PacketSerializer() {
}

const unsigned char *PacketSerializer::serialize(const PacketBase *obj, int *len) {
	// @@@ lock(this->buf) is not needed if each worker has its own PacketSerializer
	this->buf.clear();
	obj->serializePacket(this->buf);
	*len = this->buf.getLength();
	return this->buf.getConstBuffer();
}

PacketBase *PacketSerializer::deserialize(const unsigned char *in, int len) {
	// @@@ lock(this->buf) is not needed if each work has its own PacketSerializer
	this->buf.clear();
	this->buf.putBuf(in, len);
	return this->deserialize(this->buf);
}

PacketBase *PacketSerializer::deserialize(PacketBuffer &in) {
	// @@@ lock(this->buf) is not needed if each work has its own PacketSerializer
	in.resetPos();
	PacketHeader header;
	header.deserialize(in);
	PacketBase *packet = this->factory.createPacket(header.getPacketID());
	if (packet == NULL) {
		ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "unknown packet: %08x", header.getPacketID());
	}
	in.resetPos();
	packet->deserializePacket(in); // TODO @@@ header is deserialized twice !!
	return packet; // @@@ this packet will be deleted by "Receiver"
}

bool PacketSerializer::isZerocoded(PacketBuffer &buf) {
    return (buf[0] & PacketHeader::FLAG_ZEROCODED)!=0;
}

bool PacketSerializer::isAppendedAcks(PacketBuffer &buf) {
    return (buf[0] & PacketHeader::FLAG_APPENDED_ACKS)!=0;
}

void PacketSerializer::zeroEncode(PacketBuffer &data) {
	PacketBuffer src = data;
	int srclen = src.getLength();
	int bodylen = isAppendedAcks(src) ? srclen - src[srclen - 1] * 4 - 1 : srclen;
	unsigned char *dest = data.getBuffer();

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
	data.setPos(zerolen);
}

void PacketSerializer::zeroDecode(PacketBuffer &data) {
	PacketBuffer src(data);
	int srclen = src.getLength();
    int bodylen = srclen;
    unsigned char *dest = data.getBuffer();

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
	data.setPos(zerolen);
}

}
