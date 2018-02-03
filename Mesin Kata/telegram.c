/*
	NIM				: 13516072
	Nama			: Erma Safira Nurmasyita
	Tanggal			: 28 September 2017
	Topik praktikum : Mesin kata versi 1
*/

#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>

boolean IsKataSama (Kata K1, Kata K2);
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan urutan karakter yang menyusun kata juga sama. 
	 Dua kata kosong adalah kata yang sama. */
void TulisKata (Kata K1);
/*Menuliskan kata ke layar*/

int main() {
	//Kamus
	int NKata = 0;
	int katareg = 0;
	int katapjg = 0;
	Kata koma, titik;
	int biaya = 0;
	
	//Algoritma
	koma.TabKata[1] = 'K'; koma.TabKata[2] = 'O'; koma.TabKata[3] = 'M'; koma.TabKata[4] = 'A'; koma.Length = 4;
	titik.TabKata[1] = 'T'; titik.TabKata[2] = 'I'; titik.TabKata[3] = 'T'; titik.TabKata[4] = 'I'; titik.TabKata[5] = 'K'; titik.Length = 5;
	STARTKATA();
	while (!EndKata) {
		NKata++;
		if (IsKataSama(koma, CKata)) {
			printf(",");
		}
		else if (IsKataSama(titik, CKata)) {
			printf(".");
		}
		else {
			TulisKata(CKata);
			if (CKata.Length < 10)
				katareg++;
			else
				katapjg++;
		}
		ADVKATA();
		if (!IsKataSama(koma, CKata) && !IsKataSama(titik, CKata) && !EndKata)
			printf(" ");
	}
	
	biaya = katareg*1000 + katapjg*1500;
	if (NKata>10)
		biaya = 0.9*biaya;
	
	printf("\n%d\n%d\n", katareg, katapjg);
	printf("%d\n", biaya);
	return 0;
}

boolean IsKataSama (Kata K1, Kata K2)
{
	if ((K1.Length) == (K2.Length)) {
		boolean bKataSama = true;
		int i = 1;
		while (i<=K1.Length && bKataSama) {
			if (K1.TabKata[i] != K2.TabKata[i])
				bKataSama = false;
			i++;
		}
		
		return bKataSama;
	}
	else
		return false;
	
}

void TulisKata (Kata K1)
/*Menuliskan kata ke layar*/
{
	int i;
	for (i=1; i<=K1.Length; i++) {
		printf("%c", K1.TabKata[i]);
	}
}