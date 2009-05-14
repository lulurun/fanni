#ifndef FP_MUTEX_H
#define FP_MUTEX_H

#include <pthread.h>

namespace Fanni {

// ----------------------------------------------
class Mutex{
	friend class S_MUTEX_LOCK; // controller
protected:
	pthread_mutex_t 	m;
	pthread_cond_t  	c;
	pthread_mutexattr_t a;

public:
	Mutex();
	~Mutex();
public:
	int wait(long timeout = -1);
	int trigger();
protected:
public:
	int lock();
	int unlock();
};

class S_MUTEX_LOCK {
protected:
	Mutex *M;
public:
	S_MUTEX_LOCK();
	~S_MUTEX_LOCK();
	void lock(Mutex *m);
	void unlock();
};

} // namespace

#endif

