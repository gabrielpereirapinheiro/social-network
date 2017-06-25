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
	int tipo;
	int idade;
	int numero_transacao;
	
}Usuario; 

/// Struct que define os atributos de uma categoria
typedef struct categoria{
	int idCategoria;
	char nomeCategoria[51];
}Categoria;

/// Struct que define os atributos de uma avaliacao
typedef struct avaliacao{
	int notaTransacao; //Nota da transacao dada por um usuario
	char comentAvaliClient[201]; //Comentario sobre a avaliacao do cliente
}Avaliacao;

/// Struct que define os atributos de um servico
typedef struct servico{
	Usuario usuarioProvedor; //O usuario que esta provendo o servico
	char precoServico[31];
	char descricaoServico[201];
}Servico;

/// Definicao da struct de Transacao
typedef struct transacao{
	int idTransacao; //chave primaria de transacao
	int classificacao; // indica se a transacao ja foi concluida ou nao. 0 significa pendente e 1 concluida
	Servico servico; //Informacoes do servico que caracterizou essa transacao
	Categoria categoria; //Categoria da transacao
	Avaliacao avaliacao; //Avaliacao da transacao
	Usuario usuarioCliente; //O usuario que esta consumindo o servico
}Transacao;


// Assinatura das funcoes 
void sair_do_programa();

void imprime_titulo();

Usuario tela_sign_up();

void tela_sing_in();

int opcoes_tela_inicial();

void tela_inicial();

void sair_do_programa();

void cores(int opcao);

void imprime_titulo();

void imprime_usuario(char nome[]);

void excluiAmigo(char nome[], char CPF[]);

void adicionaAmigo(char nome[], char CPF[]);

void tela_cor(char nome[],char CPF[]);

void editaInformacoes(char nome[], char CPF[]);

void adicionarTransacao(char nome[], char CPF[]);

void procurar_transacao(char nome[], char CPF[]);

int menu_usuario(char nome[]);

void tela_usuario(char CPF[]);

// Funcoes relacionadas ao back-end 
// int EditarUsuario(Lista); 
void tela_usuario(char CPF[]);

int menu_configuracao(char nome[]);

void tela_configuracao(char nome[]);

void tela_visualiza(char nomeAdmin[]);

void tela_visualiza_transacao(char nomeAdmin[]);

void tela_cadastra_descadastra(char nomeAdmin[]);
/// Funcao Tela Administrador
void telaAdmin(char nomeAdmin[]);


/*************RETIRAR****************/
void populaLista();

#endif
