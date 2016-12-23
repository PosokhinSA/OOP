#include "TQueue.h"


template <class T, class TT> TQueue<T, TT>::TQueue()
{
    head = nullptr;
    tail = nullptr;

}


template <class T, class TT> void TQueue<T, TT>::RemoveSubItemByValue(double value) {
    for (auto i : *this) { // this - queue, i - TNTree<Figure>
        for (TreeIterator<TNode<TT>, TT> it = i->begin(), end = i->end(); it != end; ++it) { 
            if (it->Square() < value) {
                std::cout << "Deleting figure" << std::endl;
                i->Delete(*it);
            }
        }
    }
}

template <class T, class TT> void TQueue<T, TT>::InsertSubItem(TT* value) {
    bool inserted = false;
    size_t queue_elem_cnt = 0;
    if (head != nullptr) {
        for (auto i : *this) {
            if (i->size() < 5) {
                std::shared_ptr<TT> figure = std::shared_ptr<TT>(value);
                if (i->size() == 1) {
                    i->Insert(figure, "r", "s");
                }
                else if (i->size() == 2) {
                    i->Insert(figure, "rs", "b");
                }
                else if (i->size() == 3) {
                    i->Insert(figure, "rsb", "b");
                }
                else if (i->size() == 4) {
                    i->Insert(figure, "rsbb", "b");
                }
                std::cout << "Queue: Adding Element in queue elem # " << queue_elem_cnt << " Tree elem #" << i->size() << std::endl;
                inserted = true;
            }
            queue_elem_cnt++;
        }
    }

    if (!inserted) {
        std::cout << "Queue: New element created" << std::endl;
        T* t_value = new T();
        std::shared_ptr<TT> figure = std::shared_ptr<TT>(value);
        t_value->Insert(figure, "r", "r");
        std::cout << "Queue: Adding Element in queue elem #" << queue_elem_cnt << " Tree elem #" << t_value->size() << std::endl;
    //    t_value->Insert();
        Push(t_value);
    }
}

template <class T, class TT> void TQueue<T, TT>::Push(T* value) {
    std::shared_ptr<TQueueItem<T>> value_item(new TQueueItem<T>(value));
    std::cout << "Queue: Added to queue" << std::endl;
    if (head == nullptr) {
        head = value_item;
        tail = value_item;
    }
    else {
        tail->SetNext(value_item);
        tail = value_item;
    }

}

template <class T, class TT> size_t TQueue<T, TT>::Size() {
    size_t result = 0;
    for (auto a : *this) {
        result++;
    }
    return result;
}

template <class T, class TT> TIterator<TQueueItem<T>, T> TQueue<T, TT>::begin()
{
    return TIterator<TQueueItem<T>, T>(head);
}
template <class T, class TT> TIterator<TQueueItem<T>, T> TQueue<T, TT>::end()
{
    return TIterator<TQueueItem<T>, T>(nullptr);
}


template <class T, class TT> TQueue<T, TT>::~TQueue() {
    std::cout << "Queue: deleted" << std::endl;
}


#include "ntree.h"
template class TQueue<TNTree<Figure>, Figure>;
