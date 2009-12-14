/*
 * FileTransferClientConnection.h
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#ifndef FT_CONNECTION_H_
#define FT_CONNECTION_H_

#include <map>
#include <string>
#include "Poco/Mutex.h"
#include "Poco/BasicEvent.h"
#include "fanni/EndPoint.h"
#include "fanni/UUID.h"
#include "fanni/LockableTemplate.h"
#include "fanni/LLUDP/ConnectionBase.h"
#include "ConnectionHandler.h"
#include "Status.h"

namespace Fanni {
namespace FileTransfer {

class TransferNode;
class TransferNodeConnectionBase : public ConnectionBase {
protected:
	int circuit_code;

	typedef lockable< std::map<std::string, StatusPtr> > STATUS_MAP;
	STATUS_MAP status_map;

	// status operations
	virtual StatusPtr createStatus(uint32_t file_size, const std::string file_name, const UUID &trans_id) = 0;
	void addTransferStatus(StatusPtr &pStatus);
	StatusPtr &getTransfer(const UUID &trans_id);
	StatusPtr &getTransfer_unsafe(const UUID &trans_id);
	void closeTransfer(const UUID &trans_id);

public:
	TransferNodeConnectionBase(uint32_t circuit_code, const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp);
	virtual ~TransferNodeConnectionBase();

	int getCircuitCode() const { return this->circuit_code;	}
	//TransferNode &getTransferNode() const { return *dynamic_cast<TransferNode *>(&this->udp); };

};

class ClientConnection : public TransferNodeConnectionBase {
private:
	void onFileInfoReply(const void* pSender, const FileInfoReplyPacket &packet);
	void onTransferComplete(const void* pSender, const TransferCompletePacket &packet);
	StatusPtr createStatus(uint32_t file_size, const std::string file_name, const UUID &trans_id);

public:
	ClientConnection(uint32_t circuit_code, const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp);
	virtual ~ClientConnection();

	bool sendFile(const std::string &file_path);

	Poco::BasicEvent<const FileInfoReplyPacket> FileInfoReplyEvent;
	Poco::BasicEvent<const TransferCompletePacket> TransferCompleteEvent;
};

class ServerConnection : public TransferNodeConnectionBase {
private:
	// server event
	void onFileInfo(const void* pSender, const FileInfoPacket &packet);
	void onFileData(const void* pSender, const FileDataPacket &packet);
	StatusPtr createStatus(uint32_t file_size, const std::string file_name, const UUID &trans_id);

public:
	ServerConnection(uint32_t circuit_code, const EndPoint &ep, const PacketSerializer &packet_serializer, LLUDPBase &udp);
	virtual ~ServerConnection();

	Poco::BasicEvent<const FileInfoPacket> FileInfoEvent;
	Poco::BasicEvent<const FileDataPacket> FileDataEvent;
};


}
}

#endif /* FT_CONNECTION_H_ */

