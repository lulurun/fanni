#ifndef THREAD_WORKER_H_
#define THREAD_WORKER_H_

#include <string>
#include "Poco/SharedPtr.h"
#include "Poco/Runnable.h"
#include "Poco/Thread.h"
#include "Poco/AtomicCounter.h"
#include "fanni/Basic_def.h"
#include "fanni/TaskQueue.h"

namespace Fanni {

class Fanni_API Worker : public Poco::Runnable {
private:
	void setBusy() { this->_busy = 1; }
	void setFree() { this->_busy = 0; }

protected:
	Poco::Thread _thread;
	TaskQueue _queue;
	std::string _name;

	Poco::AtomicCounter _busy;

	void run();
	virtual void doTask(TaskPtr &task) = 0;

public:
	Worker();
	virtual ~Worker();
	void addTask(TaskPtr &task);
	void addUrgentTask(TaskPtr &task);
	void setName(const std::string &name);

	void start();
	void stop();

	bool isFree() const { return !this->_busy; };

protected:
	// TODO @@@ unsafe??
	volatile bool _stop; // @@@ used for polling
};

typedef Poco::SharedPtr<Worker> WorkerPtr;

/*
template<class T>
class Fanni_API ThreadWorker : public Poco::Runnable {
private:
	typedef T
protected:
	Poco::Thread _thread;
	Queue<T> _queue;
	std::string _name;

	void run() {
		while (!_stop) {
			TaskPtr pTask(this->_queue.get());
			if (pTask) {
				try {
					this->doTask(pTask);
				} catch (Poco::Exception &e) {
					ERROR_LOG(this->_name << " caught exception: " << e.message());
				}
			} else {
				break;
			}
		}
	};
	virtual void doTask(T &task) = 0;

	void start() {
		this->_thread.start(*this);
	};
	void stop() {
		if (!_stop) {
			try {
				this->_stop = true;
				this->addUrgentTask(StopTaskInstance);
				if (!this->_thread.tryJoin(5000)) {
					WARN_LOG("Worker stopped after timeout");
				}
			} catch (Poco::Exception &ex) {
				ERROR_LOG("Stop Worker Exception: " << ex.message());
			}
		}
	};

public:
	ThreadWorker() : _name(""), _stop(false){
		this->start();
	};
	virtual ~ThreadWorker() {
		this->stop();
	};
	void addTask(T &task) {
		this->queue.put(task);
	};
	void addUrgentTask(T &task) {
		this->queue.put_front(task);
	};
	void setName(const std::string &name) {
		this->name = name;
	};

protected:
	// TODO @@@ unsafe??
	volatile bool _stop; // @@@ used for polling
};

*/

}

#endif /*THREAD_WORKER_H_*/
