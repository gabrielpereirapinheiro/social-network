#ifndef INTERFACES_HPP
#define INTERFACES_HPP 


#define cima      259
#define baixo     258
#define esquerda  260
#define direita   261
#define enter     10

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

/// Definicao da struct de Transacao
typedef struct transacao{
	int idTransacao; //chave primaria de transacao
	int categoria; //Categoria da transacao
	int clienteID; //O id do usuario que esta consumindo o servico
	int provedorID; //O id do usuario que esta provendo o servico
	short avaliacao; //Avaliacao da transacao dos usuarios TODO
	char comentAvaliClient[201]; //Comentario sobre a avaliacao do cliente
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
