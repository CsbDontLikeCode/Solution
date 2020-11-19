/*一棵具有N个节点的完全二叉树以顺序方式存储在数组A中
  以下算法构造该二叉树的链式存储结构*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct btnode {
	int date;//数据域
	btnode* lchild, * rchild;//指针域
}btnode;

btnode* CreateCompleteBTree(int *A,int i,int n) {
	btnode* p = NULL;
	if (i < n) {
		p = (btnode*)malloc(sizeof(btnode));
		p->date = A[i];
		p->lchild = CreateCompleteBTree(A, 2 * i + 1, n);
		p->rchild = CreateCompleteBTree(A, 2 * i + 2, n);
	}
	return p;
}

void Preorder(btnode* p) {
	if (p != NULL) {
		printf("%d ", p->date);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void main(void) {
	int A[N] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("数组长度为%d,", N);
	printf("数组元素为：");
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	btnode* p;
	p = CreateCompleteBTree(A, 0, N);
	Preorder(p);
}