//PARA COMPILAR ESTE PROGRAMA USE gcc telainicial -lncurses

#include <curses.h> //Biblioteca grafica, necessaria a instalacao dela, comando disponivel no ReadMe do projeto
#include <stdio.h>

void sair_do_programa()
{
	endwin();//Finalizar a ncruses
	exit(0);
}

void tela_inicial()
{
	//Inicializa a biblioteca ncurses
	initscr();  

	//Inicializa o uso das cores
	start_color();

	//Pares de cor que usaremos, texto verde e fundo branco
	init_pair(1,COLOR_GREEN,COLOR_WHITE);

	bkgd(COLOR_PAIR(1));

	printw("SOCIAL NETWORK");

	move(3,1);

	printw("CLIQUE EM QUALQUER TECLA PARA SAIR");
	refresh();
	getch();
	sair_do_programa();
}

int main(void)
{
	
	tela_inicial();


	return 0;
}