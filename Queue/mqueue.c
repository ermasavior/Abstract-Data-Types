#include "queue.h"
#include <stdio.h>

int main() {
	Queue q;
	CreateEmpty(&q, 4);
	printf("%d\n", NBElmt(q));
	for (int i=1; i<=4; i++) {
		Add(&q, i);
		printf("%d ", i);
	}
	int x;
	printf("%d\n", InfoHead(q));
	Del(&q, &x);
	printf("%d\n", InfoHead(q));
	Del(&q, &x);
	printf("%d\n", InfoHead(q));
	Add(&q, 6);
	printf("%d\n", InfoTail(q));
	Add(&q, 7);
	printf("%d\n", InfoTail(q));
	printf("%d\n", InfoHead(q));
	printf("%d\n", NBElmt(q));
	Del(&q, &x);
	printf("%d\n", NBElmt(q));
	
	DeAlokasi(&q);
	return 0;
}