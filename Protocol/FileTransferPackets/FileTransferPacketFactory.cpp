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
    PacketList[UseCircuitCode_ID] = new UseCircuitCodePacket();
    PacketList[CloseCircuit_ID] = new CloseCircuitPacket();

}

PacketSerializer *CreateFileTransferPacketSerializer() {
    return new PacketSerializer(&FileTransferPacketFactorySingleton::get());
}

}

