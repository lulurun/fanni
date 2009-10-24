#ifndef THREAD_WORKER_H_
#define THREAD_WORKER_H_

#include "Poco/Runnable.h"
#include "Poco/NotificationQueue.h"

namespace Fanni {

class Worker : public Poco::Runnable {
protected:
	Poco::NotificationQueue queue;
	bool running;

public:
	Worker();
	virtual ~Worker();
	void addTask(Poco::Notification *data);
	void run();
	void stop();

	virtual void doTask(Poco::Notification *data) = 0;
};

}

#endif /*THREAD_WORKER_H_*/
