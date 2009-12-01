package CodeTemplate::Packets_Src;

use strict;

our $Template =<< "CODE_TEMPLATE";

#include "fanni/{IMPL_PREFIX}Packets/{IMPL_PREFIX}Packets.h"

namespace Fanni {

void {IMPL_PREFIX}Packets::init(PacketFactory &packet_factory) {
{RegisterAllPackets}
}

}

CODE_TEMPLATE

1;
