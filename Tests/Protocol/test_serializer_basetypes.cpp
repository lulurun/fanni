#include <iostream>
#include "fanni/PacketBuffer.h"
#include "Packets/PacketBaseTypes.h"

using namespace std;
using namespace Fanni;

class TestObject : public PacketSerializable {
public:
	SerializableBool b;
	SerializableFixed<5> f;
	SerializableU64 u64;
	SerializableF32 f32;
	SerializableF64 f64;
	SerializableU32 u32;
	SerializableU16 u16;
	SerializableS16 s16;
	SerializableU8 u8;
	SerializableS8 s8;
	SerializableVariable2 v2;
	SerializableVariable1 v1;
	SerializableQuaternion Q;
	SerializableVector3 v3;
	SerializableVector4 v4;
	SerializableVector3d v3d;
	SerializableUUID uuid;

public:
	TestObject() { };
	virtual ~TestObject() { };

	virtual void serialize(PacketBuffer &buffer) const {
		this->b.serialize(buffer);
		//this->f.serialize(buffer);
		this->f32.serialize(buffer);
		this->f64.serialize(buffer);
		this->u32.serialize(buffer);
		this->u16.serialize(buffer);
		this->s16.serialize(buffer);
		this->u8.serialize(buffer);
		this->s8.serialize(buffer);
		//this->v2.serialize(buffer);
		//this->v1.serialize(buffer);
		this->Q.serialize(buffer);
		this->v3.serialize(buffer);
		this->v4.serialize(buffer);
		this->v3d.serialize(buffer);
		//this->uuid.serialize(buffer);
	}
	virtual void deserialize(PacketBuffer &buffer) {
		this->b.deserialize(buffer);
		//this->f.deserialize(buffer);
		this->f32.deserialize(buffer);
		this->f64.deserialize(buffer);
		this->u32.deserialize(buffer);
		this->u16.deserialize(buffer);
		this->s16.deserialize(buffer);
		this->u8.deserialize(buffer);
		this->s8.deserialize(buffer);
		//this->v2.deserialize(buffer);
		//this->v1.deserialize(buffer);
		this->Q.deserialize(buffer);
		this->v3.deserialize(buffer);
		this->v4.deserialize(buffer);
		this->v3d.deserialize(buffer);
		//this->uuid.deserialize(buffer);
	}
};

void SetValues(TestObject &packet) {
	packet.b = true;
	packet.f32 = 0.044332;
	packet.f64 = 0.099332123456;
	packet.u32 = 288983256;
	packet.u16 = 28898;
	packet.s16 = 1234;
	packet.u8 = 126;
	packet.s8 = 97;
	//packet.v2 = { 97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100 };
	//#packet.v1 = { 97, 98, 99, 100 };
	packet.Q.w = 0.104411;
	packet.Q.x = 0.216463;
	packet.Q.y = 0.759232;
	packet.Q.z = 0.604822;
	packet.v3.x = 0.569787;
	packet.v3.y = 0.123456;
	packet.v3.z = 0.232356;
	packet.v4.s = 0.111111;
	packet.v4.x = 0.333333;
	packet.v4.y = 0.222222;
	packet.v4.z = 0.099999;
	packet.v3d.x = 0.88888822222;
	packet.v3d.y= 0.11111144444;
	packet.v3d.z = 0.55555666777;
}

void GetValues(TestObject &packet) {
	cout << packet.b << endl;
	cout << packet.f32 << endl;
	cout << packet.f64 << endl;
	cout << packet.u32 << endl;
	cout << packet.u16 << endl;
	cout << packet.s16 << endl;
	cout << packet.u8 << endl;
	cout << packet.s8 << endl;
	//cout << packet.v2 << endl;
	//cout << packet.v1 << endl;
	cout << packet.Q.w << " " << packet.Q.x << " " << packet.Q.y << " " << packet.Q.z << endl;
	cout << packet.v3.x << " " << packet.v3.y << " " << packet.v3.z << endl;
	cout << packet.v4.s << " " << packet.v4.x << " " << packet.v4.y << " " << packet.v4.z << endl;
	cout << packet.v3d.x << " " << packet.v3d.y << " " << packet.v3d.z << endl;
}

void test_base_types() {
	PacketBuffer buffer;
	{
		TestObject packet;
		SetValues(packet);
		packet.serialize(buffer);
	}
	cout << buffer.to_debug_string() << endl;
	{
		TestObject packet;
		packet.deserialize(buffer);
		GetValues(packet);
	}
}

int main() {
	printf("test base types\n");
	test_base_types();
	return 0;
}
