/*
 * queue_packet_transfer.cpp
 *
 *  Created on: Aug 7, 2009
 *      Author: lulu
 */

#include <iostream>
// framework
#include "fanni/Logger.h"
#include "fanni/ThreadTemplate.h"
#include "Network/Event_UDP.h"
#include "Network/FanniSock.h"
#include "Threads/ThreadManager.h"
#include "Threads/SeqGenerator.h"
// packets
#include "fanni/PacketBuffer.h"
#include "Packets/PacketBase.h"
#include "Packets/Packets.h"
#include "Packets/PacketSerializer.h"
// app
#include "TransferData.h"
#include "ReceiverBase.h"
#include "ProtocolPacketHandlers.h"
#include "PacketServer.h"

using namespace std;
using namespace Fanni;
using namespace Fanni::Network;
using namespace Fanni::Tests;

static const string DEFAULT_ADDR = "127.0.0.1";
static const int DEFAULT_PORT = 9001;
static const int thread_number = 1;

int main(int argc, char **argv) {
	try {
		DEBUG_LOG("enter Server mode");
		PacketServer server(DEFAULT_ADDR, DEFAULT_PORT, thread_number);
		server.init();
	} catch (ErrorException &e) {
		ERROR_LOG("ERROR Exception: " << e.get_func() << " at L" << e.get_line() << " " << e.get_msg());
	}
	return 0;
}

