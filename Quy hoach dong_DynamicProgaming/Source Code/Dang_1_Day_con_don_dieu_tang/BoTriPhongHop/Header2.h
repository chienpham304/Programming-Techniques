#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct room
{
	int s;
	int f;
};
void readData(char*path, room*&a, int&n);
void sortData(room*&a, int n);
void buildSolutionTable(room*&a, int*&len, int*&trace, int n);
void printTrace(room*a, int*len, int*trace, int n);
void printArray(room*a, int n, char*s);
