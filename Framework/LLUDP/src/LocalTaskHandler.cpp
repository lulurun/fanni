#include "Poco/Exception.h"
#include "fanni/LLUDP/LocalTaskHandler.h"
#include "fanni/LLUDP/LLUDPBase.h"

using namespace Fanni;

// CloseConnectionTaskHandler
void CloseConnectionTaskHandler::operator ()(LLUDPBase &udp, const LocalTaskBasePtr &pLocTask) const {
	const CloseConnectionTask *ccTask = dynamic_cast<const CloseConnectionTask *>(pLocTask.get());
	assert(ccTask);
	udp.closeConnection(ccTask->ep);
}

// LocalTaskHandlerFactory
LocalTaskHandlerFactory::LocalTaskHandlerFactory() {
}

LocalTaskHandlerFactory::~LocalTaskHandlerFactory() {
	for(_HANDLER_MAP::iterator it=this->handler_map.begin(); it!=this->handler_map.end(); it++) {
		delete it->second;
	}
}

void LocalTaskHandlerFactory::registerHandler(const std::string &task_name, const LocalTaskHandlerBase *handler) {
	// TODO @@@ unsafe
	_HANDLER_MAP::iterator it = this->handler_map.find(task_name);
	if (it == this->handler_map.end()) {
		this->handler_map[task_name] = handler;
	} else {
		throw Poco::ExistsException("LocalTaskHandlerFactory: handler already registered");
	}
}

const LocalTaskHandlerBase &LocalTaskHandlerFactory::getHandler(const std::string &task_name) const {
	// TODO @@@ unsafe
	_HANDLER_MAP::const_iterator it = this->handler_map.find(task_name);
	if (it != this->handler_map.end()) {
		return *it->second;
	} else {
		throw Poco::NotFoundException("LocalTaskHandlerFactory: handler not found");
	}
}


