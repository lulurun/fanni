#ifndef _MEMO_H_
#define _MEMO_H_

class MemoBase {
protected:
	MemoBase() {};
public:
	virtual ~MemoBase() {};
	virtual void run() = 0;
};

#endif // _MEMO_H_
