#include <cassert>
#include "fanni/Logger.h"
#include "fanni/LLUDP/UDPData.h"
#include "fanni/LLUDP/ConnectionPacketWorkerBase.h"

using namespace Fanni;

ConnectionPacketWorkerBase::ConnectionPacketWorkerBase(const EndPoint &ep, const PacketSerializer &packet_serializer) :
	ep(ep), packet_serializer(packet_serializer) {
	DEBUG_LOG("ConnectionPacketWorker started");
}

ConnectionPacketWorkerBase::~ConnectionPacketWorkerBase() {
	DEBUG_LOG("ConnectionPacketWorker stopped");
}

void ConnectionPacketWorkerBase::doTask(TaskPtr &task) {
	IncomingData *incoming_data = dynamic_cast<IncomingData *>(task.get());
	assert(incoming_data);
	assert(incoming_data->ep.toString() == this->getEndPoint().toString()); // TODO @@@ ???
	PacketBasePtr packet = this->packet_serializer.deserialize(incoming_data->data);
	this->dispatch(packet);
}

const EndPoint &ConnectionPacketWorkerBase::getEndPoint() const {
	return this->ep;
}

