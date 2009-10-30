#include <memory>
#include "fanni/Exception.h"
#include "fanni/Logger.h"
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
			try {
				this->doTask(task);
			} catch (ErrorException &e) {
				ERROR_LOG("rUDP", "packet handler failed. Exception: " << e.get_func()
					<< " at L" << e.get_line() << " " << e.get_msg());
			} catch (WarnException &e) {
				WARN_LOG("rUDP", "packet handler failed. Exception: " << e.get_func()
					<< " at L" << e.get_line() << " " << e.get_msg());
			} catch (FatalException &e) {
				FATAL_LOG("rUDP", "receiver loop terminated. FATAL ERROR: " << e.get_func()
					<< " at L" << e.get_line() << " " << e.get_msg());
				this->stop();
			}
		} else
			break;
	}
}

void Worker::stop() {
	// MEMO @@@ this will cause the above "if (task)" return false
	this->queue.wakeUpAll();
}
