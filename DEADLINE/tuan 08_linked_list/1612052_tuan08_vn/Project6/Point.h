//========PROTYPE STRUCT POINT========
#ifndef _POINT_H
#define _POINT_H
struct xPOINT
{
	float x, y;
};
xPOINT inputPoint();
void printPoint(xPOINT p);
float distancePoint(xPOINT P1, xPOINT P2);
#endif