#include <iostream>
#include <fstream>
#include <vector>
#include "./libs/grafos.hpp"
#include "./lib_externa/pbPlots.hpp"
#include "./lib_externa/supportLib.hpp"

using namespace std;

bool Grafo::imprimeGrafo(){
    ofstream arq("./output/"+ nome_grafo+"/resultado.txt");
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
    ofstream arq("./output/"+ nome_grafo+"/matriz_adjacente.txt");
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
    ofstream arq("./output/"+ nome_grafo+"/lista_adjacente.txt");
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
    ofstream arq("./output/"+ nome_grafo+"/componentes_conexos.txt");
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

bool Grafo::imprime_valores_busca(vector <Dado> valores, string nome){

    string nomeArq = "./output/"+ nome_grafo+"/buscas/busca_" + nome + "_" + to_string(valores[0].valor) + ".txt";

    ofstream arq(nomeArq);
    int i, x;

    if(!arq.is_open()){
        cout << "arquivo não pode ser aberto" << endl;
        return false;

    } else {

        for(x=0; x<valores.size(); x++){
            arq << "valor: "<< valores[x].valor << " | pai: " << valores[x].pai << " | nivel: " << valores[x].nivel << endl;
        }

        arq.close();
        return true;
    }
}

bool Grafo::gerar_grafico(){
    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    vector <double> vertices;
    vector <double> d_graus;

    for(int a=1; a < n_vertices+1; a++){
        vertices.push_back(a);
        d_graus.push_back(graus[a-1]);
    }
    
    DrawScatterPlot(imageReference, 600, 400, &vertices, &d_graus, errorMessage);

    vector<double> *pngdata = ConvertToPNG(imageReference->image);
    string nomeArq = "./output/" + nome_grafo + "/grafico.png";
	WriteToFile(pngdata, nomeArq);
    DeleteImage(imageReference->image);

    return true;
    
}