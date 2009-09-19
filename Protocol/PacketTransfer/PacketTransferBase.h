/*
 * PacketTransfer.h
 *
 *  Created on: Aug 18, 2009
 *      Author: lulu
 */

#ifndef PACKETTRANSFERBASE_H_
#define PACKETTRANSFERBASE_H_

#include "Network/Event_UDP.h"
#include "Threads/DataControl.h"
#include "Threads/SeqGenerator.h"
#include "Threads/ThreadWorker.h"
#include "Threads/ThreadManager.h"
#include "Threads/ThreadTemplate.h"
#include "Threads/Timer.h"

#include "SenderBase.h"
#include "ReceiverBase.h"
#include "ClientConnectionBase.h"

namespace Fanni {

class PacketTransferBase {

	class OnRecvHandler: public Fanni::Network::UDP_OnRecvHandlerBase {
	private:
		ReceiverManager *recevier_manager_ptr;

	public:
		OnRecvHandler(ReceiverManager *recevier_manager) :
			recevier_manager_ptr(recevier_manager) {
		}
		virtual void operator()(PacketBuffer *buffer, const EndPoint *ep) {
			TransferDataBuffer *recv_data = new TransferDataBuffer(buffer, ep);
			this->recevier_manager_ptr->deliverTask(recv_data);
		}
	};


private:
	ThreadTemplate<Fanni::Network::Event_UDP> *udp_server_thread;
	ReceiverManager *receiver_manager;
	SenderManager *sender_manager;

	// timer threads
	PeriodicTask *check_ACK_timer_thread;
	PeriodicTask *check_RESEND_timer_thread;
	PeriodicTask *check_ALIVE_timer_thread;

	OnRecvHandler *_udp_server_on_recv;

	SequenceGenerator seq_gen;

protected:
	Fanni::Network::Event_UDP *udp_server;
	int thread_number;

	ReceiverManager *getReceiverManager() const { return this->receiver_manager; }
	SenderManager *getSenderManager() const { return this->sender_manager; }

	typedef std::tr1::unordered_map<EndPoint::IPV4_HASH_KEY_TYPE, ClientConnectionBase *> CLIENT_CONNECTION_MAP_TYPE;
	CLIENT_CONNECTION_MAP_TYPE client_connection_map;
	DataControl client_connection_map_lock;

	virtual void removeConnection_nolock(const EndPoint *ep);
	virtual ClientConnectionBase *getConnection_nolock(const EndPoint *ep);

public:
	PacketTransferBase(const std::string &addr, int port, int thread_number);
	virtual ~PacketTransferBase();

	virtual void init(const PacketFactory *packet_factory, const PacketHandlerFactory *packet_handler_factory);
	virtual void start();
	virtual void join();
	virtual void stop();
	virtual void sendPacket(PacketBase *packet, const EndPoint *ep);

	// Client Connection management
	virtual ClientConnectionBase* addConnection(uint32_t circuit_code, const EndPoint *ep);
	virtual void removeConnection(const EndPoint *ep);
	virtual ClientConnectionBase *getConnection(const EndPoint *ep);

	virtual ClientConnectionBase *createClientConnection(uint32_t circuit_code, const EndPoint *ep) = 0;
	virtual bool skipProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id) = 0;
	virtual bool skipHandlePacket(PacketHeader::PACKET_ID_TYPE packet_id) = 0;

	// Reliable Packet Transfer
	virtual void processIncomingPacket(const PacketBase *packet, const EndPoint *ep);
	virtual void processOutgoingPacket(const PacketBase *packet, const EndPoint *ep);

	virtual void checkACK();
	virtual void checkRESEND();
	virtual void checkALIVE();

};

}

#endif /* PACKETTRANSFER_H_ */
