#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Victor Araujo Vieira - 14/0032801 */
/*MP - 1/2017*/

/*Definicoes das structs que serao usadas para modelar o grafo*/
/*Struct que define o tipo valor, que eh um tipo arbitrario*/
typedef struct valor{
	char val[50]; /*Dependendo do tipo que vai ser usado, vai ser convertido para esse tipo*/
}Valor;

/*Struct que define os vizinhos dos vertices do grafo, que sera representado na forma de lista encadeada*/
typedef struct vizinho{
	int id; /*Corresponde ao identificador do vertice no grafo*/
	Valor valorAresta; /*valor da aresta*/
	struct vizinho *prox;
}Vizinhos;

/*Struct que define o vertice do grafo, que sera representado na forma de lista encadeada*/
typedef struct vertice{
	int idVertice; /*identificador do vertice no grafo*/
	Valor valorVertice; /*valor associado ao no*/
	int numArestas; /*numero de arestas do vertice*/
	Vizinhos *listVizinhos; /*os vizinhos do vertice*/
	struct vertice *prox;
}Vertice;

/*Struct que define o grafo*/
typedef struct grafo{
	char *nomeGrafo; /*nome do grafo*/
	int tipoUsadoValor; /*Flag que definira qual o tipo que o valor vai assumir*/
	/*0 - Erro, 1 - inteiro, 2 - string, 3 - float, 4 - double*/
	int V; /*numero de vertices do grafo*/
	int E; /*numero de arestas do grafo*/
	Vertice *vertices; /*o grafo em si, sera composta por uma lista encadeada, e cada elemento da lista, vai conter outra lista com os nos adjacentes*/
}Grafo;

/*Variaveis globais usadas para indicar ou nao erro*/
#define ERRO -1
#define SEM_ERRO 1

/*Assinatura das funcoes implementadas na biblioteca de grafos*/
Grafo *cria_grafo(char *nome);
int verifica_se_existe_vertice(Grafo *G, int x);
Vertice *recupera_vertice_x(Grafo *G, int x);
int verifica_se_y_aresta_de_x(Vertice *v, int y);
int valida_funcoes_aresta(Grafo *G, int x, int y);
char *retorna_nome_grafo(Grafo *G);
int destroi_grafo(Grafo *G);
int adjacente(Grafo *G, int x, int y);
Vizinhos *vizinhos(Grafo *G, int x); 
int adiciona_vertice(Grafo *G, int x);
int remove_vertice(Grafo *G, int x);
int adiciona_aresta(Grafo *G, int x, int y);
int remove_aresta(Grafo *G, int x, int y);
Valor retorna_valor_vertice(Grafo *G, int x);
int muda_valor_vertice(Grafo *G, int x, Valor v);
Valor retorna_valor_aresta(Grafo *G, int x, int y);
int muda_valor_aresta(Grafo *G, int x, int y, Valor v);