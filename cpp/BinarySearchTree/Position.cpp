
#include "Position.h"
#include <cstdlib>
#include <iostream>

Position::Position(string elem,int l, int p) {   
    this->element=elem;
    this->parent=nullptr;
    this->left=nullptr;
    this->right=nullptr;
    again* ag= new again(l,p);
    times.assign(1,ag);
}
Position::~Position() {
}
Position* Position::getright() const{
    return this->right;
}
Position* Position::getleft() const{
    return this->left;
}
Position* Position::getparent() const{
    return this->parent;
}
void Position::addPosition(int l, int p){
    again* ag= new again(l,p);
    times.push_back(ag);
}
void Position::setRight(Position* ri){
    this->right=ri;
}
void Position::setLeft(Position* le){
    this->left=le;
}
void Position::setParent(Position* pa){
    this->parent=pa;
}
bool Position::root()const{
    return parent==nullptr;
}
bool Position::isExternal()const{
    return left==nullptr&&right==nullptr;
}
bool Position::isInternal()const{
    return left!=nullptr&&right!=nullptr;
}
string Position::getElement()const{
    return this->element;
}
void Position::setElement(string el){
    this->element=el;
}

void Position::getValues() const{
    cout<<getElement();
    int i=0;
    while (i<times.size()){
        if(i>0)
            cout<<',';
        cout<<'[';
        cout<<times.at(i)->line;
        cout<<',';
        cout<<times.at(i)->posicio;
        cout<<']';
        i++;
    }
    cout<<endl;
};