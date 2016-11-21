#include "TQueueItem.h"
#include <iostream>
/*
TQueueItem::TQueueItem(const std::shared_ptr<Rhombus> rhomb, const std::shared_ptr<Trapeze> trapez, const std::shared_ptr<Pentagon> pent) 
{
    this->rhombus = rhomb;
    this->trapeze = trapez;
    this->pentagon = pent;
    this->next = nullptr;
    std::cout << "Queue item: created" << std::endl;
}
*/
template <class T> TQueueItem<T>::TQueueItem(const std::shared_ptr<T>& item) 
{
	this->item = item;
	this->next = nullptr;
	std::cout << "Queue item: created" << std::endl;
}

/*
std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> next) 
{
    std::shared_ptr<TQueueItem> old = this->next;
    this->next = next;
    return old;
}
*/

template <class T> void TQueueItem<T>::SetNext(std::shared_ptr<TQueueItem<T>> &next)
{
	this->next = next;
}

/*
std::shared_ptr<Rhombus> TQueueItem::GetRhombus() const 
{
    return rhombus;
}

std::shared_ptr<Pentagon> TQueueItem::GetPentagon() const
{
	return pentagon;
}

std::shared_ptr<Trapeze> TQueueItem::GetTrapeze() const
{
	return trapeze;
}
*/

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
    std::cout << "Queue item: deleted" << std::endl;
}

/*
std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
    if (obj.rhombus) {
        os << "[" << *obj.rhombus << "]" << std::endl;
    } else if (obj.trapeze) {
        os << "[" << *obj.trapeze << "]" << std::endl;
    } else {
        os << "[" << *obj.pentagon << "]" << std::endl;
    }
    return os;
}
*/

template <class A> std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
	
		os << "[" << *obj.figure << "]" << std::endl;

	return os;
}




