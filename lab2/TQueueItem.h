#ifndef TQUEUEITEM_H
#define TQUEUEITEM_H
#include "rhombus.h"
class TQueueItem {
public:
    TQueueItem(const Rhombus& rhombus);
    TQueueItem(const TQueueItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

    TQueueItem* SetNext(TQueueItem* next);
    TQueueItem* GetNext();

    Rhombus GetRhombus() const;

    virtual ~TQueueItem();
private:
    Rhombus rhombus;
    TQueueItem *next;
};
#endif /* TQUEUEITEM_H */
