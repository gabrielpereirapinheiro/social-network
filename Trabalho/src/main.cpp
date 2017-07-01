#include "headers.hpp"
#include "Interfaces.hpp"
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

int main()
{

	/* Inicializacao das estruturas de dados */
	lista_usuario *listaUsuarios = NULL;
	ListaTransacao *listaTransacoes = NULL;
	ListaCategoria *listaCategorias = NULL;
	Grafo *grafoAmizade = NULL;
	Grafo *grafoTransacoes = NULL;

	/**
		@brief Funcao principal que ira chamar a primeira tela
		
	*/

	/* Inicializando as listas e grafos */
	listaUsuarios = RecupDadosUsuario(listaUsuarios);
	listaTransacoes = RecupDadosTransacoes(listaTransacoes);
	listaCategorias = RecupDadosCategorias(listaCategorias);
	grafoAmizade = RecupDadosGrafoAmiz(grafoAmizade);
	grafoTransacoes = RecupDadosGrafoTransac(grafoTransacoes);
	
	if(RecupInfosUsuaID(listaUsuarios, listaTransacoes) < 0){
		printf("Erro ao recuperar informacoes de usuario para a lista de transacoes!\n");
	}
	
	tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
	
	return 0;
}