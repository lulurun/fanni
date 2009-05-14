#ifndef CALFOS_THREAD_H_
#define CALFOS_THREAD_H_

#include <pthread.h>
#include <string>

namespace Fanni {

class ThreadBase {
public:
	enum{
		THREAD_PRIORITY_LOWEST = 8,
		THREAD_PRIORITY_LOWER,
		THREAD_PRIORITY_NOMAL,
		THREAD_PRIORITY_HIGHT,
		THREAD_PRIORITY_HIGHEST,
	};
	static void set_thread_priority( int priority );
private:
	pthread_t th;
	int priority;
public:
	ThreadBase();
	virtual ~ThreadBase();
	virtual void stop() = 0;

	void kick( int priority = THREAD_PRIORITY_NOMAL );
	void join();
	const pthread_t getID() const;
private:
	static void * thread_handler( void * This );
protected:
	virtual void loop() = 0;
};

} // namespace


#endif /*CALFOS_THREAD_H_*/
