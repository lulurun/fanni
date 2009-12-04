#include <cassert>
#include "fanni/Logger.h"
#include "fanni/LLUDP/UDPData.h"
#include "fanni/LLUDP/SystemPacketWorkerBase.h"

using namespace Fanni;

SystemPacketWorkerBase::SystemPacketWorkerBase() {
	this->packet_serializer = new PacketSerializer(this->packet_factory);
	DEBUG_LOG("SystemPacketWorker started");
}

SystemPacketWorkerBase::~SystemPacketWorkerBase() {
	delete this->packet_serializer;
	DEBUG_LOG("SystemPacketWorker stopped");
}

void SystemPacketWorkerBase::doTask(TaskPtr &pTask) {
	try {
		IncomingData *incoming_data = dynamic_cast<IncomingData *>(pTask.get());
		if (incoming_data) {
			PacketBasePtr packet = this->packet_serializer->deserialize(incoming_data->data);
			this->dispatch(packet, incoming_data->ep);
		} else {
			LocalTaskBasePtr pLocTask = pTask.cast<LocalTaskBase>();
			assert(pLocTask.get());
			this->dispatch(pLocTask);
		}
	}catch (Poco::NotFoundException &ex) {
		WARN_LOG("can not find packet handler: " << ex.message());
	}
}

