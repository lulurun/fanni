#ifndef THREAD_WORKER_H_
#define THREAD_WORKER_H_

#include "Poco/SharedPtr.h"
#include "Poco/Runnable.h"
#include "Poco/Thread.h"
#include "fanni/Basic_def.h"
#include "fanni/TaskQueue.h"

namespace Fanni {

class Fanni_API Worker : public Poco::Runnable {
protected:
	Poco::Thread _thread;
	TaskQueue _queue;

	void run();
	virtual void doTask(TaskPtr &task) = 0;

public:
	Worker();
	virtual ~Worker();
	void addTask(TaskPtr &task);
	void start();
	void stop();

private:
	bool _stop; // TODO @@@ unsafe??
};

}

#endif /*THREAD_WORKER_H_*/
