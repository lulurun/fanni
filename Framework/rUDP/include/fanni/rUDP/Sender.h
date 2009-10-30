/*
 * Sender.h
 *
 *  Created on: Oct 19, 2009
 *      Author: lulu
 */

#ifndef SENDER_H_
#define SENDER_H_

#include "Poco/AutoPtr.h"
#include "Poco/Net/DatagramSocket.h"
#include "fanni/EndPoint.h"
#include "fanni/ThreadWorker.h"
#include "fanni/ThreadManager.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketSerializer.h"

namespace Fanni {

class SenderTask: public Poco::Notification {
public:
	PacketBasePtr data;
	EndPoint ep;

	SenderTask(PacketBasePtr &data, const EndPoint &ep) : data(data), ep(ep) {}
	~SenderTask() {}
};

class TransferNode;
class Sender: public Fanni::Worker {
	friend class SenderManager;
private:
	Poco::Net::DatagramSocket &socket;
	TransferNode &node;
	// MEMO @@@ serializer is not thread safe, should be owned by the thread
	PacketSerializer *packet_serializer;

protected:
	Sender(Poco::Net::DatagramSocket &socket, TransferNode &node,
			const PacketFactory &packet_factory);

public:
	virtual ~Sender();
	void doTask(Poco::Notification::Ptr &data);
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
