/*ͳ��Ӣ�ﵥ������
ͳ�Ʒ����� ͳ���ַ����пո�������ټ�һ*/
#include <stdio.h>

#define N 5000

void main(void) {
	char s[N];
	int count=0;//count����ͳ�ƿո�����
	
	printf("������Ӣ������:");
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

	printf("��������Ϊ%d", count + 1);
}