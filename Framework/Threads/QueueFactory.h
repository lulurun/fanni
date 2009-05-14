#ifndef FP_QUEUEFACTORY_H_
#define FP_QUEUEFACTORY_H_

#include <list>
#include "Queue.h"
#include "ThreadTask.h"

namespace Fanni {

  class QueueFactory {
  public:
    typedef Queue<const ThreadTask *> QUEUE_TYPE;
    typedef std::list<QUEUE_TYPE *> QUEUE_LIST_TYPE;

  private:
    QUEUE_LIST_TYPE queue_list;

    QueueFactory();
    void init();

  public:
    virtual ~QueueFactory();
    // TODO: use template function ?
    QUEUE_TYPE *createQueue();

    static QueueFactory *GetInstance();

};

}

#endif /*FP_QUEUEFACTORY_H_*/
