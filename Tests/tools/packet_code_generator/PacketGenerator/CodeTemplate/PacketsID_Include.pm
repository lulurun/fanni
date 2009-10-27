package CodeTemplate::PacketsID_Include;

use strict;

our $Template =<< "CODE_TEMPLATE";

#ifndef {IMPL_PREFIX}PACKET_ID_H_
#define {IMPL_PREFIX}PACKET_ID_H_

namespace Fanni {

{PacketIDEnum}

};

#endif // {IMPL_PREFIX}PACKET_ID_H

CODE_TEMPLATE

1;

