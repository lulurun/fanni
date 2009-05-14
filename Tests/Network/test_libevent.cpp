/*
 * test_libevent.cpp
 *
 *  Created on: Mar 3, 2009
 *      Author: lulu
 */

#include <sys/socket.h>
#include <arpa/inet.h>

#include "fanni/Event++.h"
#include "Network/IOUtils.h"
#include "fanni/FixedLengthBuffer.h"
#include "fanni/Exception.h"
#include "fanni/EndPoint.h"

#include <iostream>

using namespace std;
using namespace Fanni;

static int counter = 0;

template <class HANDLER>
class EventA : public EventBase<HANDLER> {
public:
	EventA(int fd, short flags, HANDLER &handler) : EventBase<HANDLER>(fd, flags, handler) {
		handler.setEvent(this);
		handler.setFD(fd);
	}
};

class EventHandlerA : public EventHandlerBase {
public:
	EventHandlerA(EventManager *em) : EventHandlerBase(em) {};
	virtual void operator() (int fd, short flags) {
		if (fd != this->fd) {
		    FatalException::throw_exception(EXP_Network, EXP_PRE_MSG, "fd changed!!");
		}
		FixedLengthBuffer data;
		sockaddr_in peer;
		socklen_t l = sizeof(struct sockaddr);
		int recv_len = ::recvfrom(fd, data.getBuffer(), FixedLengthBuffer::BUF_LEN, 0,
				reinterpret_cast<struct sockaddr*>(&peer), &l);
		data.setLength(recv_len);
		printf("recv: %d %d\n", ++counter, recv_len);
		data.debug_print();
	};
};

class EventHandlerB : public EventHandlerBase {
public:
	EventHandlerB(EventManager *em) : EventHandlerBase(em) {};
	virtual void operator() (int fd, short flags) {
		printf("HandlerA %d\n", ++counter);
	};
};

int main() {
	int sock;

	EndPoint ep("0.0.0.0", 9000);
	IOUtils::init_udp_socket(&sock, ep);

	EventManager em;

	EventHandlerA handler(&em);
	EventA<EventHandlerA> e(sock, EV_READ | EV_PERSIST, handler);
	em.add(&e);
	/*
	EventHandlerA handler(&em);
	EventBase<EventHandlerA> e(sock, EV_READ | EV_PERSIST, handler);
	em.add(&e);
	*/
	em.dispatch();
	return 0;
}

