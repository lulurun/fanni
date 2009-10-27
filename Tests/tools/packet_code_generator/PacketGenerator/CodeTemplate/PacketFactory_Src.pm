package CodeTemplate::PacketFactory_Src;

use strict;

our $Template =<< "CODE_TEMPLATE";

#include "fanni/{IMPL_PREFIX}Packets/{IMPL_PREFIX}Packets.h"
#include "fanni/{IMPL_PREFIX}Packets/{IMPL_PREFIX}PacketFactory.h"

namespace Fanni {

{IMPL_PREFIX}PacketFactory::{IMPL_PREFIX}PacketFactory() {
{InitAllPackets}
}

{IMPL_PREFIX}PacketFactory::~{IMPL_PREFIX}PacketFactory() {}

PacketSerializer *Create{IMPL_PREFIX}PacketSerializer() {
    return new PacketSerializer({IMPL_PREFIX}PacketFactorySingleton::get());
}

}

CODE_TEMPLATE

1;
