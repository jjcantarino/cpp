#ifndef HASHMAP_H
#define HASHMAP_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "LinkedHashEntry.h"
template <class T>
class HashMap {
public:
    HashMap();
    ~HashMap();
    int getHashCode(const T&);
    void put(const T&,int,int);
    void putAux(LinkedHashEntry<T,int>*, LinkedHashEntry<T,int>*);
    bool get(T&);
    bool getAux(T&,LinkedHashEntry<T,int>*) ;
    LinkedHashEntry<T,int>* getPos(int);
private:
    bool exists;
    int contador;
    std::vector<LinkedHashEntry<T,int>*>v;
};

template <class T>
//Constructor
HashMap<T>::HashMap(){
    this->contador=0;
    v.resize(1000,__null);
}

template <class T>
//Destructor
HashMap<T>::~HashMap(){
    int i=0;
    while(i<v.size()){
        delete v[i];
        i++;
    }
}
template <class T>
//Inserta o Actualitza la key amb els valors (línia i paraula) al mapa
void HashMap<T>::put(const T& key, int linia, int paraula){
    LinkedHashEntry <T,int>* lhe=new LinkedHashEntry<T,int>(key,linia,paraula);
    int where=getHashCode( key);
    if(v[where]!=__null){
        if(v[where]->getNext()!=__null)
            putAux(lhe,v[where]->getNext());
        else
            v[where]->setNext(lhe);
    }
    else
       v[where]=lhe;
}
template <class T>
//Inserta o Actualitza la key amb els valors (línia i paraula) al mapa
void HashMap<T>::putAux(LinkedHashEntry <T,int> *lhe, LinkedHashEntry <T,int> *aux){
    if(aux->getNext()!=nullptr)
        putAux(lhe,aux->getNext());
    else
        aux->setNext(lhe);
}
template <class T>
//Retorna cert si és al mapa una key, fals en cas contrari
bool HashMap<T>::get(T& key){
    exists=false;
    int hash=getHashCode(key);
    if(v[hash]->getKey()==key){
        cout<<endl;
        cout<<key;
        cout<<"["<<v[hash]->getLine()<<","<<v[hash]->getWord()<<"]";        
        exists=true;
    }if(v[hash]->getNext()!=__null){
        return getAux(key,v[hash]->getNext());
    }else
        return exists;
}
template <class T>
bool HashMap<T>::getAux(T& key,LinkedHashEntry<T,int>* aux){    
    if(aux->getKey()==key){
        if(!exists){
            cout<<endl;
            cout<<key;
        }
        cout<<"["<<aux->getLine()<<","<<aux->getWord()<<"]";        
        exists=true;
    }if(aux->getNext()!=__null){
        return getAux(key,aux->getNext());
    }else
        return exists;
}
template <class T>
int HashMap<T>::getHashCode(const T& key) {
    int hash=7;
    for(int i = 0; i<key.size();i++){                       
        hash=(hash*31 + key.at(i))%17;
    }
    return hash;
}
template <class T>
LinkedHashEntry<T,int>* HashMap<T>::getPos(int where) {
    return v[where];
}
#endif	// HASHMAP_H