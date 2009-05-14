#include "ThreadWorker.h"
#include "fanni/Exception.h"

using namespace std;
using namespace Fanni;

ThreadWorker::ThreadWorker() { }

ThreadWorker::~ThreadWorker() {  }

void ThreadWorker::init(WORKER_ID_TYPE id) {
	this->id = id;
	this->queue = QueueFactory::GetInstance()->createQueue();
}

void ThreadWorker::addTask(const ThreadTask *data) {
	this->queue->push(data);
}

