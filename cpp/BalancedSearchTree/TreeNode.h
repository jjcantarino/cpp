/** 
 * File:   BinarySearchTree.h
 * Author: vitor Carvalho y jonatan Cantarino
 * Created on 21 / abril / 2016, 08:04
 */
using namespace std;
#include <iostream>
#include <vector>
#ifndef POSITION_H
#define POSITION_H
struct Word{
    int numLine;
    int numMot; 
    Word(int r, int i){ numLine = r, numMot = i;}
};

template <class T>
class TreeNode {
    T key; 
    int count;
    vector<Word> keyValues;
    TreeNode<T>* parent;
    TreeNode<T>* right;
    TreeNode<T>* left;
public:
    TreeNode(const T& key, int, int); 
    TreeNode<T>* getRight() const; 
    TreeNode<T>* getLeft() const;
    TreeNode<T>* getParent() const;
    void addPosition(int, int);
    void setRight(TreeNode<T>*);
    void setLeft(TreeNode<T>*); 
    void setParent(TreeNode<T>*); 
    bool isRoot() const; 
    bool isExternal() const;
    bool isInternal() const;
    const T& getElement() const; 
    void getValues() const;
};

template <class T>
TreeNode<T>::TreeNode(const T& key, int numLine, int numMot){
    this->key = key;
    count = 0;
    this->right = nullptr;
    this->left = nullptr;
    parent = nullptr;
    Word word(numLine, numMot);
    keyValues.push_back(word);
}

template <class T>
const T& TreeNode<T>::getElement() const{
    return this->key;
}

template <class T>
bool TreeNode<T>::isExternal() const{
    return (right == nullptr && left == nullptr);
}

template <class T>
bool TreeNode<T>::isInternal() const{
    return (!isRoot() && !isExternal());
}

template <class T>
bool TreeNode<T>::isRoot() const{
    return getParent() == nullptr;
}

template <class T>
TreeNode<T>* TreeNode<T>::getLeft() const{
    return this->left;
}

template <class T>
TreeNode<T>* TreeNode<T>::getParent() const{
    return parent;
}

template <class T>
TreeNode<T>* TreeNode<T>::getRight() const{
    return this->right;
}
template <class T>
void TreeNode<T>::getValues() const{
    int i = 0;
    cout << getElement()<<" [";
    while(i <= count){
        if(i == count){
            cout << "("<< keyValues[i].numLine
                 <<", " << keyValues[i].numMot <<")";
            i++;
        }else{
            cout << "("<< keyValues[i].numLine
                 <<", " << keyValues[i].numMot <<"),";
            i++;
        }
    }
    cout<< "]"<<endl;
}

template <class T>
void TreeNode<T>::setParent(TreeNode<T>* parent){
    this->parent = parent;
}
template <class T>
void TreeNode<T>::setRight(TreeNode<T>* right){
    this->right = right;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode<T>* left){
    this->left = left;
}
template <class T>
void TreeNode<T>::addPosition(int numLin, int numMo){
    count++;
    Word word1(numLin, numMo);
    keyValues.push_back(word1);
}

#endif /* POSITION_H */
