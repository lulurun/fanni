#include <cassert>
#include "Status.h"

using namespace Fanni;
using namespace Fanni::FileTransfer;

Status::Status(uint32_t file_size, const std::string file_name, const UUID &receive_id, const UUID &send_id, bool mem_alloc) :
	file_size(file_size), file_name(file_name), receive_id(receive_id),
	send_id(send_id), transfered_size(0), start_time(::time(NULL)),
	block_size((int)(file_size/FILE_PART_SIZE) + 1), internal_count(0), _error(false),
	file_buffer(NULL), data_block_map(NULL) {
	if (mem_alloc) {
		this->file_buffer = new unsigned char[file_size],
		this->data_block_map = new bool[block_size],
		::memset(this->data_block_map, 0, sizeof(bool) * block_size);
	}
}

Status::~Status() {
	if (this->file_buffer) delete [] this->file_buffer;
	if (this->data_block_map) delete [] this->data_block_map;
}

void Status::setReceiverTransferID(const UUID &transfer_id) {
	Poco::FastMutex::ScopedLock l(this->mutex);
	this->receive_id = transfer_id;
}

void Status::setSenderTransferID(const UUID &transfer_id) {
	Poco::FastMutex::ScopedLock l(this->mutex);
	this->send_id = transfer_id;
}

// return true if all data has been received
bool Status::update(int data_number, const unsigned char *data, size_t len) {
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
