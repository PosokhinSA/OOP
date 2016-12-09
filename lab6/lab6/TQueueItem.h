#pragma once

#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"
#include "TAllocator.h"

#include <memory>
template <class T> class TQueueItem {
public:
//    TQueueItem(std::shared_ptr<Rhombus> rhomb, std::shared_ptr<Trapeze> trapez, std::shared_ptr<Pentagon> pent);
	TQueueItem(const std::shared_ptr<T>& figure);

	template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);

    void SetNext(std::shared_ptr<TQueueItem<T>> &next);
    std::shared_ptr<TQueueItem<T>> GetNext();

	std::shared_ptr<T> GetItem() const;
    void * operator new (size_t size);
    void operator delete(void *p);
	/*    
    std::shared_ptr<Rhombus> GetRhombus() const;
    std::shared_ptr<Pentagon> GetPentagon() const;
	std::shared_ptr<Trapeze> GetTrapeze() const;
*/

    virtual ~TQueueItem();
private:
	/*
    std::shared_ptr<Rhombus> rhombus;
    std::shared_ptr<Trapeze> trapeze;
    std::shared_ptr<Pentagon> pentagon;
    */
	std::shared_ptr<T> item;
	std::shared_ptr<TQueueItem<T>> next;
    
    static TAllocator queueitem_allocator;
};
 /* TQUEUEITEM_H */
