#include "Poco/Thread.h"
#include "Poco/NObserver.h"
#include "fanni/Logger.h"
#include "fanni/LLUDP/UDPServerBase.h"

using namespace Fanni;

UDPServerBase::UDPServerBase(const EndPoint &server_ep) {	
	this->socket.bind(server_ep, true);
	this->reactor.addEventHandler(this->socket, Poco::NObserver<UDPServerBase,
		Poco::Net::ReadableNotification>(*this, &UDPServerBase::onReadable));
	this->reactor.addEventHandler(this->socket, Poco::NObserver<UDPServerBase,
		Poco::Net::ShutdownNotification>(*this, &UDPServerBase::onShutdown));
	this->reactor_thread.start(this->reactor); // TODO @@@ do not start automatically
	INFO_LOG("LLUDP", "UDPServer started");
}

UDPServerBase::~UDPServerBase() {
	this->reactor.stop();
	this->reactor_thread.join();
	INFO_LOG("LLUDP", "UDPServer stopped");
}

void UDPServerBase::onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& pNf) {
	PacketBuffer buffer = PacketBufferPool::CreatePacketBuffer();
	EndPoint ep;
	int recv_len = this->socket.receiveFrom(buffer->getBuffer(), PACKET_BUF_LEN, ep);
	if (recv_len == -1) {
		ERROR_LOG("LLUDP", "recvfrom() returned -1");
		return;
	} else if (recv_len == 0) {
		ERROR_LOG("LLUDP", "Connection Close");
		return;
	}
	INFO_LOG("LLUDP", "UDP data received");
	buffer->setLength(recv_len);
	this->processIncomingData(buffer, ep);
}

void UDPServerBase::onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf) {
	INFO_LOG("LLUDP", "shutdown udp server");
}

