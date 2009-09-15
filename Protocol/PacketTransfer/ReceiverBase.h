/*
 * ServerRecevierBase.h
 *
 *  Created on: Aug 8, 2009
 *      Author: lulu
 */

#ifndef SERVERRECEVIERBASE_H_
#define SERVERRECEVIERBASE_H_

// framework
#include "Threads/ThreadWorker.h"
#include "Threads/ThreadManager.h"
#include "Packets/PacketHeader.h"
#include "Packets/PacketSerializer.h"

// app
#include "TransferData.h"
#include "PacketHandlerFactory.h"

namespace Fanni {

class PacketTransferBase;
class ReceiverBase: public ThreadWorker {
private:
	PacketTransferBase *transfer_peer;
	const PacketHandlerFactory *packet_handler_factory;
	PacketSerializer *packet_serializer;

public:
	ReceiverBase(PacketTransferBase *transfer_peer, const PacketHandlerFactory *packet_handler_factory, const PacketFactory *packet_factory);
	~ReceiverBase();
	virtual void loop();
	virtual void stop();
};

class ReceiverManager: public ThreadManager {
private:
	int thread_number;
	PacketTransferBase *transfer_peer;
	const PacketFactory* packet_factory;
	const PacketHandlerFactory *packet_handler_factory;

public:
	ReceiverManager(int thread_number, PacketTransferBase *transfer_peer,
			const PacketFactory *packet_factory, const PacketHandlerFactory *packet_handler_factory);
	virtual void init();
};

}

#endif /* SERVERRECEVIERBASE_H_ */

