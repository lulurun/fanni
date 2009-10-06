/*
 * ClientConnection.h
 *
 *  Created on: Sep 19, 2009
 *      Author: lulu
 */

#ifndef CLIENTCONNECTION_H_
#define CLIENTCONNECTION_H_

#include "PacketTransfer/ClientConnectionBase.h"

namespace Fanni {

class ClientConnection : public ClientConnectionBase {
public:
	ClientConnection(uint32_t circuit_code, const EndPoint &ep, PacketTransferBase &transfer_base);
	virtual ~ClientConnection();
};

}

#endif /* CLIENTCONNECTION_H_ */
