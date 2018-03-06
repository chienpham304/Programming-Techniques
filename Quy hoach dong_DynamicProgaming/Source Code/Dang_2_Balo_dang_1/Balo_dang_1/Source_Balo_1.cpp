#include "Header_balo_1.h"

/*Có n món đồ, vật thứ I có trọng lượng là wi và giá trị vi. Hãy chọn ra các món có thể bỏ vào một cái balo có trọng lượng tối đa là W sao cho tổng giá trị các món đồ là lớn nhất.
Đầu vào: Tập tin BALO.INP
- Dong 1: Chứa n W
- n dòng tiếp theo, dòng I chưa wi và ai
Đầu ra: Tập tin BALO.OUT
- Dong 1: Giá trị lớn nhất trong balo
- Dòng 2: Chỉ số những đồ vật được lấy
*/

int main()
{
	item*a = NULL;
	int n, W,**F;
	readData("BALO_1_INP.txt", a, n, W);
	buildSolutionTable(n, W, a, F);
	printTrace(n, W, a, F);
	_getch();
	return 0;
}