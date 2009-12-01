
#include "fanni/FTPackets/FTPackets.h"

namespace Fanni {

void FTPackets::init(PacketFactory &packet_factory) {
	packet_factory.registerPacket<FileInfoPacket>(FileInfo_ID);
	packet_factory.registerPacket<FileInfoReplyPacket>(FileInfoReply_ID);
	packet_factory.registerPacket<TransferCompletePacket>(TransferComplete_ID);
	packet_factory.registerPacket<FileDataPacket>(FileData_ID);
	packet_factory.registerPacket<OpenConnectionPacket>(OpenConnection_ID);
	packet_factory.registerPacket<OpenConnectionReplyPacket>(OpenConnectionReply_ID);
	packet_factory.registerPacket<CloseConnectionPacket>(CloseConnection_ID);
	packet_factory.registerPacket<CloseConnectionReplyPacket>(CloseConnectionReply_ID);

}

}

