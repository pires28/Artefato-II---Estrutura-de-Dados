/*
 * main.c
 *
 *  Created on: 26 de dez de 2016
 *      Author: MACHADO-AXE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main()
{
	lPalavras* ppalavras ;
	ppalavras = criaListPalavras();

	ppalavras = lerArquivo(ppalavras);

	imprime(ppalavras);

	return 0;
}
/*
 * machado (1,1) (2,1) (3,1)
 * rodrigues (1,1) (4,1)
 * amanda (1,1) (3,1)
 * gabriel (2,2) (3,1) (4,1)
 * fuvale (4,1)*/
