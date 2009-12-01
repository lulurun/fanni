#include "Poco/Exception.h"
#include "fanni/LLUDP/SystemPacketHandler.h"

using namespace Fanni;

SystemPacketHandlerFactory::SystemPacketHandlerFactory() {
}

SystemPacketHandlerFactory::~SystemPacketHandlerFactory() {
	for(PACKET_HANDLER_MAP::iterator it=this->handler_map.begin(); it!=this->handler_map.end(); it++) {
		delete it->second;
	}
}

void SystemPacketHandlerFactory::registerHandler(PacketHeader::PACKET_ID_TYPE packet_id, const SystemPacketHandlerBase *handler) {
	// TODO @@@ unsafe
	PACKET_HANDLER_MAP::iterator it = this->handler_map.find(packet_id);
	if (it == this->handler_map.end()) {
		this->handler_map[packet_id] = handler;
	} else {
		throw Poco::ExistsException();
	}
}

const SystemPacketHandlerBase &SystemPacketHandlerFactory::getHandler(PacketHeader::PACKET_ID_TYPE packet_id) const {
	// TODO @@@ unsafe
	PACKET_HANDLER_MAP::const_iterator it = this->handler_map.find(packet_id);
	if (it != this->handler_map.end()) {
		return *it->second;
	} else {
		throw Poco::NotFoundException();
	}
}


