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

	PacketBuffer serialize(const PacketBasePtr &packet) const;
	PacketBasePtr deserialize(PacketBuffer &buf) const;

	static bool isZerocoded(PacketBuffer &buf);
	static bool isAppendedAcks(PacketBuffer &buf);

	static void zeroEncode(PacketBuffer &buf);
	static void zeroDecode(PacketBuffer &buf);

};

}

#endif /* PACKETSERIALIZER_H_ */
