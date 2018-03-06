#include <stdio.h>
#include <conio.h>
#include <math.h>
#define SIZE 8
#define STEP SIZE*SIZE

struct DIEM
{
	int x, y;
};
//kiem tra vi tri x,y co thuoc ban co khong
bool kiemTra(int x, int y)
{
	return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}
void xuatKetQua(int a[SIZE][SIZE],int &numOfSolution)
{
	numOfSolution++;
	printf("\nLoi giai thu: %02d\n", numOfSolution);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	printf("============================\n");
}
void datQuanMa(int a[SIZE][SIZE], int dong, int cot, int step, int &numOfSolution)
{
	for (int i = -2; i <= 2; i++)
	{
		for (int j = -2; j <= 2; j++)
		{
			if (i != 0 && j != 0 && (abs(i) != abs(j)) && a[dong+i][cot+j]==0 && kiemTra(dong+i,cot+j))
			{
				a[dong + i][cot + j] = step+1;
				if (step + 1== STEP)
					xuatKetQua(a,numOfSolution);
				else
				{
					datQuanMa(a, dong + i, cot + j,step+1,numOfSolution);
				}
				a[dong + i][cot + j] = 0;
			}
		}
	}
}
void main()
{
	DIEM *Step = new DIEM[STEP];
	int mark[SIZE][SIZE] = { 0 };
	int numOfSolution = 0;
	mark[5][5] = 1;
	printf("<Processing...>");
	datQuanMa(mark, 5, 5, 1,numOfSolution);
	printf("\nTA CA CO %02d LOI GIAI.",numOfSolution);
	_getch();
}
