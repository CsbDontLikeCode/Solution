/*利用输入的三个坐标点计算出三个点所围成的三角形的面积*/
#include <stdio.h>
#include <math.h>

typedef struct {
	double x;//x坐标
	double y;//y坐标
}Point;

double CalculateArea(Point* p) {
	double area;
	area = fabs((p[1].x - p[0].x) * (p[2].y - p[0].y) - (p[1].y - p[0].y) * (p[2].x - p[0].x)) / 2;
	return area;
}

void main(void) {
	Point p[3];
	for (int i = 0; i < 3; i++) {
		printf("输入第%d个点的x,y坐标:", i + 1);
		scanf_s("%lf %lf", &p[i].x, &p[i].y);
	}

	printf("AREA:%lf", CalculateArea(p));


}