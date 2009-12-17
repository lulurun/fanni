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

void ConnectionBase::onDataReceived(const void* pSender, PacketBufferPtr &pBuf) {
	PacketBasePtr pPacket = this->packet_serializer.deserialize(pBuf);
	this->last_received.update();
	if (this->ack_mgr.processIncomingPacket(pPacket)) {
		try {
			const ConnectionPacketHandlerBase &handler =
				this->connection_handler_factory.getHandler(pPacket->header.getPacketID());
			handler(this, pPacket);
		} catch (Poco::NotFoundException &ex) {
			ERROR_LOG("Exception: " << pPacket->header.getPacketID() << " " << ex.message());
		}
	}
}

void ConnectionBase::sendPacket(PacketBasePtr &pPacket) {
	this->ack_mgr.processOutgoingPacket(pPacket);
	PacketBufferPtr pBuf = this->packet_serializer.serialize(pPacket);
	this->udp.sendData(pBuf, this->ep);
}

bool ConnectionBase::checkALIVE() {
	return !this->last_received.isElapsed(CONNECTION_TIMEOUT);
}

void ConnectionBase::close() {}

