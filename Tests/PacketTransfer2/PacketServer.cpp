/*
 * PacketServer.cpp
 *
 *  Created on: Aug 15, 2009
 *      Author: lulu
 */

#include "fanni/ThreadTemplate.h"

#include "ReceiverBase.h"
#include "PacketServer.h"
#include "ProtocolPacketHandlers.h"

namespace Fanni {
namespace Tests {

class PacketServer_OnRecvHandler : public Fanni::Network::UDP_OnRecvHandlerBase {
private:
	PacketSerializer packet_serializer;
	ReceiverManager &recevier_manager;

public:
	PacketServer_OnRecvHandler(ReceiverManager &recevier_manager) : recevier_manager(recevier_manager) {};

	virtual void operator() (PacketBuffer *buffer, const EndPoint *ep) {
		TransferDataBuffer *recv_data = new TransferDataBuffer(buffer, ep);
		this->recevier_manager.deliverTask(recv_data);
	}
};

class UDPServer_ThreadHandler : public ThreadHandlerBase {
private:
	Fanni::Network::Event_UDP &peer;
public:
	UDPServer_ThreadHandler(Fanni::Network::Event_UDP &peer) : peer(peer) {}
	virtual void setArg(void *arg) {}
	virtual void operator()() {
		this->peer.start();
	}
};

typedef ThreadTemplate<UDPServer_ThreadHandler> UDPServer_Thread;

}
}

using namespace std;
using namespace Fanni;
using namespace Fanni::Tests;
using namespace Fanni::Network;

// ==========
// PacketSender
void PacketSender::loop() {
	while (1) {
		const ThreadTask *task = this->queue->pop();
		const TransferDataPacket *const_queue_data = dynamic_cast<const TransferDataPacket *> (task);
		if (!const_queue_data) {
			FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG,"unexpected queue data type" );
		}
		std::auto_ptr<const TransferDataPacket> auto_queue_data(const_queue_data);

		int len = 0;
		const unsigned char *resp_buf = this->packet_serializer.serialize(const_queue_data->data, &len);
		this->udp_server.send(resp_buf, len, *const_queue_data->ep);
	}
}

// ==========
// PacketServer
PacketServer::PacketServer(const std::string &addr, int port, int thread_number) {
	this->udp_server = new Event_UDP(addr, port);
	this->thread_number = thread_number;
}

PacketServer::~PacketServer() {
	delete this->receiver_manager;
	delete this->udp_server;
}

void PacketServer::init() {
	{ // init packet senders
		for (int i = 0; i < this->thread_number; i++) {
			PacketSender *worker = new PacketSender(*this->udp_server);
			this->addWorker(worker);
			worker->kick();
		}
	}
	{ // init receiver_manager
		this->receiver_manager = new ReceiverManager(this->thread_number, *this);
		this->receiver_manager->registerHandler(StartPingCheck_ID, new StartPingCheckPacketHandler());
		this->receiver_manager->init();
	}
	{ // start UDP server thread
		this->udp_server->setOnRecvHandler(new PacketServer_OnRecvHandler(*this->receiver_manager));
		UDPServer_ThreadHandler thread_handler(*udp_server);
		UDPServer_Thread thread(thread_handler);
		thread.kick();
		thread.join();
	}
}

typedef std::tr1::unordered_map<uint32_t, const TransferDataPacket*> RESEND_PACKET_LIST_TYPE;
static RESEND_PACKET_LIST_TYPE ResendPacketList;
static Mutex ResendPacketList_lock;

typedef std::tr1::unordered_map<uint32_t, const EndPoint*> ACK_PACKET_LIST_TYPE;
static ACK_PACKET_LIST_TYPE AckPacketList;
static Mutex AckPacketList_lock;

void PacketServer::processIncomingPacket(PacketBase *packet, const EndPoint *ep) {
	if (packet->header.isReliable()) {
		S_MUTEX_LOCK l;
		l.lock(&AckPacketList_lock);
		AckPacketList[packet->header.getSequenceNumber()] = new EndPoint(*ep);
	}
	if (packet->header.isAppendedAcks()) {
		S_MUTEX_LOCK l;
		l.lock(&ResendPacketList_lock);
		PacketBase::ACK_LIST_TYPE::const_iterator it = packet->appended_acks.begin();
		for (; it != packet->appended_acks.end(); it++) {
			ResendPacketList.erase(*it);
		}
	}
}

void PacketServer::processOutgoingPacket(PacketBase *packet, const EndPoint *ep) {
	if (packet->header.isReliable()) {
		S_MUTEX_LOCK l;
		l.lock(&ResendPacketList_lock);
		TransferDataPacket *transfer_data = new TransferDataPacket(
				PacketFactory::GetInstance()->createPacketCopy(packet->header.getPacketID(), packet),
				new EndPoint(*ep));
		ResendPacketList[packet->header.getSequenceNumber()] = transfer_data;
	}
}


