#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>
#include "fanni/Logger.h"
#include "fanni/Exception.h"
#include "Thread.h"
#include "DataControl.h"

namespace Fanni {

class OnTimerElapsedHandler {
public:
	virtual void operator()() const = 0;
};

class TimeOutTaskBase : public ThreadBase {
	static const uint64_t NANOSEC_PER_SEC = 1000 * 1000 * 1000;
	static const uint64_t NANOSEC_PER_MILLISEC = 1000 * 1000;
protected:
	class Timer {
		timespec counter;
		uint64_t timespec_difference(timespec a, timespec b) {
			uint64_t nsec_a = (uint64_t)(a.tv_sec) * NANOSEC_PER_SEC + a.tv_nsec;
			uint64_t nsec_b = (uint64_t)(b.tv_sec) * NANOSEC_PER_SEC + b.tv_nsec;
			return nsec_b - nsec_a; // TODO @@@ b must be bigger than a
		}

		void reset() {
			::clock_gettime(CLOCK_REALTIME, &this->counter);
		};

	public:
		Timer() {
			this->reset();
		};

		bool elapsed(uint64_t ns) {
			timespec now;
			::clock_gettime(CLOCK_REALTIME, &now);
			if(this->timespec_difference(this->counter, now) > ns) {
				this->reset();
				return true;
			}
			return false;
		}
	};

	uint64_t period_ns;
	const OnTimerElapsedHandler *handler;
	uint32_t check_elapsed_interval_us;
	uint32_t timeout_msec;

public:
	TimeOutTaskBase(int msec, const OnTimerElapsedHandler *handler, int check_elapsed_interval = 0) {
		this->period_ns = msec * NANOSEC_PER_MILLISEC;
		this->timeout_msec = msec;
		this->handler = handler;
		if (check_elapsed_interval > 0) {
			this->check_elapsed_interval_us = check_elapsed_interval;
		} else {
			this->check_elapsed_interval_us = msec * 1000 / 2 - 10;
		}
	};
	~TimeOutTaskBase() {};
};

class OneTimeTask : public TimeOutTaskBase {
public:
	OneTimeTask(int msec, const OnTimerElapsedHandler *handler) :
		TimeOutTaskBase(msec, handler){};

private:
	virtual void start() {
		try {
			DataControlLock l;
			l.lock(&this->dc);
			dc.wait(this->timeout_msec);
			this->handler->operator()();
		} catch (ErrorException &e) {
			// TODO @@@ catch more exceptions
			ERROR_LOG("OneTimeTask failed: " << e.get_msg());
		}
	}

	virtual void loop_func() {};
};

class PeriodicTask : public TimeOutTaskBase {
private:
	int max;
	int count;

public:
	PeriodicTask(int msec, const OnTimerElapsedHandler *handler, int max = -1) :
		TimeOutTaskBase(msec, handler), max(max), count(0) { };

private:
	virtual void loop_func() {};

	virtual void start() {
		this->count = 0;
		if (this->max > 0) {
			this->_start_limited();
		} else {
			this->_start_forever();
		}
	}

	virtual void _start_limited() {
		while(this->dc.isActive()) {
			try {
				DataControlLock l;
				l.lock(&this->dc);
				this->dc.wait(this->timeout_msec);
				this->handler->operator()();
				if (this->count++ >= this->max) {
					this->stop();
				}
			} catch (ErrorException &e) {
				// TODO @@@ catch more exceptions
				ERROR_LOG("OneTimeTask failed: " << e.get_msg());
			}
		}
	}

	virtual void _start_forever() {
		while(this->dc.isActive()) {
			try {
				DataControlLock l;
				l.lock(&this->dc);
				this->dc.wait(this->timeout_msec);
				this->handler->operator()();
			} catch (ErrorException &e) {
				// TODO @@@ catch more exceptions
				ERROR_LOG("OneTimeTask failed: " << e.get_msg());
			}
		}
	}
};

}

#endif /*TIMER_H_*/
