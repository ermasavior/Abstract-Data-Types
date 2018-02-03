/* File: mesintoken.c */
/* Realisasi Mesin Token: Model Akuisisi Versi I */

#include "mesintoken.h"

boolean EndToken;
Token CToken;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while ((CC == BLANK) && (CC != MARK)) {
		ADV();
	}
}

void STARTTOKEN()
/* I.S. : CC sembarang 
   F.S. : EndToken = true, dan CC = MARK; 
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */
{
	START();
	IgnoreBlank();
	if (CC == MARK)
		EndToken = true;
	else {
		EndToken = false;
		SalinToken();
	}
}

void ADVTOKEN()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true      
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	IgnoreBlank();
	if (CC == MARK)
		EndToken = true;
	else
		SalinToken();
}

void SalinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang Token melebihi NMax, maka sisa Token "dipotong" */
{
	CToken.val = 0;
	for(;;) {
		int x = CC - '0';
		if (x<=9 && x>=0) {
			CToken.val += x;
			CToken.tkn = 'b';
		}
		else{
			CToken.val = (-1);
			CToken.tkn = CC;
		}
		
		ADV();
		if ((CC == MARK) || (CC == BLANK))
			break;
		else {
			CToken.val *= 10;
		}
	}
	IgnoreBlank();
}
