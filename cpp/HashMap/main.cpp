#include <cstdlib>
#include <string>
#include <iostream>
#include "HashMap.h"
#include "HashMapWordFinder.h"

using namespace std;

int main(int argc, char** argv) {    
    int all=0;
    HashMapWordFinder* hmwf= new HashMapWordFinder();
    hmwf->appendText("C:\\Users\\JonatanJoaquin\\Documents\\NetBeansProjects\\Ex1_P423\\smallText.txt");
    ifstream fe("C:\\Users\\JonatanJoaquin\\Documents\\NetBeansProjects\\Ex1_P423\\dictionary.txt"); 
    string line;
    int i = 1;
    while(getline(fe, line)){
        hmwf->findOcurences(line);  
        all++;
        i++;
    }
    fe.close();
    cout<<endl<<"Total matches: "<<all<<endl;
    delete hmwf;
    return 0;
}
