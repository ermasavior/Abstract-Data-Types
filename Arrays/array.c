/*
    Nama: Erma Safira Nurmasyita
    NIM : 13516072
    Tanggal: 7 September 2017
    Nama file: array.c
*/

/* REALISASI ADT ARRAY */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include "array.h"
#include <stdio.h>

/* Kamus Umum
#define IdxMax 100
Indeks maksimum array, sekaligus ukuran maksimum array dalam C
#define IdxMin 1
Indeks minimum array
#define IdxUndef -999 
Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek
typedef int IdxType;  type indeks
typedef int ElType;   type elemen tabel
typedef struct { 
	ElType TI[IdxMax+1]; memori tempat penyimpan elemen (container)
	int Neff; >=0, banyaknya elemen efektif
} TabInt;
Indeks yang digunakan [IdxMin..IdxMax]
Jika T adalah TabInt, cara deklarasi dan akses:
Deklarasi : T : TabInt
Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i
Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */
  
/* ********** SELEKTOR **********
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)] */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    Neff(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return Neff(T);
}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (Neff(T));
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i>=IdxMin) && (i<=IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));   
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (NbElmt(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (NbElmt(T) == IdxMax);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
    int N;
    ElType X;
    IdxType i;
    do {
        scanf("%d\n", &N);
    } while ((N<0) || (MaxNbEl(*T)<N));

    Neff(*T) = N;
    if (Neff(*T)>0) {
        for (i = GetFirstIdx(*T); i<=GetLastIdx(*T); i++) {
            scanf("%d", &X);
            Elmt(*T, i) = X;
        }
    }
}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
    IdxType i = GetFirstIdx(*T);
    ElType x;

    scanf("%d", &x);
    while ((x != (-9999)) && (i<=GetLastIdx(*T))) {
        Elmt(*T, i) = x;
        scanf("%d", &x);
        i++;
    }
   Neff(*T) = i-1;
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50*/
{
    if (IsEmpty(T))
        printf("Tabel kosong\n");
    else {
        IdxType i;
        for (i = GetFirstIdx(T); i<=GetLastIdx(T); i++)
            printf("[%d]%d\n", i, Elmt(T,i));
    }
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    printf("[");
    if (NbElmt(T) != 0) {
        IdxType i;
        for (i=GetFirstIdx(T); i<=GetLastIdx(T); i++) {
            printf("%d", Elmt(T,i));
            if (i != GetLastIdx(T))
                printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
    TabInt TPlus;
    Neff(TPlus) = NbElmt(T1);
    IdxType i;
    for (i=GetFirstIdx(T1); i<=GetLastIdx(T1) ;i++) {  
        Elmt(TPlus, i) = Elmt(T1, i) + Elmt(T2, i);      
    }
    return TPlus;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
    TabInt TMinus;
    Neff(TMinus) = NbElmt(T1);
    IdxType i;
    for (i=GetFirstIdx(T1); i<=GetLastIdx(T1) ;i++) {  
        Elmt(TMinus, i) = Elmt(T1, i) - Elmt(T2, i);      
    }
    return TMinus;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
    TabInt TTimes;
    Neff(TTimes) = NbElmt(T1);
    IdxType i;
    for (i=GetFirstIdx(T1); i<=GetLastIdx(T1) ;i++) {  
        Elmt(TTimes, i) = Elmt(T1, i) * Elmt(T2, i);      
    }
    return TTimes;
}

TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
    TabInt TKons;
    Neff(TKons) = NbElmt(Tin);
    IdxType i;
    for (i=GetFirstIdx(Tin); i<=GetLastIdx(Tin) ;i++) {  
        Elmt(TKons, i) = Elmt(Tin, i) * c;      
    }
    return TKons;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
    boolean bEqual; /*boolean pengecek apakah array sama*/
    bEqual = (NbElmt(T1)==NbElmt(T2));
    if (bEqual) {
        int N;
        IdxType i = GetFirstIdx(T1);
        while (i<=GetLastIdx(T1) && bEqual) {
            bEqual = Elmt(T1,i)==Elmt(T2,i);
            i++;
        }
    }
    return bEqual;
}

boolean IsLess (TabInt T1, TabInt T2) /*tanda*/
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'; maka [0, 1] < [2, 3] */
{
    IdxType i;
    boolean isSmaller;
    int Nsmaller;
    if (NbElmt(T1)<=NbElmt(T2)) 
        Nsmaller = NbElmt(T1);
    else
        Nsmaller = NbElmt(T2);

    if (Nsmaller>0) {
        isSmaller = false;
        i = GetFirstIdx(T1);
        while (!isSmaller && i<=Nsmaller) {
            if (Elmt(T1,i)<Elmt(T2,i))
                isSmaller = true;
            else
                i++;
        }
        if (i>Nsmaller)
            isSmaller = (NbElmt(T1)<NbElmt(T2));
    } else
        isSmaller = false; /*Ketika Nsmaller=0*/

    return isSmaller;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
    if (NbElmt(T)!=0) {
        IdxType i=GetFirstIdx(T);
        while (i<GetLastIdx(T) && Elmt(T,i)!=X) {
            i++;
        }
        if (Elmt(T,i) == X)
            return i;
        else
            return IdxUndef;
    }
    else
        return IdxUndef;
}

IdxType Search2 (TabInt T, ElType X) ///60 65
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    boolean Found = false;
    IdxType i = GetFirstIdx(T);
    while (i<=GetLastIdx(T) && !Found) {
        if (Elmt(T,i) == X)
            Found = true;
        else
            i++;
    }
    if (!Found)
        i = IdxUndef;
    return i;
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
{
    return (Search2(T,X) != IdxUndef);
}

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C 
   yang tidak dipakai dalam definisi tabel */
{
    IdxType i = NbElmt(T);
    boolean isfound;
    /*Sentinel*/
    Elmt(T, 0) = X;
    while (Elmt(T,i) != X) {
        i--;
    }
    isfound = !(i==0);
    return isfound;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    IdxType i;
    ElType max = Elmt(T, GetFirstIdx(T));
    for (i=GetFirstIdx(T)+1; i<=GetLastIdx(T) ;i++) {
        if (Elmt(T,i)>max)
            max = Elmt(T,i);
    }
    return max;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
    IdxType i;
    ElType min = Elmt(T, GetFirstIdx(T));
    for (i=GetFirstIdx(T)+1; i<=GetLastIdx(T) ;i++) {
        if (Elmt(T,i)<min)
            min = Elmt(T,i);
    }
    return min;
}

IdxType IdxMaxTab (TabInt T) ///
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
    IdxType i, iValMax;
    ElType max = ValMax(T);
    iValMax == GetFirstIdx(T);
    for (i=GetFirstIdx(T)+1; i<=GetLastIdx(T); i++) {
        if (Elmt(T,i) == max) {
            iValMax = i;
        }
    }
    return iValMax;
}

IdxType IdxMinTab (TabInt T) ///
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
    IdxType i, iValMin;
    ElType min = ValMin(T);
    iValMin == GetFirstIdx(T);
    for (i=GetFirstIdx(T)+1; i<=GetLastIdx(T); i++) {
        if (Elmt(T,i) == min) {
            iValMin = i;
        }
    }
    return iValMin;
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout) ///
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
    IdxType i;
    Neff(*Tout) = NbElmt(Tin);
    for (i=GetFirstIdx(Tin); i<=GetLastIdx(Tin); i++) {
        Elmt(*Tout, i) = Elmt(Tin, i);
    }
}

TabInt InverseTab (TabInt T) ///
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
    IdxType i,j;
    TabInt Tinv;
    Neff(Tinv) = Neff(T);
    j = GetLastIdx(T);
    for (i=GetFirstIdx(Tinv); i<=GetLastIdx(Tinv); i++) {
        Elmt(Tinv, i) = Elmt(T, j);
        j--;
    }
    return Tinv;
}

boolean IsSimetris (TabInt T) ///91-95
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
    IdxType i = GetFirstIdx(T);
    IdxType j = GetLastIdx(T);
    boolean palindrom = true;
    if (NbElmt(T)>0) {
        while (palindrom && i<=GetLastIdx(T)) {
            if (Elmt(T,i) != Elmt(T,j))
                palindrom = false;
            else {
                i++;
                j--;
            }
        }
    }
    return palindrom;
}

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T) ///
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
    //Selection sort
    if (NbElmt(*T)>1) {
        int Pass, N;
        IdxType i, iMax;
        ElType temp;

        N=NbElmt(*T);
        for (Pass=GetFirstIdx(*T); Pass<=(N-1); Pass++) {
            iMax = Pass;
            for (i=Pass+1; i<=N; i++) {
                if (Elmt(*T,iMax) < Elmt(*T,i))
                    iMax = i;
                temp = Elmt(*T,iMax);
                Elmt(*T,iMax) = Elmt(*T,Pass);
                Elmt(*T,Pass) = temp;
            }
        }
    }

    /* Bubble Sort
    if (NbElmt(*T)>1) {
        int Pass, N;
        IdxType i;
        boolean isTukar = true;
        ElType temp;

        N = NbElmt(*T);
        Pass = GetFirstIdx(*T);
        while (Pass<=N-1 && isTukar) {
            isTukar = false;
            for (i = N; i>=Pass+1; i--) {
                if (Elmt(*T,i)>Elmt(*T,i-1)) {
                    temp = Elmt(*T, i);
                    Elmt(*T, i) = Elmt(*T, i-1);
                    Elmt(*T, i-1) = temp;
                    isTukar = true;
                }
            }
        }
    }*/
}

void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
    if (NbElmt(*T)>1) {
        int Pass; /*Pass = Jumlah langkah*/
        IdxType i;
        ElType temp;

        for (Pass=2; Pass<=NbElmt(*T); Pass++) {
            temp = Elmt(*T, Pass); /*Simpan harga T[Pass] sebelum pergeseran*/

            /* Sisipkan elemen ke Pass dalam T[1..Pass-1] sambil menggeser:*/
            i = Pass-1;
            while ((temp<Elmt(*T,i)) && (i>1)) {
                Elmt(*T,(i+1)) = Elmt(*T, i);
                i -= 1;
            }
            if (temp >= Elmt(*T, i))
                Elmt(*T, i+1) = temp;
            else {
                Elmt(*T, (i+1)) = Elmt(*T, i);
                Elmt(*T, i) = temp;
            }
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X) ///
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi TIDAK PENUH */
/* F.S. X adalah elemen terakhir T yang baru */
{
    Neff(*T) += 1;
    Elmt(*T, GetLastIdx(*T)) = X;
}

void AddEli (TabInt * T, ElType X, IdxType i) ///
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas 
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
    IdxType j;

    Neff(*T) += 1;
    for (j=GetLastIdx(*T); j>i; j--) {
        Elmt(*T, j) = Elmt(*T, j-1);
    }
    Elmt(*T, i) = X;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X) ///
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
    *X = Elmt(*T, GetLastIdx(*T));
    Neff(*T) -= 1;
}

void DelEli (TabInt * T, IdxType i, ElType * X) ///
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
    IdxType j;

    *X = Elmt(*T, i);
    for (j=i; j<GetLastIdx(*T); j++) {
        Elmt(*T, j) = Elmt(*T, j+1);
    }
    Neff(*T) -= 1;
}

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X) /// 115 117
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T, 
        jika belum ada elemen yang bernilai X. 
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S. 
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
    if (SearchB(*T,X))
        printf("nilai sudah ada\n");
    else {
        Neff(*T) += 1;
        Elmt(*T, GetLastIdx(*T)) = X;
    }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X) /// 118-122
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
    if (NbElmt(T)==0)
        return IdxUndef;
    else /*N!=0*/
    {
        IdxType i=GetFirstIdx(T);
        while ((i<GetLastIdx(T)) && (Elmt(T, i)<X)) {
            i++;
        }
        if (Elmt(T,i) == X)
            return i;
        else
            return IdxUndef;
    }
}

ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
    return Elmt(T, GetLastIdx(T));
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
    return Elmt(T, GetFirstIdx(T));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min) ///
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X) ///128-132
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
    if (!IsFull(*T)) {
        if (IsEmpty(*T))
            AddAsLastEl(T, X);
        else {
            IdxType i=GetFirstIdx(*T);
            while (Elmt(*T, i)<X && i<GetLastIdx(*T)) {
                i++;
            }
            AddEli(T, X, i);
        }
    }   
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
    IdxType idx;
    if (SearchB(*T, X)) {
        idx = Search1(*T, X);
        DelEli(T, idx, &X);
    }
}