/*
 * FileTransferNode.h
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#ifndef FILETRANSFERNODE_H_
#define FILETRANSFERNODE_H_

#include <string>
#include "Poco/Event.h"
#include "fanni/EndPoint.h"
#include "fanni/Packets/PacketBase.h"
#include "fanni/LLUDP/LLUDPBase.h"
#include "fanni/FTPackets/FTPacketsID.h"
#include "ConnectionHandler.h"
#include "SystemHandler.h"

namespace Fanni {
namespace FileTransfer {

class TransferNode : public LLUDPBase {
private:
	std::string send_file_path;
	Poco::Event connected;
	Poco::Event disconnected;

	virtual ConnectionBasePtr createConnection(const PacketBasePtr &packet, const EndPoint &ep);

	// server
	void onConnectionAdded(const void* pSender, const EndPoint &ep);
	void onConnectionRemoved(const void* pSender, const EndPoint &ep);
	// client
	void onConnected(const void* pSender, const EndPoint &ep);
	void onDisconnected(const void* pSender, const EndPoint &ep);

public:
	TransferNode(const EndPoint &server_ep);
	virtual ~TransferNode();

	ClientConnection &connect(const EndPoint &ep);
	bool disconnect(const ClientConnection &cConn);

	void sendFile(const std::string &file_path, const EndPoint &ep);

	const std::string &getSendFile() const { return this->send_file_path; };

};

}
}

#endif /* FILETRANSFERNODE_H_ */
