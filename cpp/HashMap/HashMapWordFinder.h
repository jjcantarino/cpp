#ifndef HASHMAPWORDFINDER_H
#define HASHMAPWORDFINDER_H

#include "LinkedHashEntry.h"
#include "HashMap.h"
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <sstream>
#include <iostream>

class HashMapWordFinder{
private:
    HashMap<string>* arrayPos;
    int hit;
public:
    HashMapWordFinder();
    virtual ~HashMapWordFinder();
    void appendText(string);  
    void insertWord(string, int, int);
    void findOcurences(string);
    void viewIndex(); 
};
#endif 
