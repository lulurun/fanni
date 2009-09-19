#ifndef THREAD_MANAGER_H_
#define THREAD_MANAGER_H_

#include <tr1/unordered_map>
#include "DataControl.h"
#include "ThreadTask.h"
#include "ThreadWorker.h"
#include "SeqGenerator.h"

namespace Fanni {

// TOOD @@@ worker_id_type should be defined here
class ThreadManager {
protected:
	typedef std::tr1::unordered_map<WORKER_ID_TYPE, ThreadWorker *> WORKER_MAP_TYPE;
	DataControl worker_list_lock;
	WORKER_MAP_TYPE worker_list;
	uint32_t delivery_counter;
	int worker_number;
	SequenceGenerator seq_gen;
	ThreadWorker *findWorkerById(WORKER_ID_TYPE id);

	ThreadManager();
public:
	virtual ~ThreadManager();
	virtual void init() = 0;
	void deliverTask(const ThreadTask *data);
	void addWorker(ThreadWorker *worker);
	void join();
};

template<class WorkerType>
class ThreadManagerTemplate: public ThreadManager {
private:
	int init_worker_number;
public:
	ThreadManagerTemplate(int init_worker_number) :
		init_worker_number(init_worker_number) {
	}
	virtual ~ThreadManagerTemplate() {
		WORKER_MAP_TYPE::iterator it;
		for (it = this->worker_list.begin(); it != this->worker_list.end(); it++) {
			ThreadWorker *worker = it->second;
			worker->stop();
			delete worker;
		}
	}
	virtual void init() {
		for (int i = 0; i < this->init_worker_number; i++) {
			WorkerType *w = new WorkerType();
			this->addWorker(w);
			w->kick();
		}
	}
};

}

#endif /*THREAD_MANAGER_H_*/
