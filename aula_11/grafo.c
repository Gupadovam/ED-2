#include <stdio.h>
#include <stdlib.h>

/* Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /* Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/* Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/* Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matriz de adjacências. */
} GrafoM;

/* Função para criar um grafo com lista de adjacências. */
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

/* Função para criar um grafo com matriz de adjacências. */
GrafoM* criar_grafo_mat (int tamanho) {
   int v, w;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
      for (w = 0; w < G->V; w++) {
         G->Mat[v][w] = 0; // Inicializa com 0
      }
   }
   return G;
}

/* Função para adicionar aresta ao grafo de lista de adjacências. */
void adicionar_aresta_adj(GrafoA *G, int u, int v) {
   NoA *atual = G->Adj[u];

   // Verificar se a aresta já existe
   while (atual != NULL) {
      if (atual->id == v) {
         return;
      }
      atual = atual->next;
   }

   // Se chegamos aqui, a aresta não existe, então a adicionamos
   NoA *novoNo = (NoA *)malloc(sizeof(NoA));
   novoNo->id = v;
   novoNo->next = G->Adj[u];
   G->Adj[u] = novoNo;

   G->E++;
}

/* Função para adicionar aresta ao grafo de matriz de adjacências. */
void adicionar_aresta_mat(GrafoM *G, int u, int v) {
   G->Mat[u][v] = 1;;
   G->E++;
}

/* Função para imprimir o grafo de lista de adjacências. */
void imprimir_grafo_adj(GrafoA *G) {
   int v;
   printf("Grafo (lista de adjacências):\n");
   for (v = 0; v < G->V; v++) {
      NoA *temp = G->Adj[v];
      printf("%d -> ", v);
      while (temp) {
         printf("%d ", temp->id);
         temp = temp->next;
      }
      printf("\n");
   }
}

/* Função para imprimir o grafo de matriz de adjacências. */
void imprimir_grafo_mat(GrafoM *G) {
   int v, w;
   printf("Grafo (matriz de adjacências):\n");
   for (v = 0; v < G->V; v++) {
      for (w = 0; w < G->V; w++) {
         printf("%d ", G->Mat[v][w]);
      }
      printf("\n");
   }
}

/* Função para destruir um grafo construído com lista de adjacências. */
void liberar_grafo_adj(GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      NoA *temp = G->Adj[v];
      while (temp) {
         NoA *prox = temp->next;
         free(temp);
         temp = prox;
      }
   }
   free(G->Adj);
   free(G);
}

/* Função para destruir um grafo construído com matriz de adjacências. */
void liberar_grafo_mat(GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      free(G->Mat[v]);
   }
   free(G->Mat);
   free(G);
}

int main () {
   int Va = 6; /* Número de vértices */

   GrafoA* Ga = criar_grafo_adj(Va);
   GrafoM* Gm = criar_grafo_mat(Va);

//Exercício 1 (não direcionado)
   /* Adicionar arestas */
   adicionar_aresta_adj(Ga, 4, 5);
   adicionar_aresta_adj(Ga, 5, 4);
   adicionar_aresta_adj(Ga, 2, 4);
   adicionar_aresta_adj(Ga, 4, 2);
   adicionar_aresta_adj(Ga, 1, 3);
   adicionar_aresta_adj(Ga, 3, 1);
   adicionar_aresta_adj(Ga, 0, 1);
   adicionar_aresta_adj(Ga, 1, 0);
   adicionar_aresta_adj(Ga, 0, 2);
   adicionar_aresta_adj(Ga, 2, 0);
   adicionar_aresta_adj(Ga, 1, 2);
   adicionar_aresta_adj(Ga, 2, 1);
   adicionar_aresta_adj(Ga, 2, 3);
   adicionar_aresta_adj(Ga, 3, 2);
   adicionar_aresta_adj(Ga, 3, 4);
   adicionar_aresta_adj(Ga, 4, 3);
   adicionar_aresta_adj(Ga, 0, 5);
   adicionar_aresta_adj(Ga, 5, 0);

   adicionar_aresta_mat(Gm, 0, 5);
   adicionar_aresta_mat(Gm, 5, 0);
   adicionar_aresta_mat(Gm, 2, 4);
   adicionar_aresta_mat(Gm, 4, 2);
   adicionar_aresta_mat(Gm, 1, 3);
   adicionar_aresta_mat(Gm, 3, 1);
   adicionar_aresta_mat(Gm, 0, 1);
   adicionar_aresta_mat(Gm, 1, 0);
   adicionar_aresta_mat(Gm, 0, 2);
   adicionar_aresta_mat(Gm, 2, 0);
   adicionar_aresta_mat(Gm, 1, 2);
   adicionar_aresta_mat(Gm, 2, 1);
   adicionar_aresta_mat(Gm, 2, 3);
   adicionar_aresta_mat(Gm, 3, 2);
   adicionar_aresta_mat(Gm, 3, 4);
   adicionar_aresta_mat(Gm, 4, 3);
   adicionar_aresta_mat(Gm, 4, 5);
   adicionar_aresta_mat(Gm, 5, 4);

//Exercício 2 (direcionado)

   /* Imprimir grafos */
   imprimir_grafo_mat(Gm);
   imprimir_grafo_adj(Ga);

   liberar_grafo_adj(Ga);
   liberar_grafo_mat(Gm);

   return 0;
}
