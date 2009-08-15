/*
 * PacketServer.h
 *
 *  Created on: Aug 15, 2009
 *      Author: lulu
 */

#ifndef PACKETSERVER_H_
#define PACKETSERVER_H_

#include <string>

#include "fanni/EndPoint.h"
#include "Threads/ThreadWorker.h"
#include "Threads/ThreadManager.h"
#include "Packets/PacketBase.h"
#include "Packets/PacketSerializer.h"
#include "Network/Event_UDP.h"

#include "ReceiverBase.h"

namespace Fanni {
namespace Tests {

class PacketSender : public ThreadWorker {
private:
	PacketSerializer packet_serializer;
	const Fanni::Network::UDPBase &udp_server;

public:
	PacketSender(const Fanni::Network::UDPBase &udp_server) : udp_server(udp_server) {}
	virtual void loop();
	virtual void stop() { ; }
};

class PacketServer : public ThreadManager {
private:
	int thread_number;
	Fanni::Network::Event_UDP *udp_server;
	ReceiverManager *receiver_manager;

public:
	PacketServer(const std::string &addr, int port, int thread_number);
	virtual ~PacketServer();
	virtual void init();

	virtual void processIncomingPacket(PacketBase *packet, const EndPoint *ep);
	virtual void processOutgoingPacket(PacketBase *packet, const EndPoint *ep);

};

}
}

#endif /* PACKETSERVER_H_ */
