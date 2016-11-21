#include "TQueue.h"


template <class T> TQueue<T>::TQueue()
{
    head = nullptr;
    tail = nullptr;
}


template <class A> std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue)
{
    std::shared_ptr<TQueueItem<A>> item = queue.head;

    while (item != nullptr)
    {
        os << *item;
        item = item->GetNext();
    }
    return os;
}


template <class T> void TQueue<T>::push(std::shared_ptr<T> item)
{
    std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(item));
    if (head == nullptr) {
        head = other;
        tail = other;
    }
    else {
        tail->SetNext(other);
        tail = other;
    }
}

template <class T> std::shared_ptr<T> TQueue<T>::top()
{
    return head->GetItem();
}


template <class T> bool TQueue<T>::empty()
{
    return head == nullptr;
}

template <class T> void TQueue<T>::pop()
{
    if (head != nullptr) {
        head = head->GetNext();
    }
}

template <class T> TIterator<TQueueItem<T>, T> TQueue<T>::begin()
{
    return TIterator<TQueueItem<T>, T>(head);
}
template <class T> TIterator<TQueueItem<T>, T> TQueue<T>::end()
{
    return TIterator<TQueueItem<T>, T>(nullptr);
}

template <class T> TQueue<T>::~TQueue() {}
/*
#include "rhombus.h"
template class TQueue<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Rhombus>&	queue);

#include "trapeze.h"
template class TQueue<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Trapeze>&	queue);
#include "pentagon.h"
template class TQueue<Pentagon>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Pentagon>&	queue);
*/

#include "figure.h"
template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Figure>& queue);

