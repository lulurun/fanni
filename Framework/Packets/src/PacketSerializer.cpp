#include "fanni/Packets/PacketHeader.h"
#include "fanni/Packets/PacketSerializer.h"

namespace Fanni {

PacketSerializer::PacketSerializer(const PacketFactory &packet_factory):
	packet_factory(packet_factory) {
}

PacketSerializer::~PacketSerializer() {}

PacketBufferPtr PacketSerializer::serialize(const PacketBasePtr &pPacket) const {
	PacketBufferPtr pBuf(new PacketBuffer());
	pPacket->serializePacket(*pBuf.get());
	return pBuf;
}

PacketBasePtr PacketSerializer::deserialize(PacketBufferPtr &pBuf) const {
	pBuf->resetPos();
	PacketHeader header;
	header.deserialize(*pBuf.get());
	PacketBasePtr pPacket = this->packet_factory.createPacket(header.getPacketID());
	if (pPacket.get() == NULL) {
		ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "unknown packet: %08x", header.getPacketID());
	}
	pBuf->resetPos();
	pPacket->deserializePacket(*pBuf.get()); // TODO @@@ header is deserialized twice !!
	return pPacket;
}

bool PacketSerializer::isZerocoded(PacketBufferPtr &pBuf) {
    return ((*pBuf)[0] & PacketHeader::FLAG_ZEROCODED)!=0;
}

bool PacketSerializer::isAppendedAcks(PacketBufferPtr &pBuf) {
    return ((*pBuf)[0] & PacketHeader::FLAG_APPENDED_ACKS)!=0;
}

void PacketSerializer::zeroEncode(PacketBufferPtr &pBuf) {
	// Create a copy
	PacketBufferPtr pSrc(new PacketBuffer(pBuf->getConstBuffer(), pBuf->getLength()));
	int srclen = pSrc->getLength();
	const unsigned char* src = pSrc->getConstBuffer();
	int bodylen = isAppendedAcks(pSrc) ? srclen - src[srclen - 1] * 4 - 1 : srclen;
	unsigned char *dest = pBuf->getBuffer();

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
	pBuf->setPos(zerolen);
}

void PacketSerializer::zeroDecode(PacketBufferPtr &pBuf) {
	// Create a copy
	PacketBufferPtr pSrc(new PacketBuffer(pBuf->getConstBuffer(), pBuf->getLength()));
	int srclen = pSrc->getLength();
    int bodylen = srclen;
	const unsigned char* src = pSrc->getConstBuffer();
    unsigned char *dest = pBuf->getBuffer();

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
	pBuf->setPos(zerolen);
}

}
