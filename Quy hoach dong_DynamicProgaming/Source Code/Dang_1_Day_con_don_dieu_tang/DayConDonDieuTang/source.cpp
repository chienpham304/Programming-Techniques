/*Cho dãy số nguyên a gồm n phần tử. Xuất ra dãy con đơn điệu tăng dài nhất
  (chọn ra một số phần từ từ a và giữ thứ tự và tính chất)*/
#include "header.h"
void main()
{
	int*a, *trace, *len;
	int n;
	printf("\nInput the number of elements: "); scanf_s("%d", &n);
	a = new int[n+2]; trace = new int[n+2], len = new int[n+2];
	for (int i = 1; i <= n; i++)
	{
		printf("\nNhap a[%d]: ", i - 1); scanf_s("%d",&a[i]);
	}
	printArray(a, n, "\nArray:");
	makeSolutionTable(a, len, trace, n);
	printTrace(a, len, trace, n);
	_getch();
	
}