#ifndef FileTransferPACKET_ID_H_
#define FileTransferPACKET_ID_H_

namespace Fanni {

typedef enum {
	 FileInfo_ID = 0xffff009a,
	 FileInfoReply_ID = 0xffff009b,
	 FileData_ID = 0x00000011,
	 PacketAck_ID = 0xFFFFFFFB,
	 UseCircuitCode_ID = 0xffff0003,
	 CloseCircuit_ID = 0xFFFFFFFD,
} PacketID;


};

#endif // FileTransferPACKET_ID_H

