/*
 * Timer.cpp
 *
 *  Created on: Aug 13, 2009
 *      Author: lulu
 */

#include <iostream>
#include "fanni/Timer.h"

namespace Fanni {
namespace Tests {

class Test_OnTimerElapsedHandler_A : public OnTimerElapsedHandler {
public:
	virtual void operator()() const {
		std::cout << "do task A" << std::endl;
	}
};

class Test_OnTimerElapsedHandler_B : public OnTimerElapsedHandler {
public:
	virtual void operator()() const {
		std::cout << "do task B" << std::endl;
	}
};

}
}

using namespace std;
using namespace Fanni;
using namespace Fanni::Tests;

int main() {
	Test_OnTimerElapsedHandler_A *handler_A = new Test_OnTimerElapsedHandler_A();
	Test_OnTimerElapsedHandler_B *handler_B = new Test_OnTimerElapsedHandler_B();

	cout << "one time" << endl;
	{ // OneTimeTask
		OneTimeTask task(1000, handler_A);
		task.start();
	}
	cout << "periodic" << endl;
	{ // PeriodicTask
		PeriodicTask task(2000, handler_B, 5);
		task.start();
	}

	cout << "Thread timers" << endl;
	PeriodicTask period_task(1000, handler_A, 7);
	PeriodicTaskThread PeriodicTask_thread(&period_task);
	PeriodicTask_thread.kick();

	OneTimeTask onetime_task(1000, handler_B);
	OneTimeTaskThread OneTimeTask_thread(&onetime_task);
	OneTimeTask_thread.kick();
	OneTimeTask_thread.join();

	PeriodicTask period_task2(1000, handler_B, 5);
	PeriodicTaskThread PeriodicTask_thread2(&period_task2);
	PeriodicTask_thread2.kick();

	PeriodicTask_thread.join();
	PeriodicTask_thread2.join();
}

