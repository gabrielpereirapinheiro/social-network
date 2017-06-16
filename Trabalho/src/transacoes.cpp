#include "headers.hpp"


/** Funcao que cria o no de transacao */
noListaTransacao *criaNoTransacao(Transacao transacao){	/** Cria nó */ 

	noListaTransacao *no = (noListaTransacao*)malloc(sizeof(noListaTransacao));
	no->prox = NULL;
	no->transacao = transacao; 

	return no;
}

ListaTransacao *criarListaTransacao(Transacao transacao){	/** Cria lista */ 

	ListaTransacao *lista_criada = (ListaTransacao*)malloc(sizeof(ListaTransacao));

	return lista_criada;

}

/** Adiciona uma transacao na lista de transacoes*/
/*Retorna 0 em caso sucesso e -1 caso contrario*/
int addNoListaTransacao(ListaTransacao *lista, noListaTransacao *no){	
	
	if(lista == NULL || no == NULL){
		printf("Erro na funcao addNoListaTransacao! Argumentos invalidos\n");
		return ERRO;
	}
	noListaTransacao *acompanha = lista->primeiro;
	while(acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	acompanha->prox = no;

	return SEM_ERRO;
}

/** Deleta uma transacao da lista de transacoes pelo seu id*/
//Retorna 0 se a remocao tiver ocorrido com sucesso e -1, caso contrario
int deletaNoListaTransacao(ListaTransacao *lista, noListaTransacao *no){ 

	noListaTransacao *acompanha = lista->primeiro;
	noListaTransacao *anterior = NULL;

	while(acompanha->transacao.idTransacao != no->transacao.idTransacao && acompanha != NULL){

		anterior = acompanha;
		acompanha = acompanha->prox;
	}

	if(acompanha == NULL && (anterior->transacao.idTransacao != no->transacao.idTransacao)){

		printf("Erro na funcao deletaNoListaTransacao! Transacao nao existe na lista de transacoes!\n");
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

/** Procura uma transacao na lista de transacoes */
//Retorna o no que esta procurando
noListaTransacao *encontraNoTransacao(noListaTransacao *inicio, Transacao transacao){	

	noListaTransacao *acompanha = inicio;	/** Primeiro no da lista */


	while(acompanha->transacao.idTransacao != transacao.idTransacao && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(acompanha->transacao.idTransacao != transacao.idTransacao){
		printf("Transacao nao existe na lista de transacoes\n");
		return NULL;
	}
	else{

		return acompanha;
	}

}

//Funcao que libera a lista
//Retorna 0 se for liberada com sucesso e -1 se nao for
int LiberaListaTransacao(ListaTransacao *listaTransacao){

	if(listaTransacao){
		if(listaTransacao->primeiro){
			noListaTransacao *l = listaTransacao->primeiro, *q = NULL;
			while(l != NULL){
				q = l->prox;
				free(l);
				l = q;
			}	
		}
		free(listaTransacao);
	}else{
		printf("\nLista passada nao existe! Erro ao destruir lista de transacoes!!\n");
		return ERRO;
	}

	return SEM_ERRO;	

}
/****************FIM***********************************/
