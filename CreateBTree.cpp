#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
	int date;//������
	btnode* lchild, * rchild;//ָ����
}btnode;

btnode* CreateBinaryTree() {
	int a;
	scanf("%d", &a);
	btnode* p = NULL;
	if (a != 0) {
		p = (btnode*)malloc(sizeof(btnode));
		p->date = a;
		p->lchild = CreateBinaryTree();
		p->rchild = CreateBinaryTree();
	}
	return p;
}

void Preorder(btnode* p) {
	if (p != NULL) {
		printf("%d", p->date);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

int main(void) {
	printf("����������������ڵ�����:");
	btnode* BTree;
	BTree = CreateBinaryTree();
	Preorder(BTree);
	return 0;
}