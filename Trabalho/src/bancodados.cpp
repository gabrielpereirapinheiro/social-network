#include "bancodados.hpp"

/// Funcao que dada uma lista, recupera os dados desse arquivo para a lista de usuarios
lista_usuario *RecupDadosUsuario(lista_usuario *listaUsuario){
	//tamanho do cabecalho do arquivo de usuarios: 76
	FILE *fUser = NULL; //! descritor do arquivo
	Usuario usuarioRecuperado; //! variavel do tipo Usuario que vai receber os dados que estao sendo recuperados do arquivo
	char *campoCbclho = NULL; //! string que vai receber cada string entre os delimitadores do arquivo
	int contadorCampoAtual = 0; //! contador para verificar qual elemento dos delimitadores do arquivo esta sendo verificado
	char strTemp[1001]; //! string temporaria que vai receber cada linha do arquivo

	fUser = fopen("../arquivos/ArquivoUsuarios.txt", "r"); // abertura do arquivo

	listaUsuario = criarListaUsuario(); // cria a lista

	// Parte que vai verificar se ao abrir o arquivo, ele existe, se existir, abre como leitura e insere os elementos da lista
	// senao, retorna a lista criada

	if(fUser != NULL){
		fseek(fUser, 76, SEEK_SET); // vai pular o cabecalho do arquivo
		fscanf(fUser, "%d\n", &listaUsuario->numeroUsuarios); // vai pegar a quantidade de usuarios

		// parte que vai ler do arquivo e inserir na lista
		while(!feof(fUser)){
		  	fgets(strTemp, 1001, fUser); // pega uma linha completa do arquivo
		  	if(feof(fUser)) break; // aqui sai do loop de percorrer o arquivo
		  	contadorCampoAtual = 0;
		  	campoCbclho = NULL;
			campoCbclho = strtok (strTemp,"|\n"); // vai quebrar a string, usando | e \n como delimitadores
			while (campoCbclho != NULL){
				// switch que, dado o valor que esta no contadorCampoAtual, vai ler o tipo de dado que tem que ser lido
			   switch(contadorCampoAtual){
			    	case 0: usuarioRecuperado.ID = atoi(campoCbclho); break; // ID
			    	case 1: strcpy(usuarioRecuperado.CPF, campoCbclho); break; // CPF
			    	case 2: strcpy(usuarioRecuperado.nome, campoCbclho); break; // nome
			    	case 3: strcpy(usuarioRecuperado.senha, campoCbclho); break; // senha
			    	case 4: strcpy(usuarioRecuperado.email, campoCbclho); break; // email
			    	case 5: usuarioRecuperado.tipo = atoi(campoCbclho); break; // tipo
			    	case 6: usuarioRecuperado.idade = atoi(campoCbclho); break; // idade
			    	default: usuarioRecuperado.numero_transacao = atoi(campoCbclho); // numero de transacoes
			    }
			   contadorCampoAtual++;
			   campoCbclho = strtok (NULL, "|\n");
			}
			addNoListaUsuarioExistente(listaUsuario, criaNoUsuario(usuarioRecuperado)); // adiciona o usuario recuperado na lista de usuarios
  		}

		fclose(fUser);
	}

  	return listaUsuario;
}

/// Funcao que dada uma lista, recupera os dados desse arquivo para a lista de transacoes
ListaTransacao *RecupDadosTransacoes(ListaTransacao *listaTransacao){
	//tamanho do cabecalho do arquivo de transacoes: 154
	FILE *fTransacao = NULL; //! descritor do arquivo
	Transacao transacaoRecuperada; //! variavel do tipo Transacao que vai receber os dados que estao sendo recuperados do arquivo
	char *campoCbclho = NULL; //! string que vai receber cada string entre os delimitadores do arquivo
	int contadorCampoAtual = 0; //! contador para verificar qual elemento dos delimitadores do arquivo esta sendo verificado
	char strTemp[1001]; //! string temporaria que vai receber cada linha do arquivo

	fTransacao = fopen("../arquivos/ArquivoTransacoes.txt", "r"); // abertura do arquivo

	listaTransacao = criarListaTransacao(); // cria a lista

	// Parte que vai verificar se ao abrir o arquivo, ele existe, se existir, abre como leitura e insere os elementos da lista
	// senao, retorna a lista criada

	//transacoes
	if(fTransacao != NULL){
		fseek(fTransacao, 154, SEEK_SET); // vai pular o cabecalho do arquivo
		fscanf(fTransacao, "%d\n", &listaTransacao->numeroTransacoes); // vai pegar a quantidade de transacoes

		// parte que vai ler do arquivo e inserir na lista
		while(!feof(fTransacao)){
		  	fgets(strTemp, 1001, fTransacao); // pega uma linha completa do arquivo
		  	if(feof(fTransacao)) break; // aqui sai do loop de percorrer o arquivo
		  	contadorCampoAtual = 0;
		  	campoCbclho = NULL;
			campoCbclho = strtok (strTemp,"|\n"); // vai quebrar a string, usando | e \n como delimitadores
			while (campoCbclho != NULL){
				// switch que, dado o valor que esta no contadorCampoAtual, vai ler o tipo de dado que tem que ser lido
			    if(contadorCampoAtual < 7){
			    	switch(contadorCampoAtual){
			    	case 0: transacaoRecuperada.idTransacao = atoi(campoCbclho); break; // ID
			    	case 1: transacaoRecuperada.classificacao = atoi(campoCbclho); break; // classificacao
			    	case 2: transacaoRecuperada.servico.usuarioProvedor.ID = atoi(campoCbclho); break; // id usuario provedor
			    	case 3: strcpy(transacaoRecuperada.servico.precoServico, campoCbclho); break; // preco
			    	case 4: strcpy(transacaoRecuperada.servico.descricaoServico, campoCbclho); break; // descricao
			    	case 5: transacaoRecuperada.categoria.idCategoria = atoi(campoCbclho); break; // id categoria
			    	default: strcpy(transacaoRecuperada.categoria.nomeCategoria, campoCbclho); break; // categoria
			    	}
			    }

			   // parte que vai verificar se classificao eh pendente ou concluida, se for concluida, ainda tem outros campos para serem obtidos
			    if(contadorCampoAtual > 6 && transacaoRecuperada.classificacao == CONCLUIDA){
			    	switch(contadorCampoAtual){
			    		case 7: transacaoRecuperada.avaliacao.notaTransacao = atoi(campoCbclho); break; // nota da transacao
			    		case 8: strcpy(transacaoRecuperada.avaliacao.comentAvaliClient, campoCbclho); break; // comentario da avaliacao
			    		default: transacaoRecuperada.usuarioCliente.ID = atoi(campoCbclho); // id do usuario cliente
			    	}
			    }
			   contadorCampoAtual++;
			   campoCbclho = strtok (NULL, "|\n");
			}
			addNoListaTransacaoExistente(listaTransacao, criaNoTransacao(transacaoRecuperada)); // adiciona a transacao recuperada na lista de transacoes
  		}
		
		// chama a funcao que coloca as informacoes na lista
		fclose(fTransacao);
	}



	return listaTransacao;
}

/// Funcao que dada uma lista, recupera os dados desse arquivo para a lista de categorias
ListaCategoria *RecupDadosCategorias(ListaCategoria *listaCat){
	//tamanho do cabecalho do arquivo de categorias: 20 
	Categoria categoriaRecuperada;
	char *campoCbclho = NULL; //! string que vai receber cada string entre os delimitadores do arquivo
	int contadorCampoAtual = 0; //! contador para verificar qual elemento dos delimitadores do arquivo esta sendo verificado
	char strTemp[1001]; //! string temporaria que vai receber cada linha do arquivo
	FILE *fCateg = NULL; //! descritor do arquivo
	fCateg = fopen("../arquivos/ArquivoCategorias.txt", "r");

	listaCat = criarListaCategoria(); // cria a lista

	// Parte que vai verificar se ao abrir o arquivo, ele existe, se existir, abre como leitura e insere os elementos da lista
	// senao, retorna a lista criada

	//categorias
	if(fCateg != NULL){
		fseek(fCateg, 20, SEEK_SET); // vai pular o cabecalho do arquivo
		fscanf(fCateg, "%d\n", &listaCat->numeroCategorias); // vai pegar a quantidade de categorias

		// parte que vai ler do arquivo e inserir na lista
		while(!feof(fCateg)){
		  	fgets(strTemp, 1001, fCateg); // pega uma linha completa do arquivo
		  	if(feof(fCateg)) break; // aqui sai do loop de percorrer o arquivo
		  	contadorCampoAtual = 0;
		  	campoCbclho = NULL;
			campoCbclho = strtok (strTemp,"|\n"); // vai quebrar a string, usando | e \n como delimitadores
			while (campoCbclho != NULL){
				// switch que, dado o valor que esta no contadorCampoAtual, vai ler o tipo de dado que tem que ser lido
			   switch(contadorCampoAtual){
			    	case 0: categoriaRecuperada.idCategoria = atoi(campoCbclho); break; // ID da categoria
			    	default: strcpy(categoriaRecuperada.nomeCategoria, campoCbclho); break; // nome da categoria
			    }
			   contadorCampoAtual++;
			   campoCbclho = strtok (NULL, "|\n");
			}
			addNoListaCategoriaExistente(listaCat, criaNoCategoria(categoriaRecuperada)); // adiciona a categoria recuperada na lista de categorias
  		}

		fclose(fCateg);
	}

	return listaCat;
}

/// Funcao que dado um grafo, recupera os dados desse arquivo para o grafo de amizades
Grafo *RecupDadosGrafoAmiz(Grafo *grafoAmizade){
	// tamanho do cabecalho dos arquivos de grafo: 25
	char *campoCbclho = NULL; //! string que vai receber cada string entre os delimitadores do arquivo
	char strTemp[1001]; //! string temporaria que vai receber cada linha do arquivo
	FILE *fGrafAmiz = NULL; //! descritor do arquivo
	int vertice = 0; //! variavel auxiliar para guardar o valor do vertice em que serao adicionadas as arestas
	int ondeArquivo = 0; //! vai receber em que posicao do arquivo comeca os vertices e arestas do grafo
	int contadorAux = 0; //! contador que sera usado para retirar o nome do grafo, e pegar o numero de vertices e arestas, na linha do arquivo
	fGrafAmiz = fopen("../arquivos/GrafoAmizades.txt", "r");

	grafoAmizade = cria_grafo("Grafo de Amizades"); // cria o grafo

	// Parte que vai verificar se ao abrir o arquivo, ele existe, se existir, abre como leitura e insere os elementos no grafo
	// senao, retorna o grafo criado

	//grafo amizades
	if(fGrafAmiz != NULL){
		fseek(fGrafAmiz, 25, SEEK_SET); // vai pular o cabecalho do arquivo
		// pega uma linha completa do arquivo, que contem o nome do grafo, numero de vertices e numero de arestas
		fgets(strTemp, 1001, fGrafAmiz);
		campoCbclho = strtok(strTemp, "|\n");
		// parte que vai pegar as outras informacoes gerais referentes ao grafo, como numero de vertices e arestas
		while(campoCbclho != NULL){
			switch(contadorAux){
				case 1: grafoAmizade->V = atoi(campoCbclho); break;
				case 2: grafoAmizade->E = atoi(campoCbclho); break;
			}
			contadorAux++;
			campoCbclho = strtok (NULL, "|\n");
		}
		ondeArquivo = ftell(fGrafAmiz); // recebe a posicao do arquivo logo depois de pegar as informacoes gerais do grafo
		campoCbclho = NULL; // reinicializa o ponteiro de char como NULL
		// parte que vai adicionar os vertices no grafo
		while(!feof(fGrafAmiz)){
		  	fscanf(fGrafAmiz, "%s", strTemp);
		  	if(feof(fGrafAmiz)) break;
			campoCbclho = strtok (strTemp,">\n");
			while (campoCbclho != NULL){
			   adiciona_vertice(grafoAmizade, atoi(strTemp)); // adiciona o vertice no grafo
			   campoCbclho = strtok (NULL, ">\n");
			}
  		}

  		//volta para a posicao do arquivo guardada na variavel ondeArquivo, para agora adicionar as arestas
  		fseek(fGrafAmiz, ondeArquivo, SEEK_SET);
  		while(!feof(fGrafAmiz)){
		  	fscanf(fGrafAmiz, "%s", strTemp);
		  	contadorAux = 0;
		  	if(feof(fGrafAmiz)) break;
			campoCbclho = strtok (strTemp,">\n");
			vertice = atoi(campoCbclho);
			while (campoCbclho != NULL){
			   if(contadorAux > 0) adiciona_aresta(grafoAmizade, vertice, atoi(strTemp)); // adiciona a aresta no vertice
			   contadorAux++;
			   campoCbclho = strtok (NULL, "|\n");
			}
  		}
		
		fclose(fGrafAmiz);
	}

	return grafoAmizade;

}

/// Funcao que dado um grafo, recupera os dados desse arquivo para o grafo de transacoes
Grafo *RecupDadosGrafoTransac(Grafo *grafoTransacoes){
	// tamanho do cabecalho dos arquivos de grafo: 25
	FILE *fgrafTransac = NULL; //! descritor do arquivo
	fgrafTransac = fopen("../arquivos/GrafoTransacoes.txt", "r");

	grafoTransacoes = cria_grafo("Grafo de Transacoes"); // cria o grafo

	// Parte que vai verificar se ao abrir o arquivo, ele existe, se existir, abre como leitura e insere os elementos no grafo
	// senao, retorna o grafo criado

	//grafo de transacoes
	if(fgrafTransac != NULL){
		
		// chama a funcao que coloca as informacoes na lista
		fclose(fgrafTransac);
	}

	return grafoTransacoes;
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
		fprintf(fp, "%d|%d|%d|\n", ptrNoUsuario->usuario.tipo, ptrNoUsuario->usuario.idade, 
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
		fprintf(fp, "%d|%d|%d|%s|%s|", ptrNoTransacoes->transacao.idTransacao, ptrNoTransacoes->transacao.classificacao, 
										ptrNoTransacoes->transacao.servico.usuarioProvedor.ID, ptrNoTransacoes->transacao.servico.precoServico,
										ptrNoTransacoes->transacao.servico.descricaoServico);

		fprintf(fp, "%d|%s|", ptrNoTransacoes->transacao.categoria.idCategoria, ptrNoTransacoes->transacao.categoria.nomeCategoria);
		// se classificacao for 1, ou seja, a transacao eh classificada como concluida, tem que adicionar informacoes extras
		if(ptrNoTransacoes->transacao.classificacao == CONCLUIDA){
			fprintf(fp, "%d|%s|%d|", ptrNoTransacoes->transacao.avaliacao.notaTransacao, 
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

/// Funcao que vai retornar as informacoes do usuario pelo ID dele, a partir da lista de usuarios
/// E passar essas informacoes para a lista de transacoes
int RecupInfosUsuaID(lista_usuario *listaUsuario, ListaTransacao *listaTransacao){
	Usuario usuarioDesejado; //! O tipo usuario que vai ser retornado
	noListaTransacao *ptrNoTransacoes = NULL;  //! vai ser o ponteiro para percorrer a lista de transacoes
	no_lista_usuario *ptrNoUsuarioProv = NULL, *ptrNoUsuarioCli = NULL; //! Os ponteiros de no de usuario 

	if(listaUsuario->primeiro == NULL || listaTransacao->primeiro == NULL){
		printf("Alguma das listas passadas como parametro vazias! Saindo da funcao RecupInfosUsuaID!\n");
		return ERRO;
	}

	ptrNoTransacoes = listaTransacao->primeiro;

	while(ptrNoTransacoes != NULL){
		ptrNoUsuarioProv = encontraNoUsuarioID(listaUsuario->primeiro, ptrNoTransacoes->transacao.servico.usuarioProvedor.ID);
		if(ptrNoUsuarioProv != NULL){
			ptrNoTransacoes->transacao.servico.usuarioProvedor = ptrNoUsuarioProv->usuario;
		}
		if(ptrNoTransacoes->transacao.classificacao == CONCLUIDA){
			ptrNoUsuarioCli = encontraNoUsuarioID(listaUsuario->primeiro, ptrNoTransacoes->transacao.usuarioCliente.ID);
			ptrNoTransacoes->transacao.usuarioCliente = ptrNoUsuarioCli->usuario;
		}
		ptrNoTransacoes = ptrNoTransacoes->prox;
	}

	return SEM_ERRO;
}