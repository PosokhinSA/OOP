#pragma once

#include <memory>
#include <iostream>


template <class Node, class T> class TIterator
{
public:
    TIterator(std::shared_ptr<Node> node) {
        node_ptr = node;
    }

    std::shared_ptr<T> operator *() {
        return node_ptr->GetItem();
    }

    std::shared_ptr<T> operator ->() {
        return node_ptr->GetItem();
    }

    void operator ++() {
        node_ptr = node_ptr->GetNext();
    }

    TIterator operator ++(int)
    {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator ==(TIterator const& i) {
        return node_ptr == i.node_ptr;
    }

    bool operator !=(TIterator const& i) {
        return !(*this == i);
    }

private:
    std::shared_ptr<Node> node_ptr;
};