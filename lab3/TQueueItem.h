#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H
#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"
#include <memory>
class TQueueItem {
public:
    TQueueItem(std::shared_ptr<Rhombus> rhomb, std::shared_ptr<Trapeze> trapez, std::shared_ptr<Pentagon> pent);
//    TQueueItem(const TQueueItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

   
    std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem> next);
    std::shared_ptr<TQueueItem> GetNext();
    
    std::shared_ptr<Rhombus> GetRhombus() const;
    std::shared_ptr<Pentagon> GetPentagon() const;
	std::shared_ptr<Trapeze> GetTrapeze() const;


    virtual ~TQueueItem();
private:
    std::shared_ptr<Rhombus> rhombus;
    std::shared_ptr<Trapeze> trapeze;
    std::shared_ptr<Pentagon> pentagon;
    std::shared_ptr<TQueueItem> next;
};
#endif /* TQUEUEITEM_H */
