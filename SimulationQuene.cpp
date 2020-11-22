/*利用两个栈模拟一个队列*/
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct SimulationQuene {
	int stack1[N];
	int top1;
	int stack2[N];
	int top2;
};

/*模拟队的初始化*/
void InitSQ(SimulationQuene *SQ) {
	SQ->top1 = 0;
	SQ->top2 = 0;
 }

/*判断模拟队未满*/
int SQIsNotFull(SimulationQuene* SQ) {
	if (SQ->top1 < N) return 1;
	else return 0;
}

/*判断模拟栈非空*/
int SQIsNotNull(SimulationQuene* SQ) {
	if (SQ->top1 == 0 && SQ->top2 == 0) return 0;
	else return 1;
}

/*元素移动函数，将栈1的元素移动至栈2*/
void SQMove(SimulationQuene* SQ) {
	for (int i = SQ->top1 - 1; i >= 0; i--) {
		SQ->stack2[SQ->top2++] = SQ->stack1[i];
		SQ->top1--;
	}
}

/*入队操作*/
void SQPush(SimulationQuene* SQ, int x) {
	if (SQIsNotFull(SQ)){
		SQ->stack1[SQ->top1++] = x;
	}
	else {
		printf("队列已满！");
	}
}

/*出队操作*/
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
		printf("队列为空");
	}
}

void main(void) {
	int i;
	SimulationQuene SQ;
	InitSQ(&SQ);
	printf("指令操作介绍：1入队一个随机数，2出队一个元素，0表示终止\n");
	do {
		printf("输入指令：");
		scanf_s("%d", &i);
		if (i == 1) {
			if (SQIsNotFull(&SQ)) {
				SQPush(&SQ, rand());
			}
			else {
				printf("队已满!\n");
			}
		}
		else if (i == 2) {
			if(SQIsNotNull(&SQ)){
				printf("出队元素%d\n", SQPop(&SQ));
			}
			else {
				printf("队为空!\n");
			}
		}
	} while (i != 0);
}