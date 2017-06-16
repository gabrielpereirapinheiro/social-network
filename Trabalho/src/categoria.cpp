#include "headers.hpp"


/** Funcao que cria o no de categoria */
noListaCategoria *criaNoCategoria(Categoria categoria){	/** Cria nó */ 

	noListaCategoria *no = (noListaCategoria*)malloc(sizeof(noListaCategoria));
	no->prox = NULL;
	no->categoria = categoria; 

	return no;
}

ListaCategoria *criarListaCategoria(){	/** Cria lista */ 

	ListaCategoria *lista_criada = (ListaCategoria*)malloc(sizeof(ListaCategoria));
	lista_criada->numeroCategorias = 0;

	return lista_criada;

}

/** Adiciona uma categoria na lista de categorias*/
/*Retorna 0 em caso sucesso e -1 caso contrario*/
int addNoListaCategoria(ListaCategoria *lista, noListaCategoria *no){	
	
	if(lista == NULL || no == NULL){
		printf("Erro na funcao addNoListaCategoria! Argumentos invalidos\n");
		return ERRO;
	}
	noListaCategoria *acompanha = lista->primeiro;

	//parte que vai atribuir um ID para as categorias e incrementar o numero de categorias na lista
	no->categoria.idCategoria = lista->numeroCategorias;
	lista->numeroCategorias++;

	while(acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	acompanha->prox = no;

	return SEM_ERRO;
}

/** Deleta uma categoria da lista de categorias pelo seu id*/
//Retorna 0 se a remocao tiver ocorrido com sucesso e -1, caso contrario
int deletaNoListaCategoria(ListaCategoria *lista, noListaCategoria *no){ 

	noListaCategoria *acompanha = lista->primeiro;
	noListaCategoria *anterior = NULL;

	while(acompanha->categoria.idCategoria != no->categoria.idCategoria && acompanha != NULL){

		anterior = acompanha;
		acompanha = acompanha->prox;
	}

	if(acompanha == NULL && (anterior->categoria.idCategoria != no->categoria.idCategoria)){

		printf("Erro na funcao deletaNoListaCategoria! Categoria nao existe na lista de categorias!\n");
		return ERRO;
	}
	else{
		
		if(acompanha != NULL && anterior != NULL){ /** Caso o nó esteja no meio da lista */

			anterior->prox = acompanha->prox;
		}
		else if(acompanha == NULL){ /** Caso o nó esteja no fim da lista */

			anterior->prox = NULL;
		}
		else if(anterior == NULL){ /** Caso o nó seja o primeiro da lista */

			lista->primeiro = acompanha->prox;
			acompanha->prox = NULL;
		}
	}
	free(no);

	return SEM_ERRO;
}

/** Procura uma categoria na lista de categorias */
//Retorna o no que esta procurando
noListaCategoria *encontraNoCategoria(noListaCategoria *inicio, Categoria categoria){	

	noListaCategoria *acompanha = inicio;	/** Primeiro no da lista */


	while(acompanha->categoria.idCategoria != categoria.idCategoria && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(acompanha->categoria.idCategoria != categoria.idCategoria){
		printf("Categoria nao existe na lista de categorias\n");
		return NULL;
	}
	else{

		return acompanha;
	}

}

//Funcao que libera a lista
//Retorna 0 se for liberada com sucesso e -1 se nao for
int LiberaListaCategoria(ListaCategoria *listaCategoria){

	if(listaCategoria){
		if(listaCategoria->primeiro){
			noListaCategoria *l = listaCategoria->primeiro, *q = NULL;
			while(l != NULL){
				q = l->prox;
				free(l);
				l = q;
			}	
		}
		free(listaCategoria);
	}else{
		printf("\nLista passada nao existe! Erro ao destruir lista de categorias!!\n");
		return ERRO;
	}

	return SEM_ERRO;	

}
/****************FIM***********************************/
