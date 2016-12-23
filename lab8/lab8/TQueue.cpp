#include "TQueue.h"


template <class T> TQueue<T>::TQueue()
{
    head = nullptr;
    tail = nullptr;
}


template <class T> void TQueue<T>::sort()
{
    if (size() > 1) {
        std::shared_ptr<T> middle = pop();
        middle->Print();
        TQueue<T> left, right;
        while (!empty()) {
            std::shared_ptr<T> item = pop();
            if (item->Square() < middle->Square()) {
                left.push(item);
            }
            else {
                right.push(item);
            }
        }
        left.sort();
        right.sort();
        while (!left.empty()) {
            push(left.pop());
            std::cout << "got here";
        }
  
        push(middle);
        while (!right.empty()) {
            push(right.pop());
        }
            
    }
}


template<class T > std::future<void> TQueue<T>::sort_in_background()
{ 
    std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TQueue<T>::sort_parallel), this));
    std::future<void> res(task.get_future());
    std::thread th(std::move(task));
    th.detach();
    return res; 
}
template <class T> void TQueue<T>::sort_parallel()
{
    if (size() > 1)
    {
        std::shared_ptr<T> middle = pop();
        TQueue<T> left, right;
        while (!empty())
        {
            std::shared_ptr<T> item = pop();
            if (item->Square() < middle->Square())
            {
                left.push(item);
            }
            else {
                right.push(item);
            }
        } 

        std::future<void> left_res = left.sort_in_background();
        std::future<void> right_res = right.sort_in_background();
        left_res.get();
        while (!left.empty())
            push(left.pop());
        
        push(middle);
        
        right_res.get();
        while (!right.empty())
            push(right.pop());
    }
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


template <class T> std::shared_ptr<T> TQueue<T>::pop()
{
    std::shared_ptr<T> result;
    if (head != nullptr)
    {
        result = head->GetItem();
        head = head->GetNext();
    }
    return result;
}







template <class T> bool TQueue<T>::empty()
{
    return head == nullptr;
}



template <class T> TIterator<TQueueItem<T>, T> TQueue<T>::begin()
{
    return TIterator<TQueueItem<T>, T>(head);
}
template <class T> TIterator<TQueueItem<T>, T> TQueue<T>::end()
{
    return TIterator<TQueueItem<T>, T>(nullptr);
}


template <class T> size_t TQueue<T>::size()
{
    int result = 0;
    for (auto i : *this)
        result++;
    return result;
}



template <class T> TQueue<T>::~TQueue() {}



#include "figure.h"
template class TQueue<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueue<Figure>& queue);

