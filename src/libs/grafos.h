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
        string nome_grafo;
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
        bool verifica_comp(int i, int contador, int *visitados);
        bool imprime_conexo(int numero, int *visitados);
    //
    public:
        Grafo(string nome_arq);
        bool carregarGrafo(string nome_arq);

        bool imprimeGrafo();
        bool imprimeMatriz();
        bool imprimeLista();

        bool busca_largura(int vertice);
        bool busca_profundidade(int vertice);
        bool comp_conexo();
        void getDados();
    //
};

#endif