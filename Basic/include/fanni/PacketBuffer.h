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
#include "fanni/SingletonTemplate.h"

namespace Fanni {

#ifndef PACKET_BUF_LEN
#define PACKET_BUF_LEN 1500
#endif

typedef FixedLengthBuffer<PACKET_BUF_LEN> PacketBuffer;
typedef Poco::SharedPtr<PacketBuffer> PacketBufferPtr;

// TODO @@@ finish me
class PacketBufferPool {
public:
};

typedef Serializable<PacketBuffer> PacketSerializable;

}

#endif /* PACKETBUFFER_H_ */
