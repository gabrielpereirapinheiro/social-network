#include "headers.hpp"



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

Usuario tela_sign_up()
{
	char confirmacao_senha[51];

	clear();

	Usuario cadastrar_agora; 

	imprime_titulo();

	printw("Name:\n");
	scanw("%s",cadastrar_agora.nome);

	printw("Age:\n");
	scanw("%d",&cadastrar_agora.idade);

	printw("CPF\n");
	scanw("%s",cadastrar_agora.CPF);

	printw("Email:");
	scanw("%s",cadastrar_agora.email);

	//Oculta caractres digitados
	noecho();

	//Poem o cursor na linha para identificar onde esta
	curs_set(1);
	
	/** Tipo setado para 0 pois e um usario normal*/
	cadastrar_agora.tipo = 0;
	
	/** Usuario digita pela primeira vez a senha */	
	printw("Senha\n");
	scanw("%s",cadastrar_agora.senha);

	printw("Confirm password");
	scanw("%s",confirmacao_senha);


	return cadastrar_agora;
}

void tela_sing_in()
{

	char name[30],senha[15];

	//Limpa a tela
	clear();

	//Imprime o titulo no canto superior
	imprime_titulo();

	//Move para baixo onde ira imprimir
	move(3,0);

	//Recebe nome do usuario
	printw("Name:");
	scanw("%s",name);

	//Desce para receber a senha
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

		printw("	Seja bem-vindo ao SOCIAL NETWORK");
		
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