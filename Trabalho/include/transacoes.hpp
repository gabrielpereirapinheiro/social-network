#ifndef TRANSACAO_HEADER
#define TRANSACAO_HEADER
#include "Interfaces.hpp"

/// Header de transacoes, com a definicao da struct de lista de transacoes e a assinatura de suas funcoes

/// Definicao da struct de lista de transacoes 
typedef struct noTransacao{
	Transacao transacao;
	struct noTransacao *prox;
}noListaTransacao;

///Definicao da struct com a cabeca da lista
typedef struct listaTransacao{
	noListaTransacao *primeiro;
}ListaTransacao;

///Assinatura das funcoes
noListaTransacao *criaNoTransacao(Transacao transacao);
ListaTransacao *criarListaTransacao(Transacao transacao);
int addNoListaTransacao(ListaTransacao *lista, noListaTransacao *no);
int deletaNoListaTransacao(ListaTransacao *lista, noListaTransacao *no);
noListaTransacao *encontraNoTransacao(noListaTransacao *inicio, Transacao transacao);

#endif

