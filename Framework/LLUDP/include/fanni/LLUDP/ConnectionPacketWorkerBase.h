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

class Fanni_LLUDP_API ConnectionPacketWorkerBase : public Worker {
public:
	ConnectionPacketWorkerBase(const EndPoint &ep, const PacketSerializer &packet_serializer);
	virtual ~ConnectionPacketWorkerBase();
	const EndPoint &getEndPoint() const;

protected:
	EndPoint ep;
	const PacketSerializer &packet_serializer;

	void doTask(TaskPtr &task);
	virtual void dispatch(const PacketBasePtr &packet) = 0;
};

}

#endif /* FANNI_CONNECTIONPACKETWORKERBASE_H_ */
