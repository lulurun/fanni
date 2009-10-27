package CodeTemplate::PacketFactory_Include;

use strict;

our $Template =<< "CODE_TEMPLATE";

#ifndef {IMPL_PREFIX}PACKETFACTORY_H_
#define {IMPL_PREFIX}PACKETFACTORY_H_

#include "fanni/SingletonTemplate.h"
#include "fanni/Packets/PacketFactory.h"
#include "fanni/Packets/PacketSerializer.h"
#include "fanni/{IMPL_PREFIX}Packets/{IMPL_PREFIX}Packets_def.h"

namespace Fanni {

class Fanni_{IMPL_PREFIX}Packets_API {IMPL_PREFIX}PacketFactory : public PacketFactory {
public:
    {IMPL_PREFIX}PacketFactory();
    virtual ~{IMPL_PREFIX}PacketFactory();
};

typedef Singleton<{IMPL_PREFIX}PacketFactory> {IMPL_PREFIX}PacketFactorySingleton;

PacketSerializer *Create{IMPL_PREFIX}PacketSerializer();

}

#endif /* {IMPL_PREFIX}PACKETFACTORY_H_ */

CODE_TEMPLATE

1;

