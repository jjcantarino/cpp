#include "BSTWordFinder.h"

BSTWordFinder::BSTWordFinder() {
    arbre = new BinarySearchTree();
}
BSTWordFinder::~BSTWordFinder() {
    delete arbre;
}
void BSTWordFinder::appendText(string filename){ 
  ifstream fe(filename);
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
                insertWord(word, i, j); 
                j++;
            }
            i++;
            j = 1;
        }
        fe.close(); 
}
void BSTWordFinder::insertWord(string text,int a, int b){ 
    arbre->insert(text,a,b);
}
void BSTWordFinder::findOccurences(string text)const{
    if(arbre->search(text)){
        Position* aux=arbre->getPosition(text);
        aux->getValues();
    }
}
void BSTWordFinder::insert(string text){
    
}
void BSTWordFinder::viewIndex(){ 

}
