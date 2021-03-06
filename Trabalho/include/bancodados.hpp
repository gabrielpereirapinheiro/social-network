#ifndef BANCODADOS_HEADER
#define BANCODADOS_HEADER
#include "headers.hpp"
#include "lista_usuario.hpp"
#include "transacoes.hpp"
#include "grafos.hpp"
#include "categoria.hpp"
#include "bancodados.hpp"

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
/// Header das funcoes que implementam o "banco de dados" da aplicacao

//Assinatura das funcoes
lista_usuario *RecupDadosUsuario(lista_usuario *listaUsuario);
ListaTransacao *RecupDadosTransacoes(ListaTransacao *listaTransacao);
ListaCategoria *RecupDadosCategorias(ListaCategoria *listaCat);
Grafo *RecupDadosGrafoAmiz(Grafo *grafoAmizade);
Grafo *RecupDadosGrafoTransac(Grafo *grafoTransacoes);
int SalvaArquivoUsuario(lista_usuario *lista_usuario);
int SalvaArquivoTransacao(ListaTransacao *listaTransacao);
int SalvaArquivoCategorias(ListaCategoria *listaCat);
int SalvaArquivoGrafoAmiz(Grafo *grafoAmizade);
int SalvaArquivoGrafoTransacao(Grafo *grafoTransacoes);
int RecupInfosUsuaID(lista_usuario *listaUsuario, ListaTransacao *listaTransacao);

#endif