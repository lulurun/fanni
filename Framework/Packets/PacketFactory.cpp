#include "PacketBase.h"
#include "PacketFactory.h"

using namespace std;
using namespace Fanni;

PacketFactory::PacketFactory() {}
PacketFactory::~PacketFactory() {}

PacketBase *PacketFactory::createPacket(PacketHeader::PACKET_ID_TYPE packet_id) const {
    PacketBase *ret = NULL;
    PACKET_MAP_TYPE::const_iterator it = this->PacketList.find(packet_id);
    if(it != this->PacketList.end()){
        ret = it->second->clone();
    }
    return ret;
}

PacketBase *PacketFactory::createPacketCopy(PacketHeader::PACKET_ID_TYPE packet_id, const PacketBase *packet) const {
    PacketBase *ret = NULL;
    PACKET_MAP_TYPE::const_iterator it = this->PacketList.find(packet_id);
    if(it != this->PacketList.end()){
        ret = it->second->clone(packet);
    }
    return ret;
}
