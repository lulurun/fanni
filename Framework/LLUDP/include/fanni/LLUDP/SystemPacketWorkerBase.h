/*
 * SystemPacketWorkerBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_SYSTEMPACKETWORKERBASE_H_
#define FANNI_SYSTEMPACKETWORKERBASE_H_

#include "fanni/ThreadWorker.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketSerializer.h"
#include "fanni/TaskQueue.h"
#include "fanni/LLUDP/LLUDP_def.h"

namespace Fanni {

class Fanni_LLUDP_API SystemPacketWorkerBase : public Worker{
public:
	SystemPacketWorkerBase();
	virtual ~SystemPacketWorkerBase();

protected:
	PacketFactory packet_factory;
	PacketSerializer *packet_serializer;

	void doTask(TaskPtr &task);
	virtual void dispatch(/* TODO @@@ const */ PacketBasePtr &packet, const EndPoint &ep) = 0;
	virtual void dispatch(const TaskPtr &task, const EndPoint &ep) = 0;
};

}

#endif /* FANNI_LLUDPBASE_H_ */

