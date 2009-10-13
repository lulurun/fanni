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
#include "Threads/SeqGenerator.h"
#include "Network/Event_UDP.h"
#include "Packets/PacketSerializer.h"

#include "PacketHandlerFactory.h"

namespace Fanni {

class PacketTransferBase;
class SenderBase: public ThreadWorker {
	friend class SenderManager;
private:
	SequenceGenerator seq_gen;
	const Fanni::Network::Event_UDP &udp_server;
	PacketTransferBase &transfer_peer;
	PacketSerializer *packet_serializer;

protected:
	SenderBase(const Fanni::Network::Event_UDP &udp_server,
			PacketTransferBase &transfer_peer,
			const PacketFactory &packet_factory);
public:
	~SenderBase();
	virtual void loop_func();
};

class SenderManager: public ThreadManager {
private:
	int thread_number;
	PacketTransferBase &transfer_peer;
	const PacketFactory &packet_factory;
	const Fanni::Network::Event_UDP &udp_server;

public:
	SenderManager(int thread_number, PacketTransferBase &transfer_peer,
			const PacketFactory &packet_factory,
			const Fanni::Network::Event_UDP &udp_server);
	virtual void init();
};

}

#endif /* SENDERBASE_H_ */
