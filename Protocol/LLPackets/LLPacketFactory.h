#ifndef LLPACKETFACTORY_H_
#define LLPACKETFACTORY_H_

#include "fanni/SingletonTemplate.h"

#include "Packets/PacketFactory.h"
#include "Packets/PacketSerializer.h"

namespace Fanni {

class LLPacketFactory : public PacketFactory {
public:
    LLPacketFactory();
    virtual ~LLPacketFactory();
};

typedef Singleton<LLPacketFactory> LLPacketFactorySingleton;

PacketSerializer *CreateLLPacketSerializer();

}

#endif /* LLPACKETFACTORY_H_ */

