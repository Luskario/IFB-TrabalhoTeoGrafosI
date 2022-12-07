#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.h"

using namespace std;

int main(){
    
    //Grafo teste("as_graph.txt");
    Grafo teste("collaboration_graph.txt");

    //teste.getDados();
    //teste.imprimeGrafo();
    //teste.imprimeMatriz();
    //teste.imprimeLista();
    
    teste.comp_conexo();

    return 0;
}