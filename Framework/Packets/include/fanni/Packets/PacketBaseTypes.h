#ifndef SERIALIZABLEBASETYPES_H_
#define SERIALIZABLEBASETYPES_H_

#include <string>
#include <list>
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
	typedef std::list<T> VAR_TYPE;

private:
	VAR_TYPE val;
public:
	MultipleSerializable() {}
	MultipleSerializable(const std::list<T> &val) : val(val) {}
	virtual ~MultipleSerializable() {};

	void push(const T &obj) {
		if (this->val.size() <= Length) {
			this->val.push_back(obj);
		} else {
	    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not add more objects");
		}
	}

	operator VAR_TYPE &() { return this->val; }
	operator const VAR_TYPE &() const { return this->val; }

	virtual void serialize(PacketBuffer &buffer) const {
		if (this->val.size() != Length) {
	    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "not enough blocks for this MultipleSerializable ");
		}
		for(VAR_TYPE::const_iterator it = this->val.begin(); it != this->val.end(); it++) {
			it->serialize(buffer);
		}
	}
	virtual void deserialize(PacketBuffer &buffer) {
		if (this->val.size() != Length) {
			this->val.resize(Length);
		}
		for(VAR_TYPE::iterator it = this->val.begin(); it != this->val.end(); it++) {
			try {
				it->deserialize(buffer);
			} catch (ErrorException &e){
		    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "deserialize Failed %s", e.get_msg());
			}
		}
	}
};

template<class T>
class Fanni_Packets_API VariableSerializable : public PacketSerializable {
public:
	typedef std::list<T> VAR_TYPE;

private:
	static const uint16_t MAX_LENGTH = 256;
	VAR_TYPE val;

public:
	VariableSerializable() {}
	VariableSerializable(const std::list<T> &val) {
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

	operator VAR_TYPE &() { return this->val; }
	operator const VAR_TYPE &() const { return this->val; }
	size_t size() const { return this->val.size(); }

	virtual void serialize(PacketBuffer &buffer) const {
		uint8_t length = static_cast<uint8_t>(this->val.size());
		buffer.putValue<uint8_t>(length);
		for(VAR_TYPE::const_iterator it = this->val.begin(); it != this->val.end(); it++) {
			it->serialize(buffer);
		}
	}

	virtual void deserialize(PacketBuffer &buffer) {
		uint8_t length = buffer.getValue<uint8_t>();
		this->val.resize(length);
		for(VAR_TYPE::iterator it = this->val.begin(); it != this->val.end(); it++) {
			try {
				it->deserialize(buffer);
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
	SerializableFixedSizeValue(const T &val) : val(val){ };
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

	T operator |(const T &val) { return this->val | val; }
	T operator &(const T &val) { return this->val & val; }
	operator T&() { return this->val; }
	operator const T&() const { return this->val; }
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
	typedef unsigned char VAR_TYPE[Length];

private:
	VAR_TYPE val;

public:
	SerializableFixed() {}
	SerializableFixed &operator=(const VAR_TYPE &val) {
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
private:
	UUID val;

public:
	SerializableUUID() {};
	SerializableUUID(const UUID &val) : val(val) {};
	virtual ~SerializableUUID() {};

	//operator UUID &() { return this->val; }
	operator const UUID &() const { return this->val; }

	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);
	void operator= (const UUID &uuid);
};

class Fanni_Packets_API SerializableVariable2 : public PacketSerializable {
public:
	typedef std::vector<unsigned char> VAR_TYPE;

private:
	VAR_TYPE val;

public:
	SerializableVariable2() { };
	SerializableVariable2(const VAR_TYPE &val) : val(val) { };
	virtual ~SerializableVariable2() { };
	virtual void serialize(PacketBuffer &buffer) const;
	virtual void deserialize(PacketBuffer &buffer);

	std::string asString() const {
		std::string str(reinterpret_cast<const char*>(&this->val[0]), 0, this->val.size());
		return str;
	}

	void setValue(const unsigned char* data, int len) {
		this->val.resize(len);
		::memcpy(&this->val[0], data, len);
	}

	const VAR_TYPE &getValue() const {
		return this->val;
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
	typedef std::vector<unsigned char> VAR_TYPE;

private:
	VAR_TYPE val;

public:
	SerializableVariable1() { };
	SerializableVariable1(const VAR_TYPE &val) : val(val) { };
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

