#include <cassert>
#include "fanni/Logger.h"
#include "fanni/LLUDP/UDPData.h"
#include "fanni/LLUDP/SystemPacketWorkerBase.h"

using namespace Fanni;

SystemPacketWorkerBase::SystemPacketWorkerBase() {
	this->packet_serializer = new PacketSerializer(this->packet_factory);
	INFO_LOG("LLUDP", "SystemPacketWorker started");
}

SystemPacketWorkerBase::~SystemPacketWorkerBase() {
	delete this->packet_serializer;
	INFO_LOG("LLUDP", "SystemPacketWorker stopped");
}

void SystemPacketWorkerBase::doTask(TaskPtr &pTask) {
	CloseConnectionTask *ccTask = dynamic_cast<CloseConnectionTask *>(pTask.get());
	if (ccTask) {
		this->dispatch(pTask, ccTask->ep); // TODO @@@ review
	} else {
		IncomingData *incoming_data = dynamic_cast<IncomingData *>(pTask.get());
		assert(incoming_data);
		PacketBasePtr packet = this->packet_serializer->deserialize(incoming_data->data);
		this->dispatch(packet, incoming_data->ep);
	}
}

