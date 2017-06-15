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
}noListaTransacao;

///Assinatura das funcoes
noListaTransacao *criaNoTransacao(Transacao transacao);
lista_usuario *criarListaTransacao(Transacao transacao);
void addNoListaTransacao(lista_usuario *lista, noListaTransacao *no);
void deletaNoListaTransacao(lista_usuario *lista, noListaTransacao *no);
noListaTransacao *encontraNoTransacao(noListaTransacao *inicio, Transacao transacao);

#endif

