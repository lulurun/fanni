/*
 * Receiver.h
 *
 *  Created on: Oct 18, 2009
 *      Author: lulu
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include "fanni/EndPoint.h"
#include "fanni/ThreadWorker.h"
#include "fanni/ThreadManager.h"
#include "fanni/Packets/PacketHeader.h"
#include "fanni/Packets/PacketSerializer.h"
#include "PacketHandlerFactory.h"

namespace Fanni {

class ReceiverTask: public Poco::Notification {
public:
	PacketBuffer *data;
	EndPoint ep;

	ReceiverTask(PacketBuffer *data, const EndPoint &ep) :
		data(data), ep(ep) {
	}
	~ReceiverTask() {
		delete this->data;
	}
};

class TransferNode;
class Receiver: public Fanni::Worker {
	friend class ReceiverManager;
private:
	TransferNode &node;
	const PacketHandlerFactory &packet_handler_factory;
	// MEMO @@@ serializer is not thread safe, should be owned by the thread
	PacketSerializer *packet_serializer;

protected:
	Receiver(TransferNode &node, const PacketFactory &packet_factory,
			const PacketHandlerFactory &packet_handler_factory);

public:
	virtual ~Receiver();
	void doTask(Poco::Notification *data);
};

class ReceiverManager: public ThreadManager {
private:
	TransferNode &node;
	const PacketFactory &packet_factory;
	const PacketHandlerFactory &packet_handler_factory;

public:
	ReceiverManager(int receiver_number, TransferNode &node,
			const PacketFactory &packet_factory,
			const PacketHandlerFactory &packet_handler_factory);
	~ReceiverManager();
};

}

#endif /* RECEIVER_H_ */
