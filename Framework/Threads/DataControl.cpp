/*
 * DataControl.cpp
 *
 *  Created on: Sep 18, 2009
 *      Author: lulu
 */

#include <sys/time.h>
#include "DataControl.h"

using namespace Fanni;

DataControl::DataControl() {
	::pthread_mutexattr_init(&a);
	::pthread_mutexattr_setpshared(&a, PTHREAD_PROCESS_PRIVATE);
	::pthread_mutexattr_settype(&a,PTHREAD_MUTEX_RECURSIVE);
	::pthread_mutex_init(&m,&a);
	::pthread_cond_init(&c,NULL);
	this->active = false;
}

DataControl::~DataControl() {
	::pthread_mutex_destroy(&m);
	::pthread_cond_destroy(&c);
	::pthread_mutexattr_destroy(&a);
}

int DataControl::lock(){
	return ::pthread_mutex_lock(&m);
}

int DataControl::unlock(){
	return ::pthread_mutex_unlock(&m);
}

int DataControl::wait(long timeout){
	int iRet;
	if(timeout < 0){ // infinite
		iRet = ::pthread_cond_wait(&c,&m);
	}else{			// enable timeout
		struct timezone tz;
		struct timeval now;
		::gettimeofday(&now,&tz);
		struct timespec ts;
		ts.tv_sec 	= now.tv_sec + (timeout/1000);
		ts.tv_nsec  = now.tv_usec*1000 + (timeout%1000)*1000000; // msec(10^-3 -> nsec(10^-9)
		if(ts.tv_nsec >= 1000000000){
			ts.tv_sec++;
			ts.tv_nsec-= 1000000000;
		}
		iRet = ::pthread_cond_timedwait(&c,&m,&ts);
	}
	return iRet;
}

int DataControl::trigger(){
	return ::pthread_cond_signal(&c);
}

void DataControl::activate() {
	this->lock();
	this->active = true;
	this->unlock();
}

void DataControl::deactivate() {
	this->lock();
	this->active = false;
	this->unlock();
}

// ============
// DataControlLock
DataControlLock::DataControlLock(DataControl &dc): dc(dc), locked(false){
	this->lock();
};

DataControlLock::~DataControlLock(){
	this->unlock();
}

void DataControlLock::lock(){
	this->dc.lock();
	this->locked = true;
}

void DataControlLock::unlock(){
	if(this->locked) {
		this->dc.unlock();
		this->locked = false;
	}
}

