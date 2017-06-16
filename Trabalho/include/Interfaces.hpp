#ifndef INTERFACES_HPP
#define INTERFACES_HPP 


#define cima      259
#define baixo     258
#define esquerda  260
#define direita   261
#define enter     10

/** Struct que define os atributos de um usuario*/
typedef struct usuario
{
	int ID;
	char CPF[12];
	char nome[101];
	char senha[51];
	char email[101];
	short tipo;
	int idade;
	int numero_transacao;
	
}Usuario;

/** Struct que define os atributos de uma categoria*/
typedef struct categoria{
	int idCategoria;
	char nomeCategoria[51];
}Categoria;

/** Struct que define os atributos de uma avaliacao*/
typedef struct avaliacao{
	short notaTransacao; //Nota da transacao dada por um usuario
	char comentAvaliClient[201]; //Comentario sobre a avaliacao do cliente
}Avaliacao;

/** Struct que define os atributos de um servico*/
typedef struct servico{
	int idUsuProvedor; //O id do usuario que esta provendo o servico
	char precoServico[31];
	char descricaoServico[201];
}Servico;

/// Definicao da struct de Transacao
typedef struct transacao{
	int idTransacao; //chave primaria de transacao
	Servico servico; //Informacoes do servico que caracterizou essa transacao
	Categoria categoria; //Categoria da transacao
	Avaliacao avaliacao; //Avaliacao da transacao
	int clienteID; //O id do usuario que esta consumindo o servico
}Transacao;


//Assinatura das funcoes
void sair_do_programa();

void imprime_titulo();

Usuario tela_sign_up();

void tela_sing_in();

int opcoes_tela_inicial();

void tela_inicial();


//Funcoes relacionadas ao back-end
//int EditarUsuario(Lista);
void tela_usuario(char CPF[]);

int menu_configuracao(char nome[]);

void tela_configuracao(char nome[]);

#endif
