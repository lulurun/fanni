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

// Default handler
void Event_UDPServer::Private_OnRecvHandler::operator()(int fd, short flags) const {
	TRACE_LOG("enter");


	PacketBuffer *buffer = new PacketBuffer();
	EndPoint ep;
	socklen_t l = sizeof(struct sockaddr);
	int recv_len = ::recvfrom(fd, buffer->getBuffer(),
			PacketBuffer::Capacity, 0, reinterpret_cast<sockaddr *> (&ep),
			&l);

	// TODO @@@ non-blocking ?
	if (recv_len == -1) {
		ERROR_LOG("recvfrom() returned -1");
	} else if (recv_len == 0) {
		ERROR_LOG("Connection Close");
	}
	// @@@ bad interface! do not forget me !!
	buffer->setLength(recv_len);
	DEBUG_LOG("recv: \n" << buffer->to_debug_string());

	if (this->UDPServer_recv_handler != NULL) {
		DEBUG_LOG("CALL OnRecv");
		this->UDPServer_recv_handler->operator ()(buffer, &ep);
	}

	TRACE_LOG("exit");
}

Event_UDPServer::Event_UDPServer() :
	UDPServerBase() {
}

Event_UDPServer::Event_UDPServer(const std::string &addr, int port) :
	UDPServerBase(addr, port) {
}

Event_UDPServer::~Event_UDPServer() {
}

void Event_UDPServer::start() {
	TRACE_LOG("enter");
	this->UDPServerBase::start();
	try {
		this->socket = FanniSock::OpenUDPSocket(this->ep);
		if (this->socket == FanniSock::INVALID_SOCKET) {
			ErrorException::throw_exception(Fanni::EXP_UUID, EXP_PRE_MSG, "invalid socket");
		}
		if (this->recv_handler == NULL) {
			WARN_LOG("recv handler is NULL");
		}
		this->_private_handler = new Private_OnRecvHandler(this->recv_handler);
		EventBase<Private_OnRecvHandler> e(this->socket, EV_READ| EV_PERSIST,
				this->_private_handler);
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

void Event_UDPServer::shutdown() {
	FanniSock::CloseSocket(this->socket);
}

