/*
 * LockableTemplate.h
 *
 *  Created on: Sep 1, 2009
 *      Author: lulu
 */

#ifndef LOCKABLETEMPLATE_H_
#define LOCKABLETEMPLATE_H_

#include "Threads/DataControl.h"

namespace Fanni {

template<class T>
class lockable : public T {
	DataControl dc;
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
	DataControl &getDataControl() {
		return this->dc;
	}
};

}

#endif /* LOCKABLETEMPLATE_H_ */
