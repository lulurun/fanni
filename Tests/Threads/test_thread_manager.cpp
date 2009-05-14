#include <string>
#include <iostream>
#include "ThreadWorker.h"
#include "ThreadManager.h"
#include "SeqGenerator.h"
#include "fanni/Exception.h"

using namespace std;
using namespace Fanni;

class ConsumerManager;
class ProducerManager;

static const int start_number = 0;
static SequenceGenerator *seq_gen = SequenceGeneratorFactory::GetInstance()->createGenerator(100000000);

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

	virtual void loop() {
		while(1) {
			// get data
			const ThreadTask *task = this->queue->pop();
			const IntData *queue_data = dynamic_cast<const IntData *>(task);
			if (!queue_data) {
				FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG, "unexpected queue data type");
			}
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
public:
	Producer(int loop_number, ConsumerManager *c_mgr) {
		this->loop_number = loop_number;
		this->c_mgr = c_mgr;
	}

	virtual void stop() {
		// TODO @@@ do something
	}

	virtual void loop() {
		int i = 0;
		while(i++ < this->loop_number) {
			int new_int = seq_gen->next();
			IntData *data = new IntData(new_int);
			// call handler
			printf("producer[%d]: %d\n", this->id, new_int);
			this->c_mgr->deliverTask(data);
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

