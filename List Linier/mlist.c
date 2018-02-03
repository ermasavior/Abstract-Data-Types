#include "listlinier.h"
#include <stdio.h>

int main() {
	List L1,L2,L3;
	infotype x;
	address Prec;

	CreateEmpty(&L1);
	CreateEmpty(&L2);
	InsVFirst(&L1,10);
	InsVFirst(&L1,20);
	InsVFirst(&L1,30);
	InsVFirst(&L2,40);
	InsVFirst(&L2,50);
	InsVFirst(&L2,20);
	InsVFirst(&L2,90);
	Konkat(L1,L2,&L3);
	DelAll(&L3);

	/*InsVFirst(&L1,10000);
	InsVFirst(&L1,10009);
	InsVLast(&L1,666);
	DelAfter(&L1,&Prec,Search(L1,10));
	Prec = Alokasi(9000000);
	InsertAfter(&L1,Prec,Search(L1,10));
	printf("%d\n", Max(L1));*/

	PrintInfo(L1);
	PrintInfo(L2);
	PrintInfo(L3);
	return 0;
}