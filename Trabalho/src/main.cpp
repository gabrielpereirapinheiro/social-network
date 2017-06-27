#include "headers.hpp"
#include "Interfaces.hpp"
#include "bancodados.hpp"

int main()
{

	// inicializacao das estruturas de dados
	lista_usuario *listaUsuarios = NULL;
	ListaTransacao *listaTransacoes = NULL;
	ListaCategoria *listaCategorias = NULL;
	Grafo *grafoAmizade = NULL;
	Grafo *grafoTransacoes = NULL;

	/**
		@brief Funcao principal que ira chamar a primeira tela
		
	*/
	//populaLista(listaCategorias);

	listaUsuarios = RecupDadosUsuario(listaUsuarios);
	listaTransacoes = RecupDadosTransacoes(listaTransacoes);
	listaCategorias = RecupDadosCategorias(listaCategorias);
	grafoAmizade = RecupDadosGrafoAmiz(grafoAmizade);
	grafoTransacoes = RecupDadosGrafoTransac(grafoTransacoes);
	tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
	return 0;

}