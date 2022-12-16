#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <filesystem>
#include "./libs/auxiliar.hpp"
#include "./libs/grafos.hpp"

using namespace std;
using namespace filesystem;

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

    system("clear || cls");
	cout << "Diametro: " << diametro << endl;
    
    return true;

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

int menu(){
    string nome_arq;
    vector <string> arquivos;
    int op;

    cout << "selecione arquivo: " << endl;

    for (const auto & file : directory_iterator("./input/")){
        nome_arq = file.path();
        nome_arq.erase(0, 8);
        arquivos.push_back(nome_arq);
    }

    for(int a=0; a<arquivos.size(); a++){
        cout << a+1 << " - " << arquivos[a] << endl;
    }
    cout << endl << "0 - para sair";

    cout << endl << "op:  "; cin >> op;
    cout << endl;

    if(op != 0){
        if(op>arquivos.size()){
            system("clear || cls");
            op = menu();
        }

        system("clear || cls");

        menu2(arquivos[op-1]);
    }
    return op;

}

int menu2(string nome_arq){
    cout << "carregando grafo..." <<endl;
    Grafo g(nome_arq);
    int op;

    system("clear || cls");

    while(op != 0){
        system("clear || cls");
    
        cout << "1 - imprimir resultado" << endl
        << "2 - imprimir lista adjacente" << endl
        << "3 - imprimir matriz adjacente" << endl
        << "4 - imprimir componentes conexos" << endl
        << "5 - realizar buscas" << endl
        << "6 - imprimir gráfico" << endl
        << "7 - achar diametro" << endl << endl
        << "0 - para sair"<< endl<< endl;
        cout << "op: ";;

        cin >> op;

        if(op == 1){
            carregando();
            g.imprimeGrafo();
            system("clear || cls");
            concluindo();
        }
        if(op == 2){
            carregando();
            g.imprimeLista();
            system("clear || cls");
            concluindo();
        }
        if(op == 3){
            carregando();
            g.imprimeMatriz();
            system("clear || cls");
            concluindo();
        }
        if(op == 4){
            carregando();
            g.comp_conexo();
            system("clear || cls");
            concluindo();
        }
        if(op == 6){
            carregando();
            g.gerar_grafico();
            system("clear || cls");
            concluindo();
        }
        if(op == 7){
            carregando();
            g.encontrar_diametro();
            concluindo();
        }

        if(op == 5){
            int vertice;
            while(op != 3){
                system("clear || cls");
                op = busca();
                
                if(op == 3){
                    break;
                }

                if(op == 1){
                    cout << "vértice: ";
                    cin >> vertice;
                    carregando();
                    g.busca_largura(vertice);
                    system("clear || cls");
                    concluindo();
                } else if(op == 2){
                    cout << "vértice: ";
                    cin >> vertice;
                    carregando();
                    g.busca_profundidade(vertice);
                    system("clear || cls");
                    concluindo();
                }
            }
        }
    }

    return 0;
}

int busca(){
    int op;
    system("clear || cls");
    cout << "1 - busca em largura" << endl 
		<< "2 - busca em profundidade" << endl << endl
        << "0 - para votlar"<< endl<< endl;
    cout << "op: ";
    cin >> op;

    if(op == 0){
        return 3;
    } else if (op > 2){
        op = busca();
    }
    return op;
}

void carregando(){
    system("clear || cls");
    cout << "carregando..." << endl;
}

void concluindo(){
    int variavel_descarte;
    cout << "concluído! Selecione 0 para voltar" << endl <<endl << "op: ";
    cin >> variavel_descarte;
    system("clear || cls");
}