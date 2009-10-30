#ifndef THREAD_WORKER_H_
#define THREAD_WORKER_H_

#include "Poco/Runnable.h"
#include "Poco/NotificationQueue.h"
#include "fanni/Basic_def.h"

namespace Fanni {

class Fanni_API Worker : public Poco::Runnable {
protected:
	Poco::NotificationQueue queue;

public:
	Worker();
	virtual ~Worker();
	void addTask(Poco::Notification *data);
	void run();
	void stop();

	virtual void doTask(Poco::Notification::Ptr &data) = 0;
};

}

#endif /*THREAD_WORKER_H_*/
