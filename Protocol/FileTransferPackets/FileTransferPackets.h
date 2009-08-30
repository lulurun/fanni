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
        SerializableUUID SenderTransferID;
        SerializableS32 Size;
        SerializableVariable2 Name;
    public:
        FileInfoBlock() {};
        virtual ~FileInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SenderTransferID.serialize(buffer);
            Size.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SenderTransferID.deserialize(buffer);
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

// FileInfoReplyPacket
class FileInfoReplyPacket : public PacketBase {
public:

    // Block Class List
    class FileInfoBlock : public PacketSerializable {
    public:
        // FileInfoBlock Member List
        SerializableUUID ReceiverTransferID;
        SerializableUUID SenderTransferID;
    public:
        FileInfoBlock() {};
        virtual ~FileInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReceiverTransferID.serialize(buffer);
            SenderTransferID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReceiverTransferID.deserialize(buffer);
            SenderTransferID.deserialize(buffer);
        }
    };
    // FileInfoReplyPacket Member List
    FileInfoBlock FileInfo;

public:
    FileInfoReplyPacket() {
        this->setID(FileInfoReply_ID);
    };
    virtual ~FileInfoReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        FileInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        FileInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FileInfoReplyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const FileInfoReplyPacket *FileInfoReplyPacket_packet = dynamic_cast<const FileInfoReplyPacket *>(packet);
        if (FileInfoReplyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new FileInfoReplyPacket(*FileInfoReplyPacket_packet);
    }
};

// FileDataPacket
class FileDataPacket : public PacketBase {
public:

    // Block Class List
    class FileDataBlock : public PacketSerializable {
    public:
        // FileDataBlock Member List
        SerializableUUID ReceiverTransferID;
        SerializableS32 DataNumber;
        SerializableVariable2 Data;
    public:
        FileDataBlock() {};
        virtual ~FileDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReceiverTransferID.serialize(buffer);
            DataNumber.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReceiverTransferID.deserialize(buffer);
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

// OpenConnectionPacket
class OpenConnectionPacket : public PacketBase {
public:

    // Block Class List
    class OpenConnectionBlock : public PacketSerializable {
    public:
        // OpenConnectionBlock Member List
        SerializableU32 Code;
    public:
        OpenConnectionBlock() {};
        virtual ~OpenConnectionBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Code.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Code.deserialize(buffer);
        }
    };
    // OpenConnectionPacket Member List
    OpenConnectionBlock OpenConnection;

public:
    OpenConnectionPacket() {
        this->setID(OpenConnection_ID);
    };
    virtual ~OpenConnectionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        OpenConnection.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        OpenConnection.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OpenConnectionPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const OpenConnectionPacket *OpenConnectionPacket_packet = dynamic_cast<const OpenConnectionPacket *>(packet);
        if (OpenConnectionPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new OpenConnectionPacket(*OpenConnectionPacket_packet);
    }
};

// OpenConnectionReplyPacket
class OpenConnectionReplyPacket : public PacketBase {
public:

    // Block Class List
    class OpenConnectionReplyBlock : public PacketSerializable {
    public:
        // OpenConnectionReplyBlock Member List
        SerializableU32 Code;
    public:
        OpenConnectionReplyBlock() {};
        virtual ~OpenConnectionReplyBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Code.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Code.deserialize(buffer);
        }
    };
    // OpenConnectionReplyPacket Member List
    OpenConnectionReplyBlock OpenConnectionReply;

public:
    OpenConnectionReplyPacket() {
        this->setID(OpenConnectionReply_ID);
    };
    virtual ~OpenConnectionReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        OpenConnectionReply.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        OpenConnectionReply.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OpenConnectionReplyPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const OpenConnectionReplyPacket *OpenConnectionReplyPacket_packet = dynamic_cast<const OpenConnectionReplyPacket *>(packet);
        if (OpenConnectionReplyPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new OpenConnectionReplyPacket(*OpenConnectionReplyPacket_packet);
    }
};

// CloseConnectionPacket
class CloseConnectionPacket : public PacketBase {
public:

    // Block Class List
    // CloseConnectionPacket Member List

public:
    CloseConnectionPacket() {
        this->setID(CloseConnection_ID);
    };
    virtual ~CloseConnectionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new CloseConnectionPacket(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const CloseConnectionPacket *CloseConnectionPacket_packet = dynamic_cast<const CloseConnectionPacket *>(packet);
        if (CloseConnectionPacket_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new CloseConnectionPacket(*CloseConnectionPacket_packet);
    }
};



};

#endif // FileTransferPACKET_IMPL_H

