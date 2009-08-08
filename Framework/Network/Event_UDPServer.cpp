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

#include <event.h>

#include "Event_UDPServer.h"
#include "FanniSock.h"
#include "fanni/Logger.h"

using namespace Fanni;
using namespace Network;

Event_UDPServer::Event_UDPServer() :
	UDPBase() {
	this->socket = FanniSock::OpenUDPSocket(this->ep);
	if (this->socket == FanniSock::INVALID_SOCKET) {
		ErrorException::throw_exception(Fanni::EXP_UUID, EXP_PRE_MSG, "invalid socket");
	}
}

Event_UDPServer::Event_UDPServer(const std::string &addr, int port) :
	UDPBase(addr, port) {
	this->socket = FanniSock::OpenUDPSocket(this->ep);
	if (this->socket == FanniSock::INVALID_SOCKET) {
		ErrorException::throw_exception(Fanni::EXP_UUID, EXP_PRE_MSG, "invalid socket");
	}
}

Event_UDPServer::~Event_UDPServer() {
}

void Event_UDPServer::start() {
	TRACE_LOG("enter");
	try {
		if (this->recv_handler == NULL) {
			WARN_LOG("recv handler is NULL");
		}
		this->_libevent_OnRecv_handler = new Event_OnRecvHandler(this->recv_handler);
		EventBase<Event_OnRecvHandler> e(this->socket, EV_READ| EV_PERSIST,
				this->_libevent_OnRecv_handler);
		this->em.add(&e);
		this->em.dispatch();
	} catch (WarnException &e) {
		WARN_LOG("WARN Exception: " << e.get_func() << " at L" << e.get_line() << e.get_msg());
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << e.get_msg());
	} catch (FatalException &e) {
		// TODO @@@ not finished
		FATAL_LOG("FATAL Exception: " << e.get_func() << " at L" << e.get_line() << e.get_msg());
		this->shutdown();
	}TRACE_LOG("exit");
}

