#include "QueueFactory.h"

using namespace Fanni;

QueueFactory::QueueFactory() {}

QueueFactory::~QueueFactory() {
	for(QUEUE_LIST_TYPE::iterator it=this->queue_list.begin(); it!=this->queue_list.end(); it++) {
		delete *it;
	}
}

QueueFactory::QUEUE_TYPE *QueueFactory::createQueue() {
	QUEUE_TYPE *queue = new QUEUE_TYPE();
	this->queue_list.push_back(queue);
	return queue;
}

