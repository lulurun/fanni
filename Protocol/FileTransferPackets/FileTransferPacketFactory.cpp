#include "FileTransferPackets.h"
#include "FileTransferPacketFactory.h"

namespace Fanni {

FileTransferPacketFactory::FileTransferPacketFactory() {
    this->init();
}

FileTransferPacketFactory::~FileTransferPacketFactory() {}

void FileTransferPacketFactory::init() {
    PacketList[FileInfo_ID] = new FileInfoPacket();
    PacketList[FileInfoReply_ID] = new FileInfoReplyPacket();
    PacketList[FileData_ID] = new FileDataPacket();
    PacketList[PacketAck_ID] = new PacketAckPacket();
    PacketList[OpenConnection_ID] = new OpenConnectionPacket();
    PacketList[OpenConnectionReply_ID] = new OpenConnectionReplyPacket();
    PacketList[CloseConnection_ID] = new CloseConnectionPacket();

}

PacketSerializer *CreateFileTransferPacketSerializer() {
    return new PacketSerializer(&FileTransferPacketFactorySingleton::get());
}

}

