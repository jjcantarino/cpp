#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(){
    this->root=nullptr;
}
 BinarySearchTree:: ~BinarySearchTree(){
     if(!empty()){
         destructaux(getroot());
     }
}
 void BinarySearchTree::destructaux(Position* aux){
     if(aux->getleft()!=nullptr){
         destructaux(aux->getleft());
     }
     if(aux->getright()!=nullptr){
         destructaux(aux->getright());
     }
     else{
         delete aux;
     }
 }
 
 Position* BinarySearchTree:: getPosition(string key)const{
     if(empty()){
         return nullptr;
     }
     else{
        return getPositionaux(key, getroot());
     }
}
 Position* BinarySearchTree:: getPositionaux(string a, Position* p)const{
    if (p->getElement()>a){
        if(p->getleft()==nullptr){
            return nullptr;
        }
        else{
            return getPositionaux(a,p->getleft());
        }
    }
    else if(p->getElement()<a){
        if(p->getright()==nullptr){
            return nullptr;
        }
        else{
            return  getPositionaux(a,p->getright());
        }
    }
    else{
        return p;
    }
 }

 bool BinarySearchTree::empty()const{
    return root==nullptr;
}
void BinarySearchTree::insert(string a,int l, int p){
    insertaux(a,getroot(),l,p);  
}
Position* BinarySearchTree::getroot()const{
    return root;
}

bool BinarySearchTree::search(string a)const{
    if(empty()){
        return false;
    }
    else{ 
        return searchaux(a,getroot());
    }
}
   void BinarySearchTree::printPreorder(Position* p){
       if(p!=nullptr){
           cout<<p->getElement()<<endl;
       }
       if(p->getleft()!=nullptr){
           printPreorder(p->getleft());
       }
       if(p->getright()!=nullptr){
           printPreorder(p->getright());
       }
       
   }
   void BinarySearchTree::printPostorder(){
       
   }
   void BinarySearchTree::printInorder(){
       
   }
void BinarySearchTree::insertaux(string a, Position*p,int l,int pos){
    if(empty())
        root= new Position(a,l,pos);
    else{
        if(p->getElement()<a){   
            if(p->getright()==nullptr){
                Position* lel= new Position(a,l,pos);
                p->setRight(lel);
                lel->setParent(p);
            }
            else
                insertaux(a,p->getright(),l,pos);
        }
        else if(p->getElement()>a){     
            if(p->getleft()==nullptr){
                Position* lel= new Position(a,l,pos);
                p->setLeft(lel);                
                lel->setParent(p);
            }
            else
                insertaux(a,p->getleft(),l,pos);            
        }
        else{
            p->addPosition(l,pos);
        }
    }
}
bool BinarySearchTree::searchaux(string a, Position* p)const{
    if (p->getElement()>a){
        if(p->getleft()==nullptr){
            return false;
        }
        else{
            return searchaux(a,p->getleft());
        }
    }
    else if(p->getElement()<a){
        if(p->getright()==nullptr){
            return false;
        }
        else{
            return searchaux(a,p->getright());
        }
    }
    else if(p->getElement().compare(a)==0){
        return true;
    }
}

