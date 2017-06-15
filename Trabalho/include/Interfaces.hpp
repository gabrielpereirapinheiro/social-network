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
	
}Usuario;

void sair_do_programa();

void imprime_titulo();

void tela_sign_up();

void tela_sing_in();

int opcoes_tela_inicial();

void tela_inicial();

#endif
