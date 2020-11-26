/*******************/
/*	创建霍夫曼数   */
/*******************/
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Node {//霍夫曼树节点结构
	int weight;
	Node* lchild;
	Node* rchild;
};

void order(int* A, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (A[i] > A[j]) {
				int temp;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

void PreOrder(Node* p) {
	if (p != NULL) {
		printf("%d ", p->weight);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void main(void) {
	int A[N];
	printf("依次输入十个数字:");
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	order(A, N);
	Node* head;
	head = (Node*)malloc(sizeof(Node));
	head->lchild = head->rchild = NULL;
	head->weight = A[0];

	for (int i = 1; i < N; i++) {
		Node* p, * q;
		p = (Node*)malloc(sizeof(Node));
		q = (Node*)malloc(sizeof(Node));
		q->lchild = q->rchild = NULL;
		q->weight = A[i];
		p->lchild = q;
		p->rchild = head;
		p->weight = head->weight + q->weight;
		head = p;
	}
	PreOrder(head);
}