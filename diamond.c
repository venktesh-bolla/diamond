#include <stdio.h>

void diamond(int size)
{
	int i, j;
	int nstar = 1, val = 0;
	int condi, m = 1, k, lower = 0;

	for (i=0; i<size; i++) {
		k = 0;
		if (nstar > size) {
			lower = 1;
			nstar -= 4;
		}
		if (lower)
			val = val+2;
		for (j=0; j<size; j++) {
			if (lower) {
				m = -1;
				condi = ((i-val+j) < (size/2));
			} else {
				m = 1;
				condi = ((i+j) < (size/2));
			}
			if ((k >= nstar))
#if 0
				break;
#else
				condi = 1;
#endif
			if (condi)
				printf(" X ");
			else {
				printf(" * ");
				k++;
			}
		}
		printf("\n");
		nstar = nstar + m*2;
	}

	return;
}

int main(void)
{
	int s;
	while (1) {
		printf("Enter the size of diamond: ");
		scanf("%d", &s);
		if (s & 1ull)
			diamond(s);
	}
	return 0;
}
