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
	INFO_LOG("Basic", "Worker stopped");
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
				ERROR_LOG("Basic", "worker loop terminated: " << e.message());
			}
		} else
			break;
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
				INFO_LOG("Basic", "Worker stopped successfully");
			} else {
				INFO_LOG("Basic", "Worker stopped after timeout");
			}
		} catch (Poco::Exception &ex) {
			ERROR_LOG("Basic", "Stop Worker Exception: " << ex.message());
		}
	}
}

