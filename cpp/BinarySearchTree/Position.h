#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include <vector>
using namespace std;

class Position {
    
    struct again{
        int line;
        int posicio;
        again(int l,int p){this->line=l;this->posicio=p;}
    };
private:
    
    Position *right;
    Position *left;
    Position *parent;
    std::vector<again*> times;
    string element;
    int line;
    
public:
    
    Position(string,int,int);
    ~Position();
    Position* getright()const;
    Position* getleft()const;
    Position* getparent()const;
    void setRight(Position*);
    void setLeft(Position*);
    void setParent(Position*);
    bool root()const;
    bool isExternal()const;
    bool isInternal()const;  
    string getElement()const;
    void setElement(string);
    void getValues()const;
    void addPosition(int, int);
};
#endif /* POSITION_H */

