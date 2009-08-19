/*
 * ServerRecevierBase.h
 *
 *  Created on: Aug 8, 2009
 *      Author: lulu
 */

#ifndef SERVERRECEVIERBASE_H_
#define SERVERRECEVIERBASE_H_

// framework
#include "Threads/ThreadWorker.h"
#include "Threads/ThreadManager.h"
#include "Packets/PacketHeader.h"
#include "Packets/PacketSerializer.h"
// app
#include "TransferData.h"
#include "PacketHandlerFactory.h"

namespace Fanni {
namespace Tests {

class PacketTransferBase;
class ReceiverBase : public ThreadWorker {
private:
	PacketSerializer packet_serializer;
	// reference of ReceiverManager::packet_handler_factory
	const PacketHandlerFactory &packet_handler_factory;
	PacketTransferBase *transfer_peer;

public:
	ReceiverBase(PacketHandlerFactory &phf, PacketTransferBase *transfer_peer);
	virtual void loop();
	virtual void stop();
};

class ReceiverManager: public ThreadManager {
private:
	int thread_number;
	PacketTransferBase *transfer_peer;
	PacketHandlerFactory packet_handler_factory;

public:
	ReceiverManager(int thread_number, PacketTransferBase *transfer_peer);
	virtual void registerHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *handler);
	virtual void init();
};

}
}

#endif /* SERVERRECEVIERBASE_H_ */

