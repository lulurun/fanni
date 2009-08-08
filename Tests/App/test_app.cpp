#include <iostream>
#include "Network/Event_UDPServer.h"
#include "fanni/ThreadTemplate.h"
#include "Threads/ThreadManager.h"
#include "fanni/Logger.h"

#include "PacketReactor.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;

class OnRecvHandlerA : public UDP_OnRecvHandlerBase {
private:
	PacketReactorThreadManager *reactor_mgr; // TODO @@@ not here

public:
	OnRecvHandlerA() {
		this->reactor_mgr = new PacketReactorThreadManager(1, 0 /* TODO @@@ server socket*/);
		this->reactor_mgr->init();
	};
	virtual void operator() (PacketBuffer *buffer, const EndPoint *ep) {
		TRACE_LOG("OnRecvHandlerA enter");
		UDPBuffer *msg = new UDPBuffer(buffer, ep);
		// @@@ This message will be deleted in the reactor
		this->reactor_mgr->deliverTask(msg);
		TRACE_LOG("exit");
	}
};

class UDPServerThreadHandler : public ThreadHandlerBase {
private:
	Event_UDPServer &server;
public:
	UDPServerThreadHandler(Event_UDPServer &server) : server(server) { }
	virtual void setArg(void *arg) { }
	virtual void operator()() {
		this->server.start();
	}
};

typedef ThreadTemplate<UDPServerThreadHandler> UDPServerThread;

int main() {
	// start udp server
	Event_UDPServer udp_server("127.0.0.1", 9001);
	udp_server.setOnRecvHandler(new OnRecvHandlerA());
	UDPServerThreadHandler server_thread_handler(udp_server);
	UDPServerThread server_thread(server_thread_handler);

	/* ******
	TODO @@@ !!!!! LOG4CXX_... seems to be not thread safe or ,....
	***** */

	server_thread.kick();

	server_thread.join();
	return 0;
}

