/*
 * Event_UDPOnRecvHandler.h
 *
 *  Created on: Aug 5, 2009
 *      Author: lulu
 */

#ifndef EVENT_UDPONRECVHANDLER_H_
#define EVENT_UDPONRECVHANDLER_H_

#include "fanni/Event++.h"
#include "fanni/EndPoint.h"
#include "fanni/Logger.h"
#include "fanni/PacketBuffer.h"

#include "FanniSock.h"

namespace Fanni {
namespace Network {

class UDP_OnRecvHandlerBase;
class Event_OnRecvHandler : public EventHandlerBase {
private:
	UDP_OnRecvHandlerBase *_udp_OnRecv_handler;

public:
	Event_OnRecvHandler(UDP_OnRecvHandlerBase *handler) {
		this->_udp_OnRecv_handler = handler;
	}

	virtual void operator() (int fd, short flags) {
		TRACE_LOG("enter");

		PacketBuffer *buffer = new PacketBuffer();
		EndPoint ep;

		int recv_len = FanniSock::GetPacket(fd, buffer->getBuffer(), reinterpret_cast<sockaddr *> (&ep));
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
		DEBUG_LOG("recv: \n" << buffer->to_debug_string());

		if (this->_udp_OnRecv_handler != NULL) {
			this->_udp_OnRecv_handler->operator ()(buffer, &ep);
		}

		TRACE_LOG("exit");
	}
};

}
}

#endif /* EVENT_UDPONRECVHANDLER_H_ */
