#ifndef PACKETFACTORY_H_
#define PACKETFACTORY_H_

#include <tr1/unordered_map>

#include "fanni/Serializable.h"

#include "PacketHeader.h"
#include "PacketBase.h"

namespace Fanni {

class PacketFactory {
protected:
	typedef std::tr1::unordered_map<PacketHeader::PACKET_ID_TYPE, const PacketBase*> PACKET_MAP_TYPE;
	PACKET_MAP_TYPE PacketList;

	PacketFactory();
public:
	virtual ~PacketFactory();
	PacketBase *createPacket(PacketHeader::PACKET_ID_TYPE packet_id) const;
	PacketBase *createPacketCopy(PacketHeader::PACKET_ID_TYPE packet_id, const PacketBase *packet) const;

	// register packets
	virtual void init() = 0;

};

}

#endif /* PACKETFACTORY_H_ */
