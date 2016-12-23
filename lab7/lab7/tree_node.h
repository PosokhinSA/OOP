#pragma once

#include "rhombus.h"
#include "trapeze.h"
#include "pentagon.h"
#include <cstdlib>
#include <memory>
#include <iostream>
#include <new>


using namespace std;

template <class T> class TNode : enable_shared_from_this<TNode<T>> {
private:
	shared_ptr<TNode<T>> brother;
	shared_ptr<TNode<T>> son;
	shared_ptr<TNode<T>> parent;
	shared_ptr<T> shape;

public:
	TNode();
	TNode(shared_ptr<T> shape);
	void SetBrother(shared_ptr<TNode<T>> node);
	void SetSon(shared_ptr<TNode<T>> node);
	void SetParent(shared_ptr<TNode<T>> node);
//	void SetShape(shared_ptr<T> shape);
	shared_ptr<TNode<T>> Son();
	shared_ptr<TNode<T>> Brother();
	shared_ptr<TNode<T>> Parent();
	shared_ptr<T> GetShape();
	double GetValue();
	bool operator == (shared_ptr<TNode<T>> &right);
	TNode<T> &operator = (shared_ptr<TNode<T>> &right);
	int Son_qty();
	shared_ptr<TNode<T>> search_rec(shared_ptr<T> sh);
//	void * operator new(size_t size);
//	void operator delete(void *p);
	virtual ~TNode();
};

