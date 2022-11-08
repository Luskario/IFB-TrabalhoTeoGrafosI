#ifndef grafos
#define grafos

using namespace std;

typedef struct aresta {
    int v1;
    int v2;
    
} Aresta;

class Grafo {
    private:
        //atributos
        int n_vertices;
        int n_arestas;
        vector <int> graus;
        vector <Aresta> arestas;
        vector<vector<int>> mat_adj;
        vector<vector<int>> list_adj;

    //
    private:
        //funções privadas
        bool gerar_graus();
        bool matriz_adjacente();
        bool lista_adjacente();
    //
    public:
        Grafo(string nome_arq);
        bool carregarGrafo(string nome_arq);

        bool imprimeGrafo();
        bool imprimeMatriz();
        bool imprimeLista();

        bool busca_largura();
        bool busca_profundidade();
        bool comp_conexo();
        void getDados();
    //
};

#endif