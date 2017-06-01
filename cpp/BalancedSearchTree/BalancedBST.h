/* 
 * File:   BalancedBST.h
 * Author: Vitor Carvalho y Jonatan Cantarino
 *
 * Created on 10 de mayo de 2016, 21:59
 */

#ifndef BALANCEDBST_H
#define BALANCEDBST_H

using namespace std;

#include "TreeNodeAVL.h"
#include "BinarySearchTree.h"

template <class T>
class BalancedBST: public BinarySearchTree<T>{
    TreeNodeAVL<T>* rootAVL;
    
    //funciones auxliares para balancear el árbol
    void balanceLeft(TreeNodeAVL<T>*);
    void balanceRight(TreeNodeAVL<T>*);
    
    void balanceNode(TreeNodeAVL<T>*);
    int heigth_aux(TreeNodeAVL<T>*);
    
    void defineHeight(TreeNodeAVL<T>*);
    
    //función auxiliar para insertar un nodo
    void insert_aux(TreeNodeAVL<T>* , const T&, int, int);
    
    void printInOrder_aux(TreeNodeAVL<T>*);
    TreeNodeAVL<T>* getNode_aux(TreeNodeAVL<T>*, const T&);
public:
    BalancedBST();
    ~BalancedBST();
    
    TreeNodeAVL<T>* getRoot() const;
    void setRoot(TreeNodeAVL<T>*);
    bool empty() const;

    int heightAVL()
    { return heigth_aux(this->rootAVL);}
    
    TreeNodeAVL<T>* getNode(const T& key)
    { return this->getNode_aux(this->rootAVL, key); }
    
    void printInOrder()
    {this->printInOrder_aux(this->rootAVL);}
    
    //afegeix un nou node a l’arbre binari de cerca
    void insert(const T& key, int numLine, int numMot)
    {  insert_aux(rootAVL, key, numLine, numMot); } 
};

#endif /* BALANCEDBST_H */

template <class T>
BalancedBST<T>::BalancedBST(){
    this->rootAVL= nullptr;
}

template <class T>
BalancedBST<T>::~BalancedBST(){
    //función para borrar todos los nodos
    BinarySearchTree<T>::makeEmpty(this->rootAVL);
}

template <class T>
TreeNodeAVL<T>* BalancedBST<T>::getRoot() const{
    return this->rootAVL;
}

template <class T>
bool BalancedBST<T>::empty() const{
    return this->rootAVL==nullptr;
}

template <class T>
int BalancedBST<T>::heigth_aux(TreeNodeAVL<T>* node){
    if(node == nullptr)
        return -1;
    else
        return (1 + max(BalancedBST<T>::heigth_aux(node->getLeft()), BalancedBST<T>::heigth_aux(node->getRight())));    
}

/**
 *      A                B
 *     / \              / \
 *        B    ----->  A   C   
 *       / \          / \   
 *          C
 */
template <class T>
void BalancedBST<T>::balanceLeft(TreeNodeAVL<T>* node){
    TreeNodeAVL<T>* aux = node->getRight();
    node->setRight(aux->getLeft());
    
    if(aux->getLeft() != nullptr)
        aux->getLeft()->setParent(node);
    aux->setParent(node->getParent());
    
    if(node->getParent() == nullptr){
        rootAVL = aux;
    }else if(node == node->getParent()->getLeft()){
        node->getParent()->setLeft(aux);

    }else{
        node->getParent()->setRight(aux);
    }
    
    aux->setLeft(node);
    node->setParent(aux);
    node->setHeight(heigth_aux(node));
}

/**
 *      A                B
 *     / \              / \
 *    B     ----->     C   A
 *   / \                  / \
 *  C 
 */
template <class T>
void BalancedBST<T>::balanceRight(TreeNodeAVL<T>* node){
    TreeNodeAVL<T>* aux = node->getLeft();
    node->setLeft(aux->getRight());
    
    if(aux->getRight() != nullptr)
        aux->getRight()->setParent(node);
    aux->setParent(node->getParent());
    
    if(node->getParent() == nullptr){
        rootAVL = aux;
    }else if(node == node->getParent()->getLeft()){
        node->getParent()->setLeft(aux);
        
    }else{
        node->getParent()->setRight(aux);
        
    }
    
    aux->setRight(node);
    node->setParent(aux);
    node->setHeight(heigth_aux(node));
}

/**
 * Se define la altura en los nodos superiores al nuevo nodo
 * y busca por nodos parents que tengan la altura desbalanceada
 * 
 */
template <class T>
void BalancedBST<T>::defineHeight(TreeNodeAVL<T>* node){
    
    if(node != nullptr){
        //Define la altura del nodo
        node->setHeight(BalancedBST<T>::heigth_aux(node));
        //Como puede que la altura del nodo sea incorrecta 
        //balanceamos su altura
        if(node->getHeight() < -2 || node->getHeight() >  2)
            balanceNode(node);
    }
    //Si el nodo tiene padre, se hace el mismo proceso recursivamente
    if(node->getParent() != nullptr)
        defineHeight(node->getParent());
}
 
/**
 * altura del  |  diferencia de altura  | rotación
 *    nodo     |  entre los nodos hijos |
 *----------------------------------------------------
 *    2        |         1 o 0          | left
 *----------------------------------------------------
 *    2        |           -1           | right-left
 * ---------------------------------------------------
 *   -2        |            1           | left-right
 * ---------------------------------------------------
 *   -2        |         -1 o 0         | right
 * ---------------------------------------------------
 */
template <class T>
void BalancedBST<T>::balanceNode(TreeNodeAVL<T>* node){
    int hLeft, hRight;
    //cálculo de las alturas de los hijos del nodo
    hLeft = BalancedBST<T>::heigth_aux(node->getLeft());
    hRight = BalancedBST<T>::heigth_aux(node->getRight());
    /* si 
     *      height nodo izquierdo  >  height nodo derecho+1
       si no si 
     *      height nodo derecho    >  height nodo izquierdo +1      
            */
    if(hLeft > hRight + 1){
        //  altura de los hijos del nodo izquierdo
        int hLR = BalancedBST<T>::heigth_aux(node->getLeft()->getRight());
        int hLL = BalancedBST<T>::heigth_aux(node->getLeft()->getLeft());
       // si 
       //   height nodo derecho  >  height nodo hizquierdo      
        if(hLR > hLL)
            balanceLeft(node->getLeft());
        balanceRight(node);
    }
    if(hRight > hLeft + 1){
        //lo mismo por la derecha
        int hRL = BalancedBST<T>::heigth_aux(node->getRight()->getLeft());
        int hRR = BalancedBST<T>::heigth_aux(node->getRight()->getRight());
        if(hRL > hRR)
            balanceRight(node->getRight());
        balanceLeft(node);
    }
}

template <class T>
void BalancedBST<T>::insert_aux(TreeNodeAVL<T>* node, const T& key, int numLine, int numMot){

    //si el árbol está vacío creamos el nodo root
    if(empty()){
        rootAVL = new TreeNodeAVL<T>(key, numLine, numMot, 0);
    }else{
        if(node->getElement() > key){ 
           
            //si está vacío el nodo izquierdo y la key es más pequeño crea un nodo hijo izquierdo
            if(node->getLeft() == nullptr){
                TreeNodeAVL<T>* aux = new TreeNodeAVL<T>(key, numLine, numMot, 0);
                node->setLeft(aux);
                aux->setParent(node);
                //comprueba las alturas y hace los cambios
                defineHeight(aux);

            }else
                //si ya existe el nodo hijo izquierdo hacemos lo mismo recursivamente 
                insert_aux(node->getLeft(), key, numLine, numMot);
        }else if(node->getElement() < key){
            //idem por la derecha
            if(node->getRight() == nullptr){
                TreeNodeAVL<T>* aux = new TreeNodeAVL<T>(key, numLine, numMot, 0);
                node->setRight(aux);
                aux->setParent(node);

                defineHeight(aux);
            }else
                insert_aux(node->getRight(), key, numLine, numMot);
        }else
            //si la key a insertar es la misma que la de un nodo, se añade una posición más a dicha key
            node->addPosition(numLine, numMot);
    }
}

template <class T>
void BalancedBST<T>::printInOrder_aux(TreeNodeAVL<T>* node){
    //si el nodo izquierdo no es nulo hacemos lo mismo recursivamente con dicho nodo
    if(node->getLeft() != nullptr)
        printInOrder_aux(node->getLeft());
    node->getValues();
    //idem por la derecha
    if(node->getRight() != nullptr)
        printInOrder_aux(node->getRight());
}

template <class T>
TreeNodeAVL<T>* BalancedBST<T>::getNode_aux(TreeNodeAVL<T>* node, const T& key ){
    if(key == node->getElement())
        return node;
    //si tiene hijos hacemos la misma comprobación
    else if(key < node->getElement()){
        if(node->getLeft() != nullptr)
            return getNode_aux(node->getLeft(), key);
        else
            return nullptr;
    }
    else if(key > node->getElement()){
        if(node->getRight() != nullptr)
            return getNode_aux(node->getRight(), key);
        else
            return nullptr;
    }
}