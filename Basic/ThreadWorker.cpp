#include <memory>
#include "fanni/Exception.h"
#include "fanni/ThreadWorker.h"

using namespace std;
using namespace Fanni;
using namespace Poco;

Worker::Worker() : running(false) {
}

Worker::~Worker() {
	if (this->running) {
		this->stop();
	}
}

void Worker::addTask(Poco::Notification *data) {
	this->queue.enqueueNotification(data);
}

void Worker::run() {
	this->running = true;
	while (this->running) {
		Notification::Ptr task(this->queue.waitDequeueNotification());
		if (task) {
			// TODO @@@ try catch fanni exceptions
			this->doTask(task);
		}
		else break;
	}
}

void Worker::stop() {
	this->running = false;
}
