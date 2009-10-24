/*
 * ClientConnection.cpp
 *
 *  Created on: Sep 19, 2009
 *      Author: lulu
 */

#include "ClientConnection.h"

namespace Fanni {

ClientConnection::ClientConnection(uint32_t circuit_code, const Poco::Net::SocketAddress &addr, TransferNode &node) :
	ConnectionBase(circuit_code, addr, node){
}

ClientConnection::~ClientConnection() {
	// TODO Auto-generated destructor stub
}

}
