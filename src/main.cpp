#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/leitura.h"
#include "./libs/grafos.h"

using namespace std;

int main(){
    
    Grafo teste;
    bool teste1 = lerGrafo("as_graph.txt", teste);
    int i;
    if(teste1){
        cout << teste.n_arestas << endl;
    }
    
    /*
    for(i=0; i<teste.n_arestas; i++){
        cout << teste.arestas[i].v1 << ' ' << teste.arestas[i].v2  << " | " << i+1 << " de " << teste.n_arestas << endl;
    }
    */
   matriz_adjacente(teste);
   cout << teste.mat_adj[1][1] << endl;

    return 0;
}