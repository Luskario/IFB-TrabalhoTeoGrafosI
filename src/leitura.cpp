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

Aresta lerArestas(ifstream& arq){

    Aresta dado; 
    arq >> dado.v1 >> dado.v2;
    return dado;
}