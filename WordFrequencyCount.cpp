/*ͳ��Ӣ�����µĵ��ʴ�Ƶ��
���ֵ��ʴ�Сд������She��she�ᱻ�ж�Ϊ��������
�����ʽ��Ӣ�������ԡ�#����β����*/
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

	printf("����Ӣ������:\n");

	int x = 0;//xͳ�����³���
	char ch = getchar();
	while (ch != '#') {
		a[x++] = ch;
		ch = getchar();
	}

	int m = 0;//m��¼w�д�ŵ��ʵĸ���

	for (int i = 0; i < x; i++) {
		char s[20];//s�洢��������
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