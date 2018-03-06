#include "header.h"

void makeSolutionTable(int*a, int*&len, int*&trace, int n)
{
	a[0] = INT_MIN; a[n+1] = INT_MAX;
	//len = { 0 }; trace = { 0 };
	len[n + 1] = 1;//cơ sở
	
	for (int i = n; i >= 0; i--)
	{
		int jmax = n+1;
		for (int j = i + 1; j <= n+1; j++)
		{
			if (a[i] < a[j] && len[j]>len[jmax])
				jmax = j;	
		}
		len[i] = len[jmax] + 1;
		trace[i] = jmax;//luu next(i)=jmax
	}
}
void printTrace(int*a, int*len, int*trace, int n)
{
	printf("\nResult: ");
	int i = trace[0];
	while (i!=n+1)
	{
		printf("\na[%d] = %d", i, a[i]);
		i = trace[i];
	}
}
void printArray(int*a, int n, char*s)
{
	printf("%s", s);
	for (int i = 0; i < n; i++)
		printf("%5d", *(a + i+1));
}
