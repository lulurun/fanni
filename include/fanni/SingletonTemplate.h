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

template<class T>
class Singleton {
private:
	static std::auto_ptr<T> instance;
	static std::once_flag flag;

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
std::once_flag Singleton<T>::flag = boost::BOOST_ONCE_INIT;

template<class T>
std::auto_ptr<T> Singleton<T>::instance;

#endif /* SINGLETONTEMPLATE_H_ */
