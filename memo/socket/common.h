#ifndef FANNI_COMMON_H_
#define FANNI_COMMON_H_

namespace Fanni {
namespace Communication {

enum HostType {
	HOSTTYPE_SERVER = -1, HOSTTYPE_CLIENT = 0,
};

enum Protocols {
	PROTOCOL_TCP = 0, PROTOCOL_UDP = 1,
};

enum ConnStates {
	STATE_CONNECTING = 0,
	STATE_CONNECTED = 1,
	STATE_DISCONNECTING = 2,
	STATE_DISCONNECTED = 4,
};

enum ErrorCode {
	INVALID_SOCKET = -1, SERVER_ERROR = 1, CLIENT_ERROR = 2, TIMEOUT = 3,
};

enum ReturnCode {
	RC_FAILED = -1, RC_OK = 0, RC_TIMEOUT = 1,
};

typedef int SOCKET;
static const int BUF_LEN = 1500;

}
}

#endif /* FANNI_COMMON_H_ */

