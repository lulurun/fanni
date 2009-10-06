/*
 * MyQueue.h
 *
 *  Created on: Sep 18, 2009
 *      Author: lulu
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <pthread.h>
#include <queue>
#include "DataControl.h"

namespace Fanni {

template<typename DATA_TYPE>
class MyQueue {
private:
	std::queue<DATA_TYPE> _queue;
	DataControl control;

public:
	MyQueue() {};
	virtual ~MyQueue() {};

	void put(const DATA_TYPE &data) {
		DataControlLock l(this->control);
		this->_queue.push(data);
		this->control.trigger();
	}

	DATA_TYPE get() {
		DataControlLock l(this->control);
		while(this->_queue.empty()) {
			this->control.wait(-1);
		}
		DATA_TYPE data = this->_queue.front();
		this->_queue.pop();
		return data;
	}

};

}

#endif /* MYQUEUE_H_ */
