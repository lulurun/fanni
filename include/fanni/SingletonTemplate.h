/*
 * SingletonTemplate.h
 *
 *  Created on: Aug 5, 2009
 *      Author: lulu
 */

#ifndef SINGLETONTEMPLATE_H_
#define SINGLETONTEMPLATE_H_

#include <iostream>
#include <memory>
#include <boost/thread.hpp>

namespace Fanni {

template<class T>
class Singleton {
private:
	static std::auto_ptr<T> instance;
	static boost::once_flag flag;

	static void init() {
		instance.reset( new T );
	}

public:
	static T &get() {
		boost::call_once( &Singleton::init, flag );
		return *instance;
	}
};

template<class T>
boost::once_flag Singleton<T>::flag = BOOST_ONCE_INIT;

template<class T>
std::auto_ptr<T> Singleton<T>::instance;

}

#endif /* SINGLETONTEMPLATE_H_ */
