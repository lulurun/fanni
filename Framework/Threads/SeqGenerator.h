#ifndef _SEQGENERATOR_H_
#define _SEQGENERATOR_H_

#include <list>
#include "DataControl.h"

namespace Fanni {

static const uint32_t SEQ_GEN_MAX = 0xffffffff;

class SequenceGenerator {
private:
	uint32_t counter;
	uint32_t max;
	DataControl counter_lock;
public:
	SequenceGenerator(uint32_t max = SEQ_GEN_MAX) {
		this->counter = 0;
		this->max = max;
	};
	~SequenceGenerator() {};
	uint32_t next() {
		{
			DataControlLock l(this->counter_lock);
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

#endif /*_SEQGENERATOR_H_*/
