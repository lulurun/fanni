#include "FileTransferPackets.h"
#include "FileTransferPacketFactory.h"

namespace Fanni {

FileTransferPacketFactory::FileTransferPacketFactory() {
    PacketList[FileInfo_ID] = new FileInfoPacket();
    PacketList[FileInfoReply_ID] = new FileInfoReplyPacket();
    PacketList[TransferComplete_ID] = new TransferCompletePacket();
    PacketList[FileData_ID] = new FileDataPacket();
    PacketList[OpenConnection_ID] = new OpenConnectionPacket();
    PacketList[OpenConnectionReply_ID] = new OpenConnectionReplyPacket();
    PacketList[CloseConnection_ID] = new CloseConnectionPacket();
    PacketList[CloseConnectionReply_ID] = new CloseConnectionReplyPacket();

}

FileTransferPacketFactory::~FileTransferPacketFactory() {}

PacketSerializer *CreateFileTransferPacketSerializer() {
    return new PacketSerializer(FileTransferPacketFactorySingleton::get());
}

}

