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
