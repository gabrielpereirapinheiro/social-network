#ifndef BANCODADOS_HEADER
#define BANCODADOS_HEADER
#include "headers.hpp"

/// Header das funcoes que implementam o "banco de dados" da aplicacao

//Assinatura das funcoes
void RecuperaDadosArquivos(lista_usuario *listaUsuario, ListaTransacao *listaTransacao, ListaCategoria *listaCat,
						   Grafo *grafoAmizade, Grafo *grafoTransacoes);
int SalvaArquivoUsuario(lista_usuario *lista_usuario);
int SalvaArquivoTransacao(ListaTransacao *listaTransacao);
int SalvaArquivoCategorias(ListaCategoria *listaCat);
int SalvaArquivoGrafoAmiz(Grafo *grafoAmizade);
int SalvaArquivoGrafoTransacao(Grafo *grafoTransacoes);
Usuario GetUsuarioPorID(lista_usuario *listaUsuario);
int RecupInfosUsuaID(lista_usuario *listaUsuario, ListaTransacao *listaTransacao);

#endif