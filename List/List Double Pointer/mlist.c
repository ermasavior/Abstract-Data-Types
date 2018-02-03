#include "listdp.h"
#include <stdio.h>

int main() {
	List L1,L2,L3;
	infotype x;
	address Prec;

	CreateEmpty(&L1);
	CreateEmpty(&L2);
	//InsVLast(&L1,10);
	//InsVLast(&L1,1001);
	InsVFirst(&L1,2);
	
	//InsVFirst(&L1,100);
	//InsVFirst(&L1,6);
	/*//DelAfter(&L1,&Prec,Search(L1,10));
	//Prec = Alokasi(9000000);*/
	//InsertAfter(&L1,Prec,Search(L1,10));
	//DelP(&L2,10);
	//InsVFirst(&L1,20);
	//DelVFirst(&L1,&x);
	DelVFirst(&L1,&x);
	//printf("%d\n", x);

	PrintForward(L1);
	return 0;
}