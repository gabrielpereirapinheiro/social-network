#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "headers.hpp"

TEST_CASE("Testes da biblioteca lista_usuario.hpp: "){

	/** Inicializacao de uma variavel do tipo usuario */
	Usuario usuario;
	strcpy(usuario.CPF, "01400705108");
	strcpy(usuario.nome, "Andre Luis Souto Ferreira");
	strcpy(usuario.senha, "senhateste");
	strcpy(usuario.email, "andre@hotmail.com");
	usuario.tipo = 0;
	usuario.idade = 24;
	usuario.numero_transacao = 0;

	/** Criacao da lista */
	lista_usuario * l = criarListaUsuario();

	/** Criacao do no usuario */
	no_lista_usuario * no = criaNoUsuario(usuario);





}