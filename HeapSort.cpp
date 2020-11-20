/*实现大、小根堆排序*/
#include <stdio.h>

#define N 10

/*函数swap用于交换两个数字的位置*/
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*大根堆排序*/
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

/*小根堆排序*/
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
	int A[N];//A数组用于大根堆排序
	int B[N];//B数组用于小根堆排序
	printf("输入%d个整数:", N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
		B[i] = A[i];//将A数组的值复制给B数组
	}
	AHeapSort(A, N);
	BHeapSort(B, N);
	printf("大根堆：");
	for (int i = 0; i <N ; i++) {
		printf("%d ", A[i]);
	}
	printf("\n小根堆：");
	for (int i = 0; i < N; i++) {
		printf("%d ", B[i]);
	}
}