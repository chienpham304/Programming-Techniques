#include "Header4.h"

void readData(char*path, triangle*&a, int&n)
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
		a = new triangle[n];
		int i = 0;
		while (!feof(f))
		{
			point A, B, C;
			int tmp;
			fscanf_s(f, "%d", &tmp);
			A.x = tmp;
			fscanf_s(f, "%d", &tmp);
			A.y = tmp;
			fscanf_s(f, "%d", &tmp);
			B.x = tmp;
			fscanf_s(f, "%d", &tmp);
			B.y = tmp;
			fscanf_s(f, "%d", &tmp);
			C.x = tmp;
			fscanf_s(f, "%d", &tmp);
			C.y = tmp;
			if (!isTriangle(A, B, C))
			{
				printf("\nThis data is not making a triangle!!!");
				_getch();
				_fcloseall();
				exit(0);
			}
			else
			{
				a[i].A = A;
				a[i].B = B;
				a[i].C = C;
				i++;
			}
			
		}
		fclose(f);
	}
}

void sortData(triangle*&a, int n)
{
	//selection sort
	for (int i = 0; i < n; i++)
	for (int j = i + 1; j < n - 1; j++)
	{
		int min = j;
		for (int k = j + 2; k < n; k++)
		if (Area(a[k]) < Area(a[min]))
			min = k;
		if (Area(a[i]) > Area(a[min]))
		{
			triangle tmp = a[i];
			a[i] = a[min]; a[min] = tmp;
		}
	}
}
void buildSolutionTable(triangle*&a, int*&len, int*&trace, int n)
{ 
	len = new int[n + 2];
	trace = new int[n + 2];
	a = (triangle*)realloc(a, (n + 2)*sizeof(triangle));
	for (int i = n; i >= 1; i--)
		a[i] = a[i - 1];
	a[0] = { { INT_MIN, INT_MIN }, { INT_MIN, INT_MIN }, { INT_MIN, INT_MIN }};
	a[n + 1] = { { INT_MAX, INT_MAX }, { INT_MAX, INT_MAX }, { INT_MAX, INT_MAX }};
	len[n + 1] = 1;
	for (int i = n; i >= 0; i--)
	{
		int jmax = n + 1;
		for (int j = i + 1; j <= n + 1; j++)
		{
			//if (a[i].f <= a[j].s && len[j] > len[jmax])
				jmax = j;
		}
		//len[i] = len[jmax] + a[i].c;
		trace[i] = jmax;
	}
}
void printTrace(triangle*a, int*len, int*trace, int n, char*path);
void printArray(triangle*a, int n, char*s)
{
	printf("%s%d\n", s, n);
	for (int i = 0; i < n; i++)
		printf("\n(%2d, %2d) _ (%2d, %2d) _ (%2d, %2d) => %0.3f", a[i].A.x, a[i].A.y, 
		a[i].B.x, a[i].B.y, a[i].C.x, a[i].C.y,Area(a[i]));
}
