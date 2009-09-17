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

class TransferDataBuffer : public ThreadTask {
public:
	PacketBuffer *data;
	const EndPoint *ep;

	TransferDataBuffer(PacketBuffer *data, const EndPoint *ep) : data(data), ep(ep) {};
	~TransferDataBuffer() {
		if (this->data) delete this->data;
		if (this->ep) delete this->ep;
	}
};

class TransferDataPacket : public ThreadTask {
public:
	PacketBase *data;
	const EndPoint *ep_ptr;

	TransferDataPacket(PacketBase *data, const EndPoint *ep) : data(data), ep_ptr(ep) {};
	~TransferDataPacket() {
		// TODO @@@ how to solve the "delete" problem more wisely ?
	        if (this->data) delete this->data;
		//if (this->ep) delete this->ep; // TODO @@@ can not delete this, now!!
	}
};

}

#endif /* TRANSFERDATA_H_ */
