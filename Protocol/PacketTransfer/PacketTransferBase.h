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
#include "ClientConnectionBase.h"

namespace Fanni {

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

	typedef std::tr1::unordered_map<EndPoint::IPV4_HASH_KEY_TYPE, ClientConnectionBase *> CLIENT_CONNECTION_MAP_TYPE;
	CLIENT_CONNECTION_MAP_TYPE client_connection_map;
	Mutex client_connection_map_lock;

public:
	PacketTransferBase(const std::string &addr, int port, int thread_number);
	virtual ~PacketTransferBase();

	virtual void init();
	virtual void start();
	virtual void join();
	virtual void sendPacket(PacketBase *packet, const EndPoint *ep);

	// Client Connection management
	virtual void addConnection(uint32_t circuit_code, const EndPoint *ep);
	virtual void removeConnection(const EndPoint *ep);
	virtual ClientConnectionBase *getConnection(const EndPoint *ep);

	virtual ClientConnectionBase *createClientConnection(uint32_t circuit_code, const EndPoint *ep) = 0;
	virtual bool ignoreInProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id) = 0;

	// Reliable Packet Transfer
	virtual void processIncomingPacket(const PacketBase *packet, const EndPoint *ep);
	virtual void processOutgoingPacket(const PacketBase *packet, const EndPoint *ep);

	virtual void checkACK();
	virtual void checkRESEND();

};

}

#endif /* PACKETTRANSFER_H_ */
