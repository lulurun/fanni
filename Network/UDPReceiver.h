/*
 * UDPReceiver.h
 *
 *  Created on: May 12, 2009
 *      Author: lulu
 */

#ifndef UDPRECEIVER_H_
#define UDPRECEIVER_H_

#include "fanni/EndPoint.h"
#include "fanni/PacketBuffer.h"
// TODO @@@ ...

namespace Fanni {
namespace Network {

class UDPReceiver {
public:
	UDPReceiver();
	virtual ~UDPReceiver();

	void asyncRecvFrom(int fd, PacketBuffer &buffer, EndPoint &ep);
};

}
}

#endif /* UDPRECEIVER_H_ */
