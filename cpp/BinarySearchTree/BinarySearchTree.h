
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include "Position.h"
#include <vector>
using namespace std;
class BinarySearchTree {
private:
    Position* root;
public:
   BinarySearchTree();
   ~BinarySearchTree();
   void destructaux(Position*);
   bool empty()const;
   Position* getroot()const;
   void insert(string,int,int);
   bool search(string)const;
   bool searchaux(string, Position*)const;
   void insertaux(string, Position*,int,int);
   Position* getPosition(string)const;
   Position* getPositionaux(string, Position*)const;
   void printPreorder(Position*);
   void printPostorder();
   void printInorder();
   int height()const;   
};

#endif /* BINARYSEARCHTREE_H */

