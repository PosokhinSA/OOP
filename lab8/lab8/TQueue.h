#ifndef TQUEUE_H
#define TQUEUE_H

#include "TQueueItem.h"
#include "TIterator.h"
#include <future> 
#include <mutex>
#include <memory>

template <class T> class TQueue {
public:
    TQueue();

    void push(std::shared_ptr<T> figure);
    bool empty();
    
    
    std::shared_ptr<T> pop();
   

    TIterator<TQueueItem<T>, T> TQueue<T>::begin();
    TIterator<TQueueItem<T>, T> TQueue<T>::end();

    std::shared_ptr<T> operator[] (size_t i);
    void sort();
    void sort_parallel();


    template <class A>  friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
    size_t size();

    virtual ~TQueue();
private:
    std::future<void> sort_in_background();
    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;
};
#endif /* TQUEUE_H */
