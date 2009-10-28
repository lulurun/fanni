/*
 * Logger.h
 *
 *  Created on: Apr 16, 2009
 *      Author: lulu
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "Poco/Logger.h"
#include "Poco/LogStream.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/Message.h"
#include "fanni/SingletonTemplate.h"

namespace Fanni {

#ifdef _DEBUG
static int DEFUALT_LOGGING_LEVEL = Poco::Message::PRIO_DEBUG;
#else
static int DEFUALT_LOGGING_LEVEL = Poco::Message::PRIO_INFORMATION;
#endif
	
// TODO @@@ should manage multiple _loggers
class Logger {
public:
	Logger() {
		Poco::Logger &logger =  Poco::Logger::root();
		logger.setLevel(DEFUALT_LOGGING_LEVEL);
	};
	~Logger() { };
};

typedef Singleton<Logger> LoggerSingleton;

inline void INIT_LOGGER(const std::string &config_file) {
    /*
      Logger &logger = LoggerSingleton::get();
      // set loging level for each logger
      //(void)Logger;
      */
}

};

#define TRACE_LOG(message)	\
	Poco::Logger::root().trace(message);
#define DEBUG_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::get(name)); ls.debug() << __VA_ARGS__ << std::endl; }
#define INFO_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::get(name)); ls.information() << __VA_ARGS__ << std::endl; }
#define WARN_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::get(name)); ls.warning() << __VA_ARGS__ << std::endl; }
#define ERROR_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::get(name)); ls.error() << __VA_ARGS__ << std::endl; }
#define FATAL_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::get(name)); ls.fatal() << __VA_ARGS__ << std::endl; }

#endif /* LOGGER_H_ */
