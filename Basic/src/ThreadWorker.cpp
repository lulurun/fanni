#include <memory>
#include "fanni/Exception.h"
#include "fanni/Logger.h"
#include "fanni/ThreadWorker.h"

namespace Fanni {
class StopTask : public TaskBase {};
static TaskPtr StopTaskInstance(new StopTask());
}

using namespace std;
using namespace Fanni;
using namespace Poco;

Worker::Worker() : _stop(false) {
	this->start();
}

Worker::~Worker() {
	this->stop();
	DEBUG_LOG("worker stopped");
}

void Worker::addTask(TaskPtr &data) {
	this->_queue.put(data);
}

void Worker::run() {
	while (!_stop) {
		TaskPtr pTask(this->_queue.get());
		if (pTask && !dynamic_cast<StopTask *>(pTask.get())) {
			try {
				this->doTask(pTask);
			} catch (Poco::Exception &e) {
				ERROR_LOG("worker loop terminated: " << e.message());
			}
		} else {
			DEBUG_LOG("break worker loop");
			break;
		}
	}
}

void Worker::start() {
	this->_thread.start(*this);
}

void Worker::stop() {
	if (!_stop) {
		try {
			this->_stop = true;
			this->addTask(StopTaskInstance);
			if (this->_thread.tryJoin(5000)) {
				INFO_LOG("Worker stopped successfully");
			} else {
				WARN_LOG("Worker stopped after timeout");
			}
		} catch (Poco::Exception &ex) {
			ERROR_LOG("Stop Worker Exception: " << ex.message());
		}
	}
}

