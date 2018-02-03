/* File: point_driver.c */
/* Tanggal: 30 Agustus 2016 */
/* *** Driver ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include <stdio.h>

int main () {
	POINT P1, P2;
	float deg; //sudut putar
	float deltaX, deltaY;

	printf("-Driver POINT-\n");
	printf("Bikin point P1\n");
	BacaPOINT(&P1);
	printf("Terbentuk P1: ");
	TulisPOINT(P1);
	printf("\n");
	BacaPOINT(&P2);
	printf("Terbentuk P2: ");
	TulisPOINT(P2);

	printf("\n\nP1 di titik origin? ");
	if (IsOrigin(P1)) {
		printf("YA\n");
		printf("Gapunya kuadran :(\n");
	}
	else {
		printf("TIDAK\n");
		if (!(IsOnSbX(P1) || IsOnSbY(P1))) {
			printf("P1 ada di kuadran %d\n", Kuadran(P1));
		}
	} 

	printf("\nGeser P2\n");
	printf("Delta x: ");
	scanf("%f", &deltaX);
	printf("Delta y: ");
	scanf("%f", &deltaY);
	Geser(&P2, deltaX, deltaY);
	TulisPOINT(P2);
	printf(" <- P2 setelah digeser\n");
	printf("\n- NextX = ");
	TulisPOINT(NextX(P2));
	printf("\n- NextY = ");
	TulisPOINT(NextY(P2));

	printf("\n\nJarak P2 ke 0,0 = %f\n\n", Jarak0(P2));

	if (NEQ(P1,P2)) {
		printf("sekarang ini P1 dan P2 tidak sama\n");
	} else
		printf("sekarang ini P1 dan P2 sama\n");
	printf("Panjang P1-P2: %.2f\n\n", Panjang(P1,P2));

	printf("Rotasi P1\n");
	printf("Masukkan sudut = ");
	scanf("%f", &deg);
	Putar(&P1, deg);
	TulisPOINT(P1);

	printf("\nGeser P1 ke SbX > ");
	GeserKeSbX(&P1);
	TulisPOINT(P1);

	printf("\nGeser P2 ke SbY -> ");
	GeserKeSbY(&P2);
	TulisPOINT(P2);

	printf("\n\nCerminan P1 \n");
	Mirror(&P1, IsOnSbY(P1));
	printf(" - Dicerminkan - \n");
	printf(".. sekarang P1 = ");
	TulisPOINT(P1);

	printf("\nCerminan P2 \n");
	printf(" - Dicerminkan - \n");
	printf(".. kalo dicerminkan, P2 = ");
	TulisPOINT(MirrorOf(P2, IsOnSbY(P2)));

	return 0;
}