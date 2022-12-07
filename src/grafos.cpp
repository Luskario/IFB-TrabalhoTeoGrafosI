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

bool Grafo::busca_largura(int vertice){
    bool verificados[n_arestas];

}

bool Grafo::busca_profundidade(int vertice){

}

bool Grafo::comp_conexo(){
    int i, contador = 0;
    int visitados[n_vertices];

    for(i=0; i<n_vertices; i++){
        visitados[i] = 0;
    }
   
    for(i=0; i<n_vertices; i++){
        //cout << visitados[i];
        if(visitados[i] == 0){
            contador++;
            verifica_comp(i, contador, visitados);
        }
    }

    imprime_conexo(contador, visitados);
    return true;
    
}

bool Grafo:: verifica_comp(int i, int contador, int *visitados){
    int a, posicao;
    cout << i << ' ' << contador << endl;

    visitados[i] = contador;

    for(a=0; a<list_adj[i].size(); a++){
        posicao = list_adj[i][a]-1;
        if(visitados[posicao] == 0){
            verifica_comp(posicao, contador, visitados);
        }
    }
    
    return true;
}