#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.h"

using namespace std;

bool Grafo::imprimeGrafo(){
    ofstream arq("./output/resultado.txt");
    int x = 1;

    if(!arq.is_open()){
        cout << "arquivo não pode ser aberto" << endl;
        return false;

    } else {
        arq <<"# n = " << n_vertices << endl << "# m = " << n_arestas << endl;
        for (int i: graus){
            arq << x << ' ' << i << endl;
            x++;
        }
        arq.close();
        return  true;
    }
}

bool Grafo::imprimeMatriz(){
    ofstream arq("./output/matriz.txt");
    int i, x;

    if(!arq.is_open()){
        cout << "arquivo não pode ser aberto" << endl;
        return false;

    } else {
        for(i=0; i<n_vertices; i++){
            for(x=0; x<i+1; x++){
                arq << mat_adj[i][x];
            }
            arq << endl;
        }
        arq.close();
        return true;
    }
}

bool Grafo::imprimeLista(){
    ofstream arq("./output/lista.txt");
    int i, x;

    if(!arq.is_open()){
        cout << "arquivo não pode ser aberto" << endl;
        return false;

    } else {
        for(i=0; i<n_vertices; i++){
            for(x=0; x<list_adj[i].size(); x++){
                arq << list_adj[i][x] << ' ';
            }
            arq << endl;
        }
        arq.close();
        return true;
    }
}

bool Grafo::imprime_conexo(int numero, int *visitados){
    ofstream arq("./output/comp_conexos.txt");
    int i, x;
    int tamanhos[numero];

    for(x=0; x<numero; x++){ tamanhos[x] = 0; }

    if(!arq.is_open()){
        cout << "arquivo não pode ser aberto" << endl;
        return false;

    } else {

        for(x=0; x<n_vertices; x++){
            tamanhos[visitados[x]-1]++;
        }
        arq << "n_componentes = " << numero << endl;
        
        for(i=1; i<numero+1; i++){
            arq << endl << "tamanho: " << tamanhos[i-1] << endl;

            for(x=0; x<n_vertices; x++){
                if(visitados[x] == i){
                    arq << x+1 << ' ';
                }
            }
            arq << endl;
        }
        arq.close();
        return true;
    }
}