//TAD : Grafo e operações.
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct VERTICE vertice;
typedef struct ARESTA aresta;
typedef struct GRAFO grafo;

void criar (grafo **G);

vertice * searchVertex(grafo *G, int k);

vertice* insertVertex (grafo *G, char o);

aresta * searchEdge(grafo *G, int k);

aresta* insertEdge (grafo *G, vertice* i, vertice* j, float d);

char vertexValue(grafo * G, vertice* v);

float edgeValue (grafo * G, aresta* e);

void replaceVertex(grafo *G, vertice* v, char o);

void replaceEdge (grafo *G, aresta* e, float o);

int areAdjacent(grafo * G, vertice * i, vertice * j);

vertice ** endVertices(grafo * G, aresta * e);

vertice * opposite(grafo * G, vertice * v, aresta * e);

float removeEdge(grafo *G, aresta * e);

char removeVertex(grafo *G, vertice * v);

int KEY (grafo * G, vertice * v);

void imprimir (grafo * G);

int ShortestPath (grafo * G, vertice * v);
