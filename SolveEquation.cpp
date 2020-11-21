/*分别使用二分法和牛顿法求解：
方程 2*x^3-(4*x^2)+3*x-6 在(-10,10)之间的根*/
#include <stdio.h>
#include <math.h>

double function(double x) {
	return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}

double derivation(double x) {
	return 6 * x * x - 8 * x + 3;
}

void main(void) {
	//二分法
	double x1 = -10, x2 = 10, x0;
	while (fabs(x1-x2) >= 1e-6) {
		x0 = (x1 + x2) / 2;
		if (function(x0)==0)break;
		if (function(x1) * function(x0) <= 0) {
			x2 = x0;
		}
		else x1 = x0;
	}
	printf("根的值为:%lf\n", x0);

	//牛顿法
	double x, x3, f, f1;
	x = 10;
	do {
		x3 = x;
		f = function(x3);
		f1 = derivation(x3);
		x = x3 - (f / f1);
	} while (fabs(x - x3) >= 1e-5);
	printf("根的值为:%lf", x);
}