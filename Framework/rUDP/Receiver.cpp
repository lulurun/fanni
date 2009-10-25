/*
 * Receiver.cpp
 *
 *  Created on: Oct 18, 2009
 *      Author: lulu
 */

#include <cassert>
#include <memory>

#include "fanni/Logger.h"
#include "Receiver.h"
#include "TransferNode.h"

using namespace std;
using namespace Poco;
using namespace Fanni;

Receiver::Receiver(TransferNode &node, const PacketFactory &packet_factory,
		const PacketHandlerFactory &packet_handler_factory) :
	node(node), packet_handler_factory(packet_handler_factory),
			packet_serializer(new PacketSerializer(packet_factory)) {
}

Receiver::~Receiver() {
	delete this->packet_serializer;
}

void Receiver::doTask(Poco::Notification *task) {
	TRACE_LOG("enter");
	ReceiverTask *transfer_data = dynamic_cast<ReceiverTask *> (task);
	assert(transfer_data);
	try {
		//DEBUG_LOG(transfer_data->data->to_debug_string());

		auto_ptr<PacketBase> packet(this->packet_serializer->deserialize(*(transfer_data->data)));
		assert(packet.get());
		/*
		DEBUG_LOG("incoming packet: ID " << packet->header.getPacketID());
		DEBUG_LOG("incoming packet: seq " << packet->header.getSequenceNumber());
		DEBUG_LOG("incoming packet: reliable " << packet->header.isReliable());
		DEBUG_LOG("incoming packet: resend " << packet->header.isResent());
		DEBUG_LOG("incoming packet: zerocode " << packet->header.isZeroCoded());
		*/
		this->node.processIncomingPacket(packet.get(), transfer_data->addr);
		// MEMO @@@ TransferDataBuffer(packet, ep) will be deleted here
	} catch (ErrorException &e) {
		ERROR_LOG("packet handler failed. Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
	} catch (WarnException &e) {
		WARN_LOG("packet handler failed. Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
	} catch (FatalException &e) {
		FATAL_LOG("receiver loop terminated. FATAL ERROR: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg() );
		this->stop();
	}
	TRACE_LOG("exit");
}

// Receiver Manager
ReceiverManager::ReceiverManager(int receiver_number, TransferNode &node,
		const PacketFactory &packet_factory,
		const PacketHandlerFactory &packet_handler_factory) :
	ThreadManager(), node(node), packet_factory(packet_factory),
			packet_handler_factory(packet_handler_factory) {
	// create receivers
	for (int i = 0; i < receiver_number; i++) {
		Receiver *r = new Receiver(node, packet_factory, packet_handler_factory);
		this->addWorker(r);
	}
}

ReceiverManager::~ReceiverManager() {}
