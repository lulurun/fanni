/*
 * PacketHandlers.h
 *
 *  Created on: Mar 10, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERS_H_
#define PACKETHANDLERS_H_

#include "PacketHandlerBase.h"

namespace Fanni {

class PacketAckHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase& packet, const EndPoint &ep) const {
		this->PacketHandlerBase::operator()(packet, ep);
	};
};

class NullHandler : public PacketHandlerBase {
public:
	virtual void operator()(const PacketBase& packet, const EndPoint &ep) const {
		this->PacketHandlerBase::operator()(packet, ep);
	};
};

}

#endif /* PACKETHANDLERS_H_ */
