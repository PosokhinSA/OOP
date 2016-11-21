#ifndef TQUEUE_H
#define TQUEUE_H

#include "TQueueItem.h"
#include "TIterator.h"

#include <memory>

template <class T> class TQueue {
public:
    TQueue();

    void push(std::shared_ptr<T> figure);
    bool empty();
    std::shared_ptr<T> top();
    void pop();

    TIterator<TQueueItem<T>, T> TQueue<T>::begin();
    TIterator<TQueueItem<T>, T> TQueue<T>::end();


    template <class A>  friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
    virtual ~TQueue();
private:

    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;
};
#endif /* TQUEUE_H */
