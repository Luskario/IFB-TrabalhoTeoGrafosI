#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.hpp"
#include "./libs/auxiliar.hpp"

using namespace std;

bool Grafo::carregarGrafo(string nome_arq){
    ifstream arq("./input/" + nome_arq);

    if(!arq.is_open()){
        cout << "arquivo não encontrado";
        return false;

    } else {
        arq >> n_vertices;

        Aresta dado; 
        while(!arq.eof()){

            dado.v1 = 0; dado.v2 = 0;
            arq >> dado.v1 >> dado.v2;

            if(dado.v1 && dado.v2){
                arestas.push_back(dado);
            }
        }

        n_arestas = arestas.size();

        bool v_graus = gerar_graus();
        bool v_mat_adj = matriz_adjacente();
        bool v_list_adj = lista_adjacente();

        arq.close();
        return true;
    }

}

Grafo::Grafo(string nome_arq){
    nome_grafo = nome_arq;
    criar_diretorio("");
    criar_diretorio(nome_arq);
    criar_diretorio(nome_arq+"/buscas");
    
    bool verifica = carregarGrafo(nome_arq);
}
