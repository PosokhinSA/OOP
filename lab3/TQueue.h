#ifndef TQUEUE_H
#define TQUEUE_H

#include "TQueueItem.h"
#include <memory>

class TQueue {
public:
    TQueue();
//    TQueue(const TQueue& orig);
    
    void push(std::shared_ptr<Rhombus> &&rhombus, std::shared_ptr<Trapeze> &&trapeze, std::shared_ptr<Pentagon> &&pentagon);
    bool empty();
    
    std::shared_ptr<Rhombus> top_rhomb();
	std::shared_ptr<Trapeze> top_trapez();
	std::shared_ptr<Pentagon> top_pent();
    void pop();
    
    friend std::ostream& operator<<(std::ostream& os,const TQueue& queue);
    virtual ~TQueue();
private:
    std::shared_ptr<TQueueItem> head;
    std::shared_ptr<TQueueItem> tail;
};
#endif /* TQUEUE_H */
