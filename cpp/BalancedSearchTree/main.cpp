/* 
 * File:   BalancedBST.h
 * Author: vitor Carvalho y Jonathan Cantarino
 *
 * Created on 10 de mayo de 2016, 21:59
 */
using namespace std;
#include "BalancedTreeWordFinder.h"
#include <time.h>
#include <math.h>
#include <stdio.h>

int main() {
    try{
        BalancedTreeWordFinder* wordFinder = new BalancedTreeWordFinder();
        int op;
        do{
            //system("clear");
            
            cout<<"-------------------------------------------------------------"<<endl;
            cout << "Menu de opciones ";
            cout << "\n 1- Insertar smalltext en arbol";
            cout << "\n 2- Insertar largeText en arbol";
            cout << "\n 3- Buscar ocurrencias del dictionary";
            cout << "\n 4- Insertar y buscar smalltext";
            cout << "\n 5- Inserta y buscar largeText";
            cout << "\n 6- Buscar palabra en el arbol";
            cout << "\n 7- Salir";
            cout << "\n Escoja su opción: "<<endl; 
            cout<<"-------------------------------------------------------------"<<endl;
            cin >> op;
            if(op < 1 || op > 7){
                cout<< "Opción invalida!"<<endl;
                
            }else if(op == 1){
                clock_t t;
                t = clock(); //temps
                
                wordFinder->appendText("smallText.txt");
                wordFinder->viewIndex();
                
                t = clock() - t; //temps total
                cout<<"-------------------------------------------------------------"<<endl;
                //temps per segon
                cout<<"Temps transcorregut: "<<(t,((float)t)/CLOCKS_PER_SEC)<<"seconds"<<endl;
                
            }else if(op == 2){
                clock_t t;
                t = clock(); //temps
                
                wordFinder->appendText("largeText.txt");
                wordFinder->viewIndex();
                
                t = clock() - t; //temps total
                cout<<"-------------------------------------------------------------"<<endl;
                //temps per segon
                cout<<"Temps transcorregut: "<<(t,((float)t)/CLOCKS_PER_SEC)<<"seconds"<<endl;
                
            }else if(op == 3){
                clock_t t;
                t = clock(); //temps
                
                ifstream fe("dictionary.txt"); //open the file
                if(fe != NULL){
                    string line;

                    while(getline(fe, line)){ //es guarda linea por linea
                        wordFinder->findOcurences(line);
                    }
                    fe.close(); //close the file
                }
                t = clock() -t;
                cout<<"-------------------------------------------------------------"<<endl;
                //temps per segon
                cout<<"Temps transcorregut: "<<(t,((float)t)/CLOCKS_PER_SEC)<<"seconds"<<endl;
                
            }else if(op == 4){
                clock_t t;
                t = clock(); //temps
                wordFinder->appendText("smallText.txt");
                ifstream fe("dictionary.txt"); //open the file
                if(fe != NULL){
                    string line;

                    while(getline(fe, line)){ //es guarda linea por linea
                        wordFinder->findOcurences(line);
                    }
                    fe.close(); //close the file
                }
                t = clock() -t;
                cout<<"-------------------------------------------------------------"<<endl;
                //temps per segon
                cout<<"Temps transcorregut: "<<(t,((float)t)/CLOCKS_PER_SEC)<<"seconds"<<endl;
            }else if(op == 5){
                clock_t t;
                t = clock(); //temps
                
                wordFinder->appendText("largeText.txt");
                
                ifstream fe("dictionary.txt"); //open the file
                if(fe != NULL){
                    string line;

                    while(getline(fe, line)){ //es guarda linea por linea
                        wordFinder->findOcurences(line);
                    }
                    fe.close(); //close the file
                }
                
                t = clock() -t;
                cout<<"-------------------------------------------------------------"<<endl;
                //temps per segon
                cout<<"Temps transcorregut: "<<(t,((float)t)/CLOCKS_PER_SEC)<<"seconds"<<endl;
            }else if(op == 6){
                string cercar;
                cout << "Palabra?"<<endl;
                cin >> cercar;
                
                clock_t t;
                t = clock(); //temps
                
                wordFinder->findOcurences(cercar);
                
                cout<<"-------------------------------------------------------------"<<endl;
                //temps per segon
                t = clock() -t;
                cout<<"Temps transcorregut: "<<(t,((float)t)/CLOCKS_PER_SEC)<<"seconds"<<endl;
            } 
        }while(op != 7);
            
        delete wordFinder;
    }catch(exception const& ex){
        cout << "Exception "<<ex.what() <<endl;
    }
    return 0;
}