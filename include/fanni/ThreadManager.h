#ifndef THREAD_MANAGER_H_
#define THREAD_MANAGER_H_

#include <vector>
#include "ThreadWorker.h"
#include "Poco/ThreadPool.h"
#include "Poco/AtomicCounter.h"
#include "Poco/Mutex.h"

namespace Fanni {

// TOOD @@@ worker_id_type should be defined here
class ThreadManager {
protected:
	typedef std::vector<Worker *> WORKER_LIST_TYPE;
	WORKER_LIST_TYPE worker_list;
	Poco::ThreadPool *thread_pool;
	Poco::AtomicCounter delivery_ac;

	virtual void addWorker(Worker *worker);

public:
	ThreadManager();
	virtual ~ThreadManager();
	void deliverTask(Poco::Notification *data);
	void start();
	void stop();
	void join();
};

}

#endif /*THREAD_MANAGER_H_*/