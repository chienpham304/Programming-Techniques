#include "Header_Market.h"
/*Đọc dữ liệu vào data
- Input: đường dẫn file input, mảng nguyên, số phần tử mảng
- Ouput: Mảng a chứa n phần tử*/
void readData(char*path, int*&a, int&n)
{
	errno_t err;
	FILE*f;
	err = fopen_s(&f, path, "rb");
	if (err != 0)
	{
		printf("\nCanot read data!");
		_getch(); exit(0);
	}
	fscanf_s(f, "%d", &n);
	a = NULL;
	a = (int*)malloc(n*sizeof(int));
	if (a == NULL)
	{
		printf("\nNot enought memory!");
		_getch(); exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf_s(f, "%d", a + i);
	fclose(f);
}

/*Tìm tổng của mảng (tổng số kẹo)
- Input: mảng a, n phần tử
- Output: số nguyên tổng các phần tử*/
int sumArray(int*a, int n)
{
	int kq = 0;
	for (int i = 0; i < n; i++)
		kq += *(a + i);
	return kq;
}

/*Xây dựng bảng phương án
- Input: Mảng nguyên a n phần từ, tổng s, mảng 2 chiều L nhị phân
- Output: Mảng 2 chiều L là bảng phương án*/
void buildSolutionTable(int*a, int n, int T, bool**&L)
{
	int i, j, k;
	//khởi tạo ma trận L[n+1xT+1]
	L = NULL;
	L = (bool**)malloc((n + 1)*sizeof(bool*));
	if (L == NULL)
	{
		printf("\nNot enought memory!");
		_getch(); exit(0);
	}
	for (i = 0; i <= n; i++)
	{
		*(L + i) = (bool*)malloc((T + 1)*sizeof(bool));
		if (*(L + i) == NULL)
		{
			printf("\nNot enought memory!");
			_getch(); exit(0);
		}
	}
	//cơ sở
	L[0][0] = 1;
	for (j = 1; j <= T; j++)
		L[0][j] = 0;
	//xây bảng phương án
	//Ghi chú: mảng nguyên chạy từ 0, mảng L xây từ dòng 1
	for (i = 1; i <= n; i++)//i truy câp mảng L
	{
		k = i - 1;//truy cập tới mảng A
		for (j = 0; j <= T; j++)
		{
			L[i][j] = 0;//mặc định
			if (L[i - 1][j] == 1)
				L[i][j] = 1;
			else if (j - a[k] >= 0 && L[i - 1][j - a[k]] == 1)
			{
				L[i][j] = 1;
			}
		}
	}
}

/*Truy vết và in kết quả
- Input: tên file, mảng nguyên a, n phần từ, tổng T, ma trận truy vấn
- Output: in ra các phương án, trả về số phương án*/
int traceAndPrintResult(char*path,int*a, int n, int T, bool**L)
{
	//ghi ra file
	errno_t err;
	FILE*f;
	err = fopen_s(&f, path, "w+");
	if (err != 0)
	{
		printf("\nCanot write data!");
		_getch(); exit(0);
	}
	for (int i = 0; i < n; i++)
		fprintf(f,"%2d ", *(a + i));
	int count = 0;
	int *re, m,tmp = n;
	re = NULL;
	m = 0;
	int S = T;
	while (S > 0)
	{
		n = tmp;
		if (L[n][S] == 1)
		{
			m = 0;
			count++;
			int tmpS = S;
			while (n > 0)
			{
				if (L[n][tmpS] != L[n - 1][tmpS])
				{
					m++;
					re = (int*)realloc(re, m*sizeof(int));
					re[m - 1] = a[n - 1];
					tmpS = tmpS - a[n - 1];
				}
				n--;
			}
			//in phương án
			fprintf(f, "\nSolution %d: ",count);
			fprintf(stdout, "\nSolution %d: ",count);
			for (int i = m - 1; i >= 0; i--)
			{
				fprintf(f, "%d ", re[i]);
				fprintf(stdout, "%d ", re[i]);
			}
		}
		S--;
	}
	fclose(f);
	free(re);
	return count;
}