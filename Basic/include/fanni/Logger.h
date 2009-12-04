/*
 * Logger.h
 *
 *  Created on: Apr 16, 2009
 *      Author: lulu
 */

#ifndef FANNI_LOGGER_H_
#define FANNI_LOGGER_H_

#include <string>
#include "Poco/Logger.h"
#include "Poco/SharedPtr.h"
#include "Poco/LogStream.h"
#include "fanni/Basic_def.h"

namespace Fanni {

// TODO @@@ how to manage multiple _loggers
class Fanni_API Logger {
public:
	static Poco::SharedPtr<Poco::LogStream> &LogStream();
	static void Initialize();
};

#ifdef _DEBUG

#ifndef WIN32
#define TRACE_LOG(message)	\
	{ Logger::pLogStream->trace() << __PRETTY_FUNCTION__ << " " << message << std::endl; }
#else
#define TRACE_LOG(message)
#endif
#define DEBUG_LOG(...)	\
	{ Logger::LogStream()->debug() << __VA_ARGS__ << std::endl; }
#else
#define TRACE_LOG(message)
#define DEBUG_LOG(...)
#endif

#define INFO_LOG(...)	\
	{ Logger::LogStream()->information() << __VA_ARGS__ << std::endl; }
#define WARN_LOG(...)	\
	{ Logger::LogStream()->warning() << __VA_ARGS__ << std::endl; }
#define ERROR_LOG(...)	\
	{ Logger::LogStream()->error() << __VA_ARGS__ << std::endl; }
#define FATAL_LOG(...)	\
	{ Logger::LogStream()->fatal() << __VA_ARGS__ << std::endl; }

}

#endif /* LOGGER_H_ */
