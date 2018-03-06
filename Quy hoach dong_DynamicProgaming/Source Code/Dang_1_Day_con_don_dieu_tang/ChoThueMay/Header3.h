#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct order
{
	int s;
	int f;
	int c;
};
void readData(char*path, order*&a, int&n);
void sortData(order*&a, int n);
void buildSolutionTable(order*&a, int*&sum, int*&trace, int n);
void printTrace(order*a, int*sum, int*trace, int n, char*path);
void printArray(order*a, int n, char*s);
