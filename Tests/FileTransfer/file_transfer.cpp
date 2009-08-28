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
using namespace Fanni::Network;
using namespace Fanni::Tests;

static const string DEFAULT_ADDR = "127.0.0.1";
static const int DEFAULT_PORT = 9001;
static const int thread_number = 1;

int start_server() {
	try {
		DEBUG_LOG("enter Server mode");
		FileTransferNode node(DEFAULT_ADDR, DEFAULT_PORT, thread_number);
		node.init();
		node.start();
		node.join();
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

int start_client(const string &file_name) {
	TRACE_LOG("enter");
	try {
		FileTransferNode node("0.0.0.0", 0, thread_number);
		node.init();
		node.start();

		EndPoint connect_to_ep(DEFAULT_ADDR, DEFAULT_PORT);
		node.openConnection(connect_to_ep);

		node.startSendFile(file_name, connect_to_ep);
		::sleep(6);

		node.closeConnection(connect_to_ep);

		node.join();
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
		if (argc >= 2) {
			string file_name(argv[1]);
			return start_client(file_name);
		} else {

		}
	}
	return 0;
}
