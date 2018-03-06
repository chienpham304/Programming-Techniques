#include "Header_balo_1.h"

void readData(char*path, item*&a,int&n,int&W)
{
	errno_t err;
	FILE*f;
	err = fopen_s(&f, path, "r");
	if (err != 0)
	{
		printf("\nCannot read data"); _getch(); exit(0);
	}
	fscanf_s(f, "%d%d", &n, &W);
	a = new item[n];
	int i = 1;//==> đồng nhất với bảng phương án
	while (!feof(f))
	{
		int tmp = 0;
		fscanf_s(f, "%d", &tmp);
		a[i].w = tmp;
		fscanf_s(f, "%d", &tmp);
		a[i].v = tmp;
		i++;
	}
	fclose(f);
}
void buildSolutionTable(int n, int W, item*a, int**&F)
{
	F = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		F[i] = new int[W + 1];

	for (int j = 0; j <= W; j++)
		F[0][j] = 0;//co so quy hoach
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			F[i][j] = F[i - 1][j];//gia su khong cho ai
			//neu chon ai tot hon thi ga lai
			int tmp = F[i - 1][j - a[i].w] + a[i].v;//giá trị sau khi chọn gói i
			if (a[i].w <= j && F[i][j] < tmp)
			{
				F[i][j] = tmp;//chon ai
			}
		}
	}
}

void printTrace(int n, int W, item*a, int**F)
{
	printf("Weight: %d", W);
	while (n != 0)
	{
		if (F[n][W] != F[n - 1][W])
		{
			printf("\na[%d]", n);
			W -= a[n].w;
		}
		n--;		
	}
}