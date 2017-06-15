#include "headers.hpp"

/** Lista declarada como variavel global. Sera usada como um buffer para salvar os dados 
	antes dos mesmos serem passados ao Banco de Dados */
lista_usuario * lista_us = criarListaUsuario();


void sair_do_programa()
{
	endwin();
	//Finalizar a ncruses
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

	/**Mostra titulo*/
	imprime_titulo();

	/**Mostrar caracteres*/
	echo();


	printw("Nome:");
	scanw("%s",cadastrar_agora.nome);

	cadastrar_agora.idade=-1;

	/**Verifica se nao e negativo*/
	while(cadastrar_agora.idade<0)
	{	
		printw("Idade:");
		scanw("%d",&cadastrar_agora.idade);
	}

	strcpy(cadastrar_agora.CPF,"inicial");

	while(strlen(cadastrar_agora.CPF)!=11)
	{
		printw("CPF:");
		scanw("%s",cadastrar_agora.CPF);
	}

	printw("Email:");
	scanw("%s",cadastrar_agora.email);

	//Oculta caractres digitados
	noecho();

	//Poem o cursor na linha para identificar onde esta
	curs_set(1);
	
	/** Tipo setado para 0 pois e um usario normal*/
	cadastrar_agora.tipo = 0;
	
	/** Setado para zero pois o usuario novo nao tem nenhuma transacao */
	cadastrar_agora.numero_transacao = 0;


	strcpy(cadastrar_agora.senha,"abc");
	strcpy(confirmacao_senha,"ab");

	while(strcmp(cadastrar_agora.senha,confirmacao_senha)!=0)
	{
	/** Usuario digita pela primeira vez a senha */	
		printw("Senha:");
		scanw("%s",cadastrar_agora.senha);

		printw("Confirmacao de senha:");
		scanw("%s",confirmacao_senha);
	}	
	return cadastrar_agora;
}

void tela_sing_in()
{

	char CPF[12],senha[51];

	//Limpa a tela
	clear();

	//Mostrar caracteres
	echo();

	//Imprime o titulo no canto superior
	imprime_titulo();

	//Move para baixo onde ira imprimir
	move(3,0);

	/**Adiciocna um valor com tamanho menor para so ser aceito CPF de 11 digitos*/
	strcpy(CPF,"010");


	/**Enquanto nao tiver 11 elementos nao aceita*/
	while(strlen(CPF)!=11)
	{
		//Recebe nome do usuario
		printw("CPF:");
		scanw("%s",CPF);
	}

	//Oculta caractres digitados
	noecho();

	//Poem o cursor na linha para identificar onde esta
	curs_set(1);

	//Recebe a senha
	printw("Senha:");
	scanw("%s",senha);

}

int opcoes_tela_inicial()
{

	int opcao = 0, tecla;

	do{
		
		imprime_titulo();

		move(3,1);

		printw("Seja bem-vindo ao SOCIAL NETWORK");
		
		move(5,0);
		(opcao == 0) ? printw("->") : printw("  ");
		printw("Log In\n");
		(opcao == 1) ? printw("->") : printw("  ");
		printw("Cadastro\n");
		(opcao ==2 ) ? printw("->") : printw("  ");
		printw("Sair\n");
	
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
			addNoListaUsuario(lista_us,criaNoUsuario(tela_sign_up()));
			break;
		case 2 :
			sair_do_programa();
			break;
	}




	clear();
	tela_inicial();
	noecho();

}