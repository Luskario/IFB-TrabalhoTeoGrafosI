#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/leitura.h"

using namespace std;

bool lerGrafo(string nome_arq, Grafo &grafo){

    ifstream arq("./input/" + nome_arq);

    if(!arq.is_open()){
        cout << "arquivo não encontrado";
        return false;
    }

    arq >> grafo.n_vertices;

    Aresta dado; 
    while(!arq.eof()){

        dado.v1 = 0; dado.v2 = 0;
        arq >> dado.v1 >> dado.v2;

        if(dado.v1 && dado.v2){
            grafo.arestas.push_back(dado);
        }
    }

    grafo.n_arestas = grafo.arestas.size();
    cout_graus(grafo);

    arq.close();
    return true;
}
