
#ifndef LLPACKET_IMPL_H_
#define LLPACKET_IMPL_H_

#include "fanni/Exception.h"
#include "fanni/Packets/PacketBaseTypes.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketFactory.h"
#include "fanni/LLPackets/LLPacketsID.h"
#include "fanni/LLPackets/LLPackets_def.h"

namespace Fanni {

// TestMessagePacket
class TestMessagePacket : public PacketBase {
public:

    // Block Class List
    class TestBlock1Block : public PacketSerializable {
    public:
        // TestBlock1Block Member List
        SerializableU32 Test1;
    public:
        TestBlock1Block() {};
        virtual ~TestBlock1Block() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Test1.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Test1.deserialize(buffer);
        }
    };
    class NeighborBlockBlock : public PacketSerializable {
    public:
        // NeighborBlockBlock Member List
        SerializableU32 Test0;
        SerializableU32 Test1;
        SerializableU32 Test2;
    public:
        NeighborBlockBlock() {};
        virtual ~NeighborBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Test0.serialize(buffer);
            Test1.serialize(buffer);
            Test2.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Test0.deserialize(buffer);
            Test1.deserialize(buffer);
            Test2.deserialize(buffer);
        }
    };
    // TestMessagePacket Member List
    TestBlock1Block TestBlock1;
    MultipleSerializable<NeighborBlockBlock, 4> NeighborBlock;
    typedef MultipleSerializable<NeighborBlockBlock, 4> NEIGHBORBLOCKBLOCK_LIST_TYPE;

public:
    TestMessagePacket() {
        this->setID(TestMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TestMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TestBlock1.serialize(buffer);
        NeighborBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TestBlock1.deserialize(buffer);
        NeighborBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TestMessagePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TestMessagePacket *TestMessagePacket_packet = dynamic_cast<const TestMessagePacket *>(packet);
        if (TestMessagePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TestMessagePacket(*TestMessagePacket_packet);
    }
};

// PacketAckPacket
class PacketAckPacket : public PacketBase {
public:

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
    PacketAckPacket() {
        this->setID(PacketAck_ID);
    };
    virtual ~PacketAckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Packets.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Packets.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PacketAckPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const PacketAckPacket *PacketAckPacket_packet = dynamic_cast<const PacketAckPacket *>(packet);
        if (PacketAckPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new PacketAckPacket(*PacketAckPacket_packet);
    }
};

// OpenCircuitPacket
class OpenCircuitPacket : public PacketBase {
public:

    // Block Class List
    class CircuitInfoBlock : public PacketSerializable {
    public:
        // CircuitInfoBlock Member List
        SerializableIPADDR IP;
        SerializableIPPORT Port;
    public:
        CircuitInfoBlock() {};
        virtual ~CircuitInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IP.serialize(buffer);
            Port.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IP.deserialize(buffer);
            Port.deserialize(buffer);
        }
    };
    // OpenCircuitPacket Member List
    CircuitInfoBlock CircuitInfo;

public:
    OpenCircuitPacket() {
        this->setID(OpenCircuit_ID);
    };
    virtual ~OpenCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        CircuitInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        CircuitInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OpenCircuitPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const OpenCircuitPacket *OpenCircuitPacket_packet = dynamic_cast<const OpenCircuitPacket *>(packet);
        if (OpenCircuitPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new OpenCircuitPacket(*OpenCircuitPacket_packet);
    }
};

// CloseCircuitPacket
class CloseCircuitPacket : public PacketBase {
public:

    // Block Class List
    // CloseCircuitPacket Member List

public:
    CloseCircuitPacket() {
        this->setID(CloseCircuit_ID);
    };
    virtual ~CloseCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new CloseCircuitPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CloseCircuitPacket *CloseCircuitPacket_packet = dynamic_cast<const CloseCircuitPacket *>(packet);
        if (CloseCircuitPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CloseCircuitPacket(*CloseCircuitPacket_packet);
    }
};

// StartPingCheckPacket
class StartPingCheckPacket : public PacketBase {
public:

    // Block Class List
    class PingIDBlock : public PacketSerializable {
    public:
        // PingIDBlock Member List
        SerializableU8 PingID;
        SerializableU32 OldestUnacked;
    public:
        PingIDBlock() {};
        virtual ~PingIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PingID.serialize(buffer);
            OldestUnacked.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PingID.deserialize(buffer);
            OldestUnacked.deserialize(buffer);
        }
    };
    // StartPingCheckPacket Member List
    PingIDBlock PingID;

public:
    StartPingCheckPacket() {
        this->setID(StartPingCheck_ID);
    };
    virtual ~StartPingCheckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        PingID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        PingID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StartPingCheckPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const StartPingCheckPacket *StartPingCheckPacket_packet = dynamic_cast<const StartPingCheckPacket *>(packet);
        if (StartPingCheckPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new StartPingCheckPacket(*StartPingCheckPacket_packet);
    }
};

// CompletePingCheckPacket
class CompletePingCheckPacket : public PacketBase {
public:

    // Block Class List
    class PingIDBlock : public PacketSerializable {
    public:
        // PingIDBlock Member List
        SerializableU8 PingID;
    public:
        PingIDBlock() {};
        virtual ~PingIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PingID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PingID.deserialize(buffer);
        }
    };
    // CompletePingCheckPacket Member List
    PingIDBlock PingID;

public:
    CompletePingCheckPacket() {
        this->setID(CompletePingCheck_ID);
    };
    virtual ~CompletePingCheckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        PingID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        PingID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CompletePingCheckPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CompletePingCheckPacket *CompletePingCheckPacket_packet = dynamic_cast<const CompletePingCheckPacket *>(packet);
        if (CompletePingCheckPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CompletePingCheckPacket(*CompletePingCheckPacket_packet);
    }
};

// UseCircuitCodePacket
class UseCircuitCodePacket : public PacketBase {
public:

    // Block Class List
    class CircuitCodeBlock : public PacketSerializable {
    public:
        // CircuitCodeBlock Member List
        SerializableU32 Code;
        SerializableUUID SessionID;
        SerializableUUID ID;
    public:
        CircuitCodeBlock() {};
        virtual ~CircuitCodeBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Code.serialize(buffer);
            SessionID.serialize(buffer);
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Code.deserialize(buffer);
            SessionID.deserialize(buffer);
            ID.deserialize(buffer);
        }
    };
    // UseCircuitCodePacket Member List
    CircuitCodeBlock CircuitCode;

public:
    UseCircuitCodePacket() {
        this->setID(UseCircuitCode_ID);
    };
    virtual ~UseCircuitCodePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        CircuitCode.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        CircuitCode.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UseCircuitCodePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UseCircuitCodePacket *UseCircuitCodePacket_packet = dynamic_cast<const UseCircuitCodePacket *>(packet);
        if (UseCircuitCodePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UseCircuitCodePacket(*UseCircuitCodePacket_packet);
    }
};

// EconomyDataRequestPacket
class EconomyDataRequestPacket : public PacketBase {
public:

    // Block Class List
    // EconomyDataRequestPacket Member List

public:
    EconomyDataRequestPacket() {
        this->setID(EconomyDataRequest_ID);
    };
    virtual ~EconomyDataRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new EconomyDataRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EconomyDataRequestPacket *EconomyDataRequestPacket_packet = dynamic_cast<const EconomyDataRequestPacket *>(packet);
        if (EconomyDataRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EconomyDataRequestPacket(*EconomyDataRequestPacket_packet);
    }
};

// AvatarPickerRequestPacket
class AvatarPickerRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID QueryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableVariable1 Name;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Name.deserialize(buffer);
        }
    };
    // AvatarPickerRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    AvatarPickerRequestPacket() {
        this->setID(AvatarPickerRequest_ID);
    };
    virtual ~AvatarPickerRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPickerRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AvatarPickerRequestPacket *AvatarPickerRequestPacket_packet = dynamic_cast<const AvatarPickerRequestPacket *>(packet);
        if (AvatarPickerRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AvatarPickerRequestPacket(*AvatarPickerRequestPacket_packet);
    }
};

// PlacesQueryPacket
class PlacesQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID QueryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS8 Category;
        SerializableVariable1 SimName;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            SimName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            SimName.deserialize(buffer);
        }
    };
    // PlacesQueryPacket Member List
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    QueryDataBlock QueryData;

public:
    PlacesQueryPacket() {
        this->setID(PlacesQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~PlacesQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PlacesQueryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const PlacesQueryPacket *PlacesQueryPacket_packet = dynamic_cast<const PlacesQueryPacket *>(packet);
        if (PlacesQueryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new PlacesQueryPacket(*PlacesQueryPacket_packet);
    }
};

// DirFindQueryPacket
class DirFindQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirFindQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirFindQueryPacket() {
        this->setID(DirFindQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirFindQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirFindQueryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DirFindQueryPacket *DirFindQueryPacket_packet = dynamic_cast<const DirFindQueryPacket *>(packet);
        if (DirFindQueryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DirFindQueryPacket(*DirFindQueryPacket_packet);
    }
};

// DirPlacesQueryPacket
class DirPlacesQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS8 Category;
        SerializableVariable1 SimName;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            SimName.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            SimName.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirPlacesQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirPlacesQueryPacket() {
        this->setID(DirPlacesQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPlacesQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPlacesQueryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DirPlacesQueryPacket *DirPlacesQueryPacket_packet = dynamic_cast<const DirPlacesQueryPacket *>(packet);
        if (DirPlacesQueryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DirPlacesQueryPacket(*DirPlacesQueryPacket_packet);
    }
};

// DirClassifiedQueryPacket
class DirClassifiedQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableU32 Category;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirClassifiedQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirClassifiedQueryPacket() {
        this->setID(DirClassifiedQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirClassifiedQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirClassifiedQueryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DirClassifiedQueryPacket *DirClassifiedQueryPacket_packet = dynamic_cast<const DirClassifiedQueryPacket *>(packet);
        if (DirClassifiedQueryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DirClassifiedQueryPacket(*DirClassifiedQueryPacket_packet);
    }
};

// ClassifiedInfoRequestPacket
class ClassifiedInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
        }
    };
    // ClassifiedInfoRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedInfoRequestPacket() {
        this->setID(ClassifiedInfoRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ClassifiedInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedInfoRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ClassifiedInfoRequestPacket *ClassifiedInfoRequestPacket_packet = dynamic_cast<const ClassifiedInfoRequestPacket *>(packet);
        if (ClassifiedInfoRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ClassifiedInfoRequestPacket(*ClassifiedInfoRequestPacket_packet);
    }
};

// ClassifiedInfoUpdatePacket
class ClassifiedInfoUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
        SerializableU32 Category;
        SerializableVariable1 Name;
        SerializableVariable2 Desc;
        SerializableUUID ParcelID;
        SerializableU32 ParentEstate;
        SerializableUUID SnapshotID;
        SerializableVector3d PosGlobal;
        SerializableU8 ClassifiedFlags;
        SerializableS32 PriceForListing;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
            Category.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            ParcelID.serialize(buffer);
            ParentEstate.serialize(buffer);
            SnapshotID.serialize(buffer);
            PosGlobal.serialize(buffer);
            ClassifiedFlags.serialize(buffer);
            PriceForListing.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
            Category.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            ParcelID.deserialize(buffer);
            ParentEstate.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            ClassifiedFlags.deserialize(buffer);
            PriceForListing.deserialize(buffer);
        }
    };
    // ClassifiedInfoUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedInfoUpdatePacket() {
        this->setID(ClassifiedInfoUpdate_ID);
    };
    virtual ~ClassifiedInfoUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedInfoUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ClassifiedInfoUpdatePacket *ClassifiedInfoUpdatePacket_packet = dynamic_cast<const ClassifiedInfoUpdatePacket *>(packet);
        if (ClassifiedInfoUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ClassifiedInfoUpdatePacket(*ClassifiedInfoUpdatePacket_packet);
    }
};

// ClassifiedDeletePacket
class ClassifiedDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
        }
    };
    // ClassifiedDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedDeletePacket() {
        this->setID(ClassifiedDelete_ID);
    };
    virtual ~ClassifiedDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedDeletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ClassifiedDeletePacket *ClassifiedDeletePacket_packet = dynamic_cast<const ClassifiedDeletePacket *>(packet);
        if (ClassifiedDeletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ClassifiedDeletePacket(*ClassifiedDeletePacket_packet);
    }
};

// ClassifiedGodDeletePacket
class ClassifiedGodDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
        SerializableUUID QueryID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    // ClassifiedGodDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedGodDeletePacket() {
        this->setID(ClassifiedGodDelete_ID);
    };
    virtual ~ClassifiedGodDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedGodDeletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ClassifiedGodDeletePacket *ClassifiedGodDeletePacket_packet = dynamic_cast<const ClassifiedGodDeletePacket *>(packet);
        if (ClassifiedGodDeletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ClassifiedGodDeletePacket(*ClassifiedGodDeletePacket_packet);
    }
};

// DirLandQueryPacket
class DirLandQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableU32 QueryFlags;
        SerializableU32 SearchType;
        SerializableS32 Price;
        SerializableS32 Area;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryFlags.serialize(buffer);
            SearchType.serialize(buffer);
            Price.serialize(buffer);
            Area.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            SearchType.deserialize(buffer);
            Price.deserialize(buffer);
            Area.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirLandQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirLandQueryPacket() {
        this->setID(DirLandQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirLandQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirLandQueryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DirLandQueryPacket *DirLandQueryPacket_packet = dynamic_cast<const DirLandQueryPacket *>(packet);
        if (DirLandQueryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DirLandQueryPacket(*DirLandQueryPacket_packet);
    }
};

// DirPopularQueryPacket
class DirPopularQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableU32 QueryFlags;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryFlags.deserialize(buffer);
        }
    };
    // DirPopularQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirPopularQueryPacket() {
        this->setID(DirPopularQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPopularQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPopularQueryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DirPopularQueryPacket *DirPopularQueryPacket_packet = dynamic_cast<const DirPopularQueryPacket *>(packet);
        if (DirPopularQueryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DirPopularQueryPacket(*DirPopularQueryPacket_packet);
    }
};

// ParcelInfoRequestPacket
class ParcelInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ParcelID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
        }
    };
    // ParcelInfoRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelInfoRequestPacket() {
        this->setID(ParcelInfoRequest_ID);
    };
    virtual ~ParcelInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelInfoRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelInfoRequestPacket *ParcelInfoRequestPacket_packet = dynamic_cast<const ParcelInfoRequestPacket *>(packet);
        if (ParcelInfoRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelInfoRequestPacket(*ParcelInfoRequestPacket_packet);
    }
};

// ParcelObjectOwnersRequestPacket
class ParcelObjectOwnersRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelObjectOwnersRequestPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelObjectOwnersRequestPacket() {
        this->setID(ParcelObjectOwnersRequest_ID);
    };
    virtual ~ParcelObjectOwnersRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelObjectOwnersRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelObjectOwnersRequestPacket *ParcelObjectOwnersRequestPacket_packet = dynamic_cast<const ParcelObjectOwnersRequestPacket *>(packet);
        if (ParcelObjectOwnersRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelObjectOwnersRequestPacket(*ParcelObjectOwnersRequestPacket_packet);
    }
};

// GroupNoticesListRequestPacket
class GroupNoticesListRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // GroupNoticesListRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    GroupNoticesListRequestPacket() {
        this->setID(GroupNoticesListRequest_ID);
    };
    virtual ~GroupNoticesListRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupNoticesListRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupNoticesListRequestPacket *GroupNoticesListRequestPacket_packet = dynamic_cast<const GroupNoticesListRequestPacket *>(packet);
        if (GroupNoticesListRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupNoticesListRequestPacket(*GroupNoticesListRequestPacket_packet);
    }
};

// GroupNoticeRequestPacket
class GroupNoticeRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupNoticeID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupNoticeID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupNoticeID.deserialize(buffer);
        }
    };
    // GroupNoticeRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    GroupNoticeRequestPacket() {
        this->setID(GroupNoticeRequest_ID);
    };
    virtual ~GroupNoticeRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupNoticeRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupNoticeRequestPacket *GroupNoticeRequestPacket_packet = dynamic_cast<const GroupNoticeRequestPacket *>(packet);
        if (GroupNoticeRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupNoticeRequestPacket(*GroupNoticeRequestPacket_packet);
    }
};

// TeleportRequestPacket
class TeleportRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID RegionID;
        SerializableVector3 Position;
        SerializableVector3 LookAt;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
            Position.serialize(buffer);
            LookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
        }
    };
    // TeleportRequestPacket Member List
    AgentDataBlock AgentData;
    InfoBlock Info;

public:
    TeleportRequestPacket() {
        this->setID(TeleportRequest_ID);
    };
    virtual ~TeleportRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TeleportRequestPacket *TeleportRequestPacket_packet = dynamic_cast<const TeleportRequestPacket *>(packet);
        if (TeleportRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TeleportRequestPacket(*TeleportRequestPacket_packet);
    }
};

// TeleportLocationRequestPacket
class TeleportLocationRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableU64 RegionHandle;
        SerializableVector3 Position;
        SerializableVector3 LookAt;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            Position.serialize(buffer);
            LookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
        }
    };
    // TeleportLocationRequestPacket Member List
    AgentDataBlock AgentData;
    InfoBlock Info;

public:
    TeleportLocationRequestPacket() {
        this->setID(TeleportLocationRequest_ID);
    };
    virtual ~TeleportLocationRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLocationRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TeleportLocationRequestPacket *TeleportLocationRequestPacket_packet = dynamic_cast<const TeleportLocationRequestPacket *>(packet);
        if (TeleportLocationRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TeleportLocationRequestPacket(*TeleportLocationRequestPacket_packet);
    }
};

// TeleportLandmarkRequestPacket
class TeleportLandmarkRequestPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID LandmarkID;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            LandmarkID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            LandmarkID.deserialize(buffer);
        }
    };
    // TeleportLandmarkRequestPacket Member List
    InfoBlock Info;

public:
    TeleportLandmarkRequestPacket() {
        this->setID(TeleportLandmarkRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TeleportLandmarkRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLandmarkRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TeleportLandmarkRequestPacket *TeleportLandmarkRequestPacket_packet = dynamic_cast<const TeleportLandmarkRequestPacket *>(packet);
        if (TeleportLandmarkRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TeleportLandmarkRequestPacket(*TeleportLandmarkRequestPacket_packet);
    }
};

// StartLurePacket
class StartLurePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableU8 LureType;
        SerializableVariable1 Message;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LureType.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LureType.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    class TargetDataBlock : public PacketSerializable {
    public:
        // TargetDataBlock Member List
        SerializableUUID TargetID;
    public:
        TargetDataBlock() {};
        virtual ~TargetDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
        }
    };
    // StartLurePacket Member List
    AgentDataBlock AgentData;
    InfoBlock Info;
    VariableSerializable<TargetDataBlock> TargetData;
    typedef VariableSerializable<TargetDataBlock> TARGETDATABLOCK_LIST_TYPE;

public:
    StartLurePacket() {
        this->setID(StartLure_ID);
    };
    virtual ~StartLurePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Info.serialize(buffer);
        TargetData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Info.deserialize(buffer);
        TargetData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StartLurePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const StartLurePacket *StartLurePacket_packet = dynamic_cast<const StartLurePacket *>(packet);
        if (StartLurePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new StartLurePacket(*StartLurePacket_packet);
    }
};

// TeleportLureRequestPacket
class TeleportLureRequestPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID LureID;
        SerializableU32 TeleportFlags;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            LureID.serialize(buffer);
            TeleportFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            LureID.deserialize(buffer);
            TeleportFlags.deserialize(buffer);
        }
    };
    // TeleportLureRequestPacket Member List
    InfoBlock Info;

public:
    TeleportLureRequestPacket() {
        this->setID(TeleportLureRequest_ID);
    };
    virtual ~TeleportLureRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLureRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TeleportLureRequestPacket *TeleportLureRequestPacket_packet = dynamic_cast<const TeleportLureRequestPacket *>(packet);
        if (TeleportLureRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TeleportLureRequestPacket(*TeleportLureRequestPacket_packet);
    }
};

// TeleportCancelPacket
class TeleportCancelPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // TeleportCancelPacket Member List
    InfoBlock Info;

public:
    TeleportCancelPacket() {
        this->setID(TeleportCancel_ID);
    };
    virtual ~TeleportCancelPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportCancelPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TeleportCancelPacket *TeleportCancelPacket_packet = dynamic_cast<const TeleportCancelPacket *>(packet);
        if (TeleportCancelPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TeleportCancelPacket(*TeleportCancelPacket_packet);
    }
};

// UndoPacket
class UndoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // UndoPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    UndoPacket() {
        this->setID(Undo_ID);
    };
    virtual ~UndoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UndoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UndoPacket *UndoPacket_packet = dynamic_cast<const UndoPacket *>(packet);
        if (UndoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UndoPacket(*UndoPacket_packet);
    }
};

// RedoPacket
class RedoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // RedoPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    RedoPacket() {
        this->setID(Redo_ID);
    };
    virtual ~RedoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RedoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RedoPacket *RedoPacket_packet = dynamic_cast<const RedoPacket *>(packet);
        if (RedoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RedoPacket(*RedoPacket_packet);
    }
};

// UndoLandPacket
class UndoLandPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // UndoLandPacket Member List
    AgentDataBlock AgentData;

public:
    UndoLandPacket() {
        this->setID(UndoLand_ID);
    };
    virtual ~UndoLandPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UndoLandPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UndoLandPacket *UndoLandPacket_packet = dynamic_cast<const UndoLandPacket *>(packet);
        if (UndoLandPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UndoLandPacket(*UndoLandPacket_packet);
    }
};

// AgentPausePacket
class AgentPausePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    // AgentPausePacket Member List
    AgentDataBlock AgentData;

public:
    AgentPausePacket() {
        this->setID(AgentPause_ID);
    };
    virtual ~AgentPausePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentPausePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentPausePacket *AgentPausePacket_packet = dynamic_cast<const AgentPausePacket *>(packet);
        if (AgentPausePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentPausePacket(*AgentPausePacket_packet);
    }
};

// AgentResumePacket
class AgentResumePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    // AgentResumePacket Member List
    AgentDataBlock AgentData;

public:
    AgentResumePacket() {
        this->setID(AgentResume_ID);
    };
    virtual ~AgentResumePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentResumePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentResumePacket *AgentResumePacket_packet = dynamic_cast<const AgentResumePacket *>(packet);
        if (AgentResumePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentResumePacket(*AgentResumePacket_packet);
    }
};

// AgentUpdatePacket
class AgentUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableQuaternion BodyRotation;
        SerializableQuaternion HeadRotation;
        SerializableU8 State;
        SerializableVector3 CameraCenter;
        SerializableVector3 CameraAtAxis;
        SerializableVector3 CameraLeftAxis;
        SerializableVector3 CameraUpAxis;
        SerializableF32 Far;
        SerializableU32 ControlFlags;
        SerializableU8 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            BodyRotation.serialize(buffer);
            HeadRotation.serialize(buffer);
            State.serialize(buffer);
            CameraCenter.serialize(buffer);
            CameraAtAxis.serialize(buffer);
            CameraLeftAxis.serialize(buffer);
            CameraUpAxis.serialize(buffer);
            Far.serialize(buffer);
            ControlFlags.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            BodyRotation.deserialize(buffer);
            HeadRotation.deserialize(buffer);
            State.deserialize(buffer);
            CameraCenter.deserialize(buffer);
            CameraAtAxis.deserialize(buffer);
            CameraLeftAxis.deserialize(buffer);
            CameraUpAxis.deserialize(buffer);
            Far.deserialize(buffer);
            ControlFlags.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // AgentUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    AgentUpdatePacket() {
        this->setID(AgentUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentUpdatePacket *AgentUpdatePacket_packet = dynamic_cast<const AgentUpdatePacket *>(packet);
        if (AgentUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentUpdatePacket(*AgentUpdatePacket_packet);
    }
};

// ChatFromViewerPacket
class ChatFromViewerPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ChatDataBlock : public PacketSerializable {
    public:
        // ChatDataBlock Member List
        SerializableVariable2 Message;
        SerializableU8 Type;
        SerializableS32 Channel;
    public:
        ChatDataBlock() {};
        virtual ~ChatDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Message.serialize(buffer);
            Type.serialize(buffer);
            Channel.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Message.deserialize(buffer);
            Type.deserialize(buffer);
            Channel.deserialize(buffer);
        }
    };
    // ChatFromViewerPacket Member List
    AgentDataBlock AgentData;
    ChatDataBlock ChatData;

public:
    ChatFromViewerPacket() {
        this->setID(ChatFromViewer_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ChatFromViewerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ChatData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ChatData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChatFromViewerPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ChatFromViewerPacket *ChatFromViewerPacket_packet = dynamic_cast<const ChatFromViewerPacket *>(packet);
        if (ChatFromViewerPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ChatFromViewerPacket(*ChatFromViewerPacket_packet);
    }
};

// AgentThrottlePacket
class AgentThrottlePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    class ThrottleBlock : public PacketSerializable {
    public:
        // ThrottleBlock Member List
        SerializableU32 GenCounter;
        SerializableVariable1 Throttles;
    public:
        ThrottleBlock() {};
        virtual ~ThrottleBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GenCounter.serialize(buffer);
            Throttles.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GenCounter.deserialize(buffer);
            Throttles.deserialize(buffer);
        }
    };
    // AgentThrottlePacket Member List
    AgentDataBlock AgentData;
    ThrottleBlock Throttle;

public:
    AgentThrottlePacket() {
        this->setID(AgentThrottle_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentThrottlePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Throttle.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Throttle.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentThrottlePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentThrottlePacket *AgentThrottlePacket_packet = dynamic_cast<const AgentThrottlePacket *>(packet);
        if (AgentThrottlePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentThrottlePacket(*AgentThrottlePacket_packet);
    }
};

// AgentFOVPacket
class AgentFOVPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    class FOVBlockBlock : public PacketSerializable {
    public:
        // FOVBlockBlock Member List
        SerializableU32 GenCounter;
        SerializableF32 VerticalAngle;
    public:
        FOVBlockBlock() {};
        virtual ~FOVBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GenCounter.serialize(buffer);
            VerticalAngle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GenCounter.deserialize(buffer);
            VerticalAngle.deserialize(buffer);
        }
    };
    // AgentFOVPacket Member List
    AgentDataBlock AgentData;
    FOVBlockBlock FOVBlock;

public:
    AgentFOVPacket() {
        this->setID(AgentFOV_ID);
    };
    virtual ~AgentFOVPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FOVBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FOVBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentFOVPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentFOVPacket *AgentFOVPacket_packet = dynamic_cast<const AgentFOVPacket *>(packet);
        if (AgentFOVPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentFOVPacket(*AgentFOVPacket_packet);
    }
};

// AgentHeightWidthPacket
class AgentHeightWidthPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    class HeightWidthBlockBlock : public PacketSerializable {
    public:
        // HeightWidthBlockBlock Member List
        SerializableU32 GenCounter;
        SerializableU16 Height;
        SerializableU16 Width;
    public:
        HeightWidthBlockBlock() {};
        virtual ~HeightWidthBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GenCounter.serialize(buffer);
            Height.serialize(buffer);
            Width.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GenCounter.deserialize(buffer);
            Height.deserialize(buffer);
            Width.deserialize(buffer);
        }
    };
    // AgentHeightWidthPacket Member List
    AgentDataBlock AgentData;
    HeightWidthBlockBlock HeightWidthBlock;

public:
    AgentHeightWidthPacket() {
        this->setID(AgentHeightWidth_ID);
    };
    virtual ~AgentHeightWidthPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeightWidthBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeightWidthBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentHeightWidthPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentHeightWidthPacket *AgentHeightWidthPacket_packet = dynamic_cast<const AgentHeightWidthPacket *>(packet);
        if (AgentHeightWidthPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentHeightWidthPacket(*AgentHeightWidthPacket_packet);
    }
};

// AgentSetAppearancePacket
class AgentSetAppearancePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 SerialNum;
        SerializableVector3 Size;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
            Size.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
            Size.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID CacheID;
        SerializableU8 TextureIndex;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CacheID.serialize(buffer);
            TextureIndex.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CacheID.deserialize(buffer);
            TextureIndex.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableVariable2 TextureEntry;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TextureEntry.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TextureEntry.deserialize(buffer);
        }
    };
    class VisualParamBlock : public PacketSerializable {
    public:
        // VisualParamBlock Member List
        SerializableU8 ParamValue;
    public:
        VisualParamBlock() {};
        virtual ~VisualParamBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParamValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParamValue.deserialize(buffer);
        }
    };
    // AgentSetAppearancePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;
    typedef VariableSerializable<WearableDataBlock> WEARABLEDATABLOCK_LIST_TYPE;
    ObjectDataBlock ObjectData;
    VariableSerializable<VisualParamBlock> VisualParam;
    typedef VariableSerializable<VisualParamBlock> VISUALPARAMBLOCK_LIST_TYPE;

public:
    AgentSetAppearancePacket() {
        this->setID(AgentSetAppearance_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentSetAppearancePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
        ObjectData.serialize(buffer);
        VisualParam.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        VisualParam.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentSetAppearancePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentSetAppearancePacket *AgentSetAppearancePacket_packet = dynamic_cast<const AgentSetAppearancePacket *>(packet);
        if (AgentSetAppearancePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentSetAppearancePacket(*AgentSetAppearancePacket_packet);
    }
};

// AgentAnimationPacket
class AgentAnimationPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AnimationListBlock : public PacketSerializable {
    public:
        // AnimationListBlock Member List
        SerializableUUID AnimID;
        SerializableBool StartAnim;
    public:
        AnimationListBlock() {};
        virtual ~AnimationListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AnimID.serialize(buffer);
            StartAnim.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AnimID.deserialize(buffer);
            StartAnim.deserialize(buffer);
        }
    };
    class PhysicalAvatarEventListBlock : public PacketSerializable {
    public:
        // PhysicalAvatarEventListBlock Member List
        SerializableVariable1 TypeData;
    public:
        PhysicalAvatarEventListBlock() {};
        virtual ~PhysicalAvatarEventListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TypeData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TypeData.deserialize(buffer);
        }
    };
    // AgentAnimationPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<AnimationListBlock> AnimationList;
    typedef VariableSerializable<AnimationListBlock> ANIMATIONLISTBLOCK_LIST_TYPE;
    VariableSerializable<PhysicalAvatarEventListBlock> PhysicalAvatarEventList;
    typedef VariableSerializable<PhysicalAvatarEventListBlock> PHYSICALAVATAREVENTLISTBLOCK_LIST_TYPE;

public:
    AgentAnimationPacket() {
        this->setID(AgentAnimation_ID);
    };
    virtual ~AgentAnimationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AnimationList.serialize(buffer);
        PhysicalAvatarEventList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AnimationList.deserialize(buffer);
        PhysicalAvatarEventList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentAnimationPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentAnimationPacket *AgentAnimationPacket_packet = dynamic_cast<const AgentAnimationPacket *>(packet);
        if (AgentAnimationPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentAnimationPacket(*AgentAnimationPacket_packet);
    }
};

// AgentRequestSitPacket
class AgentRequestSitPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TargetObjectBlock : public PacketSerializable {
    public:
        // TargetObjectBlock Member List
        SerializableUUID TargetID;
        SerializableVector3 Offset;
    public:
        TargetObjectBlock() {};
        virtual ~TargetObjectBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Offset.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Offset.deserialize(buffer);
        }
    };
    // AgentRequestSitPacket Member List
    AgentDataBlock AgentData;
    TargetObjectBlock TargetObject;

public:
    AgentRequestSitPacket() {
        this->setID(AgentRequestSit_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentRequestSitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TargetObject.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TargetObject.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentRequestSitPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentRequestSitPacket *AgentRequestSitPacket_packet = dynamic_cast<const AgentRequestSitPacket *>(packet);
        if (AgentRequestSitPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentRequestSitPacket(*AgentRequestSitPacket_packet);
    }
};

// AgentSitPacket
class AgentSitPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // AgentSitPacket Member List
    AgentDataBlock AgentData;

public:
    AgentSitPacket() {
        this->setID(AgentSit_ID);
    };
    virtual ~AgentSitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentSitPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentSitPacket *AgentSitPacket_packet = dynamic_cast<const AgentSitPacket *>(packet);
        if (AgentSitPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentSitPacket(*AgentSitPacket_packet);
    }
};

// AgentQuitCopyPacket
class AgentQuitCopyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FuseBlockBlock : public PacketSerializable {
    public:
        // FuseBlockBlock Member List
        SerializableU32 ViewerCircuitCode;
    public:
        FuseBlockBlock() {};
        virtual ~FuseBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ViewerCircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ViewerCircuitCode.deserialize(buffer);
        }
    };
    // AgentQuitCopyPacket Member List
    AgentDataBlock AgentData;
    FuseBlockBlock FuseBlock;

public:
    AgentQuitCopyPacket() {
        this->setID(AgentQuitCopy_ID);
    };
    virtual ~AgentQuitCopyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FuseBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FuseBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentQuitCopyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentQuitCopyPacket *AgentQuitCopyPacket_packet = dynamic_cast<const AgentQuitCopyPacket *>(packet);
        if (AgentQuitCopyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentQuitCopyPacket(*AgentQuitCopyPacket_packet);
    }
};

// RequestImagePacket
class RequestImagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RequestImageBlock : public PacketSerializable {
    public:
        // RequestImageBlock Member List
        SerializableUUID Image;
        SerializableS8 DiscardLevel;
        SerializableF32 DownloadPriority;
        SerializableU32 Packet;
        SerializableU8 Type;
    public:
        RequestImageBlock() {};
        virtual ~RequestImageBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Image.serialize(buffer);
            DiscardLevel.serialize(buffer);
            DownloadPriority.serialize(buffer);
            Packet.serialize(buffer);
            Type.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Image.deserialize(buffer);
            DiscardLevel.deserialize(buffer);
            DownloadPriority.deserialize(buffer);
            Packet.deserialize(buffer);
            Type.deserialize(buffer);
        }
    };
    // RequestImagePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RequestImageBlock> RequestImage;
    typedef VariableSerializable<RequestImageBlock> REQUESTIMAGEBLOCK_LIST_TYPE;

public:
    RequestImagePacket() {
        this->setID(RequestImage_ID);
    };
    virtual ~RequestImagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestImage.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestImage.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestImagePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestImagePacket *RequestImagePacket_packet = dynamic_cast<const RequestImagePacket *>(packet);
        if (RequestImagePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestImagePacket(*RequestImagePacket_packet);
    }
};

// SetAlwaysRunPacket
class SetAlwaysRunPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool AlwaysRun;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AlwaysRun.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AlwaysRun.deserialize(buffer);
        }
    };
    // SetAlwaysRunPacket Member List
    AgentDataBlock AgentData;

public:
    SetAlwaysRunPacket() {
        this->setID(SetAlwaysRun_ID);
    };
    virtual ~SetAlwaysRunPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetAlwaysRunPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SetAlwaysRunPacket *SetAlwaysRunPacket_packet = dynamic_cast<const SetAlwaysRunPacket *>(packet);
        if (SetAlwaysRunPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SetAlwaysRunPacket(*SetAlwaysRunPacket_packet);
    }
};

// ObjectAddPacket
class ObjectAddPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU8 PCode;
        SerializableU8 Material;
        SerializableU32 AddFlags;
        SerializableU8 PathCurve;
        SerializableU8 ProfileCurve;
        SerializableU16 PathBegin;
        SerializableU16 PathEnd;
        SerializableU8 PathScaleX;
        SerializableU8 PathScaleY;
        SerializableU8 PathShearX;
        SerializableU8 PathShearY;
        SerializableS8 PathTwist;
        SerializableS8 PathTwistBegin;
        SerializableS8 PathRadiusOffset;
        SerializableS8 PathTaperX;
        SerializableS8 PathTaperY;
        SerializableU8 PathRevolutions;
        SerializableS8 PathSkew;
        SerializableU16 ProfileBegin;
        SerializableU16 ProfileEnd;
        SerializableU16 ProfileHollow;
        SerializableU8 BypassRaycast;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableUUID RayTargetID;
        SerializableU8 RayEndIsIntersection;
        SerializableVector3 Scale;
        SerializableQuaternion Rotation;
        SerializableU8 State;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PCode.serialize(buffer);
            Material.serialize(buffer);
            AddFlags.serialize(buffer);
            PathCurve.serialize(buffer);
            ProfileCurve.serialize(buffer);
            PathBegin.serialize(buffer);
            PathEnd.serialize(buffer);
            PathScaleX.serialize(buffer);
            PathScaleY.serialize(buffer);
            PathShearX.serialize(buffer);
            PathShearY.serialize(buffer);
            PathTwist.serialize(buffer);
            PathTwistBegin.serialize(buffer);
            PathRadiusOffset.serialize(buffer);
            PathTaperX.serialize(buffer);
            PathTaperY.serialize(buffer);
            PathRevolutions.serialize(buffer);
            PathSkew.serialize(buffer);
            ProfileBegin.serialize(buffer);
            ProfileEnd.serialize(buffer);
            ProfileHollow.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            RayTargetID.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            Scale.serialize(buffer);
            Rotation.serialize(buffer);
            State.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PCode.deserialize(buffer);
            Material.deserialize(buffer);
            AddFlags.deserialize(buffer);
            PathCurve.deserialize(buffer);
            ProfileCurve.deserialize(buffer);
            PathBegin.deserialize(buffer);
            PathEnd.deserialize(buffer);
            PathScaleX.deserialize(buffer);
            PathScaleY.deserialize(buffer);
            PathShearX.deserialize(buffer);
            PathShearY.deserialize(buffer);
            PathTwist.deserialize(buffer);
            PathTwistBegin.deserialize(buffer);
            PathRadiusOffset.deserialize(buffer);
            PathTaperX.deserialize(buffer);
            PathTaperY.deserialize(buffer);
            PathRevolutions.deserialize(buffer);
            PathSkew.deserialize(buffer);
            ProfileBegin.deserialize(buffer);
            ProfileEnd.deserialize(buffer);
            ProfileHollow.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            Scale.deserialize(buffer);
            Rotation.deserialize(buffer);
            State.deserialize(buffer);
        }
    };
    // ObjectAddPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectAddPacket() {
        this->setID(ObjectAdd_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectAddPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectAddPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectAddPacket *ObjectAddPacket_packet = dynamic_cast<const ObjectAddPacket *>(packet);
        if (ObjectAddPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectAddPacket(*ObjectAddPacket_packet);
    }
};

// ObjectDeletePacket
class ObjectDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool Force;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Force.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Force.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDeletePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDeletePacket() {
        this->setID(ObjectDelete_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDeletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDeletePacket *ObjectDeletePacket_packet = dynamic_cast<const ObjectDeletePacket *>(packet);
        if (ObjectDeletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDeletePacket(*ObjectDeletePacket_packet);
    }
};

// ObjectDuplicatePacket
class ObjectDuplicatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class SharedDataBlock : public PacketSerializable {
    public:
        // SharedDataBlock Member List
        SerializableVector3 Offset;
        SerializableU32 DuplicateFlags;
    public:
        SharedDataBlock() {};
        virtual ~SharedDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Offset.serialize(buffer);
            DuplicateFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Offset.deserialize(buffer);
            DuplicateFlags.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDuplicatePacket Member List
    AgentDataBlock AgentData;
    SharedDataBlock SharedData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDuplicatePacket() {
        this->setID(ObjectDuplicate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDuplicatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        SharedData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        SharedData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDuplicatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDuplicatePacket *ObjectDuplicatePacket_packet = dynamic_cast<const ObjectDuplicatePacket *>(packet);
        if (ObjectDuplicatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDuplicatePacket(*ObjectDuplicatePacket_packet);
    }
};

// ObjectDuplicateOnRayPacket
class ObjectDuplicateOnRayPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableBool BypassRaycast;
        SerializableBool RayEndIsIntersection;
        SerializableBool CopyCenters;
        SerializableBool CopyRotates;
        SerializableUUID RayTargetID;
        SerializableU32 DuplicateFlags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            CopyCenters.serialize(buffer);
            CopyRotates.serialize(buffer);
            RayTargetID.serialize(buffer);
            DuplicateFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            CopyCenters.deserialize(buffer);
            CopyRotates.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            DuplicateFlags.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDuplicateOnRayPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDuplicateOnRayPacket() {
        this->setID(ObjectDuplicateOnRay_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDuplicateOnRayPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDuplicateOnRayPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDuplicateOnRayPacket *ObjectDuplicateOnRayPacket_packet = dynamic_cast<const ObjectDuplicateOnRayPacket *>(packet);
        if (ObjectDuplicateOnRayPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDuplicateOnRayPacket(*ObjectDuplicateOnRayPacket_packet);
    }
};

// MultipleObjectUpdatePacket
class MultipleObjectUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 Type;
        SerializableVariable1 Data;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Type.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Type.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // MultipleObjectUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    MultipleObjectUpdatePacket() {
        this->setID(MultipleObjectUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MultipleObjectUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MultipleObjectUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MultipleObjectUpdatePacket *MultipleObjectUpdatePacket_packet = dynamic_cast<const MultipleObjectUpdatePacket *>(packet);
        if (MultipleObjectUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MultipleObjectUpdatePacket(*MultipleObjectUpdatePacket_packet);
    }
};

// RequestMultipleObjectsPacket
class RequestMultipleObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU8 CacheMissType;
        SerializableU32 ID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CacheMissType.serialize(buffer);
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CacheMissType.deserialize(buffer);
            ID.deserialize(buffer);
        }
    };
    // RequestMultipleObjectsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    RequestMultipleObjectsPacket() {
        this->setID(RequestMultipleObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RequestMultipleObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestMultipleObjectsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestMultipleObjectsPacket *RequestMultipleObjectsPacket_packet = dynamic_cast<const RequestMultipleObjectsPacket *>(packet);
        if (RequestMultipleObjectsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestMultipleObjectsPacket(*RequestMultipleObjectsPacket_packet);
    }
};

// ObjectPositionPacket
class ObjectPositionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableVector3 Position;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Position.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Position.deserialize(buffer);
        }
    };
    // ObjectPositionPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectPositionPacket() {
        this->setID(ObjectPosition_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectPositionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectPositionPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectPositionPacket *ObjectPositionPacket_packet = dynamic_cast<const ObjectPositionPacket *>(packet);
        if (ObjectPositionPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectPositionPacket(*ObjectPositionPacket_packet);
    }
};

// ObjectScalePacket
class ObjectScalePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableVector3 Scale;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Scale.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Scale.deserialize(buffer);
        }
    };
    // ObjectScalePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectScalePacket() {
        this->setID(ObjectScale_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectScalePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectScalePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectScalePacket *ObjectScalePacket_packet = dynamic_cast<const ObjectScalePacket *>(packet);
        if (ObjectScalePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectScalePacket(*ObjectScalePacket_packet);
    }
};

// ObjectRotationPacket
class ObjectRotationPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableQuaternion Rotation;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Rotation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Rotation.deserialize(buffer);
        }
    };
    // ObjectRotationPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectRotationPacket() {
        this->setID(ObjectRotation_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectRotationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectRotationPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectRotationPacket *ObjectRotationPacket_packet = dynamic_cast<const ObjectRotationPacket *>(packet);
        if (ObjectRotationPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectRotationPacket(*ObjectRotationPacket_packet);
    }
};

// ObjectFlagUpdatePacket
class ObjectFlagUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 ObjectLocalID;
        SerializableBool UsePhysics;
        SerializableBool IsTemporary;
        SerializableBool IsPhantom;
        SerializableBool CastsShadows;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            ObjectLocalID.serialize(buffer);
            UsePhysics.serialize(buffer);
            IsTemporary.serialize(buffer);
            IsPhantom.serialize(buffer);
            CastsShadows.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            ObjectLocalID.deserialize(buffer);
            UsePhysics.deserialize(buffer);
            IsTemporary.deserialize(buffer);
            IsPhantom.deserialize(buffer);
            CastsShadows.deserialize(buffer);
        }
    };
    // ObjectFlagUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    ObjectFlagUpdatePacket() {
        this->setID(ObjectFlagUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectFlagUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectFlagUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectFlagUpdatePacket *ObjectFlagUpdatePacket_packet = dynamic_cast<const ObjectFlagUpdatePacket *>(packet);
        if (ObjectFlagUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectFlagUpdatePacket(*ObjectFlagUpdatePacket_packet);
    }
};

// ObjectClickActionPacket
class ObjectClickActionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 ClickAction;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            ClickAction.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            ClickAction.deserialize(buffer);
        }
    };
    // ObjectClickActionPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectClickActionPacket() {
        this->setID(ObjectClickAction_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectClickActionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectClickActionPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectClickActionPacket *ObjectClickActionPacket_packet = dynamic_cast<const ObjectClickActionPacket *>(packet);
        if (ObjectClickActionPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectClickActionPacket(*ObjectClickActionPacket_packet);
    }
};

// ObjectImagePacket
class ObjectImagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableVariable1 MediaURL;
        SerializableVariable2 TextureEntry;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            MediaURL.serialize(buffer);
            TextureEntry.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            MediaURL.deserialize(buffer);
            TextureEntry.deserialize(buffer);
        }
    };
    // ObjectImagePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectImagePacket() {
        this->setID(ObjectImage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectImagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectImagePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectImagePacket *ObjectImagePacket_packet = dynamic_cast<const ObjectImagePacket *>(packet);
        if (ObjectImagePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectImagePacket(*ObjectImagePacket_packet);
    }
};

// ObjectMaterialPacket
class ObjectMaterialPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 Material;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Material.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Material.deserialize(buffer);
        }
    };
    // ObjectMaterialPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectMaterialPacket() {
        this->setID(ObjectMaterial_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectMaterialPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectMaterialPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectMaterialPacket *ObjectMaterialPacket_packet = dynamic_cast<const ObjectMaterialPacket *>(packet);
        if (ObjectMaterialPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectMaterialPacket(*ObjectMaterialPacket_packet);
    }
};

// ObjectShapePacket
class ObjectShapePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 PathCurve;
        SerializableU8 ProfileCurve;
        SerializableU16 PathBegin;
        SerializableU16 PathEnd;
        SerializableU8 PathScaleX;
        SerializableU8 PathScaleY;
        SerializableU8 PathShearX;
        SerializableU8 PathShearY;
        SerializableS8 PathTwist;
        SerializableS8 PathTwistBegin;
        SerializableS8 PathRadiusOffset;
        SerializableS8 PathTaperX;
        SerializableS8 PathTaperY;
        SerializableU8 PathRevolutions;
        SerializableS8 PathSkew;
        SerializableU16 ProfileBegin;
        SerializableU16 ProfileEnd;
        SerializableU16 ProfileHollow;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            PathCurve.serialize(buffer);
            ProfileCurve.serialize(buffer);
            PathBegin.serialize(buffer);
            PathEnd.serialize(buffer);
            PathScaleX.serialize(buffer);
            PathScaleY.serialize(buffer);
            PathShearX.serialize(buffer);
            PathShearY.serialize(buffer);
            PathTwist.serialize(buffer);
            PathTwistBegin.serialize(buffer);
            PathRadiusOffset.serialize(buffer);
            PathTaperX.serialize(buffer);
            PathTaperY.serialize(buffer);
            PathRevolutions.serialize(buffer);
            PathSkew.serialize(buffer);
            ProfileBegin.serialize(buffer);
            ProfileEnd.serialize(buffer);
            ProfileHollow.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            PathCurve.deserialize(buffer);
            ProfileCurve.deserialize(buffer);
            PathBegin.deserialize(buffer);
            PathEnd.deserialize(buffer);
            PathScaleX.deserialize(buffer);
            PathScaleY.deserialize(buffer);
            PathShearX.deserialize(buffer);
            PathShearY.deserialize(buffer);
            PathTwist.deserialize(buffer);
            PathTwistBegin.deserialize(buffer);
            PathRadiusOffset.deserialize(buffer);
            PathTaperX.deserialize(buffer);
            PathTaperY.deserialize(buffer);
            PathRevolutions.deserialize(buffer);
            PathSkew.deserialize(buffer);
            ProfileBegin.deserialize(buffer);
            ProfileEnd.deserialize(buffer);
            ProfileHollow.deserialize(buffer);
        }
    };
    // ObjectShapePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectShapePacket() {
        this->setID(ObjectShape_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectShapePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectShapePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectShapePacket *ObjectShapePacket_packet = dynamic_cast<const ObjectShapePacket *>(packet);
        if (ObjectShapePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectShapePacket(*ObjectShapePacket_packet);
    }
};

// ObjectExtraParamsPacket
class ObjectExtraParamsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU16 ParamType;
        SerializableBool ParamInUse;
        SerializableU32 ParamSize;
        SerializableVariable1 ParamData;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            ParamType.serialize(buffer);
            ParamInUse.serialize(buffer);
            ParamSize.serialize(buffer);
            ParamData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            ParamType.deserialize(buffer);
            ParamInUse.deserialize(buffer);
            ParamSize.deserialize(buffer);
            ParamData.deserialize(buffer);
        }
    };
    // ObjectExtraParamsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectExtraParamsPacket() {
        this->setID(ObjectExtraParams_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectExtraParamsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectExtraParamsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectExtraParamsPacket *ObjectExtraParamsPacket_packet = dynamic_cast<const ObjectExtraParamsPacket *>(packet);
        if (ObjectExtraParamsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectExtraParamsPacket(*ObjectExtraParamsPacket_packet);
    }
};

// ObjectOwnerPacket
class ObjectOwnerPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableBool Override;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Override.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Override.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectOwnerPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectOwnerPacket() {
        this->setID(ObjectOwner_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectOwnerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectOwnerPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectOwnerPacket *ObjectOwnerPacket_packet = dynamic_cast<const ObjectOwnerPacket *>(packet);
        if (ObjectOwnerPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectOwnerPacket(*ObjectOwnerPacket_packet);
    }
};

// ObjectGroupPacket
class ObjectGroupPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectGroupPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectGroupPacket() {
        this->setID(ObjectGroup_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectGroupPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectGroupPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectGroupPacket *ObjectGroupPacket_packet = dynamic_cast<const ObjectGroupPacket *>(packet);
        if (ObjectGroupPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectGroupPacket(*ObjectGroupPacket_packet);
    }
};

// ObjectBuyPacket
class ObjectBuyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableUUID CategoryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            CategoryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            CategoryID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
        }
    };
    // ObjectBuyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectBuyPacket() {
        this->setID(ObjectBuy_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectBuyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectBuyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectBuyPacket *ObjectBuyPacket_packet = dynamic_cast<const ObjectBuyPacket *>(packet);
        if (ObjectBuyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectBuyPacket(*ObjectBuyPacket_packet);
    }
};

// BuyObjectInventoryPacket
class BuyObjectInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
        SerializableUUID FolderID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
        }
    };
    // BuyObjectInventoryPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    BuyObjectInventoryPacket() {
        this->setID(BuyObjectInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~BuyObjectInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new BuyObjectInventoryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const BuyObjectInventoryPacket *BuyObjectInventoryPacket_packet = dynamic_cast<const BuyObjectInventoryPacket *>(packet);
        if (BuyObjectInventoryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new BuyObjectInventoryPacket(*BuyObjectInventoryPacket_packet);
    }
};

// ObjectPermissionsPacket
class ObjectPermissionsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableBool Override;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Override.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Override.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 Field;
        SerializableU8 Set;
        SerializableU32 Mask;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Field.serialize(buffer);
            Set.serialize(buffer);
            Mask.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Field.deserialize(buffer);
            Set.deserialize(buffer);
            Mask.deserialize(buffer);
        }
    };
    // ObjectPermissionsPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectPermissionsPacket() {
        this->setID(ObjectPermissions_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectPermissionsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectPermissionsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectPermissionsPacket *ObjectPermissionsPacket_packet = dynamic_cast<const ObjectPermissionsPacket *>(packet);
        if (ObjectPermissionsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectPermissionsPacket(*ObjectPermissionsPacket_packet);
    }
};

// ObjectSaleInfoPacket
class ObjectSaleInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
        }
    };
    // ObjectSaleInfoPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectSaleInfoPacket() {
        this->setID(ObjectSaleInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSaleInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSaleInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectSaleInfoPacket *ObjectSaleInfoPacket_packet = dynamic_cast<const ObjectSaleInfoPacket *>(packet);
        if (ObjectSaleInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectSaleInfoPacket(*ObjectSaleInfoPacket_packet);
    }
};

// ObjectNamePacket
class ObjectNamePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableVariable1 Name;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // ObjectNamePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectNamePacket() {
        this->setID(ObjectName_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectNamePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectNamePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectNamePacket *ObjectNamePacket_packet = dynamic_cast<const ObjectNamePacket *>(packet);
        if (ObjectNamePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectNamePacket(*ObjectNamePacket_packet);
    }
};

// ObjectDescriptionPacket
class ObjectDescriptionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableVariable1 Description;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // ObjectDescriptionPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDescriptionPacket() {
        this->setID(ObjectDescription_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDescriptionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDescriptionPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDescriptionPacket *ObjectDescriptionPacket_packet = dynamic_cast<const ObjectDescriptionPacket *>(packet);
        if (ObjectDescriptionPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDescriptionPacket(*ObjectDescriptionPacket_packet);
    }
};

// ObjectCategoryPacket
class ObjectCategoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableU32 Category;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Category.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Category.deserialize(buffer);
        }
    };
    // ObjectCategoryPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectCategoryPacket() {
        this->setID(ObjectCategory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectCategoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectCategoryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectCategoryPacket *ObjectCategoryPacket_packet = dynamic_cast<const ObjectCategoryPacket *>(packet);
        if (ObjectCategoryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectCategoryPacket(*ObjectCategoryPacket_packet);
    }
};

// ObjectSelectPacket
class ObjectSelectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectSelectPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectSelectPacket() {
        this->setID(ObjectSelect_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSelectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSelectPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectSelectPacket *ObjectSelectPacket_packet = dynamic_cast<const ObjectSelectPacket *>(packet);
        if (ObjectSelectPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectSelectPacket(*ObjectSelectPacket_packet);
    }
};

// ObjectDeselectPacket
class ObjectDeselectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDeselectPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDeselectPacket() {
        this->setID(ObjectDeselect_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDeselectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDeselectPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDeselectPacket *ObjectDeselectPacket_packet = dynamic_cast<const ObjectDeselectPacket *>(packet);
        if (ObjectDeselectPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDeselectPacket(*ObjectDeselectPacket_packet);
    }
};

// ObjectAttachPacket
class ObjectAttachPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU8 AttachmentPoint;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AttachmentPoint.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AttachmentPoint.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableQuaternion Rotation;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Rotation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Rotation.deserialize(buffer);
        }
    };
    // ObjectAttachPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectAttachPacket() {
        this->setID(ObjectAttach_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectAttachPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectAttachPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectAttachPacket *ObjectAttachPacket_packet = dynamic_cast<const ObjectAttachPacket *>(packet);
        if (ObjectAttachPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectAttachPacket(*ObjectAttachPacket_packet);
    }
};

// ObjectDetachPacket
class ObjectDetachPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDetachPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDetachPacket() {
        this->setID(ObjectDetach_ID);
    };
    virtual ~ObjectDetachPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDetachPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDetachPacket *ObjectDetachPacket_packet = dynamic_cast<const ObjectDetachPacket *>(packet);
        if (ObjectDetachPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDetachPacket(*ObjectDetachPacket_packet);
    }
};

// ObjectDropPacket
class ObjectDropPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDropPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDropPacket() {
        this->setID(ObjectDrop_ID);
    };
    virtual ~ObjectDropPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDropPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDropPacket *ObjectDropPacket_packet = dynamic_cast<const ObjectDropPacket *>(packet);
        if (ObjectDropPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDropPacket(*ObjectDropPacket_packet);
    }
};

// ObjectLinkPacket
class ObjectLinkPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectLinkPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectLinkPacket() {
        this->setID(ObjectLink_ID);
    };
    virtual ~ObjectLinkPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectLinkPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectLinkPacket *ObjectLinkPacket_packet = dynamic_cast<const ObjectLinkPacket *>(packet);
        if (ObjectLinkPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectLinkPacket(*ObjectLinkPacket_packet);
    }
};

// ObjectDelinkPacket
class ObjectDelinkPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDelinkPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectDelinkPacket() {
        this->setID(ObjectDelink_ID);
    };
    virtual ~ObjectDelinkPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDelinkPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDelinkPacket *ObjectDelinkPacket_packet = dynamic_cast<const ObjectDelinkPacket *>(packet);
        if (ObjectDelinkPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDelinkPacket(*ObjectDelinkPacket_packet);
    }
};

// ObjectGrabPacket
class ObjectGrabPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableVector3 GrabOffset;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            GrabOffset.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            GrabOffset.deserialize(buffer);
        }
    };
    class SurfaceInfoBlock : public PacketSerializable {
    public:
        // SurfaceInfoBlock Member List
        SerializableVector3 UVCoord;
        SerializableVector3 STCoord;
        SerializableS32 FaceIndex;
        SerializableVector3 Position;
        SerializableVector3 Normal;
        SerializableVector3 Binormal;
    public:
        SurfaceInfoBlock() {};
        virtual ~SurfaceInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UVCoord.serialize(buffer);
            STCoord.serialize(buffer);
            FaceIndex.serialize(buffer);
            Position.serialize(buffer);
            Normal.serialize(buffer);
            Binormal.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UVCoord.deserialize(buffer);
            STCoord.deserialize(buffer);
            FaceIndex.deserialize(buffer);
            Position.deserialize(buffer);
            Normal.deserialize(buffer);
            Binormal.deserialize(buffer);
        }
    };
    // ObjectGrabPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    VariableSerializable<SurfaceInfoBlock> SurfaceInfo;
    typedef VariableSerializable<SurfaceInfoBlock> SURFACEINFOBLOCK_LIST_TYPE;

public:
    ObjectGrabPacket() {
        this->setID(ObjectGrab_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectGrabPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
        SurfaceInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        SurfaceInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectGrabPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectGrabPacket *ObjectGrabPacket_packet = dynamic_cast<const ObjectGrabPacket *>(packet);
        if (ObjectGrabPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectGrabPacket(*ObjectGrabPacket_packet);
    }
};

// ObjectGrabUpdatePacket
class ObjectGrabUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
        SerializableVector3 GrabOffsetInitial;
        SerializableVector3 GrabPosition;
        SerializableU32 TimeSinceLast;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            GrabOffsetInitial.serialize(buffer);
            GrabPosition.serialize(buffer);
            TimeSinceLast.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            GrabOffsetInitial.deserialize(buffer);
            GrabPosition.deserialize(buffer);
            TimeSinceLast.deserialize(buffer);
        }
    };
    class SurfaceInfoBlock : public PacketSerializable {
    public:
        // SurfaceInfoBlock Member List
        SerializableVector3 UVCoord;
        SerializableVector3 STCoord;
        SerializableS32 FaceIndex;
        SerializableVector3 Position;
        SerializableVector3 Normal;
        SerializableVector3 Binormal;
    public:
        SurfaceInfoBlock() {};
        virtual ~SurfaceInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UVCoord.serialize(buffer);
            STCoord.serialize(buffer);
            FaceIndex.serialize(buffer);
            Position.serialize(buffer);
            Normal.serialize(buffer);
            Binormal.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UVCoord.deserialize(buffer);
            STCoord.deserialize(buffer);
            FaceIndex.deserialize(buffer);
            Position.deserialize(buffer);
            Normal.deserialize(buffer);
            Binormal.deserialize(buffer);
        }
    };
    // ObjectGrabUpdatePacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    VariableSerializable<SurfaceInfoBlock> SurfaceInfo;
    typedef VariableSerializable<SurfaceInfoBlock> SURFACEINFOBLOCK_LIST_TYPE;

public:
    ObjectGrabUpdatePacket() {
        this->setID(ObjectGrabUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectGrabUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
        SurfaceInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        SurfaceInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectGrabUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectGrabUpdatePacket *ObjectGrabUpdatePacket_packet = dynamic_cast<const ObjectGrabUpdatePacket *>(packet);
        if (ObjectGrabUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectGrabUpdatePacket(*ObjectGrabUpdatePacket_packet);
    }
};

// ObjectDeGrabPacket
class ObjectDeGrabPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    class SurfaceInfoBlock : public PacketSerializable {
    public:
        // SurfaceInfoBlock Member List
        SerializableVector3 UVCoord;
        SerializableVector3 STCoord;
        SerializableS32 FaceIndex;
        SerializableVector3 Position;
        SerializableVector3 Normal;
        SerializableVector3 Binormal;
    public:
        SurfaceInfoBlock() {};
        virtual ~SurfaceInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UVCoord.serialize(buffer);
            STCoord.serialize(buffer);
            FaceIndex.serialize(buffer);
            Position.serialize(buffer);
            Normal.serialize(buffer);
            Binormal.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UVCoord.deserialize(buffer);
            STCoord.deserialize(buffer);
            FaceIndex.deserialize(buffer);
            Position.deserialize(buffer);
            Normal.deserialize(buffer);
            Binormal.deserialize(buffer);
        }
    };
    // ObjectDeGrabPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    VariableSerializable<SurfaceInfoBlock> SurfaceInfo;
    typedef VariableSerializable<SurfaceInfoBlock> SURFACEINFOBLOCK_LIST_TYPE;

public:
    ObjectDeGrabPacket() {
        this->setID(ObjectDeGrab_ID);
    };
    virtual ~ObjectDeGrabPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
        SurfaceInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        SurfaceInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDeGrabPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectDeGrabPacket *ObjectDeGrabPacket_packet = dynamic_cast<const ObjectDeGrabPacket *>(packet);
        if (ObjectDeGrabPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectDeGrabPacket(*ObjectDeGrabPacket_packet);
    }
};

// ObjectSpinStartPacket
class ObjectSpinStartPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // ObjectSpinStartPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectSpinStartPacket() {
        this->setID(ObjectSpinStart_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSpinStartPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSpinStartPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectSpinStartPacket *ObjectSpinStartPacket_packet = dynamic_cast<const ObjectSpinStartPacket *>(packet);
        if (ObjectSpinStartPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectSpinStartPacket(*ObjectSpinStartPacket_packet);
    }
};

// ObjectSpinUpdatePacket
class ObjectSpinUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
        SerializableQuaternion Rotation;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            Rotation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            Rotation.deserialize(buffer);
        }
    };
    // ObjectSpinUpdatePacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectSpinUpdatePacket() {
        this->setID(ObjectSpinUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSpinUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSpinUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectSpinUpdatePacket *ObjectSpinUpdatePacket_packet = dynamic_cast<const ObjectSpinUpdatePacket *>(packet);
        if (ObjectSpinUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectSpinUpdatePacket(*ObjectSpinUpdatePacket_packet);
    }
};

// ObjectSpinStopPacket
class ObjectSpinStopPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // ObjectSpinStopPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectSpinStopPacket() {
        this->setID(ObjectSpinStop_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSpinStopPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSpinStopPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectSpinStopPacket *ObjectSpinStopPacket_packet = dynamic_cast<const ObjectSpinStopPacket *>(packet);
        if (ObjectSpinStopPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectSpinStopPacket(*ObjectSpinStopPacket_packet);
    }
};

// ObjectExportSelectedPacket
class ObjectExportSelectedPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID RequestID;
        SerializableS16 VolumeDetail;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            RequestID.serialize(buffer);
            VolumeDetail.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            RequestID.deserialize(buffer);
            VolumeDetail.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // ObjectExportSelectedPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectExportSelectedPacket() {
        this->setID(ObjectExportSelected_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectExportSelectedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectExportSelectedPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectExportSelectedPacket *ObjectExportSelectedPacket_packet = dynamic_cast<const ObjectExportSelectedPacket *>(packet);
        if (ObjectExportSelectedPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectExportSelectedPacket(*ObjectExportSelectedPacket_packet);
    }
};

// ModifyLandPacket
class ModifyLandPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ModifyBlockBlock : public PacketSerializable {
    public:
        // ModifyBlockBlock Member List
        SerializableU8 Action;
        SerializableU8 BrushSize;
        SerializableF32 Seconds;
        SerializableF32 Height;
    public:
        ModifyBlockBlock() {};
        virtual ~ModifyBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Action.serialize(buffer);
            BrushSize.serialize(buffer);
            Seconds.serialize(buffer);
            Height.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Action.deserialize(buffer);
            BrushSize.deserialize(buffer);
            Seconds.deserialize(buffer);
            Height.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ModifyLandPacket Member List
    AgentDataBlock AgentData;
    ModifyBlockBlock ModifyBlock;
    VariableSerializable<ParcelDataBlock> ParcelData;
    typedef VariableSerializable<ParcelDataBlock> PARCELDATABLOCK_LIST_TYPE;

public:
    ModifyLandPacket() {
        this->setID(ModifyLand_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ModifyLandPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ModifyBlock.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ModifyBlock.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ModifyLandPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ModifyLandPacket *ModifyLandPacket_packet = dynamic_cast<const ModifyLandPacket *>(packet);
        if (ModifyLandPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ModifyLandPacket(*ModifyLandPacket_packet);
    }
};

// VelocityInterpolateOnPacket
class VelocityInterpolateOnPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // VelocityInterpolateOnPacket Member List
    AgentDataBlock AgentData;

public:
    VelocityInterpolateOnPacket() {
        this->setID(VelocityInterpolateOn_ID);
    };
    virtual ~VelocityInterpolateOnPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new VelocityInterpolateOnPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const VelocityInterpolateOnPacket *VelocityInterpolateOnPacket_packet = dynamic_cast<const VelocityInterpolateOnPacket *>(packet);
        if (VelocityInterpolateOnPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new VelocityInterpolateOnPacket(*VelocityInterpolateOnPacket_packet);
    }
};

// VelocityInterpolateOffPacket
class VelocityInterpolateOffPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // VelocityInterpolateOffPacket Member List
    AgentDataBlock AgentData;

public:
    VelocityInterpolateOffPacket() {
        this->setID(VelocityInterpolateOff_ID);
    };
    virtual ~VelocityInterpolateOffPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new VelocityInterpolateOffPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const VelocityInterpolateOffPacket *VelocityInterpolateOffPacket_packet = dynamic_cast<const VelocityInterpolateOffPacket *>(packet);
        if (VelocityInterpolateOffPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new VelocityInterpolateOffPacket(*VelocityInterpolateOffPacket_packet);
    }
};

// StateSavePacket
class StateSavePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableVariable1 Filename;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Filename.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Filename.deserialize(buffer);
        }
    };
    // StateSavePacket Member List
    AgentDataBlock AgentData;
    DataBlockBlock DataBlock;

public:
    StateSavePacket() {
        this->setID(StateSave_ID);
    };
    virtual ~StateSavePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StateSavePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const StateSavePacket *StateSavePacket_packet = dynamic_cast<const StateSavePacket *>(packet);
        if (StateSavePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new StateSavePacket(*StateSavePacket_packet);
    }
};

// ReportAutosaveCrashPacket
class ReportAutosaveCrashPacket : public PacketBase {
public:

    // Block Class List
    class AutosaveDataBlock : public PacketSerializable {
    public:
        // AutosaveDataBlock Member List
        SerializableS32 PID;
        SerializableS32 Status;
    public:
        AutosaveDataBlock() {};
        virtual ~AutosaveDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PID.serialize(buffer);
            Status.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PID.deserialize(buffer);
            Status.deserialize(buffer);
        }
    };
    // ReportAutosaveCrashPacket Member List
    AutosaveDataBlock AutosaveData;

public:
    ReportAutosaveCrashPacket() {
        this->setID(ReportAutosaveCrash_ID);
    };
    virtual ~ReportAutosaveCrashPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AutosaveData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AutosaveData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ReportAutosaveCrashPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ReportAutosaveCrashPacket *ReportAutosaveCrashPacket_packet = dynamic_cast<const ReportAutosaveCrashPacket *>(packet);
        if (ReportAutosaveCrashPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ReportAutosaveCrashPacket(*ReportAutosaveCrashPacket_packet);
    }
};

// SimWideDeletesPacket
class SimWideDeletesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID TargetID;
        SerializableU32 Flags;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // SimWideDeletesPacket Member List
    AgentDataBlock AgentData;
    DataBlockBlock DataBlock;

public:
    SimWideDeletesPacket() {
        this->setID(SimWideDeletes_ID);
    };
    virtual ~SimWideDeletesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimWideDeletesPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SimWideDeletesPacket *SimWideDeletesPacket_packet = dynamic_cast<const SimWideDeletesPacket *>(packet);
        if (SimWideDeletesPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SimWideDeletesPacket(*SimWideDeletesPacket_packet);
    }
};

// RequestObjectPropertiesFamilyPacket
class RequestObjectPropertiesFamilyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 RequestFlags;
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestFlags.serialize(buffer);
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestFlags.deserialize(buffer);
            ObjectID.deserialize(buffer);
        }
    };
    // RequestObjectPropertiesFamilyPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    RequestObjectPropertiesFamilyPacket() {
        this->setID(RequestObjectPropertiesFamily_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RequestObjectPropertiesFamilyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestObjectPropertiesFamilyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestObjectPropertiesFamilyPacket *RequestObjectPropertiesFamilyPacket_packet = dynamic_cast<const RequestObjectPropertiesFamilyPacket *>(packet);
        if (RequestObjectPropertiesFamilyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestObjectPropertiesFamilyPacket(*RequestObjectPropertiesFamilyPacket_packet);
    }
};

// TrackAgentPacket
class TrackAgentPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TargetDataBlock : public PacketSerializable {
    public:
        // TargetDataBlock Member List
        SerializableUUID PreyID;
    public:
        TargetDataBlock() {};
        virtual ~TargetDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PreyID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PreyID.deserialize(buffer);
        }
    };
    // TrackAgentPacket Member List
    AgentDataBlock AgentData;
    TargetDataBlock TargetData;

public:
    TrackAgentPacket() {
        this->setID(TrackAgent_ID);
    };
    virtual ~TrackAgentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TargetData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TargetData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TrackAgentPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TrackAgentPacket *TrackAgentPacket_packet = dynamic_cast<const TrackAgentPacket *>(packet);
        if (TrackAgentPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TrackAgentPacket(*TrackAgentPacket_packet);
    }
};

// ViewerStatsPacket
class ViewerStatsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableIPADDR IP;
        SerializableU32 StartTime;
        SerializableF32 RunTime;
        SerializableF32 SimFPS;
        SerializableF32 FPS;
        SerializableU8 AgentsInView;
        SerializableF32 Ping;
        SerializableF64 MetersTraveled;
        SerializableS32 RegionsVisited;
        SerializableU32 SysRAM;
        SerializableVariable1 SysOS;
        SerializableVariable1 SysCPU;
        SerializableVariable1 SysGPU;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            IP.serialize(buffer);
            StartTime.serialize(buffer);
            RunTime.serialize(buffer);
            SimFPS.serialize(buffer);
            FPS.serialize(buffer);
            AgentsInView.serialize(buffer);
            Ping.serialize(buffer);
            MetersTraveled.serialize(buffer);
            RegionsVisited.serialize(buffer);
            SysRAM.serialize(buffer);
            SysOS.serialize(buffer);
            SysCPU.serialize(buffer);
            SysGPU.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            IP.deserialize(buffer);
            StartTime.deserialize(buffer);
            RunTime.deserialize(buffer);
            SimFPS.deserialize(buffer);
            FPS.deserialize(buffer);
            AgentsInView.deserialize(buffer);
            Ping.deserialize(buffer);
            MetersTraveled.deserialize(buffer);
            RegionsVisited.deserialize(buffer);
            SysRAM.deserialize(buffer);
            SysOS.deserialize(buffer);
            SysCPU.deserialize(buffer);
            SysGPU.deserialize(buffer);
        }
    };
    class DownloadTotalsBlock : public PacketSerializable {
    public:
        // DownloadTotalsBlock Member List
        SerializableU32 World;
        SerializableU32 Objects;
        SerializableU32 Textures;
    public:
        DownloadTotalsBlock() {};
        virtual ~DownloadTotalsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            World.serialize(buffer);
            Objects.serialize(buffer);
            Textures.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            World.deserialize(buffer);
            Objects.deserialize(buffer);
            Textures.deserialize(buffer);
        }
    };
    class NetStatsBlock : public PacketSerializable {
    public:
        // NetStatsBlock Member List
        SerializableU32 Bytes;
        SerializableU32 Packets;
        SerializableU32 Compressed;
        SerializableU32 Savings;
    public:
        NetStatsBlock() {};
        virtual ~NetStatsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Bytes.serialize(buffer);
            Packets.serialize(buffer);
            Compressed.serialize(buffer);
            Savings.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Bytes.deserialize(buffer);
            Packets.deserialize(buffer);
            Compressed.deserialize(buffer);
            Savings.deserialize(buffer);
        }
    };
    class FailStatsBlock : public PacketSerializable {
    public:
        // FailStatsBlock Member List
        SerializableU32 SendPacket;
        SerializableU32 Dropped;
        SerializableU32 Resent;
        SerializableU32 FailedResends;
        SerializableU32 OffCircuit;
        SerializableU32 Invalid;
    public:
        FailStatsBlock() {};
        virtual ~FailStatsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SendPacket.serialize(buffer);
            Dropped.serialize(buffer);
            Resent.serialize(buffer);
            FailedResends.serialize(buffer);
            OffCircuit.serialize(buffer);
            Invalid.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SendPacket.deserialize(buffer);
            Dropped.deserialize(buffer);
            Resent.deserialize(buffer);
            FailedResends.deserialize(buffer);
            OffCircuit.deserialize(buffer);
            Invalid.deserialize(buffer);
        }
    };
    class MiscStatsBlock : public PacketSerializable {
    public:
        // MiscStatsBlock Member List
        SerializableU32 Type;
        SerializableF64 Value;
    public:
        MiscStatsBlock() {};
        virtual ~MiscStatsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Type.serialize(buffer);
            Value.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Type.deserialize(buffer);
            Value.deserialize(buffer);
        }
    };
    // ViewerStatsPacket Member List
    AgentDataBlock AgentData;
    DownloadTotalsBlock DownloadTotals;
    MultipleSerializable<NetStatsBlock, 2> NetStats;
    typedef MultipleSerializable<NetStatsBlock, 2> NETSTATSBLOCK_LIST_TYPE;
    FailStatsBlock FailStats;
    VariableSerializable<MiscStatsBlock> MiscStats;
    typedef VariableSerializable<MiscStatsBlock> MISCSTATSBLOCK_LIST_TYPE;

public:
    ViewerStatsPacket() {
        this->setID(ViewerStats_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ViewerStatsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        DownloadTotals.serialize(buffer);
        NetStats.serialize(buffer);
        FailStats.serialize(buffer);
        MiscStats.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        DownloadTotals.deserialize(buffer);
        NetStats.deserialize(buffer);
        FailStats.deserialize(buffer);
        MiscStats.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ViewerStatsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ViewerStatsPacket *ViewerStatsPacket_packet = dynamic_cast<const ViewerStatsPacket *>(packet);
        if (ViewerStatsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ViewerStatsPacket(*ViewerStatsPacket_packet);
    }
};

// ScriptAnswerYesPacket
class ScriptAnswerYesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableS32 Questions;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            Questions.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            Questions.deserialize(buffer);
        }
    };
    // ScriptAnswerYesPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ScriptAnswerYesPacket() {
        this->setID(ScriptAnswerYes_ID);
    };
    virtual ~ScriptAnswerYesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptAnswerYesPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ScriptAnswerYesPacket *ScriptAnswerYesPacket_packet = dynamic_cast<const ScriptAnswerYesPacket *>(packet);
        if (ScriptAnswerYesPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ScriptAnswerYesPacket(*ScriptAnswerYesPacket_packet);
    }
};

// UserReportPacket
class UserReportPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ReportDataBlock : public PacketSerializable {
    public:
        // ReportDataBlock Member List
        SerializableU8 ReportType;
        SerializableU8 Category;
        SerializableVector3 Position;
        SerializableU8 CheckFlags;
        SerializableUUID ScreenshotID;
        SerializableUUID ObjectID;
        SerializableUUID AbuserID;
        SerializableVariable1 AbuseRegionName;
        SerializableUUID AbuseRegionID;
        SerializableVariable1 Summary;
        SerializableVariable2 Details;
        SerializableVariable1 VersionString;
    public:
        ReportDataBlock() {};
        virtual ~ReportDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReportType.serialize(buffer);
            Category.serialize(buffer);
            Position.serialize(buffer);
            CheckFlags.serialize(buffer);
            ScreenshotID.serialize(buffer);
            ObjectID.serialize(buffer);
            AbuserID.serialize(buffer);
            AbuseRegionName.serialize(buffer);
            AbuseRegionID.serialize(buffer);
            Summary.serialize(buffer);
            Details.serialize(buffer);
            VersionString.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReportType.deserialize(buffer);
            Category.deserialize(buffer);
            Position.deserialize(buffer);
            CheckFlags.deserialize(buffer);
            ScreenshotID.deserialize(buffer);
            ObjectID.deserialize(buffer);
            AbuserID.deserialize(buffer);
            AbuseRegionName.deserialize(buffer);
            AbuseRegionID.deserialize(buffer);
            Summary.deserialize(buffer);
            Details.deserialize(buffer);
            VersionString.deserialize(buffer);
        }
    };
    // UserReportPacket Member List
    AgentDataBlock AgentData;
    ReportDataBlock ReportData;

public:
    UserReportPacket() {
        this->setID(UserReport_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UserReportPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ReportData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ReportData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UserReportPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UserReportPacket *UserReportPacket_packet = dynamic_cast<const UserReportPacket *>(packet);
        if (UserReportPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UserReportPacket(*UserReportPacket_packet);
    }
};

// RequestRegionInfoPacket
class RequestRegionInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // RequestRegionInfoPacket Member List
    AgentDataBlock AgentData;

public:
    RequestRegionInfoPacket() {
        this->setID(RequestRegionInfo_ID);
    };
    virtual ~RequestRegionInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestRegionInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestRegionInfoPacket *RequestRegionInfoPacket_packet = dynamic_cast<const RequestRegionInfoPacket *>(packet);
        if (RequestRegionInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestRegionInfoPacket(*RequestRegionInfoPacket_packet);
    }
};

// RegionInfoPacket
class RegionInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RegionInfoBlock : public PacketSerializable {
    public:
        // RegionInfoBlock Member List
        SerializableVariable1 SimName;
        SerializableU32 EstateID;
        SerializableU32 ParentEstateID;
        SerializableU32 RegionFlags;
        SerializableU8 SimAccess;
        SerializableU8 MaxAgents;
        SerializableF32 BillableFactor;
        SerializableF32 ObjectBonusFactor;
        SerializableF32 WaterHeight;
        SerializableF32 TerrainRaiseLimit;
        SerializableF32 TerrainLowerLimit;
        SerializableS32 PricePerMeter;
        SerializableS32 RedirectGridX;
        SerializableS32 RedirectGridY;
        SerializableBool UseEstateSun;
        SerializableF32 SunHour;
    public:
        RegionInfoBlock() {};
        virtual ~RegionInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            EstateID.serialize(buffer);
            ParentEstateID.serialize(buffer);
            RegionFlags.serialize(buffer);
            SimAccess.serialize(buffer);
            MaxAgents.serialize(buffer);
            BillableFactor.serialize(buffer);
            ObjectBonusFactor.serialize(buffer);
            WaterHeight.serialize(buffer);
            TerrainRaiseLimit.serialize(buffer);
            TerrainLowerLimit.serialize(buffer);
            PricePerMeter.serialize(buffer);
            RedirectGridX.serialize(buffer);
            RedirectGridY.serialize(buffer);
            UseEstateSun.serialize(buffer);
            SunHour.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            EstateID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            SimAccess.deserialize(buffer);
            MaxAgents.deserialize(buffer);
            BillableFactor.deserialize(buffer);
            ObjectBonusFactor.deserialize(buffer);
            WaterHeight.deserialize(buffer);
            TerrainRaiseLimit.deserialize(buffer);
            TerrainLowerLimit.deserialize(buffer);
            PricePerMeter.deserialize(buffer);
            RedirectGridX.deserialize(buffer);
            RedirectGridY.deserialize(buffer);
            UseEstateSun.deserialize(buffer);
            SunHour.deserialize(buffer);
        }
    };
    // RegionInfoPacket Member List
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;

public:
    RegionInfoPacket() {
        this->setID(RegionInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RegionInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RegionInfoPacket *RegionInfoPacket_packet = dynamic_cast<const RegionInfoPacket *>(packet);
        if (RegionInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RegionInfoPacket(*RegionInfoPacket_packet);
    }
};

// GodUpdateRegionInfoPacket
class GodUpdateRegionInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RegionInfoBlock : public PacketSerializable {
    public:
        // RegionInfoBlock Member List
        SerializableVariable1 SimName;
        SerializableU32 EstateID;
        SerializableU32 ParentEstateID;
        SerializableU32 RegionFlags;
        SerializableF32 BillableFactor;
        SerializableS32 PricePerMeter;
        SerializableS32 RedirectGridX;
        SerializableS32 RedirectGridY;
    public:
        RegionInfoBlock() {};
        virtual ~RegionInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            EstateID.serialize(buffer);
            ParentEstateID.serialize(buffer);
            RegionFlags.serialize(buffer);
            BillableFactor.serialize(buffer);
            PricePerMeter.serialize(buffer);
            RedirectGridX.serialize(buffer);
            RedirectGridY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            EstateID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            BillableFactor.deserialize(buffer);
            PricePerMeter.deserialize(buffer);
            RedirectGridX.deserialize(buffer);
            RedirectGridY.deserialize(buffer);
        }
    };
    // GodUpdateRegionInfoPacket Member List
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;

public:
    GodUpdateRegionInfoPacket() {
        this->setID(GodUpdateRegionInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GodUpdateRegionInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GodUpdateRegionInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GodUpdateRegionInfoPacket *GodUpdateRegionInfoPacket_packet = dynamic_cast<const GodUpdateRegionInfoPacket *>(packet);
        if (GodUpdateRegionInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GodUpdateRegionInfoPacket(*GodUpdateRegionInfoPacket_packet);
    }
};

// RegionHandshakeReplyPacket
class RegionHandshakeReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RegionInfoBlock : public PacketSerializable {
    public:
        // RegionInfoBlock Member List
        SerializableU32 Flags;
    public:
        RegionInfoBlock() {};
        virtual ~RegionInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Flags.deserialize(buffer);
        }
    };
    // RegionHandshakeReplyPacket Member List
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;

public:
    RegionHandshakeReplyPacket() {
        this->setID(RegionHandshakeReply_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RegionHandshakeReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionHandshakeReplyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RegionHandshakeReplyPacket *RegionHandshakeReplyPacket_packet = dynamic_cast<const RegionHandshakeReplyPacket *>(packet);
        if (RegionHandshakeReplyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RegionHandshakeReplyPacket(*RegionHandshakeReplyPacket_packet);
    }
};

// TransferRequestPacket
class TransferRequestPacket : public PacketBase {
public:

    // Block Class List
    class TransferInfoBlock : public PacketSerializable {
    public:
        // TransferInfoBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
        SerializableS32 SourceType;
        SerializableF32 Priority;
        SerializableVariable2 Params;
    public:
        TransferInfoBlock() {};
        virtual ~TransferInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
            SourceType.serialize(buffer);
            Priority.serialize(buffer);
            Params.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
            SourceType.deserialize(buffer);
            Priority.deserialize(buffer);
            Params.deserialize(buffer);
        }
    };
    // TransferRequestPacket Member List
    TransferInfoBlock TransferInfo;

public:
    TransferRequestPacket() {
        this->setID(TransferRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TransferRequestPacket *TransferRequestPacket_packet = dynamic_cast<const TransferRequestPacket *>(packet);
        if (TransferRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TransferRequestPacket(*TransferRequestPacket_packet);
    }
};

// TransferInfoPacket
class TransferInfoPacket : public PacketBase {
public:

    // Block Class List
    class TransferInfoBlock : public PacketSerializable {
    public:
        // TransferInfoBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
        SerializableS32 TargetType;
        SerializableS32 Status;
        SerializableS32 Size;
        SerializableVariable2 Params;
    public:
        TransferInfoBlock() {};
        virtual ~TransferInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
            TargetType.serialize(buffer);
            Status.serialize(buffer);
            Size.serialize(buffer);
            Params.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
            TargetType.deserialize(buffer);
            Status.deserialize(buffer);
            Size.deserialize(buffer);
            Params.deserialize(buffer);
        }
    };
    // TransferInfoPacket Member List
    TransferInfoBlock TransferInfo;

public:
    TransferInfoPacket() {
        this->setID(TransferInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TransferInfoPacket *TransferInfoPacket_packet = dynamic_cast<const TransferInfoPacket *>(packet);
        if (TransferInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TransferInfoPacket(*TransferInfoPacket_packet);
    }
};

// TransferPacketPacket
class TransferPacketPacket : public PacketBase {
public:

    // Block Class List
    class TransferDataBlock : public PacketSerializable {
    public:
        // TransferDataBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
        SerializableS32 Packet;
        SerializableS32 Status;
        SerializableVariable2 Data;
    public:
        TransferDataBlock() {};
        virtual ~TransferDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
            Packet.serialize(buffer);
            Status.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
            Packet.deserialize(buffer);
            Status.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // TransferPacketPacket Member List
    TransferDataBlock TransferData;

public:
    TransferPacketPacket() {
        this->setID(TransferPacket_ID);
    };
    virtual ~TransferPacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferPacketPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TransferPacketPacket *TransferPacketPacket_packet = dynamic_cast<const TransferPacketPacket *>(packet);
        if (TransferPacketPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TransferPacketPacket(*TransferPacketPacket_packet);
    }
};

// TransferAbortPacket
class TransferAbortPacket : public PacketBase {
public:

    // Block Class List
    class TransferInfoBlock : public PacketSerializable {
    public:
        // TransferInfoBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
    public:
        TransferInfoBlock() {};
        virtual ~TransferInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
        }
    };
    // TransferAbortPacket Member List
    TransferInfoBlock TransferInfo;

public:
    TransferAbortPacket() {
        this->setID(TransferAbort_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferAbortPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferAbortPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TransferAbortPacket *TransferAbortPacket_packet = dynamic_cast<const TransferAbortPacket *>(packet);
        if (TransferAbortPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TransferAbortPacket(*TransferAbortPacket_packet);
    }
};

// RequestXferPacket
class RequestXferPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableVariable1 Filename;
        SerializableU8 FilePath;
        SerializableBool DeleteOnCompletion;
        SerializableBool UseBigPackets;
        SerializableUUID VFileID;
        SerializableS16 VFileType;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Filename.serialize(buffer);
            FilePath.serialize(buffer);
            DeleteOnCompletion.serialize(buffer);
            UseBigPackets.serialize(buffer);
            VFileID.serialize(buffer);
            VFileType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Filename.deserialize(buffer);
            FilePath.deserialize(buffer);
            DeleteOnCompletion.deserialize(buffer);
            UseBigPackets.deserialize(buffer);
            VFileID.deserialize(buffer);
            VFileType.deserialize(buffer);
        }
    };
    // RequestXferPacket Member List
    XferIDBlock XferID;

public:
    RequestXferPacket() {
        this->setID(RequestXfer_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RequestXferPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestXferPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestXferPacket *RequestXferPacket_packet = dynamic_cast<const RequestXferPacket *>(packet);
        if (RequestXferPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestXferPacket(*RequestXferPacket_packet);
    }
};

// SendXferPacketPacket
class SendXferPacketPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableU32 Packet;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Packet.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Packet.deserialize(buffer);
        }
    };
    class DataPacketBlock : public PacketSerializable {
    public:
        // DataPacketBlock Member List
        SerializableVariable2 Data;
    public:
        DataPacketBlock() {};
        virtual ~DataPacketBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Data.deserialize(buffer);
        }
    };
    // SendXferPacketPacket Member List
    XferIDBlock XferID;
    DataPacketBlock DataPacket;

public:
    SendXferPacketPacket() {
        this->setID(SendXferPacket_ID);
    };
    virtual ~SendXferPacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
        DataPacket.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
        DataPacket.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SendXferPacketPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SendXferPacketPacket *SendXferPacketPacket_packet = dynamic_cast<const SendXferPacketPacket *>(packet);
        if (SendXferPacketPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SendXferPacketPacket(*SendXferPacketPacket_packet);
    }
};

// ConfirmXferPacketPacket
class ConfirmXferPacketPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableU32 Packet;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Packet.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Packet.deserialize(buffer);
        }
    };
    // ConfirmXferPacketPacket Member List
    XferIDBlock XferID;

public:
    ConfirmXferPacketPacket() {
        this->setID(ConfirmXferPacket_ID);
    };
    virtual ~ConfirmXferPacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ConfirmXferPacketPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ConfirmXferPacketPacket *ConfirmXferPacketPacket_packet = dynamic_cast<const ConfirmXferPacketPacket *>(packet);
        if (ConfirmXferPacketPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ConfirmXferPacketPacket(*ConfirmXferPacketPacket_packet);
    }
};

// AbortXferPacket
class AbortXferPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableS32 Result;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Result.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Result.deserialize(buffer);
        }
    };
    // AbortXferPacket Member List
    XferIDBlock XferID;

public:
    AbortXferPacket() {
        this->setID(AbortXfer_ID);
    };
    virtual ~AbortXferPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AbortXferPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AbortXferPacket *AbortXferPacket_packet = dynamic_cast<const AbortXferPacket *>(packet);
        if (AbortXferPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AbortXferPacket(*AbortXferPacket_packet);
    }
};

// RequestPayPricePacket
class RequestPayPricePacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // RequestPayPricePacket Member List
    ObjectDataBlock ObjectData;

public:
    RequestPayPricePacket() {
        this->setID(RequestPayPrice_ID);
    };
    virtual ~RequestPayPricePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestPayPricePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestPayPricePacket *RequestPayPricePacket_packet = dynamic_cast<const RequestPayPricePacket *>(packet);
        if (RequestPayPricePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestPayPricePacket(*RequestPayPricePacket_packet);
    }
};

// GodKickUserPacket
class GodKickUserPacket : public PacketBase {
public:

    // Block Class List
    class UserInfoBlock : public PacketSerializable {
    public:
        // UserInfoBlock Member List
        SerializableUUID GodID;
        SerializableUUID GodSessionID;
        SerializableUUID AgentID;
        SerializableU32 KickFlags;
        SerializableVariable2 Reason;
    public:
        UserInfoBlock() {};
        virtual ~UserInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GodID.serialize(buffer);
            GodSessionID.serialize(buffer);
            AgentID.serialize(buffer);
            KickFlags.serialize(buffer);
            Reason.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GodID.deserialize(buffer);
            GodSessionID.deserialize(buffer);
            AgentID.deserialize(buffer);
            KickFlags.deserialize(buffer);
            Reason.deserialize(buffer);
        }
    };
    // GodKickUserPacket Member List
    UserInfoBlock UserInfo;

public:
    GodKickUserPacket() {
        this->setID(GodKickUser_ID);
    };
    virtual ~GodKickUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UserInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UserInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GodKickUserPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GodKickUserPacket *GodKickUserPacket_packet = dynamic_cast<const GodKickUserPacket *>(packet);
        if (GodKickUserPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GodKickUserPacket(*GodKickUserPacket_packet);
    }
};

// EjectUserPacket
class EjectUserPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TargetID;
        SerializableU32 Flags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // EjectUserPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    EjectUserPacket() {
        this->setID(EjectUser_ID);
    };
    virtual ~EjectUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EjectUserPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EjectUserPacket *EjectUserPacket_packet = dynamic_cast<const EjectUserPacket *>(packet);
        if (EjectUserPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EjectUserPacket(*EjectUserPacket_packet);
    }
};

// FreezeUserPacket
class FreezeUserPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TargetID;
        SerializableU32 Flags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // FreezeUserPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    FreezeUserPacket() {
        this->setID(FreezeUser_ID);
    };
    virtual ~FreezeUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FreezeUserPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const FreezeUserPacket *FreezeUserPacket_packet = dynamic_cast<const FreezeUserPacket *>(packet);
        if (FreezeUserPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new FreezeUserPacket(*FreezeUserPacket_packet);
    }
};

// AvatarPropertiesRequestPacket
class AvatarPropertiesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID AvatarID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AvatarID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AvatarID.deserialize(buffer);
        }
    };
    // AvatarPropertiesRequestPacket Member List
    AgentDataBlock AgentData;

public:
    AvatarPropertiesRequestPacket() {
        this->setID(AvatarPropertiesRequest_ID);
    };
    virtual ~AvatarPropertiesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPropertiesRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AvatarPropertiesRequestPacket *AvatarPropertiesRequestPacket_packet = dynamic_cast<const AvatarPropertiesRequestPacket *>(packet);
        if (AvatarPropertiesRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AvatarPropertiesRequestPacket(*AvatarPropertiesRequestPacket_packet);
    }
};

// AvatarPropertiesUpdatePacket
class AvatarPropertiesUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class PropertiesDataBlock : public PacketSerializable {
    public:
        // PropertiesDataBlock Member List
        SerializableUUID ImageID;
        SerializableUUID FLImageID;
        SerializableVariable2 AboutText;
        SerializableVariable1 FLAboutText;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
        SerializableVariable1 ProfileURL;
    public:
        PropertiesDataBlock() {};
        virtual ~PropertiesDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ImageID.serialize(buffer);
            FLImageID.serialize(buffer);
            AboutText.serialize(buffer);
            FLAboutText.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
            ProfileURL.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ImageID.deserialize(buffer);
            FLImageID.deserialize(buffer);
            AboutText.deserialize(buffer);
            FLAboutText.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
            ProfileURL.deserialize(buffer);
        }
    };
    // AvatarPropertiesUpdatePacket Member List
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;

public:
    AvatarPropertiesUpdatePacket() {
        this->setID(AvatarPropertiesUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarPropertiesUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PropertiesData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PropertiesData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPropertiesUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AvatarPropertiesUpdatePacket *AvatarPropertiesUpdatePacket_packet = dynamic_cast<const AvatarPropertiesUpdatePacket *>(packet);
        if (AvatarPropertiesUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AvatarPropertiesUpdatePacket(*AvatarPropertiesUpdatePacket_packet);
    }
};

// AvatarInterestsUpdatePacket
class AvatarInterestsUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class PropertiesDataBlock : public PacketSerializable {
    public:
        // PropertiesDataBlock Member List
        SerializableU32 WantToMask;
        SerializableVariable1 WantToText;
        SerializableU32 SkillsMask;
        SerializableVariable1 SkillsText;
        SerializableVariable1 LanguagesText;
    public:
        PropertiesDataBlock() {};
        virtual ~PropertiesDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            WantToMask.serialize(buffer);
            WantToText.serialize(buffer);
            SkillsMask.serialize(buffer);
            SkillsText.serialize(buffer);
            LanguagesText.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            WantToMask.deserialize(buffer);
            WantToText.deserialize(buffer);
            SkillsMask.deserialize(buffer);
            SkillsText.deserialize(buffer);
            LanguagesText.deserialize(buffer);
        }
    };
    // AvatarInterestsUpdatePacket Member List
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;

public:
    AvatarInterestsUpdatePacket() {
        this->setID(AvatarInterestsUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarInterestsUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PropertiesData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PropertiesData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarInterestsUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AvatarInterestsUpdatePacket *AvatarInterestsUpdatePacket_packet = dynamic_cast<const AvatarInterestsUpdatePacket *>(packet);
        if (AvatarInterestsUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AvatarInterestsUpdatePacket(*AvatarInterestsUpdatePacket_packet);
    }
};

// AvatarNotesUpdatePacket
class AvatarNotesUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TargetID;
        SerializableVariable2 Notes;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Notes.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Notes.deserialize(buffer);
        }
    };
    // AvatarNotesUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    AvatarNotesUpdatePacket() {
        this->setID(AvatarNotesUpdate_ID);
    };
    virtual ~AvatarNotesUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarNotesUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AvatarNotesUpdatePacket *AvatarNotesUpdatePacket_packet = dynamic_cast<const AvatarNotesUpdatePacket *>(packet);
        if (AvatarNotesUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AvatarNotesUpdatePacket(*AvatarNotesUpdatePacket_packet);
    }
};

// EventInfoRequestPacket
class EventInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    // EventInfoRequestPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;

public:
    EventInfoRequestPacket() {
        this->setID(EventInfoRequest_ID);
    };
    virtual ~EventInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventInfoRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EventInfoRequestPacket *EventInfoRequestPacket_packet = dynamic_cast<const EventInfoRequestPacket *>(packet);
        if (EventInfoRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EventInfoRequestPacket(*EventInfoRequestPacket_packet);
    }
};

// EventNotificationAddRequestPacket
class EventNotificationAddRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    // EventNotificationAddRequestPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;

public:
    EventNotificationAddRequestPacket() {
        this->setID(EventNotificationAddRequest_ID);
    };
    virtual ~EventNotificationAddRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventNotificationAddRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EventNotificationAddRequestPacket *EventNotificationAddRequestPacket_packet = dynamic_cast<const EventNotificationAddRequestPacket *>(packet);
        if (EventNotificationAddRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EventNotificationAddRequestPacket(*EventNotificationAddRequestPacket_packet);
    }
};

// EventNotificationRemoveRequestPacket
class EventNotificationRemoveRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    // EventNotificationRemoveRequestPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;

public:
    EventNotificationRemoveRequestPacket() {
        this->setID(EventNotificationRemoveRequest_ID);
    };
    virtual ~EventNotificationRemoveRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventNotificationRemoveRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EventNotificationRemoveRequestPacket *EventNotificationRemoveRequestPacket_packet = dynamic_cast<const EventNotificationRemoveRequestPacket *>(packet);
        if (EventNotificationRemoveRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EventNotificationRemoveRequestPacket(*EventNotificationRemoveRequestPacket_packet);
    }
};

// EventGodDeletePacket
class EventGodDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // EventGodDeletePacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;
    QueryDataBlock QueryData;

public:
    EventGodDeletePacket() {
        this->setID(EventGodDelete_ID);
    };
    virtual ~EventGodDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventGodDeletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EventGodDeletePacket *EventGodDeletePacket_packet = dynamic_cast<const EventGodDeletePacket *>(packet);
        if (EventGodDeletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EventGodDeletePacket(*EventGodDeletePacket_packet);
    }
};

// PickInfoUpdatePacket
class PickInfoUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
        SerializableUUID CreatorID;
        SerializableBool TopPick;
        SerializableUUID ParcelID;
        SerializableVariable1 Name;
        SerializableVariable2 Desc;
        SerializableUUID SnapshotID;
        SerializableVector3d PosGlobal;
        SerializableS32 SortOrder;
        SerializableBool Enabled;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
            CreatorID.serialize(buffer);
            TopPick.serialize(buffer);
            ParcelID.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            SnapshotID.serialize(buffer);
            PosGlobal.serialize(buffer);
            SortOrder.serialize(buffer);
            Enabled.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            TopPick.deserialize(buffer);
            ParcelID.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            SortOrder.deserialize(buffer);
            Enabled.deserialize(buffer);
        }
    };
    // PickInfoUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    PickInfoUpdatePacket() {
        this->setID(PickInfoUpdate_ID);
    };
    virtual ~PickInfoUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PickInfoUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const PickInfoUpdatePacket *PickInfoUpdatePacket_packet = dynamic_cast<const PickInfoUpdatePacket *>(packet);
        if (PickInfoUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new PickInfoUpdatePacket(*PickInfoUpdatePacket_packet);
    }
};

// PickDeletePacket
class PickDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
        }
    };
    // PickDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    PickDeletePacket() {
        this->setID(PickDelete_ID);
    };
    virtual ~PickDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PickDeletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const PickDeletePacket *PickDeletePacket_packet = dynamic_cast<const PickDeletePacket *>(packet);
        if (PickDeletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new PickDeletePacket(*PickDeletePacket_packet);
    }
};

// PickGodDeletePacket
class PickGodDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
        SerializableUUID QueryID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    // PickGodDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    PickGodDeletePacket() {
        this->setID(PickGodDelete_ID);
    };
    virtual ~PickGodDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PickGodDeletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const PickGodDeletePacket *PickGodDeletePacket_packet = dynamic_cast<const PickGodDeletePacket *>(packet);
        if (PickGodDeletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new PickGodDeletePacket(*PickGodDeletePacket_packet);
    }
};

// ScriptDialogReplyPacket
class ScriptDialogReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableS32 ChatChannel;
        SerializableS32 ButtonIndex;
        SerializableVariable1 ButtonLabel;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ChatChannel.serialize(buffer);
            ButtonIndex.serialize(buffer);
            ButtonLabel.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ChatChannel.deserialize(buffer);
            ButtonIndex.deserialize(buffer);
            ButtonLabel.deserialize(buffer);
        }
    };
    // ScriptDialogReplyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ScriptDialogReplyPacket() {
        this->setID(ScriptDialogReply_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ScriptDialogReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptDialogReplyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ScriptDialogReplyPacket *ScriptDialogReplyPacket_packet = dynamic_cast<const ScriptDialogReplyPacket *>(packet);
        if (ScriptDialogReplyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ScriptDialogReplyPacket(*ScriptDialogReplyPacket_packet);
    }
};

// ForceScriptControlReleasePacket
class ForceScriptControlReleasePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // ForceScriptControlReleasePacket Member List
    AgentDataBlock AgentData;

public:
    ForceScriptControlReleasePacket() {
        this->setID(ForceScriptControlRelease_ID);
    };
    virtual ~ForceScriptControlReleasePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ForceScriptControlReleasePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ForceScriptControlReleasePacket *ForceScriptControlReleasePacket_packet = dynamic_cast<const ForceScriptControlReleasePacket *>(packet);
        if (ForceScriptControlReleasePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ForceScriptControlReleasePacket(*ForceScriptControlReleasePacket_packet);
    }
};

// RevokePermissionsPacket
class RevokePermissionsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableU32 ObjectPermissions;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ObjectPermissions.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ObjectPermissions.deserialize(buffer);
        }
    };
    // RevokePermissionsPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    RevokePermissionsPacket() {
        this->setID(RevokePermissions_ID);
    };
    virtual ~RevokePermissionsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RevokePermissionsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RevokePermissionsPacket *RevokePermissionsPacket_packet = dynamic_cast<const RevokePermissionsPacket *>(packet);
        if (RevokePermissionsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RevokePermissionsPacket(*RevokePermissionsPacket_packet);
    }
};

// ParcelPropertiesRequestPacket
class ParcelPropertiesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 SequenceID;
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
        SerializableBool SnapSelection;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SequenceID.serialize(buffer);
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
            SnapSelection.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SequenceID.deserialize(buffer);
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
            SnapSelection.deserialize(buffer);
        }
    };
    // ParcelPropertiesRequestPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelPropertiesRequestPacket() {
        this->setID(ParcelPropertiesRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelPropertiesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelPropertiesRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelPropertiesRequestPacket *ParcelPropertiesRequestPacket_packet = dynamic_cast<const ParcelPropertiesRequestPacket *>(packet);
        if (ParcelPropertiesRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelPropertiesRequestPacket(*ParcelPropertiesRequestPacket_packet);
    }
};

// ParcelPropertiesRequestByIDPacket
class ParcelPropertiesRequestByIDPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 SequenceID;
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SequenceID.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SequenceID.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelPropertiesRequestByIDPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelPropertiesRequestByIDPacket() {
        this->setID(ParcelPropertiesRequestByID_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelPropertiesRequestByIDPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelPropertiesRequestByIDPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelPropertiesRequestByIDPacket *ParcelPropertiesRequestByIDPacket_packet = dynamic_cast<const ParcelPropertiesRequestByIDPacket *>(packet);
        if (ParcelPropertiesRequestByIDPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelPropertiesRequestByIDPacket(*ParcelPropertiesRequestByIDPacket_packet);
    }
};

// ParcelPropertiesUpdatePacket
class ParcelPropertiesUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 Flags;
        SerializableU32 ParcelFlags;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Desc;
        SerializableVariable1 MusicURL;
        SerializableVariable1 MediaURL;
        SerializableUUID MediaID;
        SerializableU8 MediaAutoScale;
        SerializableUUID GroupID;
        SerializableS32 PassPrice;
        SerializableF32 PassHours;
        SerializableU8 Category;
        SerializableUUID AuthBuyerID;
        SerializableUUID SnapshotID;
        SerializableVector3 UserLocation;
        SerializableVector3 UserLookAt;
        SerializableU8 LandingType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Flags.serialize(buffer);
            ParcelFlags.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            MusicURL.serialize(buffer);
            MediaURL.serialize(buffer);
            MediaID.serialize(buffer);
            MediaAutoScale.serialize(buffer);
            GroupID.serialize(buffer);
            PassPrice.serialize(buffer);
            PassHours.serialize(buffer);
            Category.serialize(buffer);
            AuthBuyerID.serialize(buffer);
            SnapshotID.serialize(buffer);
            UserLocation.serialize(buffer);
            UserLookAt.serialize(buffer);
            LandingType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Flags.deserialize(buffer);
            ParcelFlags.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            MusicURL.deserialize(buffer);
            MediaURL.deserialize(buffer);
            MediaID.deserialize(buffer);
            MediaAutoScale.deserialize(buffer);
            GroupID.deserialize(buffer);
            PassPrice.deserialize(buffer);
            PassHours.deserialize(buffer);
            Category.deserialize(buffer);
            AuthBuyerID.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            UserLocation.deserialize(buffer);
            UserLookAt.deserialize(buffer);
            LandingType.deserialize(buffer);
        }
    };
    // ParcelPropertiesUpdatePacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelPropertiesUpdatePacket() {
        this->setID(ParcelPropertiesUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelPropertiesUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelPropertiesUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelPropertiesUpdatePacket *ParcelPropertiesUpdatePacket_packet = dynamic_cast<const ParcelPropertiesUpdatePacket *>(packet);
        if (ParcelPropertiesUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelPropertiesUpdatePacket(*ParcelPropertiesUpdatePacket_packet);
    }
};

// ParcelReturnObjectsPacket
class ParcelReturnObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 ReturnType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ReturnType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ReturnType.deserialize(buffer);
        }
    };
    class TaskIDsBlock : public PacketSerializable {
    public:
        // TaskIDsBlock Member List
        SerializableUUID TaskID;
    public:
        TaskIDsBlock() {};
        virtual ~TaskIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
        }
    };
    class OwnerIDsBlock : public PacketSerializable {
    public:
        // OwnerIDsBlock Member List
        SerializableUUID OwnerID;
    public:
        OwnerIDsBlock() {};
        virtual ~OwnerIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
        }
    };
    // ParcelReturnObjectsPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    VariableSerializable<TaskIDsBlock> TaskIDs;
    typedef VariableSerializable<TaskIDsBlock> TASKIDSBLOCK_LIST_TYPE;
    VariableSerializable<OwnerIDsBlock> OwnerIDs;
    typedef VariableSerializable<OwnerIDsBlock> OWNERIDSBLOCK_LIST_TYPE;

public:
    ParcelReturnObjectsPacket() {
        this->setID(ParcelReturnObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelReturnObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
        TaskIDs.serialize(buffer);
        OwnerIDs.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
        TaskIDs.deserialize(buffer);
        OwnerIDs.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelReturnObjectsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelReturnObjectsPacket *ParcelReturnObjectsPacket_packet = dynamic_cast<const ParcelReturnObjectsPacket *>(packet);
        if (ParcelReturnObjectsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelReturnObjectsPacket(*ParcelReturnObjectsPacket_packet);
    }
};

// ParcelSetOtherCleanTimePacket
class ParcelSetOtherCleanTimePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableS32 OtherCleanTime;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            OtherCleanTime.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            OtherCleanTime.deserialize(buffer);
        }
    };
    // ParcelSetOtherCleanTimePacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelSetOtherCleanTimePacket() {
        this->setID(ParcelSetOtherCleanTime_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelSetOtherCleanTimePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelSetOtherCleanTimePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelSetOtherCleanTimePacket *ParcelSetOtherCleanTimePacket_packet = dynamic_cast<const ParcelSetOtherCleanTimePacket *>(packet);
        if (ParcelSetOtherCleanTimePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelSetOtherCleanTimePacket(*ParcelSetOtherCleanTimePacket_packet);
    }
};

// ParcelDisableObjectsPacket
class ParcelDisableObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 ReturnType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ReturnType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ReturnType.deserialize(buffer);
        }
    };
    class TaskIDsBlock : public PacketSerializable {
    public:
        // TaskIDsBlock Member List
        SerializableUUID TaskID;
    public:
        TaskIDsBlock() {};
        virtual ~TaskIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
        }
    };
    class OwnerIDsBlock : public PacketSerializable {
    public:
        // OwnerIDsBlock Member List
        SerializableUUID OwnerID;
    public:
        OwnerIDsBlock() {};
        virtual ~OwnerIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
        }
    };
    // ParcelDisableObjectsPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    VariableSerializable<TaskIDsBlock> TaskIDs;
    typedef VariableSerializable<TaskIDsBlock> TASKIDSBLOCK_LIST_TYPE;
    VariableSerializable<OwnerIDsBlock> OwnerIDs;
    typedef VariableSerializable<OwnerIDsBlock> OWNERIDSBLOCK_LIST_TYPE;

public:
    ParcelDisableObjectsPacket() {
        this->setID(ParcelDisableObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelDisableObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
        TaskIDs.serialize(buffer);
        OwnerIDs.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
        TaskIDs.deserialize(buffer);
        OwnerIDs.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDisableObjectsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelDisableObjectsPacket *ParcelDisableObjectsPacket_packet = dynamic_cast<const ParcelDisableObjectsPacket *>(packet);
        if (ParcelDisableObjectsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelDisableObjectsPacket(*ParcelDisableObjectsPacket_packet);
    }
};

// ParcelSelectObjectsPacket
class ParcelSelectObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 ReturnType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ReturnType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ReturnType.deserialize(buffer);
        }
    };
    class ReturnIDsBlock : public PacketSerializable {
    public:
        // ReturnIDsBlock Member List
        SerializableUUID ReturnID;
    public:
        ReturnIDsBlock() {};
        virtual ~ReturnIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReturnID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReturnID.deserialize(buffer);
        }
    };
    // ParcelSelectObjectsPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    VariableSerializable<ReturnIDsBlock> ReturnIDs;
    typedef VariableSerializable<ReturnIDsBlock> RETURNIDSBLOCK_LIST_TYPE;

public:
    ParcelSelectObjectsPacket() {
        this->setID(ParcelSelectObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelSelectObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
        ReturnIDs.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
        ReturnIDs.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelSelectObjectsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelSelectObjectsPacket *ParcelSelectObjectsPacket_packet = dynamic_cast<const ParcelSelectObjectsPacket *>(packet);
        if (ParcelSelectObjectsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelSelectObjectsPacket(*ParcelSelectObjectsPacket_packet);
    }
};

// EstateCovenantRequestPacket
class EstateCovenantRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // EstateCovenantRequestPacket Member List
    AgentDataBlock AgentData;

public:
    EstateCovenantRequestPacket() {
        this->setID(EstateCovenantRequest_ID);
    };
    virtual ~EstateCovenantRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EstateCovenantRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EstateCovenantRequestPacket *EstateCovenantRequestPacket_packet = dynamic_cast<const EstateCovenantRequestPacket *>(packet);
        if (EstateCovenantRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EstateCovenantRequestPacket(*EstateCovenantRequestPacket_packet);
    }
};

// ParcelBuyPassPacket
class ParcelBuyPassPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelBuyPassPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelBuyPassPacket() {
        this->setID(ParcelBuyPass_ID);
    };
    virtual ~ParcelBuyPassPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelBuyPassPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelBuyPassPacket *ParcelBuyPassPacket_packet = dynamic_cast<const ParcelBuyPassPacket *>(packet);
        if (ParcelBuyPassPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelBuyPassPacket(*ParcelBuyPassPacket_packet);
    }
};

// ParcelDeedToGroupPacket
class ParcelDeedToGroupPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelDeedToGroupPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelDeedToGroupPacket() {
        this->setID(ParcelDeedToGroup_ID);
    };
    virtual ~ParcelDeedToGroupPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDeedToGroupPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelDeedToGroupPacket *ParcelDeedToGroupPacket_packet = dynamic_cast<const ParcelDeedToGroupPacket *>(packet);
        if (ParcelDeedToGroupPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelDeedToGroupPacket(*ParcelDeedToGroupPacket_packet);
    }
};

// ParcelReclaimPacket
class ParcelReclaimPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelReclaimPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelReclaimPacket() {
        this->setID(ParcelReclaim_ID);
    };
    virtual ~ParcelReclaimPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelReclaimPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelReclaimPacket *ParcelReclaimPacket_packet = dynamic_cast<const ParcelReclaimPacket *>(packet);
        if (ParcelReclaimPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelReclaimPacket(*ParcelReclaimPacket_packet);
    }
};

// ParcelClaimPacket
class ParcelClaimPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableBool IsGroupOwned;
        SerializableBool Final;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            IsGroupOwned.serialize(buffer);
            Final.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            IsGroupOwned.deserialize(buffer);
            Final.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ParcelClaimPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    VariableSerializable<ParcelDataBlock> ParcelData;
    typedef VariableSerializable<ParcelDataBlock> PARCELDATABLOCK_LIST_TYPE;

public:
    ParcelClaimPacket() {
        this->setID(ParcelClaim_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelClaimPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelClaimPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelClaimPacket *ParcelClaimPacket_packet = dynamic_cast<const ParcelClaimPacket *>(packet);
        if (ParcelClaimPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelClaimPacket(*ParcelClaimPacket_packet);
    }
};

// ParcelJoinPacket
class ParcelJoinPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ParcelJoinPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelJoinPacket() {
        this->setID(ParcelJoin_ID);
    };
    virtual ~ParcelJoinPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelJoinPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelJoinPacket *ParcelJoinPacket_packet = dynamic_cast<const ParcelJoinPacket *>(packet);
        if (ParcelJoinPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelJoinPacket(*ParcelJoinPacket_packet);
    }
};

// ParcelDividePacket
class ParcelDividePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ParcelDividePacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelDividePacket() {
        this->setID(ParcelDivide_ID);
    };
    virtual ~ParcelDividePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDividePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelDividePacket *ParcelDividePacket_packet = dynamic_cast<const ParcelDividePacket *>(packet);
        if (ParcelDividePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelDividePacket(*ParcelDividePacket_packet);
    }
};

// ParcelReleasePacket
class ParcelReleasePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelReleasePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelReleasePacket() {
        this->setID(ParcelRelease_ID);
    };
    virtual ~ParcelReleasePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelReleasePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelReleasePacket *ParcelReleasePacket_packet = dynamic_cast<const ParcelReleasePacket *>(packet);
        if (ParcelReleasePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelReleasePacket(*ParcelReleasePacket_packet);
    }
};

// ParcelBuyPacket
class ParcelBuyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableBool IsGroupOwned;
        SerializableBool RemoveContribution;
        SerializableS32 LocalID;
        SerializableBool Final;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            IsGroupOwned.serialize(buffer);
            RemoveContribution.serialize(buffer);
            LocalID.serialize(buffer);
            Final.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            IsGroupOwned.deserialize(buffer);
            RemoveContribution.deserialize(buffer);
            LocalID.deserialize(buffer);
            Final.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 Price;
        SerializableS32 Area;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Price.serialize(buffer);
            Area.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Price.deserialize(buffer);
            Area.deserialize(buffer);
        }
    };
    // ParcelBuyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    ParcelDataBlock ParcelData;

public:
    ParcelBuyPacket() {
        this->setID(ParcelBuy_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelBuyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelBuyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelBuyPacket *ParcelBuyPacket_packet = dynamic_cast<const ParcelBuyPacket *>(packet);
        if (ParcelBuyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelBuyPacket(*ParcelBuyPacket_packet);
    }
};

// ParcelGodForceOwnerPacket
class ParcelGodForceOwnerPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID OwnerID;
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelGodForceOwnerPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelGodForceOwnerPacket() {
        this->setID(ParcelGodForceOwner_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelGodForceOwnerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelGodForceOwnerPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelGodForceOwnerPacket *ParcelGodForceOwnerPacket_packet = dynamic_cast<const ParcelGodForceOwnerPacket *>(packet);
        if (ParcelGodForceOwnerPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelGodForceOwnerPacket(*ParcelGodForceOwnerPacket_packet);
    }
};

// ParcelAccessListRequestPacket
class ParcelAccessListRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 SequenceID;
        SerializableU32 Flags;
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SequenceID.serialize(buffer);
            Flags.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SequenceID.deserialize(buffer);
            Flags.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelAccessListRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelAccessListRequestPacket() {
        this->setID(ParcelAccessListRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelAccessListRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelAccessListRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelAccessListRequestPacket *ParcelAccessListRequestPacket_packet = dynamic_cast<const ParcelAccessListRequestPacket *>(packet);
        if (ParcelAccessListRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelAccessListRequestPacket(*ParcelAccessListRequestPacket_packet);
    }
};

// ParcelAccessListUpdatePacket
class ParcelAccessListUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU32 Flags;
        SerializableS32 LocalID;
        SerializableUUID TransactionID;
        SerializableS32 SequenceID;
        SerializableS32 Sections;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Flags.serialize(buffer);
            LocalID.serialize(buffer);
            TransactionID.serialize(buffer);
            SequenceID.serialize(buffer);
            Sections.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Flags.deserialize(buffer);
            LocalID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            SequenceID.deserialize(buffer);
            Sections.deserialize(buffer);
        }
    };
    class ListBlock : public PacketSerializable {
    public:
        // ListBlock Member List
        SerializableUUID ID;
        SerializableS32 Time;
        SerializableU32 Flags;
    public:
        ListBlock() {};
        virtual ~ListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Time.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Time.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // ParcelAccessListUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    VariableSerializable<ListBlock> List;
    typedef VariableSerializable<ListBlock> LISTBLOCK_LIST_TYPE;

public:
    ParcelAccessListUpdatePacket() {
        this->setID(ParcelAccessListUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelAccessListUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        List.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        List.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelAccessListUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelAccessListUpdatePacket *ParcelAccessListUpdatePacket_packet = dynamic_cast<const ParcelAccessListUpdatePacket *>(packet);
        if (ParcelAccessListUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelAccessListUpdatePacket(*ParcelAccessListUpdatePacket_packet);
    }
};

// ParcelDwellRequestPacket
class ParcelDwellRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 LocalID;
        SerializableUUID ParcelID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ParcelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ParcelID.deserialize(buffer);
        }
    };
    // ParcelDwellRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelDwellRequestPacket() {
        this->setID(ParcelDwellRequest_ID);
    };
    virtual ~ParcelDwellRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDwellRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelDwellRequestPacket *ParcelDwellRequestPacket_packet = dynamic_cast<const ParcelDwellRequestPacket *>(packet);
        if (ParcelDwellRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelDwellRequestPacket(*ParcelDwellRequestPacket_packet);
    }
};

// ParcelGodMarkAsContentPacket
class ParcelGodMarkAsContentPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelGodMarkAsContentPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelGodMarkAsContentPacket() {
        this->setID(ParcelGodMarkAsContent_ID);
    };
    virtual ~ParcelGodMarkAsContentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelGodMarkAsContentPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ParcelGodMarkAsContentPacket *ParcelGodMarkAsContentPacket_packet = dynamic_cast<const ParcelGodMarkAsContentPacket *>(packet);
        if (ParcelGodMarkAsContentPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ParcelGodMarkAsContentPacket(*ParcelGodMarkAsContentPacket_packet);
    }
};

// ViewerStartAuctionPacket
class ViewerStartAuctionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableUUID SnapshotID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            SnapshotID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            SnapshotID.deserialize(buffer);
        }
    };
    // ViewerStartAuctionPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ViewerStartAuctionPacket() {
        this->setID(ViewerStartAuction_ID);
    };
    virtual ~ViewerStartAuctionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ViewerStartAuctionPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ViewerStartAuctionPacket *ViewerStartAuctionPacket_packet = dynamic_cast<const ViewerStartAuctionPacket *>(packet);
        if (ViewerStartAuctionPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ViewerStartAuctionPacket(*ViewerStartAuctionPacket_packet);
    }
};

// UUIDNameRequestPacket
class UUIDNameRequestPacket : public PacketBase {
public:

    // Block Class List
    class UUIDNameBlockBlock : public PacketSerializable {
    public:
        // UUIDNameBlockBlock Member List
        SerializableUUID ID;
    public:
        UUIDNameBlockBlock() {};
        virtual ~UUIDNameBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // UUIDNameRequestPacket Member List
    VariableSerializable<UUIDNameBlockBlock> UUIDNameBlock;
    typedef VariableSerializable<UUIDNameBlockBlock> UUIDNAMEBLOCKBLOCK_LIST_TYPE;

public:
    UUIDNameRequestPacket() {
        this->setID(UUIDNameRequest_ID);
    };
    virtual ~UUIDNameRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UUIDNameBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UUIDNameBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UUIDNameRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UUIDNameRequestPacket *UUIDNameRequestPacket_packet = dynamic_cast<const UUIDNameRequestPacket *>(packet);
        if (UUIDNameRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UUIDNameRequestPacket(*UUIDNameRequestPacket_packet);
    }
};

// UUIDGroupNameRequestPacket
class UUIDGroupNameRequestPacket : public PacketBase {
public:

    // Block Class List
    class UUIDNameBlockBlock : public PacketSerializable {
    public:
        // UUIDNameBlockBlock Member List
        SerializableUUID ID;
    public:
        UUIDNameBlockBlock() {};
        virtual ~UUIDNameBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // UUIDGroupNameRequestPacket Member List
    VariableSerializable<UUIDNameBlockBlock> UUIDNameBlock;
    typedef VariableSerializable<UUIDNameBlockBlock> UUIDNAMEBLOCKBLOCK_LIST_TYPE;

public:
    UUIDGroupNameRequestPacket() {
        this->setID(UUIDGroupNameRequest_ID);
    };
    virtual ~UUIDGroupNameRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UUIDNameBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UUIDNameBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UUIDGroupNameRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UUIDGroupNameRequestPacket *UUIDGroupNameRequestPacket_packet = dynamic_cast<const UUIDGroupNameRequestPacket *>(packet);
        if (UUIDGroupNameRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UUIDGroupNameRequestPacket(*UUIDGroupNameRequestPacket_packet);
    }
};

// GetScriptRunningPacket
class GetScriptRunningPacket : public PacketBase {
public:

    // Block Class List
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // GetScriptRunningPacket Member List
    ScriptBlock Script;

public:
    GetScriptRunningPacket() {
        this->setID(GetScriptRunning_ID);
    };
    virtual ~GetScriptRunningPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GetScriptRunningPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GetScriptRunningPacket *GetScriptRunningPacket_packet = dynamic_cast<const GetScriptRunningPacket *>(packet);
        if (GetScriptRunningPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GetScriptRunningPacket(*GetScriptRunningPacket_packet);
    }
};

// ScriptRunningReplyPacket
class ScriptRunningReplyPacket : public PacketBase {
public:

    // Block Class List
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
        SerializableBool Running;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
            Running.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
            Running.deserialize(buffer);
        }
    };
    // ScriptRunningReplyPacket Member List
    ScriptBlock Script;

public:
    ScriptRunningReplyPacket() {
        this->setID(ScriptRunningReply_ID);
    };
    virtual ~ScriptRunningReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptRunningReplyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ScriptRunningReplyPacket *ScriptRunningReplyPacket_packet = dynamic_cast<const ScriptRunningReplyPacket *>(packet);
        if (ScriptRunningReplyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ScriptRunningReplyPacket(*ScriptRunningReplyPacket_packet);
    }
};

// SetScriptRunningPacket
class SetScriptRunningPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
        SerializableBool Running;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
            Running.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
            Running.deserialize(buffer);
        }
    };
    // SetScriptRunningPacket Member List
    AgentDataBlock AgentData;
    ScriptBlock Script;

public:
    SetScriptRunningPacket() {
        this->setID(SetScriptRunning_ID);
    };
    virtual ~SetScriptRunningPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetScriptRunningPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SetScriptRunningPacket *SetScriptRunningPacket_packet = dynamic_cast<const SetScriptRunningPacket *>(packet);
        if (SetScriptRunningPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SetScriptRunningPacket(*SetScriptRunningPacket_packet);
    }
};

// ScriptResetPacket
class ScriptResetPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // ScriptResetPacket Member List
    AgentDataBlock AgentData;
    ScriptBlock Script;

public:
    ScriptResetPacket() {
        this->setID(ScriptReset_ID);
    };
    virtual ~ScriptResetPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptResetPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ScriptResetPacket *ScriptResetPacket_packet = dynamic_cast<const ScriptResetPacket *>(packet);
        if (ScriptResetPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ScriptResetPacket(*ScriptResetPacket_packet);
    }
};

// CompleteAgentMovementPacket
class CompleteAgentMovementPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    // CompleteAgentMovementPacket Member List
    AgentDataBlock AgentData;

public:
    CompleteAgentMovementPacket() {
        this->setID(CompleteAgentMovement_ID);
    };
    virtual ~CompleteAgentMovementPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CompleteAgentMovementPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CompleteAgentMovementPacket *CompleteAgentMovementPacket_packet = dynamic_cast<const CompleteAgentMovementPacket *>(packet);
        if (CompleteAgentMovementPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CompleteAgentMovementPacket(*CompleteAgentMovementPacket_packet);
    }
};

// AgentMovementCompletePacket
class AgentMovementCompletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableVector3 Position;
        SerializableVector3 LookAt;
        SerializableU64 RegionHandle;
        SerializableU32 Timestamp;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Position.serialize(buffer);
            LookAt.serialize(buffer);
            RegionHandle.serialize(buffer);
            Timestamp.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            Timestamp.deserialize(buffer);
        }
    };
    class SimDataBlock : public PacketSerializable {
    public:
        // SimDataBlock Member List
        SerializableVariable2 ChannelVersion;
    public:
        SimDataBlock() {};
        virtual ~SimDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ChannelVersion.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ChannelVersion.deserialize(buffer);
        }
    };
    // AgentMovementCompletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    SimDataBlock SimData;

public:
    AgentMovementCompletePacket() {
        this->setID(AgentMovementComplete_ID);
    };
    virtual ~AgentMovementCompletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        SimData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        SimData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentMovementCompletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentMovementCompletePacket *AgentMovementCompletePacket_packet = dynamic_cast<const AgentMovementCompletePacket *>(packet);
        if (AgentMovementCompletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentMovementCompletePacket(*AgentMovementCompletePacket_packet);
    }
};

// LogoutRequestPacket
class LogoutRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // LogoutRequestPacket Member List
    AgentDataBlock AgentData;

public:
    LogoutRequestPacket() {
        this->setID(LogoutRequest_ID);
    };
    virtual ~LogoutRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LogoutRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const LogoutRequestPacket *LogoutRequestPacket_packet = dynamic_cast<const LogoutRequestPacket *>(packet);
        if (LogoutRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new LogoutRequestPacket(*LogoutRequestPacket_packet);
    }
};

// ImprovedInstantMessagePacket
class ImprovedInstantMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MessageBlockBlock : public PacketSerializable {
    public:
        // MessageBlockBlock Member List
        SerializableBool FromGroup;
        SerializableUUID ToAgentID;
        SerializableU32 ParentEstateID;
        SerializableUUID RegionID;
        SerializableVector3 Position;
        SerializableU8 Offline;
        SerializableU8 Dialog;
        SerializableUUID ID;
        SerializableU32 Timestamp;
        SerializableVariable1 FromAgentName;
        SerializableVariable2 Message;
        SerializableVariable2 BinaryBucket;
    public:
        MessageBlockBlock() {};
        virtual ~MessageBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromGroup.serialize(buffer);
            ToAgentID.serialize(buffer);
            ParentEstateID.serialize(buffer);
            RegionID.serialize(buffer);
            Position.serialize(buffer);
            Offline.serialize(buffer);
            Dialog.serialize(buffer);
            ID.serialize(buffer);
            Timestamp.serialize(buffer);
            FromAgentName.serialize(buffer);
            Message.serialize(buffer);
            BinaryBucket.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromGroup.deserialize(buffer);
            ToAgentID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
            RegionID.deserialize(buffer);
            Position.deserialize(buffer);
            Offline.deserialize(buffer);
            Dialog.deserialize(buffer);
            ID.deserialize(buffer);
            Timestamp.deserialize(buffer);
            FromAgentName.deserialize(buffer);
            Message.deserialize(buffer);
            BinaryBucket.deserialize(buffer);
        }
    };
    // ImprovedInstantMessagePacket Member List
    AgentDataBlock AgentData;
    MessageBlockBlock MessageBlock;

public:
    ImprovedInstantMessagePacket() {
        this->setID(ImprovedInstantMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ImprovedInstantMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MessageBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MessageBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ImprovedInstantMessagePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ImprovedInstantMessagePacket *ImprovedInstantMessagePacket_packet = dynamic_cast<const ImprovedInstantMessagePacket *>(packet);
        if (ImprovedInstantMessagePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ImprovedInstantMessagePacket(*ImprovedInstantMessagePacket_packet);
    }
};

// RetrieveInstantMessagesPacket
class RetrieveInstantMessagesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // RetrieveInstantMessagesPacket Member List
    AgentDataBlock AgentData;

public:
    RetrieveInstantMessagesPacket() {
        this->setID(RetrieveInstantMessages_ID);
    };
    virtual ~RetrieveInstantMessagesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RetrieveInstantMessagesPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RetrieveInstantMessagesPacket *RetrieveInstantMessagesPacket_packet = dynamic_cast<const RetrieveInstantMessagesPacket *>(packet);
        if (RetrieveInstantMessagesPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RetrieveInstantMessagesPacket(*RetrieveInstantMessagesPacket_packet);
    }
};

// FindAgentPacket
class FindAgentPacket : public PacketBase {
public:

    // Block Class List
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID Hunter;
        SerializableUUID Prey;
        SerializableIPADDR SpaceIP;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Hunter.serialize(buffer);
            Prey.serialize(buffer);
            SpaceIP.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Hunter.deserialize(buffer);
            Prey.deserialize(buffer);
            SpaceIP.deserialize(buffer);
        }
    };
    class LocationBlockBlock : public PacketSerializable {
    public:
        // LocationBlockBlock Member List
        SerializableF64 GlobalX;
        SerializableF64 GlobalY;
    public:
        LocationBlockBlock() {};
        virtual ~LocationBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GlobalX.serialize(buffer);
            GlobalY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GlobalX.deserialize(buffer);
            GlobalY.deserialize(buffer);
        }
    };
    // FindAgentPacket Member List
    AgentBlockBlock AgentBlock;
    VariableSerializable<LocationBlockBlock> LocationBlock;
    typedef VariableSerializable<LocationBlockBlock> LOCATIONBLOCKBLOCK_LIST_TYPE;

public:
    FindAgentPacket() {
        this->setID(FindAgent_ID);
    };
    virtual ~FindAgentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentBlock.serialize(buffer);
        LocationBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentBlock.deserialize(buffer);
        LocationBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FindAgentPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const FindAgentPacket *FindAgentPacket_packet = dynamic_cast<const FindAgentPacket *>(packet);
        if (FindAgentPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new FindAgentPacket(*FindAgentPacket_packet);
    }
};

// RequestGodlikePowersPacket
class RequestGodlikePowersPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RequestBlockBlock : public PacketSerializable {
    public:
        // RequestBlockBlock Member List
        SerializableBool Godlike;
        SerializableUUID Token;
    public:
        RequestBlockBlock() {};
        virtual ~RequestBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Godlike.serialize(buffer);
            Token.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Godlike.deserialize(buffer);
            Token.deserialize(buffer);
        }
    };
    // RequestGodlikePowersPacket Member List
    AgentDataBlock AgentData;
    RequestBlockBlock RequestBlock;

public:
    RequestGodlikePowersPacket() {
        this->setID(RequestGodlikePowers_ID);
    };
    virtual ~RequestGodlikePowersPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestGodlikePowersPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestGodlikePowersPacket *RequestGodlikePowersPacket_packet = dynamic_cast<const RequestGodlikePowersPacket *>(packet);
        if (RequestGodlikePowersPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestGodlikePowersPacket(*RequestGodlikePowersPacket_packet);
    }
};

// GodlikeMessagePacket
class GodlikeMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class MethodDataBlock : public PacketSerializable {
    public:
        // MethodDataBlock Member List
        SerializableVariable1 Method;
        SerializableUUID Invoice;
    public:
        MethodDataBlock() {};
        virtual ~MethodDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Method.serialize(buffer);
            Invoice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Method.deserialize(buffer);
            Invoice.deserialize(buffer);
        }
    };
    class ParamListBlock : public PacketSerializable {
    public:
        // ParamListBlock Member List
        SerializableVariable1 Parameter;
    public:
        ParamListBlock() {};
        virtual ~ParamListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Parameter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Parameter.deserialize(buffer);
        }
    };
    // GodlikeMessagePacket Member List
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    VariableSerializable<ParamListBlock> ParamList;
    typedef VariableSerializable<ParamListBlock> PARAMLISTBLOCK_LIST_TYPE;

public:
    GodlikeMessagePacket() {
        this->setID(GodlikeMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GodlikeMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MethodData.serialize(buffer);
        ParamList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MethodData.deserialize(buffer);
        ParamList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GodlikeMessagePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GodlikeMessagePacket *GodlikeMessagePacket_packet = dynamic_cast<const GodlikeMessagePacket *>(packet);
        if (GodlikeMessagePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GodlikeMessagePacket(*GodlikeMessagePacket_packet);
    }
};

// EstateOwnerMessagePacket
class EstateOwnerMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class MethodDataBlock : public PacketSerializable {
    public:
        // MethodDataBlock Member List
        SerializableVariable1 Method;
        SerializableUUID Invoice;
    public:
        MethodDataBlock() {};
        virtual ~MethodDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Method.serialize(buffer);
            Invoice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Method.deserialize(buffer);
            Invoice.deserialize(buffer);
        }
    };
    class ParamListBlock : public PacketSerializable {
    public:
        // ParamListBlock Member List
        SerializableVariable1 Parameter;
    public:
        ParamListBlock() {};
        virtual ~ParamListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Parameter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Parameter.deserialize(buffer);
        }
    };
    // EstateOwnerMessagePacket Member List
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    VariableSerializable<ParamListBlock> ParamList;
    typedef VariableSerializable<ParamListBlock> PARAMLISTBLOCK_LIST_TYPE;

public:
    EstateOwnerMessagePacket() {
        this->setID(EstateOwnerMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~EstateOwnerMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MethodData.serialize(buffer);
        ParamList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MethodData.deserialize(buffer);
        ParamList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EstateOwnerMessagePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EstateOwnerMessagePacket *EstateOwnerMessagePacket_packet = dynamic_cast<const EstateOwnerMessagePacket *>(packet);
        if (EstateOwnerMessagePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EstateOwnerMessagePacket(*EstateOwnerMessagePacket_packet);
    }
};

// GenericMessagePacket
class GenericMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class MethodDataBlock : public PacketSerializable {
    public:
        // MethodDataBlock Member List
        SerializableVariable1 Method;
        SerializableUUID Invoice;
    public:
        MethodDataBlock() {};
        virtual ~MethodDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Method.serialize(buffer);
            Invoice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Method.deserialize(buffer);
            Invoice.deserialize(buffer);
        }
    };
    class ParamListBlock : public PacketSerializable {
    public:
        // ParamListBlock Member List
        SerializableVariable1 Parameter;
    public:
        ParamListBlock() {};
        virtual ~ParamListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Parameter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Parameter.deserialize(buffer);
        }
    };
    // GenericMessagePacket Member List
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    VariableSerializable<ParamListBlock> ParamList;
    typedef VariableSerializable<ParamListBlock> PARAMLISTBLOCK_LIST_TYPE;

public:
    GenericMessagePacket() {
        this->setID(GenericMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GenericMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MethodData.serialize(buffer);
        ParamList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MethodData.deserialize(buffer);
        ParamList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GenericMessagePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GenericMessagePacket *GenericMessagePacket_packet = dynamic_cast<const GenericMessagePacket *>(packet);
        if (GenericMessagePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GenericMessagePacket(*GenericMessagePacket_packet);
    }
};

// MuteListRequestPacket
class MuteListRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MuteDataBlock : public PacketSerializable {
    public:
        // MuteDataBlock Member List
        SerializableU32 MuteCRC;
    public:
        MuteDataBlock() {};
        virtual ~MuteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MuteCRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MuteCRC.deserialize(buffer);
        }
    };
    // MuteListRequestPacket Member List
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;

public:
    MuteListRequestPacket() {
        this->setID(MuteListRequest_ID);
    };
    virtual ~MuteListRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MuteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MuteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MuteListRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MuteListRequestPacket *MuteListRequestPacket_packet = dynamic_cast<const MuteListRequestPacket *>(packet);
        if (MuteListRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MuteListRequestPacket(*MuteListRequestPacket_packet);
    }
};

// UpdateMuteListEntryPacket
class UpdateMuteListEntryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MuteDataBlock : public PacketSerializable {
    public:
        // MuteDataBlock Member List
        SerializableUUID MuteID;
        SerializableVariable1 MuteName;
        SerializableS32 MuteType;
        SerializableU32 MuteFlags;
    public:
        MuteDataBlock() {};
        virtual ~MuteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MuteID.serialize(buffer);
            MuteName.serialize(buffer);
            MuteType.serialize(buffer);
            MuteFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MuteID.deserialize(buffer);
            MuteName.deserialize(buffer);
            MuteType.deserialize(buffer);
            MuteFlags.deserialize(buffer);
        }
    };
    // UpdateMuteListEntryPacket Member List
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;

public:
    UpdateMuteListEntryPacket() {
        this->setID(UpdateMuteListEntry_ID);
    };
    virtual ~UpdateMuteListEntryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MuteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MuteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateMuteListEntryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UpdateMuteListEntryPacket *UpdateMuteListEntryPacket_packet = dynamic_cast<const UpdateMuteListEntryPacket *>(packet);
        if (UpdateMuteListEntryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UpdateMuteListEntryPacket(*UpdateMuteListEntryPacket_packet);
    }
};

// RemoveMuteListEntryPacket
class RemoveMuteListEntryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MuteDataBlock : public PacketSerializable {
    public:
        // MuteDataBlock Member List
        SerializableUUID MuteID;
        SerializableVariable1 MuteName;
    public:
        MuteDataBlock() {};
        virtual ~MuteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MuteID.serialize(buffer);
            MuteName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MuteID.deserialize(buffer);
            MuteName.deserialize(buffer);
        }
    };
    // RemoveMuteListEntryPacket Member List
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;

public:
    RemoveMuteListEntryPacket() {
        this->setID(RemoveMuteListEntry_ID);
    };
    virtual ~RemoveMuteListEntryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MuteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MuteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveMuteListEntryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RemoveMuteListEntryPacket *RemoveMuteListEntryPacket_packet = dynamic_cast<const RemoveMuteListEntryPacket *>(packet);
        if (RemoveMuteListEntryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RemoveMuteListEntryPacket(*RemoveMuteListEntryPacket_packet);
    }
};

// CopyInventoryFromNotecardPacket
class CopyInventoryFromNotecardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class NotecardDataBlock : public PacketSerializable {
    public:
        // NotecardDataBlock Member List
        SerializableUUID NotecardItemID;
        SerializableUUID ObjectID;
    public:
        NotecardDataBlock() {};
        virtual ~NotecardDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NotecardItemID.serialize(buffer);
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NotecardItemID.deserialize(buffer);
            ObjectID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
        }
    };
    // CopyInventoryFromNotecardPacket Member List
    AgentDataBlock AgentData;
    NotecardDataBlock NotecardData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    CopyInventoryFromNotecardPacket() {
        this->setID(CopyInventoryFromNotecard_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CopyInventoryFromNotecardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        NotecardData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        NotecardData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CopyInventoryFromNotecardPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CopyInventoryFromNotecardPacket *CopyInventoryFromNotecardPacket_packet = dynamic_cast<const CopyInventoryFromNotecardPacket *>(packet);
        if (CopyInventoryFromNotecardPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CopyInventoryFromNotecardPacket(*CopyInventoryFromNotecardPacket_packet);
    }
};

// UpdateInventoryItemPacket
class UpdateInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableU32 CallbackID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CallbackID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CallbackID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // UpdateInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    UpdateInventoryItemPacket() {
        this->setID(UpdateInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateInventoryItemPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UpdateInventoryItemPacket *UpdateInventoryItemPacket_packet = dynamic_cast<const UpdateInventoryItemPacket *>(packet);
        if (UpdateInventoryItemPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UpdateInventoryItemPacket(*UpdateInventoryItemPacket_packet);
    }
};

// MoveInventoryItemPacket
class MoveInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool Stamp;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Stamp.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Stamp.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableVariable1 NewName;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            NewName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            NewName.deserialize(buffer);
        }
    };
    // MoveInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    MoveInventoryItemPacket() {
        this->setID(MoveInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoveInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoveInventoryItemPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MoveInventoryItemPacket *MoveInventoryItemPacket_packet = dynamic_cast<const MoveInventoryItemPacket *>(packet);
        if (MoveInventoryItemPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MoveInventoryItemPacket(*MoveInventoryItemPacket_packet);
    }
};

// CopyInventoryItemPacket
class CopyInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 CallbackID;
        SerializableUUID OldAgentID;
        SerializableUUID OldItemID;
        SerializableUUID NewFolderID;
        SerializableVariable1 NewName;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CallbackID.serialize(buffer);
            OldAgentID.serialize(buffer);
            OldItemID.serialize(buffer);
            NewFolderID.serialize(buffer);
            NewName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CallbackID.deserialize(buffer);
            OldAgentID.deserialize(buffer);
            OldItemID.deserialize(buffer);
            NewFolderID.deserialize(buffer);
            NewName.deserialize(buffer);
        }
    };
    // CopyInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    CopyInventoryItemPacket() {
        this->setID(CopyInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CopyInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CopyInventoryItemPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CopyInventoryItemPacket *CopyInventoryItemPacket_packet = dynamic_cast<const CopyInventoryItemPacket *>(packet);
        if (CopyInventoryItemPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CopyInventoryItemPacket(*CopyInventoryItemPacket_packet);
    }
};

// RemoveInventoryItemPacket
class RemoveInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
        }
    };
    // RemoveInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    RemoveInventoryItemPacket() {
        this->setID(RemoveInventoryItem_ID);
    };
    virtual ~RemoveInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveInventoryItemPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RemoveInventoryItemPacket *RemoveInventoryItemPacket_packet = dynamic_cast<const RemoveInventoryItemPacket *>(packet);
        if (RemoveInventoryItemPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RemoveInventoryItemPacket(*RemoveInventoryItemPacket_packet);
    }
};

// ChangeInventoryItemFlagsPacket
class ChangeInventoryItemFlagsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableU32 Flags;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // ChangeInventoryItemFlagsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    ChangeInventoryItemFlagsPacket() {
        this->setID(ChangeInventoryItemFlags_ID);
    };
    virtual ~ChangeInventoryItemFlagsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChangeInventoryItemFlagsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ChangeInventoryItemFlagsPacket *ChangeInventoryItemFlagsPacket_packet = dynamic_cast<const ChangeInventoryItemFlagsPacket *>(packet);
        if (ChangeInventoryItemFlagsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ChangeInventoryItemFlagsPacket(*ChangeInventoryItemFlagsPacket_packet);
    }
};

// CreateInventoryFolderPacket
class CreateInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
        SerializableS8 Type;
        SerializableVariable1 Name;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
            Type.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Type.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // CreateInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    FolderDataBlock FolderData;

public:
    CreateInventoryFolderPacket() {
        this->setID(CreateInventoryFolder_ID);
    };
    virtual ~CreateInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateInventoryFolderPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CreateInventoryFolderPacket *CreateInventoryFolderPacket_packet = dynamic_cast<const CreateInventoryFolderPacket *>(packet);
        if (CreateInventoryFolderPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CreateInventoryFolderPacket(*CreateInventoryFolderPacket_packet);
    }
};

// UpdateInventoryFolderPacket
class UpdateInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
        SerializableS8 Type;
        SerializableVariable1 Name;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
            Type.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Type.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // UpdateInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;
    typedef VariableSerializable<FolderDataBlock> FOLDERDATABLOCK_LIST_TYPE;

public:
    UpdateInventoryFolderPacket() {
        this->setID(UpdateInventoryFolder_ID);
    };
    virtual ~UpdateInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateInventoryFolderPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UpdateInventoryFolderPacket *UpdateInventoryFolderPacket_packet = dynamic_cast<const UpdateInventoryFolderPacket *>(packet);
        if (UpdateInventoryFolderPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UpdateInventoryFolderPacket(*UpdateInventoryFolderPacket_packet);
    }
};

// MoveInventoryFolderPacket
class MoveInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool Stamp;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Stamp.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Stamp.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
        }
    };
    // MoveInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    MoveInventoryFolderPacket() {
        this->setID(MoveInventoryFolder_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoveInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoveInventoryFolderPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MoveInventoryFolderPacket *MoveInventoryFolderPacket_packet = dynamic_cast<const MoveInventoryFolderPacket *>(packet);
        if (MoveInventoryFolderPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MoveInventoryFolderPacket(*MoveInventoryFolderPacket_packet);
    }
};

// RemoveInventoryFolderPacket
class RemoveInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // RemoveInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;
    typedef VariableSerializable<FolderDataBlock> FOLDERDATABLOCK_LIST_TYPE;

public:
    RemoveInventoryFolderPacket() {
        this->setID(RemoveInventoryFolder_ID);
    };
    virtual ~RemoveInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveInventoryFolderPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RemoveInventoryFolderPacket *RemoveInventoryFolderPacket_packet = dynamic_cast<const RemoveInventoryFolderPacket *>(packet);
        if (RemoveInventoryFolderPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RemoveInventoryFolderPacket(*RemoveInventoryFolderPacket_packet);
    }
};

// FetchInventoryDescendentsPacket
class FetchInventoryDescendentsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID OwnerID;
        SerializableS32 SortOrder;
        SerializableBool FetchFolders;
        SerializableBool FetchItems;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            OwnerID.serialize(buffer);
            SortOrder.serialize(buffer);
            FetchFolders.serialize(buffer);
            FetchItems.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            SortOrder.deserialize(buffer);
            FetchFolders.deserialize(buffer);
            FetchItems.deserialize(buffer);
        }
    };
    // FetchInventoryDescendentsPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    FetchInventoryDescendentsPacket() {
        this->setID(FetchInventoryDescendents_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~FetchInventoryDescendentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FetchInventoryDescendentsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const FetchInventoryDescendentsPacket *FetchInventoryDescendentsPacket_packet = dynamic_cast<const FetchInventoryDescendentsPacket *>(packet);
        if (FetchInventoryDescendentsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new FetchInventoryDescendentsPacket(*FetchInventoryDescendentsPacket_packet);
    }
};

// FetchInventoryPacket
class FetchInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID OwnerID;
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // FetchInventoryPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    FetchInventoryPacket() {
        this->setID(FetchInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~FetchInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FetchInventoryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const FetchInventoryPacket *FetchInventoryPacket_packet = dynamic_cast<const FetchInventoryPacket *>(packet);
        if (FetchInventoryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new FetchInventoryPacket(*FetchInventoryPacket_packet);
    }
};

// RemoveInventoryObjectsPacket
class RemoveInventoryObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    class ItemDataBlock : public PacketSerializable {
    public:
        // ItemDataBlock Member List
        SerializableUUID ItemID;
    public:
        ItemDataBlock() {};
        virtual ~ItemDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
        }
    };
    // RemoveInventoryObjectsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;
    typedef VariableSerializable<FolderDataBlock> FOLDERDATABLOCK_LIST_TYPE;
    VariableSerializable<ItemDataBlock> ItemData;
    typedef VariableSerializable<ItemDataBlock> ITEMDATABLOCK_LIST_TYPE;

public:
    RemoveInventoryObjectsPacket() {
        this->setID(RemoveInventoryObjects_ID);
    };
    virtual ~RemoveInventoryObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
        ItemData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
        ItemData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveInventoryObjectsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RemoveInventoryObjectsPacket *RemoveInventoryObjectsPacket_packet = dynamic_cast<const RemoveInventoryObjectsPacket *>(packet);
        if (RemoveInventoryObjectsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RemoveInventoryObjectsPacket(*RemoveInventoryObjectsPacket_packet);
    }
};

// PurgeInventoryDescendentsPacket
class PurgeInventoryDescendentsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID FolderID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // PurgeInventoryDescendentsPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    PurgeInventoryDescendentsPacket() {
        this->setID(PurgeInventoryDescendents_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~PurgeInventoryDescendentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PurgeInventoryDescendentsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const PurgeInventoryDescendentsPacket *PurgeInventoryDescendentsPacket_packet = dynamic_cast<const PurgeInventoryDescendentsPacket *>(packet);
        if (PurgeInventoryDescendentsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new PurgeInventoryDescendentsPacket(*PurgeInventoryDescendentsPacket_packet);
    }
};

// UpdateTaskInventoryPacket
class UpdateTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class UpdateDataBlock : public PacketSerializable {
    public:
        // UpdateDataBlock Member List
        SerializableU32 LocalID;
        SerializableU8 Key;
    public:
        UpdateDataBlock() {};
        virtual ~UpdateDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Key.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Key.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // UpdateTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    UpdateDataBlock UpdateData;
    InventoryDataBlock InventoryData;

public:
    UpdateTaskInventoryPacket() {
        this->setID(UpdateTaskInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UpdateData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UpdateData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateTaskInventoryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UpdateTaskInventoryPacket *UpdateTaskInventoryPacket_packet = dynamic_cast<const UpdateTaskInventoryPacket *>(packet);
        if (UpdateTaskInventoryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UpdateTaskInventoryPacket(*UpdateTaskInventoryPacket_packet);
    }
};

// RemoveTaskInventoryPacket
class RemoveTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 LocalID;
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // RemoveTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    RemoveTaskInventoryPacket() {
        this->setID(RemoveTaskInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RemoveTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveTaskInventoryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RemoveTaskInventoryPacket *RemoveTaskInventoryPacket_packet = dynamic_cast<const RemoveTaskInventoryPacket *>(packet);
        if (RemoveTaskInventoryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RemoveTaskInventoryPacket(*RemoveTaskInventoryPacket_packet);
    }
};

// MoveTaskInventoryPacket
class MoveTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID FolderID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            FolderID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 LocalID;
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // MoveTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    MoveTaskInventoryPacket() {
        this->setID(MoveTaskInventory_ID);
    };
    virtual ~MoveTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoveTaskInventoryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MoveTaskInventoryPacket *MoveTaskInventoryPacket_packet = dynamic_cast<const MoveTaskInventoryPacket *>(packet);
        if (MoveTaskInventoryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MoveTaskInventoryPacket(*MoveTaskInventoryPacket_packet);
    }
};

// RequestTaskInventoryPacket
class RequestTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 LocalID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // RequestTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    RequestTaskInventoryPacket() {
        this->setID(RequestTaskInventory_ID);
    };
    virtual ~RequestTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestTaskInventoryPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RequestTaskInventoryPacket *RequestTaskInventoryPacket_packet = dynamic_cast<const RequestTaskInventoryPacket *>(packet);
        if (RequestTaskInventoryPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RequestTaskInventoryPacket(*RequestTaskInventoryPacket_packet);
    }
};

// DeRezObjectPacket
class DeRezObjectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID GroupID;
        SerializableU8 Destination;
        SerializableUUID DestinationID;
        SerializableUUID TransactionID;
        SerializableU8 PacketCount;
        SerializableU8 PacketNumber;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Destination.serialize(buffer);
            DestinationID.serialize(buffer);
            TransactionID.serialize(buffer);
            PacketCount.serialize(buffer);
            PacketNumber.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Destination.deserialize(buffer);
            DestinationID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            PacketCount.deserialize(buffer);
            PacketNumber.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // DeRezObjectPacket Member List
    AgentDataBlock AgentData;
    AgentBlockBlock AgentBlock;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    DeRezObjectPacket() {
        this->setID(DeRezObject_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DeRezObjectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AgentBlock.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AgentBlock.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeRezObjectPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DeRezObjectPacket *DeRezObjectPacket_packet = dynamic_cast<const DeRezObjectPacket *>(packet);
        if (DeRezObjectPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DeRezObjectPacket(*DeRezObjectPacket_packet);
    }
};

// RezObjectPacket
class RezObjectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RezDataBlock : public PacketSerializable {
    public:
        // RezDataBlock Member List
        SerializableUUID FromTaskID;
        SerializableU8 BypassRaycast;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableUUID RayTargetID;
        SerializableBool RayEndIsIntersection;
        SerializableBool RezSelected;
        SerializableBool RemoveItem;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
    public:
        RezDataBlock() {};
        virtual ~RezDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromTaskID.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            RayTargetID.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            RezSelected.serialize(buffer);
            RemoveItem.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromTaskID.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            RezSelected.deserialize(buffer);
            RemoveItem.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // RezObjectPacket Member List
    AgentDataBlock AgentData;
    RezDataBlock RezData;
    InventoryDataBlock InventoryData;

public:
    RezObjectPacket() {
        this->setID(RezObject_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezObjectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RezData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RezData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezObjectPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RezObjectPacket *RezObjectPacket_packet = dynamic_cast<const RezObjectPacket *>(packet);
        if (RezObjectPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RezObjectPacket(*RezObjectPacket_packet);
    }
};

// RezObjectFromNotecardPacket
class RezObjectFromNotecardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RezDataBlock : public PacketSerializable {
    public:
        // RezDataBlock Member List
        SerializableUUID FromTaskID;
        SerializableU8 BypassRaycast;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableUUID RayTargetID;
        SerializableBool RayEndIsIntersection;
        SerializableBool RezSelected;
        SerializableBool RemoveItem;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
    public:
        RezDataBlock() {};
        virtual ~RezDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromTaskID.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            RayTargetID.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            RezSelected.serialize(buffer);
            RemoveItem.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromTaskID.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            RezSelected.deserialize(buffer);
            RemoveItem.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
        }
    };
    class NotecardDataBlock : public PacketSerializable {
    public:
        // NotecardDataBlock Member List
        SerializableUUID NotecardItemID;
        SerializableUUID ObjectID;
    public:
        NotecardDataBlock() {};
        virtual ~NotecardDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NotecardItemID.serialize(buffer);
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NotecardItemID.deserialize(buffer);
            ObjectID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
        }
    };
    // RezObjectFromNotecardPacket Member List
    AgentDataBlock AgentData;
    RezDataBlock RezData;
    NotecardDataBlock NotecardData;
    VariableSerializable<InventoryDataBlock> InventoryData;
    typedef VariableSerializable<InventoryDataBlock> INVENTORYDATABLOCK_LIST_TYPE;

public:
    RezObjectFromNotecardPacket() {
        this->setID(RezObjectFromNotecard_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezObjectFromNotecardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RezData.serialize(buffer);
        NotecardData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RezData.deserialize(buffer);
        NotecardData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezObjectFromNotecardPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RezObjectFromNotecardPacket *RezObjectFromNotecardPacket_packet = dynamic_cast<const RezObjectFromNotecardPacket *>(packet);
        if (RezObjectFromNotecardPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RezObjectFromNotecardPacket(*RezObjectFromNotecardPacket_packet);
    }
};

// AcceptFriendshipPacket
class AcceptFriendshipPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // AcceptFriendshipPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
    VariableSerializable<FolderDataBlock> FolderData;
    typedef VariableSerializable<FolderDataBlock> FOLDERDATABLOCK_LIST_TYPE;

public:
    AcceptFriendshipPacket() {
        this->setID(AcceptFriendship_ID);
    };
    virtual ~AcceptFriendshipPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AcceptFriendshipPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AcceptFriendshipPacket *AcceptFriendshipPacket_packet = dynamic_cast<const AcceptFriendshipPacket *>(packet);
        if (AcceptFriendshipPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AcceptFriendshipPacket(*AcceptFriendshipPacket_packet);
    }
};

// DeclineFriendshipPacket
class DeclineFriendshipPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // DeclineFriendshipPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;

public:
    DeclineFriendshipPacket() {
        this->setID(DeclineFriendship_ID);
    };
    virtual ~DeclineFriendshipPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeclineFriendshipPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DeclineFriendshipPacket *DeclineFriendshipPacket_packet = dynamic_cast<const DeclineFriendshipPacket *>(packet);
        if (DeclineFriendshipPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DeclineFriendshipPacket(*DeclineFriendshipPacket_packet);
    }
};

// TerminateFriendshipPacket
class TerminateFriendshipPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ExBlockBlock : public PacketSerializable {
    public:
        // ExBlockBlock Member List
        SerializableUUID OtherID;
    public:
        ExBlockBlock() {};
        virtual ~ExBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OtherID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OtherID.deserialize(buffer);
        }
    };
    // TerminateFriendshipPacket Member List
    AgentDataBlock AgentData;
    ExBlockBlock ExBlock;

public:
    TerminateFriendshipPacket() {
        this->setID(TerminateFriendship_ID);
    };
    virtual ~TerminateFriendshipPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ExBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ExBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TerminateFriendshipPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const TerminateFriendshipPacket *TerminateFriendshipPacket_packet = dynamic_cast<const TerminateFriendshipPacket *>(packet);
        if (TerminateFriendshipPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new TerminateFriendshipPacket(*TerminateFriendshipPacket_packet);
    }
};

// OfferCallingCardPacket
class OfferCallingCardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID DestID;
        SerializableUUID TransactionID;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            DestID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            DestID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    // OfferCallingCardPacket Member List
    AgentDataBlock AgentData;
    AgentBlockBlock AgentBlock;

public:
    OfferCallingCardPacket() {
        this->setID(OfferCallingCard_ID);
    };
    virtual ~OfferCallingCardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AgentBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AgentBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OfferCallingCardPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const OfferCallingCardPacket *OfferCallingCardPacket_packet = dynamic_cast<const OfferCallingCardPacket *>(packet);
        if (OfferCallingCardPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new OfferCallingCardPacket(*OfferCallingCardPacket_packet);
    }
};

// AcceptCallingCardPacket
class AcceptCallingCardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // AcceptCallingCardPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
    VariableSerializable<FolderDataBlock> FolderData;
    typedef VariableSerializable<FolderDataBlock> FOLDERDATABLOCK_LIST_TYPE;

public:
    AcceptCallingCardPacket() {
        this->setID(AcceptCallingCard_ID);
    };
    virtual ~AcceptCallingCardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AcceptCallingCardPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AcceptCallingCardPacket *AcceptCallingCardPacket_packet = dynamic_cast<const AcceptCallingCardPacket *>(packet);
        if (AcceptCallingCardPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AcceptCallingCardPacket(*AcceptCallingCardPacket_packet);
    }
};

// DeclineCallingCardPacket
class DeclineCallingCardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // DeclineCallingCardPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;

public:
    DeclineCallingCardPacket() {
        this->setID(DeclineCallingCard_ID);
    };
    virtual ~DeclineCallingCardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeclineCallingCardPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DeclineCallingCardPacket *DeclineCallingCardPacket_packet = dynamic_cast<const DeclineCallingCardPacket *>(packet);
        if (DeclineCallingCardPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DeclineCallingCardPacket(*DeclineCallingCardPacket_packet);
    }
};

// RezScriptPacket
class RezScriptPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class UpdateBlockBlock : public PacketSerializable {
    public:
        // UpdateBlockBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableBool Enabled;
    public:
        UpdateBlockBlock() {};
        virtual ~UpdateBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Enabled.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Enabled.deserialize(buffer);
        }
    };
    class InventoryBlockBlock : public PacketSerializable {
    public:
        // InventoryBlockBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryBlockBlock() {};
        virtual ~InventoryBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // RezScriptPacket Member List
    AgentDataBlock AgentData;
    UpdateBlockBlock UpdateBlock;
    InventoryBlockBlock InventoryBlock;

public:
    RezScriptPacket() {
        this->setID(RezScript_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezScriptPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UpdateBlock.serialize(buffer);
        InventoryBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UpdateBlock.deserialize(buffer);
        InventoryBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezScriptPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RezScriptPacket *RezScriptPacket_packet = dynamic_cast<const RezScriptPacket *>(packet);
        if (RezScriptPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RezScriptPacket(*RezScriptPacket_packet);
    }
};

// CreateInventoryItemPacket
class CreateInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryBlockBlock : public PacketSerializable {
    public:
        // InventoryBlockBlock Member List
        SerializableU32 CallbackID;
        SerializableUUID FolderID;
        SerializableUUID TransactionID;
        SerializableU32 NextOwnerMask;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU8 WearableType;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
    public:
        InventoryBlockBlock() {};
        virtual ~InventoryBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CallbackID.serialize(buffer);
            FolderID.serialize(buffer);
            TransactionID.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            WearableType.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CallbackID.deserialize(buffer);
            FolderID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            WearableType.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // CreateInventoryItemPacket Member List
    AgentDataBlock AgentData;
    InventoryBlockBlock InventoryBlock;

public:
    CreateInventoryItemPacket() {
        this->setID(CreateInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CreateInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateInventoryItemPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CreateInventoryItemPacket *CreateInventoryItemPacket_packet = dynamic_cast<const CreateInventoryItemPacket *>(packet);
        if (CreateInventoryItemPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CreateInventoryItemPacket(*CreateInventoryItemPacket_packet);
    }
};

// CreateLandmarkForEventPacket
class CreateLandmarkForEventPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    class InventoryBlockBlock : public PacketSerializable {
    public:
        // InventoryBlockBlock Member List
        SerializableUUID FolderID;
        SerializableVariable1 Name;
    public:
        InventoryBlockBlock() {};
        virtual ~InventoryBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // CreateLandmarkForEventPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;
    InventoryBlockBlock InventoryBlock;

public:
    CreateLandmarkForEventPacket() {
        this->setID(CreateLandmarkForEvent_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CreateLandmarkForEventPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
        InventoryBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
        InventoryBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateLandmarkForEventPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CreateLandmarkForEventPacket *CreateLandmarkForEventPacket_packet = dynamic_cast<const CreateLandmarkForEventPacket *>(packet);
        if (CreateLandmarkForEventPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CreateLandmarkForEventPacket(*CreateLandmarkForEventPacket_packet);
    }
};

// RegionHandleRequestPacket
class RegionHandleRequestPacket : public PacketBase {
public:

    // Block Class List
    class RequestBlockBlock : public PacketSerializable {
    public:
        // RequestBlockBlock Member List
        SerializableUUID RegionID;
    public:
        RequestBlockBlock() {};
        virtual ~RequestBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
        }
    };
    // RegionHandleRequestPacket Member List
    RequestBlockBlock RequestBlock;

public:
    RegionHandleRequestPacket() {
        this->setID(RegionHandleRequest_ID);
    };
    virtual ~RegionHandleRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RequestBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RequestBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionHandleRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RegionHandleRequestPacket *RegionHandleRequestPacket_packet = dynamic_cast<const RegionHandleRequestPacket *>(packet);
        if (RegionHandleRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RegionHandleRequestPacket(*RegionHandleRequestPacket_packet);
    }
};

// MoneyTransferRequestPacket
class MoneyTransferRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID SourceID;
        SerializableUUID DestID;
        SerializableU8 Flags;
        SerializableS32 Amount;
        SerializableU8 AggregatePermNextOwner;
        SerializableU8 AggregatePermInventory;
        SerializableS32 TransactionType;
        SerializableVariable1 Description;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SourceID.serialize(buffer);
            DestID.serialize(buffer);
            Flags.serialize(buffer);
            Amount.serialize(buffer);
            AggregatePermNextOwner.serialize(buffer);
            AggregatePermInventory.serialize(buffer);
            TransactionType.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SourceID.deserialize(buffer);
            DestID.deserialize(buffer);
            Flags.deserialize(buffer);
            Amount.deserialize(buffer);
            AggregatePermNextOwner.deserialize(buffer);
            AggregatePermInventory.deserialize(buffer);
            TransactionType.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // MoneyTransferRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    MoneyTransferRequestPacket() {
        this->setID(MoneyTransferRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoneyTransferRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoneyTransferRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MoneyTransferRequestPacket *MoneyTransferRequestPacket_packet = dynamic_cast<const MoneyTransferRequestPacket *>(packet);
        if (MoneyTransferRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MoneyTransferRequestPacket(*MoneyTransferRequestPacket_packet);
    }
};

// MoneyBalanceRequestPacket
class MoneyBalanceRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID TransactionID;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // MoneyBalanceRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    MoneyBalanceRequestPacket() {
        this->setID(MoneyBalanceRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoneyBalanceRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoneyBalanceRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MoneyBalanceRequestPacket *MoneyBalanceRequestPacket_packet = dynamic_cast<const MoneyBalanceRequestPacket *>(packet);
        if (MoneyBalanceRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MoneyBalanceRequestPacket(*MoneyBalanceRequestPacket_packet);
    }
};

// ActivateGesturesPacket
class ActivateGesturesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID AssetID;
        SerializableU32 GestureFlags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            AssetID.serialize(buffer);
            GestureFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            AssetID.deserialize(buffer);
            GestureFlags.deserialize(buffer);
        }
    };
    // ActivateGesturesPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;
    typedef VariableSerializable<DataBlock> DATABLOCK_LIST_TYPE;

public:
    ActivateGesturesPacket() {
        this->setID(ActivateGestures_ID);
    };
    virtual ~ActivateGesturesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ActivateGesturesPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ActivateGesturesPacket *ActivateGesturesPacket_packet = dynamic_cast<const ActivateGesturesPacket *>(packet);
        if (ActivateGesturesPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ActivateGesturesPacket(*ActivateGesturesPacket_packet);
    }
};

// DeactivateGesturesPacket
class DeactivateGesturesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ItemID;
        SerializableU32 GestureFlags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            GestureFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            GestureFlags.deserialize(buffer);
        }
    };
    // DeactivateGesturesPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;
    typedef VariableSerializable<DataBlock> DATABLOCK_LIST_TYPE;

public:
    DeactivateGesturesPacket() {
        this->setID(DeactivateGestures_ID);
    };
    virtual ~DeactivateGesturesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeactivateGesturesPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DeactivateGesturesPacket *DeactivateGesturesPacket_packet = dynamic_cast<const DeactivateGesturesPacket *>(packet);
        if (DeactivateGesturesPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DeactivateGesturesPacket(*DeactivateGesturesPacket_packet);
    }
};

// UseCachedMuteListPacket
class UseCachedMuteListPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // UseCachedMuteListPacket Member List
    AgentDataBlock AgentData;

public:
    UseCachedMuteListPacket() {
        this->setID(UseCachedMuteList_ID);
    };
    virtual ~UseCachedMuteListPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UseCachedMuteListPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UseCachedMuteListPacket *UseCachedMuteListPacket_packet = dynamic_cast<const UseCachedMuteListPacket *>(packet);
        if (UseCachedMuteListPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UseCachedMuteListPacket(*UseCachedMuteListPacket_packet);
    }
};

// GrantUserRightsPacket
class GrantUserRightsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RightsBlock : public PacketSerializable {
    public:
        // RightsBlock Member List
        SerializableUUID AgentRelated;
        SerializableS32 RelatedRights;
    public:
        RightsBlock() {};
        virtual ~RightsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentRelated.serialize(buffer);
            RelatedRights.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentRelated.deserialize(buffer);
            RelatedRights.deserialize(buffer);
        }
    };
    // GrantUserRightsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RightsBlock> Rights;
    typedef VariableSerializable<RightsBlock> RIGHTSBLOCK_LIST_TYPE;

public:
    GrantUserRightsPacket() {
        this->setID(GrantUserRights_ID);
    };
    virtual ~GrantUserRightsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Rights.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Rights.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GrantUserRightsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GrantUserRightsPacket *GrantUserRightsPacket_packet = dynamic_cast<const GrantUserRightsPacket *>(packet);
        if (GrantUserRightsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GrantUserRightsPacket(*GrantUserRightsPacket_packet);
    }
};

// SetStartLocationRequestPacket
class SetStartLocationRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class StartLocationDataBlock : public PacketSerializable {
    public:
        // StartLocationDataBlock Member List
        SerializableVariable1 SimName;
        SerializableU32 LocationID;
        SerializableVector3 LocationPos;
        SerializableVector3 LocationLookAt;
    public:
        StartLocationDataBlock() {};
        virtual ~StartLocationDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            LocationID.serialize(buffer);
            LocationPos.serialize(buffer);
            LocationLookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            LocationID.deserialize(buffer);
            LocationPos.deserialize(buffer);
            LocationLookAt.deserialize(buffer);
        }
    };
    // SetStartLocationRequestPacket Member List
    AgentDataBlock AgentData;
    StartLocationDataBlock StartLocationData;

public:
    SetStartLocationRequestPacket() {
        this->setID(SetStartLocationRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~SetStartLocationRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        StartLocationData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        StartLocationData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetStartLocationRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SetStartLocationRequestPacket *SetStartLocationRequestPacket_packet = dynamic_cast<const SetStartLocationRequestPacket *>(packet);
        if (SetStartLocationRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SetStartLocationRequestPacket(*SetStartLocationRequestPacket_packet);
    }
};

// NetTestPacket
class NetTestPacket : public PacketBase {
public:

    // Block Class List
    class NetBlockBlock : public PacketSerializable {
    public:
        // NetBlockBlock Member List
        SerializableIPPORT Port;
    public:
        NetBlockBlock() {};
        virtual ~NetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Port.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Port.deserialize(buffer);
        }
    };
    // NetTestPacket Member List
    NetBlockBlock NetBlock;

public:
    NetTestPacket() {
        this->setID(NetTest_ID);
    };
    virtual ~NetTestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        NetBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        NetBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new NetTestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const NetTestPacket *NetTestPacket_packet = dynamic_cast<const NetTestPacket *>(packet);
        if (NetTestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new NetTestPacket(*NetTestPacket_packet);
    }
};

// SetCPURatioPacket
class SetCPURatioPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU8 Ratio;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Ratio.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Ratio.deserialize(buffer);
        }
    };
    // SetCPURatioPacket Member List
    DataBlock Data;

public:
    SetCPURatioPacket() {
        this->setID(SetCPURatio_ID);
    };
    virtual ~SetCPURatioPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetCPURatioPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SetCPURatioPacket *SetCPURatioPacket_packet = dynamic_cast<const SetCPURatioPacket *>(packet);
        if (SetCPURatioPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SetCPURatioPacket(*SetCPURatioPacket_packet);
    }
};

// SimCrashedPacket
class SimCrashedPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU32 RegionX;
        SerializableU32 RegionY;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionX.serialize(buffer);
            RegionY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionX.deserialize(buffer);
            RegionY.deserialize(buffer);
        }
    };
    class UsersBlock : public PacketSerializable {
    public:
        // UsersBlock Member List
        SerializableUUID AgentID;
    public:
        UsersBlock() {};
        virtual ~UsersBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // SimCrashedPacket Member List
    DataBlock Data;
    VariableSerializable<UsersBlock> Users;
    typedef VariableSerializable<UsersBlock> USERSBLOCK_LIST_TYPE;

public:
    SimCrashedPacket() {
        this->setID(SimCrashed_ID);
    };
    virtual ~SimCrashedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
        Users.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
        Users.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimCrashedPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SimCrashedPacket *SimCrashedPacket_packet = dynamic_cast<const SimCrashedPacket *>(packet);
        if (SimCrashedPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SimCrashedPacket(*SimCrashedPacket_packet);
    }
};

// RemoveAttachmentPacket
class RemoveAttachmentPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AttachmentBlockBlock : public PacketSerializable {
    public:
        // AttachmentBlockBlock Member List
        SerializableU8 AttachmentPoint;
        SerializableUUID ItemID;
    public:
        AttachmentBlockBlock() {};
        virtual ~AttachmentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AttachmentPoint.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AttachmentPoint.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // RemoveAttachmentPacket Member List
    AgentDataBlock AgentData;
    AttachmentBlockBlock AttachmentBlock;

public:
    RemoveAttachmentPacket() {
        this->setID(RemoveAttachment_ID);
    };
    virtual ~RemoveAttachmentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AttachmentBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AttachmentBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveAttachmentPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RemoveAttachmentPacket *RemoveAttachmentPacket_packet = dynamic_cast<const RemoveAttachmentPacket *>(packet);
        if (RemoveAttachmentPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RemoveAttachmentPacket(*RemoveAttachmentPacket_packet);
    }
};

// SoundTriggerPacket
class SoundTriggerPacket : public PacketBase {
public:

    // Block Class List
    class SoundDataBlock : public PacketSerializable {
    public:
        // SoundDataBlock Member List
        SerializableUUID SoundID;
        SerializableUUID OwnerID;
        SerializableUUID ObjectID;
        SerializableUUID ParentID;
        SerializableU64 Handle;
        SerializableVector3 Position;
        SerializableF32 Gain;
    public:
        SoundDataBlock() {};
        virtual ~SoundDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SoundID.serialize(buffer);
            OwnerID.serialize(buffer);
            ObjectID.serialize(buffer);
            ParentID.serialize(buffer);
            Handle.serialize(buffer);
            Position.serialize(buffer);
            Gain.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SoundID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            ObjectID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Handle.deserialize(buffer);
            Position.deserialize(buffer);
            Gain.deserialize(buffer);
        }
    };
    // SoundTriggerPacket Member List
    SoundDataBlock SoundData;

public:
    SoundTriggerPacket() {
        this->setID(SoundTrigger_ID);
    };
    virtual ~SoundTriggerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SoundData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SoundData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SoundTriggerPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SoundTriggerPacket *SoundTriggerPacket_packet = dynamic_cast<const SoundTriggerPacket *>(packet);
        if (SoundTriggerPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SoundTriggerPacket(*SoundTriggerPacket_packet);
    }
};

// AssetUploadRequestPacket
class AssetUploadRequestPacket : public PacketBase {
public:

    // Block Class List
    class AssetBlockBlock : public PacketSerializable {
    public:
        // AssetBlockBlock Member List
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableBool Tempfile;
        SerializableBool StoreLocal;
        SerializableVariable2 AssetData;
    public:
        AssetBlockBlock() {};
        virtual ~AssetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            Tempfile.serialize(buffer);
            StoreLocal.serialize(buffer);
            AssetData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            Tempfile.deserialize(buffer);
            StoreLocal.deserialize(buffer);
            AssetData.deserialize(buffer);
        }
    };
    // AssetUploadRequestPacket Member List
    AssetBlockBlock AssetBlock;

public:
    AssetUploadRequestPacket() {
        this->setID(AssetUploadRequest_ID);
    };
    virtual ~AssetUploadRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AssetBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AssetBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AssetUploadRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AssetUploadRequestPacket *AssetUploadRequestPacket_packet = dynamic_cast<const AssetUploadRequestPacket *>(packet);
        if (AssetUploadRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AssetUploadRequestPacket(*AssetUploadRequestPacket_packet);
    }
};

// AssetUploadCompletePacket
class AssetUploadCompletePacket : public PacketBase {
public:

    // Block Class List
    class AssetBlockBlock : public PacketSerializable {
    public:
        // AssetBlockBlock Member List
        SerializableUUID UUID;
        SerializableS8 Type;
        SerializableBool Success;
    public:
        AssetBlockBlock() {};
        virtual ~AssetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UUID.serialize(buffer);
            Type.serialize(buffer);
            Success.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UUID.deserialize(buffer);
            Type.deserialize(buffer);
            Success.deserialize(buffer);
        }
    };
    // AssetUploadCompletePacket Member List
    AssetBlockBlock AssetBlock;

public:
    AssetUploadCompletePacket() {
        this->setID(AssetUploadComplete_ID);
    };
    virtual ~AssetUploadCompletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AssetBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AssetBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AssetUploadCompletePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AssetUploadCompletePacket *AssetUploadCompletePacket_packet = dynamic_cast<const AssetUploadCompletePacket *>(packet);
        if (AssetUploadCompletePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AssetUploadCompletePacket(*AssetUploadCompletePacket_packet);
    }
};

// CreateGroupRequestPacket
class CreateGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableVariable1 Name;
        SerializableVariable2 Charter;
        SerializableBool ShowInList;
        SerializableUUID InsigniaID;
        SerializableS32 MembershipFee;
        SerializableBool OpenEnrollment;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Name.serialize(buffer);
            Charter.serialize(buffer);
            ShowInList.serialize(buffer);
            InsigniaID.serialize(buffer);
            MembershipFee.serialize(buffer);
            OpenEnrollment.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Name.deserialize(buffer);
            Charter.deserialize(buffer);
            ShowInList.deserialize(buffer);
            InsigniaID.deserialize(buffer);
            MembershipFee.deserialize(buffer);
            OpenEnrollment.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
        }
    };
    // CreateGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    CreateGroupRequestPacket() {
        this->setID(CreateGroupRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CreateGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateGroupRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CreateGroupRequestPacket *CreateGroupRequestPacket_packet = dynamic_cast<const CreateGroupRequestPacket *>(packet);
        if (CreateGroupRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CreateGroupRequestPacket(*CreateGroupRequestPacket_packet);
    }
};

// UpdateGroupInfoPacket
class UpdateGroupInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableVariable2 Charter;
        SerializableBool ShowInList;
        SerializableUUID InsigniaID;
        SerializableS32 MembershipFee;
        SerializableBool OpenEnrollment;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Charter.serialize(buffer);
            ShowInList.serialize(buffer);
            InsigniaID.serialize(buffer);
            MembershipFee.serialize(buffer);
            OpenEnrollment.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Charter.deserialize(buffer);
            ShowInList.deserialize(buffer);
            InsigniaID.deserialize(buffer);
            MembershipFee.deserialize(buffer);
            OpenEnrollment.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
        }
    };
    // UpdateGroupInfoPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    UpdateGroupInfoPacket() {
        this->setID(UpdateGroupInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateGroupInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateGroupInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UpdateGroupInfoPacket *UpdateGroupInfoPacket_packet = dynamic_cast<const UpdateGroupInfoPacket *>(packet);
        if (UpdateGroupInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UpdateGroupInfoPacket(*UpdateGroupInfoPacket_packet);
    }
};

// GroupRoleChangesPacket
class GroupRoleChangesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RoleChangeBlock : public PacketSerializable {
    public:
        // RoleChangeBlock Member List
        SerializableUUID RoleID;
        SerializableUUID MemberID;
        SerializableU32 Change;
    public:
        RoleChangeBlock() {};
        virtual ~RoleChangeBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RoleID.serialize(buffer);
            MemberID.serialize(buffer);
            Change.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RoleID.deserialize(buffer);
            MemberID.deserialize(buffer);
            Change.deserialize(buffer);
        }
    };
    // GroupRoleChangesPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RoleChangeBlock> RoleChange;
    typedef VariableSerializable<RoleChangeBlock> ROLECHANGEBLOCK_LIST_TYPE;

public:
    GroupRoleChangesPacket() {
        this->setID(GroupRoleChanges_ID);
    };
    virtual ~GroupRoleChangesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RoleChange.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RoleChange.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleChangesPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupRoleChangesPacket *GroupRoleChangesPacket_packet = dynamic_cast<const GroupRoleChangesPacket *>(packet);
        if (GroupRoleChangesPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupRoleChangesPacket(*GroupRoleChangesPacket_packet);
    }
};

// JoinGroupRequestPacket
class JoinGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // JoinGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    JoinGroupRequestPacket() {
        this->setID(JoinGroupRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~JoinGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new JoinGroupRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const JoinGroupRequestPacket *JoinGroupRequestPacket_packet = dynamic_cast<const JoinGroupRequestPacket *>(packet);
        if (JoinGroupRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new JoinGroupRequestPacket(*JoinGroupRequestPacket_packet);
    }
};

// EjectGroupMemberRequestPacket
class EjectGroupMemberRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class EjectDataBlock : public PacketSerializable {
    public:
        // EjectDataBlock Member List
        SerializableUUID EjecteeID;
    public:
        EjectDataBlock() {};
        virtual ~EjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EjecteeID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EjecteeID.deserialize(buffer);
        }
    };
    // EjectGroupMemberRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    VariableSerializable<EjectDataBlock> EjectData;
    typedef VariableSerializable<EjectDataBlock> EJECTDATABLOCK_LIST_TYPE;

public:
    EjectGroupMemberRequestPacket() {
        this->setID(EjectGroupMemberRequest_ID);
    };
    virtual ~EjectGroupMemberRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        EjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        EjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EjectGroupMemberRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const EjectGroupMemberRequestPacket *EjectGroupMemberRequestPacket_packet = dynamic_cast<const EjectGroupMemberRequestPacket *>(packet);
        if (EjectGroupMemberRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new EjectGroupMemberRequestPacket(*EjectGroupMemberRequestPacket_packet);
    }
};

// LeaveGroupRequestPacket
class LeaveGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // LeaveGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    LeaveGroupRequestPacket() {
        this->setID(LeaveGroupRequest_ID);
    };
    virtual ~LeaveGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LeaveGroupRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const LeaveGroupRequestPacket *LeaveGroupRequestPacket_packet = dynamic_cast<const LeaveGroupRequestPacket *>(packet);
        if (LeaveGroupRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new LeaveGroupRequestPacket(*LeaveGroupRequestPacket_packet);
    }
};

// InviteGroupRequestPacket
class InviteGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class InviteDataBlock : public PacketSerializable {
    public:
        // InviteDataBlock Member List
        SerializableUUID InviteeID;
        SerializableUUID RoleID;
    public:
        InviteDataBlock() {};
        virtual ~InviteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            InviteeID.serialize(buffer);
            RoleID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            InviteeID.deserialize(buffer);
            RoleID.deserialize(buffer);
        }
    };
    // InviteGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    VariableSerializable<InviteDataBlock> InviteData;
    typedef VariableSerializable<InviteDataBlock> INVITEDATABLOCK_LIST_TYPE;

public:
    InviteGroupRequestPacket() {
        this->setID(InviteGroupRequest_ID);
    };
    virtual ~InviteGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        InviteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        InviteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InviteGroupRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const InviteGroupRequestPacket *InviteGroupRequestPacket_packet = dynamic_cast<const InviteGroupRequestPacket *>(packet);
        if (InviteGroupRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new InviteGroupRequestPacket(*InviteGroupRequestPacket_packet);
    }
};

// GroupProfileRequestPacket
class GroupProfileRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // GroupProfileRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupProfileRequestPacket() {
        this->setID(GroupProfileRequest_ID);
    };
    virtual ~GroupProfileRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupProfileRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupProfileRequestPacket *GroupProfileRequestPacket_packet = dynamic_cast<const GroupProfileRequestPacket *>(packet);
        if (GroupProfileRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupProfileRequestPacket(*GroupProfileRequestPacket_packet);
    }
};

// GroupAccountSummaryRequestPacket
class GroupAccountSummaryRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
        }
    };
    // GroupAccountSummaryRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    GroupAccountSummaryRequestPacket() {
        this->setID(GroupAccountSummaryRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountSummaryRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountSummaryRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupAccountSummaryRequestPacket *GroupAccountSummaryRequestPacket_packet = dynamic_cast<const GroupAccountSummaryRequestPacket *>(packet);
        if (GroupAccountSummaryRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupAccountSummaryRequestPacket(*GroupAccountSummaryRequestPacket_packet);
    }
};

// GroupAccountDetailsRequestPacket
class GroupAccountDetailsRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
        }
    };
    // GroupAccountDetailsRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    GroupAccountDetailsRequestPacket() {
        this->setID(GroupAccountDetailsRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountDetailsRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountDetailsRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupAccountDetailsRequestPacket *GroupAccountDetailsRequestPacket_packet = dynamic_cast<const GroupAccountDetailsRequestPacket *>(packet);
        if (GroupAccountDetailsRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupAccountDetailsRequestPacket(*GroupAccountDetailsRequestPacket_packet);
    }
};

// GroupAccountTransactionsRequestPacket
class GroupAccountTransactionsRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
        }
    };
    // GroupAccountTransactionsRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    GroupAccountTransactionsRequestPacket() {
        this->setID(GroupAccountTransactionsRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountTransactionsRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountTransactionsRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupAccountTransactionsRequestPacket *GroupAccountTransactionsRequestPacket_packet = dynamic_cast<const GroupAccountTransactionsRequestPacket *>(packet);
        if (GroupAccountTransactionsRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupAccountTransactionsRequestPacket(*GroupAccountTransactionsRequestPacket_packet);
    }
};

// GroupActiveProposalsRequestPacket
class GroupActiveProposalsRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // GroupActiveProposalsRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    TransactionDataBlock TransactionData;

public:
    GroupActiveProposalsRequestPacket() {
        this->setID(GroupActiveProposalsRequest_ID);
    };
    virtual ~GroupActiveProposalsRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        TransactionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        TransactionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupActiveProposalsRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupActiveProposalsRequestPacket *GroupActiveProposalsRequestPacket_packet = dynamic_cast<const GroupActiveProposalsRequestPacket *>(packet);
        if (GroupActiveProposalsRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupActiveProposalsRequestPacket(*GroupActiveProposalsRequestPacket_packet);
    }
};

// GroupVoteHistoryRequestPacket
class GroupVoteHistoryRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // GroupVoteHistoryRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    TransactionDataBlock TransactionData;

public:
    GroupVoteHistoryRequestPacket() {
        this->setID(GroupVoteHistoryRequest_ID);
    };
    virtual ~GroupVoteHistoryRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        TransactionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        TransactionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupVoteHistoryRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupVoteHistoryRequestPacket *GroupVoteHistoryRequestPacket_packet = dynamic_cast<const GroupVoteHistoryRequestPacket *>(packet);
        if (GroupVoteHistoryRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupVoteHistoryRequestPacket(*GroupVoteHistoryRequestPacket_packet);
    }
};

// StartGroupProposalPacket
class StartGroupProposalPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ProposalDataBlock : public PacketSerializable {
    public:
        // ProposalDataBlock Member List
        SerializableUUID GroupID;
        SerializableS32 Quorum;
        SerializableF32 Majority;
        SerializableS32 Duration;
        SerializableVariable1 ProposalText;
    public:
        ProposalDataBlock() {};
        virtual ~ProposalDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Quorum.serialize(buffer);
            Majority.serialize(buffer);
            Duration.serialize(buffer);
            ProposalText.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Quorum.deserialize(buffer);
            Majority.deserialize(buffer);
            Duration.deserialize(buffer);
            ProposalText.deserialize(buffer);
        }
    };
    // StartGroupProposalPacket Member List
    AgentDataBlock AgentData;
    ProposalDataBlock ProposalData;

public:
    StartGroupProposalPacket() {
        this->setID(StartGroupProposal_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~StartGroupProposalPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ProposalData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ProposalData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StartGroupProposalPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const StartGroupProposalPacket *StartGroupProposalPacket_packet = dynamic_cast<const StartGroupProposalPacket *>(packet);
        if (StartGroupProposalPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new StartGroupProposalPacket(*StartGroupProposalPacket_packet);
    }
};

// GroupProposalBallotPacket
class GroupProposalBallotPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ProposalDataBlock : public PacketSerializable {
    public:
        // ProposalDataBlock Member List
        SerializableUUID ProposalID;
        SerializableUUID GroupID;
        SerializableVariable1 VoteCast;
    public:
        ProposalDataBlock() {};
        virtual ~ProposalDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ProposalID.serialize(buffer);
            GroupID.serialize(buffer);
            VoteCast.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ProposalID.deserialize(buffer);
            GroupID.deserialize(buffer);
            VoteCast.deserialize(buffer);
        }
    };
    // GroupProposalBallotPacket Member List
    AgentDataBlock AgentData;
    ProposalDataBlock ProposalData;

public:
    GroupProposalBallotPacket() {
        this->setID(GroupProposalBallot_ID);
    };
    virtual ~GroupProposalBallotPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ProposalData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ProposalData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupProposalBallotPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupProposalBallotPacket *GroupProposalBallotPacket_packet = dynamic_cast<const GroupProposalBallotPacket *>(packet);
        if (GroupProposalBallotPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupProposalBallotPacket(*GroupProposalBallotPacket_packet);
    }
};

// GroupMembersRequestPacket
class GroupMembersRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupMembersRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupMembersRequestPacket() {
        this->setID(GroupMembersRequest_ID);
    };
    virtual ~GroupMembersRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupMembersRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupMembersRequestPacket *GroupMembersRequestPacket_packet = dynamic_cast<const GroupMembersRequestPacket *>(packet);
        if (GroupMembersRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupMembersRequestPacket(*GroupMembersRequestPacket_packet);
    }
};

// ActivateGroupPacket
class ActivateGroupPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    // ActivateGroupPacket Member List
    AgentDataBlock AgentData;

public:
    ActivateGroupPacket() {
        this->setID(ActivateGroup_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ActivateGroupPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ActivateGroupPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ActivateGroupPacket *ActivateGroupPacket_packet = dynamic_cast<const ActivateGroupPacket *>(packet);
        if (ActivateGroupPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ActivateGroupPacket(*ActivateGroupPacket_packet);
    }
};

// SetGroupContributionPacket
class SetGroupContributionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableS32 Contribution;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Contribution.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Contribution.deserialize(buffer);
        }
    };
    // SetGroupContributionPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    SetGroupContributionPacket() {
        this->setID(SetGroupContribution_ID);
    };
    virtual ~SetGroupContributionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetGroupContributionPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SetGroupContributionPacket *SetGroupContributionPacket_packet = dynamic_cast<const SetGroupContributionPacket *>(packet);
        if (SetGroupContributionPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SetGroupContributionPacket(*SetGroupContributionPacket_packet);
    }
};

// SetGroupAcceptNoticesPacket
class SetGroupAcceptNoticesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableBool AcceptNotices;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            AcceptNotices.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            AcceptNotices.deserialize(buffer);
        }
    };
    class NewDataBlock : public PacketSerializable {
    public:
        // NewDataBlock Member List
        SerializableBool ListInProfile;
    public:
        NewDataBlock() {};
        virtual ~NewDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ListInProfile.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ListInProfile.deserialize(buffer);
        }
    };
    // SetGroupAcceptNoticesPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    NewDataBlock NewData;

public:
    SetGroupAcceptNoticesPacket() {
        this->setID(SetGroupAcceptNotices_ID);
    };
    virtual ~SetGroupAcceptNoticesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        NewData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        NewData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetGroupAcceptNoticesPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SetGroupAcceptNoticesPacket *SetGroupAcceptNoticesPacket_packet = dynamic_cast<const SetGroupAcceptNoticesPacket *>(packet);
        if (SetGroupAcceptNoticesPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SetGroupAcceptNoticesPacket(*SetGroupAcceptNoticesPacket_packet);
    }
};

// GroupRoleDataRequestPacket
class GroupRoleDataRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupRoleDataRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupRoleDataRequestPacket() {
        this->setID(GroupRoleDataRequest_ID);
    };
    virtual ~GroupRoleDataRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleDataRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupRoleDataRequestPacket *GroupRoleDataRequestPacket_packet = dynamic_cast<const GroupRoleDataRequestPacket *>(packet);
        if (GroupRoleDataRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupRoleDataRequestPacket(*GroupRoleDataRequestPacket_packet);
    }
};

// GroupRoleMembersRequestPacket
class GroupRoleMembersRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupRoleMembersRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupRoleMembersRequestPacket() {
        this->setID(GroupRoleMembersRequest_ID);
    };
    virtual ~GroupRoleMembersRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleMembersRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupRoleMembersRequestPacket *GroupRoleMembersRequestPacket_packet = dynamic_cast<const GroupRoleMembersRequestPacket *>(packet);
        if (GroupRoleMembersRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupRoleMembersRequestPacket(*GroupRoleMembersRequestPacket_packet);
    }
};

// GroupTitlesRequestPacket
class GroupTitlesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupTitlesRequestPacket Member List
    AgentDataBlock AgentData;

public:
    GroupTitlesRequestPacket() {
        this->setID(GroupTitlesRequest_ID);
    };
    virtual ~GroupTitlesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupTitlesRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupTitlesRequestPacket *GroupTitlesRequestPacket_packet = dynamic_cast<const GroupTitlesRequestPacket *>(packet);
        if (GroupTitlesRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupTitlesRequestPacket(*GroupTitlesRequestPacket_packet);
    }
};

// GroupTitleUpdatePacket
class GroupTitleUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableUUID TitleRoleID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            TitleRoleID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            TitleRoleID.deserialize(buffer);
        }
    };
    // GroupTitleUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    GroupTitleUpdatePacket() {
        this->setID(GroupTitleUpdate_ID);
    };
    virtual ~GroupTitleUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupTitleUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupTitleUpdatePacket *GroupTitleUpdatePacket_packet = dynamic_cast<const GroupTitleUpdatePacket *>(packet);
        if (GroupTitleUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupTitleUpdatePacket(*GroupTitleUpdatePacket_packet);
    }
};

// GroupRoleUpdatePacket
class GroupRoleUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RoleDataBlock : public PacketSerializable {
    public:
        // RoleDataBlock Member List
        SerializableUUID RoleID;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableVariable1 Title;
        SerializableU64 Powers;
        SerializableU8 UpdateType;
    public:
        RoleDataBlock() {};
        virtual ~RoleDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RoleID.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            Title.serialize(buffer);
            Powers.serialize(buffer);
            UpdateType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RoleID.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            Title.deserialize(buffer);
            Powers.deserialize(buffer);
            UpdateType.deserialize(buffer);
        }
    };
    // GroupRoleUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RoleDataBlock> RoleData;
    typedef VariableSerializable<RoleDataBlock> ROLEDATABLOCK_LIST_TYPE;

public:
    GroupRoleUpdatePacket() {
        this->setID(GroupRoleUpdate_ID);
    };
    virtual ~GroupRoleUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RoleData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RoleData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleUpdatePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const GroupRoleUpdatePacket *GroupRoleUpdatePacket_packet = dynamic_cast<const GroupRoleUpdatePacket *>(packet);
        if (GroupRoleUpdatePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new GroupRoleUpdatePacket(*GroupRoleUpdatePacket_packet);
    }
};

// AgentWearablesRequestPacket
class AgentWearablesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // AgentWearablesRequestPacket Member List
    AgentDataBlock AgentData;

public:
    AgentWearablesRequestPacket() {
        this->setID(AgentWearablesRequest_ID);
    };
    virtual ~AgentWearablesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentWearablesRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentWearablesRequestPacket *AgentWearablesRequestPacket_packet = dynamic_cast<const AgentWearablesRequestPacket *>(packet);
        if (AgentWearablesRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentWearablesRequestPacket(*AgentWearablesRequestPacket_packet);
    }
};

// AgentIsNowWearingPacket
class AgentIsNowWearingPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID ItemID;
        SerializableU8 WearableType;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            WearableType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            WearableType.deserialize(buffer);
        }
    };
    // AgentIsNowWearingPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;
    typedef VariableSerializable<WearableDataBlock> WEARABLEDATABLOCK_LIST_TYPE;

public:
    AgentIsNowWearingPacket() {
        this->setID(AgentIsNowWearing_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentIsNowWearingPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentIsNowWearingPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentIsNowWearingPacket *AgentIsNowWearingPacket_packet = dynamic_cast<const AgentIsNowWearingPacket *>(packet);
        if (AgentIsNowWearingPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentIsNowWearingPacket(*AgentIsNowWearingPacket_packet);
    }
};

// AgentCachedTexturePacket
class AgentCachedTexturePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableS32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID ID;
        SerializableU8 TextureIndex;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            TextureIndex.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            TextureIndex.deserialize(buffer);
        }
    };
    // AgentCachedTexturePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;
    typedef VariableSerializable<WearableDataBlock> WEARABLEDATABLOCK_LIST_TYPE;

public:
    AgentCachedTexturePacket() {
        this->setID(AgentCachedTexture_ID);
    };
    virtual ~AgentCachedTexturePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentCachedTexturePacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentCachedTexturePacket *AgentCachedTexturePacket_packet = dynamic_cast<const AgentCachedTexturePacket *>(packet);
        if (AgentCachedTexturePacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentCachedTexturePacket(*AgentCachedTexturePacket_packet);
    }
};

// AgentDataUpdateRequestPacket
class AgentDataUpdateRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // AgentDataUpdateRequestPacket Member List
    AgentDataBlock AgentData;

public:
    AgentDataUpdateRequestPacket() {
        this->setID(AgentDataUpdateRequest_ID);
    };
    virtual ~AgentDataUpdateRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentDataUpdateRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const AgentDataUpdateRequestPacket *AgentDataUpdateRequestPacket_packet = dynamic_cast<const AgentDataUpdateRequestPacket *>(packet);
        if (AgentDataUpdateRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new AgentDataUpdateRequestPacket(*AgentDataUpdateRequestPacket_packet);
    }
};

// ViewerEffectPacket
class ViewerEffectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EffectBlock : public PacketSerializable {
    public:
        // EffectBlock Member List
        SerializableUUID ID;
        SerializableUUID AgentID;
        SerializableU8 Type;
        SerializableF32 Duration;
        SerializableFixed<4> Color;
        SerializableVariable1 TypeData;
    public:
        EffectBlock() {};
        virtual ~EffectBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            AgentID.serialize(buffer);
            Type.serialize(buffer);
            Duration.serialize(buffer);
            Color.serialize(buffer);
            TypeData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            AgentID.deserialize(buffer);
            Type.deserialize(buffer);
            Duration.deserialize(buffer);
            Color.deserialize(buffer);
            TypeData.deserialize(buffer);
        }
    };
    // ViewerEffectPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<EffectBlock> Effect;
    typedef VariableSerializable<EffectBlock> EFFECTBLOCK_LIST_TYPE;

public:
    ViewerEffectPacket() {
        this->setID(ViewerEffect_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ViewerEffectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Effect.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Effect.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ViewerEffectPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ViewerEffectPacket *ViewerEffectPacket_packet = dynamic_cast<const ViewerEffectPacket *>(packet);
        if (ViewerEffectPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ViewerEffectPacket(*ViewerEffectPacket_packet);
    }
};

// CreateTrustedCircuitPacket
class CreateTrustedCircuitPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID EndPointID;
        SerializableFixed<32> Digest;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EndPointID.serialize(buffer);
            Digest.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EndPointID.deserialize(buffer);
            Digest.deserialize(buffer);
        }
    };
    // CreateTrustedCircuitPacket Member List
    DataBlockBlock DataBlock;

public:
    CreateTrustedCircuitPacket() {
        this->setID(CreateTrustedCircuit_ID);
    };
    virtual ~CreateTrustedCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateTrustedCircuitPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CreateTrustedCircuitPacket *CreateTrustedCircuitPacket_packet = dynamic_cast<const CreateTrustedCircuitPacket *>(packet);
        if (CreateTrustedCircuitPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CreateTrustedCircuitPacket(*CreateTrustedCircuitPacket_packet);
    }
};

// DenyTrustedCircuitPacket
class DenyTrustedCircuitPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID EndPointID;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EndPointID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EndPointID.deserialize(buffer);
        }
    };
    // DenyTrustedCircuitPacket Member List
    DataBlockBlock DataBlock;

public:
    DenyTrustedCircuitPacket() {
        this->setID(DenyTrustedCircuit_ID);
    };
    virtual ~DenyTrustedCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DenyTrustedCircuitPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DenyTrustedCircuitPacket *DenyTrustedCircuitPacket_packet = dynamic_cast<const DenyTrustedCircuitPacket *>(packet);
        if (DenyTrustedCircuitPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DenyTrustedCircuitPacket(*DenyTrustedCircuitPacket_packet);
    }
};

// RezSingleAttachmentFromInvPacket
class RezSingleAttachmentFromInvPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID OwnerID;
        SerializableU8 AttachmentPt;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            OwnerID.serialize(buffer);
            AttachmentPt.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            AttachmentPt.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // RezSingleAttachmentFromInvPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    RezSingleAttachmentFromInvPacket() {
        this->setID(RezSingleAttachmentFromInv_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezSingleAttachmentFromInvPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezSingleAttachmentFromInvPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RezSingleAttachmentFromInvPacket *RezSingleAttachmentFromInvPacket_packet = dynamic_cast<const RezSingleAttachmentFromInvPacket *>(packet);
        if (RezSingleAttachmentFromInvPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RezSingleAttachmentFromInvPacket(*RezSingleAttachmentFromInvPacket_packet);
    }
};

// RezMultipleAttachmentsFromInvPacket
class RezMultipleAttachmentsFromInvPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableUUID CompoundMsgID;
        SerializableU8 TotalObjects;
        SerializableBool FirstDetachAll;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CompoundMsgID.serialize(buffer);
            TotalObjects.serialize(buffer);
            FirstDetachAll.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CompoundMsgID.deserialize(buffer);
            TotalObjects.deserialize(buffer);
            FirstDetachAll.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID OwnerID;
        SerializableU8 AttachmentPt;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            OwnerID.serialize(buffer);
            AttachmentPt.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            AttachmentPt.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // RezMultipleAttachmentsFromInvPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    RezMultipleAttachmentsFromInvPacket() {
        this->setID(RezMultipleAttachmentsFromInv_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezMultipleAttachmentsFromInvPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezMultipleAttachmentsFromInvPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RezMultipleAttachmentsFromInvPacket *RezMultipleAttachmentsFromInvPacket_packet = dynamic_cast<const RezMultipleAttachmentsFromInvPacket *>(packet);
        if (RezMultipleAttachmentsFromInvPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RezMultipleAttachmentsFromInvPacket(*RezMultipleAttachmentsFromInvPacket_packet);
    }
};

// DetachAttachmentIntoInvPacket
class DetachAttachmentIntoInvPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID ItemID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // DetachAttachmentIntoInvPacket Member List
    ObjectDataBlock ObjectData;

public:
    DetachAttachmentIntoInvPacket() {
        this->setID(DetachAttachmentIntoInv_ID);
    };
    virtual ~DetachAttachmentIntoInvPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DetachAttachmentIntoInvPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const DetachAttachmentIntoInvPacket *DetachAttachmentIntoInvPacket_packet = dynamic_cast<const DetachAttachmentIntoInvPacket *>(packet);
        if (DetachAttachmentIntoInvPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new DetachAttachmentIntoInvPacket(*DetachAttachmentIntoInvPacket_packet);
    }
};

// CreateNewOutfitAttachmentsPacket
class CreateNewOutfitAttachmentsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableUUID NewFolderID;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NewFolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NewFolderID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID OldItemID;
        SerializableUUID OldFolderID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OldItemID.serialize(buffer);
            OldFolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OldItemID.deserialize(buffer);
            OldFolderID.deserialize(buffer);
        }
    };
    // CreateNewOutfitAttachmentsPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    CreateNewOutfitAttachmentsPacket() {
        this->setID(CreateNewOutfitAttachments_ID);
    };
    virtual ~CreateNewOutfitAttachmentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateNewOutfitAttachmentsPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CreateNewOutfitAttachmentsPacket *CreateNewOutfitAttachmentsPacket_packet = dynamic_cast<const CreateNewOutfitAttachmentsPacket *>(packet);
        if (CreateNewOutfitAttachmentsPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CreateNewOutfitAttachmentsPacket(*CreateNewOutfitAttachmentsPacket_packet);
    }
};

// UserInfoRequestPacket
class UserInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // UserInfoRequestPacket Member List
    AgentDataBlock AgentData;

public:
    UserInfoRequestPacket() {
        this->setID(UserInfoRequest_ID);
    };
    virtual ~UserInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UserInfoRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UserInfoRequestPacket *UserInfoRequestPacket_packet = dynamic_cast<const UserInfoRequestPacket *>(packet);
        if (UserInfoRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UserInfoRequestPacket(*UserInfoRequestPacket_packet);
    }
};

// UserInfoReplyPacket
class UserInfoReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class UserDataBlock : public PacketSerializable {
    public:
        // UserDataBlock Member List
        SerializableBool IMViaEMail;
        SerializableVariable1 DirectoryVisibility;
        SerializableVariable2 EMail;
    public:
        UserDataBlock() {};
        virtual ~UserDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IMViaEMail.serialize(buffer);
            DirectoryVisibility.serialize(buffer);
            EMail.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IMViaEMail.deserialize(buffer);
            DirectoryVisibility.deserialize(buffer);
            EMail.deserialize(buffer);
        }
    };
    // UserInfoReplyPacket Member List
    AgentDataBlock AgentData;
    UserDataBlock UserData;

public:
    UserInfoReplyPacket() {
        this->setID(UserInfoReply_ID);
    };
    virtual ~UserInfoReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UserData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UserData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UserInfoReplyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UserInfoReplyPacket *UserInfoReplyPacket_packet = dynamic_cast<const UserInfoReplyPacket *>(packet);
        if (UserInfoReplyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UserInfoReplyPacket(*UserInfoReplyPacket_packet);
    }
};

// UpdateUserInfoPacket
class UpdateUserInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class UserDataBlock : public PacketSerializable {
    public:
        // UserDataBlock Member List
        SerializableBool IMViaEMail;
        SerializableVariable1 DirectoryVisibility;
    public:
        UserDataBlock() {};
        virtual ~UserDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IMViaEMail.serialize(buffer);
            DirectoryVisibility.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IMViaEMail.deserialize(buffer);
            DirectoryVisibility.deserialize(buffer);
        }
    };
    // UpdateUserInfoPacket Member List
    AgentDataBlock AgentData;
    UserDataBlock UserData;

public:
    UpdateUserInfoPacket() {
        this->setID(UpdateUserInfo_ID);
    };
    virtual ~UpdateUserInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UserData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UserData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateUserInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const UpdateUserInfoPacket *UpdateUserInfoPacket_packet = dynamic_cast<const UpdateUserInfoPacket *>(packet);
        if (UpdateUserInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new UpdateUserInfoPacket(*UpdateUserInfoPacket_packet);
    }
};

// InitiateDownloadPacket
class InitiateDownloadPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class FileDataBlock : public PacketSerializable {
    public:
        // FileDataBlock Member List
        SerializableVariable1 SimFilename;
        SerializableVariable1 ViewerFilename;
    public:
        FileDataBlock() {};
        virtual ~FileDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimFilename.serialize(buffer);
            ViewerFilename.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimFilename.deserialize(buffer);
            ViewerFilename.deserialize(buffer);
        }
    };
    // InitiateDownloadPacket Member List
    AgentDataBlock AgentData;
    FileDataBlock FileData;

public:
    InitiateDownloadPacket() {
        this->setID(InitiateDownload_ID);
    };
    virtual ~InitiateDownloadPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FileData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FileData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InitiateDownloadPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const InitiateDownloadPacket *InitiateDownloadPacket_packet = dynamic_cast<const InitiateDownloadPacket *>(packet);
        if (InitiateDownloadPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new InitiateDownloadPacket(*InitiateDownloadPacket_packet);
    }
};

// MapLayerRequestPacket
class MapLayerRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    // MapLayerRequestPacket Member List
    AgentDataBlock AgentData;

public:
    MapLayerRequestPacket() {
        this->setID(MapLayerRequest_ID);
    };
    virtual ~MapLayerRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapLayerRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MapLayerRequestPacket *MapLayerRequestPacket_packet = dynamic_cast<const MapLayerRequestPacket *>(packet);
        if (MapLayerRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MapLayerRequestPacket(*MapLayerRequestPacket_packet);
    }
};

// MapBlockRequestPacket
class MapBlockRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    class PositionDataBlock : public PacketSerializable {
    public:
        // PositionDataBlock Member List
        SerializableU16 MinX;
        SerializableU16 MaxX;
        SerializableU16 MinY;
        SerializableU16 MaxY;
    public:
        PositionDataBlock() {};
        virtual ~PositionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MinX.serialize(buffer);
            MaxX.serialize(buffer);
            MinY.serialize(buffer);
            MaxY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MinX.deserialize(buffer);
            MaxX.deserialize(buffer);
            MinY.deserialize(buffer);
            MaxY.deserialize(buffer);
        }
    };
    // MapBlockRequestPacket Member List
    AgentDataBlock AgentData;
    PositionDataBlock PositionData;

public:
    MapBlockRequestPacket() {
        this->setID(MapBlockRequest_ID);
    };
    virtual ~MapBlockRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PositionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PositionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapBlockRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MapBlockRequestPacket *MapBlockRequestPacket_packet = dynamic_cast<const MapBlockRequestPacket *>(packet);
        if (MapBlockRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MapBlockRequestPacket(*MapBlockRequestPacket_packet);
    }
};

// MapNameRequestPacket
class MapNameRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    class NameDataBlock : public PacketSerializable {
    public:
        // NameDataBlock Member List
        SerializableVariable1 Name;
    public:
        NameDataBlock() {};
        virtual ~NameDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Name.deserialize(buffer);
        }
    };
    // MapNameRequestPacket Member List
    AgentDataBlock AgentData;
    NameDataBlock NameData;

public:
    MapNameRequestPacket() {
        this->setID(MapNameRequest_ID);
    };
    virtual ~MapNameRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        NameData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        NameData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapNameRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MapNameRequestPacket *MapNameRequestPacket_packet = dynamic_cast<const MapNameRequestPacket *>(packet);
        if (MapNameRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MapNameRequestPacket(*MapNameRequestPacket_packet);
    }
};

// MapItemRequestPacket
class MapItemRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    class RequestDataBlock : public PacketSerializable {
    public:
        // RequestDataBlock Member List
        SerializableU32 ItemType;
        SerializableU64 RegionHandle;
    public:
        RequestDataBlock() {};
        virtual ~RequestDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemType.serialize(buffer);
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemType.deserialize(buffer);
            RegionHandle.deserialize(buffer);
        }
    };
    // MapItemRequestPacket Member List
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;

public:
    MapItemRequestPacket() {
        this->setID(MapItemRequest_ID);
    };
    virtual ~MapItemRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapItemRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const MapItemRequestPacket *MapItemRequestPacket_packet = dynamic_cast<const MapItemRequestPacket *>(packet);
        if (MapItemRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new MapItemRequestPacket(*MapItemRequestPacket_packet);
    }
};

// SendPostcardPacket
class SendPostcardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID AssetID;
        SerializableVector3d PosGlobal;
        SerializableVariable1 To;
        SerializableVariable1 From;
        SerializableVariable1 Name;
        SerializableVariable1 Subject;
        SerializableVariable2 Msg;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AssetID.serialize(buffer);
            PosGlobal.serialize(buffer);
            To.serialize(buffer);
            From.serialize(buffer);
            Name.serialize(buffer);
            Subject.serialize(buffer);
            Msg.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AssetID.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            To.deserialize(buffer);
            From.deserialize(buffer);
            Name.deserialize(buffer);
            Subject.deserialize(buffer);
            Msg.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
        }
    };
    // SendPostcardPacket Member List
    AgentDataBlock AgentData;

public:
    SendPostcardPacket() {
        this->setID(SendPostcard_ID);
    };
    virtual ~SendPostcardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SendPostcardPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const SendPostcardPacket *SendPostcardPacket_packet = dynamic_cast<const SendPostcardPacket *>(packet);
        if (SendPostcardPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new SendPostcardPacket(*SendPostcardPacket_packet);
    }
};

// RpcScriptRequestInboundPacket
class RpcScriptRequestInboundPacket : public PacketBase {
public:

    // Block Class List
    class TargetBlockBlock : public PacketSerializable {
    public:
        // TargetBlockBlock Member List
        SerializableU32 GridX;
        SerializableU32 GridY;
    public:
        TargetBlockBlock() {};
        virtual ~TargetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GridX.serialize(buffer);
            GridY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GridX.deserialize(buffer);
            GridY.deserialize(buffer);
        }
    };
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableUUID ChannelID;
        SerializableU32 IntValue;
        SerializableVariable2 StringValue;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            ChannelID.serialize(buffer);
            IntValue.serialize(buffer);
            StringValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            ChannelID.deserialize(buffer);
            IntValue.deserialize(buffer);
            StringValue.deserialize(buffer);
        }
    };
    // RpcScriptRequestInboundPacket Member List
    TargetBlockBlock TargetBlock;
    DataBlockBlock DataBlock;

public:
    RpcScriptRequestInboundPacket() {
        this->setID(RpcScriptRequestInbound_ID);
    };
    virtual ~RpcScriptRequestInboundPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TargetBlock.serialize(buffer);
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TargetBlock.deserialize(buffer);
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RpcScriptRequestInboundPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RpcScriptRequestInboundPacket *RpcScriptRequestInboundPacket_packet = dynamic_cast<const RpcScriptRequestInboundPacket *>(packet);
        if (RpcScriptRequestInboundPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RpcScriptRequestInboundPacket(*RpcScriptRequestInboundPacket_packet);
    }
};

// RpcScriptReplyInboundPacket
class RpcScriptReplyInboundPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableUUID ChannelID;
        SerializableU32 IntValue;
        SerializableVariable2 StringValue;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            ChannelID.serialize(buffer);
            IntValue.serialize(buffer);
            StringValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            ChannelID.deserialize(buffer);
            IntValue.deserialize(buffer);
            StringValue.deserialize(buffer);
        }
    };
    // RpcScriptReplyInboundPacket Member List
    DataBlockBlock DataBlock;

public:
    RpcScriptReplyInboundPacket() {
        this->setID(RpcScriptReplyInbound_ID);
    };
    virtual ~RpcScriptReplyInboundPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RpcScriptReplyInboundPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const RpcScriptReplyInboundPacket *RpcScriptReplyInboundPacket_packet = dynamic_cast<const RpcScriptReplyInboundPacket *>(packet);
        if (RpcScriptReplyInboundPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new RpcScriptReplyInboundPacket(*RpcScriptReplyInboundPacket_packet);
    }
};

// LandStatRequestPacket
class LandStatRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RequestDataBlock : public PacketSerializable {
    public:
        // RequestDataBlock Member List
        SerializableU32 ReportType;
        SerializableU32 RequestFlags;
        SerializableVariable1 Filter;
        SerializableS32 ParcelLocalID;
    public:
        RequestDataBlock() {};
        virtual ~RequestDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReportType.serialize(buffer);
            RequestFlags.serialize(buffer);
            Filter.serialize(buffer);
            ParcelLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReportType.deserialize(buffer);
            RequestFlags.deserialize(buffer);
            Filter.deserialize(buffer);
            ParcelLocalID.deserialize(buffer);
        }
    };
    // LandStatRequestPacket Member List
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;

public:
    LandStatRequestPacket() {
        this->setID(LandStatRequest_ID);
    };
    virtual ~LandStatRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LandStatRequestPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const LandStatRequestPacket *LandStatRequestPacket_packet = dynamic_cast<const LandStatRequestPacket *>(packet);
        if (LandStatRequestPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new LandStatRequestPacket(*LandStatRequestPacket_packet);
    }
};

// ErrorPacket
class ErrorPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 Code;
        SerializableVariable1 Token;
        SerializableUUID ID;
        SerializableVariable1 System;
        SerializableVariable2 Message;
        SerializableVariable2 Data;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Code.serialize(buffer);
            Token.serialize(buffer);
            ID.serialize(buffer);
            System.serialize(buffer);
            Message.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Code.deserialize(buffer);
            Token.deserialize(buffer);
            ID.deserialize(buffer);
            System.deserialize(buffer);
            Message.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // ErrorPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ErrorPacket() {
        this->setID(Error_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ErrorPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ErrorPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ErrorPacket *ErrorPacket_packet = dynamic_cast<const ErrorPacket *>(packet);
        if (ErrorPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ErrorPacket(*ErrorPacket_packet);
    }
};

// ObjectIncludeInSearchPacket
class ObjectIncludeInSearchPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableBool IncludeInSearch;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            IncludeInSearch.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            IncludeInSearch.deserialize(buffer);
        }
    };
    // ObjectIncludeInSearchPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;
    typedef VariableSerializable<ObjectDataBlock> OBJECTDATABLOCK_LIST_TYPE;

public:
    ObjectIncludeInSearchPacket() {
        this->setID(ObjectIncludeInSearch_ID);
    };
    virtual ~ObjectIncludeInSearchPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectIncludeInSearchPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const ObjectIncludeInSearchPacket *ObjectIncludeInSearchPacket_packet = dynamic_cast<const ObjectIncludeInSearchPacket *>(packet);
        if (ObjectIncludeInSearchPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new ObjectIncludeInSearchPacket(*ObjectIncludeInSearchPacket_packet);
    }
};



class Fanni_LLPackets_API LLPackets {
public:
    static void init(PacketFactory &packet_factory);
};

}

#endif // LLPACKET_IMPL_H

