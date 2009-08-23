/*
 * PacketTransfer.cpp
 *
 *  Created on: Aug 18, 2009
 *      Author: lulu
 */

#include "fanni/ThreadTemplate.h"

#include "PacketTransferBase.h"

namespace Fanni {
namespace Tests {

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
}

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;
using namespace Fanni::Tests;

// ==========
// PacketTransferBase
PacketTransferBase::PacketTransferBase(const std::string &addr, int port, int thread_number) {
	this->udp_server = new Event_UDP(addr, port);
	this->thread_number = thread_number;
}

PacketTransferBase::~PacketTransferBase() {
	delete this->receiver_manager;
	delete this->udp_server;
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

	// TODO @@@ join join ...
	this->udp_thread->join();
	TRACE_LOG("exit");
}

void  PacketTransferBase::sendPacket(PacketBase *packet, const EndPoint *ep) {
	TransferDataPacket *data = new TransferDataPacket(packet, ep);
	this->sender_manager->deliverTask(data);
}

