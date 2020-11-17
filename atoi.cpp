/*实现函数atoi 将字符串转为整数*/
#include <stdio.h>

int atoi(char* string);

void main(void) {
	char string[] = "+456";
	int n = atoi(string);
	printf("字符串的整数形式为%d", n);
}

int atoi(char* string) {
	int sum = 0, sign = 1, i = 0;
	if (string == NULL) {
		return 0;
	}

	if (string[0] == '-') sign = -1;

	if (string[0] == '-' || string[0] == '+') {
		i++;
	}
	while (string[i] > '0' && string[i] < '9') {
		sum = sum * 10 + (string[i++] - '0');
	}

	return sum*sign;
}