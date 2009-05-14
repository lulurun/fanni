#ifndef TIMER_H_
#define TIMER_H_

#include <ctime>

class Timer {
	clock_t counter;
public:
	Timer() : counter(0) {};
	bool elasped(clock_t ms) {
		clock_t tick = std::clock();
		if(tick - counter >= ms) {
			counter = tick;
			return true;
		}
		return false;
	}
};

#endif /*TIMER_H_*/
