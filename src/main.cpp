#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "./libs/grafos.h"
#include "./libs/processamento.h"

using namespace std;

int main(){
    cout << "carregando..." << endl;
    //esperar(2000);
    Grafo teste("as_graph.txt");

    //Grafo teste("collaboration_graph.txt");

    //teste.getDados();
    //teste.imprimeGrafo();
    teste.imprimeMatriz();
    //teste.imprimeLista();
    
    
    //teste.comp_conexo();

    //for(int a=1; a<16; a++){
        //teste.busca_largura(a);
    //}
    
    cout << "\033[2J" << "\033[0;0H";

    return 0;

    return 0;
}