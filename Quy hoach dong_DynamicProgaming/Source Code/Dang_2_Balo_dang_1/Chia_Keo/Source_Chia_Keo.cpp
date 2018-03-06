#include "Header_Chia_Keo.h"

int main()
{
	int*a = NULL, n, T, *re1,*re2, n1,n2;
	bool**L = NULL;
	readData("CHIA_KEO_INP.txt", a, n);
	printf("\nA: ");
	for (int i = 0; i < n; i++)
		printf("%2d ", *(a + i));
	//Tìm Tổng số kẹo
	T = sumArray(a, n);
	//Xây dựng bảng phương án
	buildSolutionTable(a, n, T, L);
	//in bảng phuong an
	printf("\nSolution Table:\n");
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= T; j++)
			printf("%d ", *(*(L + i) + j));
		printf("\n");
	}
	//truy vết
	traceAndPrintResult("CHIA_KEO_OUT.txt",a, n, T, L);
	_getch();
	return 0;
}