#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************/
typedef struct valor{					   //Struct que representa o valor contido 
  										   //dentro de um vértice. Obs.: valor contido 
	char valor_contido[20];				   //dentro do vértice é diferente do id do vértice,
										   //que nesse código é representado pela variável int vértice
}valor; 

typedef struct no_lista_adj{

	int vertice; 
	int aresta;
	struct no_lista_adj *prox;

}no_lista_adj;								//Def dos nós e das
											//listas usadas 
typedef struct lista_adj{					//que formam o grafo

	no_lista_adj *primeiro;

}lista_adj;

typedef struct no_lista{

	int vertice;
	valor *ptr;								//Vetor para um valor char[20] contido dentro do vértice
	struct no_lista *prox;
	no_lista_adj *adj;

}no_lista;

typedef struct lista{

	no_lista *primeiro;

}lista;

typedef struct grafo{						//definição do tipo grafo

	char nome[20];
	lista *l_encadeada;

}grafo;
/*****************************************************/

/*************LISTA***********************************/
static no_lista * criaNo(int vertice){	//Cria nó 

	no_lista *no = (no_lista*)malloc(sizeof(no_lista));
	no->prox = NULL;
	no->vertice = vertice;
	no->adj = NULL;
	no->ptr = (valor*)malloc(sizeof(valor*));
	strcpy(no->ptr->valor_contido,"\0"); //Inicializando o valor como vazio

	return no;
}

static lista *criarLista(int vertice){	//Cria lista 

	lista *lista_criada = (lista*)malloc(sizeof(lista));
	no_lista *no = criaNo(vertice);
	lista_criada->primeiro = no;

	return lista_criada;

}

static void addNoLista(lista *lista, no_lista *no){	//Adiciona nó na lista

	no_lista *acompanha = lista->primeiro;
	while(acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	acompanha->prox = no;
}

static void deletaNoLista(lista *lista, no_lista *no){ //Deleta um nó da lista encadeada

	no_lista *acompanha = lista->primeiro;
	no_lista *anterior = NULL;

	while(acompanha->vertice != no->vertice && acompanha != NULL){

		anterior = acompanha;
		acompanha = acompanha->prox;
	}

	if(acompanha == NULL && anterior->vertice != no->vertice){

		printf("Vertice nao existe!\n");
	}
	else{
		
		if(acompanha != NULL && anterior != NULL){ //Caso o nó esteja no meio da lista

			anterior->prox = acompanha->prox;
		}
		else if(acompanha == NULL){ //Caso o nó esteja no fim da lista

			anterior->prox = NULL;
		}
		else if(anterior == NULL){ //Caso o nó seja o primeiro da lista

			lista->primeiro = acompanha->prox;
			acompanha->prox = NULL;
		}
	}
	free(no);
}

static no_lista *encontraNo(no_lista *inicio, int vertice){	//Procura vértice na lista

	no_lista *acompanha = inicio;	//Primeiro vértice da lista

	while(acompanha->vertice != vertice && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(acompanha->vertice != vertice){

		return NULL;
	}
	else{

		return acompanha;
	}

}
/****************FIM***********************************/

/*************LISTA ADJ********************************/
static no_lista_adj * criaNoAdj(int aresta, int vertice){	//Cria nó adjacente

	no_lista_adj *no = (no_lista_adj*)malloc(sizeof(no_lista_adj));
	no->prox = NULL;
	no->aresta = aresta;
	no->vertice = vertice;

	return no;
}

static lista_adj *criarListaAdj(int aresta, int vertice){	//Cria Lista Adjacente

	lista_adj *lista_criada = (lista_adj*)malloc(sizeof(lista_adj));
	no_lista_adj *no = criaNoAdj(aresta, vertice);
	lista_criada->primeiro = no;

	return lista_criada;

}

static void addNoListaAdj(lista_adj *lista, no_lista_adj *no){	//Adiciona nó na lista adjacente

	no_lista_adj *acompanha = lista->primeiro;
	while(acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	acompanha->prox = no;

}

static void deletaNoListaAdj(no_lista *inicio_lista, no_lista_adj *no){ //Deleta um nó da lista adjacente

	no_lista_adj *acompanha = inicio_lista->adj;
	no_lista_adj *anterior = NULL;

	while(acompanha->vertice != no->vertice && acompanha != NULL){

		anterior = acompanha;
		acompanha = acompanha->prox;
	}

	if(acompanha == NULL && anterior->vertice != no->vertice){

		printf("Vertice nao existe!\n");
	}
	else{

		if(acompanha != NULL && anterior != NULL){ //Caso o nó esteja no meio da lista

			anterior->prox = acompanha->prox;
		}
		else if(acompanha == NULL){ //Caso o nó esteja no fim da lista

			anterior->prox = NULL;
		}
		else if(anterior == NULL){ //Caso o nó seja o primeiro da lista

			inicio_lista->adj = acompanha->prox;
			acompanha->prox = NULL;
		}
	}

	free(no);
}

static no_lista_adj *encontraNoAdj(no_lista_adj *inicio, int vertice){	//Procura vértice na lista adjacente

	no_lista_adj *acompanha = inicio;	//Primeiro vértice da lista

	while(acompanha != NULL){

		if(acompanha->vertice == vertice ){
			
			return acompanha;
		}
		acompanha = acompanha->prox;
	}

	return NULL;
}
/*********************************************************/

grafo *cria_grafo(char *nome){	//Cria grafo

	grafo *G = (grafo*)malloc(sizeof(grafo));
	G->l_encadeada = criarLista(0); 	//0 é o valor do primeiro vértice por padrão
	strcpy(G->nome,nome);
	return G;

}

char *retorna_nome_grafo(grafo *G){	//Retorna o nome do grafo

	return G->nome;
}

void destroi_grafo(grafo *G){	//Destrói o grafo

	if(G == NULL){

		printf("Nao ha grafos para serem excluidos\n");
	}
	else{

		no_lista *acompanha = G->l_encadeada->primeiro; 
		no_lista_adj *aux1 = acompanha->adj;
		no_lista_adj *aux2 = acompanha->adj;

		/*Libera um nó por vez de cada lista adjacente*/
		while(acompanha != NULL){
			
			while(aux1 != NULL){

				if(aux1->prox == NULL){

					if(acompanha->adj == aux1){

						free(aux1);
						acompanha->adj = NULL;
						break;
					}
					else{

						aux2->prox = NULL;
						aux1 = acompanha->adj;
					}

				}
				else{

					aux2 = aux1;
					aux1 = aux1->prox;
					
				}
			}

			acompanha = acompanha->prox;
			
			if(acompanha != NULL){
				
				aux1 = acompanha->adj;
				aux2 = acompanha->adj;
			}
		}

		acompanha = G->l_encadeada->primeiro;
		no_lista *acompanha_aux = acompanha;

		/*Libera um nó por vez da lista principal*/
		while(acompanha != NULL){

			if(acompanha->prox == NULL){

				if(acompanha == G->l_encadeada->primeiro){

					free(acompanha);
					G->l_encadeada->primeiro = NULL;
					break;
				}
				else{

					free(acompanha);
					acompanha_aux->prox = NULL;
					acompanha = G->l_encadeada->primeiro;
					acompanha_aux = acompanha;
				}

			}
			else{

				acompanha_aux = acompanha;
				acompanha = acompanha->prox;
			}
		}

		/*Libera espaço alocado para o grafo
		  após todos os vértices terem sido
		  liberados*/

		free(G);
		printf("Grafo destruido!\n");
	}

} 

int adjacente(grafo *G, int x, int y){	//Verifica adjacencia

	no_lista *acompanha = encontraNo(G->l_encadeada->primeiro, y);

	if(acompanha == NULL){	//Verifica se y existe

		printf("Nao existe vertice %d\n",y);
	}
	else{

		no_lista *acompanha = encontraNo(G->l_encadeada->primeiro, x);

		if(acompanha == NULL){	//Verifica se x existe

			printf("Nao existe vertice %d\n",x);
		}
		else{	//Caso ambos existam, verifica adjacencia
			no_lista_adj *aux = encontraNoAdj(acompanha->adj, y);

			if(aux != NULL){

				printf("Sao adjacentes!\n");
				return 1;	//Verdadeiro
			}
			else{

				no_lista *acompanha = encontraNo(G->l_encadeada->primeiro, y);
				no_lista_adj *aux = encontraNoAdj(acompanha->adj, x);

				if(aux != NULL){

					printf("Sao adjacentes!\n");
					return 1; //Verdadeiro
				}
				else{

					printf("Nao sao adjacentes!\n");
					return 0; //Falso
				}
			}
		}
	}
}

void adiciona_vertice(grafo *G, int x){ //Adiciona vértice

	if(G->l_encadeada == NULL){
		
			G->l_encadeada = criarLista(x);
	}
	else{
		
		no_lista *acompanha = encontraNo(G->l_encadeada->primeiro, x);	/*Verificação da existência do vértice*/

		if(acompanha == NULL){	//Vértice ainda não existe

			if(G->l_encadeada == NULL){

				G->l_encadeada = criarLista(x);

			}
			else{

				no_lista *no = criaNo(x);
				addNoLista(G->l_encadeada, no);

			}
		}
		else{	//Vértice já existe

			printf("Vertice %d ja existe!\n",x);
		}
	}
}

void adiciona_aresta(grafo *G, int x, int y){ //Adiciona aresta com valor padrão igual a 0 saindo de x e indo para y

	no_lista *aux1 = encontraNo(G->l_encadeada->primeiro, x);
	no_lista *aux = encontraNo(G->l_encadeada->primeiro,y);

	if(aux1 == NULL){

		printf("Vertice %d nao existe\n",x);
	}
	else if(aux == NULL){

		printf("Vertice %d nao existe\n",y);
	}
	else{

		no_lista_adj *verifica = encontraNoAdj(aux1->adj, y);
		no_lista_adj *aux2 = aux1->adj;

		if(verifica != NULL){

			printf("Ja existe aresta saindo de %d e indo para %d\n",x,y);

		}
		else if(aux2 == NULL){

			no_lista_adj *novo_no_adj = criaNoAdj(0, y); //0 é o valor padrão da aresta
			aux1->adj = novo_no_adj;

		}
		else{

			while(aux2->prox != NULL){

				aux2 = aux2->prox; 
			}

			no_lista_adj *novo_no_adj = criaNoAdj(0, y); //0 é o valor padrão da aresta
			aux2->prox = novo_no_adj;
		}
	}
}

int retorna_valor_aresta(grafo *G, int x, int y){	//Retorna o valor da aresta 

	no_lista *aux1 = encontraNo(G->l_encadeada->primeiro, x);

	if(aux1 == NULL){

		printf("Nao ha vertice %d\n",x);
		return -1;
	}
	else{
		
		no_lista_adj *aux2 = encontraNoAdj(aux1->adj, y);

		if(aux2 == NULL){

			printf("Nao ha aresta ou nao ha vertice %d\n",y);
			return -1;
		}
		else{

			return aux2->aresta;
		} 
	}
}

lista_adj *vizinhos(grafo *G, int x){	//Retorna lista de vizinhos de um vértice específico

	no_lista *aux = encontraNo(G->l_encadeada->primeiro, x);
	if(aux == NULL){

		printf("Tal vertice nao existe!\n");
		return NULL;
	}
	else{
		
		no_lista_adj *acompanha = aux->adj;
		if(acompanha == NULL){

			printf("O vertice %d nao possui vizinhos!\n",x);
			return NULL;
		}
		else{
																					/*Valor zero usado sem significado,*/
			lista_adj *lista_de_vizinhos = criarListaAdj(0,acompanha->vertice); 	/*pois essa é uma lista de retorno,*/
			acompanha = acompanha->prox;											/*ou seja, os valores das arestas não*/
																					/*fazem diferença.*/
			while(acompanha != NULL){							
 
				addNoListaAdj(lista_de_vizinhos,criaNoAdj(0,acompanha->vertice));
				acompanha = acompanha->prox;
			}

			return lista_de_vizinhos;
		}
	}
}
 
void remove_vertice(grafo *G, int x){	//Remove vértice x do grafo G
										//Obs.: Ao remover um vértice, as arestas são removidas juntas!

	no_lista *acompanha = G->l_encadeada->primeiro;
	no_lista_adj *aux = NULL;

	while(acompanha != NULL){		//Varredura de todas as listas de adjacencia 

		aux = encontraNoAdj(acompanha->adj, x);

		if(aux == NULL){
			//Não faz nada
		}
		else{

			deletaNoListaAdj(acompanha, aux);	
		}

		acompanha = acompanha->prox;
	}

	acompanha = encontraNo(G->l_encadeada->primeiro, x);
	if(acompanha == NULL){

		printf("Vertice %d nao existe\n",x);
	}
	else{
 
		deletaNoLista(G->l_encadeada, acompanha);
	}

}

void muda_valor_aresta(grafo *G, int x, int y, int v){	//Muda o valor da aresta que sai de x e vai para y

	no_lista *encontrado = encontraNo(G->l_encadeada->primeiro, x);
	no_lista_adj *aux = NULL;

	if(encontrado == NULL){ //Tratamento de exceções

		printf("Nao ha vertice %d\n",x); 
	}
	else{

		aux = encontraNoAdj(encontrado->adj, y);
		
		if(aux == NULL){ //Tratamento de exceções

			printf("Nao ha vertice %d ou %d e %d nao tem aresta em comum\n",y,x,y);
		}
		else{
			aux->aresta = v;
		}
	}
}

void remove_aresta(grafo *G, int x, int y){	//Remoção da aresta que vai do vértice x para o vértice y

	no_lista *encontrado = encontraNo(G->l_encadeada->primeiro, x);
	no_lista_adj *aux = NULL;

	if(encontrado == NULL){

		printf("Nao ha vertice %d\n",x);
	}
	else{

		encontraNoAdj(encontrado->adj, y);

		if(aux == NULL){

			printf("Nao ha vertice ou %d e %d nao tem aresta em comum\n",x,y);
		}
		else{

			deletaNoListaAdj(encontrado, aux);
		}
	}
} 

char *retorna_valor_vertice(grafo *G, int x){	//Função que retorna um ponteiro char com o valor contido no vértice

	no_lista *acompanha = encontraNo(G->l_encadeada->primeiro, x);

	if(acompanha == NULL){

		printf("Nao existe tal vertice\n");
	}
	else{

		return acompanha->ptr->valor_contido;
	}
}

void muda_valor_vertice(grafo *G, int x, char *v){	//Função que altera o valor do contido no vértice. Sem retorno

	int  i = 0;
	no_lista *acompanha = encontraNo(G->l_encadeada->primeiro, x);

	if(acompanha == NULL){

		printf("Nao existe tal vertice\n");
	}
	else{
		
		strcpy(acompanha->ptr->valor_contido, v);
	}
} 
