#include "TQueue.h"

TQueue::TQueue() 
{
	head = nullptr;
	tail = nullptr;
}


template <class T> std::ostream& operator<<(std::ostream& os, const TQueue& queue) 
{
	std::shared_ptr<TQueueItem<T>> item = queue.head;
    
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

template <class T> void push(std::shared_ptr<T> figure)
{
	std::shared_ptr<TQueueItem<T>> other(new TQueueItem<T>(figure));
	if (head == nullptr) {
		head = new TQueueItem<T>;
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

template <class T> std::shared_ptr<T> TQueue::top()
{
	return head->GetItem();
}


bool TQueue::empty() 
{
	return head == nullptr;
}

template <class T> void TQueue::pop() 
{
    if (head != nullptr) {
        head = head->GetNext();
	}
}

TQueue::~TQueue() 
{}
