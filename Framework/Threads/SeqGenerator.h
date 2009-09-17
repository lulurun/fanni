#ifndef FP_SEQGENERATOR_H_
#define FP_SEQGENERATOR_H_

#include <list>
#include "Mutex.h"

namespace Fanni {

static const uint32_t SEQ_GEN_MAX = 0xffffffff;

class SequenceGenerator {
private:
	uint32_t counter;
	uint32_t max;
	Mutex counter_lock;
public:
	SequenceGenerator(uint32_t max = SEQ_GEN_MAX) {
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

};

#endif /*SEQGENERATOR_H_*/
