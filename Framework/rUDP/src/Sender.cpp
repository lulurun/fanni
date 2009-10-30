/*
 * Sender.cpp
 *
 *  Created on: Oct 19, 2009
 *      Author: lulu
 */

#include <cassert>
#include <memory>

#include "fanni/Logger.h"
#include "fanni/rUDP/Sender.h"
#include "fanni/rUDP/TransferNode.h"

using namespace Poco;;
using namespace Fanni;

Sender::Sender(Poco::Net::DatagramSocket &socket, TransferNode &node, const PacketFactory &packet_factory) :
	socket(socket), node(node), packet_serializer(new PacketSerializer(packet_factory)) {
}

Sender::~Sender() {
	delete this->packet_serializer;
}

void Sender::doTask(Poco::Notification *task) {
	TRACE_LOG("enter");
	SenderTask *transfer_data = dynamic_cast<SenderTask *>(task);
	assert(transfer_data);
	int len = 0;
	PacketBase *packet = transfer_data->data;
	/*
	DEBUG_LOG("outgoing packet: ID " << packet->header.getPacketID());
	DEBUG_LOG("outgoing packet: seq " << packet->header.getSequenceNumber());
	DEBUG_LOG("outgoing packet: reliable " << packet->header.isReliable());
	DEBUG_LOG("outgoing packet: resend " << packet->header.isResent());
	DEBUG_LOG("outgoing packet: zerocode " << packet->header.isZeroCoded());
	*/
	const unsigned char *resp_buf = this->packet_serializer->serialize(packet, &len);
	this->node.processOutgoingPacket(transfer_data->data, transfer_data->ep);
	this->socket.sendTo(resp_buf, len, transfer_data->ep);
	TRACE_LOG("exit");
}

// Sender Manager
SenderManager::SenderManager(int sender_number,
		Poco::Net::DatagramSocket &socket, TransferNode &node,
		const PacketFactory &packet_factory) :
	ThreadManager(), socket(socket), node(node), packet_factory(packet_factory) {
	// create senders
	for (int i = 0; i < sender_number; i++) {
		Sender *s = new Sender(socket, node, packet_factory);
		this->addWorker(s);
	}
}

SenderManager::~SenderManager() {
	WORKER_LIST_TYPE::iterator it;
	for(WORKER_LIST_TYPE::iterator it = this->worker_list.begin(); it != this->worker_list.end(); it++){
		delete (*it);
	}
}
