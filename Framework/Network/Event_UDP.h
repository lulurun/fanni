#ifndef EVENT_UDPSERVER_H_
#define EVENT_UDPSERVER_H_

#include <memory>
#include <string>
#include "fanni/Event++.h"
#include "fanni/Exception.h"
#include "fanni/EndPoint.h"
#include "fanni/Logger.h"
#include "fanni/PacketBuffer.h"
#include "UDPBase.h"
#include "FanniSock.h"

namespace Fanni {
namespace Network {

class Event_OnRecvHandler: public EventHandlerBase {
private:
	const UDP_OnRecvHandlerBase &_udp_OnRecv_handler;

public:
	Event_OnRecvHandler(const UDP_OnRecvHandlerBase &handler) :
		_udp_OnRecv_handler(handler) {
	}

	virtual void operator()(int fd, short flags) const {
		TRACE_LOG("enter");

		std::auto_ptr<PacketBuffer> buffer(new PacketBuffer());
		std::auto_ptr<EndPoint> ep(new EndPoint());

		int recv_len = FanniSock::GetPacket(fd, buffer->getBuffer(), reinterpret_cast<sockaddr *> (ep.get()));
		// TODO @@@ non-blocking ?
		if (recv_len == -1) {
			ERROR_LOG("recvfrom() returned -1");
			return;
		} else if (recv_len == 0) {
			ERROR_LOG("Connection Close");
			return;
		}
		// @@@ bad interface! do not forget me !!
		buffer->setLength(recv_len);
		this->_udp_OnRecv_handler(buffer.release(), ep.release());

		TRACE_LOG("exit");
	}
};

class Event_UDP : public UDPBase {
private:
	EventManager em;
	Event_OnRecvHandler *_libevent_OnRecv_handler;

public:
	Event_UDP();
	Event_UDP(const std::string &addr, int port);
	virtual ~Event_UDP();

	virtual void start();
	virtual void stop();
};

}
}

#endif /* UDPSERVER_H_ */
