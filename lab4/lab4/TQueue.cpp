#include "TQueue.h"


template <class T> TQueue<T>::TQueue() 
{
	head = nullptr;
	tail = nullptr;
}


template <class A> std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue) 
{
	std::shared_ptr<TQueueItem<A>> item = queue.head;
    
    while(item != nullptr)
	{
        os << *item;
        item = item->GetNext();
    } 
    return os;
}


/*
void TQueue::push(std::shared_ptr<Rhombus> &&rhombus, std::shared_ptr<Trapeze> &&trapeze, std::shared_ptr<Pentagon> &&pentagon) 
{
    std::shared_ptr<TQueueItem> other(new TQueueItem(rhombus, trapeze, pentagon));
	if (head == nullptr) {
		head = other;
		tail = other;
	}
	else {
		tail->SetNext(other);
		tail = other;
	}
    
}
*/
/*
void TQueue::push(std::shared_ptr<Rhombus> &&rhombus)
{
	std::shared_ptr<TQueueItem<Rhombus>> other(new TQueueItem<Rhombus>(rhombus));
	if (head == nullptr) {
		head = other;
		tail = other;
	}
	else {
		tail->SetNext(other);
		tail = other;
	}

}


void TQueue::push(std::shared_ptr<Trapeze> &&trapeze)
{
	std::shared_ptr<TQueueItem<Trapeze>> other(new TQueueItem<Trapeze>(trapeze));
	if (head == nullptr) {
		head = other;
		tail = other;
	}
	else {
		tail->SetNext(other);
		tail = other;
	}

}



void TQueue::push(std::shared_ptr<Rhombus> &&rhombus)
{
std::shared_ptr<TQueueItem> other(new TQueueItem(rhombus));
if (head == nullptr) {
head = other;
tail = other;
}
else {
tail->SetNext(other);
tail = other;
}

}
*/

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

/*
std::shared_ptr<Rhombus> TQueue::top_rhomb()
{
	return head->GetRhombus();
}

std::shared_ptr<Pentagon> TQueue::top_pent()
{
	return head->GetPentagon();
}

std::shared_ptr<Trapeze> TQueue::top_trapez()
{
	return head->GetTrapeze();
}
*/

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

template <class T> TQueue<T>::~TQueue() 
{}
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

