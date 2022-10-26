#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/leitura.h"

using namespace std;

int lerDado(ifstream& arq){

    int dado;
    arq >> dado;
    return dado;
}

void lerArestas(ifstream& arq, vector <Aresta> &arestas){

    Aresta dado; 
    while(!arq.eof()){
        arq >> dado.v1 >> dado.v2;
        arestas.push_back(dado);
    }
    
}