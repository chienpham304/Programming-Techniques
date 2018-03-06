/*Bài toán: BỐ TRÍ PHÒNG HỌP
 Có n cuộc họp, cuộc họp thứ i bắt đầu Si và kết thúc Fi.
 Do chỉ có 1 phòng nên cần sắp xếp sao cho số cuộc họp là nhiều nhất.
 Hai cuộc gọi giao nhau tại mút.
 -Fie Input: 
 + dòng 1: số cuộc họp
 + n dòng tiếp theo mỗi dòng có cấu trúc: Si Fi*/
#include "Header2.h"
void main()
{
	int n;
	room *a;
	int *len, *trace;
	readData("Phong_Hop.txt", a, n);
	sortData(a, n);
	printArray(a, n, "\nData:");
	buildSolutionTable(a, len, trace, n);
	printTrace(a, len, trace, n);

	_getch();
}