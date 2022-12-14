#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "./libs/grafos.h"
#include "./libs/auxiliar.h"

using namespace std;

int main(){
    cout << "carregando..." << endl;
    criar_diretorio("");

    Grafo teste("as_graph.txt");

    //Grafo teste("collaboration_graph.txt");

    //teste.getDados();
    //teste.imprimeGrafo();
    //teste.imprimeMatriz();
    //teste.imprimeLista();
    
    
    //teste.comp_conexo();

    //for(int a=1; a<16; a++){
        //teste.busca_largura(a);
    //}

    teste.busca_largura(24733);

    //teste.gerar_grafico();

    system("clear || cls");

    //teste.encontrar_diametro();

    return 0;
}