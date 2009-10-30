/*
 * PacketHandlerFactory.h
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERFACTORY_H_
#define PACKETHANDLERFACTORY_H_

#include "fanni/EndPoint.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketHeader.h"
#include "fanni/rUDP/rUDP_def.h"

namespace Fanni {

class TransferNode;
class ConnectionBase;
class ClientPacketHandlerBase {
public:
	virtual void operator()(const PacketBasePtr &packet_base, ConnectionBase *conn_base) const = 0;
};

class SystemPacketHandlerBase {
public:
	virtual void operator()(const PacketBasePtr &packet_base, const EndPoint &ep, TransferNode &node) const = 0;
};

class Fanni_RUDP_API PacketHandlerFactory {
private:
	typedef Poco::HashMap<PacketHeader::PACKET_ID_TYPE, const ClientPacketHandlerBase*> CLIENT_HANDLER_MAP;
	CLIENT_HANDLER_MAP ClientHandlerList;
	typedef Poco::HashMap<PacketHeader::PACKET_ID_TYPE, const SystemPacketHandlerBase*> SYSTEM_HANDLER_MAP;
	SYSTEM_HANDLER_MAP SystemHandlerList;

public:
	PacketHandlerFactory();
	virtual ~PacketHandlerFactory();

	void init();
	const ClientPacketHandlerBase &getClientHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
	const SystemPacketHandlerBase &getSystemHandler(PacketHeader::PACKET_ID_TYPE packet_id) const;
	void registerClientHandler(PacketHeader::PACKET_ID_TYPE packet_id, const ClientPacketHandlerBase *packet_handler);
	void registerSyetemHandler(PacketHeader::PACKET_ID_TYPE packet_id, const SystemPacketHandlerBase *packet_handler);
};

}

#endif /* PACKETHANDLERFACTORY_H_ */
