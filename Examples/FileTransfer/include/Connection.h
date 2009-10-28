/*
 * FileTransferClientConnection.h
 *
 *  Created on: Aug 26, 2009
 *      Author: lulu
 */

#ifndef FILETRANSFERCLIENTCONNECTION_H_
#define FILETRANSFERCLIENTCONNECTION_H_

#include <string>
#include "Poco/Mutex.h"
#include "Poco/HashMap.h"
#include "Poco/Net/SocketAddress.h"

#include "fanni/UUID.h"
#include "fanni/LockableTemplate.h"
#include "fanni/rUDP/ConnectionBase.h"
#include "Status.h"

namespace Fanni {
namespace FileTransfer {

class Node;
class Connection : public ConnectionBase {

private:
	typedef Poco::HashMap<std::string, Status *> __STATUS_MAP;
	typedef lockable<__STATUS_MAP> STATUS_MAP;
	STATUS_MAP receive_status_map;
	STATUS_MAP send_status_map;

	// client event
	struct OnOpenConnectionReplyEvent {
		void operator()(Connection *conn);
	};
	struct OnFileInfoReplyEvent {
		void operator()(const UUID &receive_id, const UUID &send_id, Connection *conn);
	};
	struct OnFileTransferCompleteEvent  {
		void operator()(const UUID &send_id, Connection *conn);
	};
	// server event
	struct OnFileInfoEvent {
		void operator()(uint32_t file_size, const std::string &file_name, const UUID &send_id, Connection *conn);
	};
	struct OnFileDataEvent {
		void operator()(const UUID &receive_id, int data_number, const std::vector<unsigned char> &data_buf, Connection *conn);
	};

	Status &createReceiveStatus(uint32_t file_size, const std::string file_name, const UUID &receive_id, const UUID &send_id);
	Status *getReceiveTransfer(const UUID &receive_id);
	Status *_getReceiveTransfer_nolock(const UUID &receive_id);
	void closeReceiveTransfer(const UUID &receive_id);

	Status &createSendStatus(uint32_t file_size, const std::string file_name, const UUID &receive_id, const UUID &send_id);
	Status *getSendTransfer(const UUID &send_id);
	Status *_getSendTransfer_nolock(const UUID &send_id);
	void closeSendTransfer(const UUID &send_id);

public:

	Connection(uint32_t circuit_code, const Poco::Net::SocketAddress &addr, TransferNode &node);
	virtual ~Connection();

	// client event
	OnOpenConnectionReplyEvent OnOpenConnectionReply;
	OnFileInfoReplyEvent OnFileInfoReply;
	OnFileTransferCompleteEvent OnFileTransferComplete;
	// server event
	OnFileInfoEvent OnFileInfo;
	OnFileDataEvent OnFileData;

};


}
}

#endif /* FILETRANSFERCLIENTCONNECTION_H_ */

