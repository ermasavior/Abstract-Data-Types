/* File : prioqueue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#include <stdlib.h>
#include "prioqueue.h"
#include <stdio.h>

/* ********* Prototype ********* */
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	if (Tail(Q)>=Head(Q))
		return ((Tail(Q)-Head(Q)+1) == MaxEl(Q));
	else
		return (Head(Q) == Tail(Q)+1);
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if (Tail(Q)>=Head(Q))
		return (Tail(Q)-Head(Q)+1);
	else //if (Tail(Q)<Head(Q))
		return(MaxEl(Q)-(Head(Q)-Tail(Q)-1));
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype*) malloc((Max+1) * sizeof(infotype));
	if ((*Q).T != NULL) {
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	} else
		MaxEl(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	free((*Q).T);
	MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{
	int idx2;
	if (IsEmpty(*Q)) {
		Head(*Q)++;
		Tail(*Q) = Head(*Q);
	} else {
		if (Tail(*Q) != MaxEl(*Q))
			Tail(*Q)++;
		else
			Tail(*Q) = 1;
	}

	InfoTail(*Q) = X;
	infotype temp = InfoTail(*Q);
		int idx = Tail(*Q)-1;
	        if (idx < 1)
	        	idx = MaxEl(*Q);
		if (Prio(temp) > Prio(Elmt(*Q, idx)) && (NBElmt(*Q) > 1)) {
	        while (Prio(temp) > Prio(Elmt(*Q, idx)) && (idx != Head(*Q))) {
	        	idx2 = idx + 1;
	        	if (idx2 > MaxEl(*Q))
	        		idx2 = 1;
	            Elmt(*Q, idx2) = Elmt(*Q, idx);
	            idx -= 1;
	            if (idx<1)
	            	idx = MaxEl(*Q);
	        }

	        idx2 = idx + 1;
	        if (idx2 > MaxEl(*Q))
	        	idx2 = 1;
	        if (Prio(temp) <= Prio(Elmt(*Q, idx)))
	            Elmt(*Q, idx2) = temp;
	        else {
	            Elmt(*Q, idx2) = Elmt(*Q, idx);
	            Elmt(*Q, idx) = temp;
	        }
		}
}

void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	*X = InfoHead(*Q);
	if (NBElmt(*Q) == 1) {
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	} else {
		if (Head(*Q) != MaxEl(*Q))
			Head(*Q)++;
		else
			Head(*Q) = 1;
	}
}

/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	infotype X;
	while (!IsEmpty(Q)) {
		Del(&Q, &X);
		printf("%d %d\n", Prio(X), Info(X));
	}
}
