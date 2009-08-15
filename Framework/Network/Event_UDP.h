#ifndef EVENT_UDPSERVER_H_
#define EVENT_UDPSERVER_H_

#include <string>
#include "fanni/Event++.h"
#include "fanni/Exception.h"

#include "UDPBase.h"
#include "Event_OnRecvHandler.h"

namespace Fanni {
namespace Network {

class Event_UDP : public UDPBase {
private:
	EventManager em;
	Event_OnRecvHandler *_libevent_OnRecv_handler;

	void _init();

public:
	Event_UDP();
	Event_UDP(const std::string &addr, int port);
	virtual ~Event_UDP();

	virtual void start();
};

}
}

#endif /* UDPSERVER_H_ */
