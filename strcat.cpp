/*���ڶ����ַ���ƴ�ӵ���һ���ַ�����ĩβ*/
#include <stdio.h>

char* strcat(char* s1, char* s2) {
	if (s1 == NULL || s2 == NULL) return NULL;
	while (*s1 != '\0')s1++;
	while ((*s1++ = *s2++) != '\0');
	return s1;
}

void main(void) {
	char s1[20] = "Hello,";
	char s2[10] = "World!";

	strcat(s1, s2);
	printf("%s", s1);
}