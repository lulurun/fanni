#ifndef QUEUE_H
#define QUEUE_H

// application header
#include "Mutex.h"

#include <unistd.h>
#include <sys/time.h>
#include <stdexcept>
using namespace std;

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/key_extractors.hpp>
#include <boost/multi_index/hashed_index.hpp>
using namespace boost;

class timeout_error {
//: public std::domain_error {
};
namespace Fanni {

enum{
	MODE_1,
	MODE_2,
};

template <typename DATA_TYPE,typename ORDER_TYPE = int64_t,int MODE = MODE_1>
	class Queue
{
public:
	enum TIMEOUT{
		TIMEOUT_INFINITY = -1,
		TIMEOUT_NO_WAIT	 = 0,
	};
	enum PRIORITY{ // priority
		PRIORITY_LOWEST = 20,
		PRIORITY_LOW,
		PRIORITY_NOMAL,
		PRIORITY_HIGH,
		PRIORITY_HIGHEST
	};
	typedef int32_t	PRIORITY_TYPE;


private:
	//-------------------------------------------------
	// custom lock .

	class QueueLockContl;
	class QueueLock {
		friend class QueueLockContl;
		Fanni::Mutex Lock;
		void unlock()	{ this->Lock.unlock();	}
		void lock()		{ this->Lock.lock(); 	}
		void trigger()	{ this->Lock.trigger();	}
		void wait(int t){ this->Lock.wait(t);	}
	};
	class QueueLockContl{
		bool	locked;
		QueueLock &obj;
	public:
		QueueLockContl(QueueLock &o) : obj(o) {
			this->lock();
		}
		~QueueLockContl() {
			this->unlock();
		}
		void lock(){
			this->obj.lock();
			this->locked = true;
		}
		void wait(int t){
//			if(this->locked){
				this->obj.wait(t);
//			}
		}
		void trigger(){
//			if(this->locked){
				this->obj.trigger();
//			}
		}
	private:
		void unlock(){
//			if(this->locked){
//				this->locked = false;
				this->obj.unlock();
//			}
		}
	};

	//-------------------------------------------------
	// queuing data.

	class QueueTimeb{
	public:
		int sec;
		int msec;
		void now(){
			struct timezone tz;
			struct timeval now;
			::gettimeofday(&now,&tz);
			sec = now.tv_sec;
			msec= now.tv_usec/1000;
		}
		QueueTimeb(int t = 0){
			if( t > 0 ) {
				this->now();
				(*this) += t;
			}else {
				sec = 0;
				msec= 0;
			}
		}
		int judge () const {
			int ret = 0;
			if( sec == 0 && msec == 0 ){
				ret = 0;
			}else{
				QueueTimeb n;
				n.now();
				ret = (*this) - n ;
				if(ret < 0 ){
					ret = 0;
				}
			}
			return ret;
		}
		QueueTimeb& operator += (int &in){
			sec		+= ((in + msec)/1000);
			msec	= ((in + msec)%1000);
			return (*this);
		}
		int operator - (const QueueTimeb &in)const{
			return (sec-in.sec)*1000 + (msec-in.msec);
		}
		int operator < (const QueueTimeb &in)const{
			return ((sec < in.sec)|| ((sec == in.sec && msec < in.msec)))?true:false;
		}
		int operator == (const QueueTimeb &in) const {
			return ((sec == in.sec) && (msec == in.msec));
		}
	};
	class DATA_CONTAINER
	{
	public:
		DATA_CONTAINER (const DATA_TYPE &d ,int t ,const PRIORITY_TYPE &p ,  ORDER_TYPE & om) : priority(p),timer(t),data(d) { order = om++; }
		PRIORITY_TYPE		priority;
		QueueTimeb			timer;
		DATA_TYPE			data;
		ORDER_TYPE			order;
		int		judge() const { return  timer.judge();	}
//		void print () const {
//			cout << "O : " << (int)order << " T : " << timer.sec << " P : " << priority ;
//			data->print();
//		}
	};
	template <int M>
		struct COMPARATOR
	{
		bool operator()(const DATA_CONTAINER& left, const DATA_CONTAINER& right) const {
			if(left.timer == right.timer){
				if(left.priority == right.priority){
					return (left.order < right.order);
				}
				return  (left.priority < right.priority);
			}
			return  (left.timer < right.timer);
		}
	};
//	template <>
//		struct COMPARATOR< MODE_2 >
//	{
//		bool operator()(const DATA_CONTAINER& left, const DATA_CONTAINER& right) const { return true;}
//	};
	typedef ::boost::multi_index::multi_index_container<
	   DATA_CONTAINER,
	   ::boost::multi_index::indexed_by<
	       ::boost::multi_index::ordered_unique		< ::boost::multi_index::member < DATA_CONTAINER , ORDER_TYPE , &DATA_CONTAINER::order > >,
	       ::boost::multi_index::ordered_unique		< ::boost::multi_index::identity < DATA_CONTAINER > , COMPARATOR < MODE > >
	   >
	> M_INDEX_LIST_TYPE;
	typedef typename ::boost::multi_index::nth_index<M_INDEX_LIST_TYPE,0>::type ORDER_SET_TYPE;
	typedef typename ::boost::multi_index::nth_index<M_INDEX_LIST_TYPE,1>::type SORT_SET_TYPE;

protected:
	ORDER_TYPE				OrderMaster;

	M_INDEX_LIST_TYPE		MIndexList;
	ORDER_SET_TYPE		&	OrderSet;
	SORT_SET_TYPE		&	SortSet;

	QueueLock				Lock;


public:
	Queue();
	~Queue();
	ORDER_TYPE		push		(const DATA_TYPE & data, int timeout = TIMEOUT_NO_WAIT,const PRIORITY_TYPE &priority = PRIORITY_NOMAL);
	DATA_TYPE 		pop			(int timeout = TIMEOUT_INFINITY,bool enable_throw = false); // throw logic_exception
	unsigned int	size		();
	DATA_TYPE		cancel		(const ORDER_TYPE &order);
};

//-------------------------------------------------
// Queue implementing part
template <typename DATA_TYPE,typename ORDER_TYPE,int MODE>
	Queue<DATA_TYPE,ORDER_TYPE,MODE>::Queue()
	:	OrderMaster((ORDER_TYPE)0),
		OrderSet(MIndexList.get<0>()),
		SortSet	(MIndexList.get<1>())
{
}
template <typename DATA_TYPE,typename ORDER_TYPE,int MODE>
	Queue<DATA_TYPE,ORDER_TYPE,MODE>::~Queue()
{
}

template <typename DATA_TYPE,typename ORDER_TYPE,int MODE>
	ORDER_TYPE	Queue<DATA_TYPE,ORDER_TYPE,MODE>::push(const DATA_TYPE & d,int t,const PRIORITY_TYPE &p)
{
	{ // < ** enter critical section ** >
		QueueLockContl l(this->Lock);

		DATA_CONTAINER dc(d,t,p,this->OrderMaster);
		this->OrderSet.insert(dc);
		l.trigger();
		return dc.order;
	} // < ** leave critical section ** >
}

template <typename DATA_TYPE,typename ORDER_TYPE,int MODE>
	DATA_TYPE Queue<DATA_TYPE,ORDER_TYPE,MODE>::pop(int timeout,bool enable_throw)
{
	// default retern value
	DATA_TYPE ret = 0;
	int wait_time = timeout;
	QueueTimeb first( timeout );

	{ // < ** enter critical section ** >
		QueueLockContl l(this->Lock);
		typename SORT_SET_TYPE::iterator it ;
		for(;;){
			it = this->SortSet.begin();
			if( it != this->SortSet.end() ){
				int rjudge = (*it).judge();
				if(rjudge == 0){
					break;
				}
				if( rjudge < wait_time || timeout == TIMEOUT_INFINITY){
					wait_time = rjudge;
				}
			}
			if(timeout == TIMEOUT_NO_WAIT ){
				if(enable_throw){
					throw timeout_error();
				}
				return ret;
			}
			// < ** leave critical section ** >
			l.wait(wait_time); // cond_wait : -1:infinite , 0:no wait , 1~:timeout [msec]
 			// < ** enter critical section ** >
 			if(timeout != TIMEOUT_INFINITY){
	 			wait_time = first.judge() ;
 				if(wait_time == 0){
					if(enable_throw){
						throw timeout_error();
					}
					return ret;
				}
			}
		}
		ret = (*it).data;
		this->SortSet.erase(it);
	} // < ** leave critical section ** >
	return ret;
}
template <typename DATA_TYPE,typename ORDER_TYPE,int MODE>
	unsigned int	Queue<DATA_TYPE,ORDER_TYPE,MODE>::size()
{
	{ // < ** enter critical section ** >
		QueueLockContl l(this->Lock);
		return this->OrderSet.size();
	} // < ** leave critical section ** >
}


template <typename DATA_TYPE,typename ORDER_TYPE,int MODE>
	DATA_TYPE	Queue<DATA_TYPE,ORDER_TYPE,MODE>::cancel(const ORDER_TYPE &order)
{
	DATA_TYPE ret = 0;
	{ // < ** enter critical section ** >
		QueueLockContl l(this->Lock);
		typename ORDER_SET_TYPE::iterator it = this->OrderSet.find(order);
		if( it != this->OrderSet.end() ){
			ret = (*it).data;
			this->OrderSet.erase(it);
		}
	} // < ** leave critical section ** >
	return ret;
}

} // namespace
#endif

