#ifndef BSTWORDFINDER_H
#define BSTWORDFINDER_H
#include "BinarySearchTree.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <iostream>

using namespace std;

class BSTWordFinder {
    
private:
    
    BinarySearchTree * arbre;
    
public:
   BSTWordFinder();
   ~BSTWordFinder();
   void appendText(string);
   void insertWord(string,int,int);;
   void findOccurences(string)const;
   void insert(string);
   void viewIndex();
   
};
#endif /* BSTWORDFINDER_H */

