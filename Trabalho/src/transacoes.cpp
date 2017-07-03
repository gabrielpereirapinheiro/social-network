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

/// Funcao que cria um no do tipo transacao, para ser inserido ou nao na lista de transacoes
noListaTransacao *criaNoTransacao(Transacao transacao){	

	/**
		Assertivas de entrada: Uma variavel do tipo Transacao valida, com atributos preenchidos
		Assertivas de saida: Um no do tipo noListaTransacao valido
	*/

	/** 
		\param Transacao transacao: Uma variavel do tipo Transacao, com seus atributos preenchidos. 
		\return Um ponteiro do tipo noListaTransacao. 
	*/ 

	noListaTransacao *no = (noListaTransacao*)malloc(sizeof(noListaTransacao));
	no->prox = NULL;
	no->transacao = transacao; 

	return no;
}

/********************Funcoes relacionadas a tela de adicionar transacao**********************/

/// Funcao que monta o tipo servico do usuario que vai adicionar na transacao sendo criada
Servico CriaServicoUsuario(Usuario usuarioProvedor, char *precoServico, char *descricaoServico){

	/**
		Assertivas de entrada: Uma variavel do tipo Usuario e duas strings validas 
		Assertivas de saida: Uma variavel do tipo Servico com atributos preenchidos
	*/

	/** 
		\param Usuario usuarioProvedor: Uma variavel do tipo Usuario, que eh o usuario que esta adicionando a transacao, com seus atributos preenchidos.
		\param char *precoServico: Uma string com o preco do servico a ser criado.
		\param char *descricaoServico: Uma string com a descricao do servico a ser criado. 
		\return Uma variavel do tipo Servico. 
	*/ 

	Servico servicoUsuario; // Variavel do tipo servico para abrigar os atributos do servico que o usuario
							// usuarioProvedor esta criando

	servicoUsuario.usuarioProvedor = usuarioProvedor; // atribui ao usuario do servico o usuario que esta criando o servico
	strcpy(servicoUsuario.precoServico, precoServico); // copia o preco do servico
	strcpy(servicoUsuario.descricaoServico, descricaoServico); // copia a descricao do servico

	return servicoUsuario;
}

/// Funcao que monta a transacao que vai ser adicionada, recebendo o servico e a categoria do servico
Transacao MontaTransacao(Servico servicoUsuario, Categoria categoriaServico){

	/**
		Assertivas de entrada: Uma variavel do tipo Servico e Categoria validas
		Assertivas de saida: Uma variavel do tipo Transacao com atributos preenchidos
	*/

	/** 
		\param Servico servicoUsuario: Uma variavel do tipo Servico, que eh o servico que esta sendo adicionado pelo usuario, com seus atributos preenchidos.
		\param Categoria categoriaServico: Uma variavel do tipo Categoria, que sera a categoria da transacao, com seus atributos preenchidos.
		\return Uma variavel do tipo Transacao. 
	*/ 

	Transacao transacaoUsuario;

	transacaoUsuario.servico = servicoUsuario; //recebe o servico do usuario
	transacaoUsuario.categoria = categoriaServico; //recebe a categoria do usuario
	transacaoUsuario.classificacao = PENDENTE; // quando cria a transacao, considera-se classificado como pendente

	return transacaoUsuario;
}

/********************************************************************************************/

/// Funcao que cria a lista de transacoes
ListaTransacao *criarListaTransacao(){	

	/**
		Assertivas de entrada: Sem assertivas de entrada
		Assertivas de saida: Uma lista de transacoes, com a cabeca para lista de nos vazia e o atributo numeroTransacoes = 0
	*/

	/** 
		\param	Sem parametros de entrada.
		\return Um ponteiro do tipo ListaTransacao, ou seja, a lista de transacoes criada. 
	*/

	ListaTransacao *lista_criada = (ListaTransacao*)malloc(sizeof(ListaTransacao));
	lista_criada->numeroTransacoes = 0;
	lista_criada->primeiro = NULL;

	return lista_criada;

}

/// Adiciona uma transacao na lista de transacoes, se ja existir no BD
int addNoListaTransacaoExistente(ListaTransacao *lista, noListaTransacao *no){	

	/**
		Assertivas de entrada: Uma lista de transacoes existente e um no do tipo noListaTransacao existente
		Assertivas de saida: A lista de transacoes passada como argumento com o no adicionado
	*/

	/** 
		\param	ListaTransacao *lista: Um ponteiro do tipo ListaTransacao, que eh a lista de transacoes. 
		\param noListaTransacao *no: Um ponteiro do tipo noListaTransacao a ser adicionado na lista de transacoes.
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario.
	*/
	
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

/// Adiciona uma transacao na lista de transacoes, se for nova
int addNoListaTransacaoNova(ListaTransacao *lista, noListaTransacao *no){

	/**
		Assertivas de entrada: Uma lista de transacoes existente e um no do tipo noListaTransacao existente
		Assertivas de saida: A lista de transacoes passada como argumento com o no adicionado
	*/

	/** 
		\param	ListaTransacao *lista: Um ponteiro do tipo ListaTransacao, que eh a lista de transacoes. 
		\param noListaTransacao *no: Um ponteiro do tipo noListaTransacao que foi cadastrado a ser adicionado na lista de transacoes.
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario.
	*/
	
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

/// Deleta uma transacao da lista de transacoes pelo seu id
int deletaNoListaTransacao(ListaTransacao *lista, noListaTransacao *no){ 

	/**
		Assertivas de entrada: Uma lista de transacoes existente e um no do tipo noListaTransacao existente
		Assertivas de saida: A lista de transacoes passada como argumento com o no deletado
	*/

	/** 
		\param	ListaTransacao *lista: Um ponteiro do tipo ListaTransacao, que eh a lista de transacoes. 
		\param noListaTransacao *no: Um ponteiro do tipo noListaTransacao a ser removido da lista de transacoes.
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario.
	*/

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

/// Procura uma transacao na lista de transacoes pelo id da transacao
noListaTransacao *encontraNoTransacao(noListaTransacao *inicio, Transacao transacao){

	/**
		Assertivas de entrada: Uma lista de transacoes existente e uma variavel do tipo Transacao valida
		Assertivas de saida: Um ponteiro do tipo noListaTransacao valido
	*/

	/** 
		\param	ListaTransacao *lista: Um ponteiro do tipo ListaTransacao, que eh a lista de transacoes. 
		\param Transacao transacao: Uma variavel do tipo Transacao, com os atributos preenchidos, a ser procurada na lista.
		\return O no da transacao procurada ou NULL, caso nao seja achado essa transacao na lista.
	*/	

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

/// Funcao que libera a lista de transacoes
int LiberaListaTransacao(ListaTransacao *listaTransacao){

	/**
		Assertivas de entrada: Uma lista de transacoes existente
		Assertivas de saida: A memoria alocada para a lista de transacoes livre
	*/

	/** 
		\param	ListaTransacao *lista: Um ponteiro do tipo ListaTransacao, que eh a lista de transacoes. 
		\return Um inteiro, retorna 0 em caso sucesso e -1 caso contrario
	*/

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
