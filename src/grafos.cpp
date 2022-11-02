#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.h"
#include "./libs/leitura.h"

using namespace std;

void cout_graus(Grafo &grafo){
    int i;
    
    for(i=0; i<grafo.n_vertices; i++){
        grafo.graus.push_back(0);
    }

    for(i=0; i<grafo.n_arestas; i++){
        grafo.graus[grafo.arestas[i].v1-1]++;
        grafo.graus[grafo.arestas[i].v2-1]++;
    }
}

void matriz_adjacente(Grafo &grafo){

    int i;
    vector <int> line;

    for (i=0; i<grafo.n_vertices; i++){
        line.push_back(0);
    }
    
    for (i=0; i<grafo.n_vertices; i++){
        grafo.mat_adj.push_back(line);
    }

}
