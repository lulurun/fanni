/*
 * queue_packet_transfer.cpp
 *
 *  Created on: Aug 7, 2009
 *      Author: lulu
 */

#include <iostream>
#include "fanni/Logger.h"
#include "FileTransferNode.h"

using namespace std;
using namespace Fanni;

static const string DEFAULT_ADDR = "127.0.0.1";
static const int DEFAULT_PORT = 9001;
static const int thread_number = 10;

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
