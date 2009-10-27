#ifndef BYTEORDER_H_
#define BYTEORDER_H_

#include <sys/types.h>
#include "win_stdint.h"

namespace Fanni {

  // recursive template
  template<unsigned int SIZE_, unsigned int OFFSET_ = 0>
    struct ByteOrderChange {
      ByteOrderChange(uint8_t *dst, const uint8_t *src) {
	dst[OFFSET_] = src[SIZE_-1];
	ByteOrderChange<SIZE_-1,OFFSET_+1> next(dst,src);
	(void)next;
      }
    };
  // terminator template
  template<unsigned int OFFSET_>
    struct ByteOrderChange<0, OFFSET_> {
      ByteOrderChange(uint8_t *dst, const uint8_t *src) {};
    };

  // process
  template<int SIZE_> class ByteOrder {
    uint8_t dst[SIZE_];
  public:
    inline void * change(const void *temp) {
      const uint8_t *src = reinterpret_cast<const uint8_t* >(temp);
      ByteOrderChange<SIZE_> changer(dst,src);
      (void)changer;
      return reinterpret_cast<void *>(&dst);
    }
  };
  // interface
  template<class TYPE_> class ByteOrderTemplate {
  public:
    static inline TYPE_ change(const TYPE_ &src){
      ByteOrder<sizeof(TYPE_)> ret;
      return *reinterpret_cast<TYPE_*>(ret.change(&src));
    }
  };

}

#endif /* BYTEORDER_H_ */
