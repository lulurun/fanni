#ifndef FileTransferPACKET_ID_H_
#define FileTransferPACKET_ID_H_

namespace Fanni {

typedef enum {
	 FileInfo_ID = 0xffff009a,
	 FileInfoReply_ID = 0xffff009b,
	 TransferComplete_ID = 0xffff009c,
	 FileData_ID = 0x00000011,
	 PacketAck_ID = 0xFFFFFFFB,
	 OpenConnection_ID = 0xffff0003,
	 OpenConnectionReply_ID = 0xffff0004,
	 CloseConnection_ID = 0xffff0005,
} PacketID;


};

#endif // FileTransferPACKET_ID_H

