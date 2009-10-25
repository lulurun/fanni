#include "fanni/ThreadManager.h"
#include "fanni/Exception.h"

using namespace Poco;
using namespace Fanni;

ThreadManager::ThreadManager() {
	// @@@ do not use the Poco::defaultpool
	this->thread_pool = new ThreadPool();
}

ThreadManager::~ThreadManager() {
	WORKER_LIST_TYPE::iterator it;
	for(WORKER_LIST_TYPE::iterator it = this->worker_list.begin(); it != this->worker_list.end(); it++){
		delete (*it);
	}
	delete this->thread_pool;
}

void ThreadManager::deliverTask(Poco::Notification *data) {
	Worker *worker = NULL;
	{
		this->delivery_ac++;
		// TODO @@@ simple delivery policy !!
		int idx = this->delivery_ac.value() % this->worker_list.size();
		worker = this->worker_list[idx];
	}
	if (worker) {
		worker->addTask(data);
	} else {
		WarnException::throw_exception(EXP_TEST, EXP_PRE_MSG, "failed to get worker");
	}
}

void ThreadManager::start() {
	for (WORKER_LIST_TYPE::iterator it = this->worker_list.begin(); it
			!= this->worker_list.end(); it++) {
		this->thread_pool->start(**it);
	}
}

void ThreadManager::addWorker(Worker *worker) {
	this->worker_list.push_back(worker);
}

void ThreadManager::stop() {
	for (WORKER_LIST_TYPE::iterator it = this->worker_list.begin(); it
			!= this->worker_list.end(); it++) {
		(*it)->stop();
	}
	this->thread_pool->joinAll();
}
