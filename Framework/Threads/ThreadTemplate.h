/*
 * Thread.h
 *
 *  Created on: Mar 5, 2009
 *      Author: lulu
 */

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>
#include "fanni/Exception.h"
#include "fanni/Logger.h"
#include "Thread.h"

namespace Fanni {

#if 0
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

template<class ThreadObject>
class SimpleThreadTemplate {
private:
	pthread_t th;

	class ThreadHandler {
		ThreadObject &obj;
	public:
		ThreadHandler(ThreadObject &obj) : obj(obj) {};
		virtual ~ThreadHandler() {};
		virtual void setArg(void *arg) {};
		virtual void operator()() {
			this->obj.start();
		}
	};

	ThreadHandler *handler;

public:
	SimpleThreadTemplate(ThreadObject &obj) {
		this->handler = new ThreadHandler(obj);
	}
	virtual ~SimpleThreadTemplate() {
		delete this->handler;
	}
	void getID() {
		return this->th;
	}
	void kick() {
		::pthread_create(&this->th, NULL, caller, handler);
	}
	void join() {
		::pthread_join(this->th, NULL);
	}

protected:
	// @@@ arg must be derived from ThreadHandlerBase
	static void *caller(void *arg = NULL) {
		ThreadHandler *handler = reinterpret_cast<ThreadHandler *> (arg);
		/* TODO @@@ assert typeof(handler) */
		try {
			handler->operator()();
		} catch (ErrorException &e) {
			ERROR_LOG("Thread terminated by catching ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
		}
		return NULL;
	}
};

#endif

template<class ThreadObject>
class ThreadTemplate : public ThreadBase {
private:
	ThreadObject *thread_object_ptr;

public:
	ThreadTemplate(ThreadObject *thread_object) : thread_object_ptr(thread_object){}
	virtual void start() {
		this->thread_object_ptr->start();
	}
	virtual void stop() {
		DEBUG_LOG("enter");
		this->thread_object_ptr->stop();
		DEBUG_LOG("exit");
	}
	virtual void loop_func() {};
};


}

#endif /* THREAD_H_ */
