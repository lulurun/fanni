/*
 * Event_UDPClient.cpp
 *
 *  Created on: Aug 5, 2009
 *      Author: lulu
 */

#include "Event_UDPClient.h"

using namespace Fanni;
using namespace Network;

Event_UDPClient::Event_UDPClient() :
	UDPBase() {
}

Event_UDPClient::Event_UDPClient(const std::string &addr, int port) :
	UDPBase(addr, port) {
}

Event_UDPClient::~Event_UDPClient() {
}

