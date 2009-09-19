/*
 * DataControl.h
 *
 *  Created on: Sep 18, 2009
 *      Author: lulu
 */

#ifndef DATACONTROL_H_
#define DATACONTROL_H_

#include <pthread.h>

namespace Fanni {

class DataControl {
	friend class DataControlLock;

protected:
	pthread_mutex_t 	m;
	pthread_cond_t  	c;
	pthread_mutexattr_t a;
	bool active;

public:
	DataControl();
	virtual ~DataControl();

	int wait(long timeout_msec = -1);
	int trigger();

	int lock();
	int unlock();

	void activate();
	void deactivate();
	bool isActive() const {
		return this->active;
	}
};

class DataControlLock {
protected:
	DataControl *dc_ptr;
public:
	DataControlLock();
	~DataControlLock();
	void lock(DataControl *dc);
	void unlock();

};

}

#endif /* DATACONTROL_H_ */
