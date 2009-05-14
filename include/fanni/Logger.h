/*
 * Logger.h
 *
 *  Created on: Apr 16, 2009
 *      Author: lulu
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <typeinfo>
#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/propertyconfigurator.h"
#include "log4cxx/helpers/exception.h"

namespace Fanni {

static const std::string LOG4CXX_CONFIGURATION_FILE = "log4cxx.properties";

// TODO @@@ should manage multiple _loggers
class Logger {
private:
	log4cxx::LoggerPtr _logger;
	Logger(const std::string &name = "default") {
		log4cxx::PropertyConfigurator::configure(LOG4CXX_CONFIGURATION_FILE);
		this->_logger = log4cxx::Logger::getLogger(name);
	};

public:
	~Logger() {
		delete this->_logger;
	};

	operator const log4cxx::LoggerPtr &() const {
		return this->_logger;
	};

	static const Logger *GetInstance() {
		static const Logger *instance = NULL;
		if (instance == NULL) {
			instance = new Logger();
		}
		return instance;
	}
};

};

#ifdef DEBUG
#define TRACE_LOG(...)	\
	LOG4CXX_TRACE(static_cast<const log4cxx::LoggerPtr &>(*Fanni::Logger::GetInstance()), __VA_ARGS__);
#define DEBUG_LOG(...)	\
	LOG4CXX_DEBUG(static_cast<const log4cxx::LoggerPtr &>(*Fanni::Logger::GetInstance()), __VA_ARGS__);
#else
#define TRACE_LOG(MSG ...)
#define DEBUG_LOG(MSG ...)
#endif

#define INFO_LOG(...)	\
	LOG4CXX_INFO(static_cast<const log4cxx::LoggerPtr &>(*Fanni::Logger::GetInstance()), __VA_ARGS__);
#define WARN_LOG(...)	\
	LOG4CXX_WARN(static_cast<const log4cxx::LoggerPtr &>(*Fanni::Logger::GetInstance()), __VA_ARGS__);
#define ERROR_LOG(...)	\
	LOG4CXX_ERROR(static_cast<const log4cxx::LoggerPtr &>(*Fanni::Logger::GetInstance()), __VA_ARGS__);
#define FATAL_LOG(...)	\
	LOG4CXX_FATAL(static_cast<const log4cxx::LoggerPtr &>(*Fanni::Logger::GetInstance()), __VA_ARGS__);

#endif /* LOGGER_H_ */
