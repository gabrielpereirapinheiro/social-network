#include "headers.hpp"

/// Funcao que sempre sera executada no comeco do programa, e vai verificar se todos os arquivos existem, se sim, recupera
/// todos os dados antes do termino a todas as listas e grafos do sistema. Se nao, indica que eh a primeira execucao do sistema
/// e vai criar todas as listas como NULL
void RecuperaDadosArquivos(lista_usuario *listaUsuario, ListaTransacao *listaTransacao, ListaCategoria *listaCat,
						   Grafo *grafoAmizade, Grafo *grafoTransacoes){
	//tamanho do cabecalho do arquivo de usuarios: 76
}

/// Funcao que, antes do programa encerrar de fato, vai salvar todos os usuarios e suas informacoes em um arquivo
int SalvaArquivoUsuario(lista_usuario *listaUsuario){
	FILE *fp = fopen("../arquivos/ArquivoUsuarios.txt", "w");
	no_lista_usuario *ptrNoUsuario = NULL; //! vai ser o ponteiro para percorrer a lista de usuarios

	if(fp == NULL){
		printf("Nao foi possivel abrir o arquivo ArquivoUsuarios.txt!\n");
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
	noListaTransacao * ptrNoTransacoes = NULL;  //! vai ser o ponteiro para percorrer a lista de transacoes

	if(fp == NULL){
		printf("Nao foi possivel abrir o arquivo ArquivoTransacoes.txt!\n");
		return ERRO;
	}

	// Vai escrever sempre, por default, a ordem com que os atributos de uma transacao sao dispostas no arquivo
	// OBS: so vai aparecer no arquivo os campos de nota/comentario/id usuario cliente se o campo classificacao for 1!
	fprintf(fp, "ID|CLASSIFICACAO(PENDENTE/CONCLUIDO)|ID USUARIO PROVEDOR|PRECO|DESCRICAO|ID CATEGORIA|CATEGORIA|NOTA TRANSACAO|COMENTARIO TRANSACAO| ID USUARIO CLIENTE\n\n");
	// quantidade de transacoes no sistema
	fprintf(fp, "%d\n", listaTransacao->numeroTransacoes);

	//Escrito o cabecalho, agora vai escrever todos os dados de cada transacao na ordem definida no cabecalho
	ptrNoTransacoes = listaTransacao->primeiro; // ptrNoUsuario vai receber a cabeca da lista
	//TODO
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

	return SEM_ERRO;
}

/// Funcao que, antes do programa encerrar de fato, vai salvar o grafo de amizades em um arquivo
int SalvaArquivoGrafoAmiz(Grafo *grafoAmizade){

	return SEM_ERRO;
}

///Funcao que, antes do programa encerrar de fato, vai salvar o grafo de transacoes em um arquivo
int SalvaArquivoGrafoTransacao(Grafo *grafoTransacoes){

	return SEM_ERRO;
}