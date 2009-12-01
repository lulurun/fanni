/*
 * SingletonTemplate.h
 *
 *  Created on: Aug 5, 2009
 *      Author: lulu
 */

#ifndef SINGLETONTEMPLATE_H_
#define SINGLETONTEMPLATE_H_

#include <cassert>
#include <memory>
#include "Poco/Mutex.h"

namespace Fanni {

/*
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
*/

template <class T>
class Singleton
{
public:
  static T &get() {
	  static T *m_pInstance = NULL;
	  if(!m_pInstance) {
		  m_pInstance = new T;
	  }
      assert(m_pInstance !=NULL);
      return *m_pInstance;
  }
protected:
  Singleton();
  ~Singleton();
private:
  Singleton(Singleton const&);
  Singleton& operator=(Singleton const&);
};

}

#endif /* SINGLETONTEMPLATE_H_ */
