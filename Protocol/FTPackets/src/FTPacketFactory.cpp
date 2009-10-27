
#include "fanni/FTPackets/FTPackets.h"
#include "fanni/FTPackets/FTPacketFactory.h"

namespace Fanni {

FTPacketFactory::FTPacketFactory() {
    PacketList[FileInfo_ID] = new FileInfoPacket();
    PacketList[FileInfoReply_ID] = new FileInfoReplyPacket();
    PacketList[TransferComplete_ID] = new TransferCompletePacket();
    PacketList[FileData_ID] = new FileDataPacket();
    PacketList[OpenConnection_ID] = new OpenConnectionPacket();
    PacketList[OpenConnectionReply_ID] = new OpenConnectionReplyPacket();
    PacketList[CloseConnection_ID] = new CloseConnectionPacket();
    PacketList[CloseConnectionReply_ID] = new CloseConnectionReplyPacket();

}

FTPacketFactory::~FTPacketFactory() {}

PacketSerializer *CreateFTPacketSerializer() {
    return new PacketSerializer(FTPacketFactorySingleton::get());
}

}

