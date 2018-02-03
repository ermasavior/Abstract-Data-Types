/*
	NIM				: 13516072
	Nama			: Erma Safira Nurmasyita
	Tanggal			: 28 September 2017
	Topik praktikum : Mesin kata versi 1
*/

#include "mesintoken.h"
#include <stdio.h>

int main () {
	int N;
	
	STARTTOKEN();
	if (EndToken)
		printf("Ekspresi kosong\n");
	while (!EndToken) {
		if (CToken.tkn == 'b')
			printf("%d\n", CToken.val);
		else
			printf("%c\n", CToken.tkn);
		ADVTOKEN();
	}
	return 0;
}
