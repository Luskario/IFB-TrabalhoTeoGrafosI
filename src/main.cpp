#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/leitura.h"

using namespace std;

int main(){

    ifstream arq("./input/as_graph.txt");

    vector <Aresta> teste;

    int valor = lerDado(arq); int x, i;
    Aresta dado;

    
    lerArestas(arq, teste);

    cout << valor << endl;
    for(i=0; i<teste.size(); i++){
        cout << teste[i].v1 << ' ' << teste[i].v2  << ' ' << teste.size() << endl;
    }
    

    return 0;
}