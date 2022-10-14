#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/leitura.h"

using namespace std;

struct aresta
{
    int v1;
    int v2;
};

typedef struct aresta Aresta;

int lerDado(ifstream& arq){

    int dado;
    arq >> dado;
    return dado;

}

void lerArestas(ifstream& arq, vector <Aresta> arestas){

    
}