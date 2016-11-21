#include "TQueueItem.h"
#include <iostream>
TQueueItem::TQueueItem(const std::shared_ptr<Rhombus> rhomb, const std::shared_ptr<Trapeze> trapez, const std::shared_ptr<Pentagon> pent) 
{
    this->rhombus = rhomb;
    this->trapeze = trapez;
    this->pentagon = pent;
    this->next = nullptr;
    std::cout << "Queue item: created" << std::endl;
}
/*
TQueueItem::TQueueItem(const TQueueItem& orig)
{
    this->rhombus = orig.rhombus;
    this->next = orig.next;
    std::cout << "Queue item: copied" << std::endl;
}
*/

std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> next) 
{
    std::shared_ptr<TQueueItem> old = this->next;
    this->next = next;
    return old;
}
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





std::shared_ptr<TQueueItem> TQueueItem::GetNext() 
{
    return this->next;
}

TQueueItem::~TQueueItem() 
{
    std::cout << "Queue item: deleted" << std::endl;
}

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







