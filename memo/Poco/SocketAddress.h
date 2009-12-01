#ifndef _MEMO_SOCKETADDRESS_H_
#define _MEMO_SOCKETADDRESS_H_

#include <iostream>
#include "MemoBase.h"
#include "Poco/Net/SocketAddress.h"

class SocketAddressMemo : public MemoBase {
public:
	SocketAddressMemo() {}
	virtual ~SocketAddressMemo() {
	}

	void run() {
		{
			Poco::Net::SocketAddress addr("127.0.0.1", 9001);
			// no copy
			memo1(addr);
		}
		{
			Poco::Net::SocketAddress addr("127.0.0.1", 9001);
			// copy
			memo2(addr);
		}
		{
			{ // addr is already deleted
				/*
				Poco::Net::SocketAddress &addr = memo3();
				std::cout << addr.toString() << std::endl;
				*/
			}
			{ // addr is already deleted
				/*
				Poco::Net::SocketAddress addr = memo3();
				std::cout << addr.toString() << std::endl;
				*/
			}
		}
		{
			// copy
			Poco::Net::SocketAddress addr = memo4();
			std::cout << addr.toString() << std::endl;
		}
	}
private:

	void memo1(Poco::Net::SocketAddress &addr) {
		std::cout << addr.toString() << std::endl;
	}

	inline void memo2(Poco::Net::SocketAddress addr) {
		std::cout << addr.toString() << std::endl;
	}
	/* compile warning
	Poco::Net::SocketAddress &memo3() {
		Poco::Net::SocketAddress addr("127.0.0.1", 9001);
		return addr;
	}
	*/
	Poco::Net::SocketAddress memo4() {
		Poco::Net::SocketAddress addr("127.0.0.1", 9001);
		return addr;
	}

};

#endif // _MEMO_SOCKETADDRESS_H_
