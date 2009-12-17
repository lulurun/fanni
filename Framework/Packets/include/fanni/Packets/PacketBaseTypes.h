#ifndef SERIALIZABLEBASETYPES_H_
#define SERIALIZABLEBASETYPES_H_

#include <string>
#include <vector>
#include <string.h>
#include "fanni/UUID.h"
#include "fanni/Exception.h"
#include "fanni/PacketBuffer.h"
#include "fanni/Packets/Packets_def.h"

namespace Fanni {

// Multiple Serializables
template<class T, size_t Length>
class Fanni_Packets_API MultipleSerializable : public PacketSerializable {
public:
	// TODO @@@ need better data structure
	std::vector<T> val;
public:
	MultipleSerializable() {}
	MultipleSerializable(const std::vector<T> &val) {
		// @@@ copy
		this->val = val;
	}
	virtual ~MultipleSerializable() {};

	void push(const T &obj) {
		if (this->val.size() <= Length) {
			this->val.push_back(obj);
		} else {
	    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not add more objects");
		}
	}

	const T &operator[](size_t idx) const {
		if (idx >= Length) {
	    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "out of range");
		}
		return this->val[idx];
	}

	virtual void serialize(PacketBuffer &buffer) const {
		if (this->val.size() != Length) {
	    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "not enough blocks for this MultipleSerializable ");
		}
		for(size_t i=0; i<Length; i++) {
			this->val[i].serialize(buffer);
		}
	}
	virtual void deserialize(PacketBuffer &buffer) {
		if (this->val.size() != Length) {
			this->val.resize(Length);
		}
		for(size_t i=0; i<Length; i++) {
			try {
				this->val[i].deserialize(buffer);
			} catch (ErrorException &e){
		    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "deserialize Failed %s", e.get_msg());
			}
		}
	}
};

template<class T>
class Fanni_Packets_API VariableSerializable : public PacketSerializable {
public:
	static const uint16_t MAX_LENGTH = 256;
	std::vector<T> val;

public:
	VariableSerializable() {}
	VariableSerializable(const std::vector<T> &val) {
		this->val = val;
	}
	virtual ~VariableSerializable() {};

	void push(const T &obj) {
		if (this->val.size() <= MAX_LENGTH) {
			this->val.push_back(obj);
		} else {
	    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not add more objects");
		}
	}

	size_t size() const {
		return this->val.size();
	}

	const T &operator[](size_t idx) const {
		if (idx >= this->val.size()) {
	    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "out of range");
		}
		return this->val[idx];
	}

	virtual void serialize(PacketBuffer &buffer) const {
		uint8_t length = static_cast<uint8_t>(this->val.size());
		buffer.putValue<uint8_t>(length);
		for(size_t i=0; i<length; i++) {
			this->val[i].serialize(buffer);
		}
	}
	virtual void deserialize(PacketBuffer &buffer) {
		uint8_t length = buffer.getValue<uint8_t>();
		this->val.resize(length);
		for(size_t i=0; i<length; i++) {
			try {
				this->val[i].deserialize(buffer);
			} catch (ErrorException &e){
				ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "deserialize Failed %s", e.get_msg());
			}
		}
	}
};

// FixedSizeValues
template<class T>
class Fanni_Packets_API SerializableFixedSizeValue : public PacketSerializable {
private:
	T val; // MEMO @@@ 'T' must be built-in type

public:
	SerializableFixedSizeValue() : val(0){ };
	virtual ~SerializableFixedSizeValue() {};
	virtual void serialize(PacketBuffer &buffer) const {
		buffer.putValue<T>(this->val);
	};
	virtual void deserialize(PacketBuffer &buffer) {
		this->val = buffer.getValue<T>();
	};
	SerializableFixedSizeValue<T> &operator=(const T &val) {
		this->val = val;
		return *this;
	}
	/*
	void operator |=(const T &val) {
		this->val |= val;
	}
	void operator &=(const T &val) {
		this->val &= val;
	}
	*/
	T operator |(const T &val) {
		return this->val | val;
	}
	T operator &(const T &val) {
		return this->val & val;
	}
	operator T&() {
		return this->val;
	}
	operator const T&() const {
		return this->val;
	}
};

typedef SerializableFixedSizeValue<double> Fanni_Packets_API SerializableF64;
typedef SerializableFixedSizeValue<float> Fanni_Packets_API SerializableF32;
typedef SerializableFixedSizeValue<uint64_t> Fanni_Packets_API SerializableU64;
typedef SerializableFixedSizeValue<uint32_t> Fanni_Packets_API SerializableU32;
typedef SerializableFixedSizeValue<int32_t> Fanni_Packets_API SerializableS32;
typedef SerializableFixedSizeValue<uint16_t> Fanni_Packets_API SerializableU16;
typedef SerializableFixedSizeValue<int16_t> Fanni_Packets_API SerializableS16;
typedef SerializableFixedSizeValue<uint8_t> Fanni_Packets_API SerializableU8;
typedef SerializableFixedSizeValue<int8_t> Fanni_Packets_API SerializableS8;
typedef SerializableFixedSizeValue<bool> Fanni_Packets_API SerializableBool;
typedef SerializableFixedSizeValue<uint32_t> Fanni_Packets_API SerializableIPADDR;
typedef SerializableFixedSizeValue<uint16_t> Fanni_Packets_API SerializableIPPORT;

template<int Length>
class Fanni_Packets_API SerializableFixed : public PacketSerializable {
public:
	typedef unsigned char BUF_TYPE[Length];
	BUF_TYPE val;
public:
	SerializableFixed() {}
	SerializableFixed &operator=(const BUF_TYPE &val) {
		::memcpy(this->val, val.data(), Length);
		return *this;
	}
	virtual ~SerializableFixed() {};
	virtual void serialize(PacketBuffer &buffer) const {
		buffer.putBuf(this->val, Length);
	}
	virtual void deserialize(PacketBuffer &buffer) {
		buffer.getBuf(this->val, Length);
	}
};

class Fanni_Packets_API SerializableUUID : public PacketSerializable {
public:
	UUID val;

public:
	SerializableUUID() {};
	virtual ~SerializableUUID() {};
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);
	void operator= (const UUID &uuid);
};

class Fanni_Packets_API SerializableVariable2 : public PacketSerializable {
public:
	std::vector<unsigned char> val;
public:
	SerializableVariable2() { };
	virtual ~SerializableVariable2() { };
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);

	std::string asString() const {
		std::string str((char*)&this->val[0], 0, this->val.size());
		return str;
	}

	void setValue(const unsigned char* data, int len) {
		this->val.resize(len);
		::memcpy(&this->val[0], data, len);
	}

	void operator=(const PacketBuffer &buffer) {
		this->val.resize(buffer.getLength());
		::memcpy(&this->val[0], buffer.getConstBuffer(), buffer.getLength());
	}

	void operator=(const std::string &buffer) {
		// TODO @@@ check if size <= 0xFFFF
		this->val.resize(buffer.size());
		::memcpy(&this->val[0], buffer.c_str(), buffer.size());
	}
};

class Fanni_Packets_API SerializableVariable1 : public PacketSerializable {
public:
	std::vector<unsigned char> val;
public:
	SerializableVariable1() { };
	virtual ~SerializableVariable1() { };
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);
};

class Fanni_Packets_API SerializableQuaternion : public PacketSerializable {
public:
	float x, y, z, w;
public:
	SerializableQuaternion() : x(0), y(0), z(0), w(0){};
	virtual ~SerializableQuaternion() {};
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);
};

class Fanni_Packets_API SerializableVector3 : public PacketSerializable {
public:
	SerializableF32 x, y, z;
public:
	SerializableVector3() {};
	virtual ~SerializableVector3() {};
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);
};

class Fanni_Packets_API SerializableVector3d : public PacketSerializable {
public:
	SerializableF64 x, y, z;
public:
	SerializableVector3d() {};
	virtual ~SerializableVector3d() {};
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);
};

class Fanni_Packets_API SerializableVector4 : public PacketSerializable {
public:
	SerializableF32 x, y, z, s;
public:
	SerializableVector4() {};
	virtual ~SerializableVector4() {};
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);
};

}

#endif /* SERIALIZABLEBASETYPES_H_ */

