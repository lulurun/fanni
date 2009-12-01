#include "fanni/EndPoint.h"
#include "fanni/PacketBuffer.h"
#include "fanni/LLUDP/UDPReceiveHandler.h"
#include "fanni/LLUDP/UDPBase.h"

using namespace Fanni;

UDPReceiveHandler::UDPReceiveHandler(Poco::Net::DatagramSocket &socket, UDPBase &udp) :
	socket(socket), udp(udp) {}

UDPReceiveHandler::~UDPReceiveHandler() {}

void UDPReceiveHandler::onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& pNf) {
	PacketBuffer buffer(new __PacketBuffer());
	EndPoint ep;
	int recv_len = this->socket.receiveFrom(buffer->getBuffer(), PACKET_BUF_LEN, ep);
	if (recv_len == -1) {
		ERROR_LOG("LLUDP", "recvfrom() returned -1");
		return;
	} else if (recv_len == 0) {
		ERROR_LOG("LLUDP", "Connection Close");
		return;
	}
	buffer->setLength(recv_len);
	this->udp.receiveData(buffer, ep);
}

void UDPReceiveHandler::onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf) {
	INFO_LOG("LLUDP", "shutdown udp server");
}


