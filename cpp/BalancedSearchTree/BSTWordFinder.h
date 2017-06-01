#include "BinarySearchTree.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <iostream>


#ifndef BSTWORDFINDER_H
#define BSTWORDFINDER_H

class BSTWordFinder{
    BinarySearchTree<string>* tree;
public:
    BSTWordFinder();
    virtual ~BSTWordFinder();
    void appendText(string); 
    void insertWord(string, int, int);
    void findOcurences(string) const; 
    void viewIndex() const;
};

#endif /* BSTWORDFINDER_H */
