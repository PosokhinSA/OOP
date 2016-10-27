#include "TQueue.h"
TQueue::TQueue() 
{
	head = nullptr;
	tail = nullptr;
}
TQueue::TQueue(const TQueue& orig) 
{
	head = orig.head;
	tail = orig.tail;
}
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
bool TQueue::empty() 
{
	return head == nullptr;
}
std::shared_ptr<Rhombus> TQueue::pop() 
{
    std::shared_ptr<Rhombus> result;
    if (head != nullptr) {
        std::shared_ptr<TQueueItem> old_head = head;
        head = head->GetNext();
        result = old_head->GetRhombus();
        old_head->SetNext(nullptr);
	}
	return result;
}
TQueue::~TQueue() 
{
}
