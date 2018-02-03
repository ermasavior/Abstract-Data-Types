#include "matriks.h"
#include <stdio.h>

int main() {
	//Kamus
	MATRIKS M;
	float det;

	BacaMATRIKS(&M, 3,3);
	PInverse1(&M);
	printf("\n\n");
	det = Determinan(M);
	printf("%.2f\n", det);

	TulisMATRIKS(KaliMATRIKS(M,M));

	return 0;
}