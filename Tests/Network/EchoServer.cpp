#include <iostream>
#include "Network/Event_UDP.h"
#include "Network/FanniSock.h"

#include "fanni/Logger.h"
#include "fanni/ThreadTemplate.h"
#include "Threads/ThreadManager.h"

// packets
#include "fanni/PacketBuffer.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;

namespace Fanni {
namespace Tests {

// Server handler
class PacketServer_OnRecvHandler : public UDP_OnRecvHandlerBase {
private:
	Event_UDP &udp_server;

public:
	PacketServer_OnRecvHandler(Event_UDP &udp_server) :
		udp_server(udp_server){};

	virtual void operator() (PacketBuffer *buffer, const EndPoint *ep) {
		cout << "recv: " << buffer->getFixedLength() << endl;
		cout << "recv: " << buffer->to_debug_string() << endl;
		FanniSock::SendPacket(this->udp_server.getSocket(), buffer->getLength(), buffer->getBuffer(), ep->getSockAddr());
	}
};

}
}

using namespace Fanni::Tests;

static const string DEFAULT_ADDR = "0.0.0.0";
static const int DEFAULT_PORT = 9001;

int main(int argc, char **argv) {
	try {
		Event_UDP peer(::DEFAULT_ADDR, ::DEFAULT_PORT);
		peer.setOnRecvHandler(new PacketServer_OnRecvHandler(peer));

		SimpleThreadTemplate<Event_UDP> thread(peer);
		thread.kick();
		thread.join();
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

