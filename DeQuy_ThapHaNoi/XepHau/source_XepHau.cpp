#include "XepHau.h"

void main()
{
	int a[MAX];
	bool cot[MAX] = { false };
	bool cheo1[2 * MAX-1] = { false };
	bool cheo2[2 * MAX-1] = { false };

	datHauDong(0,a,cot,cheo1,cheo2);
	_getch();
}