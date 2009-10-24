/*
 * TransferNodeConfig.h
 *
 *  Created on: Oct 23, 2009
 *      Author: lulu
 */

#ifndef TRANSFERNODECONFIG_H_
#define TRANSFERNODECONFIG_H_

#include <string>
#include "Poco/Net/SocketAddress.h"

namespace Fanni {

class TransferNodeConfig {
private:
	// UDP settings
	Poco::Net::SocketAddress socket_addr;
	int thread_number;

	// ACK, RESEND management
	int ack_interval;
	int resend_interval;
	int alive_interval;

public:
	TransferNodeConfig(const std::string &addr, uint16_t port) {
		this->socket_addr.init(addr, port);
		// TODO @@@ temporary default
		this->ack_interval = 3000;
		this->resend_interval = 3000;
		this->alive_interval = 15000;
	};
	virtual ~TransferNodeConfig();

	Poco::Net::SocketAddress &getSocketAddress() {
		return this->socket_addr;
	}
};

}

#endif /* TRANSFERNODECONFIG_H_ */
