/*统计英语单词数量
统计方法是 统计字符串中空格的数量再加一*/
#include <stdio.h>

#define N 5000

void main(void) {
	char s[N];
	int count=0;//count用于统计空格数量
	
	printf("请输入英语文章:");
	int i = 0;
	
	char ch;
	ch = getchar();
	while (ch != '\n') {
		s[i++] = ch;
		ch = getchar();
	}



	for (int j = 0; s[j] !='\0'; j++) {
		if (s[j] == ' ') count++;
	}

	printf("单词数量为%d", count + 1);
}