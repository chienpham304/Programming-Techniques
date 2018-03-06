/*Bài toán: Cho thuê máy
Trung tâm tính toán hiệu năng nhận được đơn đặt hang của n khách hàng.
Khách hàng i muốn sử dụng máy trong khoảng thời gian từ Si đến Fi 
và trả tiền thuê là Ci. Hãy bố trí lịch thuê máy để tổng số tiền 
thu được là lớn nhất mà thời gian sử dụng máy của hai khách bất kì 
được phục vụ không bằng nhau.
INPUT File
-	Dòng 1: N (số khách)
-	N dòng tiếp tiếp theo mỗi dòng có cấu trúc: Si Fi Ci
OUTPUT File:
-	Dòng 1: tổng số tiền (k khách)
-	K dòng tiếp theo mỗi dòng: Si Fi Ci
*/
#include "Header3.h"
void main()
{
	int n;
	order *a;
	int *sum, *trace;
	readData("Thue_May.txt", a, n);
	sortData(a, n);
	printArray(a, n, "\nData:");
	buildSolutionTable(a, sum, trace, n);
	printTrace(a, sum, trace, n,"Thue_May_Out.txt");

	_getch();
}