/*利用迭代对m个数的全排列*/
#include <stdio.h>

void main(void) {
	char a[4] = { 'a','b','c','d' };
	int b[4];

	for (int i = 0; i < 4; i++) {
		b[0] = i;
		for (int j = 0; j < 4; j++) {
			b[1] = j;
			if (b[1] != b[0]) {
				for (int k = 0; k < 4; k++) {
					b[2] = k;
					if (b[2] != b[0] && b[2] != b[1]) {
						for (int l = 0; l < 4; l++) {
							b[3] = l;
							if (b[3] != b[0] && b[3] != b[1] && b[3] != b[2]) {
								for (int m = 0; m < 4; m++) {
									int n = b[m];
									printf("%c", a[n]);
								}
								printf("\n");
							}
						}
					}
				}
			}
		}
	}
}
