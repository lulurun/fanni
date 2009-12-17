#ifndef PACKETSERIALIZER_H_
#define PACKETSERIALIZER_H_

#include "fanni/PacketBuffer.h"
#include "fanni/Packets/Packets_def.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketFactory.h"

namespace Fanni {

class Fanni_Packets_API PacketSerializer {
private:
	const PacketFactory &packet_factory;

public:
	PacketSerializer(const PacketFactory &packet_factory);
	virtual ~PacketSerializer();

	PacketBufferPtr serialize(const PacketBasePtr &pPacket) const;
	PacketBasePtr deserialize(PacketBufferPtr &pBuf) const;

	static bool isZerocoded(PacketBufferPtr &pBuf);
	static bool isAppendedAcks(PacketBufferPtr &pBuf);

	static void zeroEncode(PacketBufferPtr &pBuf);
	static void zeroDecode(PacketBufferPtr &pBuf);

};

}

#endif /* PACKETSERIALIZER_H_ */
