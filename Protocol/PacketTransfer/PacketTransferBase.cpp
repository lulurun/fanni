/*
 * PacketTransfer.cpp
 *
 *  Created on: Aug 18, 2009
 *      Author: lulu
 */

#include <list>
#include "PacketTransferBase.h"

namespace Fanni {

// ACK, RESEND management
static const int ACK_TIME_OUT = 250; // 0.5 sec
static const int RESEND_TIME_OUT = 500; // 3 sec
static const int ALIVE_TIME_OUT = 30000; // 30 sec

class OnTimerElapsedHandler_CheckACK: public OnTimerElapsedHandler {
	PacketTransferBase *transfer_peer_ptr;
public:
	OnTimerElapsedHandler_CheckACK(PacketTransferBase *transfer_peer) :
		transfer_peer_ptr(transfer_peer) {
	}
	virtual void operator()() const {
		this->transfer_peer_ptr->checkACK();
	}
};

class OnTimerElapsedHandler_CheckResend: public OnTimerElapsedHandler {
	PacketTransferBase *transfer_peer_ptr;
public:
	OnTimerElapsedHandler_CheckResend(PacketTransferBase *transfer_peer) :
		transfer_peer_ptr(transfer_peer) {
	}
	virtual void operator()() const {
		this->transfer_peer_ptr->checkRESEND();
	}
};

class OnTimerElapsedHandler_CheckAlive: public OnTimerElapsedHandler {
	PacketTransferBase *transfer_peer_ptr;
public:
	OnTimerElapsedHandler_CheckAlive(PacketTransferBase *transfer_peer) :
		transfer_peer_ptr(transfer_peer) {
	}
	virtual void operator()() const {
		this->transfer_peer_ptr->checkALIVE();
	}
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
	if (this->udp_server_thread) delete this->udp_server_thread;
	if (this->udp_server) delete this->udp_server;
	if (this->_udp_server_on_recv) delete this->_udp_server_on_recv;
	if (this->receiver_manager) delete this->receiver_manager;
	if (this->sender_manager) delete this->sender_manager;
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it =
			this->client_connection_map.begin(); it
			!= this->client_connection_map.end(); it++) {
		delete it->second;
	}
}

void PacketTransferBase::init(const PacketFactory *packet_factory, const PacketHandlerFactory *packet_handler_factory) {
	TRACE_LOG("enter");
	this->receiver_manager = new ReceiverManager(this->thread_number, this, packet_factory, packet_handler_factory);
	this->sender_manager = new SenderManager(this->thread_number, this, packet_factory, *this->udp_server);
	{ // start UDP server thread
		this->_udp_server_on_recv = new OnRecvHandler(this->receiver_manager);
		this->udp_server->setOnRecvHandler(this->_udp_server_on_recv);
		this->udp_server_thread = new ThreadTemplate<Event_UDP> (this->udp_server);
	}
	{ // init timers
		OnTimerElapsedHandler_CheckACK *check_ack_handler = new OnTimerElapsedHandler_CheckACK(this);
		this->check_ACK_timer_thread = new PeriodicTask(ACK_TIME_OUT, check_ack_handler);

		OnTimerElapsedHandler_CheckResend *check_resend_handler = new OnTimerElapsedHandler_CheckResend(this);
		this->check_RESEND_timer_thread = new PeriodicTask(RESEND_TIME_OUT, check_resend_handler);

		OnTimerElapsedHandler_CheckAlive *check_alive_handler = new OnTimerElapsedHandler_CheckAlive(this);
		this->check_ALIVE_timer_thread = new PeriodicTask(ALIVE_TIME_OUT, check_alive_handler);
	}
	TRACE_LOG("exit");
}

void PacketTransferBase::start() {
	TRACE_LOG("enter");
	this->receiver_manager->init();
	this->sender_manager->init();
	this->udp_server_thread->kick();

	this->check_ACK_timer_thread->kick(ThreadBase::THREAD_PRIORITY_HIGHT);
	this->check_RESEND_timer_thread->kick();
	this->check_ALIVE_timer_thread->kick();
	TRACE_LOG("exit");
}

void PacketTransferBase::join() {
	// TODO @@@ join join ...
	this->udp_server_thread->join();
}

void PacketTransferBase::stop() {
	this->check_ACK_timer_thread->stop();
	this->check_RESEND_timer_thread->stop();
	this->check_ALIVE_timer_thread->stop();

	this->udp_server_thread->stop();

	::sleep(2);
	//this->receiver_manager->stop();
	//this->sender_manager->stop();
}

void PacketTransferBase::sendPacket(PacketBase *packet, const EndPoint *ep) {
	if (!packet->header.isResent()) {
		packet->setSequence(this->seq_gen.next());
	}
	TransferDataPacket *data = new TransferDataPacket(packet, ep);
	this->sender_manager->deliverTask(data);
}

// ================
// PacketTransfer Management
ClientConnectionBase* PacketTransferBase::addConnection(uint32_t circuit_code,
		const EndPoint *ep) {
	DEBUG_LOG("add connection: " << ep->getAddrStr() << ":" << ep->getPort());
	ClientConnectionBase *client_connection = this->createClientConnection(
			circuit_code, ep);
	DataControlLock l;
	l.lock(&this->client_connection_map_lock);
	// TODO @@@ check if already exists
	this->client_connection_map[ep->getIPv4HashKey()] = client_connection;
	return client_connection;
}

ClientConnectionBase *PacketTransferBase::getConnection(const EndPoint *ep) {
	DataControlLock l;
	l.lock(&this->client_connection_map_lock);
	return this->getConnection_nolock(ep);
}

ClientConnectionBase *PacketTransferBase::getConnection_nolock(
		const EndPoint *ep) {
	uint64_t ep_key = ep->getIPv4HashKey();
	CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.find(
			ep_key);
	if (it == this->client_connection_map.end()) {
		// not found
		return NULL;
	} else {
		return it->second;
	}
}

void PacketTransferBase::removeConnection(const EndPoint *ep) {
	DataControlLock l;
	l.lock(&this->client_connection_map_lock);
	this->removeConnection_nolock(ep);
}

void PacketTransferBase::removeConnection_nolock(const EndPoint *ep) {
	DEBUG_LOG("remove connection: " << ep->getAddrStr() << ":" << ep->getPort());
	ClientConnectionBase *client_connection = this->getConnection(ep);
	if (client_connection != NULL) {
		this->client_connection_map.erase(ep->getIPv4HashKey());
		delete client_connection;
	}
}

void PacketTransferBase::checkACK() {
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it =
			this->client_connection_map.begin(); it
			!= this->client_connection_map.end(); it++) {
		it->second->checkACK();
	}
}

void PacketTransferBase::checkRESEND() {
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it =
			this->client_connection_map.begin(); it
			!= this->client_connection_map.end(); it++) {
		it->second->checkRESEND();
	}
}

void PacketTransferBase::checkALIVE() {
	DataControlLock l;
	l.lock(&this->client_connection_map_lock);
	if (this->client_connection_map.empty()) return;
	list<const EndPoint *> remove_connection_list;
	for (CLIENT_CONNECTION_MAP_TYPE::iterator it = this->client_connection_map.begin();
			it != this->client_connection_map.end(); it++) {
		if (it->second->checkALIVE()) {
			remove_connection_list.push_back(&(it->second->getEndPoint()));
		}
	}
	if (remove_connection_list.size() > 0) {
		INFO_LOG("remove " << remove_connection_list.size() << " client connection");
		for (list<const EndPoint *>::iterator it = remove_connection_list.begin(); it
				!= remove_connection_list.end(); it++) {
			this->removeConnection_nolock(*it);
		}
	}
}

void PacketTransferBase::processIncomingPacket(const PacketBase *packet, const EndPoint *ep) {
	if (this->skipProcessIncomingPacket(packet->header.getPacketID())) {
		return;
	}
	ClientConnectionBase *client_connection = this->getConnection(ep);
	if (client_connection) {
		client_connection->processIncomingPacket(packet);
	} else {
		WARN_LOG("unknown packet from ADDR: " << ep->getAddrStr() << " PORT: " << ep->getPort());
	}
}

void PacketTransferBase::processOutgoingPacket(const PacketBase *packet, const EndPoint *ep) {
	ClientConnectionBase *client_connection = this->getConnection(ep);
	if (client_connection) {
		client_connection->processOutgoingPacket(packet);
	} else {
		WARN_LOG("unknown packet to ADDR: " << ep->getAddrStr() << " PORT: " << ep->getPort());
	}
}

