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
	TQueueItem *item = queue.head;
    
    while(item != nullptr)
	{
        os << *item;
        item = item->GetNext();
    } 
    return os;
}
void TQueue::push(Rhombus&& rhombus) 
{
    TQueueItem *other = new TQueueItem(rhombus);
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
Rhombus TQueue::pop() 
{
    Rhombus result;
    if (head != nullptr) {
        TQueueItem *old_head = head;
        head = head->GetNext();
        result = old_head->GetRhombus();
        old_head->SetNext(nullptr);
        delete old_head;
	}
	return result;
}
TQueue::~TQueue() 
{
    if (head != nullptr) {
	    delete head;
	}

}
