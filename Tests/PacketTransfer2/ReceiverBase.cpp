/*
 * RecevierBase.cpp
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#include "LLPackets/LLPacketFactory.h"
#include "ReceiverBase.h"
#include "PacketServer.h"

using namespace Fanni;
using namespace Fanni::Tests;
using namespace Fanni::Network;

// ==========
// RecevierBase
ReceiverBase::ReceiverBase(PacketHandlerFactory &phf, PacketTransferBase *transfer_peer) :
	packet_handler_factory(phf), transfer_peer(transfer_peer) {
	this->packet_serializer = CreateLLPacketSerializer();
}

ReceiverBase::~ReceiverBase() {
	delete this->packet_serializer;
}

void ReceiverBase::loop() {
	while (1) {
		const ThreadTask *task = this->queue->pop();
		const TransferDataBuffer *const_queue_data = dynamic_cast<const TransferDataBuffer *> (task);
		if (!const_queue_data) {
			FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"unexpected queue data type" );
		}
		try {
			auto_ptr<const TransferDataBuffer> auto_queue_data();
			PacketBase *packet = this->packet_serializer->deserialize(*(const_queue_data->data));
			// RESEND, ACK management
			this->transfer_peer->processIncomingPacket(packet, const_queue_data->ep);
			// dispatch packet handler
			const PacketHandlerBase *packet_handler = this->packet_handler_factory.getPacketHandler(packet->header.getPacketID());
			// MEMO @@@ (inside getPacketHandler:) packet_handler can not be null;
			packet_handler->operator()(packet, const_queue_data->ep, this->transfer_peer);
		} catch (ErrorException &e) {
			ERROR_LOG("packet handler failed. Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
		} catch (WarnException &e) {
			WARN_LOG("packet handler failed. Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
		} catch (FatalException &e) {
			FATAL_LOG("receiver loop terminated. FATAL ERROR: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
			break;
		}
	}
}

void ReceiverBase::stop() {
	// TODO @@@
}

// ==========
// RecevierManager
ReceiverManager::ReceiverManager(int thread_number, PacketTransferBase *transfer_peer) :
	thread_number(thread_number), transfer_peer(transfer_peer) {}

void ReceiverManager::registerHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *handler) {
	this->packet_handler_factory.registerPacketHandler(packet_id, handler);
};

void ReceiverManager::init() {
	// TODO @@@ register handlers ?
	// init workers
	for (int i = 0; i < this->thread_number; i++) {
		ReceiverBase *worker = new ReceiverBase(this->packet_handler_factory, this->transfer_peer);
		this->addWorker(worker);
		worker->kick();
	}
}


