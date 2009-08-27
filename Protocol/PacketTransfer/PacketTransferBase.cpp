/*
 * PacketTransfer.cpp
 *
 *  Created on: Aug 18, 2009
 *      Author: lulu
 */

#include "fanni/ThreadTemplate.h"

#include "PacketTransferBase.h"

namespace Fanni {

class PacketTransferBase_OnRecvHandler : public Fanni::Network::UDP_OnRecvHandlerBase {
private:
	ReceiverManager *recevier_manager;

public:
	PacketTransferBase_OnRecvHandler(ReceiverManager *recevier_manager) :
		recevier_manager(recevier_manager) {}
	virtual void operator()(PacketBuffer *buffer, const EndPoint *ep) {
		TransferDataBuffer *recv_data = new TransferDataBuffer(buffer, ep);
		this->recevier_manager->deliverTask(recv_data);
	}
};

// ACK, RESEND management
static const int ACK_TIME_OUT = 4000; // 4 seconds
static const int RESEND_TIME_OUT = 15000; // 15 seconds

class OnTimerElapsedHandler_CheckACK: public OnTimerElapsedHandler {
	PacketTransferBase *peer;
public:
	OnTimerElapsedHandler_CheckACK(PacketTransferBase *peer) : peer(peer) {}
	virtual void operator()() const { this->peer->checkACK(); }
};

class OnTimerElapsedHandler_CheckResend: public OnTimerElapsedHandler {
	PacketTransferBase *peer;
public:
	OnTimerElapsedHandler_CheckResend(PacketTransferBase *peer) : peer(peer) {}
	virtual void operator()() const { this->peer->checkRESEND(); }
};

}

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;

// ==========
// PacketTransferBase
PacketTransferBase::PacketTransferBase(const std::string &addr, int port, int thread_number) {
	this->udp_server = new Event_UDP(addr, port);
	this->thread_number = thread_number;
}

PacketTransferBase::~PacketTransferBase() {
	delete this->receiver_manager;
	delete this->udp_server;
	for(CLIENT_CONNECTION_MAP_TYPE::iterator it=this->client_connection_map.begin(); it!=this->client_connection_map.end(); it++) {
		delete it->second;
	}
}

void PacketTransferBase::init() {
	TRACE_LOG("enter");
	this->receiver_manager = new ReceiverManager(this->thread_number, this);
	this->sender_manager = new SenderManager(this->thread_number, *this->udp_server, this);
	{ // start UDP server thread
		this->udp_server->setOnRecvHandler(new PacketTransferBase_OnRecvHandler(this->receiver_manager));
		this->udp_thread = new SimpleThreadTemplate<Event_UDP>(*this->udp_server);
	}
	{ // init timers
		OnTimerElapsedHandler_CheckACK *check_ack_handler = new OnTimerElapsedHandler_CheckACK(this);
		PeriodicTask *check_ack_timer = new PeriodicTask(ACK_TIME_OUT, check_ack_handler);
		this->check_ACK_timer_thread = new PeriodicTaskThread(check_ack_timer);

		OnTimerElapsedHandler_CheckResend *check_resend_handler = new OnTimerElapsedHandler_CheckResend(this);
		PeriodicTask *check_resend_timer = new PeriodicTask(RESEND_TIME_OUT, check_resend_handler);
		this->check_RESEND_timer_thread = new PeriodicTaskThread(check_resend_timer);
	}
	TRACE_LOG("exit");
}

void PacketTransferBase::start() {
	TRACE_LOG("enter");
	this->receiver_manager->init();
	this->sender_manager->init();
	this->udp_thread->kick();

	this->check_ACK_timer_thread->kick();
	this->check_RESEND_timer_thread->kick();
	TRACE_LOG("exit");
}

void PacketTransferBase::join() {
	// TODO @@@ join join ...
	this->udp_thread->join();
}

void  PacketTransferBase::sendPacket(PacketBase *packet, const EndPoint *ep) {
	TransferDataPacket *data = new TransferDataPacket(packet, ep);
	this->sender_manager->deliverTask(data);
}

// ================
// PacketTransfer Management
void PacketTransferBase::addConnection(uint32_t circuit_code, const EndPoint *ep) {
	DEBUG_LOG("add connection: " << ep->getAddrStr() << ":" << ep->getPort());
	ClientConnectionBase *client_connection = this->createClientConnection(circuit_code, ep);
	S_MUTEX_LOCK l;
	l.lock(&this->client_connection_map_lock);
	client_connection_map[ep->getIPv4HashKey()] = client_connection;
}

ClientConnectionBase *PacketTransferBase::getConnection(const EndPoint *ep) {
	uint64_t ep_key = ep->getIPv4HashKey();
	S_MUTEX_LOCK l;
	l.lock(&this->client_connection_map_lock);
	CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.find(ep_key);
	if (it == this->client_connection_map.end()) {
		// not found
		return NULL;
	} else {
		return it->second;
	}
}

void PacketTransferBase::removeConnection(const EndPoint *ep) {
	DEBUG_LOG("remove connection: " << ep->getAddrStr() << ":" << ep->getPort());
	S_MUTEX_LOCK l;
	l.lock(&this->client_connection_map_lock);
	ClientConnectionBase *client_connection = this->getConnection(ep);
	if (client_connection != NULL) {
		this->client_connection_map.erase(ep->getIPv4HashKey());
		delete client_connection;
	}
}

void PacketTransferBase::checkACK() {
	TRACE_LOG("enter");
	DEBUG_LOG("checking ACK for " << this->client_connection_map.size() << " connections");
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.begin();
		it != this->client_connection_map.end(); it++) {
		it->second->checkACK();
	}
	TRACE_LOG("exit");
}

void PacketTransferBase::checkRESEND() {
	TRACE_LOG("enter");
	DEBUG_LOG("checking RESEND for " << this->client_connection_map.size() << " connections");
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.begin();
		it != this->client_connection_map.end(); it++) {
		it->second->checkRESEND();
	}
	TRACE_LOG("exit");
}

void PacketTransferBase::processIncomingPacket(const PacketBase *packet, const EndPoint *ep) {
	TRACE_LOG("enter");
	if (this->ignoreInProcessIncomingPacket(packet->header.getPacketID())) {
		TRACE_LOG("exit 1");
		return;
	}
	ClientConnectionBase *client_connection = this->getConnection(ep);
	if (client_connection) {
		client_connection->processIncomingPacket(packet);
	} else {
		WARN_LOG("unknown packet from ADDR: " << ep->getAddrStr() << " PORT: " << ep->getPort());
	}
	TRACE_LOG("exit 0");
}

void PacketTransferBase::processOutgoingPacket(const PacketBase *packet, const EndPoint *ep) {
	TRACE_LOG("enter");
	ClientConnectionBase *client_connection = this->getConnection(ep);
	if (client_connection) {
		client_connection->processOutgoingPacket(packet);
		TRACE_LOG("exit 0");
	} else {
		WARN_LOG("unknown packet from ADDR: " << ep->getAddrStr() << " PORT: " << ep->getPort());
		TRACE_LOG("exit 1");
	}
}


