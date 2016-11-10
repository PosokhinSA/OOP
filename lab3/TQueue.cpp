#include "TQueue.h"
TQueue::TQueue() 
{
	head = nullptr;
	tail = nullptr;
}
/*
TQueue::TQueue(const TQueue& orig) 
{
	head = orig.head;
	tail = orig.tail;
}
*/
std::ostream& operator<<(std::ostream& os, const TQueue& queue) 
{
	std::shared_ptr<TQueueItem> item = queue.head;
    
    while(item != nullptr)
	{
        os << *item;
        item = item->GetNext();
    } 
    return os;
}
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



bool TQueue::empty() 
{
	return head == nullptr;
}
void TQueue::pop() 
{
    if (head != nullptr) {
        head = head->GetNext();
	}
}
TQueue::~TQueue() 
{
}
