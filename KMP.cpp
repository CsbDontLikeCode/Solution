#include <stdio.h>

void get_next(char* s, int* next) {
	int len = 1;
	while(s[len] != '\0') {
		len++;
	}
	printf("s2³¤¶ÈÎª%d   ",len);

	next[1] = 0;
	next[2] = 1;
	for (int i = 3; i <= len; i++) {
		for (int j = i - 2; j >= 1; j--) {
			int a = 1, b = i - j;
			while (b <= i) {
				if (s[a] == s[b]) {
					a++;
					b++;
				}
				else {
					next[i] = 1;
					break;
				}
				if (b == i) {
					next[i] = a;
					break;
				}
			}
			if (next[i] != 1)break;
		}
	}
}

void main (void){
	char s1[10] = {"#aaaabad"};
	int next[10] = {0};
	get_next(s1, next);
	for (int i = 1; i < 8; i++) {
		printf("%d ", next[i]);
	}
}