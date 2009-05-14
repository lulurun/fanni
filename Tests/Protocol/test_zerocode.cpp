#include <iostream>
#include "fanni/PacketBuffer.h"
#include "Packets/PacketBaseTypes.h"
#include "Packets/PacketSerializer.h"
#include "Packets/PacketHeader.h"

using namespace std;
using namespace Fanni;

void test_zerocode() {
	PacketBuffer buffer;
	for(int j=1; j<5; j++) {
		for(int i=0; i<j+5; i++) {
			buffer.putValue<uint8_t>(0);
		}
		buffer.putValue<uint8_t>(j);
	}
	cout << "test byte array:" << endl;
	cout << buffer.to_debug_string() << endl;

	// encode
	PacketSerializer ps;
	ps.zeroEncode(buffer);
	cout << "encode:" << endl;
	cout << buffer.to_debug_string() << endl;

	// decode
	ps.zeroDecode(buffer);
	cout << "decode:" << endl;
	cout << buffer.to_debug_string() << endl;
}

int main() {
	cout << "test zerocode" << endl;
	test_zerocode();
	return 0;
}
