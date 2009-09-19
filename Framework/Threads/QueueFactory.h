#ifndef _QUEUEFACTORY_H_
#define _QUEUEFACTORY_H_

#include <list>
#include "MyQueue.h"
#include "ThreadTask.h"
#include "fanni/SingletonTemplate.h"

namespace Fanni {

class QueueFactory {
	friend class Singleton<QueueFactory>;
public:
	typedef MyQueue<const ThreadTask *> QUEUE_TYPE;
	typedef std::list<QUEUE_TYPE *> QUEUE_LIST_TYPE;

private:
	QUEUE_LIST_TYPE queue_list;

public:
	QueueFactory();
	virtual ~QueueFactory();
	QUEUE_TYPE *createQueue();
};

typedef Singleton<QueueFactory> QueueFactorySingleton;
}

#endif /*FP_QUEUEFACTORY_H_*/
