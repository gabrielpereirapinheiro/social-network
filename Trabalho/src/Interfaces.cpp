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
	move(1,3);
	printw("S O C I A L  N E T W O R K\n");
}


int menu_configuracao(char nome[])
{

	//Oculta o cursor na tela
	curs_set(0);

	int opcao = 0, tecla;

	do{
		
		imprime_titulo();

		move(1,30);

		printw("Usuario : %s",nome);
	
		move(5,0);

		(opcao == 0) ? printw("->") : printw("  ");
		printw("Editar informacoes\n");
		(opcao == 1) ? printw("->") : printw("  ");
		printw("Adicionar transacao\n");
		(opcao == 2) ? printw("->") : printw("  ");
		printw("Adicionar amigiunho\n");
		(opcao == 3) ? printw("->") : printw("  ");
		printw("Voltar");
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 3) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 3: opcao--;
		
		clear();

	} while(tecla != enter);

	/**Retorna opcao para tela usuario*/
	return opcao;

}


void tela_configuracao(char nome[])
{


	int opcao;
	clear();
	/**Mostra titulo*/
	imprime_titulo();

	
	opcao=menu_configuracao(nome);

	switch(opcao)
	{
		case 0:
			break;

		case 1:
			break;

		case 2:
			tela_usuario(nome);
			break;

		case 3:
			tela_usuario(nome);
			break;

		case 4:
			tela_inicial();
			break;

		default: 
			break;	
	}


	/**Mostrar caracteres*/
	echo();
}


int menu_usuario(char nome[])
{
	clear();
	//Oculta o cursor na tela
	curs_set(0);

	int opcao = 0, tecla;

	do{
		
		imprime_titulo();

		move(1,30);
		printw("Usuario : %s",nome);
	
		move(5,0);

		(opcao == 0) ? printw("->") : printw("  ");
		printw("Procurar transacao\n");
		(opcao == 1) ? printw("->") : printw("  ");
		printw("Adicionar transacao\n");
		(opcao == 2) ? printw("->") : printw("  ");
		printw("Adicionar amigiunho\n");
		(opcao == 3) ? printw("->") : printw("  ");
		printw("Configuracoes\n");
		(opcao ==4 ) ? printw("->") : printw("  ");
		printw("Sair\n");
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 4) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 4: opcao--;
		
		clear();

	} while(tecla != enter);

	/**Retorna opcao para tela usuario*/
	return opcao;

}

void tela_usuario(char CPF[])
{
	no_lista_usuario *ptr;
	ptr = encontraNoUsuario(lista_us->primeiro,CPF);

	int opcao;

	clear();
	/**Mostra titulo*/
	imprime_titulo();

	opcao=menu_usuario(ptr->usuario.nome);

	switch(opcao)
	{
		case 0:
			break;

		case 1:
			break;

		case 2:
			break;

		case 3:
			int oi;
			printf("entrousaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
			scanw("%d",oi);
			tela_configuracao(ptr->usuario.nome);
			break;

		case 4:
			tela_inicial();
			break;

		default: 
			break;	
	}


	/**Mostrar caracteres*/
	echo();
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

	/**Para enquanto nao forem iguais, nao aceitar*/
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
	no_lista_usuario *ptr;

	char CPF[12],senha[51];

	int chance=3;

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


	ptr = encontraNoUsuario(lista_us->primeiro,CPF);

	while(ptr==NULL && chance>0)
	{
		printw("CPF inexistente, tente novamente :");
		scanw("%s",CPF);
		ptr = encontraNoUsuario(lista_us->primeiro,CPF);
		chance--;

	}

	if(chance==0)
	{
		tela_inicial();
	}


	//Oculta caractres digitados
	noecho();

	if(strcmp(ptr->usuario.CPF,CPF)==0)
	{
		//Poem o cursor na linha para identificar onde esta
		curs_set(1);

		//Recebe a senha
		printw("Senha:");
		scanw("%s",senha);

		while(strcmp(ptr->usuario.senha,senha)!=0)
		{
			printw("Senha incorreta, digite novamente :" );
			scanw("%s",senha);
		}

		tela_usuario(CPF);
	}
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

	clear();

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