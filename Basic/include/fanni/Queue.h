/*
 * Queue.h
 *
 *  Created on: Sep 18, 2009
 *      Author: lulu
 */

#ifndef FANNIQUEUE_H_
#define FANNIQUEUE_H_

#include "Poco/Mutex.h"
#include "Poco/Condition.h"

namespace Fanni {

template<typename DATA_TYPE>
class Queue {
private:
	std::deque<DATA_TYPE> _queue;
	Poco::FastMutex _mutex;
	Poco::Condition _cond;

public:
	Queue() {};
	virtual ~Queue() {};

	void put(const DATA_TYPE &data) {
		Poco::FastMutex::ScopedLock lock(this->_mutex);
		this->_queue.push_back(data);
		this->_cond.broadcast();
	}

	DATA_TYPE get() {
		Poco::FastMutex::ScopedLock lock(this->_mutex);
		while(this->_queue.empty()) {
			this->_cond.wait<Poco::FastMutex>(this->_mutex);
		}
		DATA_TYPE data = this->_queue.front();
		this->_queue.pop_front();
		return data;
	}

};

}

#endif /* FANNIQUEUE_H_ */

