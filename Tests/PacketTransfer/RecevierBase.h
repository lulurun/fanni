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
#include "Packets/PacketHeader.h"
// app
#include "TransferData.h"
#include "PacketTransfer.h"
#include "PacketHandlerFactory.h"

namespace Fanni {
namespace Tests {

class ReceiverBase : public ThreadWorker {
private:
	PacketSerializer packet_serializer;
	const PacketHandlerFactory &packet_handler_factory;
	PacketTransferManager *packet_transfer_manager;

	void processIncomingPacket(PacketBase *packet, const EndPoint *ep) {
		const PacketHandlerBase *packet_handler = this->packet_handler_factory.getPacketHandler(packet->header.getPacketID());
		packet_handler->operator()(packet, ep, this->packet_transfer_manager);
	}

public:
	ReceiverBase(PacketHandlerFactory &phf, PacketTransferManager *ptm = NULL) :
		packet_handler_factory(phf), packet_transfer_manager(ptm) {}

	virtual void loop() {
		while (1) {
			const ThreadTask *task = this->queue->pop();
			const TransferDataBuffer *const_queue_data = dynamic_cast<const TransferDataBuffer *> (task);
			if (!const_queue_data) {
				FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"unexpected queue data type" );
			}

			auto_ptr<const TransferDataBuffer> auto_queue_data(const_queue_data);
			PacketBase *packet = this->packet_serializer.deserialize(*(const_queue_data->data));

			/*
			DEBUG_LOG("incoming packet " <<
					"FROM: " << ep->getAddrStr() << ":" << ep->getPort() << "\n" <<
					" [id]: " << hex << packet_base->header.getPacketID() << dec <<
					" [seq] " << packet_base->header.getSequenceNumber() <<
					" [reliable] " << packet_base->header.isReliable() <<
					" [resent] " << packet_base->header.isResent() <<
					" [ack] " << packet_base->header.isAppendedAcks()
			);
			*/

			processIncomingPacket(packet, const_queue_data->ep);
		}
	}

	virtual void stop() {
			// TODO @@@ do something
	}

};

class ReceiverManager: public ThreadManager {
private:
	int thread_number;
	PacketTransferManager *packet_transfer_manager;

protected:
	PacketHandlerFactory packet_handler_factory;

public:
	ReceiverManager(int thread_number, PacketTransferManager *packet_transfer_manager = NULL) :
		thread_number(thread_number), packet_transfer_manager(packet_transfer_manager) {}

	virtual void registerHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *handler) {
		this->packet_handler_factory.registerPacketHandler(packet_id, handler);
	};

	virtual void init() {
		// TODO @@@ register handlers ?
		// init works
		for (int i = 0; i < this->thread_number; i++) {
			ReceiverBase *worker = new ReceiverBase(this->packet_handler_factory, this->packet_transfer_manager);
			this->addWorker(worker);
			worker->kick();
		}
	}
};

}
}

#endif /* SERVERRECEVIERBASE_H_ */

