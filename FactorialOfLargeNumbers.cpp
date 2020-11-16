#include <stdio.h>

#define N 1000

void main(void) {
	int a[N] = { 0 };
	a[0] = 1;
	int digit = 0,n;

	printf("输入数字:");
	scanf_s("%d", &n);

	for (int i = 2; i <= n; i++) {
		int num = 0;
		for (int j = 0; j <= digit; j++) {
			num = num + a[j] * i;
			a[j] = num % 10;
			num /= 10;
		}
		while (num) {
			a[++digit] = num % 10;
			num /= 10;
		}
	}

	for (int i = digit; i >= 0; i--) {
		printf("%d", a[i]);
	}
	printf("\n%d位数", digit);
}