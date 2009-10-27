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

Sender::Sender(Poco::Net::DatagramSocket &socket, TransferNode &node,
		const PacketFactory &packet_factory) :
	socket(socket), node(node), packet_serializer(new PacketSerializer(
			packet_factory)) {
}

Sender::~Sender() {
	delete this->packet_serializer;
}

void Sender::doTask(Poco::Notification *task) {
	TRACE_LOG("enter");
	SenderTask *transfer_data = dynamic_cast<SenderTask *> (task);
	assert(transfer_data);
	try {
		int len = 0;
		PacketBase *packet = const_cast<PacketBase *> (transfer_data->data);
		/*
		DEBUG_LOG("outgoing packet: ID " << packet->header.getPacketID());
		DEBUG_LOG("outgoing packet: seq " << packet->header.getSequenceNumber());
		DEBUG_LOG("outgoing packet: reliable " << packet->header.isReliable());
		DEBUG_LOG("outgoing packet: resend " << packet->header.isResent());
		DEBUG_LOG("outgoing packet: zerocode " << packet->header.isZeroCoded());
		*/
		const unsigned char *resp_buf = this->packet_serializer->serialize(packet, &len);
		this->node.processOutgoingPacket(transfer_data->data, transfer_data->addr);
		this->socket.sendTo(resp_buf, len, transfer_data->addr);
	} catch (ErrorException &e) {
		ERROR_LOG("rUDP", "packet handler failed. Exception: " << e.get_func()
				<< " at L" << e.get_line() << " " << e.get_msg());
	} catch (WarnException &e) {
		WARN_LOG("rUDP", "packet handler failed. Exception: " << e.get_func()
				<< " at L" << e.get_line() << " " << e.get_msg());
	} catch (FatalException &e) {
		FATAL_LOG("rUDP", "receiver loop terminated. FATAL ERROR: " << e.get_func()
				<< " at L" << e.get_line() << " " << e.get_msg());
		this->stop();
	}
	TRACE_LOG("exit");
}

// Sender Manager
SenderManager::SenderManager(int sender_number,
		Poco::Net::DatagramSocket &socket, TransferNode &node,
		const PacketFactory &packet_factory) :
	ThreadManager(), socket(socket), node(node), packet_factory(packet_factory) {
	// create senders
	for (int i = 0; i < sender_number; i++) {
		Sender *r = new Sender(socket, node, packet_factory);
		this->addWorker(r);
	}
}

SenderManager::~SenderManager() {
}
