/*ʵ�ִ�С��������*/
#include <stdio.h>

#define N 10

/*����swap���ڽ����������ֵ�λ��*/
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*���������*/
void AHeapSort(int* A, int n) {
	for (int i = n/2-1; i >= 0; i--) {
		int j = i;
		while (2 * j + 1 < n) {
			if (2 * j + 2 < n) {
				if (A[j] < (A[2 * j + 1] > A[2 * j + 2] ? A[2 * j + 1] : A[2 * j + 2])) {
					int k = A[2 * j + 1] > A[2 * j + 2] ? 1 : 2;
					swap(&A[j], &(A[2 * j + 1] > A[2 * j + 2] ? A[2 * j + 1] : A[2 * j + 2]));
					j = 2 * j + k;
				}
				else break;
			}
			else {
				if (A[j] < A[2 * j + 1]) {
					swap(&A[j], &A[2 * j + 1]);
					j = j * 2 + 1;
				}
				else break;
			}
		}
	}
	swap(&A[0], &A[n - 1]);
	if (n > 1) {
		AHeapSort(A, n - 1);
	}
}

/*С��������*/
void BHeapSort(int* A, int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		int j = i;
		while (2 * j + 1 < n) {
			if (2 * j + 2 < n) {
				if (A[j] > (A[2 * j + 1] < A[2 * j + 2] ? A[2 * j + 1] : A[2 * j + 2])) {
					int k = A[2 * j + 1] < A[2 * j + 2] ? 1 : 2;
					swap(&A[j], &(A[2 * j + 1] < A[2 * j + 2] ? A[2 * j + 1] : A[2 * j + 2]));
					j = 2 * j + k;
				}
				else break;
			}
			else {
				if (A[j] > A[2 * j + 1]) {
					swap(&A[j], &A[2 * j + 1]);
					j = j * 2 + 1;
				}
				else break;
			}
		}
	}
	swap(&A[0], &A[n - 1]);
	if (n > 1) {
		BHeapSort(A, n - 1);
	}
}

void main(void) {
	int A[N];//A�������ڴ��������
	int B[N];//B��������С��������
	printf("����%d������:", N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
		B[i] = A[i];//��A�����ֵ���Ƹ�B����
	}
	AHeapSort(A, N);
	BHeapSort(B, N);
	printf("����ѣ�");
	for (int i = 0; i <N ; i++) {
		printf("%d ", A[i]);
	}
	printf("\nС���ѣ�");
	for (int i = 0; i < N; i++) {
		printf("%d ", B[i]);
	}
}