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
	UDP_OnRecvHandlerBase() {};
	virtual ~UDP_OnRecvHandlerBase() {};
	virtual void operator()(PacketBuffer *buffer, const EndPoint *ep) = 0;
};

static const short _UDPBASE_DEFAULT_PORT = 0;
static const std::string _UDPBASE_DEFAULT_ADDR = "0.0.0.0";

class UDPBase {

protected:
	EndPoint ep;
    SOCKET socket;
    UDP_OnRecvHandlerBase *recv_handler;

public:
	UDPBase() {
		this->ep.setAddr(_UDPBASE_DEFAULT_ADDR);
		this->ep.setPort(_UDPBASE_DEFAULT_PORT);
		this->socket = 0;
		this->recv_handler = NULL;
	};

	UDPBase(const std::string &addr, int server_port) {
		this->ep.setAddr(addr);
		this->ep.setPort(server_port);
		this->socket = 0;
		this->recv_handler = NULL;
	};
	virtual ~UDPBase() {
		this->shutdown();
	};

	void setOnRecvHandler(UDP_OnRecvHandlerBase *handler) {
		this->recv_handler = handler;
	};

	int getPort() const { return this->ep.getPort(); };

	const SOCKET &getSocket() const { return this->socket; }

	virtual void start() = 0;

	virtual void send(const PacketBuffer &buffer, const EndPoint &ep) const {
		this->send(buffer.getConstBuffer(), buffer.getLength(), ep);
	}

	virtual void send(const unsigned char* data, size_t data_len, const EndPoint &ep) const {
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
