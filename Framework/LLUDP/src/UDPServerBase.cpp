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
	DEBUG_LOG("UDPServer started");
}

UDPServerBase::~UDPServerBase() {
	this->reactor.stop();
	this->reactor_thread.join();
	DEBUG_LOG("UDPServer stopped");
}

void UDPServerBase::onReadable(const Poco::AutoPtr<Poco::Net::ReadableNotification>& pNf) {
	PacketBuffer buffer = PacketBufferPool::CreatePacketBuffer();
	EndPoint ep;
	int recv_len = this->socket.receiveFrom(buffer->getBuffer(), PACKET_BUF_LEN, ep);
	if (recv_len == -1) {
		ERROR_LOG("recvfrom() returned -1");
		return;
	} else if (recv_len == 0) {
		ERROR_LOG("Connection Close");
		return;
	}
	INFO_LOG("UDP data received");
	buffer->setLength(recv_len);
	this->processIncomingData(buffer, ep);
}

void UDPServerBase::onShutdown(const Poco::AutoPtr<Poco::Net::ShutdownNotification>& pNf) {
	INFO_LOG("shutdown udp server");
}

