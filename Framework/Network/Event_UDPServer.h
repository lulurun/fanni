#ifndef EVENT_UDPSERVER_H_
#define EVENT_UDPSERVER_H_

#include <string>
#include "fanni/Event++.h"
#include "fanni/Exception.h"
#include "UDPServerBase.h"

namespace Fanni {
namespace Network {

class Event_UDPServer : public UDPServerBase {
private:
	// only used internally
	class Private_OnRecvHandler : public EventHandlerBase {
		const OnRecvHandlerBase *UDPServer_recv_handler;
	public:
		Private_OnRecvHandler(const OnRecvHandlerBase *handler) {
			this->UDPServer_recv_handler = handler;
		}
		virtual void operator() (int fd, short flags) const;
	};

private:
	EventManager em;
	Private_OnRecvHandler *_private_handler;

public:
	Event_UDPServer();
	Event_UDPServer(const std::string &addr, int port);
	virtual ~Event_UDPServer();

	virtual void start();
	virtual void shutdown();

};

}
}

#endif /* UDPSERVER_H_ */
