
#ifndef FTPACKETFACTORY_H_
#define FTPACKETFACTORY_H_

#include "fanni/SingletonTemplate.h"
#include "fanni/Packets/PacketFactory.h"
#include "fanni/Packets/PacketSerializer.h"
#include "fanni/FTPackets/FTPackets_def.h"

namespace Fanni {

class Fanni_FTPackets_API FTPacketFactory : public PacketFactory {
public:
    FTPacketFactory();
    virtual ~FTPacketFactory();
};

typedef Singleton<FTPacketFactory> FTPacketFactorySingleton;

PacketSerializer *CreateFTPacketSerializer();

}

#endif /* FTPACKETFACTORY_H_ */

