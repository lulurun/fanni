/*
 * TaskQueue.h
 *
 *  Created on: Sep 18, 2009
 *      Author: lulu
 */

#ifndef FANNI_TASKQUEUE_H_
#define FANNI_TASKQUEUE_H_

#include "Poco/SharedPtr.h"
#include "fanni/Queue.h"

namespace Fanni {

class TaskBase {
public:
	TaskBase() {};
	virtual ~TaskBase() {};
};

typedef Poco::SharedPtr<TaskBase> TaskPtr;
typedef Queue<TaskPtr> TaskQueue;

}

#endif /* FANNI_TASKQUEUE_H_ */

