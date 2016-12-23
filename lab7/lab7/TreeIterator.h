#pragma once


#include <memory>
#include <iostream>

using namespace std;

template <class TNode, class T> class TreeIterator {
public:
    TreeIterator(shared_ptr<TNode> n) //node - is current elem
    {
        node = n;
    }
    shared_ptr<T> operator * () 
    {
        if (node != nullptr) {
            return node->GetShape();
        }
        else return nullptr;
    }
    shared_ptr<T> operator -> () //returns shape from current node
    {
        if (node != nullptr) {
            return node->GetShape();
        }
        else return nullptr;
    }
    void operator ++ () // this operator - walking of the tree. Minimum  - is the deepest son. We are going to the brother and then his minimum. But if brother null, then go to parent
    {
        if (node->Brother()) {
            node = node->Brother();
            if (node->Son()) {
                node = node->Son();
                while (node->Son()) {
                    node = node->Son();
                }
            }
        }
        else if (node->Parent()) {
            node = node->Parent();
        }
    }
    TreeIterator operator ++(int)
    {
        TreeIterator iter(*this);
        ++(*this);
        return iter;
    }
    bool operator == (TreeIterator const i) //comparing
    {
        return this->node == i.node;
    }
    bool operator != (TreeIterator const i)//comparing
    {
        return !(*this == i);
    }
private:
    shared_ptr<TNode> node;
};
