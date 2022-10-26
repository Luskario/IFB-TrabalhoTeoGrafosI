#ifndef leitura
#define leitura

using namespace std;

struct aresta
{
    int v1;
    int v2;
};

typedef struct aresta Aresta;


int lerDado(ifstream& arq);
void lerArestas(ifstream& arq, vector <Aresta> &arestas);


#endif