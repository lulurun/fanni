/*
 * Timer.cpp
 *
 *  Created on: Aug 13, 2009
 *      Author: lulu
 */

#include <iostream>
#include "Threads/Timer.h"

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
		task.kick();
		task.join();
	}

	cout << "periodic" << endl;
	{ // PeriodicTask
		PeriodicTask task(2000, handler_B, 5);
		task.kick();
		task.join();
	}

	cout << "Thread timers" << endl;
	{
		PeriodicTask period_task(1000, handler_A, 7);
		period_task.kick();

		OneTimeTask onetime_task(1000, handler_B);
		onetime_task.kick();

		PeriodicTask period_task2(1000, handler_B, 5);
		period_task2.kick();

		onetime_task.join();
		period_task.join();
		period_task2.join();
	}

	cout << "infinite timer" << endl;
	{
		PeriodicTask period_task(1000, handler_A);
		period_task.kick();
		::sleep(10);
		period_task.stop();
	}

}

