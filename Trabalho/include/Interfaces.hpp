#ifndef INTERFACES_HPP
#define INTERFACES_HPP 

#include "lista_usuario.hpp"
#include "transacoes.hpp"
#include "grafos.hpp"
#include "categoria.hpp"
#include "bancodados.hpp"

#define cima      259
#define baixo     258
#define esquerda  260
#define direita   261
#define enter     10

// Assinatura das funcoes 

void imprime_titulo();

Usuario tela_sign_up();

void tela_sing_in(lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

int opcoes_tela_inicial();

void tela_inicial(lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void sair_do_programa(lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void cores(int opcao);

void imprime_titulo();

void imprime_usuario(char nome[]);

void excluiAmigo(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void adicionaAmigo(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void tela_cor(char nome[],char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void editaInformacoes(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void adicionarTransacao(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void procurar_transacao(char nome[], char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

int menu_usuario(char nome[]);

void tela_usuario(char CPF[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

// Funcoes relacionadas ao back-end 
// int EditarUsuario(Lista); 
int menu_configuracao(char nome[]);

void tela_configuracao(char nome[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void tela_visualiza(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void tela_visualiza_transacao(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);

void tela_cadastra_descadastra(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);
/// Funcao Tela Administrador
void telaAdmin(char nomeAdmin[], lista_usuario *listaUsuarios, ListaTransacao *listaTransacoes, ListaCategoria *listaCategorias, Grafo *grafoAmizade, Grafo *grafoTransacoes);


/*************RETIRAR****************/
void populaLista(ListaCategoria *listaCategorias);

#endif
