#include <cassert>
#include "fanni/Logger.h"
#include "fanni/LLUDP/UDPData.h"
#include "fanni/LLUDP/SystemPacketWorkerBase.h"

using namespace Fanni;

SystemPacketWorkerBase::SystemPacketWorkerBase() : packet_serializer(this->packet_factory) {
	DEBUG_LOG("SystemPacketWorker started");
}

SystemPacketWorkerBase::~SystemPacketWorkerBase() {
	DEBUG_LOG("SystemPacketWorker stopped");
}

void SystemPacketWorkerBase::doTask(TaskPtr &pTask) {
	try {
		SystemPacketData *data = dynamic_cast<SystemPacketData *>(pTask.get());
		if (data) {
			PacketBasePtr pPacket = this->packet_serializer.deserialize(data->pBuf);
			this->dispatch(pPacket, data->ep);
		} else {
			LocalTaskBasePtr pLocTask = pTask.cast<LocalTaskBase>();
			assert(pLocTask.get());
			this->dispatch(pLocTask);
		}
	}catch (Poco::NotFoundException &ex) {
		WARN_LOG("can not find packet handler: " << ex.message());
	}
}

