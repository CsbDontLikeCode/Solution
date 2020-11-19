#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
	int date;//数据域
	btnode* lchild, * rchild;//指针域
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
	printf("按中序输入二叉树节点数字:");
	btnode* BTree;
	BTree = CreateBinaryTree();
	Preorder(BTree);
	return 0;
}