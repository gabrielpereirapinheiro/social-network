#include "headers.hpp"

/// Funcao que sempre sera executada no comeco do programa, e vai verificar se todos os arquivos existem, se sim, recupera
/// todos os dados antes do termino a todas as listas e grafos do sistema. Se nao, indica que eh a primeira execucao do sistema
/// e vai criar todas as listas como NULL
void RecuperaDadosArquivos(lista_usuario *listaUsuario, ListaTransacao *listaTransacao, ListaCategoria *listaCat,
						   Grafo *grafoAmizade, Grafo *grafoTransacoes){
	//tamanho do cabecalho do arquivo de usuarios: 76
	//tamanho do cabecalho do arquivo de transacoes: 154
	//tamanho do cabecalho do arquivo de categorias: 20
	//tamanho do cabecalho dos arquivos de grafo: 25
}

/// Funcao que, antes do programa encerrar de fato, vai salvar todos os usuarios e suas informacoes em um arquivo
int SalvaArquivoUsuario(lista_usuario *listaUsuario){
	FILE *fp = fopen("../arquivos/ArquivoUsuarios.txt", "w");
	no_lista_usuario *ptrNoUsuario = NULL; //! vai ser o ponteiro para percorrer a lista de usuarios

	if(fp == NULL){
		printf("Nao foi possivel abrir o arquivo ArquivoUsuarios.txt!\n");
		return ERRO;
	}

	if(listaUsuario == NULL){
		printf("Lista de usuario passada eh vazia! Saindo da funcao SalvaArquivoUsuario!\n");
		return ERRO;
	}

	// Vai escrever sempre, por default, a ordem com que os atributos de um usuario sao dispostas no arquivo
	fprintf(fp, "ID|CPF|NOME|SENHA|EMAIL|TIPO(NORMAL/ADMIN)|IDADE|QUANTIDADE DE TRANSACOES|\n\n");
	// quantidade de usuarios no sistema
	fprintf(fp, "%d\n", listaUsuario->numeroUsuarios);

	//Escrito o cabecalho, agora vai escrever todos os dados de cada usuario na ordem definida no cabecalho
	ptrNoUsuario = listaUsuario->primeiro; // ptrNoUsuario vai receber a cabeca da lista
	while(ptrNoUsuario != NULL){
		fprintf(fp, "%d|%s|%s|%s|%s|", ptrNoUsuario->usuario.ID, ptrNoUsuario->usuario.CPF, ptrNoUsuario->usuario.nome,
									   ptrNoUsuario->usuario.senha, ptrNoUsuario->usuario.email);
		fprintf(fp, "%hi|%d|%d|\n", ptrNoUsuario->usuario.tipo, ptrNoUsuario->usuario.idade, 
									ptrNoUsuario->usuario.numero_transacao);
		ptrNoUsuario = ptrNoUsuario->prox;
	}

	fclose(fp);

	return SEM_ERRO;
}

/// Funcao que, antes do programa encerrar de fato, vai salvar todos as transacoes e suas informacoes em um arquivo
int SalvaArquivoTransacao(ListaTransacao *listaTransacao){
	FILE *fp = fopen("../arquivos/ArquivoTransacoes.txt", "w");
	noListaTransacao *ptrNoTransacoes = NULL;  //! vai ser o ponteiro para percorrer a lista de transacoes

	if(fp == NULL){
		printf("Nao foi possivel abrir o arquivo ArquivoTransacoes.txt!\n");
		return ERRO;
	}

	if(listaTransacao == NULL){
		printf("Lista de transacoes passada eh vazia! Saindo da funcao SalvaArquivoTransacao!\n");
		return ERRO;
	}

	// Vai escrever sempre, por default, a ordem com que os atributos de uma transacao sao dispostas no arquivo
	// OBS: so vai aparecer no arquivo os campos de nota/comentario/id usuario cliente se o campo classificacao for 1!
	fprintf(fp, "ID|CLASSIFICACAO(PENDENTE/CONCLUIDO)|ID USUARIO PROVEDOR|PRECO|DESCRICAO|ID CATEGORIA|CATEGORIA|NOTA TRANSACAO|COMENTARIO TRANSACAO| ID USUARIO CLIENTE|\n\n");
	// quantidade de transacoes no sistema
	fprintf(fp, "%d\n", listaTransacao->numeroTransacoes);

	//Escrito o cabecalho, agora vai escrever todos os dados de cada transacao na ordem definida no cabecalho
	ptrNoTransacoes = listaTransacao->primeiro; // ptrNoTransacoes vai receber a cabeca da lista

	while(ptrNoTransacoes != NULL){
		fprintf(fp, "%d|%hi|%d|%s|%s|", ptrNoTransacoes->transacao.idTransacao, ptrNoTransacoes->transacao.classificacao, 
										ptrNoTransacoes->transacao.servico.usuarioProvedor.ID, ptrNoTransacoes->transacao.servico.precoServico,
										ptrNoTransacoes->transacao.servico.descricaoServico);

		fprintf(fp, "%d|%s|", ptrNoTransacoes->transacao.categoria.idCategoria, ptrNoTransacoes->transacao.categoria.nomeCategoria);
		// se classificacao for 1, ou seja, a transacao eh classificada como concluida, tem que adicionar informacoes extras
		if(ptrNoTransacoes->transacao.classificacao == 1){
			fprintf(fp, "%hi|%s|%d|", ptrNoTransacoes->transacao.avaliacao.notaTransacao, 
									 ptrNoTransacoes->transacao.avaliacao.comentAvaliClient, ptrNoTransacoes->transacao.usuarioCliente.ID);
		}
		fprintf(fp, "\n");
		ptrNoTransacoes = ptrNoTransacoes->prox;
	}

	return SEM_ERRO;
}

/// Funcao que, antes do programa encerrar de fato, vai salvar todas as categorias e suas informacoes em um arquivo
int SalvaArquivoCategorias(ListaCategoria *listaCat){
	FILE *fp = fopen("../arquivos/ArquivoCategorias.txt", "w");
	noListaCategoria *ptrNoCategorias = NULL;  //! vai ser o ponteiro para percorrer a lista de transacoes

	if(fp == NULL){
		printf("Nao foi possivel abrir o arquivo ArquivoCategorias.txt!\n");
		return ERRO;
	}

	if(listaCat == NULL){
		printf("Lista de categorias passada eh vazia! Saindo da funcao SalvaArquivoCategorias!\n");
		return ERRO;
	}

	// Vai escrever sempre, por default, a ordem com que os atributos de uma categoria sao dispostas no arquivo
	fprintf(fp, "ID|Nome Categoria|\n\n");
	// quantidade de categorias no sistema
	fprintf(fp, "%d\n", listaCat->numeroCategorias);

	//Escrito o cabecalho, agora vai escrever todos os dados de cada categoria na ordem definida no cabecalho
	ptrNoCategorias = listaCat->primeiro; // ptrNoCategorias vai receber a cabeca da lista

	while(ptrNoCategorias != NULL){
		fprintf(fp, "%d|%s|\n", ptrNoCategorias->categoria.idCategoria, ptrNoCategorias->categoria.nomeCategoria);
		ptrNoCategorias = ptrNoCategorias->prox;
	}

	return SEM_ERRO;
}

/// Funcao que, antes do programa encerrar de fato, vai salvar o grafo de amizades em um arquivo
int SalvaArquivoGrafoAmiz(Grafo *grafoAmizade){
	FILE *fp = fopen("../arquivos/GrafoAmizades.txt", "w");
	Vertice *vert = NULL; //! ponteiro de vertice para percorrer os vertices do grafo
	Vizinhos *vizinhos = NULL; //! ponteiro de vizinhos para percorrer os vizinhos do vertice do grafo

	if(fp == NULL){
		printf("Nao foi possivel abrir o arquivo GrafoAmizades.txt!\n");
		return ERRO;
	}

	if(grafoAmizade == NULL){
		printf("Grafo de amizades passado eh vazio! Saindo da funcao SalvaArquivoGrafoAmiz!\n");
		return ERRO;
	}

	// Vai escrever sempre, por default, a ordem com que as informacoes do grafo vao ser dispostas
	fprintf(fp, "ID VERTICE>|ID ARESTAS|\n\n");
	// vai mostrar: nome do grafo|Quantidade de vertices|Quantidade de arestas|
	fprintf(fp, "%s|%d|%d|\n", grafoAmizade->nomeGrafo, grafoAmizade->V, grafoAmizade->E);

	//Escrito o cabecalho, agora vai escrever todos os dados do grafo de amizades
	if(grafoAmizade->vertices){
			vert = grafoAmizade->vertices;
			while(vert != NULL){
				fprintf(fp, "%d>|", vert->idVertice);
				if(vert->listVizinhos){
					vizinhos = vert->listVizinhos;
					while(vizinhos != NULL){
						fprintf(fp, "%d|", vizinhos->id);
						vizinhos = vizinhos->prox;
					}
				}
				fprintf(fp, "\n");
				vert = vert->prox;
			}	
	}

	return SEM_ERRO;
}

///Funcao que, antes do programa encerrar de fato, vai salvar o grafo de transacoes em um arquivo
int SalvaArquivoGrafoTransacao(Grafo *grafoTransacoes){
	FILE *fp = fopen("../arquivos/GrafoTransacoes.txt", "w");
	Vertice *vert = NULL; //! ponteiro de vertice para percorrer os vertices do grafo
	Vizinhos *vizinhos = NULL; //! ponteiro de vizinhos para percorrer os vizinhos do vertice do grafo

	if(fp == NULL){
		printf("Nao foi possivel abrir o arquivo GrafoTransacoes.txt!\n");
		return ERRO;
	}

	if(grafoTransacoes == NULL){
		printf("Grafo de transacoes passado eh vazio! Saindo da funcao SalvaArquivoGrafoTransacao!\n");
		return ERRO;
	}

	// Vai escrever sempre, por default, a ordem com que as informacoes do grafo vao ser dispostas
	fprintf(fp, "ID VERTICE>|ID ARESTAS|\n\n");
	// vai mostrar: nome do grafo|Quantidade de vertices|Quantidade de arestas|
	fprintf(fp, "%s|%d|%d|\n", grafoTransacoes->nomeGrafo, grafoTransacoes->V, grafoTransacoes->E);

	//Escrito o cabecalho, agora vai escrever todos os dados do grafo de transacoes
	if(grafoTransacoes->vertices){
			vert = grafoTransacoes->vertices;
			while(vert != NULL){
				fprintf(fp, "%d>|", vert->idVertice);
				if(vert->listVizinhos){
					vizinhos = vert->listVizinhos;
					while(vizinhos != NULL){
						fprintf(fp, "%d|", vizinhos->id);
						vizinhos = vizinhos->prox;
					}
				}
				fprintf(fp, "\n");
				vert = vert->prox;
			}	
	}

	return SEM_ERRO;
}

/// Funcao que retorna o tipo usuario pelo ID dele, procurando na lista de usuarios
Usuario GetUsuarioPorID(lista_usuario *listaUsuario, int idUsuario){
	Usuario usuarioDesejado;

	return usuarioDesejado;
}

/// Funcao que vai retornar as informacoes do usuario pelo ID dele, a partir da lista de usuarios
/// E passar essas informacoes para a lista de transacoes
int RecupInfosUsuaID(lista_usuario *listaUsuario, ListaTransacao *listaTransacao){

	return SEM_ERRO;
}