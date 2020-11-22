/*��������ջģ��һ������*/
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct SimulationQuene {
	int stack1[N];
	int top1;
	int stack2[N];
	int top2;
};

/*ģ��ӵĳ�ʼ��*/
void InitSQ(SimulationQuene *SQ) {
	SQ->top1 = 0;
	SQ->top2 = 0;
 }

/*�ж�ģ���δ��*/
int SQIsNotFull(SimulationQuene* SQ) {
	if (SQ->top1 < N) return 1;
	else return 0;
}

/*�ж�ģ��ջ�ǿ�*/
int SQIsNotNull(SimulationQuene* SQ) {
	if (SQ->top1 == 0 && SQ->top2 == 0) return 0;
	else return 1;
}

/*Ԫ���ƶ���������ջ1��Ԫ���ƶ���ջ2*/
void SQMove(SimulationQuene* SQ) {
	for (int i = SQ->top1 - 1; i >= 0; i--) {
		SQ->stack2[SQ->top2++] = SQ->stack1[i];
		SQ->top1--;
	}
}

/*��Ӳ���*/
void SQPush(SimulationQuene* SQ, int x) {
	if (SQIsNotFull(SQ)){
		SQ->stack1[SQ->top1++] = x;
	}
	else {
		printf("����������");
	}
}

/*���Ӳ���*/
int SQPop(SimulationQuene* SQ) {
	if (SQ->top2 > 0) {
		int y = SQ->top2 - 1;
		int x = SQ->stack2[y];
		SQ->top2--;
		return x;
	}
	else if (SQ->top1>0) {
		SQMove(SQ);
		int y = SQ->top2 - 1;
		int x = SQ->stack2[y];
		SQ->top2 = SQ->top2 - 1;
		return x;
	}
	else {
		printf("����Ϊ��");
	}
}

void main(void) {
	int i;
	SimulationQuene SQ;
	InitSQ(&SQ);
	printf("ָ��������ܣ�1���һ���������2����һ��Ԫ�أ�0��ʾ��ֹ\n");
	do {
		printf("����ָ�");
		scanf_s("%d", &i);
		if (i == 1) {
			if (SQIsNotFull(&SQ)) {
				SQPush(&SQ, rand());
			}
			else {
				printf("������!\n");
			}
		}
		else if (i == 2) {
			if(SQIsNotNull(&SQ)){
				printf("����Ԫ��%d\n", SQPop(&SQ));
			}
			else {
				printf("��Ϊ��!\n");
			}
		}
	} while (i != 0);
}