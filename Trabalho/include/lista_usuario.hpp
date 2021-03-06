#ifndef LISTA_HPP
#define LISTA_HPP 
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
typedef struct no_lista_usuario{

	Usuario usuario;
	struct no_lista_usuario *prox;

}no_lista_usuario;


typedef struct lista_usuario{
	int numeroUsuarios;
	no_lista_usuario *primeiro;

}lista_usuario;


no_lista_usuario * criaNoUsuario(Usuario usuario);
lista_usuario *criarListaUsuario();
void addNoListaUsuarioExistente(lista_usuario *lista, no_lista_usuario *no);
void addNoListaUsuarioNovo(lista_usuario *lista, no_lista_usuario *no);
void deletaNoListaUsuario(lista_usuario *lista, no_lista_usuario *no);
no_lista_usuario *encontraNoUsuario(no_lista_usuario *inicio, char cpf[]);
no_lista_usuario *encontraNoUsuarioEmail(no_lista_usuario *inicio, char email[]);
no_lista_usuario *encontraNoUsuarioID(no_lista_usuario *inicio, int id);
int LiberaListaUsuario(lista_usuario *listaUsuario);

#endif