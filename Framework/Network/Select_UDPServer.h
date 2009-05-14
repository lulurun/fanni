/*
 * FanniServer.h
 *
 *  Created on: Apr 23, 2009
 *      Author: lulu
 */

#ifndef SELECT_UDPSERVER_H_
#define SELECT_UDPSERVER_H_

#include <string>
#include "Packets/PacketBase.h"
#include "Packets/PacketSerializer.h"
#include "AckManager.h"

namespace Fanni {
namespace Communication {

struct OnRecvPacketHandler {
	virtual void operator() (PacketBase *packet, struct sockaddr *from) = 0;
};

class Select_UDPServer {
private:
    int port;
    SOCKET socket;

    OnRecvPacketHandler *OnRecvPacket_handler;
    PacketSerializer serializer;
    AckManager ack_mgr;

public:
	Select_UDPServer();
	virtual ~Select_UDPServer();

	OnRecvPacket *OnRecvPacket() {
		return this->OnRecvPacket_handler;
	}

	int start(const std::string &addr, int server_port);
	void shutdown();
	int recvPacket();
	void sendPacket();

protected:
	virtual int checkConnectivity();
	virtual void sendPing();
	virtual void sendAck();
};

}
}

#endif /* FANNISERVER_H_ */
