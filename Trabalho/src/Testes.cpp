#define CATCH_CONFIG_MAIN   
#include "catch.hpp"
#include "headers.hpp" 
#include "lista_usuario.hpp"
#include "transacoes.hpp"
#include "grafos.hpp"
#include "categoria.hpp"
#include "bancodados.hpp"


/* Teste case para biblioteca lista_usuario.hpp */
TEST_CASE("Testes da biblioteca lista_usuario.hpp:"){


	char matricula1[] = "01400705108";
	char matricula2[] = "01400777708";
	char matricula3[] = "01400555508"; 

	/* Inicializacao de variaveis de tipo usuario */
	Usuario usuario1;
	strcpy(usuario1.CPF, matricula1);
	strcpy(usuario1.nome, "Andre Luis Souto Ferreira");
	strcpy(usuario1.senha, "senhateste");
	strcpy(usuario1.email, "andre@hotmail.com");
	usuario1.tipo = 1;
	usuario1.idade = 20;
	usuario1.numero_transacao = 0;

	Usuario usuario2;
	strcpy(usuario2.CPF, matricula2);
	strcpy(usuario2.nome, "Gabriel Araujo Vieira");
	strcpy(usuario2.senha, "senhateste2");
	strcpy(usuario2.email, "gabriel@hotmail.com");
	usuario2.tipo = 1;
	usuario2.idade = 24;
	usuario2.numero_transacao = 0;

	Usuario usuario3;
	strcpy(usuario3.CPF, matricula3);
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
	no_lista_usuario * ptr = encontraNoUsuario(l->primeiro,matricula3);
	REQUIRE(strcmp(ptr->usuario.nome,"Victor Pereira Ferreira") == 0);

	ptr = encontraNoUsuario(l->primeiro,matricula1);
	REQUIRE(strcmp(ptr->usuario.nome,"Andre Luis Souto Ferreira") == 0);

	ptr = encontraNoUsuario(l->primeiro,matricula2);
	REQUIRE(strcmp(ptr->usuario.nome,"Victor Pereira Ferreira") != 0);

 
	/* Deletando um no */
	deletaNoListaUsuario(l, no1);


	/* Confirmacao dos resultados do teste */
	ptr = encontraNoUsuario(l->primeiro,matricula1);
	REQUIRE(ptr == NULL);

	ptr = encontraNoUsuario(l->primeiro,matricula3);
	REQUIRE(strcmp(ptr->usuario.nome,"Victor Pereira Ferreira") == 0);

	ptr = encontraNoUsuario(l->primeiro,matricula2);
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

/* Teste case para biblioteca categoria.hpp */
TEST_CASE("Testes da biblioteca categoria.hpp:"){

	/* Inicializacao de variaveis de tipo categoria */
	categoria cat0;
	cat0.idCategoria = 0;
	strcpy(cat0.nomeCategoria,"eletronicos");

	categoria cat1;
	cat1.idCategoria = 1;
	strcpy(cat1.nomeCategoria,"vestuario");

	categoria cat2;
	cat2.idCategoria = 2;
	strcpy(cat2.nomeCategoria,"sapatos");

	/* Criacao da lista */
	ListaCategoria * l = criarListaCategoria();


	/* Criacao do no categoria */
	noListaCategoria * no0 = criaNoCategoria(cat0);
	noListaCategoria * no1 = criaNoCategoria(cat1);
	noListaCategoria * no2 = criaNoCategoria(cat2);


	/* Insercao na lista */
	int retorno = -10;
	retorno = addNoListaCategoria(l,no0);
	REQUIRE(retorno == SEM_ERRO);
	retorno = addNoListaCategoria(l,no1);
	REQUIRE(retorno == SEM_ERRO);
	retorno = addNoListaCategoria(l,no2);
	REQUIRE(retorno == SEM_ERRO);


	/* Confirmacao dos resultados do teste */
	noListaCategoria * ptr = encontraNoCategoria(l->primeiro,cat0);
	REQUIRE(ptr->categoria.idCategoria == 0);

	ptr = encontraNoCategoria(l->primeiro,cat1);
	REQUIRE(ptr->categoria.idCategoria == 1);
	 
	ptr = encontraNoCategoria(l->primeiro,cat2);
	REQUIRE(ptr->categoria.idCategoria == 2);


	/* Deletando um no */
	deletaNoListaCategoria(l, no1);


	/* Confirmacao dos resultados do teste */
	ptr = encontraNoCategoria(l->primeiro,cat0);
	REQUIRE(ptr->categoria.idCategoria == 0);

	ptr = encontraNoCategoria(l->primeiro,cat1);
	REQUIRE(ptr == NULL);
	
	ptr = encontraNoCategoria(l->primeiro,cat2);
	REQUIRE(ptr->categoria.idCategoria == 2);
 
}

/* Teste case para biblioteca bancodados.hpp */
TEST_CASE("Testes da biblioteca bancodados.hpp:"){

// Grafo *RecupDadosGrafoAmiz(Grafo *grafoAmizade); -----
// Grafo *RecupDadosGrafoTransac(Grafo *grafoTransacoes);	------
// int SalvaArquivoUsuario(lista_usuario *lista_usuario);
// int SalvaArquivoTransacao(ListaTransacao *listaTransacao);
// int SalvaArquivoCategorias(ListaCategoria *listaCat);
// int SalvaArquivoGrafoAmiz(Grafo *grafoAmizade);
// int SalvaArquivoGrafoTransacao(Grafo *grafoTransacoes);
// int RecupInfosUsuaID(lista_usuario *listaUsuario, ListaTransacao *listaTransacao);

	/* Teste da funcao RecupDadosUsuario */
	lista_usuario *lista_us = criarListaUsuario();
	lista_us = RecupDadosUsuario(lista_us);

	REQUIRE(lista_us->primeiro == NULL);

	/* Teste da funcao RecupDadosTransacoes */
	ListaTransacao *lista_tr = criarListaTransacao();
	lista_tr = RecupDadosTransacoes(lista_tr);

	REQUIRE(lista_tr->primeiro == NULL);

	/* Teste da funcao RecupDadosCategorias */
	ListaCategoria *lista_cat = criarListaCategoria();
	lista_cat = RecupDadosCategorias(lista_cat);

	REQUIRE(lista_cat->primeiro == NULL);

	/* Teste da funcao SalvaArquivoUsuario */
	int retorno_SalvaArquivoUsuario;
	retorno_SalvaArquivoUsuario = SalvaArquivoUsuario(lista_us);

	REQUIRE(retorno_SalvaArquivoUsuario == ERRO);

}
