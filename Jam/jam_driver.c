/* File: jam_driver.c */
/* Tanggal: 31 Agustus 2016 */
/* Driver ADT JAM */

#include "jam.h"
#include <stdio.h>

int main() {
   JAM J1, J2;
   int n;

   printf("-DRIVER JAM-\nBaca Jam awal\n");
   BacaJAM(&J1);
   printf("Baca jam akhir\n");
   BacaJAM(&J2);

   printf("Jam Awal >> ");
   TulisJAM(J1);
   printf(" - Jam Akhir >> ");
   TulisJAM(J2);
   if (JLT(J1,J2))
      printf("\n** Jam awal lebih kecil dari jam akhir\n");
   if (JGT(J1,J2))
      printf("\n** Jam awal lebih besar dari jam akhir\n");

   printf("\nJam awal dan akhir ");
   if (JEQ(J1,J2))
      printf("sama\n");
   if (JNEQ(J1,J2))
      printf("tidak sama\n");
   printf("\nMaka selisih detik adalah: %ld, alias (j:m:d) ", Durasi(J1,J2));
   TulisJAM(DetikToJAM(Durasi(J1,J2)));

   printf("\n\n Operasi jam\n");
   printf("1 detik sebelum J1 = ");
   TulisJAM(PrevDetik(J1));
   printf("\n1 detik setelah J1 = ");
   TulisJAM(NextDetik(J1));

   printf("\n\nMau maju berapa detik? ");
   scanf("%d", &n);
   printf("Maju %d detik dari J1 >> ", n);
   TulisJAM(NextNDetik(J1,n));
   printf("\n\nMau mundur berapa detik? ");
   scanf("%d", &n);
   printf("Mundur %d detik dari J1 >> ", n);
   TulisJAM(PrevNDetik(J1, n));
   return 0;
}