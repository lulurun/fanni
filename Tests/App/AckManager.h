/*
 * AckManager.h
 *
 *  Created on: Apr 23, 2009
 *      Author: lulu
 */

#ifndef ACKMANAGER_H_
#define ACKMANAGER_H_

#include <tr1/unordered_map>
#include "Packets/PacketBase.h"
#include "Threads/Mutex.h"
#include "Threads/ThreadManager.h"
#include "Threads/ThreadWorker.h"
#include "UDPSender.h"

namespace Fanni {

class AckManager {
public:
	typedef std::tr1::unordered_map<uint32_t, bool> ACK_MAP_TYPE;
	typedef std::tr1::unordered_map<uint32_t, const PacketBase *> RELIABLE_MAP_TYPE;

private:
	UDPSenderThreadWorker *sender;
public:
	AckManager(UDPSenderThreadWorker *sender) : sender(sender) {}
	virtual ~AckManager() {}
	void checkInPacket(const PacketBase &packet);
	void checkOutPacket(PacketBase &packet);
};

}

#endif /* ACKMANAGER_H_ */
