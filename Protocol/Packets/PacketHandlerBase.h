/*
 * PacketHandlerBase.h
 *
 *  Created on: Mar 9, 2009
 *      Author: lulu
 */

#ifndef PACKETHANDLERBASE_H_
#define PACKETHANDLERBASE_H_

#include "fanni/EndPoint.h"
#include "fanni/Exception.h"
#include "PacketBase.h"

namespace Fanni {

class PacketHandlerBase {
public:
  PacketHandlerBase(){};
  virtual ~PacketHandlerBase(){};
  virtual void operator()(const PacketBase &packet, const EndPoint &ep) const {
		WarnException::throw_exception(EXP_Packet, EXP_PRE_MSG, "Default packet handler called, implement me");
	};
};

}

#endif /* PACKETHANDLERBASE_H_ */
