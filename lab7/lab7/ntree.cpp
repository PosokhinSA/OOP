#include "ntree.h"
using namespace std;

template <class T> TNTree<T>::TNTree()
{
    this->root = nullptr;
    this->_size = 0;
  
    std::cout << "[NTree Created]" << std::endl;
}

template <class T> size_t TNTree<T>::size() {
    return this->_size;
}

template <class T> shared_ptr<TNode<T>> TNTree<T>::Search(shared_ptr<T> sh)
{
    if (root->GetShape() == sh) {
        return root;
    }
    else {
        return root->search_rec(sh);
    }
}
template <class T> shared_ptr<TNode<T>> TNTree<T>::Search_Path(char *path)
{
    shared_ptr<TNode<T>> NodePath = nullptr;
    shared_ptr<TNode<T>> prev = nullptr;
    while (*path != '\0') {
        if (*path == 'r') {
            NodePath = this->root;
            prev = nullptr;
            path++;
            continue;
        }
        if (*path == 's') {
            prev = NodePath;
            NodePath = NodePath->Son();
            path++;
            continue;
        }
        if (*path == 'b') {
            prev = NodePath;
            NodePath = NodePath->Brother();
            path++;
            continue;
        }
    }
    return NodePath;
}
template <class T> void TNTree<T>::Insert(shared_ptr<T> sh, char *path, char *who)
{
    shared_ptr<TNode<T>> nd(new TNode<T>(sh));
    if ((this->root == nullptr)) {
        this->root = nd;
    }
    else {
        shared_ptr<TNode<T>> Nodepath = Search_Path(path);
        if (*who == 's') {
            Nodepath->SetSon(nd);
            nd->SetParent(Nodepath);
        }
        if (*who == 'b') {
            if (Nodepath == root) {
                cout << "ROOT CAN'T HAVE BROTHERS" << endl;
            }
            else {
                Nodepath->SetBrother(nd);
                nd->SetParent(Nodepath->Parent());
            }
        }
    }
    this->_size++;
}
template <class T> void TNTree<T>::delete_rec(shared_ptr<TNode <T>> node)
{
    if (node->Brother() != nullptr) {
        delete_rec(node->Brother());
    }
    if (node->Son() != nullptr) {
        delete_rec(node->Son());
    }
    node = nullptr;
}
template <class T> void TNTree<T>::Delete(shared_ptr<T> sh)
{
    shared_ptr<TNode <T>> deleting = this->Search(sh);
    delete_rec(deleting);
    this->_size--;
}
template <class T> void TNTree<T>::Print(char *path)
{
    shared_ptr<TNode<T>> Path = this->Search_Path(path);
    shared_ptr<Figure> shape = Path->GetShape();
    *path++;
    cout << "/" << path;
    shape->Print();
}
template <class T> shared_ptr<TNode<T>> TNTree<T>::Minimum() //minimum is the deepest son
{
    shared_ptr<TNode<T>> node = this->root;
    while (node->Son()) {
        node = node->Son();
    }
    return node;
}
template <class T> shared_ptr<TNode<T>> TNTree<T>::Maximum() //maximum is the root
{
    return this->root;
}
template <class T> TreeIterator<TNode<T>, T> TNTree<T>::begin() //begin == minimum
{
    return TreeIterator<TNode<T>, T>(this->Minimum());
}
template <class T> TreeIterator<TNode<T>, T> TNTree<T>::end() // end is the maximum is the root
{
    return TreeIterator<TNode<T>, T>(this->Maximum());
}

template <class T> TNTree<T>::~TNTree()
{
    this->delete_rec(root);
}

#include "figure.h"
template class TNTree<Figure>;
