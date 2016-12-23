#pragma once

#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"
#include "TAllocator.h"

#include <memory>
template <class T> class TQueueItem {
public:
	TQueueItem(T* value);


    std::shared_ptr<T> GetItem();
    std::shared_ptr<TQueueItem<T>> GetNext();

    void SetNext(std::shared_ptr<TQueueItem<T>> next);


    virtual ~TQueueItem();
private:
	
	std::shared_ptr<T> item;
	std::shared_ptr<TQueueItem<T>> next;
    
};
 
