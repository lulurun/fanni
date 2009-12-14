#include "fanni/LLUDP/ConnectionBase.h"
#include "fanni/LLUDP/LLUDPBase.h"

using namespace Fanni;

ConnectionBase::ConnectionBase(const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp) :
	packet_serializer(packet_serializer), connection_handler_factory(udp.getConnectionHandlerFactory()),
	ep(ep), udp(udp), ack_mgr(*this) {
}

ConnectionBase::~ConnectionBase() {
	this->close();
	DEBUG_LOG("ConnectionBase destoryed");
}

const EndPoint &ConnectionBase::getEndPoint() const {
	return this->ep;
}

LLUDPBase &ConnectionBase::getUDPBase() const {
	return this->udp;
}

void ConnectionBase::doTask(TaskPtr &task) {
	IncomingData *incoming_data = dynamic_cast<IncomingData *>(task.get());
	assert(incoming_data);
	assert(incoming_data->ep.toString() == this->getEndPoint().toString()); // TODO @@@ ???
	PacketBasePtr packet = this->packet_serializer.deserialize(incoming_data->data);

	this->last_received.update();
	if (this->ack_mgr.processIncomingPacket(packet)) {
		try {
			const ConnectionPacketHandlerBase &handler = this->connection_handler_factory.getHandler(packet->header.getPacketID());
			handler(this, packet);
		} catch (Poco::NotFoundException &ex) {
			ERROR_LOG("Exception: " << packet->header.getPacketID() << " " << ex.message());
		}
	}
}

void ConnectionBase::sendPacket(PacketBasePtr &packet) {
	this->ack_mgr.processOutgoingPacket(packet);
	PacketBuffer buffer = this->packet_serializer.serialize(packet);
	this->udp.sendData(buffer, this->ep);
}

bool ConnectionBase::checkALIVE() {
	return !this->last_received.isElapsed(CONNECTION_TIMEOUT);
}

void ConnectionBase::close() {
	this->stop();
}

