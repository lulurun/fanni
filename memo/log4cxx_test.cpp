/*
 * log4cxx_test.cpp
 *
 *  Created on: Apr 16, 2009
 *      Author: lulu
 */

#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"

namespace com {
namespace foo {

// Single thread
class Bar {
	static log4cxx::LoggerPtr logger;

public:
	void doIt();
};
}
}

using namespace log4cxx;
using namespace log4cxx::helpers;
using namespace com::foo;

LoggerPtr logger(Logger::getLogger("MyApp"));
LoggerPtr Bar::logger(Logger::getLogger("com.foo.bar"));

void Bar::doIt() {
	LOG4CXX_DEBUG(logger, "Did it again!");
}

// Multiple thread
#include <iostream>
#include "Threads/ThreadManager.h"
#include "Threads/ThreadWorker.h"

using namespace std;
using namespace Fanni;

class LoggerWorker : public ThreadWorker {
private:
	int count;
public:
	LoggerWorker() {
		this->count = 1000;
	};
	virtual void loop() {
		while(1) {
			LOG4CXX_INFO(logger, "worker loop");
		}
	};
};

class LoggerManager : public ThreadManager {
public:
	virtual void init() {
		for (int i=0; i<5; i++) {
			LoggerWorker *w = new LoggerWorker();
			this->addWorker(w);
			w->kick();
		}
	};
};

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char **argv) {
	cout << "Single Thread" << endl;
	int result = EXIT_SUCCESS;
	try {
		if (argc > 1) {
			// BasicConfigurator replaced with PropertyConfigurator.
			PropertyConfigurator::configure(argv[1]);
		} else {
			BasicConfigurator::configure();
		}

		LOG4CXX_INFO(logger, "Entering application.");
		Bar bar;
		bar.doIt();
		LOG4CXX_INFO(logger, "Exiting application.");
	} catch (Exception&) {
		result = EXIT_FAILURE;
	}

	cout << "Multiple Thread" << endl;
	LoggerManager m;
	m.init();

	for(int i=0; i<1000; i++) {
		LOG4CXX_INFO(logger, "main worker loop");
	}

	m.join();
	return result;
}

