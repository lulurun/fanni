#include "Mutex.h"

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
// posix
#include <sys/time.h>

using namespace std;
using namespace Fanni;

Mutex::Mutex(){
	::pthread_mutexattr_init(&a);
	::pthread_mutexattr_setpshared(&a, PTHREAD_PROCESS_PRIVATE);
	::pthread_mutexattr_settype(&a,PTHREAD_MUTEX_RECURSIVE);
	::pthread_mutex_init(&m,&a);
	::pthread_cond_init(&c,NULL);
}

Mutex::~Mutex(){
	::pthread_mutex_destroy(&m);
	::pthread_cond_destroy(&c);
	::pthread_mutexattr_destroy(&a);
}

int Mutex::lock(){
	return ::pthread_mutex_lock(&m);
}

int Mutex::unlock(){
	return ::pthread_mutex_unlock(&m);
}

int Mutex::wait(long timeout){
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

int Mutex::trigger(){
	return ::pthread_cond_signal(&c);
}

S_MUTEX_LOCK::S_MUTEX_LOCK(){
	this->M = NULL;
};

S_MUTEX_LOCK::~S_MUTEX_LOCK(){
	if(this->M)
		this->unlock();
}

void S_MUTEX_LOCK::lock(Mutex *m){
	this->M = m;
	this->M->lock();
}

void S_MUTEX_LOCK::unlock(){
	Mutex *m = this->M;
	this->M = NULL;
	if(m)
		m->unlock();
}

