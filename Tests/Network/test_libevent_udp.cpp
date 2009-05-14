#include <iostream>
#include "Network/UDPServer.h"
#include "fanni/Thread.h"

using namespace std;
using namespace Fanni;

static int counter = 0;
class OnRecvHandlerA : public OnRecvHandler {
public:
	OnRecvHandlerA() {};
	virtual void operator() (int fd, short flags) {
		UDPServer::ClientMessage msg;
		socklen_t l = sizeof(struct sockaddr);
		int recv_len = ::recvfrom(fd, msg.data.getBuffer(), FixedLengthBuffer::BUF_LEN, 0, reinterpret_cast<sockaddr *>(&msg.ep), &l);

		// TODO @@@ non-blocking ?
		if (recv_len == -1) {
			// TODO @@@ do not throw an exception. this->logger->Error();
			ErrorException::throw_exception(EXP_Network, EXP_PRE_MSG, "recvfrom() returned -1");
		} else if (recv_len == 0) {
			// TODO @@@ do not throw an exception. this->logger->Error();
		    ErrorException::throw_exception(EXP_Network, EXP_PRE_MSG, "Connection Closed");
		}
		msg.data.setLength(recv_len);
		printf("recv#%d:\n", ++counter);
		msg.data.debug_print();
	}
};

class UDPServerHandler : public ThreadHandlerBase {
private:
	UDPServer server;
public:
	UDPServerHandler(UDPServer &server) : server(server) { }
	virtual void setArg(void *arg) { }
	virtual void operator()() {
		this->server.init();
		this->server.run();
	}
};

int main() {
#if 0
	UDPServer udp_server;
	udp_server.onRecv = new OnRecvHandlerA();
	udp_server.init();
	udp_server.run();
#else
	UDPServer udp_server;
	udp_server.onRecv = new OnRecvHandlerA();
	UDPServerHandler handler(udp_server);
	Thread<UDPServerHandler> udp_server_thread(handler);
	udp_server_thread.kick();
	cout << "udp server thread started ..." << endl;
	udp_server_thread.join();
#endif
	return 0;
}

