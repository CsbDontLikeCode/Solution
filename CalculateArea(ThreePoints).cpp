/*������������������������������Χ�ɵ������ε����*/
#include <stdio.h>
#include <math.h>

typedef struct {
	double x;//x����
	double y;//y����
}Point;

double CalculateArea(Point* p) {
	double area;
	area = fabs((p[1].x - p[0].x) * (p[2].y - p[0].y) - (p[1].y - p[0].y) * (p[2].x - p[0].x)) / 2;
	return area;
}

void main(void) {
	Point p[3];
	for (int i = 0; i < 3; i++) {
		printf("�����%d�����x,y����:", i + 1);
		scanf_s("%lf %lf", &p[i].x, &p[i].y);
	}

	printf("AREA:%lf", CalculateArea(p));


}