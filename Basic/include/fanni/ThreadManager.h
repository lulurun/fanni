#ifndef THREAD_MANAGER_H_
#define THREAD_MANAGER_H_

#include <vector>
#include "Poco/ThreadPool.h"
#include "Poco/AtomicCounter.h"
#include "Poco/Mutex.h"
#include "fanni/Basic_def.h"
#include "fanni/ThreadWorker.h"

namespace Fanni {

class Fanni_API ThreadManager {
protected:
	typedef std::vector<WorkerPtr> WORKER_LIST_TYPE;
	WORKER_LIST_TYPE worker_list;
	Poco::AtomicCounter delivery_ac;

public:
	ThreadManager();
	virtual ~ThreadManager();
	void deliverTask(TaskPtr &pTask);
	void addWorker(WorkerPtr &pWorker);
	void stopAll();
};

}

#endif /*THREAD_MANAGER_H_*/
