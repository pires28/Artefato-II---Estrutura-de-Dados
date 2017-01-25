/*
 * Lista.h
 *
 *  Created on: 22 de dez de 2016
 *      Author: MACHADO-AXE
 */

#ifndef LISTA_H_
#define LISTA_H_

#endif /* LISTA_H_ */

typedef struct lPalavras {
	char palavras[40];
	struct lPalavras *proxPalavra;
	struct lOcorrencia* quantidades;
} lPalavras;

typedef struct lOcorrencia {
	int numLinhas;
	int quantVezes;
	struct lOcorrencia* proxQuanti;
} lOcorrencia;


//Fun��es para palavras
lPalavras* criaListPalavras();
lPalavras* inserePalavras( lPalavras* pp, char* palavra);
void imprime(lPalavras* pp);
lPalavras* buscaPalavras(lPalavras* pp, char* palavra);

//Fun��es para quantidades
lOcorrencia* crisQt();
lOcorrencia* inseriQuantLin(lOcorrencia* pq, lPalavras* pp, int linha);
lOcorrencia* buscaOcorrencia(lOcorrencia* quanti, int linha);

//Fun��es de funcionamento
void soma_quant(lOcorrencia* pq, lPalavras* pp);
lPalavras* lerArquivo (lPalavras* ppalavra);
