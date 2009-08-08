/*
 * ServerRecevierBase.h
 *
 *  Created on: Aug 8, 2009
 *      Author: lulu
 */

#ifndef SERVERRECEVIERBASE_H_
#define SERVERRECEVIERBASE_H_

// framework
#include "Threads/ThreadWorker.h"
// app
#include "TransferData.h"
#include "PacketTransfer.h"
#include "PacketHandlerFactory.h"

namespace Fanni {
namespace Tests {

class ServerReceiverBase : public ThreadWorker {
private:
	PacketSerializer packet_serializer;
	PacketTransferManager *packet_transfer_manager;
	const PacketHandlerFactory &packet_handler_factory;

	void processIncomingPacket(TransferDataBuffer *queue_data) {
		auto_ptr<TransferDataBuffer> auto_queue_data(queue_data);
		PacketBuffer *buffer = queue_data->data;
		const EndPoint *ep = queue_data->ep;
		// get request packet
		PacketBase *packet_base = this->packet_serializer.deserialize(*buffer);

		DEBUG_LOG("incoming packet " <<
				"FROM: " << ep->getAddrStr() << ":" << ep->getPort() << "\n" <<
				" [id]: " << hex << packet_base->header.getPacketID() << dec <<
				" [seq] " << packet_base->header.getSequenceNumber() <<
				" [reliable] " << packet_base->header.isReliable() <<
				" [resent] " << packet_base->header.isResent() <<
				" [ack] " << packet_base->header.isAppendedAcks()
		);

		const PacketHandlerBase *packet_handler = this->packet_handler_factory.getPacketHandler(packet_base->header.getPacketID());
		packet_handler->operator()(packet_base, ep, this->packet_transfer_manager);
	}

public:
	ServerReceiverBase(PacketTransferManager *ptm, PacketHandlerFactory &phf) :
		packet_transfer_manager(ptm), packet_handler_factory(phf) {}

	virtual void loop() {
		while (1) {
			const ThreadTask *task = this->queue->pop();
			const TransferDataBuffer *const_queue_data =
					dynamic_cast<const TransferDataBuffer *> (task);
			if (!const_queue_data) {
				FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"unexpected queue data type" );
			}
			processIncomingPacket(const_cast<TransferDataBuffer *>(const_queue_data));
		}
	}

	virtual void stop() {
			// TODO @@@ do something
	}

};

}
}

#endif /* SERVERRECEVIERBASE_H_ */

