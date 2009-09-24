/*
 * Simulator.cpp
 *
 *  Created on: Sep 19, 2009
 *      Author: lulu
 */

#include <iostream>
#include "PacketServer.h"

using namespace std;
using namespace Fanni;

static const string DEFAULT_ADDR = "127.0.0.1";
static const int DEFAULT_PORT = 9001;
static const int thread_number = 10;

int main(int argc, char **argv) {
	try {
		PacketServer server("0.0.0.0", DEFAULT_PORT, thread_number);
		server.init();
		server.start();
		server.join();
	} catch (WarnException &e) {
		cout << "catch WARN Exception: " << e.get_msg();
	} catch (ErrorException &e) {
		cout << "catch ERROR Exception: " << e.get_msg();
	} catch (FatalException &e) {
		cout << "catch FATAL Exception: " << e.get_msg();
	}
	return 0;
}

