#include "tree_node.h"


using namespace std;

template <class T> TNode<T>::TNode()
{
    brother = nullptr;
    son = nullptr;
}



template <class T> TNode<T>::TNode(shared_ptr<T> sh)
{
    brother = nullptr;
    son = nullptr;
    parent = nullptr;
    shape = sh;
}
template <class T> void TNode<T>::SetBrother(shared_ptr<TNode <T>> node)
{
    if (this->brother == nullptr) {
        this->brother = node;
    }
    else {
        this->SetBrother(node);
    } 
}
template <class T> void TNode<T>::SetSon(shared_ptr<TNode <T>> node)
{
    if (this->son == nullptr) {
        this->son = node;
    }
    else {
        this->SetBrother(node);
    }
}
template <class T> void TNode<T>::SetParent(shared_ptr<TNode <T>> node)
{
    this->parent = node;
}
template <class T> shared_ptr<TNode<T>> TNode<T>::Son()
{
    return this->son;
}
template <class T> shared_ptr<TNode<T>> TNode<T>::Brother()
{
    return this->brother;
}
template <class T> shared_ptr<TNode<T>> TNode<T>::Parent()
{
    return this->parent;
}
template <class T> shared_ptr<T> TNode<T>::GetShape()
{
    return this->shape;
}
template <class T> double TNode<T>::GetValue()
{
    return this->shape->Square();
}

template <class T> bool TNode<T>::operator == (shared_ptr<TNode<T>> &right)
{
    if (this->shape == right->shape) {
        return true;
    }
    else return false;
}
template <class T> TNode<T> &TNode<T>::operator = (shared_ptr<TNode<T>> &right)
{
    if (shared_from_this() == right) {
        return *this;
    }
    else {
        son = right->son;
        brother = right->brother;
        shape = right->shape;
        return *this;
    }
}
template <class T> int TNode<T>::Son_qty()
{
    int count = 1;
    shared_ptr<TNode<T>> node = this->son;
    while (node->brother != nullptr) {
        count++;
        node = node->brother;
    }
    return count;
}
template <class T> shared_ptr<TNode<T>> TNode<T>::search_rec(shared_ptr<T> sh)
{
    if (!(this->shape == sh)) {
        if (this->son != nullptr) {
            shared_ptr<TNode<T>> tmp = this->Son();
            return tmp->search_rec(sh);
        }
        if (this->brother != nullptr) {
            shared_ptr<TNode<T>> tmp = this->Brother();
            return tmp->search_rec(sh);
        }
    }
    return shared_from_this();
}
template <class T> TNode<T>::~TNode()
{
    son = nullptr;
    brother = nullptr;
}


#include "figure.h"
template class TNode<Figure>;