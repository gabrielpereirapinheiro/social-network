#include "categoria.hpp"
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

/// Funcao que cria um no do tipo categoria, para ser inserido ou nao na lista de categorias
noListaCategoria *criaNoCategoria(Categoria categoria){	

	/**
		Assertivas de entrada: Uma variavel do tipo categoria valida, com atributos preenchidos
		Assertivas de saida: Um no do tipo noListaCategoria valido
	*/

	/** 
		\param Categoria categoria: Uma variavel do tipo Categoria, com seus atributos preenchidos. 
		\return Um ponteiro do tipo noListaCategoria. 
	*/

	noListaCategoria *no = (noListaCategoria*)malloc(sizeof(noListaCategoria));
	no->prox = NULL;
	no->categoria = categoria; 

	return no;
}

/// Funcao que cria a lista de categorias
ListaCategoria *criarListaCategoria(){	

	/**
		Assertivas de entrada: Sem assertivas de entrada
		Assertivas de saida: Uma lista de categorias, com a cabeca para lista de nos vazia e o atributo numeroCategorias = 0
	*/

	/** 
		\param	Sem parametros de entrada.
		\return Um ponteiro do tipo ListaCategoria, ou seja, a lista de categorias criada. 
	*/

	ListaCategoria *lista_criada = (ListaCategoria*)malloc(sizeof(ListaCategoria));
	lista_criada->numeroCategorias = 0;
	lista_criada->primeiro = NULL;

	return lista_criada;

}

/// Adiciona uma categoria na lista de categorias, se for existente no BD
int addNoListaCategoriaExistente(ListaCategoria *lista, noListaCategoria *no){

	/**
		Assertivas de entrada: Uma lista de categorias existente e um no do tipo noListaCategoria existente
		Assertivas de saida: A lista de categorias passada como argumento com o no adicionado
	*/

	/** 
		\param	ListaCategoria *lista: Um ponteiro do tipo ListaCategoria, que eh a lista de categorias. 
		\param noListaCategoria *no: Um ponteiro do tipo noListaCategoria a ser adicionado na lista de categorias.
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario
	*/

	if(lista == NULL || no == NULL){
		printf("Erro na funcao addNoListaCategoria! Argumentos invalidos\n");
		return ERRO;
	}
	noListaCategoria *acompanha = lista->primeiro;

	if (acompanha == NULL){

		lista->primeiro = no;
	}
	else{
		
		while(acompanha->prox != NULL){

			acompanha = acompanha->prox;
		}

		acompanha->prox = no;
	}

	return SEM_ERRO;
}

/// Adiciona uma categoria na lista de categorias, se for nova
int addNoListaCategoriaNova(ListaCategoria *lista, noListaCategoria *no){

	/**
		Assertivas de entrada: Uma lista de categorias existente e um no do tipo noListaCategoria existente
		Assertivas de saida: A lista de categorias passada como argumento com o no adicionado
	*/

	/** 
		\param	ListaCategoria *lista: Um ponteiro do tipo ListaCategoria, que eh a lista de categorias. 
		\param noListaCategoria *no: Um ponteiro do tipo noListaCategoria que foi cadastrado a ser adicionado na lista de categorias.
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario
	*/

	if(lista == NULL || no == NULL){
		printf("Erro na funcao addNoListaCategoria! Argumentos invalidos\n");
		return ERRO;
	}
	noListaCategoria *acompanha = lista->primeiro;

	//parte que vai atribuir um ID para as categorias e incrementar o numero de categorias na lista
	no->categoria.idCategoria = lista->numeroCategorias;
	lista->numeroCategorias++;

	if (acompanha == NULL){

		lista->primeiro = no;
	}
	else{
		
		while(acompanha->prox != NULL){

			acompanha = acompanha->prox;
		}

		acompanha->prox = no;
	}

	return SEM_ERRO;
}

/// Deleta uma categoria da lista de categorias pelo seu id
int deletaNoListaCategoria(ListaCategoria *lista, noListaCategoria *no){

	/**
		Assertivas de entrada: Uma lista de categorias existente e um no do tipo noListaCategoria existente
		Assertivas de saida: A lista de categorias passada como argumento com o no deletado
	*/

	/** 
		\param	ListaCategoria *lista: Um ponteiro do tipo ListaCategoria, que eh a lista de categorias. 
		\param noListaCategoria *no: Um ponteiro do tipo noListaCategoria a ser removido da lista de categorias.
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario
	*/

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
		else if(acompanha == NULL && anterior != NULL){ /** Caso o nó esteja no fim da lista */

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

/// Funcao que procura uma categoria na lista de categorias 
noListaCategoria *encontraNoCategoria(noListaCategoria *inicio, Categoria categoria){

	/**
		Assertivas de entrada: Uma lista de categorias existente e uma variavel do tipo Categoria valida
		Assertivas de saida: Um ponteiro do tipo noListaCategoria valido
	*/

	/** 
		\param	ListaCategoria *lista: Um ponteiro do tipo ListaCategoria, que eh a lista de categorias. 
		\param Categoria categoria: Uma variavel do tipo categoria, com os atributos preenchidos, a ser procurada na lista .
		\return O no da categoria procurada ou NULL, caso nao seja achado essa categoria na lista
	*/

	noListaCategoria *acompanha = inicio;	/** Primeiro no da lista */


	while(strcmp(acompanha->categoria.nomeCategoria,categoria.nomeCategoria) != 0 && acompanha->prox != NULL){

		acompanha = acompanha->prox;
	}

	if(strcmp(acompanha->categoria.nomeCategoria, categoria.nomeCategoria) != 0){
		printf("Categoria nao existe na lista de categorias\n");
		return NULL;
	}
	else{

		return acompanha;
	}

}

/// Funcao que libera a lista de categorias
int LiberaListaCategoria(ListaCategoria *listaCategoria){

	/**
		Assertivas de entrada: Uma lista de categorias existente
		Assertivas de saida: A memoria alocada para a lista de categorias livre
	*/

	/** 
		\param	ListaCategoria *lista: Um ponteiro do tipo ListaCategoria, que eh a lista de categorias. 
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario
	*/

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
