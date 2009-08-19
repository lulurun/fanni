#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>
#include "fanni/ThreadTemplate.h"
#include "fanni/Logger.h"

// TODO @@@ CPU cost !!, change to a better "TIMER"

namespace Fanni {

class OnTimerElapsedHandler {
public:
	OnTimerElapsedHandler() {};
	virtual ~OnTimerElapsedHandler() {};
	virtual void operator()() const = 0;
};

class TimeOutTaskBase : public ThreadHandlerBase {
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

public:
	TimeOutTaskBase(int milliseconds, const OnTimerElapsedHandler *handler) {
		this->period_ns = milliseconds  * NANOSEC_PER_MILLISEC;
		this->handler = handler;
	};
	~TimeOutTaskBase() {};
	// from ThreadHandlerBase
	virtual void setArg(void *arg) {};
	virtual void start() const = 0;
	virtual void operator()() { this->start(); }
};

static const uint32_t ELAPSE_CHECK_INTERVAL = 1000 * 1000; /* microseconds, I am using usleep! */
class OneTimeTask : public TimeOutTaskBase {
public:
	OneTimeTask(int milliseconds, const OnTimerElapsedHandler *handler) :
		TimeOutTaskBase(milliseconds, handler){};
	virtual void start() const {
		Timer timer;
		while(1) {
			if (timer.elapsed(this->period_ns)) {
				try {
					this->handler->operator()();
				} catch (ErrorException &e) {
					// TODO @@@ catch more general exceptions
					ERROR_LOG("OneTimeTask failed: " << e.get_msg());
				}
				break;
			}
			::usleep(ELAPSE_CHECK_INTERVAL);
		}
	}
};

class PeriodicTask : public TimeOutTaskBase {
private:
	int max_time;

public:
	PeriodicTask(int milliseconds, const OnTimerElapsedHandler *handler, int max_time = -1) :
		TimeOutTaskBase(milliseconds, handler), max_time(max_time) { };

	void stop() {};

	virtual void start() const {
		if (max_time > 0) {
			this->_start_limited();
		} else {
			this->_start_forever();
		}
	}

private:
	virtual void _start_limited() const {
		Timer timer;
		int count = 0;
		while(count < max_time) {
			if (timer.elapsed(this->period_ns)) {
				try {
					this->handler->operator()();
					count++;
				} catch (ErrorException &e) {
					// TODO @@@ catch more general exceptions
					ERROR_LOG("OneTimeTask failed: " << e.get_msg());
				}
				// TODO @@@ implement stop !!
			}
			::usleep(ELAPSE_CHECK_INTERVAL);
		}
	}

	virtual void _start_forever() const {
		Timer timer;
		while(1) {
			if (timer.elapsed(this->period_ns)) {
				try {
					this->handler->operator()();
				} catch (ErrorException &e) {
					// TODO @@@ catch more general exceptions
					ERROR_LOG("OneTimeTask failed: " << e.get_msg());
				}
				// TODO @@@ implement stop !!
			}
			::usleep(ELAPSE_CHECK_INTERVAL);
		}
	}
};

typedef ThreadTemplate<OneTimeTask> OneTimeTaskThread;
typedef ThreadTemplate<PeriodicTask> PeriodicTaskThread;

}

#endif /*TIMER_H_*/
