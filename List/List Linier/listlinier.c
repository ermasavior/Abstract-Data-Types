/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Realisasi address dengan pointer */
/* infotype adalah integer */

#include <stdlib.h>
#include "listlinier.h"
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P = malloc (sizeof(int));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P = First(L);
	boolean found = false;

	while (P != Nil && !found) {
		if (Info(P) == X)
			found = true;
		else
			P = Next(P);
	} /*found=true or P==Nil*/
	return P;
}
boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	address Pcheck = First(L);
	boolean found = false;

	while (Pcheck != Nil && !found) {
		if (Pcheck == P)
			found = true;
		else
			Pcheck = Next(Pcheck);
	} /*found=true or P==Nil*/
	return found;
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	address P = First(L);
	address Prec = Nil;
	boolean found = false;

	while (P != Nil && !found) {
		if (Info(P) == X)
			found = true;
		else {
			Prec = P;
			P = Next(P);
		}
	} /*found=true or P==Nil*/
	if (found)
		return Prec;
	else
		return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = Alokasi(X);
	if (P != Nil) {
		InsertFirst(L,P);
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P = Alokasi(X);
	if (P != Nil) {
		InsertLast(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	DelFirst(L,&P);
	*X = Info(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;
	DelLast(L,&P);
	*X = Info(P);
	Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmpty(*L))
		InsertFirst(L,P);
	else {
		address Prec = First(*L);
		while (Next(Prec) != Nil) {
			Prec = Next(Prec);
		}
		InsertAfter(L,P,Prec);
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	Next(*P) = Nil;
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{

	address Prec = Nil;
	address P = First(*L);
	boolean found = false;

	if (Info(P) == X) {
		DelFirst(L,&P);
		Dealokasi(&P);
	} else {
		while (P != Nil && !found) {
			if (Info(P) == X)
				found = true;
			else {
				Prec = P;
				P = Next(P);
			}
		}
		if (found) {
			DelAfter(L,&P,Prec);
			Dealokasi(&P);
		}
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	address Prec = First(*L);
	if (Next(Prec) == Nil) {
		DelFirst(L,P);
	} else {
		while (Next(Next(Prec)) != Nil) {
			Prec = Next(Prec);
		}
		DelAfter(L,P,Prec);
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	printf("[");
	if (!IsEmpty(L)) {
		address P = First(L);
		while (Next(P) != Nil) {
			printf("%d,", Info(P));
			P = Next(P);
		}
		printf("%d", Info(P));
	}
	printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	int count = 0;
	address P = First(L);
	while (P != Nil) {
		count++;
		P = Next(P);
	}
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	infotype valMax = Info(First(L));
	address P = Next(First(L));
	while (P != Nil) {
		if (Info(P)>valMax)
			valMax = Info(P);
		P = Next(P);
	}
	return valMax;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
	infotype valMax = Max(L);
	address P = First(L);
	boolean found = false;
	
	while (P != Nil && !found) {
		if (Info(P) = valMax)
			found = true;
		else {
			P = Next(P);
		}
	}
	return P;
}
infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
	infotype valMin = Info(First(L));
	address P = Next(First(L));
	while (P != Nil) {
		if (Info(P)<valMin)
			valMin = Info(P);
		P = Next(P);
	}
	return valMin;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
	infotype valMin = Min(L);
	address P = First(L);
	boolean found = false;
	
	while (P != Nil && !found) {
		if (Info(P) = valMin)
			found = true;
		else {
			P = Next(P);
		}
	}
	return P;
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
	address P = First(L);
	float sum = 0;
	int N = 0;
	
	while (P != Nil) {
		N++;
		sum += Info(P);
		P = Next(P);
	}
	
	return sum/N;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
	address P = First(*L);
	address Pc;
	
	while (P != Nil) {
		Pc = P;
		P = Next(P);
		Dealokasi(&Pc);
	}
	First(*L) = Nil;
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
	address P = First(*L);
	address Pc;
	List LInv;

	CreateEmpty(&LInv);
	while (P != Nil) {
		P = Next(P);
		DelFirst(L,&Pc);
		InsertFirst(&LInv,Pc);
	}
	if (!IsEmpty(LInv)) {
		CopyList(&LInv, L);
		First(LInv) = Nil;
	}
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	List LInv;
	address P = First(L);
	address P3;
	boolean isfailed = false;
	
	CreateEmpty(&LInv);
	while (P != Nil && !isfailed) {
		P3 = Alokasi(Info(P));
		if (P3 == Nil)
			isfailed = true;
		else {
			InsertFirst(&LInv, P3);
			P = Next(P);
		}
	}
	
	if (isfailed)
		DelAll(&LInv);
		
	return LInv;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
	First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
	List LCpy;
	address P = First(L);
	address P3;
	boolean isfailed = false;
	
	CreateEmpty(&LCpy);
	while (P != Nil && !isfailed) {
		P3 = Alokasi(Info(P));
		if (P3 == Nil)
			isfailed = true;
		else {
			InsertLast(&LCpy, P3);
			P = Next(P);
		}
	}
	
	if (isfailed)
		DelAll(&LCpy);
	return LCpy;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	boolean isfailed = false;
	address P = First(Lin);
	address P3;
	CreateEmpty(Lout);
	
	while (P != Nil && !isfailed) {
		P3 = Alokasi(Info(P));
		if (P3 == Nil)
			isfailed = true;
		else {
			InsertLast(Lout, P3);
			P = Next(P);
		}
	}
	
	if (isfailed)
		DelAll(Lout);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
	address P = First(L1);
	address P3;
	boolean isfailed = false;
	
	CreateEmpty(L3);
	while (P != Nil && !isfailed) {
		P3 = Alokasi(Info(P));
		if (P3 == Nil)
			isfailed = true;
		else {
			InsertLast(L3, P3);
			P = Next(P);
		}
	}
	
	P = First(L2);
	while (P != Nil && !isfailed) {
		P3 = Alokasi(Info(P));
		if (P3 == Nil)
			isfailed = true;
		else {
			InsertLast(L3, P3);
			P = Next(P);
		}
	}
	
	if (isfailed)
		DelAll(L3);
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	address P = First(*L1);
	if (P!=Nil) {
		First(*L3) = P;
		while (Next(P) != Nil) {
			P = Next(P);
		}
		CreateEmpty(L1);
		Next(P) = First(*L2);
	}
	else
		First(*L3) = First(*L2);

	CreateEmpty(L2);
}


void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
	address Pl = First(L);
	address P;
	boolean isfailed = false;
	int N = NbElmt(L)/2;
	int i = 1;
	
	CreateEmpty(L1);
	CreateEmpty(L2);

	while (i<=N && !isfailed) {
		P = Alokasi(Info(Pl));
		if (P != Nil) {
			InsertLast(L1, P);
			Pl = Next(Pl);
			i++;
		} else
			isfailed = true;
	}
	
	while (Pl != Nil && !isfailed) {
		P = Alokasi(Info(Pl));
		if (P != Nil){
			P = Alokasi(Info(Pl));
			InsertLast(L2, P);
			Pl = Next(Pl);
		} else
			isfailed = true;
	}

	if (isfailed) {
		DelAll(L1);
		DelAll(L2);
	}
}
