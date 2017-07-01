#ifndef TRANSACOES_HPP
#define TRANSACOES_HPP
#include "headers.hpp"
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
/// Header de transacoes, com a definicao da struct de lista de transacoes e a assinatura de suas funcoes

/// Definicao da struct de lista de transacoes 
typedef struct noTransacao{
	Transacao transacao;
	struct noTransacao *prox;
}noListaTransacao;

///Definicao da struct com a cabeca da lista
typedef struct listaTransacao{
	int numeroTransacoes; // numero de transacoes que existem no aplicativo
	noListaTransacao *primeiro;
}ListaTransacao;

///Assinatura das funcoes
noListaTransacao *criaNoTransacao(Transacao transacao);
ListaTransacao *criarListaTransacao();
Servico CriaServicoUsuario(Usuario usuarioProvedor, char *precoServico, char *descricaoServico);
Transacao MontaTransacao(Servico servicoUsuario, Categoria categoriaServico);
int addNoListaTransacaoExistente(ListaTransacao *lista, noListaTransacao *no);
int addNoListaTransacaoNova(ListaTransacao *lista, noListaTransacao *no);
int deletaNoListaTransacao(ListaTransacao *lista, noListaTransacao *no);
noListaTransacao *encontraNoTransacao(noListaTransacao *inicio, Transacao transacao);
int LiberaListaTransacao(ListaTransacao *listaTransacao);

#endif

