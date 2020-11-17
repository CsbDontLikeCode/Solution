/*实现函数itoa 实现整数向字符串转换*/
#include <stdio.h>

void itoa(int n, char* string);

void main(void) {
	char string[100];
	int n = -1234;
	itoa(n, string);
	printf("%s", string);
}

void itoa(int n, char* s) {
	int i = 0;//用于数组下标
	if (n < 0) {
		s[i++] = '-';
		n = n * (-1);
	}
	int count = 0, temp = n;
	while (temp > 0) {
		temp /= 10;
		count++;
	}
	for (int j = count + i - 1; j >= i; j--) {
		s[j] = '0' + (n % 10);
		n /= 10;
	}
	s[count+i] = '\0';
}