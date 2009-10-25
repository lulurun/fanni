/*
 * queue_packet_transfer.cpp
 *
 *  Created on: Aug 7, 2009
 *      Author: lulu
 */

#include <iostream>
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/HelpFormatter.h"
#include "fanni/Logger.h"
#include "FileTransferNode.h"

using namespace std;
using namespace Fanni;

using namespace Poco::Util;

class FileTransferApp : public ServerApplication {
public:
	FileTransferApp() :
		_server_mode(false), ip(), port(0), path() {}
	~FileTransferApp() {}

protected:
	void initialize(Application& self) {
		loadConfiguration(); // load default configuration files, if present
		ServerApplication::initialize(self);
	}

	void uninitialize() {
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options)
	{
		ServerApplication::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information on command line arguments")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<FileTransferApp>(this, &FileTransferApp::handleHelp)));
		options.addOption(
			Option("server", "S", "running in server mode")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<FileTransferApp>(this, &FileTransferApp::startServer)));
		options.addOption(
			Option("host", "H", "IP of FileTransfer server")
				.required(false)
				.repeatable(false)
				.argument("IP address (x.x.x.x)")
				.callback(OptionCallback<FileTransferApp>(this, &FileTransferApp::setHost)));
		options.addOption(
			Option("port", "P", "Port of FileTransfer server")
				.required(false)
				.repeatable(false)
				.argument("port number")
				.callback(OptionCallback<FileTransferApp>(this, &FileTransferApp::setPort)));
		options.addOption(
			Option("file", "F", "file path to transfer")
				.required(false)
				.repeatable(false)
				.argument("file")
				.callback(OptionCallback<FileTransferApp>(this, &FileTransferApp::setFile)));
	}

	void startServer(const std::string& name, const std::string& value) {
		this->_server_mode = true;
	}

	void setHost(const std::string& name, const std::string& value) {
		this->ip = value;
	}

	void setPort(const std::string& name, const std::string& value) {
		DEBUG_LOG("set port: " << value);
		this->port = ::atoi(value.c_str());
	}

	void setFile(const std::string& name, const std::string& value) {
		this->path = value;
	}

	void handleHelp(const std::string& name, const std::string& value)
	{
		displayHelp();
		stopOptionsProcessing();
	}

	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A sample server application that demonstrates some of the features of the Util::ServerApplication class.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args)
	{
		bool _error = false;
		if (!_server_mode) {
			INFO_LOG("enter client mode");
			if ( this->ip.empty() ) {
				cout << "requires host" << endl;
				_error = true;
			}
			if ( this->port == 0 ) {
				cout << "requires port" << endl;
				_error = true;
			}
			if ( this->path.empty() ) {
				cout << "requires file" << endl;
				_error = true;
			}
			if (_error) {
				return 1;
			}
			try {
				int thread_number = 5;
				FileTransferNode node("0.0.0.0", 0, thread_number);
				node.start();

				Poco::Net::SocketAddress connect_to_addr(this->ip, this->port);
				INFO_LOG("send " << this->path << " to " << connect_to_addr.toString());
				node.startSendFile(this->path, connect_to_addr);

				waitForTerminationRequest();
				node.stop();
			} catch (ErrorException &e) {
				ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
			}
		} else {
			try {
				if ( this->port == 0 ) {
					cout << "requires port" << endl;
					_error = true;
				}
				if (_error) {
					return 1;
				}
				int thread_number = 5;
				INFO_LOG("enter server mode");
				INFO_LOG("listening port: " << this->port);
				FileTransferNode node("0.0.0.0", this->port, thread_number);
				node.start();
				waitForTerminationRequest();
				node.stop();
			} catch (ErrorException &e) {
				ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
			}
		}
		return Application::EXIT_OK;
	}

private:
	bool _server_mode;
	std::string ip;
	int port;
	std::string path;
};

int main(int argc, char** argv)
{
	FileTransferApp app;
	return app.run(argc, argv);
}

/*
int start_server() {
	try {
		DEBUG_LOG("enter Server mode");
		FileTransferNode node("0.0.0.0", DEFAULT_PORT, thread_number);
		node.start();
		while(1) {
			;
		}
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

int start_client(const string &server_addr, const string &file_path) {
	TRACE_LOG("enter");
	try {
		FileTransferNode node("0.0.0.0", 0, thread_number);
		node.start();

		Poco::Net::SocketAddress connect_to_addr(server_addr, DEFAULT_PORT);
		node.startSendFile(file_path, connect_to_addr);

		while(1) {
			;
		}

	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	TRACE_LOG("exit");
	return 0;
}

int main(int argc, char **argv) {
    bool server_mode = false;
    if (argc >= 2) {
	string arg(argv[1]);
	if (arg == "server") server_mode = true;
    }
    if (server_mode) {
	return start_server();
    } else {
	if (argc >= 3) {
	    string server_addr(argv[1]);
	    string file_name(argv[2]);
	    return start_client(server_addr, file_name);
	} else {
	    cout << "help" << endl;
	}
    }
    return 0;
}

*/

