/*
 * FileTransferNode.h
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#ifndef FILETRANSFERNODE_H_
#define FILETRANSFERNODE_H_

#include <string>
#include "fanni/EndPoint.h"
#include "Packets/PacketBase.h"
#include "rUDP/PacketTransferBase.h"
#include "FileTransferPackets/FileTransferPacketFactory.h"
#include "FileTransferPackets/FileTransferPacketsID.h"

namespace Fanni {
namespace Tests {

class FileTransferNode : public PacketTransferBase {
private:
	static const PacketHeader::PACKET_ID_TYPE OPEN_CONNECTION_PACKET = OpenConnection_ID;
	static const PacketHeader::PACKET_ID_TYPE CLOSE_CONNECTION_PACKET = CloseConnection_ID;

	std::string send_file_path;
	void openConnection(const EndPoint &ep);
	void closeConnection(const EndPoint &ep);

	// MEMO @@@ get from Singleton
	const FileTransferPacketFactory &packet_factory;
	PacketHandlerFactory packet_handler_factory;

public:
	FileTransferNode(const std::string &addr, int port, int thread_number);
	virtual ~FileTransferNode();
	virtual void init();

	virtual ClientConnectionBase *createClientConnection(uint32_t circuit_code, const EndPoint *ep);
	virtual bool skipProcessIncomingPacket(PacketHeader::PACKET_ID_TYPE packet_id);
	virtual bool skipHandlePacket(PacketHeader::PACKET_ID_TYPE packet_id);

	void startSendFile(const std::string &file_path, const EndPoint &ep);
	const std::string &getSendFile() const {
		return this->send_file_path;
	}
};

}
}

#endif /* FILETRANSFERNODE_H_ */
