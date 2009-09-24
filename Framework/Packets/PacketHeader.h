#ifndef PACKETHEADER_H_
#define PACKETHEADER_H_

#include "fanni/PacketBuffer.h"
#include "PacketBaseTypes.h"

namespace Fanni {

class PacketHeader : public PacketSerializable {

public:
	typedef uint32_t PACKET_ID_TYPE;

	enum Flag {
		FLAG_UNKNOWN		= 0x00,
		FLAG_APPENDED_ACKS	= 0x10,
		FLAG_RESENT			= 0x20,
		FLAG_RELIABLE		= 0x40,
		FLAG_ZEROCODED		= 0x80,
	};

	enum Frequency {
		FREQ_UNKNOWN = 1,
		FREQ_FIXED = 0xFFFFFF,
		FREQ_LOW = 0xFFFF,
		FREQ_MEDIUM = 0xFF,
		FREQ_HIGH = 0x0,
	};

	enum HeaderSize {
		SIZE_UNKNOWN = -1,
		SIZE_LOW_HEADER_ = 10,
		SIZE_MEDIUM_HEADER = 8,
		SIZE_HIGH_HEADER = 7,
	};

public:
	SerializableU8 flag;
	SerializableU32 sequence;
	SerializableU8 undef; // TODO: @@@ seems to be nothing

	PACKET_ID_TYPE id;
	Frequency freq;

public:
	PacketHeader();
	virtual ~PacketHeader();

	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);

	bool isAppendedAcks() const;
	bool isResent() const;
	bool isReliable() const;
	bool isZeroCoded() const;

	void setAppendedAcks(bool val);
	void setResent(bool val);
	void setReliable(bool val);
	void setZeroCoded(bool val);

	uint32_t getSequenceNumber() const;
	PACKET_ID_TYPE getPacketID() const;
	Frequency getFrequence() const;

	void setSequenceNumber(uint32_t seq);
	void setPacketID(PACKET_ID_TYPE packet_id);
	void setFrequence(Frequency freq);

};


}

#endif /* PACKETHEADER_H_ */
