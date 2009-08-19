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
#include "Network/Event_UDP.h"
#include "Network/FanniSock.h"
#include "Threads/ThreadManager.h"
#include "Threads/SeqGenerator.h"
// packets
#include "fanni/PacketBuffer.h"
#include "Packets/PacketBase.h"
#include "Packets/Packets.h"
#include "Packets/PacketSerializer.h"
// app
#include "TransferData.h"
#include "PacketTransfer.h"
#include "RecevierBase.h"
#include "PacketTransferHandlers.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;

namespace Fanni {
namespace Tests {

class PacketTransfer_OnRecvHandler : public UDP_OnRecvHandlerBase {
private:
	PacketSerializer packet_serializer;
	ReceiverManager *recevier_manager;

public:
	PacketTransfer_OnRecvHandler(ReceiverManager *recevier_manager) : recevier_manager(recevier_manager) {};

	virtual void operator() (PacketBuffer *buffer, const EndPoint *ep) {
		TransferDataBuffer *recv_data = new TransferDataBuffer(buffer, ep);
		this->recevier_manager->deliverTask(recv_data);
	}
};

class PacketTransfer_ThreadHandler : public ThreadHandlerBase {
private:
	Event_UDP &peer;
public:
	PacketTransfer_ThreadHandler(Event_UDP &peer) : peer(peer) {}
	virtual void setArg(void *arg) {}
	virtual void operator()() {
		this->peer.start();
	}
};

typedef ThreadTemplate<PacketTransfer_ThreadHandler> PacketTransfer_Thread;

static SequenceGenerator *sg = SequenceGeneratorFactory::GetInstance()->createGenerator();
class Event_UDPClient : public Event_UDP {
private:
	EndPoint current_server;
	PacketTransferManager *packet_transfer_manager;

	void sendStartPingCheck(uint8_t ping_id) {
		PacketBase *packet = PacketFactory::GetInstance()->createPacket(StartPingCheck_ID);
		StartPingCheckPacket *start_ping_packet = dynamic_cast<StartPingCheckPacket *> (packet);
		if (start_ping_packet == NULL) {
			FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"wrong implementation" );
		}
		start_ping_packet->PingID.PingID = ping_id;
		start_ping_packet->setSequence(sg->next());
		TransferDataPacket *transfer_packet = new TransferDataPacket(start_ping_packet, &this->current_server);
		this->packet_transfer_manager->deliverTask(transfer_packet);
	};

public:
	Event_UDPClient(int thread_number) : Event_UDP(){
		this->packet_transfer_manager = new PacketTransferManager(thread_number, this->socket);
		this->packet_transfer_manager->init();
	}

	int connect(const EndPoint &ep) {
		this->current_server = ep;
		return 0;
	}

	void test() {
		for(int i=0; i<100; i++) {
			this->sendStartPingCheck(i);
		}
	}
};

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
		if (arg == "server") server_mode = true;
	}
	try {
		if (server_mode) {
			DEBUG_LOG("enter Server mode");
			Event_UDP peer(DEFAULT_ADDR, DEFAULT_PORT);
			// set UDP server handlers
			PacketTransferManager *packet_transfer_manager = new PacketTransferManager(thread_number, peer.getSocket());
			packet_transfer_manager->init();
			ReceiverManager *recevier_manager = new ReceiverManager(thread_number, packet_transfer_manager);
			recevier_manager->init();
			// register packet handlers
			recevier_manager->registerHandler(StartPingCheck_ID, new StartPingCheckPacketHandler());
			peer.setOnRecvHandler(new PacketTransfer_OnRecvHandler(recevier_manager));
			// start UDP server
			PacketTransfer_ThreadHandler thread_handler(peer);
			PacketTransfer_Thread thread(&thread_handler);
			thread.kick();
			thread.join();
		} else {
			DEBUG_LOG("enter Client mode");
			Event_UDPClient peer(thread_number);
			// set UDP client handlers
			PacketTransferManager *packet_transfer_manager = new PacketTransferManager(thread_number, peer.getSocket());
			packet_transfer_manager->init();
			ReceiverManager *recevier_manager = new ReceiverManager(thread_number, packet_transfer_manager);
			recevier_manager->init();
			// register packet handlers
			recevier_manager->registerHandler(CompletePingCheck_ID, new CompletePingCheckPacketHandler());
			peer.setOnRecvHandler(new PacketTransfer_OnRecvHandler(recevier_manager));
			// start UDP client
			PacketTransfer_ThreadHandler thread_handler(peer);
			PacketTransfer_Thread thread(&thread_handler);
			thread.kick();

			sleep(1);
			EndPoint server_ep(::DEFAULT_ADDR, ::DEFAULT_PORT);
			peer.connect(server_ep);
			peer.test();

			thread.join();
		}
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

