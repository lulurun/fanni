/*
 * TransferNode.cpp
 *
 *  Created on: Oct 18, 2009
 *      Author: lulu
 */

#include <list>

#include "fanni/Logger.h"
#include "fanni/EndPoint.h"
#include "fanni/rUDP/DefaultPacketAckPacket.h"
#include "fanni/rUDP/TransferNode.h"

using namespace std;
using namespace Poco;
using namespace Poco::Net;
using namespace Fanni;

TransferNode::TransferNode(PacketFactory &packet_factory, const std::string &addr, uint16_t port, int thread_number) :
	packet_factory(packet_factory), isRunning(false) {
	DefaultPacketAckPacket packet;
	this->packet_factory.registerPacket(DefaultPacketAckPacket::DefaultPacketAck_ID, packet);
	// init scoket
	EndPoint ep(addr, port);
	this->socket.bind(ep, true);
	// init Receiver, Sender
	this->receiver_manager = new ReceiverManager(thread_number, *this, this->packet_factory, this->packet_handler_factory);
	this->sender_manager = new SenderManager(thread_number, this->socket, *this, this->packet_factory);
	// init UDP server
	this->udp_server_handler = new UDPServerHandler(this->socket, *this->receiver_manager);
	this->reactor.addEventHandler(this->socket, NObserver<UDPServerHandler,
			ReadableNotification> (*this->udp_server_handler, &UDPServerHandler::onReadable));
	this->reactor.addEventHandler(this->socket, NObserver<UDPServerHandler,
			ShutdownNotification> (*this->udp_server_handler, &UDPServerHandler::onShutdown));
	// init timers
	this->check_ACK_timer = new Poco::Timer(0, 1000);
	this->check_RESEND_timer = new Poco::Timer(0, 4000);
	this->check_ALIVE_timer = new Poco::Timer(0, 15000);
}

TransferNode::~TransferNode() {
	delete this->receiver_manager;
	delete this->sender_manager;
	delete this->udp_server_handler;

	delete this->check_ACK_timer;
	delete this->check_RESEND_timer;
	delete this->check_ALIVE_timer;
}

void TransferNode::start() {
	TRACE_LOG("enter");
	// start UDP server
	INFO_LOG("rUDP", "start receiver sender");
	this->receiver_manager->start();
	this->sender_manager->start();
	INFO_LOG("rUDP", "start udp server");
	this->udp_server_thread.start(this->reactor);
	// start timers
	INFO_LOG("rUDP", "start ack resend timers");
	// TODO @@@ use dedicated thread pool
	this->check_ACK_timer->start(Poco::TimerCallback<TransferNode>(*this, &TransferNode::onCheckACKTimer));
	this->check_RESEND_timer->start(Poco::TimerCallback<TransferNode>(*this, &TransferNode::onCheckRESENDTimer));
	this->check_ALIVE_timer->start(Poco::TimerCallback<TransferNode>(*this, &TransferNode::onCheckALIVETimer));

	TRACE_LOG("exit");
}

void TransferNode::stop() {
	// stop timers
	INFO_LOG("rUDP", "stop ack resend timers");
	this->check_ACK_timer->stop();
	this->check_RESEND_timer->stop();
	this->check_ALIVE_timer->stop();
	// stop UDP server
	INFO_LOG("rUDP", "stop udp server");
	this->reactor.stop();
	this->udp_server_thread.join();
	INFO_LOG("rUDP", "stop receiver sender");
	this->receiver_manager->stop();
	this->sender_manager->stop();
}

void TransferNode::sendPacket(PacketBasePtr &packet, const EndPoint &ep) {
	TRACE_LOG("enter");
	if (!packet->header.isResent()) {
		this->ac++;
		packet->setSequence(this->ac.value());
	}
	// MEMO @@@ the task will be deleted after being processed
	this->sender_manager->deliverTask(new SenderTask(packet, ep));
	TRACE_LOG("exit");
}

// PacketTransfer Management
void TransferNode::addConnection(ConnectionBase *conn) {
	INFO_LOG("rUDP", "add connection: " << conn->getEndPoint().toString());
	Poco::FastMutex::ScopedLock l(this->connection_map);
	// TODO @@@ check if already exists
	this->connection_map[conn->getEndPoint().toString()] = conn;
}

ConnectionBase *TransferNode::getConnection(const EndPoint &ep) {
	Poco::FastMutex::ScopedLock l(this->connection_map);
	return this->getConnection_nolock(ep);
}

ConnectionBase *TransferNode::getConnection_nolock(const EndPoint &ep) {
	CONNECTION_MAP::Iterator it = this->connection_map.find(ep.toString());
	if (it == this->connection_map.end()) {
		// not found
		return NULL;
	} else {
		return it->second;
	}
}

void TransferNode::removeConnection(const EndPoint &ep) {
	Poco::FastMutex::ScopedLock l(this->connection_map);
	this->removeConnection_nolock(ep);
}

void TransferNode::removeConnection_nolock(const EndPoint &ep) {
	INFO_LOG("rUDP", "remove connection: " << ep.toString());
	ConnectionBase *conn = this->getConnection_nolock(ep);
	if (conn != NULL) {
		this->connection_map.erase(ep.toString());
		delete conn;
	}
}

void TransferNode::onCheckACKTimer(Poco::Timer &timer) {
	TRACE_LOG("enter");
	for (CONNECTION_MAP::Iterator it = this->connection_map.begin(); it
			!= this->connection_map.end(); it++) {
		it->second->checkACK();
	}
	TRACE_LOG("exit");
}

void TransferNode::onCheckRESENDTimer(Poco::Timer &timer) {
	TRACE_LOG("enter");
	for (CONNECTION_MAP::Iterator it = this->connection_map.begin(); it
			!= this->connection_map.end(); it++) {
		it->second->checkRESEND();
	}
	TRACE_LOG("exit");
}

void TransferNode::onCheckALIVETimer(Poco::Timer &timer) {
	TRACE_LOG("enter");
	Poco::FastMutex::ScopedLock l(this->connection_map);
	if (this->connection_map.empty())
		return;
	list<const EndPoint> remove_connection_list;
	for (CONNECTION_MAP::Iterator it = this->connection_map.begin(); it
			!= this->connection_map.end(); it++) {
		if (it->second->checkALIVE()) {
			remove_connection_list.push_back(it->second->getEndPoint());
		}
	}
	if (remove_connection_list.size() > 0) {
		INFO_LOG("rUDP", "remove " << remove_connection_list.size() << " client connections");
		for (list<const EndPoint>::iterator it = remove_connection_list.begin(); it != remove_connection_list.end(); it++) {
			this->removeConnection_nolock(*it);
		}
	}
	TRACE_LOG("exit");
}

// Reliable Packet Transfer
void TransferNode::processIncomingPacket(const PacketBasePtr &packet, const EndPoint &ep) {
	if (this->isSystemPacket(packet)) {
		const SystemPacketHandlerBase &handler = this->packet_handler_factory.getSystemHandler(packet->header.getPacketID());
		handler(packet, ep, *this);
	} else {
		ConnectionBase *conn = this->getConnection(ep);
		if (conn) {
			conn->processIncomingPacket(packet);
		} else {
			WARN_LOG("rUDP", "unknown packet from: " << ep.toString());
		}
	}
}

void TransferNode::processOutgoingPacket(const PacketBasePtr &packet, const EndPoint &ep) {
	ConnectionBase *conn = this->getConnection(ep);
	if (conn) {
		conn->processOutgoingPacket(packet);
	} else {
		WARN_LOG("rUDP", "unknown packet to: " << ep.toString());
	}
}

const PacketHandlerFactory &TransferNode::getPacketHandlerFactory() const {
	return this->packet_handler_factory;
}

