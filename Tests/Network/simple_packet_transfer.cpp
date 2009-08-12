#include <iostream>
#include "Network/Event_UDP.h"
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

static SequenceGenerator *sg =
		SequenceGeneratorFactory::GetInstance()->createGenerator();

// Client
class Test_UDPClient : public Event_UDP {
private:
	PacketSerializer serializer;
	EndPoint current_server;

public:
	Test_UDPClient() {};
	virtual ~Test_UDPClient() {};

	void sendStartPingCheck(uint8_t ping_id) {
		PacketBase *packet = PacketFactory::GetInstance()->createPacket(StartPingCheck_ID);
		StartPingCheckPacket *start_ping_packet = dynamic_cast<StartPingCheckPacket *> (packet);
		if (start_ping_packet == NULL) {
			FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"wrong implementation" );
		}
		start_ping_packet->PingID.PingID = ping_id;
		start_ping_packet->setSequence(sg->next());

		int buffer_size = 0;
		const unsigned char *buffer = this->serializer.serialize(start_ping_packet, &buffer_size);
		FanniSock::SendPacket(this->socket, buffer_size, buffer, this->current_server.getSockAddr());
	};

	int connect(const EndPoint &ep) {
		this->current_server = ep;
		return 0;
	};

	virtual void test() {
		TRACE_LOG("enter");
		if (this->socket == FanniSock::INVALID_SOCKET) {
			ErrorException::throw_exception(EXP_TEST, EXP_PRE_MSG,"error creating socket" );
		}
		for (uint8_t i = 0; i < 100; i++) {
			this->sendStartPingCheck(i);
		}
		TRACE_LOG("exit");
	};
};

//Client handler
class PacketClient_OnRecvHandler: public UDP_OnRecvHandlerBase {
private:
	PacketSerializer packet_serializer;

public:
	PacketClient_OnRecvHandler() {}

	virtual void operator()(PacketBuffer *buffer, const EndPoint *ep) {
		TRACE_LOG("enter");
		PacketBase *packet_base;

		// get request packet
		packet_base = this->packet_serializer.deserialize(*buffer);
		DEBUG_LOG("incoming packet " <<
				"FROM: " << ep->getAddrStr() << ":" << ep->getPort() << "\n" <<
				" [id]: " << hex << packet_base->header.getPacketID() << dec <<
				" [seq] " << packet_base->header.getSequenceNumber() <<
				" [reliable] " << packet_base->header.isReliable() <<
				" [resent] " << packet_base->header.isResent() <<
				" [ack] " << packet_base->header.isAppendedAcks()
		);

		CompletePingCheckPacket *complete_ping_packet =
				dynamic_cast<CompletePingCheckPacket *> (packet_base);
		if (complete_ping_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint8_t ping_id = complete_ping_packet->PingID.PingID;
		// TODO @@@ delete buffer ???
		delete buffer;

		DEBUG_LOG("recv complete_ping: " << ping_id);

		TRACE_LOG("exit");
	}
};

// Server handler
class PacketServer_OnRecvHandler : public UDP_OnRecvHandlerBase {
private:
	PacketSerializer packet_serializer;
	Event_UDP &udp_server;

public:
	PacketServer_OnRecvHandler(Event_UDP &udp_server) :
		udp_server(udp_server){
	};

	virtual void operator() (PacketBuffer *buffer, const EndPoint *ep) {
		TRACE_LOG("enter");
		PacketBase *packet_base;

		// get request packet
		packet_base = this->packet_serializer.deserialize(*buffer);
		DEBUG_LOG("incoming packet " <<
				"FROM: " << ep->getAddrStr() << ":" << ep->getPort() << "\n" <<
				" [id]: " << hex << packet_base->header.getPacketID() << dec <<
				" [seq] " << packet_base->header.getSequenceNumber() <<
				" [reliable] " << packet_base->header.isReliable() <<
				" [resent] " << packet_base->header.isResent() <<
				" [ack] " << packet_base->header.isAppendedAcks()
				);

		StartPingCheckPacket *start_ping_packet = dynamic_cast<StartPingCheckPacket *>(packet_base);
		if (start_ping_packet == NULL) {
			ERROR_LOG("unexpected packet type");
			return;
		}
		uint8_t ping_id = start_ping_packet->PingID.PingID;
		// TODO @@@ delete buffer ???
		delete buffer;
		// create response packet
		packet_base = PacketFactory::GetInstance()->createPacket(CompletePingCheck_ID);
		CompletePingCheckPacket *complete_ping_packet = dynamic_cast<CompletePingCheckPacket *>(packet_base);
		if (complete_ping_packet == NULL) {
			FATAL_LOG("should never reach here");
			return;
		}
		complete_ping_packet->PingID.PingID = ping_id;

		int len = 0;
		const unsigned char *resp_buf = this->packet_serializer.serialize(complete_ping_packet, &len);

		// send response
		if (len > 0) {
			DEBUG_LOG("anwsering start_ping: " << ping_id);
			FanniSock::SendPacket(this->udp_server.getSocket(), len, resp_buf, ep->getSockAddr());
		}

		TRACE_LOG("exit");
	}
};

class PacketTransfer_ThreadHandler : public ThreadHandlerBase {
private:
	Event_UDP &peer;
public:
	PacketTransfer_ThreadHandler(Event_UDP &peer) : peer(peer) { }
	virtual void setArg(void *arg) { }
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

int main(int argc, char **argv) {
	bool server_mode = false;
	if (argc == 2) {
		string arg(argv[1]);
		if (arg == "server") server_mode = true;
	}
	try {
		if (server_mode) {
			Event_UDP peer(::DEFAULT_ADDR, ::DEFAULT_PORT);
			peer.setOnRecvHandler(new PacketServer_OnRecvHandler(peer));

			PacketTransfer_ThreadHandler thread_handler(peer);
			PacketTransfer_Thread thread(thread_handler);
			thread.kick();
			thread.join();
		} else {
			Test_UDPClient peer;
			peer.setOnRecvHandler(new PacketClient_OnRecvHandler());

			PacketTransfer_ThreadHandler thread_handler(peer);
			PacketTransfer_Thread thread(thread_handler);
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

