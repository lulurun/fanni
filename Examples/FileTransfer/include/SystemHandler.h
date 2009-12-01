/*
 * SystemHandler.h
 *
 *  Created on: Aug 9, 2009
 *      Author: lulu
 */

#ifndef SYSTEMHANDLER_H_
#define SYSTEMHANDLER_H_

#include <cassert>
#include <memory>
#include "fanni/EndPoint.h"
#include "fanni/UUID.h"
#include "fanni/Logger.h"
#include "fanni/FTPackets/FTPackets.h"
#include "fanni/LLUDP/SystemPacketHandler.h"
#include "Connection.h"
#include "TransferNode.h"

namespace Fanni {
namespace FileTransfer {

class OpenConnectionPacketHandler : public SystemPacketHandlerBase {
public:
	virtual void operator()(LLUDPBase &udp, const PacketBasePtr &packet_base, const EndPoint &ep) const {
		TRACE_LOG("enter");
		ConnectionBasePtr pConnBase = udp.addConnection(packet_base, ep);
		ServerConnection *sConn = dynamic_cast<ServerConnection *>(pConnBase.get());
		assert(sConn);
		// send reply
		OpenConnectionReplyPacket *reply_packet = new OpenConnectionReplyPacket();
		PacketBasePtr pPacket(reply_packet);
		reply_packet->OpenConnectionReply.Code = sConn->getCircuitCode();
		sConn->sendPacket(pPacket);
		TRACE_LOG("exit");
	};
};

class OpenConnectionReplyPacketHandler : public SystemPacketHandlerBase {
public:
	virtual void operator()(LLUDPBase &udp, const PacketBasePtr &packet_base, const EndPoint &ep) const {
		TRACE_LOG("enter");
		ConnectionBasePtr pConnBase = udp.addConnection(packet_base, ep);
		ClientConnection *cConn = dynamic_cast<ClientConnection *>(pConnBase.get());
		assert(cConn);
		//cConn->OnOpenConnectionReply(();
		TRACE_LOG("exit");
	};
};

}
}

#endif /* SYSTEMHANDLER_H_ */
