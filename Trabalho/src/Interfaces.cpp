#include "Interfaces.hpp"


/// Funcao que sera responsavel por sair do programa na tela inicial quando o usuario socilitar, nela serao salvos os grafos no arquivo
void sair_do_programa(lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{

	/** 
		\details Funcao que salva as listas e finaliza o programa.
		\param	lista_usuario *listaUsuarios: lista de usuarios lida do banco. 
		 		ListaTransacao *listaTransacoes: lista de transacoes lida do banco.
		 		ListaCategoria *listaCategorias: lista de categorias lida do banco.
		 		Grafo *grafoAmizade: grafo de amizades entre usuarios lido do banco.
		 		Grafo *grafoTransacoes: grafo de transacoes entre usuarios lido do banco.
		\return Sem retorno. 
	*/

	
	/* Finalizar a ncruses */
	endwin(); 
	

	/* Salvando grafos e listas no banco de dados */
	int retornoSalvaUsuario = 0;
	int retornoSalvaGrafoAmiz = 0;
	int retornoSalvaTransacoes = 0;
	int retornoSalvaGrafoTransac = 0;
	int retornoSalvaCategorias = 0;

	if(listaUsuarios->primeiro != NULL){
		retornoSalvaUsuario = SalvaArquivoUsuario(listaUsuarios);
	}
	if(grafoAmizade->vertices != NULL){
		retornoSalvaGrafoAmiz = SalvaArquivoGrafoAmiz(grafoAmizade);
	}
	if(listaTransacoes->primeiro != NULL){
		retornoSalvaTransacoes = SalvaArquivoTransacao(listaTransacoes);
	}
	if(listaCategorias->primeiro != NULL){
		retornoSalvaCategorias = SalvaArquivoCategorias(listaCategorias);
	}
	if(grafoTransacoes->vertices != NULL){
		retornoSalvaGrafoTransac = SalvaArquivoGrafoTransacao(grafoTransacoes);
	}
	

	/* Desalocando listas e grafos */
	LiberaListaUsuario(listaUsuarios);
	destroi_grafo(grafoAmizade);
	LiberaListaTransacao(listaTransacoes);
	LiberaListaCategoria(listaCategorias);
	destroi_grafo(grafoTransacoes);

	/*Fim do programa*/
	exit(0);
}


/// Funcao responsavel por definir as cores do fundo e das letras do programa
void cores(int opcao)
{

	/** 
		\details Funcao que recebe uma opcao e muda as cores da tela.
		\param int opcao: opcao de cores da tela escolhida pelo usuario. 
		\return Sem retorno. 
	*/
	/*Colocando a cor que o usuario escolheu*/
	bkgd(COLOR_PAIR(opcao));
}


/// Funcao responsavel por imprimir Titulo na tela sempre na mesma posicao
void imprime_titulo()
{
	/** 
		\details Funcao que imprime o titulo da tela.
		\param	Sem parametros.
		\return Sem retorno. 
	*/

	/*Definindo a posicao onde ira imprimir*/
	move(1,0);
	printw(" ---------------------------\n");
	printw(" S O C I A L  N E T W O R K\n");
	printw(" ---------------------------\n");
}


/// Funcao responsavel por imprimir nome do usuario no canto superior da tela
void imprime_usuario(char nome[])
{

	/** 
		\details Funcao que exibe na tela o nome do usuario logado.
		\param	char nome[]: nome do usuario logado. 
		\return Sem retorno. 
	*/

	/*Definindo a posicao e imprimindo na tela o nome do usuario*/
	move(2,30);
	printw("\t\t [ Usuario : %s ]",nome);
}


/// Funcao Excluir Amigo
void excluiAmigo(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{	


	/** 
		\details Permite exclusao de amizade pelo usuario.
		\param	Char nome[]: Nome do usuario;
				Char CPF[]: CPF do usuario.
				lista_usuario *listaUsuarios: lista de usuarios lida do banco. 
		 		ListaTransacao *listaTransacoes: lista de transacoes lida do banco.
		 		ListaCategoria *listaCategorias: lista de categorias lida do banco.
		 		Grafo *grafoAmizade: grafo de amizades entre usuarios lido do banco.
		 		Grafo *grafoTransacoes: grafo de transacoes entre usuarios lido do banco.
		\return Sem retorno. 
	*/	


	char email_excluir[101];
	int controle_erro; 

	/* Limpando a tela */
	clear();

	/* Oculta o cursor na tela */
	curs_set(0);
	
	/* Construcao da interface */	
	imprime_titulo();

	imprime_usuario(nome);
	move(5,0);
	printw("Lista de usuarios:\n");


	no_lista_usuario * ptr_amigo = NULL;
	no_lista_usuario * ptr_usuario = encontraNoUsuario(listaUsuarios->primeiro,CPF);
	Vizinhos * ptr = vizinhos(grafoAmizade, ptr_usuario->usuario.ID);
	

	/* Listando amigos */
	if (ptr == NULL)
	{
		printw("\n\nVoce nao possui usuarios amigos.\n\n");
		getch();
	}
	else{
		
		while(ptr != NULL)
		{	
			ptr_amigo = encontraNoUsuarioID(listaUsuarios->primeiro,ptr->id);
			printw("%s\t %s\n",ptr_amigo->usuario.nome,ptr_amigo->usuario.email);

			ptr = ptr->prox;
		}

		curs_set(1);
		echo();

		/* Excluindo usuario desejado */
		printw("\n\nInsira o email do usuario a ser deletado:\n");
		scanw("%s",email_excluir);

		ptr_amigo = encontraNoUsuarioEmail(listaUsuarios->primeiro,email_excluir);
		
		if (ptr_amigo == NULL)
		{
			printw("\n\nUsuario com email fornecido nao consta em sua lista de amigos!\n\n");
			getch();
		}
		else{
			
			controle_erro = remove_aresta(grafoAmizade, ptr_usuario->usuario.ID, ptr_amigo->usuario.ID);

			if (controle_erro != ERRO)
			{

				printw("\n\n\nAmigo removido com sucesso! \n");
				getch();
			}
			else
			{

				printw("\n\n\nTal usuario nao existe na sua relacao de amigos ou o email esta incorreto! \n");
				getch();
			}
		}
	}
	
	tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
}


/// Funcao Adicionar Amigo
void adicionaAmigo(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{	


	/** 
		\details Permite inclusao de amizade pelo usuario.
		\param	Char nome[]: Nome do usuario;
				Char CPF[]: CPF do usuario.
				lista_usuario *listaUsuarios: lista de usuarios lida do banco. 
		 		ListaTransacao *listaTransacoes: lista de transacoes lida do banco.
		 		ListaCategoria *listaCategorias: lista de categorias lida do banco.
		 		Grafo *grafoAmizade: grafo de amizades entre usuarios lido do banco.
		 		Grafo *grafoTransacoes: grafo de transacoes entre usuarios lido do banco.
		\return Sem retorno. 
	*/	


	char email_desejado[101];
	int controle_erro; 

	/* Limpando a tela */
	clear();

	/* Oculta o cursor na tela */
	curs_set(0);
	
	/* Construcao da interface */	
	imprime_titulo();

	imprime_usuario(nome);
	move(5,0);
	printw("Digite o email do usario desejado:\n");


	curs_set(1);
	echo();

	/* Encontrando usuario desejado */
	scanw("%s",email_desejado);
	no_lista_usuario * ptr_usuario = encontraNoUsuario(listaUsuarios->primeiro,CPF);
	no_lista_usuario * ptr_amigo = encontraNoUsuarioEmail(listaUsuarios->primeiro,email_desejado);

	if(ptr_amigo== NULL)
	{
		printw("Nao foi encontrado o usuario '%s'. \n\nPressiona qualquer tecla para voltar para o MENU",email_desejado);
		getch();
		tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
	}
	else
	{
		/* Adicionando no grafo de amizades */
		controle_erro = adiciona_aresta(grafoAmizade, ptr_usuario->usuario.ID, ptr_amigo->usuario.ID);

		if (controle_erro != ERRO)
		{

			printw("\n\n\n'%s' adicionado com sucesso! \n",ptr_amigo->usuario.nome);
			getch();
		}
		else
		{

			printw("\n\n\n'%s' nao pode ser adicionado! \n",ptr_amigo->usuario.nome);
			getch();
		}		
	}

	tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);

}


///
void tela_cor(char nome[],char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{


	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/


	/* Limpando a tela */
	clear();

	/* Oculta o cursor na tela */
	curs_set(0);

	int opcao=0;

	int tecla;

	do{
		
		imprime_titulo();

		imprime_usuario(nome);
	
		move(5,0);

		(opcao == 0) ? printw(" >") : printw("  ");
		printw("Fundo preto e letra azul\n");
		(opcao == 1) ? printw(" >") : printw("  ");
		printw("Fundo branco e letra verde \n");
		(opcao == 2) ? printw(" >") : printw("  ");
		printw("Fundo vermelho e letra amarela \n");
		(opcao == 3) ? printw(" >") : printw("  ");
		printw("Fundo verde e letra preta \n");
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 3) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 3: opcao--;
		
		clear();

	} while(tecla != enter);



	switch (opcao) {

		case 0:	/* nome */

			cores(2);
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 1: /* senha */

			cores(1);
			echo();
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 2: /* email */

			cores(3);
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 3: /* idade */

			cores(4);
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;
	}

}


/// Funcao Editar Informacoes
void editaInformacoes(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{	


	/** 
		\details Permite edicao de informacao do usuario.
		\param	Char nome[]: Nome do usuario; 
				Char CPF[]: CPF do usuario.
		\return Sem retorno. 
	*/	


	/* Variveis que recebem os novos dados do usuario */
	char novo_nome[101], nova_senha[51], novo_email[101];
	int nova_idade = 0;
	int opcao = 0, tecla;
	
	no_lista_usuario * ptr = encontraNoUsuario(listaUsuarios->primeiro,CPF);


	/* Limpando a tela */
	clear();

	/* Oculta o cursor na tela */
	curs_set(0);


	/* Selecionar a opcao de alteracao de campo */
	do{
		
		imprime_titulo();

		imprime_usuario(nome);
	
		move(5,0);

		(opcao == 0) ? printw(" >") : printw("  ");
		printw("Alterar Nome (%s)\n",ptr->usuario.nome);
		(opcao == 1) ? printw(" >") : printw("  ");
		printw("Alterar Senha \n");
		(opcao == 2) ? printw(" >") : printw("  ");
		printw("Alterar Email (%s)\n",ptr->usuario.email);
		(opcao == 3) ? printw(" >") : printw("  ");
		printw("Alterar Idade (%d)\n",ptr->usuario.idade);
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 3) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 3: opcao--;
		
		clear();

	} while(tecla != enter);


	curs_set(1);
	echo();

	/* Alterando o campo desejado */
	switch (opcao) {

		case 0:	/* nome */

			printw("\n\n\nDigite o novo nome: \n");
			scanw("%[^\n]s",novo_nome);
			
			strcpy(ptr->usuario.nome,novo_nome);
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 1: /* senha */

			noecho();
			printw("\n\n\nDigite o novo senha: \n");
			scanw("%s",nova_senha);
			
			strcpy(ptr->usuario.senha,nova_senha);
			echo();
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 2: /* email */

			printw("\n\n\nDigite o novo email: \n");
			scanw("%s",novo_email);

			strcpy(ptr->usuario.email,novo_email);
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 3: /* idade */

			nova_idade = -1;

			
			while(nova_idade<0)
			{
				printw("\n\n\nDigite a nova idade: \n");
				scanw("%d",&nova_idade);
			}

			ptr->usuario.idade = nova_idade;
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;
	}
}

 
int menu_configuracao(char nome[])
{


	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/


	//Oculta o cursor na tela
	curs_set(0);

	int opcao = 0, tecla;

	do{
		
		imprime_titulo();

		imprime_usuario(nome);
	
		move(5,0);

		(opcao == 0) ? printw(" >") : printw("  ");
		printw("Editar informacoes\n");
		(opcao == 1) ? printw("->") : printw("  ");
		printw("Editar cores \n");
		(opcao == 2) ? printw(" >") : printw("  ");
		printw("Voltar");
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 2) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 2: opcao--;
		
		clear();

	} while(tecla != enter);

	/**Retorna opcao para tela usuario*/
	return opcao;

}


void tela_configuracao(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{

	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador e char CPF[]: CPF do usuario 
		\return Sem retorno. 
	*/

	int opcao;
	clear();
	/**Mostra titulo*/
	imprime_titulo();
	
	opcao=menu_configuracao(nome);

	switch(opcao)
	{
		case 0:
			editaInformacoes(nome,CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 1:
			tela_cor(nome,CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 2:
			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		default: 
			break;	
	}

	/**Mostrar caracteres*/
	echo();
}


/// Funcao Adiciona Transacao
void adicionarTransacao(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{	

	/** 
		\details Permite ao usuario adicionar uma transacao.
		\param	Char nome[]: Nome do usuario; 
				Char CPF[]: CPF do usuario.
		\return Sem retorno. 
	*/
	char categoria_desejada[51];
	char descricao_servico[201];
	char preco_servico[31];

	clear();
	imprime_titulo();

	noListaCategoria * ptr_categoria = listaCategorias->primeiro;
	printw("\n");

	/* Listando as categorias de transacoes existentes */
	while(ptr_categoria != NULL)
	{
		printw("%s\n",ptr_categoria->categoria.nomeCategoria);
		ptr_categoria = ptr_categoria->prox;
	}

	curs_set(1);
	echo();

	/* Categoria desejada requerida do usuario */
	printw("\n\nDigite o nome da categoria desejada:\n");
	scanw("%s",categoria_desejada);

	noListaCategoria * no_categoria = listaCategorias->primeiro;

	/* Pegando no da categoria escolhida */
	while(no_categoria != NULL)
	{
		if(strcmp(no_categoria->categoria.nomeCategoria, categoria_desejada) == 0){

			break;
		}
		no_categoria = no_categoria->prox;
	}

	clear();
	imprime_titulo();

	printw("\nInsira a descricao do produto/servico oferecido. Maximo 200 caracteres. \n\n");
	scanw("%[^\n]s",descricao_servico);

	clear();
	imprime_titulo();

	printw("\nInsira o preco do servico.\n\n");
	scanw("%[^\n]s",preco_servico);

	no_lista_usuario * no_usuario_atual = encontraNoUsuario(listaUsuarios->primeiro, CPF);
	
	/* Criando um servico */
	Servico novo_servico = CriaServicoUsuario(no_usuario_atual->usuario, preco_servico, descricao_servico);

	/* Adicionando transacao */
	Transacao nova_transacao = MontaTransacao(novo_servico, no_categoria->categoria);
	noListaTransacao * novo_no_transacao = criaNoTransacao(nova_transacao);
	int retorno_addNoListaTransacaoNova;
	retorno_addNoListaTransacaoNova = addNoListaTransacaoNova(listaTransacoes, novo_no_transacao);

	if(retorno_addNoListaTransacaoNova == SEM_ERRO)
	{
		printw("\n\nTransacao adicionada com sucesso.\nClique ENTER para sair.\n");
		getch();
	}
	else
	{
		printw("\n\nTransacao nao foi adicionada!\nClique ENTER para sair.\n");
		getch();
	}

	tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);

}

void procurar_transacao(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{	
	/** 
		\details Permite ao usuario adicionar uma transacao.
		\param	Char nome[]: Nome do usuario; 
				Char CPF[]: CPF do usuario.
		\return Sem retorno. 
	*/
	char categoria_desejada[51];

	clear();
	imprime_titulo();
	imprime_usuario(nome);


	noListaCategoria * ptr_categoria = listaCategorias->primeiro;
	printw("\n\n\n");

	/* Listando as categorias de transacoes existentes */
	while(ptr_categoria != NULL)
	{
		printw("-%s\n",ptr_categoria->categoria.nomeCategoria);
		ptr_categoria = ptr_categoria->prox;
	}

	curs_set(1);
	echo();

	/* Categoria desejada requerida do usuario */
	printw("\n\nDigite o nome da categoria desejada:\n");
	scanw("%s",categoria_desejada);

	noListaTransacao * ponteiro = listaTransacoes->primeiro;

	/* Contador para identificar a transacao escolhida */
	int contador = 0; 
	while(ponteiro != NULL)
	{
		
		if(strcmp(ponteiro->transacao.categoria.nomeCategoria,categoria_desejada) == 0)
		{	
			printw("--------------------------------------------------------------");	
			printw("\n(%d)\n\nDescricao: %s\nPreco: %s\n",contador, ponteiro->transacao.servico.descricaoServico,
												  		 ponteiro->transacao.servico.precoServico);
			printw("--------------------------------------------------------------");
			
			contador++;
		}

		ponteiro = ponteiro->prox;
	}
	getch();

	/* Recebe opcao desejada */
	int opcao_desejada;
	printw("Digite o numero da opcao desejada:\n");
	scanw("%d",&opcao_desejada);


	/* Recuperando transacao escolhida */
	ponteiro = listaTransacoes->primeiro;
	contador = 0;
	while(ponteiro != NULL)
	{

		if(strcmp(ponteiro->transacao.categoria.nomeCategoria,categoria_desejada) == 0)
		{	
			if(opcao_desejada == contador)
			{
				break;
			}

			contador++;
		}

		ponteiro = ponteiro->prox;
	}


	clear();
	imprime_titulo();
	imprime_usuario(nome);

	/* Mostrando ao usuario transacao esolhida */
	printw("--------------------------------------------------------------");
	printw("\n(%d)\n\nDescricao: %s\nPreco: %s\n",contador, ponteiro->transacao.servico.descricaoServico,
												  		 ponteiro->transacao.servico.precoServico);
	printw("--------------------------------------------------------------\n\n");
	
	//Fazer : adicionar transacao nova  o grafo !!!!!!

	printw("Entrar em contato com %s pelo email %s.\n",ponteiro->transacao.servico.usuarioProvedor.nome,
													   ponteiro->transacao.servico.usuarioProvedor.email);		
	getch();
}

int menu_usuario(char nome[])
{

	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Retorna a opcao escolhida pelo usuario. 
	*/


	clear();
	//Oculta o cursor na tela
	curs_set(0);

	int opcao = 0, tecla;

	do{
		
		imprime_titulo();

		imprime_usuario(nome);
	
		move(5,0);

		(opcao == 0) ? printw(" >") : printw("  ");
		printw("Procurar transacao\n");
		(opcao == 1) ? printw(" >") : printw("  ");
		printw("Adicionar transacao\n");
		(opcao == 2) ? printw(" >") : printw("  ");
		printw("Adicionar amigiunho\n");
		(opcao == 3) ? printw(" >") : printw("  ");
		printw("Excluir amigo\n");
		(opcao ==4 ) ? printw(" >") : printw("  ");
		printw("Configuracoes\n");
		(opcao ==5 ) ? printw(" >") : printw("  ");
		printw("Sair\n");
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 5) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 5: opcao--;
		
		clear();

	} while(tecla != enter);

	/**Retorna opcao para tela usuario*/
	return opcao;

}

void tela_usuario(char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{

	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/


	no_lista_usuario *ptr = NULL;
	ptr = encontraNoUsuario(listaUsuarios->primeiro,CPF);

	int opcao;

	clear();
	/**Mostra titulo*/
	imprime_titulo();

	opcao=menu_usuario(ptr->usuario.nome);

	switch(opcao)
	{
		case 0:
			procurar_transacao(ptr->usuario.nome, ptr->usuario.CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 1:
			adicionarTransacao(ptr->usuario.nome, ptr->usuario.CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 2:
			adicionaAmigo(ptr->usuario.nome, ptr->usuario.CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 3:
			excluiAmigo(ptr->usuario.nome, ptr->usuario.CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 4:
			tela_configuracao(ptr->usuario.nome, ptr->usuario.CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 5:
			tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
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

	move(5,0);

	printw("Cadastro");

	move(7,0);

	printw("Nome:");
	scanw("%[^\n]s",cadastrar_agora.nome);

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
	cadastrar_agora.tipo = NORMAL;
	
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
void tela_visualiza(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{

	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/

	no_lista_usuario *ptr;
	imprime_titulo();
	imprime_usuario(nomeAdmin);

	move(5,0);
	if(listaUsuarios->primeiro == NULL)
	{
		printw("Nao ha usuarios salvos !\n\nClique 'enter' para voltar ");
	}
	else
	{
		no_lista_usuario *ponteiro = listaUsuarios->primeiro;

		Usuario recebe_usuario;

		while(ponteiro!=NULL)
		{

			recebe_usuario = ponteiro->usuario;

			Vizinhos *lista_vizinhos;

			Vertice *ponteiro_vertice = recupera_vertice_x(grafoAmizade,recebe_usuario.ID);

			if (ponteiro_vertice==NULL)
			{
				printw("deu ruim");
			}

			lista_vizinhos = ponteiro_vertice->listVizinhos;

			move(5,0);
			printw("Usuario %s\n\n",recebe_usuario.nome);

			if(lista_vizinhos == NULL)
			{
				printw("Sem amigos\n\n");
			}

			while(lista_vizinhos!=  NULL)
			{
				no_lista_usuario *temporario = encontraNoUsuarioID(listaUsuarios->primeiro,lista_vizinhos->id);
				printw("Amigo : %s \n",temporario->usuario.nome);
				lista_vizinhos = lista_vizinhos->prox;
			}

			ponteiro = ponteiro->prox;

			printw("Clique enter para ver o proximo");
			getch();
		}

	}

	getch();
	telaAdmin(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
}


void tela_visualiza_transacao(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{

	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/

	imprime_titulo();
	imprime_usuario(nomeAdmin);
	getch();
	telaAdmin(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
}

void tela_cadastra_descadastra(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{

	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/

	imprime_titulo();
	imprime_usuario(nomeAdmin);
	
	int opcao=0;
	int tecla;

	do{
		
		imprime_titulo();
		imprime_usuario(nomeAdmin);
		move(4,1);
		
		move(6,0);
		(opcao == 0) ? printw(" >") : printw("  ");
		printw("Cadastrar\n");
		(opcao == 1) ? printw(" >") : printw("  ");
		printw("Descadastrar\n");
		(opcao == 2) ? printw(" >") : printw("  ");
		printw("Voltar\n");
	
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
			{
				imprime_titulo();
				imprime_usuario(nomeAdmin);
				move(5,0);

				curs_set(1);
				echo();

				char cat_nome[51];
				printw("\nDigite o nome da categoria a ser cadastrada:\n");
				scanw("%[^\n]s",cat_nome);

				Categoria categ;
				strcpy(categ.nomeCategoria,cat_nome);
				noListaCategoria *novo_no = criaNoCategoria(categ);
				addNoListaCategoriaNova(listaCategorias, novo_no);

				printw("\n\nA categoria %s foi adicionada com sucesso !\nEnter para voltar.\n", cat_nome);
				getch();

				telaAdmin(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			}
			break;
			
		case 1:
			{
				imprime_titulo();
				imprime_usuario(nomeAdmin);
				move(5,0);

				curs_set(1);
				echo();

				char cat_nome[51];
				printw("\nDigite o nome da categoria a ser descadastrada:\n");
				scanw("%[^\n]s",cat_nome);

				Categoria categ;
				strcpy(categ.nomeCategoria,cat_nome);
				noListaCategoria * deleta_no = encontraNoCategoria(listaCategorias->primeiro, categ);
				deletaNoListaCategoria(listaCategorias, deleta_no);

				printw("\n\nA categoria %s foi excluida com sucesso !\nEnter para voltar.\n", cat_nome);
				getch();

				telaAdmin(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			}		
			break;
			
		case 2:

			telaAdmin(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;
						
		default: 
			break;	
	}

}

/// Funcao Tela Administrador
void telaAdmin(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{
	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/

	clear();
	curs_set(0);
	
	int opcao=0;
	int tecla;

	do{
		
		imprime_titulo();
		imprime_usuario(nomeAdmin);
		move(4,1);

		printw("Bem-vindo Administrador do SOCIAL NETWORK");
		
		move(6,0);
		(opcao == 0) ? printw(" >") : printw("  ");
		printw("Visiualizar informacoes dos usuarios\n");
		(opcao == 1) ? printw(" >") : printw("  ");
		printw("Cadastrar e descadastrar transacoes\n");
		(opcao ==2 ) ? printw(" >") : printw("  ");
		printw("Visiualizar transacoes e avaliacoes\n");
		(opcao ==3 ) ? printw(" >") : printw("  ");
		printw("Sair\n");
	
		tecla = getch();

		if(tecla == baixo)
			(opcao == 3) ? opcao = 0: opcao++;
		if(tecla == cima)
			(opcao == 0) ? opcao = 3: opcao--;
		
		clear();

	} while(tecla != enter);

	switch(opcao)
	{
		case 0:
			tela_visualiza(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;
			
		case 1:
			tela_cadastra_descadastra(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;
			
		case 2:
			tela_visualiza_transacao(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;
				
		case 3:
			tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		default: 
			break;	
	}
}
void tela_sing_in(lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{

	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/

	no_lista_usuario *ptr;

	char CPF[12],senha[51];
	char cpf_admin[] = "00000000000";
	char nomeAdmin[] = "Admin";
	char senhaAdmin[] = "ADMIN123";

	int chance=3;

	//Limpa a tela
	clear();

	//Mostrar caracteres
	echo();

	//Imprime o titulo no canto superior
	imprime_titulo();

	//Move para baixo onde ira imprimir
	move(5,0);

	/**Adiciocna um valor com tamanho menor para so ser aceito CPF de 11 digitos*/
	strcpy(CPF,"010");

	/**Enquanto nao tiver 11 elementos nao aceita*/
	while(strlen(CPF)!=11)
	{
		//Recebe nome do usuario
		printw("CPF:");
		scanw("%s",CPF);
	}

	if(strcmp(CPF,cpf_admin) == 0)
	{

		noecho();
		curs_set(1);

		printw("Senha:");
		scanw("%s",senha);

		while(strcmp(senha,senhaAdmin) != 0)
		{
			printw("Senha incorreta, digite novamente :" );
			scanw("%s",senha);
		}

		/*OBS.: Colocar senha no banco !!!!*/
		telaAdmin(nomeAdmin, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
	}
	else{

		/** Verifica se o ponteiro listaUsuarios->primeiro aponta pra algo diferente de NULL, se sim, a funcao
		  	encontraNoUsuario podera ser usada. */
		if(listaUsuarios->primeiro != NULL)
		{

			ptr = encontraNoUsuario(listaUsuarios->primeiro,CPF);
		}
		else
		{

			ptr = NULL;
		}

		while(ptr==NULL && chance>0)
		{
			printw("CPF inexistente, tente novamente :");
			scanw("%s",CPF);
			
			if(listaUsuarios->primeiro != NULL)
			{
				
				ptr = encontraNoUsuario(listaUsuarios->primeiro,CPF);
			}	
			chance--;
		}

		if(chance==0)
		{	
			printw("\nCrie um cadastro primeiro e clique em qualquer tecla para voltar\n");
			getch();
			tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
		}
		// !Oculta caractres digitados
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

			tela_usuario(CPF, listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
		}
	}
}

int opcoes_tela_inicial(lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{
	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/
	int opcao = 0, tecla;

	do{
		
		imprime_titulo();

		move(4,1);

		printw("Seja bem-vindo ao SOCIAL NETWORK");
		
		move(6,0);
		(opcao == 0) ? printw(" >") : printw("  ");
		printw("Log In\n");
		(opcao == 1) ? printw(" >") : printw("  ");
		printw("Cadastro\n");
		(opcao ==2 ) ? printw(" >") : printw("  ");
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

void tela_inicial(lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes)
{
	/** 
		\details Funcao que exibe a tela apos login do usuario administrador do sistema.
		\param	char nomeAdmin[]: nome do administrador. 
		\return Sem retorno. 
	*/
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
	init_pair(2,COLOR_BLUE,COLOR_BLACK);
	init_pair(3,COLOR_YELLOW,COLOR_RED);
	init_pair(4,COLOR_BLACK,COLOR_GREEN);

	cores(1);
		
	//Funcao que imprime o titulo na parte superior da tela	
	imprime_titulo();

	//Recebe a opcao na tela inicial
	opcao = opcoes_tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);

	switch(opcao)
	{
		case 0 :
			tela_sing_in(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;

		case 1:
			{
				no_lista_usuario * novo_no = criaNoUsuario(tela_sign_up());
				addNoListaUsuarioNovo(listaUsuarios, novo_no);
				adiciona_vertice(grafoAmizade, novo_no->usuario.ID);//OBS.: Talvez nao esteja certo, pois nao sabemos 														 // se esta mudando o ID diretamente no no
			}
			break;
		case 2 :
			sair_do_programa(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
			break;
	}

	clear();
	tela_inicial(listaUsuarios, listaTransacoes, listaCategorias, grafoAmizade, grafoTransacoes);
	noecho();
}