#include "Poco/Exception.h"
#include "fanni/LLUDP/ConnectionPacketHandler.h"

using namespace Fanni;

ConnectionPacketHandlerFactory::ConnectionPacketHandlerFactory() {
}

ConnectionPacketHandlerFactory::~ConnectionPacketHandlerFactory() {
	for(PACKET_HANDLER_MAP::iterator it=this->handler_map.begin(); it!=this->handler_map.end(); it++) {
		delete it->second;
	}
}

void ConnectionPacketHandlerFactory::registerHandler(PacketHeader::PACKET_ID_TYPE packet_id, const ConnectionPacketHandlerBase *handler) {
	// TODO @@@ unsafe
	PACKET_HANDLER_MAP::iterator it = this->handler_map.find(packet_id);
	if (it == this->handler_map.end()) {
		this->handler_map[packet_id] = handler;
	} else {
		throw Poco::ExistsException("ConnectionPacketHandlerFactory: handler already registered");
	}
}

const ConnectionPacketHandlerBase &ConnectionPacketHandlerFactory::getHandler(PacketHeader::PACKET_ID_TYPE packet_id) const {
	// TODO @@@ unsafe
	PACKET_HANDLER_MAP::const_iterator it = this->handler_map.find(packet_id);
	if (it != this->handler_map.end()) {
		return *it->second;
	} else {
		throw Poco::NotFoundException("ConnectionPacketHandlerFactory: handler not found");
	}
}

