#include "HashMapWordFinder.h"

HashMapWordFinder::HashMapWordFinder(){
    this->hit=0;
    arrayPos = new HashMap<string>();
}

HashMapWordFinder::~HashMapWordFinder(){
    cout<<"Hits: "<<hit<<endl;
    delete arrayPos;
}


void HashMapWordFinder::appendText(string filename){
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
                this->insertWord(word, i, j);
                j++;
            }
            i++;
            j = 1;
        }
        fe.close();
}

void HashMapWordFinder::findOcurences(string key){
    if(arrayPos->get(key)){
        hit=hit+1;
    }
}
void HashMapWordFinder::insertWord(string key, int numLine, int numMot){
    arrayPos->put(key, numLine, numMot);
}

void HashMapWordFinder::viewIndex(){
}
