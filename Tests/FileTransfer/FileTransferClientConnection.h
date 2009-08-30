/*
 * FileTransferClientConnection.h
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#ifndef FILETRANSFERCLIENTCONNECTION_H_
#define FILETRANSFERCLIENTCONNECTION_H_

#include <ctime>
#include <string>
#include <tr1/unordered_map>
#include "fanni/UUID.h"
#include "PacketTransfer/ClientConnectionBase.h"

namespace Fanni {
namespace Tests {

struct FileTransferStatus {
	size_t file_size;
	const std::string file_name;
	UUID ReceiverTransferID;
	UUID SenderTransferID;
	size_t transfered_size;
	time_t start_time;
	FileTransferStatus(uint32_t file_size, const std::string file_name, const UUID &receiver_transfer_id, const UUID &sender_transfer_id) :
		file_size(file_size), file_name(file_name){
		this->ReceiverTransferID = receiver_transfer_id;
		this->SenderTransferID = sender_transfer_id;
		this->transfered_size = 0;
		this->start_time = ::time(NULL);
	}
};

class FileTransferClientConnection : public ClientConnectionBase {
private:
	typedef std::tr1::unordered_map<std::string, FileTransferStatus *> FILE_TRANSFER_STATUS_MAP_TYPE;
	FILE_TRANSFER_STATUS_MAP_TYPE receive_transfer_status_map;
	Mutex receive_transfer_status_map_lock;
	FILE_TRANSFER_STATUS_MAP_TYPE send_transfer_status_map;
	Mutex send_transfer_status_map_lock;

	struct OnOpenConnectionReplyEvent {
		void operator()(FileTransferClientConnection *connection);
	};
	struct OnFileInfoEvent {
		void operator()(uint32_t file_size, const std::string &file_name, const UUID &sender_tranfer_id, FileTransferClientConnection *connection);
	};
	struct OnFileInfoReplyEvent {
		void operator()(const UUID &receiver_transfer_id, const UUID &sender_transfer_id, FileTransferClientConnection *connection);
	};
	struct OnFileDataEvent {
		void operator()(const UUID &receiver_transfer_id, const std::string &file_name, FileTransferClientConnection *connection);
	};
	struct OnFileTransferCompleteEvent  {
		void operator()(const UUID &sender_transfer_id, FileTransferClientConnection *connection);
	};

	void addReceiveFileTransfer(FileTransferStatus *status);
	FileTransferStatus *getReceiveFileTransfer(const UUID &receiver_transfer_id);
	void addSendFileTransfer(FileTransferStatus *status);
	FileTransferStatus *getSendFileTransfer(const UUID &sender_transfer_id);

public:
	static const size_t FILE_PART_SIZE = 1200;

	FileTransferClientConnection(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_base);
	virtual ~FileTransferClientConnection();

	OnOpenConnectionReplyEvent OnOpenConnectionReply;
	OnFileInfoEvent OnFileInfo;
	OnFileInfoReplyEvent OnFileInfoReply;
	OnFileDataEvent OnFileData;
	OnFileTransferCompleteEvent OnFileTransferComplete;
};

}
}

#endif /* FILETRANSFERCLIENTCONNECTION_H_ */

