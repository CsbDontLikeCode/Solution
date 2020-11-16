#include <stdio.h>

#define N 1000

void main(void) {
	int m, n;//相乘的两个数
	int a[N] = { 0 };//存放结果的数组
	int num = 0, digit = -1, j = 0;//num存放每次相乘的结果 digit存放最终结果的位数 j用于循环

	printf("输入两个整型数字:");
	scanf_s("%d %d", &m, &n);

	for (int i = 0; m != 0; i++) {
		a[i] = m % 10;
		m /= 10;
		digit++;
	}

	for (j = 0; j <= digit; j++) {
		num = num + a[j] * n;
		a[j] = num % 10;
		num /= 10;
	}

	while (num != 0) {
		a[++digit] = num % 10;
		num /= 10;
	}

	printf("相乘结果为:");
	for (int i = digit; i >= 0; i--) {
		printf("%d", a[i]);
	}
}