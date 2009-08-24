#ifndef FileTransferPACKET_IMPL_H_
#define FileTransferPACKET_IMPL_H_

#include "fanni/Exception.h"

#include "Packets/PacketBaseTypes.h"
#include "Packets/PacketBase.h"
#include "FileTransferPacketsID.h"

namespace Fanni {

// FileInfoPacket
class FileInfoPacket : public PacketBase {
public:

    // Block Class List
    class FileInfoBlock : public PacketSerializable {
    public:
        // FileInfoBlock Member List
        SerializableUUID TransferID;
        SerializableS32 Size;
        SerializableVariable2 Name;
    public:
        FileInfoBlock() {};
        virtual ~FileInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            Size.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            Size.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // FileInfoPacket Member List
    FileInfoBlock FileInfo;

public:
    FileInfoPacket() {
        this->setID(FileInfo_ID);
    };
    virtual ~FileInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        FileInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        FileInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FileInfoPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const FileInfoPacket *FileInfoPacket_packet = dynamic_cast<const FileInfoPacket *>(packet);
        if (FileInfoPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new FileInfoPacket(*FileInfoPacket_packet);
    }
};

// FileDataPacket
class FileDataPacket : public PacketBase {
public:

    // Block Class List
    class FileDataBlock : public PacketSerializable {
    public:
        // FileDataBlock Member List
        SerializableUUID TransferID;
        SerializableS32 DataNumber;
        SerializableVariable2 Data;
    public:
        FileDataBlock() {};
        virtual ~FileDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            DataNumber.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            DataNumber.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // FileDataPacket Member List
    FileDataBlock FileData;

public:
    FileDataPacket() {
        this->setID(FileData_ID);
    };
    virtual ~FileDataPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        FileData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        FileData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FileDataPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const FileDataPacket *FileDataPacket_packet = dynamic_cast<const FileDataPacket *>(packet);
        if (FileDataPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new FileDataPacket(*FileDataPacket_packet);
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



};

#endif // FileTransferPACKET_IMPL_H

