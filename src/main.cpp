#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/leitura.h"

using namespace std;

int main(){

    ifstream arq("./input/as_graph.txt");

    vector <Aresta> teste;

    int valor = lerDado(arq); int x;
    Aresta dado;

    while(!arq.eof()){
        teste.push_back(lerArestas(arq));
    }
    

    cout << valor << endl;
    cout << teste[23].v1 << ' ' << teste[23].v2  << ' ' << teste.size() << endl;


    return 0;
}