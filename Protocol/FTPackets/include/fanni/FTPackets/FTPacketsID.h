
#ifndef FTPACKET_ID_H_
#define FTPACKET_ID_H_

namespace Fanni {

typedef enum {
	 FileInfo_ID = 0xffff0201,
	 FileInfoReply_ID = 0xffff0202,
	 TransferComplete_ID = 0xffff0203,
	 FileData_ID = 0x00000021,
	 OpenConnection_ID = 0xffff0204,
	 OpenConnectionReply_ID = 0xffff0205,
	 CloseConnection_ID = 0xffff0206,
	 CloseConnectionReply_ID = 0xffff0207,
} PacketID;


};

#endif // FTPACKET_ID_H

