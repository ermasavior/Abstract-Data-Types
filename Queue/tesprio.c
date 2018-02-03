#include "prioqueue.h"
#include <stdio.h>

int main() {
	Queue Q;
	infotype X;
	int A, B;
	int idx = 1;
	int head = 1;
	int count = 0;

	for (int i=1; i<=100; i++) {
		idx = (head+count-1)%5+1;
		count++;
		if (i%2==0) {
			head = head%5+1;
			count--;
		}
		printf("%d-%d  ", idx, count);
	}
	/*CreateEmpty(&Q, 5);
	for (int i=1; i<=2; i++) {
		scanf("%d", &A);
		scanf("%d", &B);
		X.prio = A;
		X.info = B;
		Add(&Q, X);
	}
	
	PrintQueue(Q);
	DeAlokasi(&Q);*/
	return 0;
}