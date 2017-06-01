#include "BalancedTreeWordFinder.h"

//Constructor
BalancedTreeWordFinder::BalancedTreeWordFinder(){
    this->treeBalanced = new BalancedBST<string>();
}

//Destructor
BalancedTreeWordFinder::~BalancedTreeWordFinder(){
    delete treeBalanced;
}

void BalancedTreeWordFinder::appendText(string filename){
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
       throw runtime_error("Error file reading");
}

void BalancedTreeWordFinder::insertWord(string key, int numLine, int numMot){
    treeBalanced->insert(key, numLine, numMot);
}

void BalancedTreeWordFinder::findOcurences(string key) const{
    if(treeBalanced->getNode(key) != nullptr)
        treeBalanced->getNode(key)->getValues();
}

void BalancedTreeWordFinder::viewIndex() const{
    treeBalanced->printInOrder();
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"Tree Height: "<< treeBalanced->heightAVL() <<" Size: "<<treeBalanced->getSize() <<endl;
}
