#ifndef TQUEUE_H
#define TQUEUE_H

#include "TQueueItem.h"
#include "TIterator.h"

#include <memory>

template <class T, class TT> class TQueue { // T - 2nd lvl container, TT value type
public:
    TQueue();

    void InsertSubItem(TT* figure);
  
    void RemoveSubItemByValue(double value);
    void Push(T* value);
  //  bool Remove(T* value);
    size_t Size();

  //  bool empty();
  //  std::shared_ptr<TT> top();
  //  void pop();*
    TIterator<TQueueItem<T>, T> TQueue<T, TT>::begin();
    TIterator<TQueueItem<T>, T> TQueue<T, TT>::end();
    

//    template <class A, class AA> friend std::ostream& operator<<(std::ostream& os, const TQueue<A, AA>& list);
    virtual ~TQueue();
private:

    std::shared_ptr<TQueueItem<T>> head;
    std::shared_ptr<TQueueItem<T>> tail;
};
#endif /* TQUEUE_H */
