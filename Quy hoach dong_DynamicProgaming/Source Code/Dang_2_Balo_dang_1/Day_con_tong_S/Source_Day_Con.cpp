#include "Header_Day_Con.h"

int main()
{
	int*a = NULL, n, S;
	bool**L = NULL;
	readData("DAY_CON_INP.txt", a, n, S);
	printf("\nSum: %d\nA:",S);
	for (int i = 0; i < n; i++)
		printf("%2d ", *(a + i));
	buildSolutionTable(a, n, S, L);
	//in bảng phuong an
	printf("\nSolution Table:\n");
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= S; j++)
			printf("%d ", *(*(L + i) + j));
		printf("\n");
	}
	//truy vấn
	traceAndPrintResult("DAY_CON_OUT.txt",a, n, S, L);
	_getch();
	return 0;
}