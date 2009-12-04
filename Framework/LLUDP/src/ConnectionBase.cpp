#include "fanni/LLUDP/ConnectionBase.h"
#include "fanni/LLUDP/LLUDPBase.h"

using namespace Fanni;

ConnectionBase::ConnectionBase(const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp) :
	ConnectionPacketWorkerBase(ep, packet_serializer),
	connection_handler_factory(udp.getConnectionHandlerFactory()), udp(udp) {
	this->ack_mgr = new AckManager(*this); // @@@ start ack manager
}

ConnectionBase::~ConnectionBase() {
	delete this->ack_mgr;
	DEBUG_LOG("ConnectionBase destoryed");
}

void ConnectionBase::dispatch(const PacketBasePtr &packet) {
	this->ack_mgr->processIncomingPacket(packet);
	const ConnectionPacketHandlerBase &handler = this->connection_handler_factory.getHandler(packet->header.getPacketID());
	handler(this, packet);
}

void ConnectionBase::sendPacket(PacketBasePtr &packet) {
	this->ack_mgr->processOutgoingPacket(packet);
	PacketBuffer buffer = this->packet_serializer.serialize(packet);
	this->udp.sendData(buffer, this->ep);
}

bool ConnectionBase::checkALIVE() {
	return true; // TODO @@@
}

LLUDPBase &ConnectionBase::getUDPBase() const {
	return this->udp;
}

