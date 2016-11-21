#include "TQueueItem.h"
#include <iostream>
#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"

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
/*
template <class A> std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
	
		os << "[" << *obj.item << "]" << std::endl;

	return os;
}
*/
template <class A> std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj) {
	
	std::shared_ptr<A> figure = obj.item;
	figure->Print();
	

	return os;
}



/*
#include "rhombus.h"
template class TQueueItem<Rhombus>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Rhombus>&	stack);

#include "trapeze.h"
template class TQueueItem<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Trapeze>&	stack);
#include "pentagon.h"
template class TQueueItem<Pentagon>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Pentagon>&	stack);
*/

#include "figure.h"
template class TQueueItem<Figure>;
template std::ostream& operator<<(std::ostream& os, const TQueueItem<Figure>& queue);


