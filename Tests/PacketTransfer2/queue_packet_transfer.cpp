/*
 * queue_packet_transfer.cpp
 *
 *  Created on: Aug 7, 2009
 *      Author: lulu
 */

#include <iostream>
#include "fanni/Logger.h"
#include "PacketServer.h"

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
		PacketServer server(DEFAULT_ADDR, DEFAULT_PORT, thread_number);
		server.init();
		server.start();
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

int start_client() {
	TRACE_LOG("enter");
	try {
		PacketServer server(DEFAULT_ADDR, DEFAULT_PORT, thread_number);
		server.init();
		server.start();
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	TRACE_LOG("exit");
	return 0;
}

int main(int argc, char **argv) {
	bool server_mode = false;
	if (argc == 2) {
		string arg(argv[1]);
		if (arg == "server") server_mode = true;
	}
	if (server_mode) {
		return start_server();
	} else {
		return start_client();
	}
	return 0;
}
