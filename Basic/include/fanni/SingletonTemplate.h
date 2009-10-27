/*
 * SingletonTemplate.h
 *
 *  Created on: Aug 5, 2009
 *      Author: lulu
 */

#ifndef SINGLETONTEMPLATE_H_
#define SINGLETONTEMPLATE_H_

#include <memory>
#include "Poco/Mutex.h"

namespace Fanni {

// TODO @@@ not thrad safe
template<class T>
class Singleton {
private:
	static std::auto_ptr<T> instance;
	static Poco::Mutex mutex;

public:
	static T &get() {
		Poco::Mutex::ScopedLock l(mutex);
		if (instance.get() == NULL) {
			instance.reset(new T());
		}
		return *instance;
	}
};

template<class T>
std::auto_ptr<T> Singleton<T>::instance(NULL);

template<class T>
Poco::Mutex Singleton<T>::mutex;

}

#endif /* SINGLETONTEMPLATE_H_ */
