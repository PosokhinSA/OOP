#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H
#include "rhombus.h"
#include <memory>
class TQueueItem {
public:
    TQueueItem(std::shared_ptr<Rhombus> rhombus);
    TQueueItem(const TQueueItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

    std::shared_ptr<TQueueItem> SetNext(std::shared_ptr<TQueueItem> next);
    std::shared_ptr<TQueueItem> GetNext();
    std::shared_ptr<Rhombus> GetRhombus() const;

    virtual ~TQueueItem();
private:
    std::shared_ptr<Rhombus> rhombus;
    std::shared_ptr<TQueueItem> next;
};
#endif /* TQUEUEITEM_H */
