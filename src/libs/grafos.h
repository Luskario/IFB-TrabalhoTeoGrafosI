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
        void matriz_adjacente();
        void lista_adjacente();
    //
    public:
        Grafo(string nome_arq);
        bool imprimeGrafo();
        bool imprimeMatriz();
        bool imprimeLista();

        void getDados();
    //
};

#endif