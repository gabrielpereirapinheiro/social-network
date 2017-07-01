#include "transacoes.hpp"

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

/** Funcao que cria o no de transacao */
noListaTransacao *criaNoTransacao(Transacao transacao){	/** Cria nó */ 

	noListaTransacao *no = (noListaTransacao*)malloc(sizeof(noListaTransacao));
	no->prox = NULL;
	no->transacao = transacao; 

	return no;
}

/********************Funcoes relacionadas a tela de adicionar transacao**********************/

/** Funcao que monta o tipo servico do usuario que vai adicionar na transacao sendo criada*/
Servico CriaServicoUsuario(Usuario usuarioProvedor, char *precoServico, char *descricaoServico){
	Servico servicoUsuario; //! Variavel do tipo servico para abrigar os atributos do servico que o usuario
							//! usuarioProvedor esta criando

	servicoUsuario.usuarioProvedor = usuarioProvedor; // atribui ao usuario do servico o usuario que esta criando o servico
	strcpy(servicoUsuario.precoServico, precoServico); // copia o preco do servico
	strcpy(servicoUsuario.descricaoServico, descricaoServico); // copia a descricao do servico

	return servicoUsuario;
}

/** Funcao que monta a transacao que vai ser adicionada, recebendo o servico e a categoria do servico*/
Transacao MontaTransacao(Servico servicoUsuario, Categoria categoriaServico){
	Transacao transacaoUsuario;

	transacaoUsuario.servico = servicoUsuario; //recebe o servico do usuario
	transacaoUsuario.categoria = categoriaServico; //recebe a categoria do usuario
	transacaoUsuario.classificacao = PENDENTE; // quando cria a transacao, considera-se classificado como pendente

	return transacaoUsuario;
}

/********************************************************************************************/

ListaTransacao *criarListaTransacao(){	/** Cria lista */ 

	ListaTransacao *lista_criada = (ListaTransacao*)malloc(sizeof(ListaTransacao));
	lista_criada->numeroTransacoes = 0;
	lista_criada->primeiro = NULL;

	return lista_criada;

}

/** Adiciona uma transacao na lista de transacoes, se ja existir no BD*/
/*Retorna 0 em caso sucesso e -1 caso contrario*/
int addNoListaTransacaoExistente(ListaTransacao *lista, noListaTransacao *no){	
	
	if(lista == NULL || no == NULL){
		printf("Erro na funcao addNoListaTransacao! Argumentos invalidos\n");
		return ERRO;
	}
	noListaTransacao *acompanha = lista->primeiro;

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

/** Adiciona uma transacao na lista de transacoes, se for nova*/
/*Retorna 0 em caso sucesso e -1 caso contrario*/
int addNoListaTransacaoNova(ListaTransacao *lista, noListaTransacao *no){	
	
	if(lista == NULL || no == NULL){
		printf("Erro na funcao addNoListaTransacao! Argumentos invalidos\n");
		return ERRO;
	}
	noListaTransacao *acompanha = lista->primeiro;

	//parte que vai atribuir um ID para as transacoes e incrementar o numero de transacoes na lista
	no->transacao.idTransacao = lista->numeroTransacoes;
	lista->numeroTransacoes++;

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
