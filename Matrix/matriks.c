/* 
	Nama: Erma Safira Nurmasyita
	NIM: 13516072
	Tanggal: 13 September 2017
*/
/* ********** Realisasi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return (i>=BrsMin && i<=BrsMax && j>=KolMin && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return (NBrsEff(M)-GetFirstIdxBrs(M)+1);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return (NKolEff(M)-GetFirstIdxKol(M)+1);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return ((i>=GetFirstIdxBrs(M)) && (i<=GetLastIdxBrs(M)) && (j>=GetFirstIdxKol(M)) && (j<=GetLastIdxKol(M)));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	indeks i, j;

	MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
	for (i=GetFirstIdxBrs(MIn); i<=GetLastIdxBrs(MIn); i++) {
		for (j=GetFirstIdxKol(MIn); j<=GetLastIdxKol(MIn); j++) {
			Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
	indeks i, j;
	ElType el;

	MakeMATRIKS(NB, NK, M);
	for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++) {
		for (j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++) {
			scanf("%d", &el);
			Elmt(*M, i, j) = el;
		}
	}
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	indeks i, j;

	for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++) {
		for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
			printf("%d", Elmt(M, i, j));
			if (j!=GetLastIdxKol(M))
				printf(" ");
		}
		if (i!=GetLastIdxBrs(M))
			printf("\n");
	}
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{
	MATRIKS MHsl;
	indeks i, j;

	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);
	for (i=GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1); i++) {
		for (j=GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++) {
			Elmt(MHsl, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
		}
	}

	return MHsl;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{
	MATRIKS MHsl;
	indeks i, j;

	MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &MHsl);
	for (i=GetFirstIdxBrs(M1); i<=GetLastIdxBrs(M1); i++) {
		for (j=GetFirstIdxKol(M1); j<=GetLastIdxKol(M1); j++) {
			Elmt(MHsl, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
		}
	}

	return MHsl;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
	MATRIKS MHsl;
	indeks i, j, k;
	int sumKali;
	//under construction
	MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &MHsl);
	for (i=GetFirstIdxBrs(MHsl); i<=GetLastIdxBrs(MHsl); i++) {
		for (j=GetFirstIdxKol(MHsl); j<=GetLastIdxKol(MHsl); j++) {
			sumKali = 0;
			for (k=GetFirstIdxKol(M1); k<=GetLastIdxKol(M1); k++) {
				sumKali += Elmt(M1, i, k) * Elmt(M2, k, j);
			}
			Elmt(MHsl, i, j) = sumKali;
		}
	}

	return MHsl;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
	MATRIKS MHsl;
	indeks i, j;

	MakeMATRIKS(NBrsEff(M), NKolEff(M), &MHsl);
	for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++) {
		for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
			Elmt(MHsl, i, j) = X * Elmt(M, i, j);
		}
	}

	return MHsl;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
	*M = KaliKons(*M, K);
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	if (EQSize(M1,M2)) {
		indeks i, j;
		boolean bEQ = true;

		i=GetFirstIdxBrs(M1); 
		while (i<=GetLastIdxBrs(M1) && bEQ) {
			j=GetFirstIdxKol(M1); 
			while (j<=GetLastIdxKol(M1) && bEQ) {
				bEQ = (Elmt(M1, i, j) == Elmt(M2, i, j));
				j++;
			}
			i++;
		}

		return bEQ;
	} else
		return false;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return (!EQ(M1, M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan NKolEff (M1) = NKolEff (M2) */
{
	return (GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetFirstIdxKol(M1) == GetFirstIdxKol(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	return (NBrsEff(M) == NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	if (IsBujurSangkar(M)) {
		indeks i, j;
		boolean bSimetris = true;

		i=GetFirstIdxBrs(M); 
		while (i<=GetLastIdxBrs(M) && bSimetris) {
			j=GetFirstIdxKol(M); 
			while (j<=GetLastIdxKol(M) && bSimetris) {
				bSimetris = (Elmt(M, i, j) == Elmt(M, j, i));
				j++;
			}
			i++;
		}

		return bSimetris;
	} else
		return false;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{
	if (IsBujurSangkar(M)) {
		indeks i, j;
		boolean bSatuan = true;

		i=GetFirstIdxBrs(M); 
		while (i<=GetLastIdxBrs(M) && bSatuan) {
			j=GetFirstIdxKol(M); 
			while (j<=GetLastIdxKol(M) && bSatuan) {
				if (i==j)
					bSatuan = (Elmt(M, i, j)==1);
				else
					bSatuan = (Elmt(M, i, j)==0);
				j++;
			}
			i++;
		}

		return bSatuan;
	} else
		return false;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{
	indeks i, j;
	boolean bSparse = true;
	int limit, count = 0;

	limit = NBElmt(M)*0.05;
	i=GetFirstIdxBrs(M);
	while (i<=GetLastIdxBrs(M) && bSparse) {
		j=GetFirstIdxKol(M); 
		while (j<=GetLastIdxKol(M) && bSparse) {
			if (Elmt(M, i, j) != 0)
				count += 1;
			bSparse = (count <= limit);
			j++;
		}
		i++;
	}

	return bSparse;
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
	return (KaliKons(M, (-1)));
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
	indeks i=GetFirstIdxBrs(M);
	indeks j=GetFirstIdxKol(M);
	float sumDeterminan=0;

	if (NBElmt(M) == 1)
		sumDeterminan += Elmt(M, i, j);
	else if (NBElmt(M) == 4)
		sumDeterminan += (Elmt(M, i, j)*Elmt(M, i+1, j+1) - Elmt(M, i, j+1)*Elmt(M, i+1, j));
	else {
		MATRIKS Minor;
		indeks a, b, x, y;
		int c;

		MakeMATRIKS(NBrsEff(M)-1, NKolEff(M)-1, &Minor);
		i=GetFirstIdxBrs(M);
		for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++) {
			x=GetFirstIdxBrs(Minor);
			for (a=GetFirstIdxBrs(M); a<=GetLastIdxBrs(M); a++) {
				y = GetFirstIdxKol(Minor);
				for (b=GetFirstIdxKol(M); b<=GetLastIdxKol(M); b++) {
					if ((a != i) && (b != j)) {
						Elmt(Minor, x, y) = Elmt(M, a, b);
						y++;
					}
				}
				if (a != i) x++;
			}

			if ((i+j)%2 == 0)
				c = 1;
			else
				c = -1;

			sumDeterminan += c*Elmt(M, i, j)*Determinan(Minor);
		}
	}

	return sumDeterminan;
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
	MATRIKS M1;

	CopyMATRIKS(*M, &M1);
	M1 = Inverse1(*M);
	*M = M1;
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	indeks i, j;
	ElType temp;

	for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++) {
		for (j=i; j<=GetLastIdxKol(*M); j++) {
			temp = Elmt(*M, i, j);
			Elmt(*M, i, j) = Elmt(*M, j, i);
			Elmt(*M, j, i) = temp;
		}
	}
}