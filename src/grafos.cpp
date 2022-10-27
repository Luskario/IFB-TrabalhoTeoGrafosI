#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.h"
#include "./libs/leitura.h"

using namespace std;

int cout_graus(vector <Aresta> &arestas, int vertice){
    int graus, i;

    for(i=0; i<arestas.size(); i++){
        if (arestas[i].v1 == vertice || arestas[i].v2 == vertice){
            graus++;
        }
    }

    return graus;
}

void matrix_adjacente(vector <Aresta> &arestas, int &matrix){}