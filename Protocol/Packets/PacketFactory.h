#ifndef PACKETFACTORY_H_
#define PACKETFACTORY_H_

#include "fanni/Serializable.h"
#include "PacketHeader.h"
#include "PacketBase.h"

namespace Fanni {

class PacketFactory {

	PacketFactory();
public:
	virtual ~PacketFactory();

	void init();
	PacketBase *createPacket(PacketHeader::PACKET_ID_TYPE packet_id) const;
	PacketBase *createPacketCopy(PacketHeader::PACKET_ID_TYPE packet_id, const PacketBase *packet) const;
	static PacketFactory *GetInstance();
};

}

#endif /* PACKETFACTORY_H_ */
