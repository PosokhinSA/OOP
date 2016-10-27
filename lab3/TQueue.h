#ifndef TQUEUE_H
#define TQUEUE_H
#include "rhombus.h"
#include "TQueueItem.h"
#include <memory>

class TQueue {
public:
    TQueue();
    TQueue(const TQueue& orig);
    
    void push(std::shared_ptr<Rhombus> &&rhombus);
    bool empty();
    std::shared_ptr<Rhombus> pop();
    friend std::ostream& operator<<(std::ostream& os,const TQueue& queue);
    virtual ~TQueue();
private:
    std::shared_ptr<TQueueItem> head;
    std::shared_ptr<TQueueItem> tail;
};
#endif /* TQUEUE_H */
