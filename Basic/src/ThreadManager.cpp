#include "fanni/Logger.h"
#include "fanni/ThreadManager.h"
#include "fanni/Exception.h"

using namespace Poco;
using namespace Fanni;

ThreadManager::ThreadManager() {}

ThreadManager::~ThreadManager() {}

void ThreadManager::deliverTask(TaskPtr &pTask) {
	for (WORKER_LIST_TYPE::iterator it = this->worker_list.begin(); it!= this->worker_list.end(); it++) {
		if ((*it)->isFree()) {
			(*it)->addTask(pTask);
			return;
		}
	}
	// can not find a free worker
	this->delivery_ac++;
	int idx = this->delivery_ac.value() % this->worker_list.size();
	this->worker_list[idx]->addTask(pTask);
}

void ThreadManager::addWorker(WorkerPtr &pWorker) {
	this->worker_list.push_back(pWorker);
}

void ThreadManager::stopAll() {
	for (WORKER_LIST_TYPE::iterator it = this->worker_list.begin(); it!= this->worker_list.end(); it++) {
		(*it)->stop();
	}
	this->worker_list.clear();
	DEBUG_LOG("ThreadManager stopped");
}

