package CodeTemplate::Packets_Include;

use strict;


our $Template =<< "CODE_TEMPLATE";

#ifndef {IMPL_PREFIX}PACKET_IMPL_H_
#define {IMPL_PREFIX}PACKET_IMPL_H_

#include "fanni/Exception.h"
#include "fanni/Packets/PacketBaseTypes.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketFactory.h"
#include "fanni/{IMPL_PREFIX}Packets/{IMPL_PREFIX}PacketsID.h"
#include "fanni/{IMPL_PREFIX}Packets/{IMPL_PREFIX}Packets_def.h"

namespace Fanni {

{PacketClasses}

class Fanni_{IMPL_PREFIX}Packets_API {IMPL_PREFIX}Packets {
public:
    static void init(PacketFactory &packet_factory);
};

}

#endif // {IMPL_PREFIX}PACKET_IMPL_H

CODE_TEMPLATE

our $PacketClass_Template =<< "PACKETCLASS_TEMPLATE";
// {ClassName}
class {ClassName} : public {BaseClassName} {
public:

    // Block Class List
{BlockClassList}

    // {ClassName} Member List
{MemberList}

public:
    {ClassName}() {
{SetPacketInfo}
    };
    virtual ~{ClassName}() { };

    virtual void serialize(PacketBuffer &buffer) const {
{MemberListSerialize}
    }
    virtual void deserialize(PacketBuffer &buffer) {
{MemberListDeserialize}
    }
    virtual PacketBase *clone() const {
        return new {ClassName}(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const {ClassName} *{ClassName}_packet = dynamic_cast<const {ClassName} *>(packet);
        if ({ClassName}_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new {ClassName}(*{ClassName}_packet);
    }
};

PACKETCLASS_TEMPLATE

our $BlockClass_Template =<< "BLOCKCLASS_TEMPLATE";
class {ClassName} : public {BaseClassName} {
public:
    // {ClassName} Member List
{MemberList}

public:
    {ClassName}() {
{SetPacketInfo}
    };
    virtual ~{ClassName}() { };

    virtual void serialize(PacketBuffer &buffer) const {
{MemberListSerialize}
    }
    virtual void deserialize(PacketBuffer &buffer) {
{MemberListDeserialize}
    }
};

BLOCKCLASS_TEMPLATE

1;

