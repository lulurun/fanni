#ifndef _POCOMEMO_H_
#define _POCOMEMO_H_

#include <iostream>
#include <vector>

#include "MemoBase.h"
#include "SocketAddress.h"

class PocoMemoSet {
private:
	typedef std::vector<MemoBase *> MEMO_LIST;
	MEMO_LIST _list;

	PocoMemoSet() {
		this->registerMemo(new SocketAddressMemo());
	};

public:
	~PocoMemoSet() {
		for(MEMO_LIST::iterator it=this->_list.begin(); it!=this->_list.end(); it++) {
			delete *it;
		}
		this->_list.clear();
	};

	void registerMemo(MemoBase *memo) {
		this->_list.push_back(memo);
	};

	void run() {
		std::cout << "start ..." << std::endl;
		for(MEMO_LIST::iterator it=this->_list.begin(); it!=this->_list.end(); it++) {
			(*it)->run();
		}
		std::cout << "end ....." << std::endl;
	}

	static PocoMemoSet &Instance() {
		static PocoMemoSet instance;
		return instance;
	};
};

#endif // _POCOMEMO_H_
