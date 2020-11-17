/*统计英语文章的单词词频。
区分单词大小写，例如She跟she会被判定为两个单词
输入格式：英语文章以‘#’结尾即可*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

#define N 10000

typedef struct {
	char ss[100];
	int count;
}Word;

Word w[1000];

void main(void) {
	char a[N];

	printf("输入英语文章:\n");

	int x = 0;//x统计文章长度
	char ch = getchar();
	while (ch != '#') {
		a[x++] = ch;
		ch = getchar();
	}

	int m = 0;//m记录w中存放单词的个数

	for (int i = 0; i < x; i++) {
		char s[20];//s存储单个单词
		int j = 0;
		while ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
			s[j++] = a[i++];
		}
		s[j] = '\0';
		if (s[0]) {
			int k=0;
			for (k = 0; k < m; k++) {
				if (!strcmp(w[k].ss, s)) {
					w[k].count++;
					break;
				}
			}
			if (k == m) {
				strcpy(w[m].ss, s);
				w[m++].count = 1;
			}
		}
	}

	for (int k = 0; k < m; k++) {
		printf("%s %d\n", w[k].ss, w[k].count);
	}
}