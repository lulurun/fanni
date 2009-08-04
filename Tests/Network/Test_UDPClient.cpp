/*
 * Test_UDPClient.cpp
 *
 *  Created on: Apr 26, 2009
 *      Author: lulu
 */

#include <cstdlib>
#include <iostream>

#include "Test_UDPClient.h"
#include "Packets/Packets.h"
#include "Packets/PacketFactory.h"
#include "fanni/UUID.h"
#include "fanni/Logger.h"
#include "Threads/SeqGenerator.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;
using namespace Test;

static const int DEFAULT_CONNECT_PORT = 9001;

Test_UDPClient::Test_UDPClient() {
	EndPoint ep("", 0);
	this->socket = FanniSock::OpenUDPSocket(ep);
	if (this->socket == FanniSock::INVALID_SOCKET) {
		ErrorException::throw_exception(EXP_TEST, EXP_PRE_MSG,"error creating socket" );
	}
}

Test_UDPClient::~Test_UDPClient() {
	FanniSock::CloseSocket(this->socket);
}

int Test_UDPClient::connect(const EndPoint &ep) {
	this->current_server = ep;
	this->sendUseCircuitCode();
	return 0;
}

static SequenceGenerator *sg = SequenceGeneratorFactory::GetInstance()->createGenerator();

void Test_UDPClient::sendUseCircuitCode() {
	PacketBase *packet = PacketFactory::GetInstance()->createPacket( UseCircuitCode_ID);
	UseCircuitCodePacket *usecircuitcode =
			dynamic_cast<UseCircuitCodePacket *> (packet);
	if (usecircuitcode == NULL) {
		FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"wrong implementation" );
	}
	usecircuitcode->CircuitCode.Code = 123456;
	usecircuitcode->CircuitCode.SessionID = UUID::New();
	usecircuitcode->CircuitCode.ID = UUID::New();

	usecircuitcode->setSequence(sg->next());

	int buffer_size = 0;
	const unsigned char *buffer = this->serializer.serialize(packet,
			&buffer_size);
	FanniSock::SendPacket(this->socket, buffer_size, buffer, this->current_server.getSockAddr());
}

void Test_UDPClient::test_send() {
	for(int i=0; i<10; i++) {
		this->sendUseCircuitCode();
	}
}

int main(int argc, char **argv) {
	int port = DEFAULT_CONNECT_PORT;

	if (argc == 2) {
		port = ::atoi(argv[1]);
	}
	try {
		Test_UDPClient client;
		EndPoint server_ep("127.0.0.1", port);
		client.connect(server_ep);
		client.test_send();
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
}

