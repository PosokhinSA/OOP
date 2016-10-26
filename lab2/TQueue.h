#ifndef TQUEUE_H
#define TQUEUE_H
#include "rhombus.h"
#include "TQueueItem.h"
class TQueue {
public:
    TQueue();
    TQueue(const TQueue& orig);
    
    void push(Rhombus&& rhombus);
    bool empty();
    Rhombus pop();
    friend std::ostream& operator<<(std::ostream& os,const TQueue& queue);
    virtual ~TQueue();
private:
    TQueueItem *head;
    TQueueItem *tail;
};
#endif /* TQUEUE_H */
