#include "ThreadWorker.h"
#include "fanni/Exception.h"

using namespace std;
using namespace Fanni;

ThreadWorker::ThreadWorker() { }

ThreadWorker::~ThreadWorker() {  }

void ThreadWorker::init(WORKER_ID_TYPE id) {
	this->id = id;
	this->queue = QueueFactorySingleton::get().createQueue();
}

void ThreadWorker::addTask(const ThreadTask *data) {
	this->queue->put(data);
}

const ThreadTask *ThreadWorker::getTask() {
	return this->queue->get();
}
