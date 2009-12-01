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
#include "Poco/SharedPtr.h"
#include "fanni/win_stdint.h"
#include "fanni/UUID.h"

namespace Fanni {
namespace FileTransfer {

static const size_t FILE_PART_SIZE = 1200;

class Status {

private:
	Poco::FastMutex mutex;

	size_t file_size;
	const std::string file_name;
	UUID trans_id;
	size_t transfered_size;
	time_t start_time;
	int block_size;
	int internal_count;
	bool _error;

	unsigned char *file_buffer;
	bool *data_block_map;
public:
	Status(uint32_t file_size, const std::string file_name, const UUID &trans_id, bool mem_alloc = false);
	~Status();

	inline const size_t getFileSize() const { return this->file_size; }
	inline const std::string &getFileName() const { return this->file_name; }
	inline const UUID &getTransferID() const { return this->trans_id; }
	inline const time_t &getStartTime() const { return this->start_time; }
	inline const unsigned char *getFileBuffer() const { return this->file_buffer; }
	inline const bool isFailed() const { return this->_error; }
	inline void failed() { this->_error = true; }

	void setTransferID(const UUID &trans_id);
	// return true if all data has been received
	bool update(int data_number, const unsigned char *data, size_t len);
};

typedef Poco::SharedPtr<Status> StatusPtr;

}
}

#endif // FileTransferStatus_H_

