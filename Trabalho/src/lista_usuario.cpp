#include "lista_usuario.hpp"

/**
 * @file
 * @author  Andre Luis Souto Ferreira  <andre_luisferreira@hotmail.com>
 * @author  Gabriel Pereira Pinheiro <gabriel.pereira.pinheiro@gmail.com>
 * @author Victor Araujo Viera <icevct@gmail.com>
 * @version 1.0
 *
 * @section Descrição
 * 
 * Projeto da disciplina metodos de programacão 2017/1
 *
 */

/*************LISTA***********************************/

/// Funcao que cria um no do tipo usuario, para ser inserido ou nao na lista de usuarios
no_lista_usuario * criaNoUsuario(Usuario usuario){	 

	/**
		Assertivas de entrada: Uma variavel do tipo usuario valida, com atributos preenchidos
		Assertivas de saida: Um no do tipo no_lista_usuario valido
	*/

	/** 
		\param	Usuario usuario: Uma variavel do tipo Usuario, com seus atributos preenchidos. 
		\return Um ponteiro do tipo no_lista_usuario. 
	*/

	no_lista_usuario *no = (no_lista_usuario*)malloc(sizeof(no_lista_usuario));
	no->prox = NULL;
	no->usuario = usuario; 

	return no;
}

/// Funcao que cria a lista de usuarios
lista_usuario *criarListaUsuario(){	/** Cria lista */ 

	/**
		Assertivas de entrada: Sem assertivas de entrada
		Assertivas de saida: Uma lista de usuarios, com a cabeca para lista de nos vazia e o atributo numeroUsuarios = 1
	*/

	/** 
		\param	Sem parametros de entrada.
		\return Um ponteiro do tipo lista_usuario, ou seja, a lista de usuarios criada. 
	*/

	lista_usuario *lista_criada = (lista_usuario*)malloc(sizeof(lista_usuario));
	lista_criada->numeroUsuarios = 1; // inicia o numero de usuarios. Comeca com 1 porque ja existe o administrador
	lista_criada->primeiro = NULL;

	return lista_criada;

}

/// Funcao que vai adicionar na lista um usuario que ja existe, ou seja, que ja tem no BD
void addNoListaUsuarioExistente(lista_usuario *lista, no_lista_usuario *no){

	/**
		Assertivas de entrada: Uma lista de usuarios existente e um no do tipo no_lista_usuario existente
		Assertivas de saida: A lista de usuarios passada como argumento com o no adicionado
	*/

	/** 
		\param	lista_usuario *lista: Um ponteiro do tipo lista_usuario, que eh a lista de usuarios. 
		\param no_lista_usuario *no: Um ponteiro do tipo no_lista_usuario a ser adicionado na lista de usuarios.
		\return Sem retorno. 
	*/

	no_lista_usuario *acompanha = NULL; // inicializa um ponteiro do tipo no_lista_usuario
	acompanha = lista->primeiro; // o ponteiro do tipo no_lista_usuario recebe a cabeca da lista

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

/// Funcao que vai adicionar na lista um usuario novo, ou seja, que esta sendo cadastrado
void addNoListaUsuarioNovo(lista_usuario *lista, no_lista_usuario *no){

	/**
		Assertivas de entrada: Uma lista de usuarios existente e um no do tipo no_lista_usuario existente
		Assertivas de saida: A lista de usuarios passada como argumento com o no adicionado
	*/

	/** 
		\param	lista_usuario *lista: Um ponteiro do tipo lista_usuario, que eh a lista de usuarios. 
		\param no_lista_usuario *no: Um ponteiro do tipo no_lista_usuario que foi cadastrado a ser adicionado na lista de usuarios.
		\return Sem retorno. 
	*/

	no_lista_usuario *acompanha = NULL; // inicializa um ponteiro do tipo no_lista_usuario
	acompanha = lista->primeiro; // o ponteiro do tipo no_lista_usuario recebe a cabeca da lista

	//Ja vai atribuir o id para o usuario, que eh o numero atual de usuarios cadastrados
	//Depois incrementa o numero de usuarios cadastrados
	no->usuario.ID = lista->numeroUsuarios;
	lista->numeroUsuarios++;

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

/// Funcao que vai deletar um no da lista de usuarios
void deletaNoListaUsuario(lista_usuario *lista, no_lista_usuario *no){

	/**
		Assertivas de entrada: Uma lista de usuarios existente e um no do tipo no_lista_usuario existente
		Assertivas de saida: A lista de usuarios passada como argumento com o no deletado
	*/

	/** 
		\param	lista_usuario *lista: Um ponteiro do tipo lista_usuario, que eh a lista de usuarios. 
		\param no_lista_usuario *no: Um ponteiro do tipo no_lista_usuario a ser removido da lista de usuarios.
		\return Sem retorno. 
	*/

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
		else if(acompanha == NULL && anterior != NULL){ /** Caso o nó esteja no fim da lista */

			anterior->prox = NULL;
		}
		else if(anterior == NULL){ /** Caso o nó seja o primeiro da lista */

			lista->primeiro = acompanha->prox;
			acompanha->prox = NULL;
		}
	}
	free(no);
}

/// Funcao que vai procurar um no de usuario na lista de usuarios, pelo CPF
no_lista_usuario *encontraNoUsuario(no_lista_usuario *inicio, char cpf[]){	

	/**
		Assertivas de entrada: Um no do tipo no_lista_usuario existente, que no caso eh a cabeca da lista de usuarios
		Assertivas de saida: Um no do tipo no_lista_usuario valido, ou NULL caso nao tenha sido encontrado
	*/

	/** 
		\param no_lista_usuario *no: Um ponteiro do tipo no_lista_usuario que no caso eh a cabeca da lista de usuarios.
		\param char cpf[]: Uma string, contendo o CPF do usuario a ser procurado.
		\return Um ponteiro do tipo no_lista_usuario, podendo ser NULL caso nao tenha sido encontrado. 
	*/

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

/// Funcao que vai procurar um no de usuario na lista de usuarios, pelo email
no_lista_usuario *encontraNoUsuarioEmail(no_lista_usuario *inicio, char email[]){	

	/**
		Assertivas de entrada: Um no do tipo no_lista_usuario existente, que no caso eh a cabeca da lista de usuarios
		Assertivas de saida: Um no do tipo no_lista_usuario valido, ou NULL caso nao tenha sido encontrado
	*/

	/** 
		\param no_lista_usuario *no: Um ponteiro do tipo no_lista_usuario que no caso eh a cabeca da lista de usuarios.
		\param char email[]: Uma string, contendo o email do usuario a ser procurado.
		\return Um ponteiro do tipo no_lista_usuario, podendo ser NULL caso nao tenha sido encontrado. 
	*/

	no_lista_usuario *acompanha = inicio;	/** Primeiro vértice da lista */

	while(strcmp(acompanha->usuario.email,email) != 0 && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(strcmp(acompanha->usuario.email,email) != 0){

		return NULL;
	}
	else{

		return acompanha;
	}

}

/// Funcao que vai procurar um no de usuario na lista de usuarios, pelo id
no_lista_usuario *encontraNoUsuarioID(no_lista_usuario *inicio, int id){	
	
	/**
		Assertivas de entrada: Um no do tipo no_lista_usuario existente, que no caso eh a cabeca da lista de usuarios
		Assertivas de saida: Um no do tipo no_lista_usuario valido, ou NULL caso nao tenha sido encontrado
	*/

	/** 
		\param no_lista_usuario *no: Um ponteiro do tipo no_lista_usuario que no caso eh a cabeca da lista de usuarios.
		\param int id: Um inteiro, que eh o id do usuario a ser procurado.
		\return Um ponteiro do tipo no_lista_usuario, podendo ser NULL caso nao tenha sido encontrado. 
	*/

	no_lista_usuario *acompanha = inicio;	/** Primeiro vértice da lista */

	while(acompanha->usuario.ID != id && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(acompanha->usuario.ID != id){

		return NULL;
	}
	else{

		return acompanha;
	}

}

/// Funcao que libera a lista de usuarios
int LiberaListaUsuario(lista_usuario *listaUsuario){

	/**
		Assertivas de entrada: Uma lista de usuarios existente
		Assertivas de saida: A memoria alocada para a lista de usuarios livre
	*/

	/** 
		\param	lista_usuario *lista: Um ponteiro do tipo lista_usuario, que eh a lista de usuarios. 
		\return Um inteiro, retorna 0 se for liberada com sucesso e -1 se nao for. 
	*/

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
