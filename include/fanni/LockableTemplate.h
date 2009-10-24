/*
 * LockableTemplate.h
 *
 *  Created on: Sep 1, 2009
 *      Author: lulu
 */

#ifndef LOCKABLETEMPLATE_H_
#define LOCKABLETEMPLATE_H_

#include "Poco/Mutex.h"

namespace Fanni {

// TODO @@@ experimental
template<typename T>
class lockable_impl: public T {
public:
	lockable_impl(const T &obj) :
		T(obj) {
	}
	operator T &() {
		return _obj;
	}
	operator const T &() const {
		return _obj;
	}
	lockable_impl &operator=(T obj) {
		_obj = obj;
		return *this;
	}

private:
	T _obj;
};

template<typename T>
class lockable: public lockable_impl<T> , public Poco::FastMutex {
private:
	typedef lockable_impl<T> LOCKABLE_IMPL;
public:
	lockable() :
		LOCKABLE_IMPL(T()), Poco::FastMutex() {
	}
	explicit lockable(const T &obj) :
		LOCKABLE_IMPL(obj) {
	}
	lockable &operator=(const T &obj) {
		LOCKABLE_IMPL & l = *this;
		l = obj;
		return *this;
	}
};

}

#endif /* LOCKABLETEMPLATE_H_ */
