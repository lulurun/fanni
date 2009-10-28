#include "fanni/Logger.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketFactory.h"

using namespace std;
using namespace Fanni;

PacketFactory::PacketFactory() {}
PacketFactory::~PacketFactory() {
	for (PACKET_MAP_TYPE::ConstIterator it = this->PacketList.begin(); it!=this->PacketList.end(); it++) {
		delete it->second;
	}
}

PacketBase *PacketFactory::createPacket(PacketHeader::PACKET_ID_TYPE packet_id) const {
    PacketBase *ret = NULL;
    PACKET_MAP_TYPE::ConstIterator it = this->PacketList.find(packet_id);
    if(it != this->PacketList.end()){
        ret = it->second->clone();
    }
    return ret;
}

PacketBase *PacketFactory::createPacketCopy(PacketHeader::PACKET_ID_TYPE packet_id, const PacketBase *packet) const {
    PacketBase *ret = NULL;
    PACKET_MAP_TYPE::ConstIterator it = this->PacketList.find(packet_id);
    if(it != this->PacketList.end()){
        ret = it->second->clone(packet);
    }
    return ret;
}

void PacketFactory::registerPacket(PacketHeader::PACKET_ID_TYPE id, const PacketBase &packet) {
	TRACE_LOG("enter");
	this->PacketList[id] = packet.clone();
	TRACE_LOG("exit");
}

