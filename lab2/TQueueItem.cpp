#include "TQueueItem.h"
#include <iostream>
TQueueItem::TQueueItem(const Rhombus& rhombus) 
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
TQueueItem* TQueueItem::SetNext(TQueueItem* next) 
{
    TQueueItem* old = this->next;
    this->next = next;
    return old;
}
Rhombus TQueueItem::GetRhombus() const 
{
    return this->rhombus;
}
TQueueItem* TQueueItem::GetNext() 
{
    return this->next;
}
TQueueItem::~TQueueItem() 
{
    std::cout << "Queue item: deleted" << std::endl;
    delete next;
}
std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
    os << "[" << obj.rhombus << "]" << std::endl;
    return os;
}
