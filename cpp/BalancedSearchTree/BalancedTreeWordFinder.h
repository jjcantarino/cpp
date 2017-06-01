
#ifndef BALANCEDTREEWORDFINDER_H
#define BALANCEDTREEWORDFINDER_H
#include <iostream>
#include <string>
#include "BalancedBST.h"
#include "BSTWordFinder.h"

class BalancedTreeWordFinder: public BSTWordFinder{
    BalancedBST<string>* treeBalanced;
public:
    BalancedTreeWordFinder();
    ~BalancedTreeWordFinder();
    
    void insertWord(string, int, int); 
                         
    void appendText(string);
    void findOcurences(string) const;
    void viewIndex() const; 
};

#endif /* BALANCEDTREEWORDFINDER_H */
