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
#include "fanni/Packets/PacketBase.h"
#include "fanni/rUDP/TransferNode.h"
#include "fanni/FTPackets/FTPacketsID.h"

namespace Fanni {
namespace FileTransfer {

class Node : public TransferNode {
private:
	std::string send_file_path;

	void connect(const EndPoint &ep);
	void close(const EndPoint &ep);

public:
	Node(const std::string &addr, uint16_t port, int thread_number);
	virtual ~Node();
	virtual ConnectionBase &createConnection(const PacketBasePtr &packet, const EndPoint &ep);
	virtual bool isSystemPacket(const PacketBasePtr &packet) const;

	void startSendFile(const std::string &file_path, const EndPoint &ep);

	const std::string &getSendFile() const;
};

}
}

#endif /* FILETRANSFERNODE_H_ */
