#include <stdio.h>

int chess[8][8] = { 0 };

int check(int row, int col) {
	for (int i = row - 1; i >= 0; i--) {
		if (chess[i][col] == 1) return 0;
		if (((col + row - i) < 8 && chess[i][col + row - i] == 1) || ((col - row + i) >= 0 && chess[i][col - row + i] == 1)) return 0;
	}
	return 1;
}

void main(void) {
	int count = 0;
	for (int a = 0; a < 8; a++) {
		chess[0][a] = 1;
		for (int b = 0; b < 8; b++) {
			if (check(1, b)) chess[1][b] = 1;
			else continue;
			for (int c = 0; c < 8; c++) {
				if (check(2, c)) chess[2][c] = 1;
				else continue;
				for (int d = 0; d < 8; d++) {
					if (check(3, d)) chess[3][d] = 1;
					else continue;
					for (int e = 0; e < 8; e++) {
						if (check(4, e)) chess[4][e] = 1;
						else continue;
						for (int f = 0; f < 8; f++) {
							if (check(5, f)) chess[5][f] = 1;
							else continue;
							for (int g = 0; g < 8; g++) {
								if (check(6, g)) chess[6][g] = 1;
								else continue;
								for (int h = 0; h < 8; h++) {
									if (check(7, h)) {
										printf("(1,%d)(2,%d)(3,%d),(4,%d),(5,%d),(6,%d),(7,%d),(8,%d)\n", a+1, b+1, c+1, d+1, e+1, f+1, g+1, h+1);
										count++;
									}
									else continue;
								}
								chess[6][g] = 0;
							}
							chess[5][f] = 0;
						}
						chess[4][e] = 0;
					}
					chess[3][d] = 0;
				}
				chess[2][c] = 0;
			}
			chess[1][b] = 0;
		}
		chess[0][a] = 0;
	}
	printf("总共有%d种", count);
}