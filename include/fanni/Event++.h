#ifndef FANNI_EVENT_H_
#define FANNI_EVENT_H_

#include <sys/time.h>
#include <sys/types.h>
#include <event.h>
#include <stdio.h>
#include "fanni/Exception.h"
#include "fanni/Logger.h"

namespace Fanni {

template <class HANDLER>
class EventBase : public ::event{
public:
	EventBase(int fd, short flags, void *h) {
		::event_set(this, fd, flags, &this->caller, h);
	};
	virtual ~EventBase() {};
protected:
	static void caller(int fd, short flags, void *h) {
		// TODO @@@ how to catch exceptions???
		HANDLER &handler = *reinterpret_cast< HANDLER* >(h);
		handler(fd, flags);
	};
};

class EventHandlerBase {
public:
	EventHandlerBase() { }
	virtual ~EventHandlerBase(){ }
	virtual void operator() (int fd, short flags) const = 0;
};

class EventManager {
private:
	event_base *_event_base;
public:
	EventManager() {
	  // TODO @@@ reinterpret_cast is for older libevent(1.3)
		TRACE_LOG("enter");
		this->_event_base = reinterpret_cast<event_base *>(event_init());
		TRACE_LOG("exit");
	};
	~EventManager() {
		TRACE_LOG("enter");
		event_base_free(this->_event_base);
		TRACE_LOG("exit");
	};
	void add(::event *e) {
		event_base_set(this->_event_base, e);
		event_add(e, 0);
	};
	void del(::event *e) {
		event_del(e);
	};
	int dispatch(int flags = 0) {
		return event_base_loop(this->_event_base, flags);
	}

};

};

#endif // EVENT++_H_

