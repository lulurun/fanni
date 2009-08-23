/*
 * PacketTransfer.h
 *
 *  Created on: Aug 18, 2009
 *      Author: lulu
 */

#ifndef PACKETTRANSFERBASE_H_
#define PACKETTRANSFERBASE_H_

#include "fanni/ThreadTemplate.h"
#include "fanni/Timer.h"
#include "Network/Event_UDP.h"
#include "Threads/ThreadWorker.h"
#include "Threads/ThreadManager.h"

#include "SenderBase.h"
#include "ReceiverBase.h"
#include "ClientConnection.h"

namespace Fanni {
namespace Tests {

class PacketTransferBase {
private:
	// Threads handled by "this"
	SimpleThreadTemplate<Fanni::Network::Event_UDP> *udp_thread;
	PeriodicTaskThread *check_ACK_timer_thread;
	PeriodicTaskThread *check_RESEND_timer_thread;
	ReceiverManager *receiver_manager;
	SenderManager *sender_manager;

protected:
	Fanni::Network::Event_UDP *udp_server;
	int thread_number;

	ReceiverManager *getReceiverManager() const { return this->receiver_manager; }
	SenderManager *getSenderManager() const { return this->sender_manager; }


public:
	PacketTransferBase(const std::string &addr, int port, int thread_number);
	virtual ~PacketTransferBase();

	virtual void init();
	virtual void start();
	virtual void sendPacket(PacketBase *packet, const EndPoint *ep);

	// Reliable Packet Transfer
	virtual void processIncomingPacket(const PacketBase *packet, const EndPoint *ep) = 0;
	virtual void processOutgoingPacket(const PacketBase *packet, const EndPoint *ep) = 0;

	virtual void checkACK() = 0;
	virtual void checkRESEND() = 0;

	virtual void addConnection(uint32_t circuit_code, const EndPoint *ep) = 0;
	virtual void removeConnection(const EndPoint *ep) = 0;
	virtual ClientConnection *getConnection(const EndPoint *ep) = 0;
};

}
}

#endif /* PACKETTRANSFER_H_ */
