#ifndef PACKETSERIALIZER_H_
#define PACKETSERIALIZER_H_

#include "fanni/PacketBuffer.h"
#include "fanni/Packets/Packets_def.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketFactory.h"

namespace Fanni {

class Fanni_Packets_API PacketSerializer {
private:
	// @@@ not thread safe
	PacketBuffer buf;
	const PacketFactory &factory;

public:
	PacketSerializer(const PacketFactory &packet_factory);
	virtual ~PacketSerializer();

	const unsigned char *serialize(const PacketBase *packet, int *len);
	PacketBase *deserialize(const unsigned char *in, int len);
	PacketBase *deserialize(PacketBuffer &buf);

	static bool isZerocoded(PacketBuffer &buf);
	static bool isAppendedAcks(PacketBuffer &buf);

	static void zeroEncode(PacketBuffer &buf);
	static void zeroDecode(PacketBuffer &buf);

};

}

#endif /* PACKETSERIALIZER_H_ */
