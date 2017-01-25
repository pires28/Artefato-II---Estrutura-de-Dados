/*
 * Lista.c
 *
 *  Created on: 26 de dez de 2016
 *      Author: MACHADO-AXE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

//Funções para as Palavras
lPalavras* criaListPalavras()
{
	lPalavras* novo = (lPalavras*)malloc(sizeof(lPalavras));
	lOcorrencia* quanti = ( lOcorrencia*)malloc(sizeof( lOcorrencia));
	novo->quantidades = quanti;
	novo->quantidades->numLinhas = 1;
	novo->quantidades->quantVezes = 0;
	return novo;
}
lPalavras* inserePalavras(lPalavras* p, char* palavra)
{
	lPalavras* novoP = (lPalavras*)malloc(sizeof(lPalavras));
	novoP->quantidades = malloc(sizeof(lOcorrencia));
	strcpy(novoP->palavras, palavra);
	novoP->proxPalavra = p;
	//p=novoP;
	return novoP;
}
void imprime(lPalavras* pp)
{
	lPalavras* pri;
	for(pri = pp; pri != NULL; pri = pri->proxPalavra){
		printf("%s\n", pri->palavras);
	}
}
lPalavras* buscaPalavras(lPalavras* pp, char* palavra)
{
	if(pp != NULL){
		lPalavras* aux;
		for(aux = pp; aux != NULL; aux = aux->proxPalavra){
			if(strcmp(palavra,aux->palavras) == 0){
				return aux;
			}
		}
	}
	return NULL;
}

//Funções para Quantidades
 lOcorrencia* ciraQt( lOcorrencia* pq, lPalavras* pp, char* palavra)
{
	return NULL;
}
 lOcorrencia* inseriQuantLin( lOcorrencia* pq, lPalavras* ppalavra, int linha)
{
	 lOcorrencia* novoQ;
	 lOcorrencia* auxQ;
	 lOcorrencia* aux2;
	novoQ = ( lOcorrencia*)malloc(sizeof( lOcorrencia));
	novoQ->numLinhas = linha;
	for(auxQ = pq; auxQ != NULL; auxQ = auxQ->proxQuanti){
		aux2 = auxQ;
	}
	novoQ->proxQuanti = NULL;
	aux2->proxQuanti = novoQ;
	pq=novoQ;
	return pq;
}
//Funções de funcionamento
lPalavras* lerArquivo (lPalavras* ppalavra)
{
	int i = 0, linha = 1;
	char palavra[40];
	lPalavras* novo = (lPalavras*)malloc(sizeof(lPalavras));
	lPalavras* aux = ppalavra;
	FILE *arquivo;
	arquivo = fopen("texto.txt", "r");
	if (arquivo == NULL){
		printf("!!!   ERRO   !!!");
	}
	palavra[i] = fgetc(arquivo);
	while(palavra[i] != EOF){
		while(palavra[i] != ' ' && palavra[i] != '\n'){
			if(palavra[i] == EOF)
				break;
			printf("%c", palavra[i]);
			i++;
			palavra[i] = fgetc(arquivo);
		}
		if(palavra[i] == '\n')
			linha++;
		palavra[i] = '\0';
		i=0;
		aux = buscaPalavras(novo, palavra);
		if(aux == NULL){
			printf("\tEntrou no if");
			novo = inserePalavras(novo, palavra);
		}else {//procura o nodo da linha atual se existir adiciona quantidade
			printf("\tEntrou no else");
			aux->quantidades->quantVezes++;
		}
		printf("\n %s \n", novo->palavras);
		palavra[i] = fgetc(arquivo);
	}
	fclose(arquivo);
	return novo;
}
