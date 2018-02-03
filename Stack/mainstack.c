#include "stackt.h"
#include "mesintoken.h"
#include <stdio.h>

int main() {
	Stack S;
	boolean isError = false;
	infotype a, b, hsl;
	int Tab[20];
	char Op[20]; 
	int i = 0;
	int j =0;
	int NeffTab, NeffOp;

	CreateEmpty(&S);
	/*Baca File*/
	STARTTOKEN();
	while (!EndToken && !isError) {
		if (CToken.tkn == 'b') {
			Push(&S, CToken.val);
			Tab[i] = CToken.val;
			i++;
		} else {
			if (IsEmpty(S)) {
				isError = true;
			} else {
				Pop(&S, &a);
				if (IsEmpty(S))
					isError = true;
				else {
					Pop(&S, &b);
					Op[j] = CToken.tkn;
					j++;
					switch(CToken.tkn) {
				      case '*' :
				         hsl = a*b;
				         break;
				      case '/' :
				      	 hsl = a/b;
				      	 break;
				      case '+' :
				         hsl = a+b;
				         break;
				      default :
				         hsl = a-b;
				   }
				   Push(&S, hsl);
				}
			}
		}
		ADVTOKEN();
	}

		NeffTab = i-1;
		NeffOp = j-1;

	if (isError || NeffTab != NeffOp+1)
		printf("Error\n");
	else {
		Pop(&S, &hsl);
		i = 0;
		while (i<=NeffTab) {
			printf("%d ", Tab[i]);
			if (i<=NeffOp)
				printf("%c ", Op[i]);
			i++;
		}
		printf("= %d\n", hsl);
	}
	return 0;
}