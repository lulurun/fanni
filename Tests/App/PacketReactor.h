/*
 * PacketReactor.h
 *
 *  Created on: Apr 13, 2009
 *      Author: lulu
 */

#ifndef PACKETREACTOR_H_
#define PACKETREACTOR_H_

#include <cassert>
#include <iostream> // TODO @@@ delete me
#include <memory>
#include "fanni/PacketBuffer.h"
#include "Packets/PacketHandlerFactory.h"
#include "Packets/PacketBase.h"
#include "Packets/PacketSerializer.h"
#include "Threads/ThreadManager.h"
#include "UDPPacketData.h"
#include "AckManager.h"
#include "UDPSender.h"

namespace Fanni {

class PacketReactor {
private:
	PacketHandlerFactory *handler_factory;

public:
	void init();
	void dispatch(const PacketBase &packet, const EndPoint &ep);

	PacketReactor();
	virtual ~PacketReactor();
};

class PacketReactorThreadWorker : public ThreadWorker {
// friend class PacketReactorThreadManager;
// TODO @@@ all member functions should be private, someone said we can do it until 2010private:
	PacketSerializer packet_serializer;
	PacketReactor packet_reactor;
	UDPSenderThreadWorker *sender;
	AckManager *ack_mgr;

public:
	PacketReactorThreadWorker() {}
	virtual ~PacketReactorThreadWorker() {}

	void init(UDPSenderThreadWorker *sender) {
		this->packet_reactor.init( /* sender */ );
		this->ack_mgr = new AckManager(sender);
	}

	virtual void stop() {
		// TODO @@@ do something
	}
	virtual void loop();
};

class PacketReactorThreadManager: public ThreadManager {
private:
	int init_worker_number;
	Fanni::Network::SOCKET server_socket;
public:
	PacketReactorThreadManager(int init_worker_number, Fanni::Network::SOCKET socket) :
		init_worker_number(init_worker_number), server_socket(socket){
	}
	virtual ~PacketReactorThreadManager() {
		WORKER_MAP_TYPE::iterator it;
		for (it = this->worker_list.begin(); it != this->worker_list.end(); it++) {
			ThreadWorker *worker = it->second;
			// TODO @@@ worker->stop();
			delete worker;
		}
	}
	virtual void init() {
		for (int i = 0; i < this->init_worker_number; i++) {
			PacketReactorThreadWorker *w = new PacketReactorThreadWorker();
			UDPSenderThreadWorker *sender = new UDPSenderThreadWorker(this->server_socket);
			w->init(sender);
			this->addWorker(w);
			w->kick();
		}
	}
};


}

#endif /* PACKETREACTOR_H_ */
