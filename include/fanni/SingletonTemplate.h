/*
 * SingletonTemplate.h
 *
 *  Created on: Aug 5, 2009
 *      Author: lulu
 */

#ifndef SINGLETONTEMPLATE_H_
#define SINGLETONTEMPLATE_H_

#include <memory>

namespace Fanni {

// TODO @@@ not thrad safe
template<class T>
class Singleton {
private:
	static T *instance;

public:
	static T &get() {
		if (instance == NULL) {
			instance = new T();
		}
		return *instance;
	}
};

template<class T>
T *Singleton<T>::instance = NULL;

}

#endif /* SINGLETONTEMPLATE_H_ */
