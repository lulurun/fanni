/*
 * UDPBase.h
 *
 *  Created on: Apr 26, 2009
 *      Author: lulu
 */

#ifndef UDPBASE_H_
#define UDPBASE_H_

#include <string>

#include "fanni/PacketBuffer.h"
#include "fanni/EndPoint.h"
#include "fanni/Exception.h"

#include "FanniSock.h"

namespace Fanni {
namespace Network {

class UDP_OnRecvHandlerBase {
public:
	virtual void operator()(PacketBuffer *buffer, const EndPoint *ep) const = 0;
};

static const short _UDPBASE_DEFAULT_PORT = 0;
static const std::string _UDPBASE_DEFAULT_ADDR = "0.0.0.0";

class UDPBase {

protected:
	EndPoint ep;
	SOCKET socket;
	UDP_OnRecvHandlerBase *recv_handler_ptr;

public:
	UDPBase() :
		ep(_UDPBASE_DEFAULT_ADDR, _UDPBASE_DEFAULT_PORT), socket(0),
				recv_handler_ptr(NULL) {
		this->open_socket();
	}
	UDPBase(const std::string &addr, int server_port) :
		ep(addr, server_port), socket(0), recv_handler_ptr(NULL) {
		this->open_socket();
	}
	virtual ~UDPBase() {
		//this->stop();
		this->shutdown();
	}
	void open_socket() {
		this->socket = FanniSock::OpenUDPSocket(this->ep);
		if (this->socket == FanniSock::INVALID_SOCKET) {
			ErrorException::throw_exception(Fanni::EXP_UUID, EXP_PRE_MSG,"invalid socket" );
		}
	}
	virtual void setOnRecvHandler(UDP_OnRecvHandlerBase *handler) {
		this->recv_handler_ptr = handler;
	};

	int getPort() const {return this->ep.getPort();};

	const SOCKET &getSocket() const {return this->socket;}

	virtual void start() = 0;
	virtual void stop() = 0;

	virtual void send(const PacketBuffer &buffer, const EndPoint &ep) const {
		this->send(buffer.getConstBuffer(), buffer.getLength(), ep);
	}

	virtual void send(const unsigned char* data, size_t data_len, const EndPoint&ep) const {
		FanniSock::SendPacket(this->socket, data_len, data, *reinterpret_cast<const sockaddr *>(&ep));
	}

	virtual void shutdown() {
		if (this->socket == 0) {
			return;
		}
		FanniSock::CloseSocket(this->socket);
	};

};

}
}

#endif /* UDPSERVERBASE_H_ */
