/*
 * UDPPacketData.h
 *
 *  Created on: Oct 18, 2009
 *      Author: lulu
 */

#ifndef _FANNI_UDPPACKET_DATA_H_
#define _FANNI_UDPPACKET_DATA_H_

#include <string>
#include "Poco/Timestamp.h"
#include "Fanni/TaskQueue.h"
#include "fanni/EndPoint.h"
#include "fanni/PacketBuffer.h"
#include "fanni/Packets/PacketBase.h"

namespace Fanni {

class UDPPacketData : public TaskBase {
public:
	PacketBufferPtr pBuf;
	EndPoint ep;

	UDPPacketData() : pBuf(new PacketBuffer()) {};
	UDPPacketData(PacketBufferPtr &pBuf, const EndPoint &ep) : pBuf(pBuf), ep(ep) {};
	virtual ~UDPPacketData() {};
};

class LocalTaskBase : public TaskBase {
protected:
	std::string name;
	LocalTaskBase(const std::string &name): name(name) {};
public:
	virtual ~LocalTaskBase() {};
	const std::string &getName() const { return this->name; };
};

typedef Poco::SharedPtr<LocalTaskBase> LocalTaskBasePtr;

class CloseConnectionTask : public LocalTaskBase {
public:
	EndPoint ep;
	CloseConnectionTask(const EndPoint &ep): ep(ep), LocalTaskBase("CloseConnection") {}
	virtual ~CloseConnectionTask() {}
};

}

#endif // _FANNI_UDPPACKET_DATA_H_
