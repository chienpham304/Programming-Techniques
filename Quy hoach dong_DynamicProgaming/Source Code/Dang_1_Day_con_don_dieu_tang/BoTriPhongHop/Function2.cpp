#include "Header2.h"

void readData(char*path, room*&a, int&n)
{
	errno_t err; FILE*f;
	err = fopen_s(&f, path, "r");
	if (err != 0)
	{
		printf("\nCannot read data!!");
		_getch();
		exit(0);
	}
	else
	{
		fscanf_s(f, "%d", &n);
		a = new room[n];
		int i = 0;
		while (!feof(f))
		{
			int tmp = 0;
			fscanf_s(f, "%d", &tmp);
			a[i].s = tmp;
			fscanf_s(f, "%d", &tmp);
			a[i].f = tmp;
			i++;
		}
		fclose(f);
	}
}
void buildSolutionTable(room*&a, int*&len, int*&trace,int n)
{
	len = new int[n + 2];
	trace = new int[n + 2];
	a = (room*)realloc(a, (n + 2)*sizeof(room));
	for (int i = n; i >= 1; i--)
		a[i] = a[i - 1];
	a[0] = { INT_MIN, INT_MIN };
	a[n + 1] = { INT_MAX, INT_MAX };
	len[n + 1] = 1;
	for (int i = n; i >= 0; i--)
	{
		int jmax = n + 1;
		for (int j = i + 1; j <= n + 1; j++)
		{
			if (a[i].f <= a[j].s && len[j] > len[jmax])
				jmax = j;
		}
		len[i] = len[jmax] + 1;
		trace[i] = jmax;
	}
}
void printTrace(room*a, int*len, int*trace, int n)
{
	printf("\nResult:");
	int i = trace[0];
	while (i != n + 1)
	{
		printf("\nA[%d] = (%d,%d)", i, a[i].s, a[i].f);
		i = trace[i];
	}
}
void sortData(room*&a, int n)
{
	//selection sort
	for (int i = 0; i < n;i++)
	for (int j = i + 1; j < n-1; j++)
	{
		int min = j;
		for (int k = j + 2; k < n;k++)
		if (a[k].f < a[min].f)
			min = k;
		if (a[i].f > a[min].f)
		{
			room tmp = a[i];
			a[i] = a[min]; a[min] = tmp;
		}
	}
}
void printArray(room*a, int n, char*s)
{
	printf("%s%d\n", s,n);
	for (int i = 0; i < n; i++)
		printf("(%d,%d)  ", a[i].s, a[i].f);
}