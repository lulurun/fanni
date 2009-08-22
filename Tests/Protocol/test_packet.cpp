#include <vector>
#include <iostream>
#include "fanni/Serializable.h"
#include "Packets/PacketBaseTypes.h"
#include "Packets/PacketSerializer.h"
#include "Packets/PacketHeader.h"
#include "Packets/PacketBase.h"
#include "LLPackets/LLPackets.h"
#include "fanni/Exception.h"
#include "fanni/PacketBuffer.h"

using namespace Fanni; // TODO @@@ remove me !

using namespace std;
using namespace Fanni;

void SetPacketData(TestMessagePacket &packet) {
	{
		packet.TestBlock1.Test1 = 0x1234;
	}
	{
		TestMessagePacket::NeighborBlockBlock block;
		block.Test0 = 0x1111;
		block.Test1 = 0x2222;
		block.Test2 = 0x3333;
		packet.NeighborBlock.push(block);
	}
	{
		TestMessagePacket::NeighborBlockBlock block;
		block.Test0 = 0x4444;
		block.Test1 = 0x5555;
		block.Test2 = 0x6666;
		packet.NeighborBlock.push(block);
	}
	{
		TestMessagePacket::NeighborBlockBlock block;
		block.Test0 = 0x7777;
		block.Test1 = 0x8888;
		block.Test2 = 0x9999;
		packet.NeighborBlock.push(block);
	}
	{
		TestMessagePacket::NeighborBlockBlock block;
		block.Test0 = 0xaaaa;
		block.Test1 = 0xbbbb;
		block.Test2 = 0xcccc;
		packet.NeighborBlock.push(block);
	}
	packet.setSequence(0x8765);
}

void GetPacketData(const TestMessagePacket &packet) {
	cout << packet.header.getPacketID() << endl;
	cout << packet.header.getFrequence() << endl;
	cout << hex << packet.header.getSequenceNumber() << endl;
	cout << hex << packet.TestBlock1.Test1 << endl;
	for(int i=0; i<4; i++) {
		cout << hex << packet.NeighborBlock[i].Test0 << endl;
		cout << hex << packet.NeighborBlock[i].Test1 << endl;
		cout << hex << packet.NeighborBlock[i].Test2 << endl;
	}
}

void test_packet() {
	PacketBuffer buffer;
	{
		TestMessagePacket packet;
		SetPacketData(packet);
		packet.serializePacket(buffer);
	}
	cout << "serialized packet" << endl;
	cout << buffer.to_debug_string() << endl;
	{
		TestMessagePacket packet;
		packet.deserializePacket(buffer);
		cout << "deserialized packet" << endl;
		GetPacketData(packet);
	}
}

int main() {
	cout << "test packet" << endl;
	try {
		test_packet();
	} catch (ErrorException &e) {
		cout << "Exception:" << endl;
		cout << e.get_func() << " at L" << e.get_line() << endl;
		cout << e.get_msg() << endl;
	}
	return 0;
}
