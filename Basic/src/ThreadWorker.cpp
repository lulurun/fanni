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

Worker::Worker() : _name(""), _stop(false) {
	this->start();
}

Worker::~Worker() {
	this->stop();
}

void Worker::setName(const std::string &name) {
	this->_name = name;
}

void Worker::addTask(TaskPtr &data) {
	this->_queue.put(data);
}

void Worker::addUrgentTask(TaskPtr &data) {
	this->_queue.put_front(data);
}

void Worker::run() {
	while (!_stop) {
		TaskPtr pTask(this->_queue.get());
		if (pTask && !dynamic_cast<StopTask *>(pTask.get())) {
			try {
				this->doTask(pTask);
			} catch (Poco::Exception &e) {
				ERROR_LOG(this->_name << " caught exception: " << e.message());
			}
		} else {
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
			this->addUrgentTask(StopTaskInstance);
			if (!this->_thread.tryJoin(5000)) {
				WARN_LOG("Worker stopped after timeout");
			}
		} catch (Poco::Exception &ex) {
			ERROR_LOG("Stop Worker Exception: " << ex.message());
		}
	}
}

