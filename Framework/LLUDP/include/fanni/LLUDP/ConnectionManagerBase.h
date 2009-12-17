/*
 * ConnectionManagerBase.h
 *
 *  Created on: May 6, 2009
 *      Author: lulu
 */

#ifndef FANNI_CONNECTIONMANAGERBASE_H_
#define FANNI_CONNECTIONMANAGERBASE_H_

#include <map>
#include "Poco/Timer.h"
#include "Poco/Delegate.h"
#include "Poco/BasicEvent.h"
#include "fanni/EndPoint.h"
#include "fanni/PacketBuffer.h"
#include "fanni/LockableTemplate.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/LLUDP/ConnectionBase.h"
#include "fanni/LLUDP/LLUDP_def.h"

namespace Fanni {

class Fanni_LLUDP_API ConnectionManagerBase {
protected:
	typedef lockable<std::map<std::string, ConnectionBasePtr>> CONNECTION_MAP;
	mutable CONNECTION_MAP conn_map;

	Poco::Timer *check_ALIVE_timer;
	void onCheckALIVETimer(Poco::Timer &timer);

	bool isConnected_unsafe(const EndPoint &ep) const;
	ConnectionBasePtr &getConnection_unsafe(const EndPoint &ep) const;

	virtual ConnectionBasePtr createConnection(const PacketBasePtr &packet, const EndPoint &ep) = 0;

	Poco::BasicEvent<const EndPoint> ConnectionAdded;
	Poco::BasicEvent<const EndPoint> ConnectionRemoved;

public:
	ConnectionManagerBase();
	virtual ~ConnectionManagerBase();
	virtual ConnectionBasePtr addConnection(const PacketBasePtr &packet, const EndPoint &ep);
	virtual void closeConnection(const EndPoint &ep);
	ConnectionBasePtr &getConnection(const EndPoint &ep) const;
};

}

#endif /* FANNI_CONNECTIONMANAGERBASE_H_ */

