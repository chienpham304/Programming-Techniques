#include "Header_Market.h"

int main()
{
	int*a = NULL, n, T;
	bool**L = NULL;
	readData("MARKET_INP.txt", a, n);
	printf("\nA: ");
	for (int i = 0; i < n; i++)
		printf("%2d ", *(a + i));
	//Tìm Tổng số kg cá
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
	int count = 0;
	count = traceAndPrintResult("MARKET_OUT.txt", a, n, T, L);
	_getch();
	return 0;
}