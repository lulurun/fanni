/*
 * Sender.h
 *
 *  Created on: Oct 19, 2009
 *      Author: lulu
 */

#ifndef SENDER_H_
#define SENDER_H_

#include "Poco/Net/DatagramSocket.h"

#include "fanni/ThreadWorker.h"
#include "fanni/ThreadManager.h"
#include "Packets/PacketBase.h"
#include "Packets/PacketSerializer.h"

namespace Fanni {

class SenderTask: public Poco::Notification {
public:
	PacketBase *data;
	Poco::Net::SocketAddress addr;

	SenderTask(PacketBase *data, const Poco::Net::SocketAddress &addr) :
		data(data), addr(addr) {
	}

	~SenderTask() {
		delete this->data;
	}
};

class TransferNode;
class Sender: public Fanni::Worker {
	friend class SenderManager;
private:
	Poco::Net::DatagramSocket &socket;
	TransferNode &node;
	PacketSerializer *packet_serializer;

protected:
	Sender(Poco::Net::DatagramSocket &socket, TransferNode &node,
			const PacketFactory &packet_factory);

public:
	virtual ~Sender();
	void doTask(Poco::Notification *data);
};

class SenderManager: public ThreadManager {
private:
	const Poco::Net::DatagramSocket &socket;
	TransferNode &node;
	const PacketFactory &packet_factory;

public:
	SenderManager(int sender_number, Poco::Net::DatagramSocket &socket,
			TransferNode &node, const PacketFactory &packet_factory);
	~SenderManager();
};

}

#endif /* SENDER_H_ */
