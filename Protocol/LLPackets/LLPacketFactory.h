#ifndef LLPACKETFACTORY_H_
#define LLPACKETFACTORY_H_

#include "fanni/Serializable.h"
#include "fanni/SingletonTemplate.h"

#include "Packets/PacketFactory.h"
#include "Packets/PacketSerializer.h"
#include "LLPackets.h"

namespace Fanni {

class LLPacketFactory : public PacketFactory {
public:
	LLPacketFactory();
	virtual ~LLPacketFactory();
	virtual void init();
};

typedef Singleton<LLPacketFactory> LLPacketFactorySingleton;

PacketSerializer *CreateLLPacketSerializer();

}

#endif /* LLPACKETFACTORY_H_ */
