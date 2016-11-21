#ifndef TQUEUE_H
#define TQUEUE_H

#include "TQueueItem.h"

#include <memory>

template <class T> class TQueue {
public:
	TQueue();
	//    TQueue(const TQueue& orig);

	//    void push(std::shared_ptr<Rhombus> &&rhombus, std::shared_ptr<Trapeze> &&trapeze, std::shared_ptr<Pentagon> &&pentagon);
	//	void push(std::shared_ptr<Rhombus> &&rhombus);
	//	void push(std::shared_ptr<Trapeze> &&trapeze);
	//	void push(std::shared_ptr<Pentagon> &&pentagon);
	void push(std::shared_ptr<T> figure);

	bool empty();
	/*
	 std::shared_ptr<Rhombus> top_rhomb();
	 std::shared_ptr<Trapeze> top_trapez();
	 std::shared_ptr<Pentagon> top_pent();
   */

	std::shared_ptr<T> top();
	void pop();

	template <class A>  friend std::ostream& operator<<(std::ostream& os, const TQueue<A>& queue);
	virtual ~TQueue();
private:

	std::shared_ptr<TQueueItem<T>> head;
	std::shared_ptr<TQueueItem<T>> tail;
};
#endif /* TQUEUE_H */
