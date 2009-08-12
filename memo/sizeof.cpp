/*
 * sizeof.cpp
 *
 *  Created on: Aug 11, 2009
 *      Author: lulu
 */

#include <iostream>
#include "Packets/Packets.h"
#include "Packets/PacketFactory.h"

using namespace std;
using namespace Fanni;

int main() {
	{
		PacketBase *packet = new StartPingCheckPacket();
		cout << "StartPingCheckPacket: " << sizeof(packet) << endl;
		cout << "StartPingCheckPacket: " << sizeof(StartPingCheckPacket) << endl;
	}

	{
		PacketBase *packet = new RegionHandshakePacket();
		cout << "RegionHandshakePacket: " << sizeof(packet) << endl;
		cout << "RegionHandshakePacket: " << sizeof(RegionHandshakePacket) << endl;
	}

	{
		StartPingCheckPacket *packet = new StartPingCheckPacket();
		packet->PingID.PingID = 1;
		StartPingCheckPacket *packet_copy = new StartPingCheckPacket(*packet);
		cout << packet_copy->PingID.PingID << endl;
	}

	{
		StartPingCheckPacket *packet = new StartPingCheckPacket();
		packet->PingID.PingID = 1;
		PacketBase *packet_copy = new StartPingCheckPacket(*packet);
		StartPingCheckPacket *start_ping_check_packet_copy = dynamic_cast<StartPingCheckPacket *>(packet_copy);
		cout << start_ping_check_packet_copy->PingID.PingID << endl;
	}

	{
		StartPingCheckPacket *packet = new StartPingCheckPacket();
		packet->PingID.PingID = 1;
		PacketBase *packet_copy = PacketFactory::GetInstance()->createPacket(StartPingCheck_ID);
		StartPingCheckPacket *start_ping_check_packet_copy = dynamic_cast<StartPingCheckPacket *>(packet_copy);
		cout << start_ping_check_packet_copy->PingID.PingID << endl;
	}
}
