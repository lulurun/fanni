/*
 * UDPReceiveHandler.h
 *
 *  Created on: Oct 24, 2009
 *      Author: lulu
 */

#ifndef UDPRECEIVEHANDLER_H_
#define UDPRECEIVEHANDLER_H_

#include <memory>
#include "Poco/NObserver.h"
#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketNotification.h"
#include "fanni/Logger.h"

#include "Receiver.h"

namespace Fanni {

class UDPServerHandler {
	friend class TransferNode;
private:
	enum {
		BUFFER_SIZE = 1500,
	};
	Poco::Net::DatagramSocket &socket;
	ReceiverManager &receiver_manager;

	UDPServerHandler(Poco::Net::DatagramSocket &socket, ReceiverManager &receiver_manager) :
		socket(socket), receiver_manager(receiver_manager) {
	}
public:
	~UDPServerHandler() {
	}

	void onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& pNf) {
		std::auto_ptr<PacketBuffer> buffer(new PacketBuffer());
		Poco::Net::SocketAddress sender;
		int recv_len = this->socket.receiveFrom(buffer->getBuffer(), PACKET_BUF_LEN, sender);
		if (recv_len == -1) {
			ERROR_LOG("rUDP", "recvfrom() returned -1");
			return;
		} else if (recv_len == 0) {
			ERROR_LOG("rUDP", "Connection Close");
			return;
		}
		buffer->setLength(recv_len);
		this->receiver_manager.deliverTask(new ReceiverTask(buffer.release(), sender));
	}

	void onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf) {
		INFO_LOG("rUDP", "shutdown udp server");
	}

};

}

#endif /* UDPRECEIVEHANDLER_H_ */
