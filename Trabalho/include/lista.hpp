#ifndef LISTA_HPP
#define LISTA_HPP 

typedef struct no_lista_usuario{

	Usuario usuario;
	struct no_lista_usuario *prox;

}no_lista_usuario;


typedef struct lista_usuario{
	no_lista_usuario *primeiro;
}lista_usuario;


static no_lista_usuario * criaNoUsuario(Usuario usuario);
static lista_usuario *criarListaUsuario(Usuario usuario);
static void addNoListaUsuario(lista_usuario *lista, no_lista_usuario *no);
static void deletaNoListaUsuario(lista_usuario *lista, no_lista_usuario *no);
static no_lista_usuario *encontraNoUsuario(no_lista_usuario *inicio, Usuario usuario);

#endif