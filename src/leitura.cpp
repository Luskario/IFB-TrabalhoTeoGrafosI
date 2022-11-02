#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.h"

using namespace std;

Grafo::Grafo(string nome_arq){
    ifstream arq("./input/" + nome_arq);

    if(!arq.is_open()){
        cout << "arquivo não encontrado";
    }

    arq >> n_vertices;

    Aresta dado; 
    while(!arq.eof()){

        dado.v1 = 0; dado.v2 = 0;
        arq >> dado.v1 >> dado.v2;

        if(dado.v1 && dado.v2){
            arestas.push_back(dado);
        }
    }

    n_arestas = arestas.size();
    int i;

    for(i=0; i<n_vertices; i++){
        graus.push_back(0);
    }

    for(i=0; i<n_arestas; i++){
        graus[arestas[i].v1-1]++;
        graus[arestas[i].v2-1]++;
    }

    arq.close();
}
