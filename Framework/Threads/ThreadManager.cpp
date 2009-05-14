#include "ThreadManager.h"
#include "fanni/Exception.h"

using namespace Fanni;

ThreadManager::ThreadManager() {
	this->delivery_counter = 0;
	this->worker_number = 0;
	this->worker_sequence = SequenceGeneratorFactory::GetInstance()->createGenerator();
}

ThreadManager::~ThreadManager() {
	WORKER_MAP_TYPE::iterator it;
	for(it = this->worker_list.begin(); it != this->worker_list.end(); it++){
		ThreadWorker *worker = it->second;
		worker->stop();
	}
	for(it = this->worker_list.begin(); it != this->worker_list.end(); it++){
		ThreadWorker *worker = it->second;
		delete worker;
	}
	// TODO @@@ leak: sequence_generator
}

void ThreadManager::deliverTask(const ThreadTask *data) {
	ThreadWorker *worker = NULL;
	{
		S_MUTEX_LOCK l;
		l.lock( &this->worker_list_lock );
		this->delivery_counter++;
		// TODO: simple policy -> reasonable
		WORKER_ID_TYPE worker_id = this->delivery_counter % this->worker_number;
		worker = this->findWorkerById(worker_id);
	}
	if (worker) {
		worker->addTask(data);
	} else {
		WarnException::throw_exception(EXP_TEST, EXP_PRE_MSG, "failed to get worker");
	}
}

ThreadWorker *ThreadManager::findWorkerById(WORKER_ID_TYPE id) {
	ThreadWorker *ret = NULL;
	WORKER_MAP_TYPE::iterator it = this->worker_list.find(id);
	if(it != this->worker_list.end()){
		ret = it->second;
	}
	return ret;
}

void ThreadManager::addWorker(ThreadWorker *worker) {
	WORKER_ID_TYPE id = this->worker_sequence->next();
	worker->init(id);
	WORKER_MAP_TYPE::value_type val(id, worker);
	this->worker_list.insert(val);
	this->worker_number++; // TODO: get this from hashmap!!
}

void ThreadManager::join() {
	WORKER_MAP_TYPE::iterator it;
	for(it = this->worker_list.begin(); it != this->worker_list.end(); it++){
		ThreadWorker *worker = it->second;
		worker->join();
	}
}
