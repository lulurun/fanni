/*
 * LocalTaskHandler.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_LocalTaskHandler_H_
#define FANNI_LocalTaskHandler_H_

#include <map>
#include <string>
#include "fanni/LLUDP/UDPData.h"
#include "fanni/LLUDP/LLUDP_def.h"

namespace Fanni {

class LLUDPBase;
class Fanni_LLUDP_API LocalTaskHandlerBase {
public:
	virtual void operator()(LLUDPBase &udp, const LocalTaskBasePtr &pLocTask) const = 0;
};

class Fanni_LLUDP_API CloseConnectionTaskHandler : public LocalTaskHandlerBase {
public:
	virtual void operator()(LLUDPBase &udp, const LocalTaskBasePtr &pLocTask) const;
};

class Fanni_LLUDP_API LocalTaskHandlerFactory {
private:
	typedef std::map<std::string, const LocalTaskHandlerBase *> _HANDLER_MAP;
	_HANDLER_MAP handler_map;

public:
	LocalTaskHandlerFactory();
	~LocalTaskHandlerFactory();

	// unsafe methods
	void registerHandler(const std::string &task_name, const LocalTaskHandlerBase *handler);
	const LocalTaskHandlerBase &getHandler(const std::string &task_name) const;
};

}

#endif /* FANNI_LocalTaskHandler_H_ */

