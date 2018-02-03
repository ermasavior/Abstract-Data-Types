#include "array.h"
#include <stdio.h>

int main() {
	//Kamus
	TabInt T;
	ElType X, max, min, median;
	IdxType i, idx;
	int count;

	//Algoritma
	BacaIsi(&T);

	scanf("%d", &X);
	count = 0;
	for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
		if (Elmt(T, i) == X) {
			count += 1;
		}
	}
	TulisIsiTab(T);
	printf("\n");
	printf("%d\n", count);

	if (SearchB(T,X)) {
		printf("%d\n", Search2(T,X));

		InsSortAsc(&T);
		MaxMinUrut(T, &max, &min);
		if (NbElmt(T)%2 == 0)
			median = Elmt(T, NbElmt(T)/2);
		else
			median = Elmt(T, (NbElmt(T)/2)+1);

		if (X == max)
			printf("maksimum\n");
		if (X == min)
			printf("minimum\n");
		if (X == median)
			printf("median\n");
	}
	else
		printf("%d tidak ada\n", X);

	return 0;
}