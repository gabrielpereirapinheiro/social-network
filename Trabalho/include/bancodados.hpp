#ifndef BANCODADOS_HEADER
#define BANCODADOS_HEADER
#include "headers.hpp"
#include "lista_usuario.hpp"
#include "transacoes.hpp"
#include "grafos.hpp"
#include "categoria.hpp"
#include "bancodados.hpp"
/// Header das funcoes que implementam o "banco de dados" da aplicacao

//Assinatura das funcoes
void RecupDadosUsuario(lista_usuario *listaUsuario, FILE *fp);
void RecupDadosTransacoes(ListaTransacao *listaTransacao, FILE *fp);
void RecupDadosCategorias(ListaCategoria *listaCat, FILE *fp);
void RecupDadosGrafoAmiz(Grafo *grafoAmizade, FILE *fp);
void RecupDadosGrafoTransac(Grafo *grafoTransacoes, FILE *fp);
void RecuperaDadosArquivos(lista_usuario *listaUsuario, ListaTransacao *listaTransacao, ListaCategoria *listaCat,
						   Grafo *grafoAmizade, Grafo *grafoTransacoes);
int SalvaArquivoUsuario(lista_usuario *lista_usuario);
int SalvaArquivoTransacao(ListaTransacao *listaTransacao);
int SalvaArquivoCategorias(ListaCategoria *listaCat);
int SalvaArquivoGrafoAmiz(Grafo *grafoAmizade);
int SalvaArquivoGrafoTransacao(Grafo *grafoTransacoes);
int RecupInfosUsuaID(lista_usuario *listaUsuario, ListaTransacao *listaTransacao);

#endif