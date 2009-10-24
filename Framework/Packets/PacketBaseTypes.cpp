#include "PacketBaseTypes.h"

#include <string.h>
#include <math.h>
#include "fanni/PacketBuffer.h"
#include "fanni/Exception.h"

using namespace Fanni;

// UUID (16Bytes)
void SerializableUUID::serialize(PacketBuffer &buffer) const {
	// @@@ check inside buffer
	// TODO @@@ !!! ??? look into Poco

	buffer.putBuf(&this->val, sizeof(UUID));
}

void SerializableUUID::deserialize(PacketBuffer &buffer) {
	// @@@ check inside buffer
	// TODO @@@ !!! ??? look into Poco
	buffer.getBuf(&this->val, sizeof(UUID));
}

void SerializableUUID::operator=(const UUID &uuid) {
	// TODO @@@ bad copy ?
	this->val = uuid;
}

// STRING len (0 - 256*256Bytes)
void SerializableVariable2::serialize(PacketBuffer &buffer) const {
	uint16_t length = val.size();
	buffer.putValue<uint16_t>(length, false);
	buffer.putBuf(&this->val[0], length);
}

void SerializableVariable2::deserialize(PacketBuffer &buffer) {
	uint16_t length = buffer.getValue<uint16_t>(false);
	buffer.getBuf(this->val, length);
}

// STRING len (0 - 256Bytes)
void SerializableVariable1::serialize(PacketBuffer &buffer) const {
	uint8_t length = val.size();
	buffer.putValue<uint8_t>(length);
	buffer.putBuf(&this->val[0], length);
}

void SerializableVariable1::deserialize(PacketBuffer &buffer) {
	// @@@ check inside buffer
	uint8_t length = buffer.getValue<uint8_t>();
	buffer.getBuf(this->val, length);
}

// Quaternion
void SerializableQuaternion::serialize(PacketBuffer &buffer) const {
	// @@@ check inside buffer
    float norm = (float)sqrt(
    		this->x*this->x +
			this->y*this->y +
			this->z*this->z +
			this->w*this->w);
    if (norm == 0.0) {
    	ErrorException::throw_exception(EXP_Packet, EXP_PRE_MSG, "norm of the Quaternion is 0");
    }
    norm = 1 / norm;
    float fx, fy, fz;
    if (w >= 0.0) {
        fx = this->x;
        fy = this->y;
        fz = this->z;
    } else {
        fx = -this->x;
        fy = -this->y;
        fz = -this->z;
    }
	buffer.putValue<float>(norm * fx);
	buffer.putValue<float>(norm * fy);
	buffer.putValue<float>(norm * fz);
}

void SerializableQuaternion::deserialize(PacketBuffer &buffer) {
	// @@@ check inside buffer
	this->x = buffer.getValue<float>();
	this->y = buffer.getValue<float>();
	this->z = buffer.getValue<float>();

    float xyzsum = 1 - (this->x*this->x + this->y*this->y + this->z*this->z);
    this->w = (xyzsum > 0.0) ? (float)sqrt(xyzsum) : 0.0;
}

// vector3 (float)
void SerializableVector3::serialize(PacketBuffer &buffer) const {
	this->x.serialize(buffer);
	this->y.serialize(buffer);
	this->z.serialize(buffer);
}

void SerializableVector3::deserialize(PacketBuffer &buffer) {
	this->x.deserialize(buffer);
	this->y.deserialize(buffer);
	this->z.deserialize(buffer);
}

// vector4 (float)
void SerializableVector4::serialize(PacketBuffer &buffer) const {
	this->x.serialize(buffer);
	this->y.serialize(buffer);
	this->z.serialize(buffer);
	this->s.serialize(buffer);
}

void SerializableVector4::deserialize(PacketBuffer &buffer) {
	this->x.deserialize(buffer);
	this->y.deserialize(buffer);
	this->z.deserialize(buffer);
	this->s.deserialize(buffer);
}

// vector3d (double)
void SerializableVector3d::serialize(PacketBuffer &buffer) const {
	this->x.serialize(buffer);
	this->y.serialize(buffer);
	this->z.serialize(buffer);
}

void SerializableVector3d::deserialize(PacketBuffer &buffer) {
	this->x.deserialize(buffer);
	this->y.deserialize(buffer);
	this->z.deserialize(buffer);
}

