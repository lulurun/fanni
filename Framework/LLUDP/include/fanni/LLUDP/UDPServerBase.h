/*
 * UDPServerBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_UDPSERVERBASE_H_
#define FANNI_UDPSERVERBASE_H_

#include "Poco/AutoPtr.h"
#include "Poco/Thread.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/SocketNotification.h"
#include "fanni/EndPoint.h"
#include "fanni/PacketBuffer.h"
#include "fanni/LLUDP/LLUDP_def.h"

namespace Fanni {

class Fanni_LLUDP_API UDPServerBase {
private:
	Poco::Net::DatagramSocket socket;
	Poco::Net::SocketReactor reactor;
	Poco::Thread reactor_thread;

public:
	UDPServerBase(const EndPoint &server_ep);
	virtual ~UDPServerBase();
	inline int sendData(PacketBuffer &buffer, const EndPoint &ep) {
		return this->socket.sendTo(buffer->getBuffer(), buffer->getLength(), ep);
	};

	// UDPServerHandler
	void onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& pNf);
	void onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf);

	virtual void processIncomingData(PacketBuffer &buffer, const EndPoint &ep) = 0;
};

}

#endif /* FANNI_UDPSERVERBASE_H_ */

