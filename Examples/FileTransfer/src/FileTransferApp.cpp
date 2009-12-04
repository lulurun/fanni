/*
 * queue_packet_transfer.cpp
 *
 *  Created on: Aug 7, 2009
 *      Author: lulu
 */

#include <iostream>
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/HelpFormatter.h"
#include "fanni/Sleep.h"
#include "fanni/Logger.h"
#include "TransferNode.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::FileTransfer;
using namespace Poco::Util;

class FileTransferApp : public ServerApplication {
private:
	TransferNode *transfer_node;

public:
	FileTransferApp() : _server_mode(false), ip(), port(0), path() {}
	~FileTransferApp() {}

protected:
	void initialize(Application& self) {
		loadConfiguration(); // load default configuration files, if present
		ServerApplication::initialize(self);
		Logger::Initialize();
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


	void startServer() {
		try {
			EndPoint server_ep("0.0.0.0", port);
			TransferNode node(server_ep);
			waitForTerminationRequest();
		} catch (ErrorException &e) {
			ERROR_LOG("startServer Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
		}
	}

	void startClient() {
		try {
			EndPoint server_ep("0.0.0.0", 0);
			TransferNode node(server_ep);
			EndPoint connect_ep(this->ip, this->port);
			INFO_LOG("send " << this->path << " to " << connect_ep.toString());
			ClientConnection &cConn = node.connect(connect_ep);
			//cConn.sendFile(this->path);
			if (node.disconnect(cConn)) {
				INFO_LOG("disconnected");
			} else {
				INFO_LOG("disconnected without receiving reply");
			}
		} catch (Poco::Exception &ex) {
			ERROR_LOG("startClient Exception: " << ex.message());
		}
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
			this->startClient();
		} else {
			if ( this->port == 0 ) {
				cout << "requires port" << endl;
				_error = true;
			}
			if (_error) {
				return 1;
			}
			INFO_LOG("enter server mode");
			INFO_LOG("listening port: " << this->port);
			this->startServer();
		}

#ifdef _WIN32
#ifdef _DEBUG

		_CrtDumpMemoryLeaks();

#endif
#endif

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

