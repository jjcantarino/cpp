#ifndef LINKEDHASHENTRY_H
#define LINKEDHASHENTRY_H
#include <iostream>
using namespace std;

template <class T, class E>
class LinkedHashEntry {
private:
    LinkedHashEntry <T,E> *next;
    T key;
    E numline;
    E numword;
    
public:
    
    ~LinkedHashEntry();
    LinkedHashEntry(const T&, const E&, const E&);
    const T& getKey()const;
    const E& getLine();
    const E& getWord();
    void setValue(const E&, const E&);
    LinkedHashEntry *getNext();
    void setNext(LinkedHashEntry *);
 };
template <class T, class E>
//Constructor
LinkedHashEntry<T,E>::LinkedHashEntry(const T& clave, const E& linia, const E& word){
    next=nullptr;
    key = clave;
    numline = linia;
    numword = word;
}
template <class T, class E>
//Constructor
LinkedHashEntry<T,E>::~LinkedHashEntry(){
    
}
template <class T, class E>
const T& LinkedHashEntry<T,E>::getKey() const{
    return key;
}
template <class T, class E>
const E& LinkedHashEntry<T,E>::getLine(){
    return this->numline;
}
template <class T, class E>
const E& LinkedHashEntry<T,E>::getWord(){
    return this->numword;
}
template <class T, class E>
void LinkedHashEntry<T,E>::setValue(const E& linia, const E& word){
    numline=linia;
    numword=word;
}
template <class T, class E>
LinkedHashEntry<T,E> * LinkedHashEntry<T,E>::getNext(){
    return next;
}
template <class T, class E>
void  LinkedHashEntry<T,E>::setNext(LinkedHashEntry * a){
    this->next=a;
}

#endif /* LINKEDHASHENTRY_H */
