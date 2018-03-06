#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct item
{
	int w;
	int v;
};

void readData(char*path, item*&a, int&n, int&W);
void buildSolutionTable(int n, int W, item*a, int**&F);
void printTrace(int n, int W, item*a, int**F);