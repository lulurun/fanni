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
#include "Poco/Mutex.h"

#include "fanni/UUID.h"
#include "fanni/LockableTemplate.h"
#include "rUDP/ConnectionBase.h"

namespace Fanni {

static const size_t FILE_PART_SIZE = 1200;

class FileTransferStatus {
private:
	Poco::FastMutex mutex;

	size_t file_size;
	const std::string file_name;
	UUID receiver_transfer_id;
	UUID sender_transfer_id;
	size_t transfered_size;
	time_t start_time;
	unsigned char *file_buffer;
	int block_size;
	bool *data_block_map;

	int internal_count;

public:
	FileTransferStatus(uint32_t file_size, const std::string file_name, const UUID &receiver_transfer_id, const UUID &sender_transfer_id) :
		file_size(file_size), file_name(file_name),
		receiver_transfer_id(receiver_transfer_id),
		sender_transfer_id(sender_transfer_id),
		transfered_size(0),
		start_time(::time(NULL)),
		file_buffer(new unsigned char[file_size]),
		block_size((int)(file_size/FILE_PART_SIZE) + 1),
		data_block_map(new bool[block_size]),
		internal_count(0) {
		::memset(this->data_block_map, 0, sizeof(bool) * block_size);
	}

	~FileTransferStatus() {
		DEBUG_LOG("release status memory !!");
		if (this->file_buffer) delete [] this->file_buffer;
		if (this->data_block_map) delete [] this->data_block_map;
	}
	const size_t getFileSize() const { return this->file_size; }
	const std::string &getFileName() const { return this->file_name; }
	const UUID &getReceiverTransferID() const { return this->receiver_transfer_id; }
	const UUID &getSenderTransferID() const { return this->sender_transfer_id; }
	const time_t &getStartTime() const { return this->start_time; }
	const unsigned char *getFileBuffer() const { return this->file_buffer; }

	void setReceiverTransferID(const UUID &transfer_id) {
		Poco::FastMutex::ScopedLock l(this->mutex);
		this->receiver_transfer_id = transfer_id;
	}

	void setSenderTransferID(const UUID &transfer_id) {
		Poco::FastMutex::ScopedLock l(this->mutex);
		this->sender_transfer_id = transfer_id;
	}

	// return true if all data has been received
	bool update(int data_number, const unsigned char *data, size_t len) {
		Poco::FastMutex::ScopedLock l(this->mutex);
		if (!this->data_block_map[data_number]) {
			size_t start = data_number * FILE_PART_SIZE;
			assert(start + len <= this->file_size);
			::memcpy(this->file_buffer + start, data, len);
			this->transfered_size += len;
			this->data_block_map[data_number] = true;
			this->internal_count++;
		}
		return (this->transfered_size == this->file_size);
	}
};

class FileTransferClientConnection : public ConnectionBase {
private:
	typedef std::tr1::unordered_map<std::string, FileTransferStatus *> __FILE_TRANSFER_STATUS_MAP;
	typedef lockable<__FILE_TRANSFER_STATUS_MAP> FILE_TRANSFER_STATUS_MAP;
	FILE_TRANSFER_STATUS_MAP receive_transfer_status_map;
	FILE_TRANSFER_STATUS_MAP send_transfer_status_map;

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
		void operator()(const UUID &receiver_transfer_id, int data_number, const std::vector<unsigned char> &data_buf, FileTransferClientConnection *connection);
	};
	struct OnFileTransferCompleteEvent  {
		void operator()(const UUID &sender_transfer_id, FileTransferClientConnection *connection);
	};
	struct OnCloseConnectionEvent {
		void operator()(FileTransferClientConnection *connection);
	};
	struct OnCloseConnectionReplyEvent {
		void operator()(FileTransferClientConnection *connection);
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

	OnOpenConnectionReplyEvent OnOpenConnectionReply;
	OnFileInfoEvent OnFileInfo;
	OnFileInfoReplyEvent OnFileInfoReply;
	OnFileDataEvent OnFileData;
	OnFileTransferCompleteEvent OnFileTransferComplete;
	OnCloseConnectionEvent OnCloseConnection;
	OnCloseConnectionReplyEvent OnCloseConnectionReply;
};

}

#endif /* FILETRANSFERCLIENTCONNECTION_H_ */

