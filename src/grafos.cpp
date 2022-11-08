#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.h"

using namespace std;

void Grafo::getDados(){
    cout <<"arestas: " << n_arestas << " vertices: " << n_vertices << endl;
    for (int i: graus){
        cout << i << ' ';
    }
}

bool Grafo::gerar_graus(){
    int i;

    for(i=0; i<n_vertices; i++){
        graus.push_back(0);
    }

    for(i=0; i<n_arestas; i++){
        graus[arestas[i].v1-1]++;
        graus[arestas[i].v2-1]++;
    }

    return true;
}

bool Grafo::matriz_adjacente(){
    int i; vector <int> line;

    for(i=0; i<n_vertices; i++){
        line.push_back(0);
        mat_adj.push_back(line);
    }
    
    for(Aresta a: arestas){
        if(a.v1 > a.v2){
            mat_adj[a.v1-1][a.v2-1] = 1;
        } else {
            mat_adj[a.v2-1][a.v1-1] = 1;
        }
    }

    return true;
}

bool Grafo::lista_adjacente(){
    int i; vector <int> line;

    for(i=0; i<n_vertices; i++){
        list_adj.push_back(line);
    }
    for(aresta a: arestas){
        list_adj[a.v1-1].push_back(a.v2);
        list_adj[a.v2-1].push_back(a.v1);
    }
    
    return true;
}

bool Grafo::busca_largura(){

}

bool Grafo::busca_profundidade(){

}

bool Grafo::comp_conexo(){
    
}