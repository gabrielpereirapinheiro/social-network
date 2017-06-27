#include "headers.hpp"
#include "Interfaces.hpp"
#include "bancodados.hpp"

int main()
{

	lista_usuario *listaUsuarios = NULL;
	ListaTransacao *listaTransacoes = NULL;
	ListaCategoria *listaCategorias = NULL;
	Grafo *grafoAmizade = NULL;
	Grafo *grafoTransacoes = NULL;

	/**
		@brief Funcao principal que ira chamar a primeira tela
		
	*/
	//populaLista(listaCategorias);
	initscr();
	RecuperaDadosArquivos(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
	if(listaUsuarios == NULL) printw("nao era assim nao burrao\n");
	getch();
	tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
	return 0;

}