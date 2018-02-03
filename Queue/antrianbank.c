#include "queue.h"
#include <stdio.h>

float AvgElmt (Queue Q);
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */

int main() {
	Queue Q;
	infotype X;
	int n, pil;

	scanf("%d", &n);
	CreateEmpty(&Q, n);

	do {
		scanf("%d", &pil);
		if (pil == 1) {
			scanf("%d", &X);
			if (!IsFull(Q)) {
				Add(&Q, X);
			}
			else {
				printf("Queue penuh\n");
			}
		} else if (pil == 2) {
			if (!IsEmpty(Q)) {
				Del(&Q, &X);
			}
			else
				printf("Queue kosong\n");
		}
	} while (pil != 0);

	printf("%d\n", NBElmt(Q));
	if (!IsEmpty(Q)) {
		printf("%.2f\n", AvgElmt(Q));
	}
	else
		printf("Tidak bisa dihitung\n");

	DeAlokasi(&Q);
	return 0;
}

float AvgElmt (Queue Q)
{
	float sum = 0;
	int N = NBElmt(Q);
	infotype X;

	while (!IsEmpty(Q)) {
		Del(&Q,&X);
		sum = sum + X;
	}

	return sum/N;
}