//PARA COMPILAR ESTE PROGRAMA USE gcc telainicial.c -lncurses

#include <curses.h> //Biblioteca grafica, necessaria a instalacao dela, comando disponivel no ReadMe do projeto
#include <stdio.h>
#include <stdlib.h>



#define cima      259
#define baixo     258
#define esquerda  260
#define direita   261
#define enter     10



void sair_do_programa()
{
	endwin();//Finalizar a ncruses
	exit(0);
}

void imprime_titulo()
{
	move(1,5);
	printw("S O C I A L  N E T W O R K\n");
}

void tela_sign_up()
{
	char nome[30],cpf[11],senha[15],confirmacao_senha[15];
	int idade;

	clear();

	imprime_titulo();

	printw("Name:\n");
	scanw("%s",nome);

	printw("Age:\n");
	scanw("%d",&idade);

	printw("CPF\n");
	scanw("%s",cpf);

	/**Oculta caractres digitados*/
	noecho();

	/**Poem o cursor na linha para identificar onde esta*/
	curs_set(1);


	printw("Password\n");
	scanw("%s",senha);

	printw("Confirm password");
	scanw("%s",confirmacao_senha);
}

void tela_sing_in()
{

	char name[30],senha[15];

	/**Limpa a tela*/
	clear();

	/**Imprime o titulo no canto superior*/
	imprime_titulo();

	/**Move para baixo onde ira imprimir*/
	move(3,0);

	/**Recebe nome do usuario*/
	printw("Name:");
	scanw("%s",name);

	/**Desce para receber a senha*/
	move(4,0);

	//Oculta caractres digitados
	noecho();

	//Poem o cursor na linha para identificar onde esta
	curs_set(1);

	//Recebe a senha
	printw("Password:");
	scanw("%s",senha);

}

int opcoes_tela_inicial()
{

	int opcao = 0, tecla;

	do{
		
		imprime_titulo();

		move(3,1);

		printw("	Welcome to SOCIAL NETWORK !");
		
		move(5,0);
		(opcao == 0) ? printw("->") : printw("  ");
		printw("Log In\n");
		(opcao == 1) ? printw("->") : printw("  ");
		printw("Sign Up\n");
		(opcao ==2 ) ? printw("->") : printw("  ");
		printw("Exit\n");
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 2) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 2: opcao--;
		
		clear();

	} while(tecla != enter);

	switch(opcao)
	{
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;	
		default: 
			return -1;	
	}
}


void tela_inicial()
{

	int opcao;
	//Inicializa a biblioteca
	initscr();  

	//Comando que habilita pegar teclas do teclado
	keypad(stdscr, true); 
	
	//Oculta o cursor na tela
	curs_set(0);

	//Inicializa o uso das cores
	start_color();

	//Pares de cor que usaremos, texto verde e fundo branco
	init_pair(1,COLOR_GREEN,COLOR_WHITE);

	//Atualiza o fundo para o par de cor 1
	bkgd(COLOR_PAIR(1));
		
	//Funcao que imprime o titulo na parte superior da tela	
	imprime_titulo();

	//Recebe a opcao na tela inicial
	opcao = opcoes_tela_inicial();

	switch(opcao)
	{
		case 0 :
			tela_sing_in();
			break;
		case 1:
			tela_sign_up();
		case 2 :
			sair_do_programa();
			break;
	}

	noecho();

}

int main(void)
{
	
	tela_inicial();

	return 0;
}