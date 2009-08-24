/*
 * SenderBase.cpp
 *
 *  Created on: Aug 19, 2009
 *      Author: lulu
 */

#include "fanni/Exception.h"
#include "FileTransferPackets/FileTransferPacketFactory.h"

#include "TransferData.h"
#include "SenderBase.h"
#include "PacketTransferBase.h"

using namespace Fanni;
using namespace Fanni::Network;
using namespace Fanni::Tests;

// ==========
// SenderBase
SenderBase::SenderBase(const Event_UDP &udp_server, PacketTransferBase *transfer_peer) :
	udp_server(udp_server), transfer_peer(transfer_peer) {
	this->packet_serializer = CreateFileTransferPacketSerializer();
}

SenderBase::~SenderBase() {
	delete this->packet_serializer;
}

void SenderBase::loop() {
	while (1) {
		const ThreadTask *task = this->queue->pop();
		TRACE_LOG("get sending packet");
		const TransferDataPacket *const_queue_data = dynamic_cast<const TransferDataPacket *> (task);
		if (!const_queue_data) {
			FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"unexpected queue data type" );
		}
		std::auto_ptr<const TransferDataPacket> auto_queue_data(const_queue_data);

		int len = 0;
		const unsigned char *resp_buf = this->packet_serializer->serialize(const_queue_data->data, &len);
		this->transfer_peer->processOutgoingPacket(const_queue_data->data, const_queue_data->ep);
		this->udp_server.send(resp_buf, len, *const_queue_data->ep);
		TRACE_LOG("exit send packet");
	}
}

void SenderBase::stop() {
	// TODO @@@
}

// ==========
// SenderManager
SenderManager::SenderManager(int thread_number, const Event_UDP &udp_server, PacketTransferBase *transfer_peer) :
	thread_number(thread_number), udp_server(udp_server), transfer_peer(transfer_peer) {}

void SenderManager::init() {
	// init workers
	for (int i = 0; i < this->thread_number; i++) {
		SenderBase *worker = new SenderBase(this->udp_server, this->transfer_peer);
		this->addWorker(worker);
		worker->kick();
	}
}


