#include <stdio.h>

#define N 1000

void main(void) {
	int m, n;//��˵�������
	int a[N] = { 0 };//��Ž��������
	int num = 0, digit = -1, j = 0;//num���ÿ����˵Ľ�� digit������ս����λ�� j����ѭ��

	printf("����������������:");
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

	printf("��˽��Ϊ:");
	for (int i = digit; i >= 0; i--) {
		printf("%d", a[i]);
	}
}