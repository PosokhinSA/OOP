#include "TQueueItem.h"
#include <iostream>
#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"
#include <new>



template <class T> TQueueItem<T>::TQueueItem(T* value) 
{
	this->item = std::shared_ptr<T> (value); 
	this->next = nullptr;
	std::cout << "Queue item: created" << std::endl;
}

//template <class T> TAllocator TQueueItem<T>::queueitem_allocator(sizeof(TQueueItem<T>), 100);


template <class T> std::shared_ptr<T> TQueueItem<T>::GetItem() 
{
    return item;
}

template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext()
{
    return this->next;
}

template <class T> void TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> next)
{
	this->next = next;
}





template <class T> TQueueItem<T>::~TQueueItem() 
{
    std::cout << "Queue item: deleted" << std::endl;
}


/*
template <class T> void * TQueueItem<T>::operator new(size_t size) 
{ 
    return queueitem_allocator.allocate(); 
}
template <class T> void TQueueItem<T>::operator delete(void* p) 
{
    queueitem_allocator.deallocate(p);
}
*/

#include "ntree.h"
template class TQueueItem<TNTree<Figure>>;
//template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>& queue);


