/*
 * queue_packet_transfer.cpp
 *
 *  Created on: Aug 7, 2009
 *      Author: lulu
 */

#include <iostream>
// framework
#include "fanni/Logger.h"
#include "fanni/ThreadTemplate.h"
#include "Network/Event_UDPServer.h"
#include "Network/FanniSock.h"
#include "Threads/ThreadManager.h"
// packets
#include "fanni/PacketBuffer.h"
#include "Packets/PacketBase.h"
#include "Packets/Packets.h"
#include "Packets/PacketSerializer.h"
// app
#include "TransferData.h"
#include "PacketTransfer.h"
#include "ServerRecevierBase.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;

namespace Fanni {
namespace Tests {

class StartPingCheckPacketHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase *packet, const EndPoint *ep, PacketTransferManager *packet_transfer_manager) const {
		const StartPingCheckPacket *start_ping_packet = dynamic_cast<const StartPingCheckPacket *> (packet);
		if (start_ping_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint8_t ping_id = start_ping_packet->PingID.PingID;
		// create response packet
		PacketBase *packet_base = PacketFactory::GetInstance()->createPacket(CompletePingCheck_ID);
		CompletePingCheckPacket *complete_ping_packet = dynamic_cast<CompletePingCheckPacket *> (packet_base);
		if (complete_ping_packet == NULL) {
			FATAL_LOG("should never reach here");
			return;
		}
		complete_ping_packet->PingID.PingID = ping_id;
		 DEBUG_LOG("answering start_ping: " << ping_id);
		 TransferDataPacket *resp_data = new TransferDataPacket();
		 resp_data->data = complete_ping_packet;
		 resp_data->ep = ep;
		 packet_transfer_manager->deliverTask(resp_data);
	};
};

class ServerReceiverManager: public ThreadManager {
private:
	int thread_number;
	PacketTransferManager *packet_transfer_manager;
	PacketHandlerFactory packet_handler_factory;

public:
	ServerReceiverManager(int thread_number, PacketTransferManager *packet_transfer_manager) :
		thread_number(thread_number), packet_transfer_manager(packet_transfer_manager) {}

	void registerHandlers() {
		this->packet_handler_factory.registerPacketHandler(StartPingCheck_ID, new StartPingCheckPacketHandler());
	}

	virtual void init() {
		// register handlers
		this->registerHandlers();

		// init works
		for (int i = 0; i < this->thread_number; i++) {
			ServerReceiverBase *worker = new ServerReceiverBase(this->packet_transfer_manager, this->packet_handler_factory);
			this->addWorker(worker);
			worker->kick();
		}
	}
};

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
		TransferDataBuffer *recv_data = new TransferDataBuffer();
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

