/*
 * TransferData.h
 *
 *  Created on: Aug 8, 2009
 *      Author: lulu
 */

#ifndef TRANSFERDATA_H_
#define TRANSFERDATA_H_

#include "fanni/PacketBuffer.h"
#include "fanni/EndPoint.h"
#include "Threads/ThreadTask.h"
#include "Packets/PacketBase.h"

namespace Fanni {
namespace Tests {

class TransferDataBuffer : public ThreadTask {
public:
	PacketBuffer *data;
	const EndPoint *ep;

	TransferDataBuffer(PacketBuffer *data, const EndPoint *ep) : data(data), ep(ep) {};
};

class TransferDataPacket : public ThreadTask {
public:
	PacketBase *data;
	const EndPoint *ep;

	TransferDataPacket(PacketBase *data, const EndPoint *ep) : data(data), ep(ep) {};
};

}
}

#endif /* TRANSFERDATA_H_ */
