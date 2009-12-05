#ifndef THREAD_WORKER_H_
#define THREAD_WORKER_H_

#include <string>
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
	std::string _name;

	void run();
	virtual void doTask(TaskPtr &task) = 0;

public:
	Worker();
	virtual ~Worker();
	void addTask(TaskPtr &task);
	void setName(const std::string &name);

private:
	void start();
	void stop();
	// TODO @@@ unsafe??
	volatile bool _stop; // @@@ used for polling
};

}

#endif /*THREAD_WORKER_H_*/
