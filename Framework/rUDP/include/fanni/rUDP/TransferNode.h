/*
 * TransferNode.h
 *
 *  Created on: Oct 18, 2009
 *      Author: lulu
 */

#ifndef TRANSFERNODE_H_
#define TRANSFERNODE_H_

#include <string>
#include "Poco/HashMap.h"
#include "Poco/Thread.h"
#include "Poco/Timer.h"
#include "Poco/Mutex.h"
#include "Poco/AtomicCounter.h"
#include "Poco/Net/SocketReactor.h"

#include "fanni/LockableTemplate.h"
#include "fanni/Packets/PacketHeader.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/rUDP/rUDP_def.h"
#include "fanni/rUDP/Receiver.h"
#include "fanni/rUDP/Sender.h"
#include "fanni/rUDP/ConnectionBase.h"
#include "fanni/rUDP/UDPReceiveHandler.h"

namespace Fanni {

class Fanni_RUDP_API TransferNode {
protected:
	PacketFactory &packet_factory;
	PacketHandlerFactory packet_handler_factory;

	// UDP server
	Poco::Net::DatagramSocket socket;
	Poco::Net::SocketReactor reactor;
	Poco::Thread udp_server_thread;
	UDPServerHandler *udp_server_handler;
	ReceiverManager *receiver_manager;
	SenderManager *sender_manager;
	// Timers
	Poco::Timer *check_ACK_timer;
	Poco::Timer *check_RESEND_timer;
	Poco::Timer *check_ALIVE_timer;
	void onCheckACKTimer(Poco::Timer &timer);
	void onCheckRESENDTimer(Poco::Timer &timer);
	void onCheckALIVETimer(Poco::Timer &timer);

	Poco::AtomicCounter ac;
	bool isRunning;

public:
	TransferNode(PacketFactory &packet_factory, const std::string &addr, uint16_t port, int thread_number);
	virtual ~TransferNode();

	virtual void start();
	virtual void stop();
	virtual void sendPacket(PacketBasePtr &packet, const EndPoint &ep);

	// Reliable Packet Transfer
	void processIncomingPacket(const PacketBasePtr &packet, const EndPoint &ep);
	void processOutgoingPacket(const PacketBasePtr &packet, const EndPoint &ep);

	// Connection Management
private:
	typedef Poco::HashMap<std::string, ConnectionBase *> __CONNECTION_MAP;
public:
	typedef lockable<__CONNECTION_MAP> CONNECTION_MAP;
private:
	CONNECTION_MAP connection_map;

	void removeConnection_nolock(const EndPoint &ep);
	ConnectionBase *getConnection_nolock(const EndPoint &ep);

protected:
	void addConnection(ConnectionBase *connection);

public:
	virtual bool isSystemPacket(const PacketBasePtr &packet) const = 0;
	ConnectionBase *getConnection(const EndPoint &ep);
	virtual ConnectionBase &createConnection(const PacketBasePtr &packet, const EndPoint &ep) = 0;
	void removeConnection(const EndPoint &ep);

public:
	const PacketHandlerFactory &getPacketHandlerFactory() const;
};

}

#endif /* TRANSFERNODE_H_ */
