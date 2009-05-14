/*
 * UDPPacketSender.h
 *
 *  Created on: Apr 17, 2009
 *      Author: lulu
 */

#ifndef UDPSENDER_H_
#define UDPSENDER_H_

#include "fanni/Logger.h"
#include "Threads/ThreadManager.h"
#include "UDPPacketData.h"
#include "Packets/PacketSerializer.h"
#include "Network/FanniSock.h"

namespace Fanni {

class UDPPacketSender {
public:
	UDPPacketSender();
	virtual ~UDPPacketSender();
};

class UDPSenderThreadWorker : public ThreadWorker {
private:
	Fanni::Network::SOCKET server_socket;
	PacketSerializer packet_serializer;
public:
	UDPSenderThreadWorker(Fanni::Network::SOCKET socket) :server_socket(socket) { }
	~UDPSenderThreadWorker() { }

	virtual void stop() {}

	virtual void loop() {
		while(1) {
			TRACE_LOG("enter");
			try {
				// get data
				const ThreadTask *task = this->queue->pop();
				const  UDPPacket *queue_data = dynamic_cast<const  UDPPacket*>(task);
				if (queue_data == NULL) {
					FATAL_LOG("unexpected queue data type: " << typeid(queue_data).name());
					FatalException::throw_exception(EXP_TEST, EXP_PRE_MSG, "unexpected queue data type");
				}
				// TODO: GOOD ? avoid coping data !!!
				UDPPacket *data = const_cast<UDPPacket *>(queue_data);
				// serialize packet -> send to ep
				if (data->packet == NULL) {
					ERROR_LOG("got a null packet, skip");
					continue;
				}
				int buffer_size = 0;
				const unsigned char *buffer = this->packet_serializer.serialize(data->packet, &buffer_size);
				delete queue_data; // @@@ delete here
				Fanni::Network::FanniSock::SendPacket(this->server_socket, buffer_size, buffer, data->ep->getSockAddr());
			} catch (WarnException &e) {
				WARN_LOG("WARN Exception: " << e.get_func() << " at L" << e.get_line() << e.get_msg());
			} catch (ErrorException &e) {
				ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << e.get_msg());
			}
			TRACE_LOG("exit");
		}
	}
};

}

#endif /* UDPPACKETSENDER_H_ */
