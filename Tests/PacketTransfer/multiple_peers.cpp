/*
 * multiple_peers.cpp
 *
 *  Created on: Aug 8, 2009
 *      Author: lulu
 */

#include <iostream>
#include "Network/Event_UDPServer.h"
#include "Network/FanniSock.h"

#include "fanni/Logger.h"
#include "fanni/ThreadTemplate.h"
#include "Threads/ThreadManager.h"

// packets
#include "fanni/PacketBuffer.h"
#include "Packets/PacketHandlerFactory.h"
#include "Packets/PacketBase.h"
#include "Packets/Packets.h"
#include "Packets/PacketSerializer.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;

namespace Fanni {
namespace Tests {

class PacketServer_OnRecvHandler : public UDP_OnRecvHandlerBase {
private:
	PacketSerializer packet_serializer;
	Event_UDPServer &udp_server;
	ServerReceiverManager *recevier_manager;

public:
	PacketServer_OnRecvHandler(Event_UDPServer &udp_server, ServerReceiverManager *recevier_manager) :
	udp_server(udp_server), recevier_manager(recevier_manager) {
	};

	virtual void operator() (PacketBuffer *buffer, const EndPoint *ep) {
		ThreadTaskPacket *recv_data = new ThreadTaskPacket();
		recv_data->data = buffer;
		recv_data->ep = ep;
		this->recevier_manager->deliverTask(recv_data);
	}
};

class PacketTransfer_ThreadHandler : public ThreadHandlerBase {
private:
	Event_UDPServer &peer;
public:
	PacketTransfer_ThreadHandler(Event_UDPServer &peer) : peer(peer) {}
	virtual void setArg(void *arg) {}
	virtual void operator()() {
		this->peer.start();
	}
};

typedef ThreadTemplate<PacketTransfer_ThreadHandler> PacketTransfer_Thread;

}
}

using namespace Fanni::Tests;

static const string DEFAULT_ADDR = "127.0.0.1";
static const int DEFAULT_PORT = 9001;
static const int thread_number = 1;

int main(int argc, char **argv) {
	bool server_mode = false;
	if (argc == 2) {
		string arg(argv[1]);
		if (arg == "server")
			server_mode = true;
	}
	try {
		Event_UDPServer peer(::DEFAULT_ADDR, ::DEFAULT_PORT);

		PacketTransferManager *packet_transfer_manager = new PacketTransferManager(thread_number, peer.getSocket());
		packet_transfer_manager->init();

		ServerReceiverManager *server_recevier_manager = new ServerReceiverManager(thread_number, packet_transfer_manager);
		server_recevier_manager->init();

		peer.setOnRecvHandler(new PacketServer_OnRecvHandler(peer, server_recevier_manager));

		PacketTransfer_ThreadHandler thread_handler(peer);
		PacketTransfer_Thread thread(thread_handler);
		thread.kick();
		thread.join();

	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

