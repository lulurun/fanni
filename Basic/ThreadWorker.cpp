#include <memory>
#include "fanni/Exception.h"
#include "fanni/ThreadWorker.h"

using namespace std;
using namespace Fanni;
using namespace Poco;

Worker::Worker() {
}

Worker::~Worker() {
}

void Worker::addTask(Poco::Notification *data) {
	this->queue.enqueueNotification(data);
}

void Worker::run() {
	while (true) {
		Notification::Ptr task(this->queue.waitDequeueNotification());
		if (task) {
			// TODO @@@ try catch fanni exceptions
			this->doTask(task);
		} else
			break;
	}
}

void Worker::stop() {
	this->queue.wakeUpAll();
}
