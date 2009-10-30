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
#include "Poco/Net/SocketNotification.h"
#include "fanni/EndPoint.h"
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
		PacketBuffer buffer(new __PacketBuffer());
		EndPoint ep;
		int recv_len = this->socket.receiveFrom(buffer->getBuffer(), PACKET_BUF_LEN, ep);
		if (recv_len == -1) {
			ERROR_LOG("rUDP", "recvfrom() returned -1");
			return;
		} else if (recv_len == 0) {
			ERROR_LOG("rUDP", "Connection Close");
			return;
		}
		buffer->setLength(recv_len);
		// MEMO @@@ the task will be deleted after being processed
		this->receiver_manager.deliverTask(new ReceiverTask(buffer, ep));
	}

	void onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf) {
		INFO_LOG("rUDP", "shutdown udp server");
	}

};

}

#endif /* UDPRECEIVEHANDLER_H_ */
