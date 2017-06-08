#ifndef GRAFO_HPP
#define GRAFO_HPP 

typedef struct valor{
	char valor_vert;
}valor;
typedef struct no_lista_adj{
	int vertice;
	int aresta;
	struct no_lista_adj *prox;
}no_lista_adj;														 
typedef struct lista_adj{					
	no_lista_adj *primeiro;
}lista_adj;
typedef struct no_lista{
	int vertice;
	struct no_lista *prox;
	no_lista_adj *adj;
}no_lista;
typedef struct lista{
	no_lista *primeiro;
}lista;
typedef struct grafo{						
	char nome[20];
	lista *l_encadeada;
}grafo;

grafo *cria_grafo(char *nome);
char *retorna_nome_grafo(grafo *G);
void destroi_grafo(grafo *G);
int adjacente(grafo *G, int x, int y);
void adiciona_vertice(grafo *G, int x);
void adiciona_aresta(grafo *G, int x, int y);
int retorna_valor_aresta(grafo *G, int x, int y);
lista_adj *vizinhos(grafo *G, int x);
void remove_vertice(grafo *G, int x);
void muda_valor_aresta(grafo *G, int x, int y, int v);
void remove_aresta(grafo *G, int x, int y);
char *retorna_valor_vertice(grafo *G, int x);
void muda_valor_vertice(grafo *G, int x, char *v);

#endif
