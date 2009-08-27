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
	uint32_t file_size;
	const std::string file_name;
	UUID TransferID;
	uint32_t transfered_size;
	time_t start_time;
	FileTransferStatus(uint32_t file_size, const std::string file_name) :
		file_size(file_size), file_name(file_name){
		this->TransferID = UUID::New();
		this->transfered_size = 0;
		this->start_time = ::time(NULL);
	}
};

class FileTransferClientConnection : public ClientConnectionBase {
private:
	typedef std::tr1::unordered_map<std::string, FileTransferStatus *> FILE_TRANSFER_STATUS_MAP_TYPE;
	FILE_TRANSFER_STATUS_MAP_TYPE file_transfer_status_map;
	Mutex file_transfer_status_map_lock;

	struct OnFileInfoEvent {
		void operator()(uint32_t file_size, const std::string &file_name, FileTransferClientConnection *connection);
	};
	struct OnFileInfoReplyEvent {
		void operator()(UUID &transfer_id, const std::string &file_name, FileTransferClientConnection *connection);
	};
	struct OnFileDataEvent {
		void operator()(UUID &transfer_id, const std::string &file_name, FileTransferClientConnection *connection);
	};
	struct OnFileTransferCompleteEvent  {
		void operator()(UUID &transfer_id, FileTransferClientConnection *connection);
	};

	void addFileTransfer(FileTransferStatus *status);
public:
	FileTransferClientConnection(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase *transfer_base);
	virtual ~FileTransferClientConnection();

	OnFileInfoEvent OnFileInfo;
	OnFileInfoReplyEvent OnFileInfoReply;
	OnFileDataEvent OnFileData;
	OnFileTransferCompleteEvent OnFileTransferComplete;
};

}
}

#endif /* FILETRANSFERCLIENTCONNECTION_H_ */

