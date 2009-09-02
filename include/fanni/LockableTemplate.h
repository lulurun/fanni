/*
 * LockableTemplate.h
 *
 *  Created on: Sep 1, 2009
 *      Author: lulu
 */

#ifndef LOCKABLETEMPLATE_H_
#define LOCKABLETEMPLATE_H_

#include "Threads/Mutex.h"

namespace Fanni {

template<class T>
class lockable : public T {
	Mutex m;
public:
	lockable() : T() {}
	explicit lockable(const T &obj) : T(obj){}
	lockable &operator=(const T &obj) {
		if (this != &obj) {
			T &b = *this;
			b = obj;
			return *this;
		}
	}
	Mutex &getMutex() {
		return this->m;
	}
};

}

#endif /* LOCKABLETEMPLATE_H_ */
