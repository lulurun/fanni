/*
 * ClientConnection.h
 *
 *  Created on: Sep 19, 2009
 *      Author: lulu
 */

#ifndef CLIENTCONNECTION_H_
#define CLIENTCONNECTION_H_

#include "rUDP/ConnectionBase.h"

namespace Fanni {

class ClientConnection : public ConnectionBase {
public:
	ClientConnection(uint32_t circuit_code, const Poco::Net::SocketAddress&addr, TransferNode &node);
	virtual ~ClientConnection();
};

}

#endif /* CLIENTCONNECTION_H_ */
