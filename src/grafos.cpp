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