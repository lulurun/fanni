#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>
#include "fanni/ThreadTemplate.h"
#include "fanni/Logger.h"

namespace Fanni {

class OnTimerElapsedHandler {
public:
	OnTimerElapsedHandler() {};
	virtual ~OnTimerElapsedHandler() {};
	virtual void operator()() const = 0;
};

// TODO @@@ BUG!!!!
class Timer {
	clock_t counter;
public:
	Timer() : counter(0) {};
	bool elapsed(clock_t ms) {
		clock_t tick = std::clock();
		if(tick - counter >= ms) {
			counter = tick;
			return true;
		}
		return false;
	}
};

class TimeOutTaskBase : public ThreadHandlerBase{
protected:
	clock_t period;
	const OnTimerElapsedHandler *handler;

public:
	TimeOutTaskBase(int ms, const OnTimerElapsedHandler *handler) {
		this->period = CLOCKS_PER_SEC * 1000 / ms;
		this->handler = handler;
	};
	~TimeOutTaskBase() {};
	virtual void start() const = 0;

	// from ThreadHandlerBase
	virtual void setArg(void *arg) {};

	virtual void operator()() {
		this->start();
	}
};

class OneTimeTask : TimeOutTaskBase {
public:
	OneTimeTask(int ms, const OnTimerElapsedHandler *handler) : TimeOutTaskBase(ms, handler){};

	virtual void start() const {
		Timer timer;
		while(1) {
			if (timer.elapsed(this->period)) {
				try {
					this->handler->operator()();
				} catch (ErrorException &e) {
					// TODO @@@ catch more general exceptions
					ERROR_LOG("OneTimeTask failed: " << e.get_msg());
				}
				break;
			}
		}
	}
};

class PeriodicTask : public TimeOutTaskBase {
private:
	int max_time;
public:
	PeriodicTask(int ms, const OnTimerElapsedHandler *handler, int max_time = -1) :
		TimeOutTaskBase(ms, handler), max_time(max_time) { };

	void stop() {};

	virtual void start() const {
		Timer timer;
		while(1) {
			if (timer.elapsed(this->period)) {
				try {
					this->handler->operator()();
				} catch (ErrorException &e) {
					// TODO @@@ catch more general exceptions
					ERROR_LOG("OneTimeTask failed: " << e.get_msg());
				}
				// TODO @@@ implement stop !!
			}
		}
	}

};

typedef ThreadTemplate<OneTimeTask> OneTimeThread;
typedef ThreadTemplate<PeriodicTask> PeriodicTaskThread;

}

#endif /*TIMER_H_*/
