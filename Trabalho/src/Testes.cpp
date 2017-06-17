#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "headers.hpp"


/* Teste case para biblioteca lista_usuario.hpp */
TEST_CASE("Testes da biblioteca lista_usuario.hpp:"){


	/* Inicializacao de variaveis de tipo usuario */
	Usuario usuario1;
	strcpy(usuario1.CPF, "01400705108");
	strcpy(usuario1.nome, "Andre Luis Souto Ferreira");
	strcpy(usuario1.senha, "senhateste");
	strcpy(usuario1.email, "andre@hotmail.com");
	usuario1.tipo = 1;
	usuario1.idade = 20;
	usuario1.numero_transacao = 0;

	Usuario usuario2;
	strcpy(usuario2.CPF, "01400777708");
	strcpy(usuario2.nome, "Gabriel Araujo Vieira");
	strcpy(usuario2.senha, "senhateste2");
	strcpy(usuario2.email, "gabriel@hotmail.com");
	usuario2.tipo = 1;
	usuario2.idade = 24;
	usuario2.numero_transacao = 0;

	Usuario usuario3;
	strcpy(usuario3.CPF, "01400555508");
	strcpy(usuario3.nome, "Victor Pereira Ferreira");
	strcpy(usuario3.senha, "senhateste3");
	strcpy(usuario3.email, "victor@hotmail.com");
	usuario3.tipo = 1;
	usuario3.idade = 29;
	usuario3.numero_transacao = 0;


	/* Criacao da lista */
	lista_usuario * l = criarListaUsuario();


	/* Criacao do no usuario */
	no_lista_usuario * no1 = criaNoUsuario(usuario1);
	no_lista_usuario * no2 = criaNoUsuario(usuario2);
	no_lista_usuario * no3 = criaNoUsuario(usuario3);


	/* Insercao na lista */
	addNoListaUsuario(l,no1);
	addNoListaUsuario(l,no2);
	addNoListaUsuario(l,no3);


	/* Confirmacao dos resultados do teste */
	no_lista_usuario * ptr = encontraNoUsuario(l->primeiro,"01400555508");
	REQUIRE(strcmp(ptr->usuario.nome,"Victor Pereira Ferreira") == 0);

	ptr = encontraNoUsuario(l->primeiro,"01400705108");
	REQUIRE(strcmp(ptr->usuario.nome,"Andre Luis Souto Ferreira") == 0);

	ptr = encontraNoUsuario(l->primeiro,"01400777708");
	REQUIRE(strcmp(ptr->usuario.nome,"Victor Pereira Ferreira") != 0);


	/* Deletando um no */
	deletaNoListaUsuario(l, no1);


	/* Confirmacao dos resultados do teste */
	ptr = encontraNoUsuario(l->primeiro,"01400705108");
	REQUIRE(ptr == NULL);

	ptr = encontraNoUsuario(l->primeiro,"01400555508");
	REQUIRE(strcmp(ptr->usuario.nome,"Victor Pereira Ferreira") == 0);

	ptr = encontraNoUsuario(l->primeiro,"01400777708");
	REQUIRE(strcmp(ptr->usuario.nome,"Gabriel Araujo Vieira") == 0);

}


/* Teste case para biblioteca transacoes.hpp */
TEST_CASE("Testes da biblioteca transacoes.hpp:"){

	/* Inicializacao de variaveis de tipo Transacao */
	Transacao t0;
	t0.idTransacao = 0;
	t0.classificacao = 0;

	Transacao t1;
	t1.idTransacao = 1;
	t1.classificacao = 0;

	Transacao t2;
	t2.idTransacao = 2;
	t2.classificacao = 0;


	/* Criacao da lista */
	ListaTransacao * l = criarListaTransacao();


	/* Criacao do no transacao */
	noListaTransacao * no0 = criaNoTransacao(t0);
	noListaTransacao * no1 = criaNoTransacao(t1);
	noListaTransacao * no2 = criaNoTransacao(t2);


	/* Insercao na lista */
	int retorno = -10;
	retorno = addNoListaTransacao(l,no0);
	REQUIRE(retorno == SEM_ERRO);
	retorno = addNoListaTransacao(l,no1);
	REQUIRE(retorno == SEM_ERRO);
	retorno = addNoListaTransacao(l,no2);
	REQUIRE(retorno == SEM_ERRO);


	/* Confirmacao dos resultados do teste */
	noListaTransacao * ptr = encontraNoTransacao(l->primeiro,t0);
	REQUIRE(ptr->transacao.idTransacao == 0);

	ptr = encontraNoTransacao(l->primeiro,t1);
	REQUIRE(ptr->transacao.idTransacao == 1);
	
	ptr = encontraNoTransacao(l->primeiro,t2);
	REQUIRE(ptr->transacao.idTransacao == 2);


	/* Deletando um no */
	deletaNoListaTransacao(l, no1);


	/* Confirmacao dos resultados do teste */
	ptr = encontraNoTransacao(l->primeiro,t0);
	REQUIRE(ptr->transacao.idTransacao == 0);

	ptr = encontraNoTransacao(l->primeiro,t1);
	REQUIRE(ptr == NULL);
	
	ptr = encontraNoTransacao(l->primeiro,t2);
	REQUIRE(ptr->transacao.idTransacao == 2);

}


