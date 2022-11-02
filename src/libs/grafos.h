#ifndef grafos
#define grafos

using namespace std;

typedef struct aresta {
    int v1;
    int v2;
    
} Aresta;

typedef struct grafo {
    int n_vertices;
    int n_arestas;
    vector <int> graus;
    vector <Aresta> arestas;
    vector<vector<int>> mat_adj;

} Grafo;

void cout_graus(Grafo &grafo);
void matriz_adjacente(Grafo &grafo);

#endif