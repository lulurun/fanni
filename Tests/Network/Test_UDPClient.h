/*
 * Test_UDPClient.h
 *
 *  Created on: Apr 26, 2009
 *      Author: lulu
 */

#ifndef TEST_UDPCLIENT_H_
#define TEST_UDPCLIENT_H_

#include "fanni/EndPoint.h"
#include "Network/FanniSock.h"
#include "Packets/PacketSerializer.h"

namespace Fanni {
namespace Test {

class Test_UDPClient {
private:
	Fanni::Network::SOCKET socket;
	PacketSerializer serializer;
	EndPoint current_server;

public:
	Test_UDPClient();
	virtual ~Test_UDPClient();

	int connect(const EndPoint &server_ep);
	void sendUseCircuitCode();

	// test
	void test_send();
};

}
}

#endif /* TEST_UDPCLIENT_H_ */
