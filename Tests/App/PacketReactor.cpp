/*
 * PacketReactor.cpp
 *
 *  Created on: Apr 13, 2009
 *      Author: lulu
 */

#include "fanni/Logger.h"
#include "PacketReactor.h"
#include "UDPPacketData.h"

using namespace Fanni;

PacketReactor::PacketReactor() {
	// TODO Auto-generated constructor stub

}

PacketReactor::~PacketReactor() {
	// TODO Auto-generated destructor stub
}

void PacketReactor::init() {
	this->handler_factory = new PacketHandlerFactory();
}

void PacketReactor::dispatch(const PacketBase &packet, const EndPoint &ep) {
	TRACE_LOG("enter");
	const PacketHandlerBase *handler = this->handler_factory->getPacketHandler(packet.header.id);
	handler->operator()(packet, ep);
	TRACE_LOG("exit");
}

// PacketReactorThreadWorker
void PacketReactorThreadWorker::loop() {
	while(1) {
		TRACE_LOG("enter");
		try {
			// get data
			const ThreadTask *task = this->queue->pop();
			const  UDPBuffer *queue_data = dynamic_cast<const  UDPBuffer*>(task);
			assert(queue_data);
			// TODO @@@ GOOD (const_cast)?
			UDPBuffer *data = const_cast<UDPBuffer *>(queue_data);
			// get packet
			PacketBase *packet = this->packet_serializer.deserialize(*data->data);
			delete queue_data; // @@@ delete here
			DEBUG_LOG("incoming packet " <<
					"FROM: " << data->ep->getAddrStr() << ":" << data->ep->getPort() << "\n" <<
					" [id]: " << hex << packet->header.getPacketID() << dec <<
					" [seq] " << packet->header.getSequenceNumber() <<
					" [reliable] " << packet->header.isReliable() <<
					" [resent] " << packet->header.isResent() <<
					" [ack] " << packet->header.isAppendedAcks()
					);
			// add to ack queue
			// TODO @@@ unnecessary lock/unlock
			this->ack_mgr->checkInPacket(*packet);

			// call handler
			this->packet_reactor.dispatch(*packet, *data->ep);
		} catch (WarnException &e) {
			WARN_LOG("Exception: " << e.get_func() << " at L" << e.get_line() << std::endl << e.get_msg());
		} catch (ErrorException &e) {
			ERROR_LOG("Exception: " << e.get_func() << " at L" << e.get_line() << std::endl << e.get_msg());
		}
		TRACE_LOG("exit");
	}
}
