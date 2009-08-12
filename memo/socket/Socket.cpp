#include "Socket.h"

using namespace std;

namespace Fanni {
namespace Communication {

Socket::Socket() {
	// TODO Auto-generated constructor stub

}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
}


ReturnCode Socket::connect(const std::string &addr, unsigned short port, Protocols proto) {
	this->port = port;
	this->protocol = proto;
	this->hostname = addr;
	return connect();
}

ReturnCode Socket::connect() {
    ReturnCode ret = RC_OK;
    unsigned long timeout = 0;
    int err = 0;
    ncSockAddrIn tmp;
    ncSockAddrIn *servaddr =
        ((m_socktype == PROTOCOL_TCP) ? &tmp : &m_to);
    int sockType =
        ((this->protocol == PROTOCOL_TCP) ? SOCK_STREAM : SOCK_DGRAM);

    this->sockfd = socket(AF_INET, sockType, 0);
    if (!this->sockfd) {
        return NC_FAILED;
    }

    memset(servaddr,0,sizeof(servaddr));
    servaddr->sin_family = AF_INET;
    servaddr->sin_port = htons(m_port);

    /* resolve dotted ip address */
    if (!ncValidInetAddr(
            ncGetInetAddr(m_hostname,&servaddr->sin_addr.s_addr)))
    {
        /* otherwise, resolve host name */
        ncHostent *pHostent = ncGetHostByName(m_hostname);
        if (!pHostent)
        {
            err = ncGetLastError();
            DEBUG("host address resolution failed for " << m_hostname);
            DEBUG("Error Code: " << err);
            return NC_FAILED;
        }
        else
        {
            servaddr->sin_addr.s_addr =
                *((unsigned long *)pHostent->h_addr_list[0]);
        }
    }

    /* stash the ip address as an unsigned long in host byte order */
    m_ipaddr = servaddr->sin_addr.s_addr;
    DEBUG("about to connect to " << m_ipaddr << " (numeric format)");

    /* set socket to non-blocking mode */
    ncSetSocketNonBlocking(m_sockfd);

    /* attempt the connect until we timeout */
    while (::connect(m_sockfd,(struct sockaddr *)servaddr,
                     sizeof(*servaddr)) < 0)
    {
        err = ncGetLastError();
        DEBUG("connect error = " << err);
        if (ncIsBlockingError(err))
        {
            timeout += 100;
            if (timeout > m_timeout)
            {
                DEBUG("connect to host timed out (" << err << ").");
                ret = NC_TIMEDOUT;
                break;
            }
        }
        else if (ncIsConnected(err))
        {
            DEBUG("already connected!");
            break;
        }
        else
        {
            DEBUG("connect to host failed (" << err << ").");
            ret = NC_FAILED;
            break;
        }
        ncSleep(100);
    }
    return ret;
}

/*
void close();
ReturnCode writeData(void *buf, int bufLen, int *writeLen = 0);
ReturnCode readData(void *buf, int bufLen, int *readLen = 0);

ReturnCode flush();
void setTimeout(int millisecs);
void setPollTime(int millisecs);

unsigned long getIpAddr();
void setIpAddr(unsigned long ipaddr);

SOCKET getSockfd();

ReturnCode checkTimeout(unsigned int *timeout, unsigned int *timedout,
		int haveAllData);
*/

}
}
