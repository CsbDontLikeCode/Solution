/*���һ������ջ*/
#include <stdio.h>
#include <stdlib.h>

#define N 20 //����ջ��С

typedef struct ShareStack {
	int a[N];
	int share1top;
	int share2top;
};

/*����ջ�ĳ�ʼ��*/
void InitShareStack(ShareStack* S) {
	S->share1top = 0;
	S->share2top = N-1;
}

/*�ж�ջ��,ջ������0����������1*/
int ShareStackIsNotFull(ShareStack* S){
	if (S->share1top > S->share2top) return 0;
	else if (S->share1top <= S->share2top) return 1;
}

/*�ж�ջ��*/
int ShareStackIsNull(ShareStack* S, int flag) {
	if (flag == 1) {
		if (S->share1top == 0) return 1;
		else return 0;
	}
	else if (flag == 2) {
		if (S->share2top == N-1) return 1;
		else return 0;
	}
	else {
		printf("�������");
	}
}

/*����ջ�Ľ�ջ����*/
void ShareStackPush(ShareStack* S, int num, int flag) {
	if (flag == 1) {
		if (ShareStackIsNotFull(S)) {
			S->a[S->share1top] = num;
			S->share1top++;
		}
		else {
			printf("ջ����");
		}
		
	}
	else if (flag == 2) {
		if (ShareStackIsNotFull(S)) {
			S->a[S->share2top] = num;
			S->share2top--;
		}
		else {
			printf("ջ����");
		}
	}
	else{
		printf("�������");
	}
}

int ShareStackPop(ShareStack* S, int flag) {
	if (flag == 1) {
		if (ShareStackIsNull(S, 1)) {
			printf("ջ�գ���Ԫ�س�ջ��");
		}
		else {
			return S->a[--S->share1top];
		}	
	}
	else if (flag == 2) {
		if (ShareStackIsNull(S, 2)) {
			printf("ջ�գ���Ԫ�س�ջ��");
		}
		else {
			return S->a[++S->share2top];
		}
	}
}

void main(void) {
	ShareStack S;
	InitShareStack(&S);
	int r;//�����1,2
	int i;
	while (ShareStackIsNotFull(&S)) {
		r = rand() % 2 + 1;//���������r,�����ﵽ����ջ������������Ŀ��
		printf("��������ջԪ�أ�");
		scanf_s("%d", &i);
		ShareStackPush(&S, i, r);
	}
	printf("����ջ1Ԫ�������");
	while (!ShareStackIsNull(&S,1)) {
		int j = ShareStackPop(&S, 1);
		printf("%d ", j);
	}
	printf("\n����ջ2Ԫ�������");
	while (!ShareStackIsNull(&S,2)) {
		int j = ShareStackPop(&S, 2);
		printf("%d ", j);
	}
}