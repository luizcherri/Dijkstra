/*******************************************************************************
ALUNOS
      Agilso Benet de Oliveira  nºUSP 5888991
      Elan Bernardes Dutra      nºUSP 5889129
      Luiz Henrique Cherri      nºUSP 5991829

Professor:
      Ricardo J. G. B. Campello
********************************************************************************/


#define infinito 32767;
#include <stdio.h>
#include <stdlib.h>
#include "Tad_Grafo.h"

//===ESTRUTURAS=================================================================
typedef struct VD {            //Utilizada na função ShortestPath
       float dist;             //Distancia do vertice à origem dada
       vertice * atual;        //Ponteiro para o vertice que se referencia
       vertice * parent;       //Ponteiro para o pai do vertice atual
       VD * parentVD;          //Ponteiro para o pai do atual na lista VD
}VD;

struct VERTICE {               //Utilizada criar para uma lista de vertices
    char elemV;                //Armazena o elemento
    vertice * vnext;           //Armazenaum ponteiro para o proximo vertice na lista
    vertice * vprev;           //Armazenaum ponteiro para o vertice anterior na lista
};

struct ARESTA {                //Utilizada criar para uma lista de arestas
	float elemA;               //Armazena o elemento, distancia
	vertice *pt_v1;            //Ponteiro para um vertice adjacente a aresta
	vertice *pt_v2;            //Ponteiro para um outro vertice adjacente a aresta
	aresta * aprev;            //Ponteiro para a proxima aresta na lista
	aresta * anext;            //Ponteiro para a aresta anterior na lista
};

struct GRAFO {                 //Utilizada para referenciar as outras estruturas
        vertice *headV;        //Ponteiro para o primeiro nó da lista de vertices
        vertice *tailV;        //Ponteiro para o ultimo nó da lista de vertices
        aresta *headA;         //Ponteiro para o primeiro nó da lista de arestas
        aresta *tailA;         //Ponteiro para o ultimo nó da lista de vertices
        int nvertices;         //Número de vertices que o grafo conterá
		int narestas;          //Número de arestas que o grafo conterá
};

//===FUNÇÕES====================================================================
void imprimeA (grafo* G);
void imprimeV (grafo* G);

void criar (grafo **G){                  //Inicia o grafo criando um nó vazio e
     *G=(grafo*)calloc(sizeof(grafo),1);          //setando todas os capos para zero
     (*G)->nvertices = 0;
     (*G)->narestas = 0;
     (*G)->headV = 0;
     (*G)->headA = 0;
     (*G)->tailV = 0;
     (*G)->tailA = 0;
}

vertice * searchVertex(grafo *G, int k){          //Procura vertice na lista apartir da chave
        vertice * i;                              //Declara uma variavel do tipo ponteiro para vertice
        i = G->headV;                             //i recebe um ponteiro para o inicio da lista de vertices
        int j=0;                                  //Contador
        if ((G->nvertices==0)||(k>G->nvertices)) {//se nao estiver na lista
           return (0);                                 //Retorne zero
        }
        while (1) {                               //Enquanto nao encontrar     
              j++;                                     //Incremente j
              if (j==k)                                //Se j=k
                 return (i);                                //Retorne o ponteiro
              if (i->vnext == 0)                       //Se o proximo da lista for zero
                 return (0);                                //Retorna zero
              i=i->vnext;                              //i recebe o proximo da lista
        } //end while
}

aresta * searchEdge(grafo *G, int k){             //Procura aresta na lista apartir da chave
        aresta * i;                               //Declara uma variavel do tipo ponteiro para aresta
        i = G->headA;                             //i recebe um ponteiro para o inicio da lista de arestas
        int j=1;                                  //contador
        if ((G->narestas == 0)||(k>G->narestas)) {//se nao estiver na lista
           return (0);                                //Retorne zero
        }
        
        if (k<=G->narestas){                      //Se estiver na lista
            while (j<k){                               //Enquanto j>k
                  j++;                                      //Incrementa j
                  i=i->anext;                               //i passa a ser o proximo da lista
            }
            return (i);                                //Retorne o ponteiro
        }
}

vertice* insertVertex (grafo *H, char o){         //Insere vertice na lista
    if ((H->nvertices)<=(100)){                   //Se o numero de vertices eistentes for menor ou igual a 100
        vertice *e;                                    //Declara um ponteiro para vertices e
        e = (vertice *)calloc(1,sizeof(vertice));      //Aloca e dinamicamente em memoria
        e->elemV = o;                                  //Armazena o char em e
        if (H->nvertices==0) {                         //Se for o primeiro a ser inserido
           e->vprev=0;                                      //Seta a referência em 'e' para o vertice anterior para 0 (NULO)
           H->headV = e;                                    //Seta e como sendo o primeiro vertice
        }
        else {                                         //Senao
                 e->vprev=H->tailV;                         //Seta a referência em 'e' para o vertice anterior para o ultimo elemento da lista
                 e->vprev->vnext=e;                         //O ultimo elemento da lista seta 'e' como seu sucessor
        }
        e->vnext=0;                                    //Seta a referência em 'e' para o proximo vertice para o 0
        H->tailV=e;                                    //O ultimo elemento passa a ser e
        H->nvertices ++;                               //Incrementa o numero de vertices
        return(e);                                     //Retorna o elemento
    } //end if
    else                                           //senao
        return (0);                                       //Retorna zero
    
}

aresta* insertEdge (grafo *G, vertice* i, vertice* j, float d){  //Insere aresta na lista
        aresta *e;                                               //Declara um ponteiro para aresta e
        e=(aresta *)calloc(sizeof(aresta), 1);                   //Aloca e dinamicamente em memoria
        e->elemA = d;                                            //d passa a ser o elemento de e
        e->pt_v1 = i;                                            //i passa a ser o ponteiro para o vertice 1
        e->pt_v2 = j;                                            //j passa a ser o ponteiro para o vertice 2
        
        if (G->narestas==0) {                                    //Se for a primeira a ser inserida
           e->aprev=0;                                                //Seta a referência em 'e' para a aresta anterior para 0 (NULO)
           G->headA=e;                                                //Seta e como sendo a primeira aresta
        }
        else {                                                   //Senão
             e->aprev=G->tailA;                                         //Seta a referência em 'e' para a aresta anterior, para o ultimo elemento da lista
             e->aprev->anext=e;                                         //O ultimo elemento da lista seta 'e' como seu sucessor
        }
        e->anext=0;                                               //Seta a referência em 'e' para a proxima aresta, para o 0
        G->tailA=e;                                               //O ultimo elemento passa a ser e
        G->narestas++;                                            //Incrementa o numero de arestas
        return(e);                                                //Retorna o elemento
}

char vertexValue(grafo * G, vertice* v) { // retorna o elemento armazenado no vértice v.
     return(v->elemV);
}

float edgeValue (grafo * G, aresta* e)  {// retorna o elemento armazenado na aresta e.
       return(e->elemA);
}

void replaceVertex(grafo *G, vertice* v, char o) {    // substitui o elemento do vértice v por o.
     v->elemV=o;
}

void replaceEdge (grafo *G, aresta* e, float o){    // substitui o elemento da aresta e por o.
     e->elemA=o;
}

int areAdjacent(grafo * G, vertice * i, vertice * j){    // verdadeiro se os vértices v e w forem adjacentes, falso c.c.
    aresta* a = G->headA;                                //Declara um ponteiro para aresta a
    int k = 0;                                           //inteiro auxiliar
    while (1){
          if (  ((i==a->pt_v1) || (i==a->pt_v2)) && ((j==a->pt_v1) || (j==a->pt_v2)) )     // Se sorem adjacentes
             return (1);                                                                      //Retorne Verdadeiro
          if (G->narestas = k)                                                             // Sechegou no fim e nao achou
             return (0);                                                                      //Retorne Falso
          a = a->anext;                                                                    // a passa a ser o proximo da lista
          k++;                                                                             //Incrementa k
    }
}

vertice ** endVertices(grafo * G, aresta * e){            //Retorna os vertices finais
       vertice ** aux;                                    //Declara um ponteiro duplo para vertice
       aux = (vertice**)calloc(sizeof(vertice*), 2);      //Aloca duas posiçoes para saida
       aux[1] = e->pt_v2;                                         //atribuiçoes para retorno
       aux[0] = e->pt_v1;

       return(aux);                                       //Retorne aux que sao dois ponteiros para inteiros
}


vertice * opposite(grafo * G, vertice * v, aresta * e) {     // retorna uma referência para o vértice oposto a v na aresta e.
    if (e->pt_v1 == v)                //Se o vertice de entreda for igual ao de pt_v1
       return (e->pt_v2);                  //Retorne pt_v2
    if (e->pt_v2 == v)                //Se o vertice de entreda for igual ao de pt_v2
       return (e->pt_v1);                  //Retorne pt_v1
    else return (0);                  //caso contrario retorne zero
}


float removeEdge(grafo *G, aresta * e){         // remove a aresta e, retornando o elemento armazenado nela.
      if (G->narestas == 0)                     // Se o numero de arestas for zero
         return (0);                               //retorne zero
      
      if (G->narestas == 1){                    // Se o numero de arestas for 1
          float r = e->elemA;                      // r armazena o elemento da aresta
          free(e);                                 // Libera memoria
          G->narestas--;                           //Decrementa o numero de arestas
          return (r);                              //Retorna r
      }
         
      if (e->aprev == 0) {                      // Se o ponteiro que aponta para o anterior da lista for igual a zero
         G->headA = e->anext;                      // Ajusta os ponteiros
         e->anext->aprev = 0;                     
      }
      else {
           if (e->anext == 0 ){                 // Se o ponteiro que aponta para o proximo da lista for igual a zero
              G->tailA = e->aprev;                 // Ajusta os ponteiros
              e->aprev->anext = 0;                 
           }
           else {                               // Senao
              e->aprev->anext = e->anext;          // Ajusta os ponteiros
              e->anext->aprev = e->aprev;           
           }
      }
      
      float r = e->elemA;                       // r armazena o elemento da aresta
      free(e);                                  // Libera memoria
      G->narestas--;                            //Decrementa o numero de arestas
      return (r);                               //Retorna r
}

char removeVertex(grafo *G, vertice * v) {     // remove o vértice v (e suas arestas incidentes) e retorna o elemento armazenado nele.
     int w = KEY(G,v);                         // w armazena a chave do vertic v
     if (G->nvertices == 0){                   // Se o numero de vertices fo zero
        return (0);                               //Retorne zero
     }
     if (G->nvertices == 1){                   // Se o numero de vertices for 1
        char r = v->elemV;                        // r armazena o elemento do vertice
        free(v);                                  // Libera memoria
        G->nvertices--;                           // Decrementa o numero de vertices

        return (r);                               //Retorna r
     }
     
     int k=0;
     aresta * a = G->headA;
     aresta * b;
     while (k < G->narestas){                  // Busca as arests incidentes as remove
           b=a->anext;
           if ((a->pt_v1 == v)  ||  (a->pt_v2 == v)){
              removeEdge (G, a);
           }
           a = b;
           k++;
     }
     
      if (v->vprev == 0) {                    // Se o anterior for zero
         G->headV = v->vnext;                    // Ajusta os ponteiros
         v->vnext->vprev = 0;
      }
      else { 
          if (v->vnext == 0) {                // Se o proximo for zeto   
             G->tailV = v->vprev;                // Ajusta os ponteiros
             v->vprev->vnext = 0;
          }
          else {                              // Senao
             ((*v).vprev)->vnext = v->vnext;     // Ajusta os ponteiros
             ((*v).vnext)->vprev = v->vprev;
          }
      } 
     
     
     
     while (w <= G->nvertices-1){             // Imprime mudança de chaves
           w++;
           printf ("A o numero da cidade %d agora eh %d\n", w, w-1);
           
     }
     char r = v->elemV;                       // r armazena o elemento do vertice
     free(v);                                 // Libera memoria
     G->nvertices--;                             // Decrementa o numero de vertices

     return (r);                              // Retorna r
}

int KEY (grafo * G, vertice * v) {
    vertice * vr;
    int i = 0;
    vr = G->headV;
    while (i<=G->nvertices) {
          i++;
          if (v == vr)
             return (i); 
          vr = vr->vnext;
    }    
    return (0);
}

void imprimeA (grafo* G){
     int k=1;
     aresta * a;
     a = G->headA;
     if (G->narestas==0){
        printf ("Grafo sem arestas\n");
     }
     else {
         while (k <= G->narestas){
               printf ("Aresta %2d  -->>  ", k);
               printf ("%d <=> ", KEY (G, a->pt_v1));
               printf ("%d -> ", KEY (G, a->pt_v2));
               printf ("%.3f \n", a->elemA);
               a = a->anext;
               k++;
         }
     }      
}

void imprimeV (grafo * G){
     int k=1;
     vertice * v;
     v = G->headV;
     if (G->nvertices==0){
        printf ("Grafo Vazio\n");
     }
     else{
        while (k <= G->nvertices){
           printf ("Chave %2d  ->  ", KEY(G, v));
           printf ("| Elemento %c\n", v->elemV);
           v = v->vnext;
           k++;
        } 
     }     
}

void imprimir (grafo *G){
     imprimeA(G);
     printf ("\n");
     imprimeV(G);
}

/////////////////////////////////////////////////////////////////////
//Funçoes para o Dijkstra que retornará os Caminhos Minimos
////////////////////////////////////////////////////////////////////

void ordena (VD e[], int j) {
     VD aux;
     for (int i = 1 ; i<=j ; i++){
         for (int k = i ; k<=j ; k++){
             if (e[i].dist < e[k].dist){
                aux = e[k];
                e[k] = e[i];
                e[i] = aux;
             }
         }    
     }    
}

VD remova (VD e[], int j){
      VD C = e[j];
      return (C);
}

VD * atualiza (VD e[] , VD z, int j){
     for (int i = 1 ; i<=j ; i++){
         if (e[i].atual == z.atual){
            return (e+i);         
         }
     }
}

int ShortestPath (grafo * G, vertice * v){
    VD * e;
    e = (VD*)calloc(G->nvertices+1 , sizeof(VD));
    int j=0;
    while (j<G->nvertices){
          j++;
          
          e[j].atual = searchVertex(G,j);
          if (v==e[j].atual) {
             e[j].dist = 0;
             e[j].parent = 0;
          }
          else
              e[j].dist = infinito;
          
          e[j].parentVD = 0;
    }

    VD u, z;
    int h = j;
    while (j>0) {
          ordena (e, j);
          u = remova(e,j); j=j-1;
          aresta * u_z;
          VD * aux;
          u_z = G->headA;
          while (u_z != 0){
                if ((z.atual = opposite (G, u.atual, u_z )) != 0) {
                    aux = atualiza ( e, z, h);
                    if (aux->dist > u.dist+u_z->elemA){
                       aux->dist = u.dist+u_z->elemA;
                       aux->parent = u.atual;
                       aux->parentVD = e+(j+1);
                    }
                }
                u_z = u_z->anext;
          }
    }

    VD* aux;
    int n=1;
    int k;
    int vect[G->nvertices];
    while (n <= G->nvertices){
          aux = e+n;

          if (aux->atual != v) {
             if (aux->parentVD!=0){
                  printf("Caminho minimo da cidade %d a cidade %d:\n", KEY(G, v), KEY(G, aux->atual));
                  k = 0;
                  while (aux->atual != v){
                        vect [k] = KEY(G, aux->atual);
                        aux = aux->parentVD;
                        k++;
                  }
                  printf("%d >", KEY(G, v));
                  for (int y=k-1; y>0; y--){
                      printf(" %d >", vect[y]);    
                  }
                  printf(" %d", vect[0]); 
                  printf("\nDistância do caminho = %.2f", e[n].dist);
                  printf("\n\n");
             }
             else
                 printf("Nao ha caminho para a cidade %d:\n\n", KEY(G, aux->atual));
          }
          n++;
    }
    
}
