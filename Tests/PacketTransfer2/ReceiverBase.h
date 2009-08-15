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

class PacketServer;
class ReceiverBase : public ThreadWorker {
private:
	PacketSerializer packet_serializer;
	const PacketHandlerFactory &packet_handler_factory;
	PacketServer &packet_server;

public:
	ReceiverBase(PacketHandlerFactory &phf, PacketServer &packet_server);
	virtual void loop();
	virtual void stop();
};

class ReceiverManager: public ThreadManager {
private:
	int thread_number;
	PacketServer &packet_server;
	PacketHandlerFactory packet_handler_factory;

public:
	ReceiverManager(int thread_number, PacketServer &packet_server);
	virtual void registerHandler(PacketHeader::PACKET_ID_TYPE packet_id, const PacketHandlerBase *handler);
	virtual void init();
};

}
}

#endif /* SERVERRECEVIERBASE_H_ */

