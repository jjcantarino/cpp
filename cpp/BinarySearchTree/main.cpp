#include <cstdlib>
#include <iostream>
#include <array>
#include "BinarySearchTree.h"

using namespace std;


int main() {
    BinarySearchTree * bst=new BinarySearchTree();
    int arbreinicial []={50,20,80,10,30,60,90};
    for(int elem: arbreinicial){
        bst->insert(elem);
    }
    bst.Subarbre(20);
    
    return 0;
}