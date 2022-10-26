#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/process.h"
#include "./libs/leitura.h"

using namespace std;

void code_run(ifstream& arq){

    vector <Aresta> teste;

    int n_vertices = lerDado(arq);
    
    while(!arq.eof()){
        lerArestas(arq, teste);
    }

    int n_arestas = teste.size();

}

int count_graus(vector <Aresta> arestas, int vertice){

    return 1;
}