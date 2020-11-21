/*设计一个共享栈*/
#include <stdio.h>
#include <stdlib.h>

#define N 20 //共享栈大小

typedef struct ShareStack {
	int a[N];
	int share1top;
	int share2top;
};

/*共享栈的初始化*/
void InitShareStack(ShareStack* S) {
	S->share1top = 0;
	S->share2top = N-1;
}

/*判断栈满,栈满返回0，不满返回1*/
int ShareStackIsNotFull(ShareStack* S){
	if (S->share1top > S->share2top) return 0;
	else if (S->share1top <= S->share2top) return 1;
}

/*判断栈空*/
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
		printf("输入错误！");
	}
}

/*共享栈的进栈操作*/
void ShareStackPush(ShareStack* S, int num, int flag) {
	if (flag == 1) {
		if (ShareStackIsNotFull(S)) {
			S->a[S->share1top] = num;
			S->share1top++;
		}
		else {
			printf("栈满！");
		}
		
	}
	else if (flag == 2) {
		if (ShareStackIsNotFull(S)) {
			S->a[S->share2top] = num;
			S->share2top--;
		}
		else {
			printf("栈满！");
		}
	}
	else{
		printf("输入错误！");
	}
}

int ShareStackPop(ShareStack* S, int flag) {
	if (flag == 1) {
		if (ShareStackIsNull(S, 1)) {
			printf("栈空！无元素出栈！");
		}
		else {
			return S->a[--S->share1top];
		}	
	}
	else if (flag == 2) {
		if (ShareStackIsNull(S, 2)) {
			printf("栈空！无元素出栈！");
		}
		else {
			return S->a[++S->share2top];
		}
	}
}

void main(void) {
	ShareStack S;
	InitShareStack(&S);
	int r;//随机数1,2
	int i;
	while (ShareStackIsNotFull(&S)) {
		r = rand() % 2 + 1;//生成随机数r,进而达到共享栈两端随机插入的目的
		printf("请输入入栈元素：");
		scanf_s("%d", &i);
		ShareStackPush(&S, i, r);
	}
	printf("共享栈1元素输出：");
	while (!ShareStackIsNull(&S,1)) {
		int j = ShareStackPop(&S, 1);
		printf("%d ", j);
	}
	printf("\n共享栈2元素输出：");
	while (!ShareStackIsNull(&S,2)) {
		int j = ShareStackPop(&S, 2);
		printf("%d ", j);
	}
}