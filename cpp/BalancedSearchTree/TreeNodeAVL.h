    
#ifndef TREENODEAVL_H
#define TREENODEAVL_H

using namespace std;
#include <iostream>
#include "TreeNode.h"

template <class T>
class TreeNodeAVL: public TreeNode<T> {   
    TreeNodeAVL<T>* parent;
    TreeNodeAVL<T>* right;
    TreeNodeAVL<T>* left;
    int height;
public:
    TreeNodeAVL(const T& key, int, int, int);
    TreeNodeAVL<T>* getRight() const;
    TreeNodeAVL<T>* getLeft() const; 
    TreeNodeAVL<T>* getParent() const; 
    void setRight(TreeNodeAVL<T>*);
    void setLeft(TreeNodeAVL<T>*);
    void setParent(TreeNodeAVL<T>*);

    void setHeight(int);
    int getHeight() const;
};

#endif 
template <class T>
TreeNodeAVL<T>::TreeNodeAVL(const T& key, int numLine, int numMot, int height): TreeNode<T>(key, numLine, numMot){
    this->height = height;
    this->right = nullptr;
    this->left = nullptr;
}


template <class T>
void TreeNodeAVL<T>::setHeight(int height){
    this->height = height;
}

template <class T>
void TreeNodeAVL<T>::setParent(TreeNodeAVL<T>* parent){
    this->parent = parent;
}

template <class T>
void TreeNodeAVL<T>::setRight(TreeNodeAVL<T>* right){
    this->right = right;
}

template <class T>
void TreeNodeAVL<T>::setLeft(TreeNodeAVL<T>* left){
    this->left = left;
}

template <class T>
int TreeNodeAVL<T>::getHeight() const{
    return this->height;
}

template <class T>
TreeNodeAVL<T>* TreeNodeAVL<T>::getLeft() const{
    return this->left;
}

template <class T>
TreeNodeAVL<T>* TreeNodeAVL<T>::getParent() const{
    return parent;
}

template <class T>
TreeNodeAVL<T>* TreeNodeAVL<T>::getRight() const{
    return this->right;
}
