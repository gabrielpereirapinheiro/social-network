//PARA COMPILAR ESTE PROGRAMA USE gcc telainicial.c -lncurses

#include <curses.h> //Biblioteca grafica, necessaria a instalacao dela, comando disponivel no ReadMe do projeto
#include <stdio.h>
#include <stdlib.h>
void sair_do_programa()
{
	endwin();//Finalizar a ncruses
	exit(0);
}

void tela_inicial()
{


WINDOW *janela; (void)initscr();
border(ACS_LTEE,ACS_RTEE,ACS_TTEE,ACS_BTEE, ACS_URCORNER,ACS_ULCORNER,ACS_LRCORNER,ACS_LLCORNER); 

janela = newwin(LINES-10,COLS-5,(LINES-(LINES-10))/2,(COLS-(COLS- 5))/2); 
wborder(janela, ACS_RTEE, ACS_LTEE, ACS_BTEE, ACS_TTEE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
//Inicializa a biblioteca ncurses
initscr();  

//Inicializa o uso das cores
start_color();
//Pares de cor que usaremos, texto verde e fundo branco
init_pair(1,COLOR_GREEN,COLOR_WHITE);

//Atualiza o fundo para o par de cor 1
bkgd(COLOR_PAIR(1));
refresh(); 
wrefresh(janela);
move(2,70);
printw("S  O  C  I  A  L        N  E  T  W  O  R  K");
move(10,50);
printw("LOGIN");
move(11,100);
printw("CADASTRAR");
move(18,70);
printw("SAIR");
int ch = getch();
switch (ch) 
{
    case KEY_LEFT:
        printw("aAaAAAAAAAAAAAAAAAAAAAAAAAAA");
        int valor;
        scanw("%d",&valor);
        break;
    default:
      break;
}
printw("%c",ch); 
noecho();
getch();
getch();
delwin(janela);

	sair_do_programa();
}

int main(void)
{
	
	tela_inicial();


	return 0;
}