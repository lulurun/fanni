#include <cassert>
#include <string>
#include <iostream>
#include "fanni/Exception.h"

#include "Threads/ThreadWorker.h"
#include "Threads/ThreadManager.h"
#include "Threads/SeqGenerator.h"

using namespace std;
using namespace Fanni;

class ConsumerManager;
class ProducerManager;

static const int start_number = 0;
static SequenceGenerator seq_gen;

class IntData : public ThreadTask {
public:
	int data;
	IntData(int data) {
		this->data = data;
	}
};

class Consumer : public ThreadWorker {
public:
	virtual void stop() {
		// TODO @@@ do something
	}

	virtual void loop_func() {
		// get data
		const IntData *queue_data = dynamic_cast<const IntData *>(this->getTask());
		assert(queue_data);
		auto_ptr<const IntData> data(queue_data);
		// call handler
		printf("\t\tconsumer[%d]: %d\n", this->id, queue_data->data);
		if (queue_data->data == 4999) {
			printf("\t\tconsumer[%d]: get 4999 !!\n", this->id);
			printf("\t\tconsumer[%d]: get 4999 !!\n", this->id);
			printf("\t\tconsumer[%d]: get 4999 !!\n", this->id);
			printf("\t\tconsumer[%d]: get 4999 !!\n", this->id);
			printf("\t\tconsumer[%d]: get 4999 !!\n", this->id);
			printf("\t\tconsumer[%d]: get 4999 !!\n", this->id);
			printf("\t\tconsumer[%d]: get 4999 !!\n", this->id);
		}
	}
};

class ConsumerManager : public ThreadManager {
private:
	int thread_number;
public:
	ConsumerManager(int thread_number) {
		this->thread_number = thread_number;
	}

	virtual void init() {
		for(int i=0; i<this->thread_number; i++) {
			Consumer *worker = new Consumer();
			this->addWorker(worker);
			worker->kick();
		}
	}
};

class Producer : public ThreadWorker {
private:
	int loop_number;
	ConsumerManager *c_mgr;

	int inner_count;
public:
	Producer(int loop_number, ConsumerManager *c_mgr) {
		this->loop_number = loop_number;
		this->c_mgr = c_mgr;
		this->inner_count = 0;
	}

	virtual void stop() {
		// TODO @@@ do something
	}

	virtual void loop_func() {
		int new_int = seq_gen.next();
		IntData *data = new IntData(new_int);
		// call handler
		printf("producer[%d]: %d\n", this->id, new_int);
		this->c_mgr->deliverTask(data);
		if (inner_count++ > loop_number) {
			// TODO @@@ stop;
		}
	}
};

class ProducerManager : public ThreadManager {
private:
	int thread_number;
	int loop;
	ConsumerManager *c_mgr;
public:
	ProducerManager(int thread_number, int loop, ConsumerManager *c_mgr) {
		this->thread_number = thread_number;
		this->loop = loop;
		this->c_mgr = c_mgr;
	}

	virtual void init() {
		for(int i=0; i<this->thread_number; i++) {
			Producer *worker = new Producer(this->loop, this->c_mgr);
			this->addWorker(worker);
			worker->kick();
		}
	}
};


int main() {
	ConsumerManager *c_mgr = new ConsumerManager(5);
	c_mgr->init();
	ProducerManager *p_mgr = new ProducerManager(5, 1000, c_mgr);
	p_mgr->init();
	sleep(100);
}

