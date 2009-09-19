/*
#include <sys/types.h>
#include <sys/stat.h>

#ifndef WIN32
#include <sys/queue.h>
#include <unistd.h>
#include <sys/time.h>
#else
#include <windows.h>
#endif
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
*/
#include <event.h>

#include "Event_UDP.h"
#include "FanniSock.h"
#include "fanni/Logger.h"

using namespace Fanni;
using namespace Network;

Event_UDP::Event_UDP() :
	UDPBase() {
	this->init();
}

Event_UDP::Event_UDP(const std::string &addr, int port) :
	UDPBase(addr, port) {
	this->init();
}

void Event_UDP::init() {
	UDPBase::init();
	this->_libevent_OnRecv_handler = NULL;
}

Event_UDP::~Event_UDP() {
	this->stop(); // TODO @@@ should be here ???
	if (this->_libevent_OnRecv_handler) delete this->_libevent_OnRecv_handler;
}

void Event_UDP::start() {
	TRACE_LOG("enter");
	if (this->recv_handler_ptr == NULL) {
		ERROR_LOG("recv handler is NULL");
		return;
	}
	this->_libevent_OnRecv_handler = new Event_OnRecvHandler(this->recv_handler_ptr);
	EventBase<Event_OnRecvHandler> e(this->socket, EV_READ| EV_PERSIST, this->_libevent_OnRecv_handler);
	this->em.add(&e);
	this->em.dispatch();
	TRACE_LOG("exit");
}

void Event_UDP::stop() {
	TRACE_LOG("enter");
	this->em.stop();
	TRACE_LOG("exit");
}

