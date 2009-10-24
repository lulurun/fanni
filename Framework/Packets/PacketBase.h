#ifndef PACKETBASE_H_
#define PACKETBASE_H_

#include "fanni/PacketBuffer.h"
#include "fanni/Serializable.h"
#include "PacketHeader.h"
#include <vector>

namespace Fanni {

class PacketBase : public PacketSerializable {
public:
	typedef std::vector<uint32_t> ACK_LIST_TYPE;
	ACK_LIST_TYPE appended_acks;

protected:
	virtual void serialize(PacketBuffer &buffer) const = 0;
	virtual void deserialize(PacketBuffer &buffer) = 0;

public:
	PacketHeader header; // TODO @@@ should be protected

	PacketBase();
	virtual ~PacketBase();

	void setFlag(PacketHeader::Flag flag);
	void setSequence(uint32_t seq);
	void setID(uint32_t id);
	void appendAck(uint32_t ack_seq);

	const ACK_LIST_TYPE &getAppendedAcks() const;

	virtual void serializePacket(PacketBuffer &buffer) const;
	virtual void deserializePacket(PacketBuffer &buffer);

	virtual PacketBase *clone() const = 0;
	virtual PacketBase *clone(const PacketBase *packet) const = 0;
};

}

#endif /* PACKETBASE_H_ */
