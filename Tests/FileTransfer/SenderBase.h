/*
 * SenderBase.h
 *
 *  Created on: Aug 19, 2009
 *      Author: lulu
 */

#ifndef SENDERBASE_H_
#define SENDERBASE_H_

#include "Threads/ThreadWorker.h"
#include "Threads/ThreadManager.h"
#include "Network/Event_UDP.h"
#include "Packets/PacketSerializer.h"

#include "PacketHandlerFactory.h"

namespace Fanni {
namespace Tests {

class PacketTransferBase;
class SenderBase : public ThreadWorker {
private:
	PacketSerializer *packet_serializer;
	const Fanni::Network::Event_UDP &udp_server;
	PacketTransferBase *transfer_peer;

public:
	SenderBase(const Fanni::Network::Event_UDP &udp_server, PacketTransferBase *peer);
	~SenderBase();
	virtual void loop();
	virtual void stop();
};


class SenderManager: public ThreadManager {
private:
	PacketHandlerFactory packet_handler_factory;
	int thread_number;
	const Fanni::Network::Event_UDP &udp_server;
	PacketTransferBase *transfer_peer;

public:
	SenderManager(int thread_number, const Fanni::Network::Event_UDP &udp_server, PacketTransferBase *peer);
	virtual void init();
};

}
}

#endif /* SENDERBASE_H_ */
