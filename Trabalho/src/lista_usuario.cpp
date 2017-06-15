#include "headers.hpp"


/*************LISTA***********************************/
no_lista_usuario * criaNoUsuario(Usuario usuario){	/** Cria nó */ 

	no_lista_usuario *no = (no_lista_usuario*)malloc(sizeof(no_lista_usuario));
	no->prox = NULL;
	no->usuario = usuario; 

	return no;
}

lista_usuario *criarListaUsuario(){	/** Cria lista */ 

	lista_usuario *lista_criada = (lista_usuario*)malloc(sizeof(lista_usuario));
	/*no_lista_usuario *no = criaNoUsuario(usuario);
	lista_criada->primeiro = no;*/

	return lista_criada;

}

void addNoListaUsuario(lista_usuario *lista, no_lista_usuario *no){	/** Adiciona nó na lista */

	no_lista_usuario *acompanha = lista->primeiro;

	if (acompanha == NULL){

		lista->primeiro = no;
	}
	else{
		
		while(acompanha->prox != NULL){

			acompanha = acompanha->prox;
		}

		acompanha->prox = no;
	}
}

void deletaNoListaUsuario(lista_usuario *lista, no_lista_usuario *no){ /** Deleta um nó da lista encadeada */

	no_lista_usuario *acompanha = lista->primeiro;
	no_lista_usuario *anterior = NULL;

	while(strcmp(acompanha->usuario.CPF, no->usuario.CPF) != 0 && acompanha != NULL){

		anterior = acompanha;
		acompanha = acompanha->prox;
	}

	if(acompanha == NULL && strcmp(anterior->usuario.CPF, no->usuario.CPF) != 0){

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

no_lista_usuario *encontraNoUsuario(no_lista_usuario *inicio, char cpf[]){	/** Procura vértice na lista */

	no_lista_usuario *acompanha = inicio;	/** Primeiro vértice da lista */

	while(strcmp(acompanha->usuario.CPF,cpf) != 0 && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(strcmp(acompanha->usuario.CPF,cpf) != 0){

		return NULL;
	}
	else{

		return acompanha;
	}

}

//Funcao que libera a lista
//Retorna 0 se for liberada com sucesso e -1 se nao for
int LiberaListaUsuario(lista_usuario *listaUsuario){

	if(listaUsuario){
		if(listaUsuario->primeiro){
			no_lista_usuario *l = listaUsuario->primeiro, *q = NULL;
			while(l != NULL){
				q = l->prox;
				free(l);
				l = q;
			}	
		}
		free(listaUsuario);
	}else{
		printf("\nLista passada nao existe! Erro ao destruir lista de usuarios!\n");
		return ERRO;
	}

	return SEM_ERRO;	

}
/****************FIM***********************************/