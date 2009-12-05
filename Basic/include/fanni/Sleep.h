/*
 * Logger.h
 *
 *  Created on: Apr 16, 2009
 *      Author: lulu
 */

#ifndef _FANNI_SLEEP_H_
#define _FANNI_SLEEP_H_

#include "Poco/Thread.h"

namespace Fanni {

inline void Sleep(long milliseconds) {
	Poco::Thread::sleep(milliseconds);
}

}


#endif _FANNI_SLEEP_H_
