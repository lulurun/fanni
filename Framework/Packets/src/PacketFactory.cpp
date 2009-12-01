#include "fanni/Logger.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketFactory.h"

using namespace std;
using namespace Fanni;

PacketFactory::PacketFactory() {}
PacketFactory::~PacketFactory() {
	// @@@ need not to delete
}

PacketBasePtr PacketFactory::createPacket(PacketHeader::PACKET_ID_TYPE packet_id) const {
    PacketBase *ret = NULL;
    PACKET_MAP::ConstIterator it = this->PacketList.find(packet_id);
    if(it != this->PacketList.end()){
        ret = it->second->clone();
    }
    return ret;
}

void PacketFactory::registerPacket(PacketHeader::PACKET_ID_TYPE id, const PacketBasePtr &packet) {
	TRACE_LOG("enter");
	PacketBasePtr p(packet->clone());
	this->PacketList[id] = p;
	TRACE_LOG("exit");
}

void PacketFactory::merge(PacketFactory &factory) {
	for (PACKET_MAP::ConstIterator it = factory.PacketList.begin(); it!=factory.PacketList.end(); it++) {
		PacketHeader::PACKET_ID_TYPE packet_id = it->second->header.getPacketID();
		PACKET_MAP::ConstIterator this_it = this->PacketList.find(packet_id);
		if(this_it == this->PacketList.end()){
			this->registerPacket(packet_id, it->second->clone());
		}
	}
}

