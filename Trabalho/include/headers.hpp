#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

//Flags para indicar informacoes de tipo de usuario
#define ADMIN 1
#define NORMAL 0

//Flags para indicar erro ou nao
#define ERRO -1
#define SEM_ERRO 0

//Flags para indicar informacoes sobre transacao
#define PENDENTE 0
#define CONCLUIDA 1

/** Struct que define os atributos de um usuario*/
typedef struct usuario
{
	int ID;
	char CPF[12];
	char nome[101];
	char senha[51];
	char email[101];
	int tipo;
	int idade;
	int numero_transacao;
	
}Usuario; 

/// Struct que define os atributos de uma categoria
typedef struct categoria{
	int idCategoria;
	char nomeCategoria[51];
}Categoria;

/// Struct que define os atributos de uma avaliacao
typedef struct avaliacao{
	int notaTransacao; //Nota da transacao dada por um usuario
	char comentAvaliClient[201]; //Comentario sobre a avaliacao do cliente
}Avaliacao;

/// Struct que define os atributos de um servico
typedef struct servico{
	Usuario usuarioProvedor; //O usuario que esta provendo o servico
	char precoServico[31];
	char descricaoServico[201];
}Servico;

/// Definicao da struct de Transacao
typedef struct transacao{
	int idTransacao; //chave primaria de transacao
	int classificacao; // indica se a transacao ja foi concluida ou nao. 0 significa pendente e 1 concluida
	Servico servico; //Informacoes do servico que caracterizou essa transacao
	Categoria categoria; //Categoria da transacao
	Avaliacao avaliacao; //Avaliacao da transacao
	Usuario usuarioCliente; //O usuario que esta consumindo o servico
}Transacao;


#endif

