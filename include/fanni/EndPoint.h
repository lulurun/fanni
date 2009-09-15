/*
 * EndPoint.h
 *
 *  Created on: Mar 9, 2009
 *      Author: lulu
 */

#ifndef ENDPOINT_H_
#define ENDPOINT_H_

#include <string>
#include <arpa/inet.h>
#include <fanni/Exception.h>
#include <fanni/Logger.h>

namespace Fanni {

struct EndPoint : sockaddr_in {

public:
	EndPoint() {
		this->sin_family = AF_INET;
		this->sin_addr.s_addr = INADDR_ANY;
		this->sin_port = 0;
	}
	EndPoint(const EndPoint &ep) {
		this->sin_family = AF_INET;
		this->sin_addr.s_addr = ep.sin_addr.s_addr;
		this->sin_port = ep.sin_port;
	}
	EndPoint(const std::string &ipaddr, int port) {
		this->sin_family = AF_INET;
		this->setAddr(ipaddr);
		this->setPort(port);
	};
	~EndPoint() {
		TRACE_LOG("enter");
	};

	void setAddr(const std::string &ipaddr) {
		in_addr_t addr = ::inet_addr(ipaddr.c_str());
		if (addr < 0) {
			ErrorException::throw_exception(EXP_Network, EXP_PRE_MSG, "bad address format");
		}
		this->setAddr(addr);
	};
	void setAddr(const in_addr_t ipaddr) {
		this->sin_addr.s_addr = ipaddr;
	};
	void setPort(const in_port_t port) {
		this->sin_port = ::htons((uint16_t)port);
	};

	const in_addr_t getAddr() const {
		return ::ntohl(this->sin_addr.s_addr);
	}

	std::string getAddrStr() const {
		std::string addr_str;
		addr_str = ::inet_ntoa(this->sin_addr);
		return addr_str;
	}
	const int getPort() const {
		return ::ntohs(this->sin_port);
	}

	const sockaddr &getSockAddr() const {
		return *reinterpret_cast<const sockaddr *>(this); // TODO @@@ is this OK, =:hihihi ???
	}

	typedef uint64_t IPV4_HASH_KEY_TYPE;
	IPV4_HASH_KEY_TYPE getIPv4HashKey() const {
		return (static_cast<uint64_t>(this->sin_addr.s_addr) << 32) + this->sin_port;

	}
};

}

#endif /* ENDPOINT_H_ */
