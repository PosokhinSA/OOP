#include "TQueueItem.h"
#include <iostream>
TQueueItem::TQueueItem(const std::shared_ptr<Rhombus> rhombus) 
{
    this->rhombus = rhombus;
    this->next = nullptr;
    std::cout << "Queue item: created" << std::endl;
}
TQueueItem::TQueueItem(const TQueueItem& orig)
{
    this->rhombus = orig.rhombus;
    this->next = orig.next;
    std::cout << "Queue item: copied" << std::endl;
}
std::shared_ptr<TQueueItem> TQueueItem::SetNext(std::shared_ptr<TQueueItem> next) 
{
    std::shared_ptr<TQueueItem> old = this->next;
    this->next = next;
    return old;
}
std::shared_ptr<Rhombus> TQueueItem::GetRhombus() const 
{
    return this->rhombus;
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
    os << "[" << *obj.rhombus << "]" << std::endl;
    return os;
}
