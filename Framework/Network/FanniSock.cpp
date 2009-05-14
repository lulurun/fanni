/*
 * FanniSock.cpp
 *
 *  Created on: Apr 22, 2009
 *      Author: lulu
 */

#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "fanni/Logger.h"
#include "FanniSock.h"

namespace Fanni {
namespace Network {

SOCKET FanniSock::Socket(int protocol) {
	int type;
	int proto;
	SOCKET sock;
	// Check which protocol to use
	if (protocol == PROTOCOL_TCP) {
		type = SOCK_STREAM;
		proto = IPPROTO_TCP;
	} else {
		type = SOCK_DGRAM;
		proto = IPPROTO_UDP;
	}
	// Create the socket
	if ((sock = socket(AF_INET, type, proto)) == -1) {
		FATAL_LOG("Socket - socket() failed: " << strerror(errno));
		return INVALID_SOCKET;
	}
	return sock;
}

int FanniSock::SetNonBlocking(SOCKET sock, u_long setMode) {
	u_long set = setMode;
	// Set the socket option
	return ioctl(sock, FIONBIO, &set);
}

int FanniSock::SetBroadcasting(SOCKET sock, int mode) {
	// make it broadcast capable
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *) &mode, sizeof(int))
			== -1) {
		ERROR_LOG("SetBroadcasting failed: " << strerror(errno));
		return INVALID_SOCKET;
	}
	return 0;
}

SOCKET FanniSock::OpenUDPSocket(const EndPoint &address) {
	TRACE_LOG("enter");
	SOCKET sock;
	sock = Socket(PROTOCOL_UDP);
	if (sock == INVALID_SOCKET)
		return sock;
	SetNonBlocking(sock, 1);
	SetBroadcasting(sock, 1);
	// Bind the address to the socket
	if (bind(sock, (struct sockaddr *) &address, sizeof(address)) == -1) {
		FATAL_LOG("Error code " << errno << ": bind() : " << strerror(errno));
		return INVALID_SOCKET;
	}
	socklen_t len = sizeof(address);
	getsockname(sock, (struct sockaddr *) &address, &len);
	INFO_LOG("Opening UDP addr [IP]:" << address.getAddrStr() << " [PORT]:" << address.getPort());

	TRACE_LOG("exit");
	return sock;
}

void FanniSock::CloseSocket(SOCKET sock) {
	close(sock);
}

int FanniSock::GetPacket(SOCKET sock, unsigned char *data, struct sockaddr *from) {
	int ret;
	struct sockaddr tempFrom;
	socklen_t fromlen;
	fromlen = sizeof(tempFrom);
	ret = recvfrom(sock, data, RECV_SIZE, 0, (struct sockaddr *) &tempFrom, &fromlen);
	// Copy the address to the from pointer
	if (from != NULL)
		*(struct sockaddr *) from = tempFrom;
	if (ret == -1) {
		// Silently handle would block
		if (errno== EWOULDBLOCK || errno == ECONNREFUSED)
			return ret;
		ERROR_LOG("Error code " << errno << ": recvfrom() : " << strerror(errno));
		return ret;
	}
	return ret;
}
void FanniSock::SendPacket(SOCKET sock, int length, const unsigned char *data, const struct sockaddr &addr) {
	TRACE_LOG("enter");
	int ret;
	ret = sendto(sock, data, length, 0, &addr, sizeof(addr));
	if (ret == -1) {
		// Silently handle would block
		if (errno== EWOULDBLOCK)
			return;
		ERROR_LOG("Error code " << errno << ": sendto() : " << strerror(errno));
	}
	TRACE_LOG("exit");
}

void FanniSock::Broadcast(SOCKET sock, int length, unsigned char *data, int port) {
	struct sockaddr_in servaddr;
	socklen_t len;
	// Use broadcast address
	u_long inetAddr = inet_addr("255.255.255.255");
	// Fill address information structure
	memset(&servaddr, 0, sizeof(struct sockaddr_in));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inetAddr;
	len = sizeof(servaddr);
	// Broadcast!
	int ret = sendto(sock, data, length, 0, (struct sockaddr *) &servaddr, len);
	if (ret == -1) {
		// Silently handle would block
		if (errno== EWOULDBLOCK)
			return;
		ERROR_LOG("Error code " << errno << ": sendto() : " << strerror(errno));
	}
}

}
}
