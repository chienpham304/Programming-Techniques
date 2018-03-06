#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
struct point
{
	int x, y;
};
struct triangle //tam giác (angle: góc)
{
	point A, B, C;
};
//Kiểm tra điểm P có thuộc tam giác T hay không
float Sign(point p1, point p2, point p3);
bool PointInTriangle(point pt, triangle p);
bool isTriangle(point A, point B, point C);
float Distance(point P1, point P2);
float Area(triangle p);
//kiem tra P1 cos trong P2 khong 
bool TriangleInTriangle(triangle P1, triangle P2);
///////////////////////////////////////////
void readData(char*path, triangle*&a, int&n);
void sortData(triangle*&a, int n);
void buildSolutionTable(triangle*&a, int*&sum, int*&trace, int n);
void printTrace(triangle*a, int*sum, int*trace, int n, char*path);
void printArray(triangle*a, int n, char*s);
