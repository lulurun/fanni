
#ifndef LLPACKETFACTORY_H_
#define LLPACKETFACTORY_H_

#include "fanni/SingletonTemplate.h"
#include "fanni/Packets/PacketFactory.h"
#include "fanni/Packets/PacketSerializer.h"
#include "fanni/LLPackets/LLPackets_def.h"

namespace Fanni {

class Fanni_LLPackets_API LLPacketFactory : public PacketFactory {
public:
    LLPacketFactory();
    virtual ~LLPacketFactory();
};

typedef Singleton<LLPacketFactory> LLPacketFactorySingleton;

PacketSerializer *CreateLLPacketSerializer();

}

#endif /* LLPACKETFACTORY_H_ */

