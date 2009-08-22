/*
 * PacketTransfer.cpp
 *
 *  Created on: Aug 10, 2009
 *      Author: lulu
 */

#include "fanni/Timer.h"
#include "Network/FanniSock.h"

#include "PacketTransfer.h"
#include "TransferData.h"

using namespace Fanni;
using namespace Tests;

// ============
// PacketSender
void PacketSender::loop() {
	while (1) {
		const ThreadTask *task = this->queue->pop();
		const TransferDataPacket *const_queue_data = dynamic_cast<const TransferDataPacket *> (task);
		if (!const_queue_data) {
			FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"unexpected queue data type" );
		}
		std::auto_ptr<const TransferDataPacket> auto_queue_data(const_queue_data);

		int len = 0;
		const unsigned char *resp_buf = this->packet_serializer->serialize(const_queue_data->data, &len);
		Fanni::Network::FanniSock::SendPacket(this->server_socket, len, resp_buf, *reinterpret_cast<const sockaddr *>(const_queue_data->ep));
	}
}

// ============
// PacketTransferManager
void PacketTransferManager::init() {
	for (int i = 0; i < this->thread_number; i++) {
		PacketSender *worker = new PacketSender(server_socket);
		this->addWorker(worker);
		worker->kick();
	}
}

/*
void PacketTransferManager::processIncomingPacket(PacketBase *packet, const EndPoint *ep) {

}
*/
