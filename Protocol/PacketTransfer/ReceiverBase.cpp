/*
 * RecevierBase.cpp
 *
 *  Created on: Aug 16, 2009
 *      Author: lulu
 */

#include "ReceiverBase.h"
#include "PacketTransferBase.h"

using namespace Fanni;

// ==========
// RecevierBase
ReceiverBase::ReceiverBase(PacketTransferBase *transfer_peer,
		const PacketFactory *packet_factory,
		const PacketHandlerFactory *packet_handler_factory) :
	transfer_peer(transfer_peer), packet_handler_factory(packet_handler_factory) {
	this->packet_serializer = new PacketSerializer(packet_factory);
}

ReceiverBase::~ReceiverBase() {
	delete this->packet_serializer;
}

void ReceiverBase::loop() {
	while (1) {
		auto_ptr<const TransferDataBuffer> transfer_data(
				dynamic_cast<const TransferDataBuffer *> (this->queue->pop()));
		assert(transfer_data.get());
		try {
			auto_ptr<PacketBase> packet(this->packet_serializer->deserialize(*(transfer_data->data)));
			assert(packet.get());
			// RESEND, ACK management
			this->transfer_peer->processIncomingPacket(packet.get(), transfer_data->ep);
			if ( !this->transfer_peer->skipHandlePacket( packet->header.getPacketID() ) ) {
				// dispatch packet handler
				const PacketHandlerBase *packet_handler = this->packet_handler_factory->getPacketHandler(packet->header.getPacketID());
				// MEMO @@@ (inside getPacketHandler:) packet_handler never be null;
				packet_handler->operator()(packet.get(), transfer_data->ep,this->transfer_peer);
			}
			// MEMO @@@ TransferDataBuffer(packet, ep) will be deleted here
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
ReceiverManager::ReceiverManager(int thread_number,
		PacketTransferBase *transfer_peer, const PacketFactory *packet_factory,
		const PacketHandlerFactory *packet_handler_factory) :
	thread_number(thread_number), transfer_peer(transfer_peer), packet_factory(
			packet_factory), packet_handler_factory(packet_handler_factory) {
}

void ReceiverManager::init() {
	// TODO @@@ register handlers ?
	// init workers
	for (int i = 0; i < this->thread_number; i++) {
		ReceiverBase *worker = new ReceiverBase(this->transfer_peer, this->packet_factory, this->packet_handler_factory);
		this->addWorker(worker);
		worker->kick();
	}
}

