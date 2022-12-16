#ifndef grafos
#define grafos

using namespace std;

typedef struct aresta {
    int v1;
    int v2;
    
} Aresta;

typedef struct dado {
    int valor;
    int nivel;
    int pai;
    
} Dado;

class Grafo {
    private:
        //atributos
        string nome_grafo;
        int n_vertices;
        int n_arestas;
        int diametro;
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
        bool verifica_profundidade(int vertice, int* verificados, vector <Dado> &valores, int nivel);
        bool imprime_valores_busca(vector <Dado> valores, string nome);
        int buscar_maior_nivel(int vertice);
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
        bool gerar_grafico();
        bool encontrar_diametro();
        
    //
};

#endif