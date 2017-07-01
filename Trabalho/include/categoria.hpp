#ifndef CATEGORIA_HEADER
#define CATEGORIA_HEADER
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

/// Header de categoria, com a definicao da struct de lista de categoria e a assinatura de suas funcoes

/// Definicao da struct de lista de categorias 
typedef struct noCategoria{
	Categoria categoria;
	struct noCategoria *prox;
}noListaCategoria;

///Definicao da struct com a cabeca da lista
typedef struct listacategoria{
	int numeroCategorias; // numero de categorias que existem no aplicativo
	noListaCategoria *primeiro;
}ListaCategoria;

///Assinatura das funcoes
noListaCategoria *criaNoCategoria(Categoria categoria);
ListaCategoria *criarListaCategoria();
int addNoListaCategoriaExistente(ListaCategoria *lista, noListaCategoria *no);
int addNoListaCategoriaNova(ListaCategoria *lista, noListaCategoria *no);
int deletaNoListaCategoria(ListaCategoria *lista, noListaCategoria *no);
noListaCategoria *encontraNoCategoria(noListaCategoria *inicio, Categoria categoria);
int LiberaListaCategoria(ListaCategoria *listaCategoria);

#endif

