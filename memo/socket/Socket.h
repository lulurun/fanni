#ifndef FANNI_SOCKET_H_
#define FANNI_SOCKET_H_

#include <netinet/in.h>
#include <string>
#include "common.h"

namespace Fanni {
namespace Communication {

class Socket {
public:
	Socket();
	Socket(const std::string &addr, unsigned short port, Protocols proto =
			PROTOCOL_UDP);
	virtual ~Socket();

	ReturnCode connect(const std::string &addr, unsigned short port, Protocols proto);
	ReturnCode connect();
	void close();
	ReturnCode writeData(void *buf, int bufLen, int *writeLen = 0);
	ReturnCode readData(void *buf, int bufLen, int *readLen = 0);

	ReturnCode flush();
	void setTimeout(int millisecs);
	void setPollTime(int millisecs);

	unsigned long getIpAddr();
	void setIpAddr(unsigned long ipaddr);

	SOCKET getSockfd();

private:
	ReturnCode checkTimeout(unsigned int *timeout, unsigned int *timedout,
			int haveAllData);

	SOCKET sockfd;
	FILE *stdiofd;
	sockaddr_in to;
	unsigned long ipaddr;
	Protocols protocol;
	unsigned int timeout;
	unsigned int polltime;
	unsigned short port;
	std::string hostname;
};

}
}

#endif /* FANNI_SOCKET_H_ */

