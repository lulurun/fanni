#include <fstream>
#include <string>
#include <iostream>
#include "fanni/PacketBuffer.h"
#include "fanni/Exception.h"
#include "Packets/PacketSerializer.h"

using namespace std;
using namespace Fanni;

static int hex_value_table[23] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
		0x07, 0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0B,
		0x0C, 0x0D, 0x0E, 0x0F };

void hexstring_to_bytearray(const string &hex_string, PacketBuffer &buf) {
	for (size_t i = 0; i < hex_string.length(); i += 2) {
		uint8_t b = (hex_value_table[hex_string[i] - '0'] << 4)
				| hex_value_table[hex_string[i + 1] - '0'];
		buf.putValue<uint8_t>(b);
	}
}

bool compare(const unsigned char *buf_1, int buf_1_len,
		const unsigned char *buf_2, int buf_2_len) {
	if (buf_1_len != buf_2_len) {
		cout << "size! " << buf_1_len << " " << buf_2_len << endl;
		return false;
	}
	for (int i = 0; i < buf_1_len; i++) {
		if (buf_1[i] != buf_2[i]) {
			cout << "compare failed at " << i << endl;
			return false;
		}
	}
	return true;
}

int main() {
	int skip = -1;
	int max_line = 500;
	try {
		PacketSerializer packet_serializer;
		ifstream ifs("libomv_generated_messages.txt");
		string csharp_line;
		int count = 0;
		bool suc = true;
		while (ifs && getline(ifs, csharp_line)) {
			if (count++ < skip)
				continue;
			if (count == max_line)
				break;
			{
				// print 1
				cout << "message length: " << csharp_line.length() << endl;
				cout << "CSharp:" << endl;
				cout << csharp_line << endl;
			}
			// serialize
			PacketBuffer buf_1;
			hexstring_to_bytearray(csharp_line, buf_1);
			PacketBase *packet = packet_serializer.deserialize(buf_1);
			cout << hex << packet->header.getPacketID() << dec << endl;
			// deserialize
			int len = 0;
			const unsigned char *cpp_line = packet_serializer.serialize(packet,
					&len);
			(void) cpp_line;
			{
				// print 2
				for (int i = 0; i < len; i++) {
					printf("%02X", cpp_line[i]);
				}
				printf("\n");
			}
			if (!compare(buf_1.getConstBuffer(), buf_1.getLength(), cpp_line,
					len)) {
				suc = false;
				break;
			}
		}
		if (suc) {
			cout << "All Tests Success!!" << endl;
		} else {
			cout << "Failed!!" << endl;
			return -1;
		}
	} catch (ErrorException &e) {
		cout << "Exception:" << endl;
		cout << e.get_func() << " at L" << e.get_line() << endl;
		cout << e.get_msg() << endl;
		return -1;
	}
	return -1;
}

