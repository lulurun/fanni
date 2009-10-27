#ifndef FIXEDLENGTHBUFFER_H_
#define FIXEDLENGTHBUFFER_H_

#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include "fanni/ByteOrder.h"
#include "fanni/Exception.h"

// TODO @@@ should be template !!

namespace Fanni {

template<size_t FixedLength>
class FixedLengthBuffer {
private:
	unsigned char *_ptr;
	unsigned char *_tail;
	unsigned char *_head;

	void check_capability(size_t len) const {
		if (this->getLength() + len >= FixedLength) {
			ErrorException::throw_exception(EXP_FixedLengthBuffer, EXP_PRE_MSG, "not enough space %d %d", this->getLength(), len);
		}
	};
	void check_length(size_t len) const {
		if (this->_ptr + len > this->_tail) {
			ErrorException::throw_exception(EXP_FixedLengthBuffer, EXP_PRE_MSG,
					"buffer over flow %d %d", this->_tail - this->_ptr, len);
		}
	};

public:
	static const unsigned int Capacity = FixedLength;

	FixedLengthBuffer() {
		this->_head = new unsigned char[FixedLength];
		this->_ptr = this->_head;
		this->_tail = this->_head;
	};
	FixedLengthBuffer(const unsigned char *data, size_t len) {
		this->_head = new unsigned char[len];
		::memcpy(this->_head, data, len);
		this->_ptr = this->_head;
		this->_tail = this->_head + len;
	};
	FixedLengthBuffer(const FixedLengthBuffer &buf) {
		size_t len = buf.getLength();
		this->_head = new unsigned char[len];
		::memcpy(this->_head, buf._head, len);
		this->_ptr = this->_head;
		this->_tail = this->_head + len;
	};
	~FixedLengthBuffer() {
		delete this->_head;
	};

	unsigned char operator[](int i) const {
		return this->_head[i];
	};
	const unsigned char *getPos() const {
		return this->_ptr;
	};
	void setPos(int pos) {
		this->_ptr = this->_head + pos;
	};
	const unsigned char *getEnd() const {
		return this->_tail;
	};
	size_t getLength() const {
		return this->_tail - this->_head;
	};
	void setLength(size_t len) {
		this->check_capability(len);
		this->_tail = this->_head + len;
	};
	const unsigned char *getConstBuffer() const {
		return this->_head;
	};
	unsigned char *getBuffer() {
		return this->_head;
	};
	void resetPos(int pos = 0) {
		this->_ptr = this->_head + pos;
	};
	void clear() {
		this->_tail = this->_head;
		this->_ptr = this->_head;
	};
	void putBuf(const void *val, size_t len) {
		check_capability(len);
		::memcpy(this->_tail, val, len);
		this->_tail += len;
	};
	void getBuf(void *val, size_t len) {
		check_length(len);
		::memcpy(val, this->_ptr, len);
		this->_ptr += len;
	};
	void getBuf(std::vector<unsigned char> &out_vector, size_t len) {
		check_length(len);
		out_vector.resize(len);
		::memcpy(&out_vector[0], this->_ptr, len);
		this->_ptr += len;
	};

	template<class T>
	T getValue(bool change_byteorder = true) {
		check_length(sizeof(T));
		// copy
		T val;
		::memcpy(&val, this->_ptr, sizeof(T));
		if (change_byteorder) {
			val = ByteOrderTemplate<T>::change(val);
		}
		this->_ptr += sizeof(T);
		return val;
	}

	template<class T>
	void putValue(const T &val, bool change_byteorder = true) {
		check_capability(sizeof(T));
		T _val;
		if (change_byteorder) {
			_val = ByteOrderTemplate<T>::change(val);
		} else {
			_val = val;
		}
		::memcpy(this->_tail, &_val, sizeof(T));
		this->_tail += sizeof(T);
	}

	// for debug
	std::string to_debug_string() const {
		static const int chars_per_line = 32;
		static const int chars_per_block = 4;
		static const char* hex_map = "0123456789ABCDEF";

		std::ostringstream ost;
		int count = 1;
		for (unsigned char *i = this->_head; i < this->_tail; i++, count++) {
			unsigned char ch = i[0];
			char hex_str[3];
			hex_str[0] = hex_map[ch % 16];
			hex_str[1] = hex_map[ch >> 4];
			hex_str[2] = '\0';
			std::string pointer = " ";
			if (i == this->_ptr) {
				pointer = "*";
			}
			ost << pointer << hex_str;
			if (count % chars_per_block == 0) {
				ost << " ";
			}
			if (count % chars_per_line == 0) {
				ost << "\n";
			}
		}
		return ost.str();
	};

	int getFixedLength() const {
		return FixedLength;
	}

};

/*
 // TODO @@@ temporary, not implemented as expected
 class FixedLengthBufferPool {
 static const unsigned int DEFAULT_BUF_LEN = 5000;
 public:
 static FixedLengthBufferPool *GetInstance() {
 static FixedLengthBufferPool *pool = NULL;
 if (pool == NULL) {
 pool = new FixedLengthBufferPool();
 //pool->init();
 }
 return pool;
 }

 FixedLengthBuffer *getBuffer() {
 unsigned char *buf = new unsigned char[FixedLengthBufferPool::DEFAULT_BUF_LEN];
 return new FixedLengthBuffer(buf);
 }

 void returnBuffer(FixedLengthBuffer *buf) {
 if (buf != NULL) {
 delete buf;
 }
 }
 };
 */

}

#endif /* FIXEDLENGTHBUFFER_H_ */
