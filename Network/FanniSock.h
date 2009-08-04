/*
 * FanniSock.h
 *
 *  Created on: Apr 22, 2009
 *      Author: lulu
 */

#ifndef FANNISOCK_H_
#define FANNISOCK_H_

#include <string>
#include <netinet/in.h>
#include <stdio.h>
#include <stddef.h>
#include "fanni/EndPoint.h"

namespace Fanni {
namespace Network {

typedef int SOCKET;

class FanniSock {
public:
	static const int RECV_SIZE = 1500;

	enum HostType {
		HOSTTYPE_SERVER = -1,
		HOSTTYPE_CLIENT = 0,
	};

	enum Protocols {
		PROTOCOL_TCP = 0,
		PROTOCOL_UDP = 1,
	};

	enum ConnStates {
		STATE_CONNECTING = 0,
		STATE_CONNECTED = 1,
		STATE_DISCONNECTING = 2,
		STATE_DISCONNECTED = 4,
	};

	enum ErrorCode {
		INVALID_SOCKET = -1,
		SERVER_ERROR = 1,
		CLIENT_ERROR = 2,
	};

	static SOCKET Socket(int protocol);
	static int SetNonBlocking(SOCKET sock, u_long setMode);
	static int SetBroadcasting(SOCKET sock, int mode);
	static SOCKET OpenUDPSocket(const EndPoint &address);
	static void CloseSocket(SOCKET sock);
	static int GetPacket(SOCKET sock, unsigned char *data, struct sockaddr *from);
	static void SendPacket(SOCKET sock, int length, const unsigned char *data, const struct sockaddr &addr);
	static void Broadcast(SOCKET sock, int length, unsigned char *data, int port);
};

}
}

#endif /* FANNISOCK_H_ */
