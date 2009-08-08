/*
 * PacketTransfer.h
 *
 *  Created on: Aug 8, 2009
 *      Author: lulu
 */

#ifndef PACKETTRANSFER_H_
#define PACKETTRANSFER_H_

#include "Network/FanniSock.h"
#include "Threads/ThreadManager.h"
#include "Packets/PacketSerializer.h"

#include "TransferData.h"

namespace Fanni {
namespace Tests {

class PacketSender: public ThreadWorker {
private:
	int server_socket;
	PacketSerializer packet_serializer;

public:
	PacketSender(int server_socket) :
		server_socket(server_socket) {}

	virtual void loop() {
		while (1) {
			const ThreadTask *task = this->queue->pop();
			const TransferDataPacket *const_queue_data = dynamic_cast<const TransferDataPacket *> (task);
			if (!const_queue_data) {
				FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"unexpected queue data type" );
			}
			int len = 0;
			const unsigned char *resp_buf = this->packet_serializer.serialize(const_queue_data->data, &len);
			Fanni::Network::FanniSock::SendPacket(this->server_socket, len, resp_buf, *reinterpret_cast<const sockaddr *>(const_queue_data->ep));
		}
	}

	virtual void stop() {
		;
	}
};

class PacketTransferManager: public ThreadManager {
private:
	int thread_number;
	int server_socket;

public:
	PacketTransferManager(int thread_number, int server_socket) :
		thread_number(thread_number), server_socket(server_socket) {}

	virtual void init() {
		for (int i = 0; i < this->thread_number; i++) {
			PacketSender *worker = new PacketSender(server_socket);
			this->addWorker(worker);
			worker->kick();
		}
	}
};

}
}

#endif /* PACKETTRANSFER_H_ */
