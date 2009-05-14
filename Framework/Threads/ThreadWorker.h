#ifndef FP_WORKER_H_
#define FP_WORKER_H_

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
	virtual void loop() = 0;
	void addTask(const ThreadTask *data);
	void init(WORKER_ID_TYPE id);
};

}

#endif /*FP_WORKER_H_*/
