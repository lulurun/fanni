/*
 * SenderBase.cpp
 *
 *  Created on: Aug 19, 2009
 *      Author: lulu
 */

#include <cassert>
#include "fanni/Exception.h"
#include "TransferData.h"
#include "SenderBase.h"
#include "PacketTransferBase.h"

using namespace Fanni;
using namespace Fanni::Network;

// ==========
// SenderBase
SenderBase::SenderBase(const Event_UDP &udp_server,
		PacketTransferBase &transfer_peer, const PacketFactory &packet_factory) :
	udp_server(udp_server), transfer_peer(transfer_peer),
	packet_serializer(new PacketSerializer(packet_factory)) { }

SenderBase::~SenderBase() {
	delete this->packet_serializer;
}

void SenderBase::loop_func() {
	try {
		const TransferDataPacket *const_queue_data = dynamic_cast<const TransferDataPacket *> (this->getTask());
		assert(const_queue_data);
		std::auto_ptr<const TransferDataPacket> data_ptr(const_queue_data);
		int len = 0;
		PacketBase *packet = const_cast<PacketBase *> (const_queue_data->data);
		const unsigned char *resp_buf = this->packet_serializer->serialize(packet, &len);
		this->transfer_peer.processOutgoingPacket(const_queue_data->data, const_queue_data->ep_ptr);
		this->udp_server.send(resp_buf, len, *const_queue_data->ep_ptr);
	} catch (ErrorException &e) {
		ERROR_LOG("packet handler failed. Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
	} catch (WarnException &e) {
		WARN_LOG("packet handler failed. Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
	} catch (FatalException &e) {
		FATAL_LOG("receiver loop terminated. FATAL ERROR: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
		this->stop();
	}
}

// ==========
// SenderManager
SenderManager::SenderManager(int thread_number,
		PacketTransferBase &transfer_peer, const PacketFactory &packet_factory,
		const Event_UDP &udp_server) :
	thread_number(thread_number), transfer_peer(transfer_peer), packet_factory(
			packet_factory), udp_server(udp_server) {
}

void SenderManager::init() {
	// init workers
	for (int i = 0; i < this->thread_number; i++) {
		SenderBase *worker = new SenderBase(this->udp_server,
				this->transfer_peer, this->packet_factory);
		this->addWorker(worker);
		worker->kick();
	}
}

