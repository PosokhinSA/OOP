#pragma once

#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"
#include <memory>
template <class T> class TQueueItem {
public:
	TQueueItem(const std::shared_ptr<T>& figure);

	template <class A> friend std::ostream& operator<<(std::ostream& os, const TQueueItem<A>& obj);

    void SetNext(std::shared_ptr<TQueueItem<T>> next);
    std::shared_ptr<TQueueItem<T>> GetNext();

	std::shared_ptr<T> GetItem() const;


    virtual ~TQueueItem();
private:
	
	std::shared_ptr<T> item;
	std::shared_ptr<TQueueItem<T>> next;
};
 /* TQUEUEITEM_H */
