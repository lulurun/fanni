/*
 * FanniServer.cpp
 *
 *  Created on: Apr 23, 2009
 *      Author: lulu
 */

#include "FanniServer.h"
#include "FanniSock.h"

#include "fanni/FixedLengthBuffer.h"

using namespace std;
using namespace Fanni;
using namespace Communication;

FanniServer::FanniServer() {
	this->port = 0;
	this->socket = 0;
	this->OnRecvPacket_handler = NULL;
}

FanniServer::~FanniServer() {
	this->shutdown(this->socket);
}

int FanniServer::start(const string &addr, int server_port) {
	this->port = server_port;
	this->socket = FanniSock::OpenUDPSocket(addr, this->port);
	if (socket == FanniSock::INVALID_SOCKET) {
		return FanniSock::SERVER_ERROR;
	}
	return 0;
}

void FanniServer::shutdown() {
	FanniSock::CloseSocket(this->socket);
}

int FanniServer::recvPacket(unsigned char* data, , struct sockaddr *from) {
	// Check if the server is set up
	if (!socket)
		return 0;
	// TODO @@@ need Checking for timeout ???
	// Wait for a while or incoming data
	int maxfd = socket;
	fd_set allset;
	struct timeval waittime;
	waittime.tv_sec = 10 / 1000;
	waittime.tv_usec = (10 % 1000) * 1000;
	FD_ZERO(&allset);
	FD_SET(socket, &allset);
	fd_set reading = allset;
	int nready = select(maxfd + 1, &reading, NULL, NULL, &waittime);
	if (!nready)
		return 0;

	// Read data of the socket
	FixedLengthBuffer buffer;
	int recv_len = FanniSock::GetPacket(socket, buffer.getBuffer(), from);
	if (recv_len <= 0)
		return 0;
	buffer.setLength(recv_len);

	PacketBase *packet = this->serializer.deserialize(buffer);
	if (packet->header.isResent()) {
		; // @@@ do statistics or nothing for now
	}
	this->ack_mgr.checkInPacket(packet);

	if (this->OnRecvPacket_handler != NULL) {
		this->OnRecvPacket_handler->operator ()(packet, from);
	}

	return recv_len;
}

void FanniServer::sendPacket() {

}

int FanniServer::checkConnectivity() {

}

void FanniServer::sendPing() {

}

void FanniServer::sendAck() {

}

