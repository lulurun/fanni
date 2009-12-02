/*
 * Logger.h
 *
 *  Created on: Apr 16, 2009
 *      Author: lulu
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include "Poco/File.h"
#include "Poco/FileStream.h"
#include "Poco/Path.h"
#include "Poco/Logger.h"
#include "Poco/LogStream.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/Message.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "fanni/SingletonTemplate.h"

namespace Fanni {

#ifdef _DEBUG
static int DEFUALT_LOGGING_LEVEL = Poco::Message::PRIO_DEBUG;
#else
static int DEFUALT_LOGGING_LEVEL = Poco::Message::PRIO_INFORMATION;
#endif
	
static std::string DEFAULT_CONFIG_FILE_PATH = "logger.properties";
static const std::string DEFAULT_CONFIG_STRING =
	"logging.loggers.root.channel.class = ConsoleChannel\n"
	"logging.loggers.app.name = Application\n"
	"logging.loggers.app.channel = c0\n"
	"logging.formatters.f1.class = PatternFormatter\n"
	"logging.formatters.f1.pattern = %Y/%m/%d %H:%M:%S[%q] - %t\n"
	"logging.channels.c0.class = SplitterChannel\n"
	"logging.channels.c0.channel1 = c1\n"
	"logging.channels.c0.channel2 = c2\n"
	"logging.channels.c1.class = ConsoleChannel\n"
	"logging.channels.c1.formatter = f1\n"
	"logging.channels.c2.class = FileChannel\n"
	"logging.channels.c2.path = run.log\n"
	"logging.channels.c2.formatter = f1\n";

// TODO @@@ should manage multiple _loggers
class Logger {
public:
	Logger() {
		try {
			Poco::Util::LoggingConfigurator configurator;
			Poco::File config_file(DEFAULT_CONFIG_FILE_PATH);
			if (!config_file.exists())
			{
				Poco::FileOutputStream fos(DEFAULT_CONFIG_FILE_PATH);
				fos << DEFAULT_CONFIG_STRING;
				fos.close();
			}
			configurator.configure(new Poco::Util::PropertyFileConfiguration(DEFAULT_CONFIG_FILE_PATH));
		} catch (Poco::Exception &ex) {
			;// TODO @@@ ...
		}
	};
	~Logger() { };

	Poco::Logger &getLogger(const std::string &name = "") const {
		return Poco::Logger::root();
	}
};

typedef Singleton<Logger> LoggerSingleton;

};

/*
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
*/

#define TRACE_LOG(message)	\
	Poco::Logger::root().trace(message);
#define DEBUG_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::root()); ls.debug() << __VA_ARGS__ << std::endl; }
#define INFO_LOG(name, ...)	\
	{ Poco::LogStream ls(LoggerSingleton::get().getLogger()); ls.information() << __VA_ARGS__ << std::endl; }
#define WARN_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::root()); ls.warning() << __VA_ARGS__ << std::endl; }
#define ERROR_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::root()); ls.error() << __VA_ARGS__ << std::endl; }
#define FATAL_LOG(name, ...)	\
	{ Poco::LogStream ls(Poco::Logger::root()); ls.fatal() << __VA_ARGS__ << std::endl; }

#endif /* LOGGER_H_ */
