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

class Test_OnTimerElapsedHandler : public OnTimerElapsedHandler {
public:
	virtual void operator()() const {
		std::cout << "do task" << std::endl;
	}
};

}
}

using namespace std;
using namespace Fanni;
using namespace Fanni::Tests;

int main() {
	Test_OnTimerElapsedHandler *handler = new Test_OnTimerElapsedHandler();
/*
	cout << "one time" << endl;
	{ // OneTimeTask
		OneTimeTask task(1000, handler);
		task.start();
	}
*/
	cout << "periodic" << endl;
	{ // PeriodicTask
		PeriodicTask task(1000, handler);
		task.start();
	}
}

