/*
 * PacketBuffer.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef PACKETBUFFER_H_
#define PACKETBUFFER_H_

#include "Poco/SharedPtr.h"
#include "fanni/FixedLengthBuffer.h"
#include "fanni/Serializable.h"

namespace Fanni {

#ifndef PACKET_BUF_LEN
#define PACKET_BUF_LEN 1500
#endif

typedef FixedLengthBuffer<PACKET_BUF_LEN> __PacketBuffer;
typedef Poco::SharedPtr<__PacketBuffer> PacketBuffer;

typedef Serializable<PacketBuffer> PacketSerializable;

}

#endif /* PACKETBUFFER_H_ */
