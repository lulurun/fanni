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

static const short DEFAULT_PORT = 9001;
static const std::string DEFAULT_ADDR = "0.0.0.0";

class UDPServerBase {
protected:
	EndPoint ep;
    SOCKET socket;

public:
	UDPServerBase() {
		this->ep.setAddr(DEFAULT_ADDR);
		this->ep.setPort(DEFAULT_PORT);
		this->socket = 0;
		this->recv_handler = NULL;
	};

	UDPServerBase(const std::string &addr, int server_port) {
		this->ep.setAddr(addr);
		this->ep.setPort(server_port);
		this->socket = 0;
		this->recv_handler = NULL;
	};
	virtual ~UDPServerBase() {};

	virtual void start() = 0;
	virtual void shutdown() {
		if (this->socket == 0) {
			// TODO @@@ not needed ??
			ErrorException::throw_exception(EXP_Network, EXP_PRE_MSG, "UDPServer not started");
		}
		::close(this->socket); // TODO @@@ what to do ???
	};

	int getPort() const { return this->ep.getPort(); };
};

}
}

#endif /* UDPSERVERBASE_H_ */
