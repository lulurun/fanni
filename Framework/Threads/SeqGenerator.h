#ifndef FP_SEQGENERATOR_H_
#define FP_SEQGENERATOR_H_

#include <list>
#include "Mutex.h"

namespace Fanni {

class SequenceGenerator {
private:
	uint32_t counter;
	uint32_t max;
	Mutex counter_lock;
public:
	SequenceGenerator(int max = 100000) { // TODO: replace with INT_MAX or sth. ...
		this->counter = 0;
		this->max = max;
	};
	~SequenceGenerator() {};
	uint32_t next() {
		{
			S_MUTEX_LOCK l;
			l.lock(&this->counter_lock);
			if (this->counter > this->max) {
				this->reset();
			}
			return this->counter++;
		}
	};
	uint32_t operator++() {
		return this->next();
	}
	void reset() {
		this->counter = 0;
	}
};

class SequenceGeneratorFactory {
private:
	std::list<SequenceGenerator *> gen_list;
public:
	SequenceGeneratorFactory() {};
	~SequenceGeneratorFactory() {
		for(std::list<SequenceGenerator *>::iterator it=this->gen_list.begin(); it!=this->gen_list.end(); it++) {
			delete &it;
		}
	};
	SequenceGenerator *createGenerator(int max = 0xffffffff) { // TODO: replace with INT_MAX or sth. ...
		SequenceGenerator *gen = new SequenceGenerator(max);
		this->gen_list.push_back(gen);
		return gen;
	}
	static SequenceGeneratorFactory *GetInstance() {
		static SequenceGeneratorFactory *ptr = NULL;
		if (ptr == NULL) {
			ptr = new SequenceGeneratorFactory();
		}
		return ptr;
	}
};

};

#endif /*SEQGENERATOR_H_*/
