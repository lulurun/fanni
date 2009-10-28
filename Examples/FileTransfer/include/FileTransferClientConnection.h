/*
 * FileTransferClientConnection.h
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#ifndef FILETRANSFERCLIENTCONNECTION_H_
#define FILETRANSFERCLIENTCONNECTION_H_

#include <string>
#include "Poco/Mutex.h"
#include "Poco/HashMap.h"

#include "fanni/UUID.h"
#include "fanni/LockableTemplate.h"
#include "fanni/rUDP/ConnectionBase.h"
#include "FileTransferStatus.h"

namespace Fanni {

class FileTransferClientConnection : public ConnectionBase {
private:
	typedef Poco::HashMap<std::string, FileTransferStatus *> __FILE_TRANSFER_STATUS_MAP;
	typedef lockable<__FILE_TRANSFER_STATUS_MAP> FILE_TRANSFER_STATUS_MAP;
	FILE_TRANSFER_STATUS_MAP receive_transfer_status_map;
	FILE_TRANSFER_STATUS_MAP send_transfer_status_map;

	// client event
	struct OnOpenConnectionReplyEvent {
		void operator()(FileTransferClientConnection *connection);
	};
	struct OnFileInfoReplyEvent {
		void operator()(const UUID &receiver_transfer_id, const UUID &sender_transfer_id, FileTransferClientConnection *connection);
	};
	struct OnFileTransferCompleteEvent  {
		void operator()(const UUID &sender_transfer_id, FileTransferClientConnection *connection);
	};
	// server event
	struct OnFileInfoEvent {
		void operator()(uint32_t file_size, const std::string &file_name, const UUID &sender_tranfer_id, FileTransferClientConnection *connection);
	};
	struct OnFileDataEvent {
		void operator()(const UUID &receiver_transfer_id, int data_number, const std::vector<unsigned char> &data_buf, FileTransferClientConnection *connection);
	};

	void addReceiveFileTransfer(FileTransferStatus *status);
	FileTransferStatus *getReceiveFileTransfer(const UUID &receiver_transfer_id);
	FileTransferStatus *_getReceiveFileTransfer_nolock(const UUID &receiver_transfer_id);
	void closeReceiveTransfer(const UUID &receiver_transfer_id);

	void addSendFileTransfer(FileTransferStatus *status);
	FileTransferStatus *getSendFileTransfer(const UUID &sender_transfer_id);
	FileTransferStatus *_getSendFileTransfer_nolock(const UUID &sender_transfer_id);
	void closeSendTransfer(const UUID &sender_transfer_id);

public:

	FileTransferClientConnection(uint32_t circuit_code, const Poco::Net::SocketAddress &addr, TransferNode &node);
	virtual ~FileTransferClientConnection();

	// client event
	OnOpenConnectionReplyEvent OnOpenConnectionReply;
	OnFileInfoReplyEvent OnFileInfoReply;
	OnFileTransferCompleteEvent OnFileTransferComplete;
	// server event
	OnFileInfoEvent OnFileInfo;
	OnFileDataEvent OnFileData;
};

}

#endif /* FILETRANSFERCLIENTCONNECTION_H_ */

