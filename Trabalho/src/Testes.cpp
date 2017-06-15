#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "headers.hpp"

TEST_CASE("Testes da biblioteca lista_usuario.hpp: "){

	/** Inicializacao de variaveis de tipo usuario */
	Usuario usuario;
	strcpy(usuario.CPF, "01400705108");
	strcpy(usuario.nome, "Andre Luis Souto Ferreira");
	strcpy(usuario.senha, "senhateste");
	strcpy(usuario.email, "andre@hotmail.com");
	usuario.tipo = 1;
	usuario.idade = 20;
	usuario.numero_transacao = 0;

	Usuario usuario;
	strcpy(usuario.CPF, "01400777708");
	strcpy(usuario.nome, "Gabriel Araujo Vieira");
	strcpy(usuario.senha, "senhateste2");
	strcpy(usuario.email, "gabriel@hotmail.com");
	usuario.tipo = 1;
	usuario.idade = 24;
	usuario.numero_transacao = 0;

	Usuario usuario;
	strcpy(usuario.CPF, "01400555508");
	strcpy(usuario.nome, "Victor Pereira Ferreira");
	strcpy(usuario.senha, "senhateste3");
	strcpy(usuario.email, "victor@hotmail.com");
	usuario.tipo = 1;
	usuario.idade = 29;
	usuario.numero_transacao = 0;

	/** Criacao da lista */
	lista_usuario * l = criarListaUsuario();

	/** Criacao do no usuario */
	no_lista_usuario * no = criaNoUsuario(usuario);





}