#include "grafos.h"

/*Victor Araujo Vieira - 14/0032801 */
/*MP - 1/2017*/

/*Funcao que cria um grafo e da um nome para ele*/
Grafo *cria_grafo(char *nome){
	int tam_nome_grafo = strlen(nome) + 1;

	Grafo *g = (Grafo*)malloc(sizeof(Grafo));
	if(g == NULL){
		printf("Nao foi possivel alocar o grafo!\n");
		exit(1);
	}
	/*a principio, o grafo nao tem nenhuma aresta e nenhum vertice*/
	g->V = 0;
	g->E = 0;
	g->nomeGrafo = NULL;
	g->tipoUsadoValor = 1; /*dependendo do valor, o tipo do valor usado vai mudar*/
	g->vertices = NULL;
	g->nomeGrafo = (char*)malloc(tam_nome_grafo*sizeof(char));
	if(g->nomeGrafo == NULL){
		printf("Nao foi possivel alocar o nome do grafo!\n");
		exit(1);
	}
	strcpy(g->nomeGrafo, nome); /*copia a string passada como argumento para o nome do grafo*/

	return g;
}

/*Funcao que retorna o nome do grafo*/
char *retorna_nome_grafo(Grafo *G){
	
	return G->nomeGrafo;
}

/*Funcao que libera o grafo*/
int destroi_grafo(Grafo *G){

	if(G){
		if(G->vertices){
			Vertice *v = G->vertices, *q = NULL;
			while(v != NULL){
				if(v->listVizinhos){
					Vizinhos *p = v->listVizinhos, *t = NULL;
					while(p != NULL){
						t = p->prox;
						free(p);
						p = t;
					}
				}
				q = v->prox;
				free(v);
				v = q;
			}	
		}
		free(G->nomeGrafo);
		free(G);
	}else{
		printf("\nGrafo passado nao existe! Erro ao destruir grafo!\n");
		return ERRO;
	}

	return SEM_ERRO;
}

/*Funcao que verifica se os vertices x e y sao adjacentes*/
int adjacente(Grafo *G, int x, int y){
	Vizinhos *viz = NULL;

	/*se a funcao de validar as arestas nao retornar verdadeiro, sai da funcao*/
	if(!valida_funcoes_aresta(G, x, y)){
		printf("Saindo da funcao adjacente\n\n");
		return ERRO;
	}

	/*parte que vai verificar se sao adjacentes*/
	for(viz = vizinhos(G, x); viz != NULL; viz = viz->prox){
		if(viz->id == y) return 1; /*se tiver y na lista de adjacencias de x, sao adjacentes*/
	}

	return 0; /*retorna falso caso nao sejam adjacentes*/
}

/*Funcao que percorre a lista de vertices e verifica se o vertice x existe ou nao no grafo*/
int verifica_se_existe_vertice(Grafo *G, int x){
	Vertice *p = NULL;

	for(p = G->vertices; p != NULL; p = p->prox){
		if(p->idVertice == x) return 1; /*Se existir o vertice no grafo, retorna 1*/
	}

	return 0; /*Por definicao, assumir que nao existe o vertice no grafo*/
}

/*Funcao que retorna o ponteiro do vertice x*/
Vertice *recupera_vertice_x(Grafo *G, int x){
	Vertice *v = NULL, *p = NULL;

	for(p = G->vertices; p != NULL; p = p->prox){
		if(p->idVertice == x){
			v = p; /*v recebera o ponteiro para o no*/
		}
	}

	return v;
}

/*Funcao que verifica se o vertice y ja existe na lista de arestas do vertice v*/
int verifica_se_y_aresta_de_x(Vertice *v, int y){
	Vizinhos *q = NULL;
	if(v == NULL) return 0;

	if(v->listVizinhos){
		for(q = v->listVizinhos; q != NULL; q = q->prox){
			if(q->id == y){
				return 1; /*retorna verdadeiro caso y ja seja aresta de x*/
			}
		}
	}

	return 0; /*retorna falso por definicao*/
}

/*Funcao que vai validar se a funcao adiciona_aresta, remove_aresta, muda_valor_aresta e retorna_valor_aresta respeita os requisitos para executar*/
int valida_funcoes_aresta(Grafo *G, int x, int y){
	int flagX = 0, flagY = 0; /*flags para verificar se os vertices nao existem no grafo*/

	/*Parte que vai verificar se existem ou nao os vertices que deseja-se inserir a aresta*/
	if(verifica_se_existe_vertice(G, x)) flagX = 1;
	if(verifica_se_existe_vertice(G, y)) flagY = 1;

	/*Se um ou o outro nao existirem, sai da funcao*/
	if(flagX == 0 || flagY == 0){
		if(flagX == 0) printf("\nNao existe o vertice %d no grafo!\n", x);
		if(flagY == 0) printf("\nNao existe o vertice %d no grafo!\n", y);
		return 0; /*nao validadas*/
	} 

	return 1; /*por definicao, vai validar*/
}

/*Funcao que adiciona um vertice ao grafo*/
int adiciona_vertice(Grafo *G, int x){
	Vertice *v = NULL;
	
	if(verifica_se_existe_vertice(G, x)){
		printf("\nJa existe o vertice %d no grafo! Nao sera inserido!\n", x);
		printf("Saindo da funcao adiciona_vertice\n\n");
		return ERRO;
	}

	v = (Vertice*)malloc(sizeof(Vertice));
	if(v == NULL){
		printf("Nao foi possivel alocar o vertice\n");
		exit(1);
	}
	/*instancia os valores e coloca esse vertice no grafo*/
	G->V++;
	v->idVertice = x;
	v->numArestas = 0;
	v->listVizinhos = NULL;
	v->prox = G->vertices;
	G->vertices = v;
	
	return SEM_ERRO;
}

/*Funcao que remove um vertice do grafo*/
int remove_vertice(Grafo *G, int x){
	Vertice *anterior = NULL, *p = G->vertices; //p eh o ponteiro para percorrer a lista
	/*anterior vai receber o elemento antecessor da lista sendo percorrida*/

	while(p != NULL && p->idVertice != x){
		anterior = p;
		p = p->prox;
	}

	/*Se nao achar o vertice, encerra funcao*/
	if(p == NULL){
		printf("\nNao existe o vertice %d no grafo para ser retirado!\n", x);
		printf("Saindo da funcao remove_vertice\n\n");
		return ERRO;
	}
	/*Se anterior for NULL, quer dizer que o elemento a ser retirado eh o elemento do inicio*/
	/*senao, esta no meio da lista ou no final*/
	if(anterior == NULL){
		G->vertices = p->prox;
	}else{
		anterior->prox = p->prox;
	}

	/*Se o vertice a ser removido tiver vizinhos, parte que libera os vizinhos*/
	if(p->listVizinhos){
		Vizinhos *q = p->listVizinhos, *t = NULL;
		while(q != NULL){
			t = q->prox;
			free(q);
			q = t;
		}
	}
	G->V--; /*decrementa o numero de vertices no grafo*/

	free(p); /*libera o vertice que foi removido*/

	return SEM_ERRO;
}

/*Funcao que adiciona aresta entre os vertices x e y no grafo*/
int adiciona_aresta(Grafo *G, int x, int y){
	Vertice *v = NULL;
	Vizinhos *viz = NULL;

	/*se a funcao de validar as arestas nao retornar verdadeiro, sai da funcao*/
	if(!valida_funcoes_aresta(G, x, y)){
		printf("Saindo da funcao adiciona_aresta\n\n");
		return ERRO;
	} 

	/*Recuperacao do vertice x*/
	v = recupera_vertice_x(G, x);

	/*Verifica se ja tem o vertice y na lista de arestas do vertice x*/
	if(verifica_se_y_aresta_de_x(v, y)){
		printf("\nO vertice %d ja eh adjacente do vertice %d! Funcao encerrada\n", y, x);
		printf("Saindo da funcao adiciona_aresta\n\n");
		return ERRO;
	}
	
	/*criacao da aresta*/
	viz = (Vizinhos*)malloc(sizeof(Vizinhos));
	if(viz == NULL){
		printf("Nao foi possivel alocar a aresta!\n");
		exit(1);
	}

	G->E++; /*numero de arestas do grafo incrementado*/
	v->numArestas++; /*numero de arestas do vertice incrementado*/
	viz->id = y;
	viz->prox = v->listVizinhos;
	v->listVizinhos = viz;

	return SEM_ERRO;
}

/*Funcao que remove a aresta que vai de x para y*/
int remove_aresta(Grafo *G, int x, int y){
	Vizinhos *anterior = NULL, *p = NULL; /*anterior vai receber o elemento antecessor da lista sendo percorrida*/
	Vertice *v = NULL;
	
	/*se a funcao de validar as arestas nao retornar verdadeiro, sai da funcao*/
	if(!valida_funcoes_aresta(G, x, y)){
		printf("Saindo da funcao remove_aresta\n\n");
		return ERRO;
	} 

	/*Recuperacao do vertice x*/
	v = recupera_vertice_x(G, x);

	/*Verifica se existe o vertice y na lista de arestas do vertice x*/
	if(!verifica_se_y_aresta_de_x(v, y)){
		printf("\nO vertice %d nao eh adjacente do vertice %d!\n", y, x);
		printf("Saindo da funcao remove_aresta\n\n");
		return ERRO;
	}

	/*Parte da funcao responsavel por remover a aresta de fato da lista de arestas do vertice x*/
	p = v->listVizinhos;
	while(p != NULL && p->id != y){
		anterior = p;
		p = p->prox;
	}

	/*Se anterior for NULL, quer dizer que o elemento a ser retirado eh o elemento do inicio*/
	/*senao, esta no meio da lista ou no final*/
	if(anterior == NULL){
		v->listVizinhos = p->prox;
	}else{
		anterior->prox = p->prox;
	}

	G->E--;
	v->numArestas--;

	free(p); /*libera a aresta que foi removida*/

	return SEM_ERRO;
}

/*Funcao que retorna a lista de todos os vertices que podem ser visitados a partir de x*/
Vizinhos *vizinhos(Grafo *G, int x){
	Vertice *v = NULL;

	/*verifica se existe o vertice x no grafo*/
	if(!verifica_se_existe_vertice(G, x)){
		printf("\nNao existe o vertice %d no grafo!\n", x);
		printf("Saindo da funcao vizinhos\n\n");
		return NULL;
	}

	/*recupera o vertice x*/
	v = recupera_vertice_x(G, x);
	/*se o vertice x nao tiver vizinhos*/
	if(!v->listVizinhos){
		printf("\nO vertice %d nao possui vizinhos!\n", x);
		printf("Saindo da funcao vizinhos\n\n");
		return NULL;
	} 

	return v->listVizinhos; /*por definicao, retorna a lista dos vizinhos do vertice x*/

}

/*Funcao que muda o valor que esta contido no vertice x do grafo*/
int muda_valor_vertice(Grafo *G, int x, Valor v){
	Vertice *vert = NULL;

	/*Verifica se existe o vertice x no grafo*/
	if(!verifica_se_existe_vertice(G, x)){
		printf("\nNao existe o vertice %d no grafo!\n", x);
		printf("Saindo da funcao muda_valor_vertice\n\n");
		return ERRO;
	}

	/*retorna em vert o vertice x*/
	vert = recupera_vertice_x(G, x);
	vert->valorVertice = v;

	return SEM_ERRO;
}

/*Funcao que retorna o valor que esta contido no vertice x do grafo*/
Valor retorna_valor_vertice(Grafo *G, int x){
	Vertice *vert = NULL;
	Valor val;

	/*Verifica se existe o vertice x no grafo*/
	if(!verifica_se_existe_vertice(G, x)){
		printf("\nNao existe o vertice %d no grafo!\n", x);
		printf("Saindo da funcao retorna_valor_vertice\n\n");
		return val;
	}

	vert = recupera_vertice_x(G, x);

	return vert->valorVertice;

}

/*Funcao que muda o valor da aresta que liga o vertice x e y*/
int muda_valor_aresta(Grafo *G, int x, int y, Valor v){
	Vizinhos *viz = NULL;
	Vertice *vert = NULL;

	/*se a funcao de validar as arestas nao retornar verdadeiro, sai da funcao*/
	if(!valida_funcoes_aresta(G, x, y)){
		printf("Saindo da funcao muda_valor_aresta\n\n");
		return ERRO;
	} 

	vert = recupera_vertice_x(G, x);

	/*Verifica se existe o vertice y na lista de arestas do vertice x*/
	if(!verifica_se_y_aresta_de_x(vert, y)){
		printf("\nO vertice %d nao eh adjacente do vertice %d!\n", y, x);
		printf("Saindo da funcao muda_valor_aresta\n\n");
		return ERRO;
	}

	for(viz = vert->listVizinhos; viz != NULL; viz = viz->prox){
		if(viz->id == y){
			viz->valorAresta = v; /*novo valor da aresta eh v*/
		}
	}

	return SEM_ERRO;
}

/*Funcao que retorna o valor da aresta que liga o vertice x e y*/
Valor retorna_valor_aresta(Grafo *G, int x, int y){
	Vertice *vert = NULL;
	Vizinhos *viz = NULL;
	Valor val, valorRetorno;

	/*se a funcao de validar as arestas nao retornar verdadeiro, sai da funcao*/
	if(!valida_funcoes_aresta(G, x, y)){
		printf("Saindo da funcao retorna_valor_aresta\n\n");
		return val;
	} 

	vert = recupera_vertice_x(G, x);

	/*Verifica se existe o vertice y na lista de arestas do vertice x*/
	if(!verifica_se_y_aresta_de_x(vert, y)){
		printf("\nO vertice %d nao eh adjacente do vertice %d!\n", y, x);
		printf("Saindo da funcao retorna_valor_aresta\n\n");
		return val;
	}

	for(viz = vert->listVizinhos; viz != NULL; viz = viz->prox){
		if(viz->id == y){
			valorRetorno = viz->valorAresta; /*novo valor da aresta eh v*/
		}
	}


	return valorRetorno;
}