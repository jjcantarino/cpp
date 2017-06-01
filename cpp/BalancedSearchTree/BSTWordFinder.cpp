#include "BSTWordFinder.h"

//Constructor
BSTWordFinder::BSTWordFinder(){
    tree = new BinarySearchTree<string>();
}

//Destructor
BSTWordFinder::~BSTWordFinder(){
    delete tree;
}


void BSTWordFinder::appendText(string filename){
    ifstream fe(filename);
    if(fe != NULL){
        string line;
        string word;
        int i = 1, j = 1;
        while(getline(fe, line)){ 
            istringstream linea(line); 
            while (linea) {
                linea >> word;
                for (int l=0; word[l]; l++) {
                    word[l] = tolower(word[l]);
                    if(ispunct(word[l])){
                        word[l] = 0;
                    }
                }
                this->insertWord(word, i, j);
                j++;
            }
            i++;
            j = 1;
        }
        fe.close();
        
    }else
       throw runtime_error("Error reading file");
}

void BSTWordFinder::findOcurences(string key) const{
    if(tree->getNode(key) != nullptr)
        tree->getNode(key)->getValues();
}

void BSTWordFinder::insertWord(string key, int numLine, int numMot){
    tree->insert(key, numLine, numMot);
}

void BSTWordFinder::viewIndex() const{
    tree->printInOrder();
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Tree height: "<<tree->heigth()<<" Size: "<<tree->getSize() <<endl;
}
