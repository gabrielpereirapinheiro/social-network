#ifndef LISTA_HPP
#define LISTA_HPP 

typedef struct no_lista_usuario{

	Usuario usuario;
	struct no_lista_usuario *prox;

}no_lista_usuario;


typedef struct lista_usuario{
	
	no_lista_usuario *primeiro;

}lista_usuario;


no_lista_usuario * criaNoUsuario(Usuario usuario);
lista_usuario *criarListaUsuario();
void addNoListaUsuario(lista_usuario *lista, no_lista_usuario *no);
void deletaNoListaUsuario(lista_usuario *lista, no_lista_usuario *no);
no_lista_usuario *encontraNoUsuario(no_lista_usuario *inicio, char cpf[]);

#endif