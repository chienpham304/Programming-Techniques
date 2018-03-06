#include "Header_Day_Con.h"
/*Đọc dữ liệu vào data
- Input: đường dẫn file input, mảng nguyên, số phần tử mảng, tổng S
- Ouput: Mảng a chứa n phần tử, tổng S*/
void readData(char*path, int*&a, int&n, int&S)
{
	errno_t err;
	FILE*f;
	err = fopen_s(&f, path, "rb");
	if (err != 0)
	{
		printf("\nCanot read data!");
		_getch(); exit(0);
	}
	fscanf_s(f,"%d%d", &n, &S);
	a = NULL;
	a = (int*)malloc(n*sizeof(int));
	if (a==NULL)
	{
		printf("\nNot enought memory!");
		_getch(); exit(0);
	}
	for (int i = 0; i < n; i++)
		fscanf_s(f, "%d", a + i);
}

/*Xây dựng bảng phương án
- Input: Mảng nguyên a n phần từ, tổng s, mảng 2 chiều L nhị phân
- Output: Mảng 2 chiều L là bảng phương án*/
void buildSolutionTable(int*a, int n, int S, bool**&L)
{
	int i, j, k;
	//khởi tạo ma trận L[n+1xS+1]
	L = NULL;
	L = (bool**)malloc((n + 1)*sizeof(bool*));
	if (L==NULL)
	{
		printf("\nNot enought memory!");
		_getch(); exit(0);
	}
	for (i = 0; i <= n; i++)
	{
		*(L + i) = (bool*)malloc((S + 1)*sizeof(bool));
		if (*(L+i)==NULL)
		{
			printf("\nNot enought memory!");
			_getch(); exit(0);
		}
	}
	//cơ sở
	L[0][0] = 1;
	for (j = 1; j <= S; j++)
		L[0][j] = 0;
	//xây bảng phương án
	//Ghi chú: mảng nguyên chạy từ 0, mảng L xây từ dòng 1
	for (i = 1; i <= n; i++)//i truy câp mảng L
	{
		k = i - 1;//truy cập tới mảng A
		for (j = 0; j <= S; j++)
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
- Input: tên file, mảng a, n phần từ, tổng s, ma trận truy vấn
- Output: dãy con có tổng bằng s, không có sẽ in ra thong báo*/
void traceAndPrintResult(char*path,int*a, int n, int S, bool**L)
{
	int *result, m; int tmp = S;
	result = NULL;
	m = 0;
	errno_t err;
	FILE*f;
	err = fopen_s(&f, path, "w+");
	if (err != 0)
	{
		printf("\nCanot write data!");
		_getch(); exit(0);
	}

	if (*(*(L + n) + S) == 0)
	{
		//in ra man hinh
		printf("\nNot exist an result (vo nghiem)");
		//ghi ra file
		fprintf(f, "%d\n",S);
		for (int i = 0; i<n;i++)
			fprintf(f, "%d ",a[i]);
		fprintf(f,"\nNO RESULT");
	}
	else
	{
		while (n>0)
		{
			if (L[n][S] != L[n - 1][S])
			{
				m++;
				result = (int*)realloc(result, m*sizeof(int));
				result[m - 1] = a[n - 1];
				//printf("%d, ", *(a + n - 1));
				S = S - a[n - 1];
			}
			n--;
		}
		//ghi kêt quả
		printf("\nSum: %d\nResult:", tmp);
		for (int i = m - 1; i >= 0; i--)
			printf("%d ", result[i]);
		//ghi file

		fprintf(f,"%d\n", tmp);
		for (int i = m - 1; i >= 0; i--)
			fprintf(f,"%d ", result[i]);
	}
	
}