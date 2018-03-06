#include "PointList.h"

xPOINT inputPoint()
{
	xPOINT P;
	//P = (xPOINT*)malloc(sizeof(xPOINT));
	/*if (&P == NULL)
		return NULL;*/
	float tmp;
	printf("\nNhap (x,y):\n  - x: ");
	scanf_s("%f", &tmp);
	P.x = tmp;
	printf("\n  - y: ");
	scanf_s("%f", &tmp);
	P.y = tmp;
	return P;
}
void printPoint(xPOINT P)
{
	printf("(%0.2f ; %0.2f)", P.x, P.y);
}
float distancePoint(xPOINT P1, xPOINT P2)
{
	return sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
}
