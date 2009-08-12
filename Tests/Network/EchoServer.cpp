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
		FanniSock::SendPacket(this->udp_server.getSocket(), buffer->getLength(), buffer->getBuffer(), ep->getSockAddr());
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

static const string DEFAULT_ADDR = "0.0.0.0";
static const int DEFAULT_PORT = 9001;

int main(int argc, char **argv) {
	try {
		Event_UDP peer(::DEFAULT_ADDR, ::DEFAULT_PORT);
		peer.setOnRecvHandler(new PacketServer_OnRecvHandler(peer));

		PacketTransfer_ThreadHandler thread_handler(peer);
		PacketTransfer_Thread thread(thread_handler);
		thread.kick();
		thread.join();
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

