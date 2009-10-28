/*
 * FileTransferStatus.h
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#ifndef FileTransferStatus_H_
#define FileTransferStatus_H_

#include <ctime>
#include <string>
#include "Poco/Mutex.h"
#include "fanni/win_stdint.h"
#include "fanni/UUID.h"

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
	int block_size;
	int internal_count;
	bool _error;

	unsigned char *file_buffer;
	bool *data_block_map;
public:
	FileTransferStatus(uint32_t file_size, const std::string file_name, const UUID &receiver_transfer_id, const UUID &sender_transfer_id, bool mem_alloc = false);
	~FileTransferStatus();

	const size_t getFileSize() const { return this->file_size; }
	const std::string &getFileName() const { return this->file_name; }
	const UUID &getReceiverTransferID() const { return this->receiver_transfer_id; }
	const UUID &getSenderTransferID() const { return this->sender_transfer_id; }
	const time_t &getStartTime() const { return this->start_time; }
	const unsigned char *getFileBuffer() const { return this->file_buffer; }
	const bool isFailed() const { return this->_error; }
	void failed() { this->_error = true; }

	void setReceiverTransferID(const UUID &transfer_id);
	void setSenderTransferID(const UUID &transfer_id);
	// return true if all data has been received
	bool update(int data_number, const unsigned char *data, size_t len);
};

}

#endif // FileTransferStatus_H_

