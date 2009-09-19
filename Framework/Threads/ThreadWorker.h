#ifndef THREAD_WORKER_H_
#define THREAD_WORKER_H_

#include "Thread.h"
#include "QueueFactory.h"

namespace Fanni {

typedef uint32_t WORKER_ID_TYPE;

class ThreadWorker : public ThreadBase {
protected:
	WORKER_ID_TYPE id;
	QueueFactory::QUEUE_TYPE *queue;

public:
	ThreadWorker();
	virtual ~ThreadWorker();
	void init(WORKER_ID_TYPE id);
	void addTask(const ThreadTask *data);
	const ThreadTask *getTask();
};

}

#endif /*THREAD_WORKER_H_*/
