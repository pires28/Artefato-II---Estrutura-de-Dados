
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

//Funções para as Palavras
lPalavras* criaListPalavras()
{
    lPalavras* novo = (lPalavras*)malloc(sizeof(lPalavras));
    novo->quantidades = NULL;
    novo->proxPalavra = NULL;
    novo = NULL;
    return novo;
}
lPalavras* inserePalavras(lPalavras* p, char* palavra, int linha)
{
    lPalavras* novoP = (lPalavras*)malloc(sizeof(lPalavras));
    lOcorrencia* quant = (lOcorrencia*)malloc(sizeof(lOcorrencia));
    quant->quantVezes = 1;
    quant->numLinhas = linha;
    quant->proxQuanti = NULL;
    novoP->quantidades = quant;
    strcpy(novoP->palavras, palavra);
    novoP->proxPalavra = p;
    return novoP;
}
void imprime(lPalavras* pp)
{
    lPalavras* pri;
    lOcorrencia* quant;
    for(pri = pp; pri != NULL; pri = pri->proxPalavra)
    {
        printf("\n%s  <=>", pri->palavras);
        for(quant = pri->quantidades; quant != NULL; quant = quant->proxQuanti)
        {
            printf("  (%d, %d)",quant->numLinhas, quant->quantVezes);
        }
        printf("\n");
    }
}
lPalavras* buscaPalavras(lPalavras* pp, char* palavra)
{
    if(pp != NULL)
    {
        lPalavras* aux;
        for(aux = pp; aux != NULL; aux = aux->proxPalavra)
        {
            if(strcmp(palavra,aux->palavras) == 0)
            {
                return aux;
            }
        }
    }
    return NULL;
}

//Funções para Quantidades
lOcorrencia* inseriQuantLin( lOcorrencia* pq, int linha)
{
    lOcorrencia* novoQ;
    lOcorrencia* aux;
    lOcorrencia* ant;
    novoQ = ( lOcorrencia*)malloc(sizeof( lOcorrencia));
    for(aux = pq; aux != NULL; aux = aux->proxQuanti)
    {
        ant = aux;
    }
    novoQ->numLinhas = linha;
    novoQ->quantVezes = 1;
    ant->proxQuanti = novoQ;
    novoQ->proxQuanti = NULL;
    return pq;
}
//Funções de funcionamento
lPalavras* lerArquivo (lPalavras* ppalavra)
{
    int i = 0, linha = 1;
    char palavra[40];
    lPalavras* novo = ppalavra;
    lPalavras* aux = ppalavra;

    FILE *arquivo;
    arquivo = fopen("texto.txt", "r");
    if (arquivo == NULL)
    {
        printf("!!!   ERRO   !!!");
    }
    palavra[i] = fgetc(arquivo);
    while(palavra[i] != EOF)
    {
        while(palavra[i] != ' ' && palavra[i] != '\n')
        {
            if(palavra[i] == EOF)
                break;
            i++;
            palavra[i] = fgetc(arquivo);
        }
        if(palavra[i] == '\n'){
            linha++;
        }
        palavra[i] = '\0';
        i=0;
        aux = buscaPalavras(novo, palavra);
        if(aux == NULL)
        {
            //printf("Entrou no if AUX\n");
            novo = inserePalavras(novo, palavra, linha);
        }
        else
        {
            //printf("Entrou no else");
            if(aux->quantidades->numLinhas != linha)
            {
                inseriQuantLin(aux->quantidades, linha);
            }else{
                aux->quantidades->quantVezes++;
            }
        }

        palavra[i] = fgetc(arquivo);
    }
    fclose(arquivo);
    return novo;
}
