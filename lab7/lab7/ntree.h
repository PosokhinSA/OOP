#ifndef NTREE_H
#define NTREE_H
#include "tree_node.h"
#include "TreeIterator.h"

template <class T> class TNTree {
private:
    shared_ptr<TNode <T>> root;
    size_t _size;
    
public:
    TNTree();
   
    size_t size();

    shared_ptr<TNode <T>> Search(shared_ptr<T> sh);
    shared_ptr<TNode <T>> Search_Path(char *path);
    void Insert(shared_ptr<T> sh, char *path, char *who);
    void delete_rec(shared_ptr<TNode <T>> node);
    void Delete(shared_ptr<T> sh);
    void Print(char *path);
    shared_ptr<TNode<T>> Minimum();
    shared_ptr<TNode<T>> Maximum();
    TreeIterator<TNode<T>, T> begin();
    TreeIterator<TNode<T>, T> end();
    virtual ~TNTree();
};

#endif


