/*
 * Thread.h
 *
 *  Created on: Mar 5, 2009
 *      Author: lulu
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

namespace Fanni {

class ThreadHandlerBase {
public:
	ThreadHandlerBase() {
	}
	;
	virtual ~ThreadHandlerBase() {
	}
	;
	virtual void setArg(void *arg) = 0;
	virtual void operator()() = 0;
};

template<class ThreadHandlerType>
class ThreadTemplate {
private:
	pthread_t th;
	ThreadHandlerType &handler;

public:
	ThreadTemplate(ThreadHandlerType &handler) :
		handler(handler) {
	}
	virtual ~ThreadTemplate() {
	}
	void getID() {
		return this->th;
	}
	void kick() {
		::pthread_create(&this->th, NULL, caller, &handler);
	}
	void join() {
		::pthread_join(this->th, NULL);
	}

protected:
	// @@@ arg must be derived from ThreadHandlerBase
	static void *caller(void *arg) {
		ThreadHandlerType & handler
				= *reinterpret_cast<ThreadHandlerType *> (arg);
		// TODO @@@ assert typeof(handler)
		handler();
		return NULL;
	}
};

}

#endif /* THREAD_H_ */
