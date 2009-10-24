/*
 * DefaultPacketAckPacket.h
 *
 *  Created on: Oct 24, 2009
 *      Author: lulu
 */

#ifndef DEFAULTPACKETACKPACKET_H_
#define DEFAULTPACKETACKPACKET_H_

#include "fanni/Exception.h"
#include "Packets/PacketBase.h"
#include "Packets/PacketSerializer.h"
#include "Packets/PacketBaseTypes.h"

namespace Fanni {

// Default PacketAckPacket
class DefaultPacketAckPacket : public PacketBase {
public:
	enum {
		 DefaultPacketAck_ID = 0xFFFFFFFB,
	};
    // Block Class List
    class PacketsBlock : public PacketSerializable {
    public:
        // PacketsBlock Member List
        SerializableU32 ID;
    public:
        PacketsBlock() {};
        virtual ~PacketsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // PacketAckPacket Member List
    VariableSerializable<PacketsBlock> Packets;
    typedef VariableSerializable<PacketsBlock> PACKETSBLOCK_LIST_TYPE;

public:
    DefaultPacketAckPacket() {
        this->setID(DefaultPacketAck_ID);
    };
    virtual ~DefaultPacketAckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Packets.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Packets.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DefaultPacketAckPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DefaultPacketAckPacket *PacketAckPacket_packet = dynamic_cast<const DefaultPacketAckPacket *>(packet);
        if (PacketAckPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DefaultPacketAckPacket(*PacketAckPacket_packet);
    }
};

// TODO @@@ get this from config
static const int MAX_ACK_NUMBER = 0xff;

}

#endif /* DEFAULTPACKETACKPACKET_H_ */
