/*******************************************************************************
ALUNOS
      Luiz Henrique Cherri      nºUSP 5991829

********************************************************************************/


#include "Tad_grafo.h"


int ler_grafo(grafo *G);    // Função que lê o grafo de um arquivo.

int main () {
     grafo *G;                 // Declara uma variavel G do tipo grafo
     int opc, v, e;
     float k;
     char c;
     vertice *v1, *v2;         //Variaveis auxiliares para trabalhar com vertices
     aresta * a1;              //Variaveis auxiliares para trabalhar com arestas
     criar(&G);                //Cria um grafo vazio
   
//=====MENU=====================================================================
   while (opc != 0){
         printf ("------ESCOLHA A OPCAO DESEJADA------\n");
         printf (" 1 - Ler grafo do Arquivo\n");
         printf (" 2 - Inserir Cidade\n");
         printf (" 3 - Inserir Estrada\n");
         printf (" 4 - Remover Cidade\n");
         printf (" 5 - Remover Estrada\n");
         printf (" 6 - Alterar elemento do Cidade\n");
         printf (" 7 - Alterar elemento da Estrada\n");
         printf (" 8 - Obter Cidades finais das Estradas\n");
         printf (" 9 - Obter o valor de um Cidade\n");
         printf ("10 - Obter o valor de uma Estrada\n");
         printf ("11 - Encontrar Cidade oposto ao outro atraves de uma Estrada\n");
         printf ("12 - Retorna se dois Cidades sao adjacentes\n");
         printf ("13 - Imprimir Cidades e rotas\n");
         printf ("14 - Caminho minimo\n");
         printf (" 0 - SAIR\n\n    >> ");
         fflush(stdin);
         scanf ("%d", &opc);         //opc lê a opção
         system ("CLS");             // Limpa a tela

       switch (opc){
              case 0:
                     break;
              case 1:
                     if (not(ler_grafo(G)))                       // Leitura do grafo a partir de um arquivo
                         printf ("ERRO NA LEITURA\n");            //se a leitura fot mal sucedida da mensagem de erro
                     else                                         
                     printf ("\nGrafo lido");
                     printf ("\nPressione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              case 2: //Insere Vertice
                     printf ("Digite o elemento a ser inserido >>"); 
                     fflush(stdin);                                      //Limpa buffer de entrada (eventualmente a letura de strings pode ocasionar erros)
                     scanf ("%c", &c);                                   //Lê elemento que o vertice armazenará
                     insertVertex (G, c);                                //Insere o vertice
                     printf ("\nPressione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break; 
              case 3:
                     imprimir(G);
                     printf ("Quais Cidades a Estrada conectara?\n");
                     printf ("Cidade 1 >> ");
                     scanf ("%d", &v);                              //Lê a chave para uma cidade
                     printf ("Cidade 2 >> ");
                     scanf ("%d", &e);                              //Lê a chave para uma outra cidade
                     printf ("Qual eh a distancia? >> ");
                     scanf ("%f", &k);                              //Lê a distancia entre as cidades
                     v1 =  searchVertex(G, v);                     //v1 e v2 recebem os ponteiros para a lista de vertices
                     v2 =  searchVertex(G, e);                         //referentes as referencias v e e
                     insertEdge(G, v1, v2, k);                     //Insere a aresta
                     printf ("\nPressione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;            
              case 4:
                     imprimir(G);                                 // Imprime o grafo
                     printf ("Qual Cidade sera removido? >> ");  
                     scanf ("%d", &v);                            //Lê a chave e um vertice
                     v1 =  searchVertex(G, v);                    //v1 recebe um ponteiro para a lista de vertices referente a v
                     removeVertex (G, v1);                        //Remove o vertice
                     printf ("\nGrafo atualizado: \n"); 
                     imprimir(G);                                 //Imprime o grafo
                     printf ("\nPressione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              case 5:
                     imprimir(G);                                // Imprime o grafo
                     printf ("Qual Estrada sera removida? >> ");  
                     scanf ("%d", &e);                           //Lê a chave e uma aresta
                     a1 =  searchEdge(G,e);                      //a1 recebe um ponteiro para a lista de arestas referente a e
                     removeEdge(G, a1);                          //Remove a aresta
                     printf ("\nNovas Estradas\n"); 
                     imprimir(G);                                //Imprime o grafo
                     printf ("\nPressione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              case 6:
                     imprimir(G);                                //Imprime o grafo
                     printf ("De qual Cidade sera alterado o elemento? >> ");
                     scanf ("%d",&v);                            //Lê a chave de um vertice
                     v1 =  searchVertex(G, v);                   //v1 recebe um ponteiro para a lista de vertices referente a v
                     printf ("\nQual eh o novo elemento? >> ");
                     fflush(stdin);                              //Limpa buffer de entrada
                     scanf ("%c", &c);                           //Lê um char
                     replaceVertex (G, v1, c);                   //Atualiza o elemento do vertice pelo char lido anteriormente
                     printf ("\nCidades Pos-Atualizacao\n"); 
                     imprimir(G);                                // Imprime o grafo
                     printf ("\nPressione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              case 7:
                     imprimir(G);                                // Imprime o grafo
                     printf ("De qual Estrada sera alterado o elemento? >> ");
                     scanf ("%d",&v);                            //Lê a chave e uma aresta
                     a1 =  searchEdge(G, v);                     //a1 recebe um ponteiro para a lista de arestas referente a v
                     printf ("\nQual eh a nova distancia? >> ");
                     scanf("%f",&k);                             //Lê a nova distância
                     replaceEdge (G, a1, k);                     //Atualiza a distancia da aresta pelo float k lido anteriormente
                     printf ("\nEstradas Pos-Atualizacao\n"); 
                     imprimir(G);                                // Imprime o grafo
                     printf ("\nPressione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;                 
              case 8:
                     imprimir(G);                                // Imprime o grafo
                     printf ("Escolha uma Estrada >> ");
                     scanf ("%d", &e);                           //Lê a chave e uma aresta
                     a1 =  searchEdge(G, e);                     //a1 recebe um ponteiro para a lista de arestas referente a e
                     vertice ** a;                               //declara a sendo um ponteiro duplo para vertices
                     a = endVertices(G, a1);                     //a recebe os vertices 2 finais da aresta
                     
                     printf ("Os Cidades finais sao: %d e %d", KEY(G, a[0]), KEY(G, a[1]));  //Imprime a chave dos vertices finais
                     
                     printf ("\nPresione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;    
              case 9:
                     imprimir(G);                                // Imprime o grafo
                     printf ("Qual eh o Cidade? >> ");
                     scanf ("%d", &v);                           //Lê a chave de um vertice 
                     v1=searchVertex(G,v);                       //v1 recebe um ponteiro para a lista de vertices referente a v
                     if (v1 !=0){
                        printf ("O elemento eh -> %c\n", vertexValue (G, v1)); //Imprime o elemento que o vertice armazena
                     }
                     else
                         printf ("Chave invalida");
                     printf ("\nPresione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              case 10:
                     imprimir(G);                                // Imprime o grafo
                     printf ("Qual eh a Estrada? >> ");  
                     scanf ("%d", &v);                           //Lê a chave e uma aresta
                     a1=searchEdge(G,v);                         //a1 recebe um ponteiro para a lista de arestas referente a v
                     if (a1!=0){
                        printf ("O elemento eh -> %.3f\n", edgeValue (G, a1)); //Imprime o elemento armazenado na aresta
                     }
                     else
                         printf ("Chave invalida");
                     printf ("\nPresione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;            
              case 11: 
                     imprimir(G);                                // Imprime o grafo
                     printf ("Digite o Cidade >> ");
                     scanf ("%d", &v);                           //Lê a chave de um vertice   
                     system("CLS");
                     imprimir(G);                                // Imprime o grafo
                     printf ("Digite a Estrada >> ");
                     scanf ("%d", &e);                           //Lê a chave e uma aresta
                     v1=searchVertex(G,v);                       //v1 recebe um ponteiro para a lista de vertices referente a v
                     a1=searchEdge(G,e);                         //a1 recebe um ponteiro para a lista de arestas referente a e
                     if (opposite (G, v1,a1))
                        printf ("O oposto eh >> %d\n", KEY(G,(opposite (G, v1, a1)))); //Imprime o verice oposto a v1 pela aresta a1
                     else
                         printf ("O Cidade e a Estrada fornecidos nao se conectam!");
                     printf ("\nPresione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              case 12:
                     imprimir(G);                                // Imprime o grafo
                     printf ("\nDigite uma Cidade >> ");
                     scanf ("%d", &v);                           //Lê a chave de um vertice   
                     system ("CLS"); 
                     imprimir(G);                                // Imprime o grafo
                     printf ("Digite outra Cidade >> ");
                     scanf ("%d", &e);                           //Lê a chave de um outro vertice  
                     v1 = searchVertex(G,v);                     //v1 recebe um ponteiro para a lista de vertices referente a v
                     v2 = searchVertex(G,e);                     //v2 recebe um ponteiro para a lista de vertices referente a e
                     if (areAdjacent (G, v1, v2))                //Verifica se v1 e v2 são adjacentes
                        printf ("Sao Adjacentes");                          //Se forem imprime que sim
                     else
                        printf ("Nao sao Adjacentes");                      //Senao imprime que não
                     printf ("\nPresione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;                      
                     
              case 13:
                     imprimir(G);                                // Imprime o grafo
                     printf ("\nPresione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              case 14:
                     printf ("Deseja o menor caminho apartir de qual cidade? >> ");
                     scanf ("%d", &v);                          //Lê a chave de um vertice   
                     printf ("\nOs menores caminhos possiveis sao: \n\n");
                     v1 = searchVertex(G, v);                   //v1 recebe um ponteiro para a lista de vertices referente a v
                     ShortestPath(G, v1);                       //Retorna os Caminhos minimos de todos os vertices até v1
                     printf ("\n\nPresione qualquer tecla para voltar para o menu principal");
                     getch();
                     system ("CLS");
                     break;
              default:
                      printf ("Opcao invalida\nPressione qualquer tecla e digite uma opção valida\n\n");
                      fflush(stdin);                           //Limpa buffer de entrada                       
                      getch();
                      break;
                          
         }//end switch
     }//end while     
} //END



//===Função Ler Grafo===========================================================
int ler_grafo(grafo *G){
     FILE * arq;              // Variável que axília na manipulação de arquivos
     int i, j;                // variaveis aixiliares
	 float distancia;                 // Variavel auxiliar
     char s[25];                      //Auxiliar para ler o nome do aruivo
     char o = '\0';                   //Elemento dos vertices
     printf ("Digite o nome do arquivo >> ");
     scanf ("%s", s);                 //Lê o nome do arquivo
     
	 if (arq = fopen (s , "r")){  // Abre o arquivo de texto
           fscanf(arq,"%d",&i);    //Lê as quantidades de arestas e vertices      
           fscanf(arq,"%d",&j);
           
           if (i<=100){            // Se houverem menos de 100 vertices
               for (int k=1; k<=i; k++){   //Insere os vertices
                   insertVertex (G, o);    
               }
               
               while (!feof(arq)) {                // Enquanto não chegar o fim do arquivo
                     
                     //Leitura de dois vertices e a aresta que liga os dois
                     fscanf(arq,"%d",&i);                 
                     fscanf(arq,"%d",&j);        
                     fscanf(arq,"%f\n",&distancia); 
                     if (distancia > 1000){    // Ajusta da distancia caso seja maior que mil
                        distancia = 1000;
                     } 
                     vertice * v1 =  searchVertex(G, i);  //v1 recebe um ponteiro para a lista de vertices referente a i
                     vertice * v2 =  searchVertex(G, j);  //v2 recebe um ponteiro para a lista de vertices referente a j
                     insertEdge(G, v1, v2, distancia);    //Insere aresta
               }
               
               fclose (arq);      // Fecha o arquivo
               return (1);        //retorna verdadeiro
           }
     }
     return (0); // Retorna Falso
}
