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
protected:
	  PacketHandlerBase(){};
public:
  virtual ~PacketHandlerBase(){};
  virtual void operator()(const PacketBase &packet, const EndPoint &ep) const = 0;
};

}

#endif /* PACKETHANDLERBASE_H_ */
