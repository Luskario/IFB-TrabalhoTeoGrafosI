#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.h"

using namespace std;

int main(){
    
    Grafo teste("as_graph.txt");

    teste.getDados();

    return 0;
}