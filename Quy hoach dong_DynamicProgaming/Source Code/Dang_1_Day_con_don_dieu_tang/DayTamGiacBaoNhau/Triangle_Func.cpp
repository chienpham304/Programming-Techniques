#include "Header4.h"

//Kiểm tra điểm P có thuộc tam giác T hay không
float Sign(point p1, point p2, point p3)
{
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle(point pt, triangle p)
{
	bool b1, b2, b3;
	b1 = Sign(pt, p.A, p.B) < 0.0f;
	b2 = Sign(pt, p.B, p.C) < 0.0f;
	b3 = Sign(pt, p.C, p.A) < 0.0f;
	return ((b1 == b2) && (b2 == b3));
}
//kiem tra P1 cos trong P2 khong 
bool TriangleInTriangle(triangle P1, triangle P2)
{ 
	return (PointInTriangle(P1.A, P2) && PointInTriangle(P1.B, P2) &&
		PointInTriangle(P1.C, P2));
}
bool isTriangle(point A, point B, point C)
{
	float a = Distance(B, C);
	float b = Distance(A, C);
	float c = Distance(A, B);
	return ((a + b>c) && (a + c>b) && (b + c>a) && (a > 0) && (b > 0) && (c > 0));
}
//distance
float Distance(point P1, point P2)
{
	return sqrt(pow(P1.x - P2.x + 0.0, 2) + pow(P1.y - P2.y + 0.0, 2));
}
//dien tich
float Area(triangle p)
{
	float a = Distance(p.B, p.C);
	float b = Distance(p.A, p.C);
	float c = Distance(p.A, p.B);
	float m = (a + b + c) / 2;
	float kq = sqrt(m*(m - a)*(m - b)*(m - c));
	return kq;
}
//////////////////////////////////////////////////