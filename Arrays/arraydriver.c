#include "arraydinamik.h"
#include <stdio.h>

int main() {
	TabInt A, B;

	BacaIsiTab(&A);
	TulisIsi(A);
	BacaIsiTab(&B);
	TulisIsi(B);
	if (IsLess(A,B))
		printf("\n\nArray A less than B\n\n");
	else
		printf("\n\nArray B less than A\n\n");
	printf("\n\n\nArray A simetris gak?");
	if (IsSimetris(A))
		printf("yes\n\n");
	else
		printf("no\n\n");
	printf("index: %d\n", Search1(A,69));
	
	/*printf("\n\nTambah ikon unik jadinnya");
	AddElUnik(&A, 69);
	TulisIsi(A);

	Del1Urut(&A, 4);
	TulisIsi(A);*/

	printf("\n\nSelection mengecil\n");
	MaxSortDesc(&A);
	TulisIsi(A);
	/*printf("Insertion membesar\n");
	InsSortAsc(&A);
	TulisIsi(A);*/

//104-107 sorting dan ?
	//84 86 (?)
	//51 search1
	//24-26 input (?)

	//104 105 107
	//84 86
	//51 54 55 57
	//24-26


	return 0;
}