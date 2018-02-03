/*
	Nama: Erma Safira Nurmasyita
	NIM: 13516072
	Tanggal: 16 November 2017
	Topik: Binary Tree
*/

#include "bintree.h"
#include <stdio.h>

int main () {
	BinTree B;
	infotype X;
	addrNode L = AlokNode(1);
	addrNode R = AlokNode(3);
	MakeTree(2, L, R, &B);
	Left(L) = AlokNode(10); Right(L) = AlokNode(0);
	Left(R) = AlokNode(8);	Right(R) = AlokNode(9); //Left(Left(R)) = AlokNode(8);
	//PrintPreorder(B);
	PrintTree(B, 3);
	printf("SearchTree: %d\n", SearchTree(B, 33));
	printf("Level: %d\n", Level(B,3));
	printf("Tinggi: %d\n", Tinggi(B));
	//AddDaunTerkiri(&B, 5);
	PrintTree(B, 3);
	//DelDaunTerkiri(&B, &X);
	printf("NBElmt: %d -- NBDaun: %d\n", NbElmt(B), NbDaun(B));
	AddDaun (&B, 0, 13, true);
	PrintTree(B, 3);
	
	printf("\n");
	PrintList(MakeListDaun(B));
	PrintPreorder(B);
	printf("\n");
	PrintList(MakeListPreorder(B));
	printf("\n");
	PrintList(MakeListLevel(B, 4));
	printf("\n\n");
	DelDaun(&B, 8);
	PrintTree(B, 3);

	List LL;
	int N;
	LL = Alokasi(69);
	Next(LL) = Nil;
	CountProcedure(LL, &N);
	printf(">>>%d\n", N);
	return 0;
}