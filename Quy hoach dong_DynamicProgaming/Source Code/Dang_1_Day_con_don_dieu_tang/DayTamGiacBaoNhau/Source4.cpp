#include "Header4.h"

void main()
{
	triangle *a;
	int n;
	readData("Day_Tam_Giac.txt", a, n);
	//sortData(a, n);
	printArray(a, n, "\nArray: ");
	printf("\n==%d", TriangleInTriangle(a[3], a[2]));

	_getch();
}