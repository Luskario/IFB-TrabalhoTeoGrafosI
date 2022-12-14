#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "./libs/auxiliar.h"
#include "./libs/grafos.h"

using namespace std;

bool criar_diretorio(string nome){

    string nomeDir = "./output/" + nome;

    struct stat st = {0};
	
	if (stat(nomeDir.c_str(), &st) == -1) {
		if(mkdir(nomeDir.c_str(), 0700) == 0){
			return true;
		}
	}		
	
	return false;
}

bool Grafo::encontrar_diametro(){
    int diametro = 0, i, verticeMaiorNivel = 0;
	
	for(int a=1; a<n_vertices+1; a++){
		i = buscar_maior_nivel(a);
		if(diametro<i){
			diametro = i;
			verticeMaiorNivel = a;
		}
	}

	cout << diametro << " " << verticeMaiorNivel << endl;

}

int Grafo::buscar_maior_nivel(int vertice){
	int verificados[n_vertices], nivel[n_vertices];
    int i, x, ultimo;
    vector <Dado> valores;

    for(i=0; i<n_vertices; i++){
        verificados[i] = 0;
        nivel[i] = 0;
    }
    
    queue <int> lidos;
    lidos.push(vertice);
    valores.push_back({vertice, 0, 0});

    while(lidos.size() > 0){
        ultimo = lidos.front();

        for(x=0; x<list_adj[ultimo-1].size(); x++){
            i = list_adj[ultimo-1][x];

            if(verificados[i-1] == 0){
                lidos.push(i);
                verificados[i-1] = 1;
                nivel[i-1] = nivel[ultimo-1]+1;
                valores.push_back({i, nivel[i-1], ultimo});
            }
        }

        lidos.pop();
    }

	return valores[valores.size()-1].nivel;
}

