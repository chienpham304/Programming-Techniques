#include "Header3.h"

void readData(char*path, order*&a, int&n)
{
	errno_t err; FILE*f;
	printf("\nReading file: %s", path);
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
		a = new order[n];
		int i = 0;
		while (!feof(f))
		{
			int tmp = 0;
			fscanf_s(f, "%d", &tmp);
			a[i].s = tmp;
			fscanf_s(f, "%d", &tmp);
			a[i].f = tmp;
			fscanf_s(f, "%d", &tmp);
			a[i].c = tmp;
			i++;
		}
		fclose(f);
	}
}
void buildSolutionTable(order*&a, int*&sum, int*&trace, int n)
{
	sum = new int[n + 2];
	trace = new int[n + 2];
	a = (order*)realloc(a, (n + 2)*sizeof(order));
	for (int i = n; i >= 1; i--)
		a[i] = a[i - 1];
	a[0] = { INT_MIN, INT_MIN,0};
	a[n + 1] = { INT_MAX, INT_MAX,0 };
	sum[n + 1] = 0;
	for (int i = n; i >= 0; i--)
	{
		int jmax = n + 1;
		for (int j = i + 1; j <= n + 1; j++)
		{
			if (a[i].f <= a[j].s && sum[j] > sum[jmax])
				jmax = j;
		}
		sum[i] = sum[jmax] + a[i].c;
		trace[i] = jmax;
	}
}
void printTrace(order*a, int*sum, int*trace, int n,char*path)
{
	errno_t err; FILE*f;
	err = fopen_s(&f, path, "wb");
	if (err != 0)
	{
		printf("\nCannot write data!!");
		_getch();
		exit(0);
	}
	fprintf(f, "Sum: %d", sum[0]);
	int i = trace[0];
	while (i != n + 1)
	{
		fprintf(f,"\n%d %d %d",a[i].s, a[i].f,a[i].c);
		i = trace[i];
	}
	fclose(f);
	printf("\nWriting done: %s", path);
}
void sortData(order*&a, int n)
{
	//selection sort
	for (int i = 0; i < n; i++)
	for (int j = i + 1; j < n - 1; j++)
	{
		int min = j;
		for (int k = j + 2; k < n; k++)
		if (a[k].f < a[min].f)
			min = k;
		if (a[i].f > a[min].f)
		{
			order tmp = a[i];
			a[i] = a[min]; a[min] = tmp;
		}
	}
}
void printArray(order*a, int n, char*s)
{
	printf("%s%d\n", s, n);
	for (int i = 0; i < n; i++)
		printf("(%d,%d)  ", a[i].s, a[i].f);
}