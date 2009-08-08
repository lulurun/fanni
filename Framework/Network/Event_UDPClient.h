/*
 * Event_UDPClient.h
 *
 *  Created on: Aug 5, 2009
 *      Author: lulu
 */

#ifndef EVENT_UDPCLIENT_H_
#define EVENT_UDPCLIENT_H_

#include <string>
#include "fanni/Event++.h"
#include "fanni/Exception.h"
#include "UDPBase.h"

namespace Fanni {
namespace Network {

class Event_UDPClient : public UDPBase{
private:
	EventManager em;
	Event_OnRecvHandler *_libevent_OnRecv_handler;

public:

	Event_UDPClient();
	Event_UDPClient(const std::string &addr, int port);
	virtual ~Event_UDPClient();

	virtual void start() {};
	virtual void connect();
};

}
}

#endif /* EVENT_UDPCLIENT_H_ */
