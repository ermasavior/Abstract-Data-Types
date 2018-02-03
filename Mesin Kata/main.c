#include "mesinkata.h"
#include <stdio.h>


void TulisKata (Kata K1)
/*Menuliskan kata ke layar*/
{
	int i;
	for (i=1; i<=K1.Length; i++) {
		printf("%c", K1.TabKata[i]);
	}
}

int main() {
	int i = 1;

	STARTKATA();
	while (!EndKata) {
		printf("[%d]%d", i, CKata.Length);
		TulisKata(CKata);
		printf("\n");
		i++;
		ADVKATA();
	}
	return 0;
}