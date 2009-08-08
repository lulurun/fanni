/*
 * UDPServerBase.h
 *
 *  Created on: Apr 26, 2009
 *      Author: lulu
 */

#ifndef UDPSERVERBASE_H_
#define UDPSERVERBASE_H_

#include <string>
#include "fanni/PacketBuffer.h"
#include "fanni/EndPoint.h"
#include "fanni/Exception.h"

#include "FanniSock.h"

namespace Fanni {
namespace Network {

static const short DEFAULT_PORT = 0;
static const std::string DEFAULT_ADDR = "0.0.0.0";

class UDPBase;

class UDP_OnRecvHandlerBase {
public:
	UDP_OnRecvHandlerBase() {};
	virtual ~UDP_OnRecvHandlerBase() {};
	virtual void operator()(PacketBuffer *buffer, const EndPoint *ep) = 0;
};

class UDPBase {
protected:
	EndPoint ep;
    SOCKET socket;
    UDP_OnRecvHandlerBase *recv_handler;

public:
	UDPBase() {
		this->ep.setAddr(DEFAULT_ADDR);
		this->ep.setPort(DEFAULT_PORT);
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

	int getPort() const { return this->ep.getPort(); };
	const SOCKET &getSocket() const { return this->socket; }
	void setOnRecvHandler(UDP_OnRecvHandlerBase *handler) {
		this->recv_handler = handler;
	};

	virtual void start() = 0;

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
