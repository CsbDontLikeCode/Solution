#include <stdio.h>

#define N 5

void swap(char* a, char* b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void AllRange(char* A, int n, int i){
	if (i <= n) {
		for (int k = i - 1; k < n; k++) {
			swap(&A[i - 1], &A[k]);
			AllRange(A, n, i + 1);
			swap(&A[i - 1], &A[k]);
		}
	}
	else {
		for (int j = 0; j < n; j++) {
			printf("%c", A[j]);
		}
		printf("\n");
	}
}

void main(void) {
	char A[N];
	printf("��������е�%d���ַ�:",N);
	for (int i = 0; i < N; i++) {
		scanf_s("%c", &A[i]);
	}
	AllRange(A, N, 1);
}