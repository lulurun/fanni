#include "Thread.h"
#include "fanni/Exception.h"
#include "fanni/Logger.h"

using namespace Fanni;

ThreadBase::ThreadBase() { }
ThreadBase::~ThreadBase() { }

void ThreadBase::kick( int priority ) {
	this->priority	= priority;
	::pthread_create(&this->th, NULL, ThreadBase::thread_handler, this);
}

void ThreadBase::join() {
	// TODO: timeout ?
	void *ret;
	::pthread_join(this->th, &ret);
}

void *ThreadBase::thread_handler(void *t) {
	TRACE_LOG("enter");
	ThreadBase *This = reinterpret_cast<ThreadBase*>(t);
	ThreadBase::set_thread_priority ( This->priority );
	try {
		This->loop();
	} catch (const FatalException &e) {
		ERROR_LOG("FATAL Worker Thread terminated: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	} catch (const ErrorException &e) {
		ERROR_LOG("ERROR Worker Thread terminated: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	TRACE_LOG("exit");
	return NULL;
}

void ThreadBase::set_thread_priority( int priority ) {
	int policy;
	struct sched_param	param;
	pthread_t self_th = ::pthread_self();
	{
		int res = ::pthread_getschedparam(self_th,&policy,&param);
		if ( res ) {
			// TODO: "::pthread_getschedparam() error"
			return;
		}
	}
	policy = SCHED_RR;
	int priority_max	= ::sched_get_priority_max(policy);
	int priority_min	= ::sched_get_priority_min(policy);
	int priority_nomal  = (priority_max + priority_min)/2;
	if ( priority == THREAD_PRIORITY_HIGHEST ) {
		param.sched_priority = priority_nomal + 2;
	} else if( priority == THREAD_PRIORITY_HIGHT ) {
		param.sched_priority = priority_nomal + 1;
	} else if( priority == THREAD_PRIORITY_NOMAL ) {
		param.sched_priority = priority_nomal;
	} else if( priority == THREAD_PRIORITY_LOWER ) {
		param.sched_priority = priority_nomal - 1;
	} else if( priority == THREAD_PRIORITY_LOWEST ) {
		param.sched_priority = priority_nomal - 2;
	} else {
		// TODO: "Invalid priority"
		return;
	}
	{
		int res = ::pthread_setschedparam(self_th,policy,&param);
		if ( res ) {
			// TODO: "::pthread_setschedparam() error"
			return ;
		}
	}
}

const pthread_t ThreadBase::getID() const {
	return this->th;
}

