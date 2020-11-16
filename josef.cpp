#include <stdio.h>

#define N 10
#define M 5

void main(void) {
	int a[N] = { 1,2,3,4,5,6,7,8,9,10 };
	int mark = -1, count = N;
	int n = M % N;
	while (count >= 1) {
		for (int i = 0; i < n; i++) {
			while (a[(mark+1)%N] == 0) {
				mark = (mark + 1) % N;
			}
			mark = (mark + 1) % N;
		}
		printf("%d ", a[mark]);
		a[mark] = 0;
		count--;
	}

}