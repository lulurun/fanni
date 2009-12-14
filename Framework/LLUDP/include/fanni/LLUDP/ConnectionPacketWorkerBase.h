/*
 * ConnectionPacketWorkerBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_CONNECTIONPACKETWORKERBASE_H_
#define FANNI_CONNECTIONPACKETWORKERBASE_H_

#include "fanni/EndPoint.h"
#include "fanni/TaskQueue.h"
#include "fanni/ThreadWorker.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/Packets/PacketSerializer.h"
#include "fanni/LLUDP/LLUDP_def.h"

namespace Fanni {

class Fanni_LLUDP_API ConnectionPacketWorker : public Worker {
public:
	ConnectionPacketWorker(const EndPoint &ep, const PacketSerializer &packet_serializer);
	virtual ~ConnectionPacketWorker();

protected:
	const PacketSerializer &packet_serializer;
	void doTask(TaskPtr &task);
};

}

#endif /* FANNI_CONNECTIONPACKETWORKERBASE_H_ */
