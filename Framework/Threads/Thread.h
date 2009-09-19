#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <string>
#include "DataControl.h"

namespace Fanni {

class ThreadBase {
public:
	enum{
		THREAD_PRIORITY_LOWEST = 8,
		THREAD_PRIORITY_LOWER,
		THREAD_PRIORITY_NOMAL,
		THREAD_PRIORITY_HIGHT,
		THREAD_PRIORITY_HIGHEST,
	};
	static void set_thread_priority( int priority );
protected:
	pthread_t th;
	int priority;
	DataControl dc;

public:
	ThreadBase();
	virtual ~ThreadBase();
	virtual void stop();

	void kick( int priority = THREAD_PRIORITY_NOMAL );
	void join();
	const pthread_t getID() const;
private:
	static void * _thread_func( void * This );
protected:
	virtual void start();
	virtual void loop_func() = 0;
};

} // namespace

#endif /*_THREAD_H_*/
