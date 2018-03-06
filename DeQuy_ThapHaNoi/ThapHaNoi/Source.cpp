#include <iostream>
#include <conio.h>
using namespace std;
/*c1: cột nguồn
  c2: cột trung gian
  c3: cột đích*/
void xuatDuong(int n, char c1, char c2, char c3)
{
	if (n == 1)
	{
		printf("Dua dia tu %c qua %c \n", c1, c3);
		return;
	}
	else
	{
		xuatDuong(n - 1, c1, c3, c2);
		printf("Dua dia tu %c qua %c \n", c1, c3);
		xuatDuong(n - 1, c2, c1, c3);
	}
	
}

void main(){
	int n = 4;
	xuatDuong(n, '1', '2', '3');

	_getch();
}
/*Thuật toán: luôn có bộ 3 đĩa (1 gốc, 1 trung gian, 1 đích)
	- Đưa n-1 đĩa từ c1->c2
	- Đưa đĩa thứ n từ c1->c3
	- Đưa n-1 đĩa từ c2->c3
	**************ĐỆ QUY************
	- NẾU C1 chỉ có n=1 đĩa : đưa qua C3 (c1 gốc, c2 tg, c3 đích) 
	- else
		+ Đưa n-1 từ C1 qua C2: c1 gốc, c3 tg, c2 đích.
		+ Đưa đĩa còn lại từ c1->c2
		+ Đưa n-1 từ C2->C3: c2 gốc, c1 tg,c3 đích
		+ Xong
*/