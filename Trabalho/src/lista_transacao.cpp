#include "headers.hpp"


//Funcao que cria o no de transacao
noListaTransacao *criaNoTransacao(Transacao transacao){	/** Cria nó */ 

	noListaTransacao *no = (noListaTransacao*)malloc(sizeof(noListaTransacao));
	no->prox = NULL;
	no->usuario = usuario; 

	return no;
}

lista_usuario *criarListaUsuario(Usuario usuario){	/** Cria lista */ 

	lista_usuario *lista_criada = (lista_usuario*)malloc(sizeof(lista_usuario));
	no_lista_usuario *no = criaNoUsuario(usuario);
	lista_criada->primeiro = no;

	return lista_criada;

}

int addNoListaUsuario(lista_usuario *lista, no_lista_usuario *no){	/** Adiciona nó na lista */

	no_lista_usuario *acompanha = lista->primeiro;
	while(acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	acompanha->prox = no;
}

int deletaNoListaUsuario(lista_usuario *lista, no_lista_usuario *no){ /** Deleta um nó da lista encadeada */

	no_lista_usuario *acompanha = lista->primeiro;
	no_lista_usuario *anterior = NULL;

	while(acompanha->usuario.CPF != no->usuario.CPF && acompanha != NULL){

		anterior = acompanha;
		acompanha = acompanha->prox;
	}

	if(acompanha == NULL && anterior->usuario.CPF != no->usuario.CPF){

		printf("Vertice nao existe!\n");
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
}

no_lista_usuario *encontraNoUsuario(no_lista_usuario *inicio, Usuario usuario){	/** Procura vértice na lista */

	no_lista_usuario *acompanha = inicio;	/** Primeiro vértice da lista */

	while(acompanha->usuario.CPF != usuario.CPF && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(acompanha->usuario.CPF != usuario.CPF){

		return NULL;
	}
	else{

		return acompanha;
	}

}
/****************FIM***********************************/
