/* Desenvolvido por Gabriel Machado e Francisco Pires 
*  Curso: Ciência da Computação - UFRR
*
*
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
