/*
 * UDPPacketData.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef UDPPACKETDATA_H_
#define UDPPACKETDATA_H_

#include "Threads/ThreadTask.h"
#include "fanni/PacketBuffer.h"
#include "fanni/EndPoint.h"
#include <cassert>

namespace Fanni {

class UDPBuffer : public ThreadTask {
public:
	PacketBuffer *data;
	const EndPoint *ep;
	UDPBuffer(PacketBuffer *data, const EndPoint *ep) :
		data(data), ep(ep)
	{
		assert(this->data && this->ep);
	}
};

class UDPPacket : public ThreadTask {
public:
	PacketBase *packet;
	const EndPoint *ep;
	UDPPacket(PacketBase *packet, const EndPoint *ep) :
		packet(packet), ep(ep)
	{
		assert(this->packet && this->ep);
	}
};

}

#endif /* UDPPACKETDATA_H_ */
