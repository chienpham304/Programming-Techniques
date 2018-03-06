#include "XepHau.h"


void xuatVT(int a[])
{
	std::cout << std::endl << "****************\n";
	for (int i = 0; i < 8;i++)
		printf("(%d,%d) ;",i,a[i]);
}

void datHauDong(int i, int a[],bool cot[],bool cheo1[],bool cheo2[])
{
	for (int j = 0; j < 8; j++)
	{
		if (cot[j] == false &&  cheo1[j-i+7]== false && cheo2[j+i]==false)
		{
			a[i] = j;
			if (i == 7)
			{
				//xuatMang(a);
				xuatVT(a);
				//return;
			}
			else
			{
				cot[j] = cheo1[j - i + 7] = cheo2[j + i] = true;
				datHauDong(i + 1, a,cot, cheo1, cheo2);
				//xoa danh dau
				cot[j] = cheo1[j - i + 7] = cheo2[j + i] = false;
				//a[i][j] = 0;
			}
				
		}
	}
}