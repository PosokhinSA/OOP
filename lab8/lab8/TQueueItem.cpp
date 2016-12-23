#include "TQueueItem.h"
#include <iostream>
#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"

template <class T> TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& item) 
{
	this->item = item;
	this->next = nullptr;
//	std::cout << "Queue item: created" << std::endl;
}


template <class T> void TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> next)
{
	this->next = next;
}

template <class T> std::shared_ptr<T> TQueueItem<T>::GetItem() const
{
	return item;
}


template <class T> std::shared_ptr<TQueueItem<T>> TQueueItem<T>::GetNext() 
{
    return this->next;
}

template <class T> TQueueItem<T>::~TQueueItem() 
{
//    std::cout << "Queue item: deleted" << std::endl;
}

template <class A> std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
	
	std::shared_ptr<A> figure = obj.item;
	figure->Print();
    std::cout << std::endl;

	return os;
}

#include "figure.h"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>& queue);


