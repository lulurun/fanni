#include "Poco/File.h"
#include "Poco/Message.h"
#include "Poco/FileStream.h"
#include "Poco/Path.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/PropertyFileConfiguration.h"

#include "fanni/Logger.h"

namespace Fanni {

static std::string DEFAULT_CONFIG_FILE_PATH = "logger.properties";
static const std::string DEFAULT_CONFIG_STRING =
	"logging.loggers.root.channel = c0\n"
	"logging.loggers.root.level = debug\n"
	"logging.loggers.LLUDP.name = LLUDP\n"
	"logging.loggers.LLUDP.channel = c0\n"
	"logging.loggers.LLUDP.level = debug\n"
	"logging.loggers.Example.name = Example\n"
	"logging.loggers.Example.channel = c0\n"
	"logging.loggers.Example.level = debug\n"
	"logging.loggers.Basic.name = Basic\n"
	"logging.loggers.Basic.channel = c0\n"
	"logging.loggers.Basic.level = debug\n"
	"logging.loggers.Packet.name = Packets\n"
	"logging.loggers.Packet.channel = c0\n"
	"logging.loggers.Packet.level = debug\n"
	"logging.formatters.f1.class = PatternFormatter\n"
	"logging.formatters.f1.pattern = [%q] %Y/%m/%d %H:%M:%S - %t\n"
	"logging.channels.c0.class = SplitterChannel\n"
	"logging.channels.c0.channel1 = c1\n"
	"logging.channels.c0.channel2 = c2\n"
	"logging.channels.c1.class = ConsoleChannel\n"
	"logging.channels.c1.formatter = f1\n"
	"logging.channels.c2.class = FileChannel\n"
	"logging.channels.c2.path = run.log\n"
	"logging.channels.c2.formatter = f1\n";

static Poco::SharedPtr<Poco::LogStream> pLogStream = new Poco::LogStream(Poco::Logger::root());
Poco::SharedPtr<Poco::LogStream> &Logger::LogStream() {
	return pLogStream;
}

void Logger::Initialize() {
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

		//Logger::pLogStream.assign(new Poco::LogStream(Poco::Logger::root()));
	} catch (Poco::Exception &ex) {
		;// TODO @@@ ...
	}
};

}

