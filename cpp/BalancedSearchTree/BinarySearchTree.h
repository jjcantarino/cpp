
#include "TreeNode.h"
#include <stdexcept>
using namespace std;
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T>
class BinarySearchTree{
protected:
    TreeNode<T>* root;
    int getSize_aux(TreeNode<T>*);
    int heigth_aux(TreeNode<T>*);
    void insert_aux(TreeNode<T>*, const T&, int, int);
    bool search_aux(TreeNode<T>*, const T&);
    void printPreOrder_aux(TreeNode<T>*);
    void printPostOrder_aux(TreeNode<T>*);
    void printInOrder_aux(TreeNode<T>*);
    void makeEmpty(TreeNode<T>*);
    TreeNode<T>* getNode_aux(TreeNode<T>*, const T&);
public:
    BinarySearchTree();
    ~BinarySearchTree(); 
    bool empty() const; 
    TreeNode<T>* getRoot() const; 
    void insert(const T& key, int numLine, int numMot)
    { insert_aux(getRoot(),key, numLine, numMot); } 
    bool search(const T& key)
    { search_aux(getRoot(), key); } 
    void printPreOrder()
    { printPreOrder_aux(getRoot()); } 
    void printPostOrder()
    { printPostOrder_aux(getRoot()); } 
    void printInOrder()
    { printInOrder_aux(getRoot()); }
    int heigth()
    { return heigth_aux(getRoot()); } 
    int getSize()
    { return getSize_aux(getRoot()); }
    TreeNode<T>* getNode(const T& key)
    { return getNode_aux(getRoot(), key); }
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = nullptr;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree(){
    makeEmpty(root);
}

template <class T>
bool BinarySearchTree<T>::empty() const{
    return getRoot() == nullptr;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::getRoot() const{
    return root;
}

template <class T>
bool BinarySearchTree<T>::search_aux(TreeNode<T>* node, const T& key ){
    if(key == node->getElement())
        return true;
    else if(key < node->getElement())
        return search_aux(node->getLeft(), key);
    else if(key > node->getElement())
        return search_aux(node->getRight(), key);
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::getNode_aux(TreeNode<T>* node, const T& key ){
    if(key == node->getElement())
        return node;
    else if(key < node->getElement())
        getNode_aux(node->getLeft(), key);
    else if(key > node->getElement())
        getNode_aux(node->getRight(), key);
}

template <class T>
int BinarySearchTree<T>::heigth_aux(TreeNode<T>* node){
    if(node == nullptr)
        return -1;
    else
        return (1 + max(heigth_aux(node->getLeft()), heigth_aux(node->getRight())));
}

template <class T>
int BinarySearchTree<T>::getSize_aux(TreeNode<T>* node){
    if(node == nullptr)
        return 0;
    else
        return (1 + getSize_aux(node->getLeft()) + getSize_aux(node->getRight()));
}

template <class T>
void BinarySearchTree<T>::insert_aux(TreeNode<T>* node, const T& key, int numLine, int numMot){

    if(empty()){
        root = new TreeNode<T>(key, numLine, numMot);
    }else{
        if(node->getElement() > key){ 
            if(node->getLeft() == nullptr){
                TreeNode<T>* aux = new TreeNode<T>(key, numLine, numMot);
                node->setLeft(aux);
                aux->setParent(node);
            }else
                insert_aux(node->getLeft(), key, numLine, numMot);
        }else if(node->getElement() < key){
            if(node->getRight() == nullptr){
                TreeNode<T>* aux = new TreeNode<T>(key, numLine, numMot);
                node->setRight(aux);
                aux->setParent(node);
            }else
                insert_aux(node->getRight(), key, numLine, numMot);
        }else
            node->addPosition(numLine, numMot);
    }
}
template <class T>
void BinarySearchTree<T>::printPreOrder_aux(TreeNode<T>* node){
        if(node != nullptr)
            cout << node->getElement() <<" ";
        if(node->getLeft() != nullptr)
            printPreOrder_aux(node->getLeft());
        if(node->getRight() != nullptr)
            printPreOrder_aux(node->getRight());
}
template <class T>
void BinarySearchTree<T>::printPostOrder_aux(TreeNode<T>* node){
    if(node->getLeft() != nullptr)
        printPostOrder_aux(node->getLeft());
    if(node->getRight() != nullptr)
        printPostOrder_aux(node->getRight());
    if(node != nullptr)
        cout << node->getElement() <<" ";
}

template <class T>
void BinarySearchTree<T>::printInOrder_aux(TreeNode<T>* node){
    if(node->getLeft() != nullptr)
        printInOrder_aux(node->getLeft());
    node->getValues();
    if(node->getRight() != nullptr)
        printInOrder_aux(node->getRight());
}

template <class T>
void BinarySearchTree<T>::makeEmpty(TreeNode<T>* node){

    if(node->getLeft() != nullptr)
        makeEmpty(node->getLeft());
    if(node->getRight() != nullptr)
        makeEmpty(node->getRight()); 
    if(node != nullptr){
        delete node;
    }
}

#endif /* BINARYSEARCHTREE_H */
