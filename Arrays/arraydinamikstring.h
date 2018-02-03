/* MODUL TABEL STRING */
/* Berisi definisi dan semua primitif pemrosesan tabel string */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel dinamik */

#ifndef ARRAYDINAMIK_H
#define ARRAYDINAMIK_H

#include "boolean.h"

/*  Kamus Umum */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/
#define ValUndef -9999

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef char ElType[20];   /* type elemen tabel */
typedef struct { 
	ElType * TI; /* alokasi memori tempat penyimpan elemen (container) */
	int Neff; /* >=0, banyaknya elemen efektif */
  int MaxEl; /*Ukuran elemen*/
} TabStr;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabStr, cara deklarasi dan akses: */
/* Deklarasi : T : TabStr */
/* Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i 
   T.MaxEl untuk mengakses ukuran elemen matriks dinamik */
/* Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */
  
/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]
#define MaxEl(T)  (T).MaxEl

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void Dealokasi (TabStr * T);
/*I.S: T terdefinisi
  F.S: TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

void MakeEmpty (TabStr * T, int maxel);
/* I.S. T sembarang untuk maxel>=0*/
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-maxel+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabStr T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

/* *** Daya tampung container *** */
int MaxNbEl (TabStr T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabStr T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */

IdxType GetLastIdx (TabStr T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabStr T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean IsIdxEff (TabStr T, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabStr T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsiTab (TabStr * T);
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */

void TulisIsi (TabStr T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/

/* ********** SEARCHING ********** */
IdxType Search (TabStr T, ElType X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

#endif